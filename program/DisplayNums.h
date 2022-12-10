/*  DisplayNums.h
 *  Author: Lucas Merritt/dynamic.void
 *  Date: 12/8/22
 *  Header file for display functions  */


/*
 * All of the displayableDigits on the seven-segment display
 *
 * Segments to enable(h), is G segment enabled
 */
unsigned char displayableDigits[10][2] = {
    {0xFC, 0},  //0
    {0x18, 0},  //1
    {0x6C, 1},  //2
    {0x3C, 1},  //3
    {0x98, 1},  //4
    {0xB4, 1},  //5
    {0xF4, 1},  //6
    {0x1C, 0},  //7
    {0xFC, 1},  //8
    {0x9C, 1},  //9
};

/*
 * The current numbers to display, indexed by which display to show them on
 * All initially 0(maybe change to '-'?)
 *
 * Segments to enable(h), is G segment enabled
 */
unsigned char numbersToDisplay[4][2] = {
    {0xFC, 0},  //0
    {0xFC, 0},  //0
    {0xFC, 0},  //0
    {0xFC, 0},  //0
};

/*
 * Clears the current segments and whatever else is needed
 */
void DisplayClear();

/*
 * Sets the current display, used for multiplexing
 *
 * displayNum: The index of the display to set to(0-3), use hardware definitions to call
 */
void DisplaySet(int displayNum);

/*
 * Shows the specified numbers on the display
 *
 * numbersToDisplay: The numbers to display, int form
 * ex: to display "1234" you would call DisplayNumbers(1234)
 * selectedDisplay: The current display
 * decimalLocation: What display the decimal should be shown on
 * Input a number > 3 if no decimal point(purposeful)
 */
void DisplayNumbers(int numbersToDisplay, int selectedDisplay, int decimalLocation);

/*
 * Update the time counter after a delay, based on time passed
 *
 * currentTime: The current time counter that is being actively displayed
 * decimalLocation: Where the decimal is/time precision
 * delayPeriod: How often the displays are switched between/multiplexed
 */
void UpdateDisplayTime(int currentTime, int decimalLocation, int delayPeriod);
