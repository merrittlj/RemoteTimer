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

void HardwareInit() {
    HardwareModifyPin(DISPLAY_DDR, APPLY_MODE_SET, DISPLAY_0_PIN);
    HardwareModifyPin(DISPLAY_DDR, APPLY_MODE_SET, DISPLAY_1_PIN);
    HardwareModifyPin(DISPLAY_DDR, APPLY_MODE_SET, DISPLAY_2_PIN);
    HardwareModifyPin(DISPLAY_DDR, APPLY_MODE_SET, DISPLAY_3_PIN);

    HardwareModifyPin(SEGMENT_DDR, APPLY_MODE_SET, SEGMENT_A_PIN);
    HardwareModifyPin(SEGMENT_DDR, APPLY_MODE_SET, SEGMENT_B_PIN);
    HardwareModifyPin(SEGMENT_DDR, APPLY_MODE_SET, SEGMENT_C_PIN);
    HardwareModifyPin(SEGMENT_DDR, APPLY_MODE_SET, SEGMENT_D_PIN);
    HardwareModifyPin(SEGMENT_DDR, APPLY_MODE_SET, SEGMENT_E_PIN);
    HardwareModifyPin(SEGMENT_DDR, APPLY_MODE_SET, SEGMENT_F_PIN);
    if(SEGMENT_G_SEPERATE)
        HardwareModifyPin(SEPERATE_DDR, APPLY_MODE_SET, SEPERATE_G_PIN);
    else
        HardwareModifyPin(SEGMENT_DDR, APPLY_MODE_SET, SEGMENT_G_PIN);

    /* Add misc port initializations here: */
    HardwareModifyPin(MISC_DDR, APPLY_MODE_SET, MISC_DECIMAL_PIN);
}
