/*  HardwareImplementation.h
 *  Author: Lucas Merritt/dynamic.void
 *  Date: 12/8/22
 *  The hardware implementation of the timer, configurable  */


/*
 * Memory addresses
 *
 * PORTx_DATA: Set this to control output, reading will only give what you have output before
 * PORTx_DDR: Set this to control data direction, 1 = output 0 = input
 * PORTx_PINS: Read from this to get input from peripherals
 */
#define PORTB_DATA (*((volatile unsigned char *)0x25))
#define PORTC_DATA (*((volatile unsigned char *)0x28))
#define PORTD_DATA (*((volatile unsigned char *)0x2B))
#define PORTB_DDR (*((volatile unsigned char *)0x24))
#define PORTC_DDR (*((volatile unsigned char *)0x27))
#define PORTD_DDR (*((volatile unsigned char *)0x2A))
#define PORTB_PINS (*((volatile unsigned char *)0x23))
#define PORTC_PINS (*((volatile unsigned char *)0x26))

/*
 * Hardware Pins
 * Used to set output and read input
 * Usage: 
 *
 * SEGMENT_PORT_[DATA|DDR|PINS] - The port that the segments are on, used for GPIO 
 * SEGMENT_[A-G]_PIN - The respective segment's pin
 * MISC_PORT_[DATA|DDR|PINS] - The port that miscellaneous things are on, used for GPIO
 * MISC_[NAME]_PIN - The respective item's pin
 */

#define SEGMENT_DATA PORTD_DATA
#define SEGMENT_DDR PORTD_DDR
#define SEGMENT_PINS PORTD_PINS
#define SEGMENT_A_PIN 2
#define SEGMENT_B_PIN 3
#define SEGMENT_C_PIN 4
#define SEGMENT_D_PIN 5
#define SEGMENT_E_PIN 6
#define SEGMENT_F_PIN 7
#define SEGMENT_G_PIN 8
#define SEGMENT_A2_PIN 2
#define SEGMENT_B2_PIN 3
#define SEGMENT_C2_PIN 4
#define SEGMENT_D2_PIN 5
#define SEGMENT_E2_PIN 6
#define SEGMENT_F2_PIN 7
#define SEGMENT_G2_PIN 8

/* All of the segment pins added together(used for functions) */
unsigned char segmentPinsValue = (1<<SEGMENT_A_PIN)+(1<<SEGMENT_B_PIN)+(1<<SEGMENT_C_PIN)+(1<<SEGMENT_D_PIN)+(1<<SEGMENT_E_PIN)+(1<<SEGMENT_F_PIN)+(1<<SEGMENT_G_PIN)+(1<<SEGMENT_A2_PIN)+(1<<SEGMENT_B2_PIN)+(1<<SEGMENT_C2_PIN)+(1<<SEGMENT_D2_PIN)+(1<<SEGMENT_E2_PIN)+(1<<SEGMENT_F2_PIN)+(1<<SEGMENT_G2_PIN);

#define MISC_DATA PORTC_DATA
#define MISC_DDR PORTC_DDR
#define MISC_PINS PORTC_PINS
#define MISC_DECIMAL_PIN 0
#define MISC_DECIMAL2_PIN 0

/*
 * Apply modes(for below function)
 *
 * applyModeClear - Clear the pin/register
 * applyModeSet - Set the pin/register to a specified value
 */
#define APPLY_MODE_CLEAR 0
#define APPLY_MODE_SET 1

/*
 * Sets/clears a pin on the specified port in the specified way
 *
 * portPinMode: Uses definitions to specify which way to modify the pin on which port
 * ex: SEGMENT_DATA
 * applyMode: See Apply Mode definitions
 * hardwarePin: the pin to clear/set
 */
void HardwareModifyPin(volatile unsigned char portPinMode, int applyMode, int hardwarePin);

/*
 * Sets/clears a whole register
 *
 * modifyPortMode: The way to modify the port and which register to use
 * ex: SEGMENT_DATA
 * applyMode: See Apply Mode definitions
 * applyPins: The value to set the register to(h)/The representation of all pins that will be set or cleared(h)
 * Can be hexadecimal or int(ex: the value of all the pins added together)
 */
void HardwareModifyRegister(volatile unsigned char modifyPortMode, int applyMode, unsigned char applyPins);

/*
 * Initializes the hardware, data directions and such
 *
 * Uses previously defined hardware pins
 */
void HardwareInit();
