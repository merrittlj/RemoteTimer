/*  DisplayNums.c
 *  Author: Lucas Merritt/dynamic.void
 *  Date: 12/8/22
 *  Functions to help display numbers and multiplex  */


#include "HardwareImplementation.h"
#include "DisplayNums.h"

void DisplayClear() {
    unsigned char pinsValue = (1<<DISPLAY_0_PIN)+(1<<DISPLAY_1_PIN)+(1<<DISPLAY_2_PIN)+(1<<DISPLAY_3_PIN);
    HardwareModifyRegister(DISPLAY_DDR, APPLY_MODE_CLEAR, pinsValue);

    pinsValue = (1<<SEGMENT_A_PIN)+(1<<SEGMENT_B_PIN)+(1<<SEGMENT_C_PIN)+(1<<SEGMENT_D_PIN)+(1<<SEGMENT_E_PIN)+(1<<SEGMENT_F_PIN);
    HardwareModifyRegister(SEGMENT_DDR, APPLY_MODE_CLEAR, pinsValue);
    if(SEGMENT_G_SEPERATE)
        HardwareModifyPin(SEPERATE_DDR, APPLY_MODE_CLEAR, SEPERATE_G_PIN);
    else
        HardwareModifyPin(SEGMENT_DDR, APPLY_MODE_CLEAR, SEGMENT_G_PIN);

    /* Add misc port initializations here: */
    HardwareModifyPin(MISC_DDR, APPLY_MODE_CLEAR, MISC_DECIMAL_PIN);
}

void DisplaySet(int displayNum) {
    HardwareModifyPin(DISPLAY_DATA, APPLY_MODE_CLEAR, displayNum);
}

void DisplayNumbers(int numbersToDisplay, int selectedDisplay, int decimalLocation) {
     int currentNumber;
     int currentNumberPosition = 4-selectedDisplay;
     for(int i=0; i<currentNumberPosition; i++) {
        numbersToDisplay /= 10;
     }
     currentNumber = numbersToDisplay % 10;

     unsigned char hexToDisplay = displayableDigits[currentNumber][0];
     unsigned char gSegmentEnabled = displayableDigits[currentNumber][1];

     HardwareModifyRegister(SEGMENT_DATA, hexToDisplay);
     if(SEGMENT_G_SEPERATE)
         HardwareModifyPin(SEPERATE_DATA, gSegmentEnabled, SEPERATE_G_PIN);
     else
         HardwareModifyPin(SEGMENT_DATA, gSegmentEnabled, SEGMENT_G_PIN);
     if(decimalLocation<4)
         HardwareModifyPin(MISC_DATA, APPLY_MODE_SET, MISC_DECIMAL_PIN);
}
