/* HardwareImplementation.c
 * Author: Lucas Merritt/dynamic.void
 * Date: 12/9/22
 * Hardware init and useful functions
 */

#include "HardwareImplementation.h"

void HardwareModifyPin(volatile unsigned char portPinMode, int applyMode, int hardwarePin) {
    if(applyMode == APPLY_MODE_CLEAR)
        portPinMode &= ~(1<<hardwarePin);
    if(applyMode == APPLY_MODE_SET)
        portPinMode |= (1<<hardwarePin);
}

void HardwareModifyRegister(volatile unsigned char modifyPortMode, int applyMode unsigned char applyPins) {
    if(applyMode == APPLY_MODE_CLEAR)
        modifyPortMode &= ~(applyPins);
    if(applyMode == APPLY_MODE_CLEAR)
        modifyPortMode |= applyPins;
}

void HardwareInit() {
    unsigned char pinsValue = (1<<DISPLAY_0_PIN)+(1<<DISPLAY_1_PIN)+(1<<DISPLAY_2_PIN)+(1<<DISPLAY_3_PIN);
    HardwareModifyRegister(DISPLAY_DDR, APPLY_MODE_SET, pinsValue);

    pinsValue = (1<<SEGMENT_A_PIN)+(1<<SEGMENT_B_PIN)+(1<<SEGMENT_C_PIN)+(1<<SEGMENT_D_PIN)+(1<<SEGMENT_E_PIN)+(1<<SEGMENT_F_PIN);
    HardwareModifyRegister(SEGMENT_DDR, APPLY_MODE_SET, pinsValue);
    if(SEGMENT_G_SEPERATE)
        HardwareModifyPin(SEPERATE_DDR, APPLY_MODE_SET, SEPERATE_G_PIN);
    else
        HardwareModifyPin(SEGMENT_DDR, APPLY_MODE_SET, SEGMENT_G_PIN);

    /* Add misc port initializations here: */
    HardwareModifyPin(MISC_DDR, APPLY_MODE_SET, MISC_DECIMAL_PIN);
}
