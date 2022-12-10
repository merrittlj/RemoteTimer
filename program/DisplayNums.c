/*  DisplayNums.c
 *  Author: Lucas Merritt/dynamic.void
 *  Date: 12/8/22
 *  Functions to help display numbers and multiplex  */


#include "HardwareImplementation.h"
#include "DisplayNums.h"

void DisplayClear() {
    HardwareModifyPin(DISPLAY_DATA, APPLY_MODE_CLEAR, DISPLAY_0_PIN);
    HardwareModifyPin(DISPLAY_DATA, APPLY_MODE_CLEAR, DISPLAY_1_PIN);
    HardwareModifyPin(DISPLAY_DATA, APPLY_MODE_CLEAR, DISPLAY_2_PIN);
    HardwareModifyPin(DISPLAY_DATA, APPLY_MODE_CLEAR, DISPLAY_3_PIN);

    HardwareModifyPin(SEGMENT_DATA, APPLY_MODE_CLEAR, SEGMENT_A_PIN);
    HardwareModifyPin(SEGMENT_DATA, APPLY_MODE_CLEAR, SEGMENT_B_PIN);
    HardwareModifyPin(SEGMENT_DATA, APPLY_MODE_CLEAR, SEGMENT_C_PIN);
    HardwareModifyPin(SEGMENT_DATA, APPLY_MODE_CLEAR, SEGMENT_D_PIN);
    HardwareModifyPin(SEGMENT_DATA, APPLY_MODE_CLEAR, SEGMENT_E_PIN);
    HardwareModifyPin(SEGMENT_DATA, APPLY_MODE_CLEAR, SEGMENT_F_PIN);
    if(SEGMENT_G_SEPERATE)
        HardwareModifyPin(SEPERATE_DATA, APPLY_MODE_CLEAR, SEPERATE_G_PIN);
    else
        HardwareModifyPin(SEGMENT_DATA, APPLY_MODE_CLEAR, SEGMENT_G_PIN);

    /* Add misc port clears here: */
    HardwareModifyPin(MISC_DATA, APPLY_MODE_CLEAR, MISC_DECIMAL_PIN);
}

void DisplaySet(int displayNum) {
    HardwareModifyPin(DISPLAY_DATA, APPLY_MODE_SET, displayNum);
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
