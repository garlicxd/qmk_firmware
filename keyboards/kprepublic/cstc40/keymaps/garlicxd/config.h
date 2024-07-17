/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once

#define LAYER_STATE_32BIT

// unicode
#define UNICODE_SELECTED_MODES UNICODE_MODE_WINCOMPOSE

// tap toggle layer key
#define TAPPING_TOGGLE 1

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define QUICK_TAP_TERM 0

#define COMBO_SHOULD_TRIGGER

// Layer Lock feature timeout
#define LAYER_LOCK_IDLE_TIMEOUT 60000

// rgb stuff
#define RGB_MATRIX_DEFAULT_SPD 64

#define ENABLE_RGB_MATRIX_BREATHING
#define RGB_MATRIX_DEFAULT_HUE 20   // Sets the default hue value, if none has been set
#define RGB_MATRIX_DEFAULT_SAT 80   // Sets the default saturation value, if none has been set
#define RGB_MATRIX_DEFAULT_VAL 100  // Sets the default brightness value, if none has been set