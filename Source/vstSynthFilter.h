/*
filter.h - header file for filter.cpp
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

# include "StkIncludes.h"
#include "../JuceLibraryCode/JuceHeader.h"

using namespace stk;

class vstSynthFilter// : public IIRFilter
{
public:
	vstSynthFilter();
	~vstSynthFilter();

	void setCoefficients(int newType, float newGain, float newFrequency, float newResonance);

	void setType(int newType);
	void setGain(float newGain);
    void setFrequency(float newFrequency);
    void setResonance(float newResonance);
    
    void processSamples(float* samples, int numSamples) noexcept;
    
	void reset();
    
private:
    void defineParameters(); // calculates g, g0, and epsilon
	void updateFilter(); // calculates all coefficients

	float G0;		//reference gain
	float G;			//filter gain
	float Gb;		//gain at deltaW

	float Wc;		//center/cutoff frequency
	int filterType;	//0 = LP, 1 = BP, 2 = HP

	float N;			//analog filter order
    float W0;       //center frequency
	float W1;		//lower transition frequency
	float W2;		//upper transition frequency
	float dW;		//W2-W1

	float g;		//G^(1/N)
    float g0;		//G0^(1/N)
	float phi;		//pi/6

    float epsilon;
	float beta;     // hpeq beta
	float c0;		//cos(W0)
	float s1;		//sin(phi)

	float gSq;
	float betaSq;
	float g0Sq;
	float c0Sq;

	float D0;
    // second order coefficients
    float b00, b01, b02;
    float a00, a01, a02;
    // second order internal states
    float x01, x02;
    float y01, y02;
    
	float D1;
    // fourth order coefficients
    float b10, b11, b12, b13, b14;
    float a10, a11, a12, a13, a14;
    // fourth order internal states
    float x11, x12, x13, x14;
    float y11, y12, y13, y14;
    float w11, w12, w13, w14;
    
    
    float Gr;       //resonator gain
    float G0r;      //resonator reference gain
    float dWr;      //resonator width 0.001
    float betaR;    //resonator beta
    float c0r;      //resonator center freq cosine
    float Gbr;      //resonator gain at dWr

    // resonator coefficients
    float b20, b21, b22;
    float a20, a21, a22;
    // resonator internal states
    float x21, x22;
    float y21, y22;

};