/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef APPLICATION_H
#define	APPLICATION_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include "mcc_generated_files/system/system.h"

/*
 ***********************************************************
 *                                                         *
 *              User Defined MACROS                        *
 *                                                         *
 ***********************************************************
*/

#define START_0_9_DISPLAY_LOOP     ('1')
#define ZERO                       (0)
#define SEVEN_SEG_COUNT            (10)
#define HOLD_DISP_DIGIT_DELAY      (500)

/*
 ***********************************************************
 *                                                         *
 *              User Defined Variables                     *
 *                                                         *
 ***********************************************************
*/

static const uint8_t sevenSegHexCode[10] = 
{0xC0,0xF9,0xA4,0xB0,0x99,
0x92,0x82,0xF8,0x80,0x90};                              // Seven Segment Display (SSD) Hex Code (if all pins are mapped on PortD)            

static const uint8_t sevenSegHexCodePortD[10] = 
{0x00,0x22,0x10,0x00,0x22,
0x04,0x04,0x20,0x00,0x00};

static const uint8_t sevenSegHexCodePortC[10] = 
{0x20,0x38,0x10,0x18,0x08,
0x08,0x00,0x38,0x00,0x08};                              // Seven Segment Display (SSD) Hex Code (if pins are mapped on PortC & PortD)
/*
 ***********************************************************
 *                                                         *
 *         User Defined Function Declaration               *
 *                                                         *
 ***********************************************************
*/

/**
   @Param
    none
   @Returns
    none
   @Description
    Performs the action of sending the EUSART command to start SSD counter
   @Example
    none
 */
void Application(void);

#endif	/* APPLICATION_H */

