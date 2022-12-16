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
    pinsValue = (1<<SEGMENT_A_PIN)+(1<<SEGMENT_B_PIN)+(1<<SEGMENT_C_PIN)+(1<<SEGMENT_D_PIN)+(1<<SEGMENT_E_PIN)+(1<<SEGMENT_F_PIN)+(1<<SEGMENT_G_PIN)+(1<<SEGMENT_A2_PIN)+(1<<SEGMENT_B2_PIN)+(1<<SEGMENT_C2_PIN)+(1<<SEGMENT_D2_PIN)+(1<<SEGMENT_E2_PIN)+(1<<SEGMENT_F2_PIN)+(1<<SEGMENT_G2_PIN);
    HardwareModifyRegister(SEGMENT_DDR, APPLY_MODE_SET, pinsValue);

    /* Add misc port initializations here: */
    HardwareModifyPin(MISC_DDR, APPLY_MODE_SET, MISC_DECIMAL_PIN);
    HardwareModifyPin(MISC_DDR, APPLY_MODE_SET, MISC_DECIMAL2_PIN);
}
