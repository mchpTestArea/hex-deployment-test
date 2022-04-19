/*
 * File:   application.c
 * Author: I62418
 *
 * Created on October 7, 2021, 10:01 AM
 */
#include <xc.h>
#include "application.h"

void Application(void)
{      
    uint8_t sevenSegArrIndex;                          // 7 Segment Display Array Index variable
    uint8_t input_command;
    
    if(EUSART1_IsRxReady() != ZERO)                         // Monitor the input on EUSART RX Pin 
    {
        input_command = EUSART1_Read();                // Read command received on UART
        
        if(input_command == START_0_9_DISPLAY_LOOP)                   
        {
            for (sevenSegArrIndex = ZERO; sevenSegArrIndex < SEVEN_SEG_COUNT; sevenSegArrIndex++)     // Loop to display 0-9 on 7 Segment Display
            {
                LATC = sevenSegHexCodePortC[sevenSegArrIndex];
                LATD = sevenSegHexCodePortD[sevenSegArrIndex];
                //LATD = sevenSegHexCode[sevenSegArrIndex]; 
                __delay_ms(HOLD_DISP_DIGIT_DELAY);
                LED_Toggle();                          // Toggle the on board LED after every count          
            }
            //LATD = sevenSegHexCode[ZERO];              // Reset display on 7 Segment Display to zero
            LATC = sevenSegHexCodePortC[ZERO];
            LATD = sevenSegHexCodePortD[ZERO];
        }
    }
}
