/*  DisplayNums.c
 *  Author: Lucas Merritt/dynamic.void
 *  Date: 12/8/22
 *  Functions to help display numbers  */


#include "HardwareImplementation.h"
#include "DisplayNums.h"

void DisplayClear() {
    HardwareModifyRegister(SEGMENT_DDR, APPLY_MODE_CLEAR, segmentPinsValue);

    /* Add misc port initializations here: */
    HardwareModifyPin(MISC_DDR, APPLY_MODE_CLEAR, MISC_DECIMAL_PIN);
    HardwareModifyPin(MISC_DDR, APPLY_MODE_CLEAR, MISC_DECIMAL2q_PIN);
}

void DisplayNumbers(int numbersToDisplay, int selectedDisplay, int decimalLocation) {
     int currentNumber;
     int currentNumberPosition = 2-selectedDisplay;
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
     if(decimalLocation<3)
         HardwareModifyPin(MISC_DATA, APPLY_MODE_SET, MISC_DECIMAL_PIN);
}
