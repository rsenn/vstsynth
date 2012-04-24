/*
filter.cpp - canonical implementation of high order parametric filter 
			and resonant parametric	equalizer
Copyright (C) 2012 Gabriel Olochwoszcz

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#include "vstSynthFilter.h"	

vstSynthFilter::vstSynthFilter()
{
	G0 = 0.0001;
	N = 3.0;
	phi = PI/6;
	s1 = sin(phi);

	x01 = x02 = 0;
	y01 = y02 = 0;

	x11 = x12 = x13 = x14 = 0;
	y11 = y12 = y13 = y14 = 0;

	x21 = x22 = 0;
	y21 = y22 = 0;
}

vstSynthFilter::~vstSynthFilter()
{
}


void vstSynthFilter::setCoefficients(int newType, float newGain, float newFrequency, float newResonance)
{
	this->setType(newType);
	this->setGain(newGain);
	this->setFrequency(newFrequency);
	this->setResonance(newResonance);
	this->updateFilter();
}

void vstSynthFilter::setType(int newType)
{
	this->filterType = newType;
	this->updateFilter();
}

void vstSynthFilter::setGain(float newGain)
{
	this->G = newGain;
	this->updateFilter();
}

void vstSynthFilter::setFrequency(float newFrequency)
{
	this->Wc = PI * newFrequency;
	this->updateFilter();
}

void vstSynthFilter::setResonance(float newResonance)
{
	this->Gr = newResonance * G;
	this->updateFilter();
}

void vstSynthFilter::reset()
{
	x01 = x02 = 0;
	y01 = y02 = 0;

	x11 = x12 = x13 = x14 = 0;
	y11 = y12 = y13 = y14 = 0;

	x21 = x22 = 0;
	y21 = y22 = 0;
}

void vstSynthFilter::updateFilter()
{
	if (G >= G0)
	{
		Gb = G/2;
	}
	if (G < G0)
	{
		Gb = G0/2;
	}

	G0r = G;
	Gbr = Gr/2;

	switch (filterType) {
	case 0:
		{
			W0 = 0;
			W1 = 0;
			W2 = Wc;
			break;
		}
	case 1:
		{
			W0 = Wc;
			W1 = Wc/3;

			if (3*Wc < PI)
			{
				W2 = 3*Wc;
			}
			else
			{
				W2 = PI;
			}
			break;
		}
	case 2:
		{
			W0 = PI;
			W1 = Wc;
			W2 = PI;
			break;
		}

	default:
		break;
	}

	dW = W2 - W1;
	dWr = 0.001*G;

	g = pow(G,1.0f/N);
	g0 = pow(G0,1.0f/N); 

	epsilon = sqrt((G*G - Gb*Gb)/(Gb*Gb - G0*G0));
	beta = pow(epsilon,-1.0f/N) * tanf(dW/2);

	c0 = cos(W0); 

	// second order section coefficients
	D0 = beta + 1;
	b00 = (g0 + g*beta)/D0;
	b01 =  -2*g0*c0/D0;
	b02 = (g0 - g*beta)/D0;
	a00 = 1;
	a01 =  -2*c0/D0;
	a02 = (1 - beta)/D0;
	x01 = x02 = 0;
	y01 = y02 = 0;


	float gSq = g*g;
	float betaSq = beta*beta;
	float g0Sq = g0*g0;
	float c0Sq = c0*c0;

	// fourth order section coefficients
	D1 = betaSq + 2*s1*beta + 1;
	b10 = (gSq*betaSq + 2*g*g0*s1*beta + g0Sq)/D1;
	b11 =  -4*c0*(g0Sq + g*g0*s1*beta)/D1;
	b12 = 2*(g0Sq*(1 + 2*c0Sq) - gSq*betaSq)/D1;
	b13 =  -4*c0*(g0Sq - g*g0*s1*beta)/D1;
	b14 = (gSq*betaSq - 2*g*g0*s1*beta + g0Sq)/D1;
	a10 = 1;
	a11 =  - 4*c0*(1 + s1*beta)/D1;
	a12 = 2*(1 + 2*c0Sq - betaSq)/D1;
	a13 =  -4*c0*(1 - s1*beta)/D1;
	a14 = (betaSq - 2*s1*beta + 1)/D1;

	// resonator section coefficients
	betaR = sqrt((Gbr*Gbr - G0*G0)/(Gr*Gr - Gbr*Gbr))*tanf(dWr/2);
	c0r = cos(Wc);

	b20 = (G0r + Gr*betaR)/(1 + betaR);
	b21 = -2*(G0r*c0r/(1 + betaR));
	b22 = (G0r - Gr*betaR)/(1 + betaR);
	a20 = 1;
	a21 = -2*c0r/(1 + betaR);
	a22 = (1 - betaR)/(1 + betaR);

	reset();
}

void vstSynthFilter::processSamples(float* const samples, const int numSamples) noexcept
{
	for (int currentSample = 0; currentSample < numSamples; ++currentSample)
	{
		// second order section
		const float x00 = samples[currentSample];

		float y00 = b00 * x00
			+ b01 * x01
			+ b02 * x02
			- a01 * y01
			- a02 * y02;

		x02 = x01;
		x01 = x00;

		y02 = y01;
		y01 = y00;

		//// fourth order section
		//const float x10 = y00;

		//float y10 = 0.001 *b10 * x10
		//	+ b11 * x11
		//	+ b12 * x12
		//	+ b13 * x13
		//	+ b14 * x14
		//	- a11 * y11
		//	- a12 * y12
		//	- a13 * y13
		//	- a14 * y14;

		//x14 = x13;
		//x13 = x12;
		//x12 = x11;
		//x11 = x10;

		//y14 = y13;
		//y13 = y12;
		//y12 = y11;
		//y11 = y10;

		// resonator section
		const float x20 = y00;

		float y20 = b20 * x20
			+ b21 * x21
			+ b22 * x22
			- a21 * y21
			- a22 * y22;

		x22 = x21;
		x21 = x20;

		y22 = y21;
		y21 = y20;

		samples[currentSample] = y20;
	}
}