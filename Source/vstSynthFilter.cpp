/*
vstSynthFilter.cpp - implementation of high order parametric filter 
			 and resonant parametric equalizer
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
	// Initialize fixed design parameters
    G0 = 0.0001; // reference gain -120db
	N = 3.0;
	phi = PI/6;
	s1 = sin(phi);
	
    // Initialize internal filter states
    // 2nd order
	//b00 = b01 = b02 = 0;
	//a00 = a01 = a02 = 0;
	x01 = x02 = 0;
	y01 = y02 = 0;

    // 4th order 
	//b10 = b11 = b12 = b13 = b14 = 0;
	//a10 = a11 = a12 = a13 = a14 = 0;
	x11 = x12 = x13 = x14 = 0;
	y11 = y12 = y13 = y14 = 0;
	w11 = w12 = w13 = w14 = 0;

    // resonator
	//b20 = b21 = b22 = 0;
	//a20 = a21 = a22 = 0;
	x21 = x22 = 0;
	y21 = y22 = 0;
}

vstSynthFilter::~vstSynthFilter()
{
}

// Set all parameters and update filter with new coefficients
void vstSynthFilter::setCoefficients(int newType, float newGain, float newFrequency, float newResonance)
{
	this->setType(newType);
	this->setGain(newGain);
	this->setFrequency(newFrequency);
	this->setResonance(newResonance);
	this->updateFilter();
}

// Set filter type - 0=lp,1=bp,2=hp
void vstSynthFilter::setType(int newType)
{
	this->filterType = newType;
	this->updateFilter();
}

// Set 2nd and 4th order gain
void vstSynthFilter::setGain(float newGain)
{
	this->G = newGain;
	this->updateFilter();
}

// Set cutoff frequency
void vstSynthFilter::setFrequency(float newFrequency)
{
	this->Wc = newFrequency;
	this->updateFilter();
}

// Set resonator gain above 2nd/4th order gain
void vstSynthFilter::setResonance(float newResonance)
{
	this->Gr = newResonance * G;
	this->updateFilter();
}

// Reset internal states after changes
void vstSynthFilter::reset()
{
	x01 = x02 = 0;
	y01 = y02 = 0;

	x11 = x12 = x13 = x14 = 0;
	y11 = y12 = y13 = y14 = 0;
    w11 = w12 = w13 = w14 = 0;

	x21 = x22 = 0;
	y21 = y22 = 0;
}

// Calculate g, g0, and epsilon
void vstSynthFilter::defineParameters()
{
	// Filter gain > reference gain
    // Set cutoff gain to 6 dB below passband gain
	if (G >= G0)
	{
		Gb = G/2;
	}
    
    // Filter gain < reference gain
    // Set cutoff gain to 6 db below reference gain
	if (G < G0)
	{
		Gb = G0/2;
	}

    // Resonator reference gain is the passband gain
	G0r = G;
    
    // 6 dB below resonator peak
	Gbr = Gr/2;
	g = pow(G,1.0f/N);
	g0 = pow(G0,1.0f/N); 

	epsilon = sqrt((G*G - Gb*Gb)/(Gb*Gb - G0*G0));
	
    c0r = cos(Wc);

	// squared values
	gSq = g*g;
	g0Sq = g0*g0;
}


// Calculate all coefficients
void vstSynthFilter::updateFilter()

// All resonator coefficients have "r" appended
{
    reset();
	defineParameters();
	
	// Set frequency parameters for each filter type
	switch (filterType) {

    // lowpass
	case 0:
		{
			W0 = 0;
			W1 = 0;
			W2 = Wc;
			dW = W2 - W1;
			beta = pow(epsilon,-1.0f/N) * tanf(dW/2);
			betaSq = beta*beta;

		    c0 = cos(W0);
			c0Sq = c0*c0;

			// Lowpass second order section
			D0 = beta + 1;
			b00 = (g*beta + g0)/D0;
			b01 = (g*beta - g0)/D0;
			b02 = 0;
			a01 = (beta - 1)/D0;
			a02 = 0;

			// Lowpass fourth order section
			D1 = betaSq + 2*s1*beta + 1;
			b10 = (gSq*betaSq + 2*g*g0*s1*beta + g0Sq)/D1;
			b11 = 2*(gSq*betaSq - g0Sq)/D1;
			b12 = (gSq*betaSq  -  2*g*g0*s1*beta + g0Sq)/D1;
			b13 = 0;
			b14 = 0;
			a11 = 2*(betaSq - 1)/D1;
			a12 = (betaSq - 2*s1*beta + 1)/D1;
			a13 = 0;
			a14 = 0;

			break;
		}
            
    // bandpass
	case 1:
		{
            // Approx two octave bandwidth
			if (Wc < 0.025)
            {
                Wc = 0.025;
            }
            W0 = Wc;
			W1 = Wc/2;
			float tanSq = tan(Wc/2)*tan(Wc/2);
			W2 = 2*atan(tanSq / tan(W1/2));
			dW = W2 - W1;
			
			beta = pow(epsilon,-1.0f/N) * tanf(dW/2);
			betaSq = beta*beta;

			c0 = cos(W0);
			c0Sq = c0*c0;


			// second order section coefficients
			D0 = beta + 1;
			b00 = (g0 + g*beta)/D0;
			b01 =  -2*g0*c0/D0;
			b02 = (g0 - g*beta)/D0;
			a01 =  -2*c0/D0;
			a02 = (1 - beta)/D0;

			// fourth order section coefficients
			D1 = betaSq + 2*s1*beta + 1;
			b10 = (gSq*betaSq + 2*g*g0*s1*beta + g0Sq)/D1;
			b11 =  -4*c0*(g0Sq + g*g0*s1*beta)/D1;
			b12 = 2*(g0Sq*(1 + 2*c0Sq) - gSq*betaSq)/D1;
			b13 =  -4*c0*(g0Sq - g*g0*s1*beta)/D1;
			b14 = (gSq*betaSq - 2*g*g0*s1*beta + g0Sq)/D1;
			a11 =  - 4*c0*(1 + s1*beta)/D1;
			a12 = 2*(1 + 2*c0Sq - betaSq)/D1;
			a13 =  -4*c0*(1 - s1*beta)/D1;
			a14 = (betaSq - 2*s1*beta + 1)/D1;
			
			break;

		}
            
    // highpass
	case 2:
		{
			W0 = PI;
			W1 = Wc;
			W2 = PI;
			dW = W2 - W1;
			
			beta = pow(epsilon,-1.0f/N) * tanf(dW/2);
			betaSq = beta*beta;
		    
			c0 = cos(W0);
			c0Sq = c0*c0;

			// Highpass second order section
			D0 = beta + 1;
			b00 = (g*beta + g0)/D0;
			b01 = -(g*beta - g0)/D0;
			b02 = 0;
			a01 = -(beta - 1)/D0;
			a02 = 0;

			// Highpass fourth order section
			D1 = betaSq + 2*s1*beta + 1;
			b10 = (gSq*betaSq + 2*g*g0*s1*beta + g0Sq)/D1;
			b11 = -2*(gSq*betaSq - g0Sq)/D1;
			b12 = (gSq*betaSq  -  2*g*g0*s1*beta + g0Sq)/D1;
			b13 = 0;
			b14 = 0;
			a11 = -2*(betaSq - 1)/D1;
			a12 = (betaSq - 2*s1*beta + 1)/D1;
			a13 = 0;
			a14 = 0;
			
			break;
		}

	default:
		break;
	}

    // Resonator bandwidth
	// fixed ratio to gain to keep shape of resonator as gain changes
	dWr = 0.01 * G;
	
	// resonator section coefficients
	betaR = sqrt((Gbr*Gbr - G0*G0)/(Gr*Gr - Gbr*Gbr))*tanf(dWr/2);

	b20 = (G0r + Gr*betaR)/(1 + betaR);
	b21 = -2*(G0r*c0r/(1 + betaR));
	b22 = (G0r - Gr*betaR)/(1 + betaR);
	a20 = 1;
	a21 = -2*c0r/(1 + betaR);
	a22 = (1 - betaR)/(1 + betaR);
}

void vstSynthFilter::processSamples(float* const samples, const int numSamples) noexcept
{
	for (int currentSample = 0; currentSample < numSamples; ++currentSample)
	{
		// Get data from buffer
        const float x00 = samples[currentSample];

		// second order section
		float y00 = b00 * x00
			+ b01 * x01
			+ b02 * x02
			- a01 * y01
			- a02 * y02;
        
        // Update internal states
		x02 = x01;
		x01 = x00;

		y02 = y01;
		y01 = y00;

		// fourth order section
//		const float x10 = y00;
//
//		float y10 = b10 * x10
//			+ b11 * x11
//			+ b12 * x12
//			+ b13 * x13
//			+ b14 * x14
//			- a11 * y11
//			- a12 * y12
//			- a13 * y13
//			- a14 * y14;
//
//		x14 = x13;
//		x13 = x12;
//		x12 = x11;
//		x11 = x10;
//
//		y14 = y13;
//		y13 = y12;
//		y12 = y11;
//		y11 = y10;
        
        const float w10 = y00
            - a11 * w11
            - a12 * w12
            - a13 * w13
            - a14 * w14;
        
        float y10 = b10 * w10
            + b11 * w11
            + b12 * w12
            + b13 * w13
            + b14 * w14;

        // Update internal states
        w14 = w13;
        w13 = w12;
        w12 = w11;
        w11 = w10;
        
		// resonator section
		const float x20 = y10;

		float y20 = b20 * x20
			+ b21 * x21
			+ b22 * x22
			- a21 * y21
			- a22 * y22;
        
        // Update internal states
		x22 = x21;
		x21 = x20;

		y22 = y21;
		y21 = y20;
        
        // Write cascaded output to buffer
		samples[currentSample] = y20;
	}
}