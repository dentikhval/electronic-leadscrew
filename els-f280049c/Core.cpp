// Clough42 Electronic Leadscrew
// https://github.com/clough42/electronic-leadscrew
//
// MIT License
//
// Copyright (c) 2019 James Clough
//
// Modified by Denis Tikhonov to use an additional MPG input and a left/right lever
// for lathes that have no half-nuts and the nut is directly coupled to the apron.
//
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.


#include "F28x_Project.h"
#include "Core.h"



Core :: Core(Encoder *encoder, StepperDrive *stepperDrive)
{
    this->encoder = encoder;
    this->stepperDrive = stepperDrive;
    
    this->MPG_ACTIVE = true;
    this->THREADING_ACTIVE = false;

    this->feed = NULL;
    this->feedDirection = 0;

    this->previousMPGPosition = 0;
    this->previousSpindlePosition = 0;
    this->previousFeedDirection = 0;
    this->previousFeed = NULL;
}


void Core :: setMPGActive(bool mpg_selected)
{
    if( mpg_selected )
    {
        this->MPG_ACTIVE = true;
    }
    else
    {
        this->MPG_ACTIVE = false;
    }
}
void Core :: setThreading(bool threading)
{
    if( threading )
    {
        this->THREADING_ACTIVE = true;
    }
    else
    {
        this->THREADING_ACTIVE = false;
    }
}

void Core :: setReverse(bool reverse)
{
    if( reverse )
    {
        this->feedDirection = -1;
    }
    else
    {
        this->feedDirection = 1;
    }
}







