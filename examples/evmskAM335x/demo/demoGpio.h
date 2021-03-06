/**
 * \file   demoGpio.h
 *
 * \brief  Function prototypes for the audio buzzer
*/

/*
* Copyright (C) 2010 Texas Instruments Incorporated - http://www.ti.com/
*/
/*
*  Redistribution and use in source and binary forms, with or without
*  modification, are permitted provided that the following conditions
*  are met:
*
*    Redistributions of source code must retain the above copyright
*    notice, this list of conditions and the following disclaimer.
*
*    Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in the
*    documentation and/or other materials provided with the
*    distribution.
*
*    Neither the name of Texas Instruments Incorporated nor the names of
*    its contributors may be used to endorse or promote products derived
*    from this software without specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
*  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
*  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
*  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*/

#ifndef _DEMOBUZZER_H_
#define _DEMOBUZZER_H_

#include "gpio_v2.h"

/*
** Structure for GPIO Configuration
*/
typedef struct gpioPinConfig
{
    unsigned int dir;
    unsigned int debouEnable;
    unsigned int debouTime;
    unsigned int intrEnable;
    unsigned int intrType;
    unsigned int intrLine;
    unsigned int wakeEnable;
    unsigned int wakeLine;
} tGPIOPinConfig;

/*
** Structure for IO Pad Configuration
*/
typedef struct ioPadConfig
{
    unsigned int slewRate;
    unsigned int mode;
    unsigned int type;
    unsigned int pullEnable;
    unsigned int pullSel;
} tIOPadConfig;

/*
** Structure for IO Pad & Pin
*/
typedef struct ioPin
{
    unsigned int ioPadOff;
    unsigned int instNum;
    unsigned int pinNum;
    unsigned int gpioBaseAddr;
    unsigned int intrNum;
    void (*gpioIsr) (void);
    tIOPadConfig padConfig;
    tGPIOPinConfig gpioConfig;
} tIOPin;

/******************************************************************************
**                     EXTERNAL VARIABLE DECLARATIONS
*******************************************************************************/

/******************************************************************************
**                      EXTERNAL FUNCTION PROTOTYPES
*******************************************************************************/
extern void gpioLedInit(void);
extern void gpioLedBlink(void);

extern void configWakeGpio(void);
extern void enableGpioWake(void);
extern void disableGpioWake(void);

// extern void configureGpio1Pin2(void);
extern void toggleLatGpio(void);
extern void DemoGpioPinStandbySrcConfig(tIOPin *ioPin);
void gpioStdbyUartIsr(void);
void gpioStdbyGPIOIsr(void);

#endif
