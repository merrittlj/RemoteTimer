/*  hardwareImplementation.h
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
