/*  displayNums.h
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
 * Initializes the display for the numbers, clearing past numbers and anything else required
 */
void displayInit();

/*
 * Sets the current display, used for multiplexing
 *
 * displayNum: The index of the display to set to(0-3)
 */
void setCurrentDisplay(int displayNum);
