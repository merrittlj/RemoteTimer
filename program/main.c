/*  main.c
 *  Author: Lucas Merritt/dynamic.void
 *  Date: 12/8/22
 *  Main file for calling and iterations, etc  */

#include <util/delay.h>

#include "HardwareImplementation.h"
#include "DisplayNums.h"
#include "StateMachine.h"

int main() {
    HardwareInit();

    int currentNumberDisplay = 0;  //Tracks the current display that segments are being shown on
    int displaySwitchMs = 1;  //How long until switching to the next display, milliseconds
    int timeCounter = 1500;  //Time to count down from, mm:ss
    int decimalDisplayLocation = 1;  //What display to display the decimal on(0-3)
    /*while(1<2) {
        DisplayClear();

        DisplaySet(currentNumberDisplay);
        DisplayNumbers(timeCounter, currentNumberDisplay, decimalDisplayLocation);

        currentNumberDisplay += (currentNumberDisplay==3 ? -3 : 1);

        _delay_ms(displaySwitchMs);
        UpdateDisplayTime(timeCounter, decimalDisplayLocation, displaySwitchMs);
    }*/

    /* For debugging, ensuring hardware is working */
    DISPLAY_DATA |= 0xF-(1<<1);
    SEGMENT_DATA |= 0xFC;
}
