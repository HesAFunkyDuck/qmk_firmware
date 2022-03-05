/*
Copyright 2018 Mattia Dal Ben <matthewdibi@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

// wiring of each half
#define MATRIX_ROW_PINS { C6, D7, E6, B5, B4 }
#define MATRIX_COL_PINS { B6, B2, B3, B1, F7, F6, F5 }

/* Use I2C or Serial, not both */
#define USE_SERIAL
// #define USE_I2C

/* Select hand configuration */
#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

/* Other Configuration Settings */
#define TAPPING_TERM 200  // Default is 200*******ADJUST AS NEEDED

/* Other Settings to disable to save space */
#define LAYER_STATE_8BIT // I am using less than 8 layers
//#define NO_DEBUG // Make disabled after I know my config works
//#define NO_PRINT // Make disabled after I know my config works
#undef LOCKING_RESYNC_ENABLE // Locking resynchronize hack, seems to be for syncing up an led to indicate key lock status
#define NO_ACTION_ONESHOT // I am not using this right now so I will disable it for now

/* All LED Settings */
#define RGB_DI_PIN F4
#define RGBLED_NUM 16

//#define RGBLIGHT_SPLIT   // sync LEDs between RIGHT and LEFT hand
//#define RGBLED_SPLIT { 16, 16 }

//#define RGBLIGHT_ANIMATIONS

#define RGBLIGHT_EFFECT_BREATHING  //I like. Modes 0,1,2,3
// #define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL //I like. Modes 0,1,2,3,4,5
// #define RGBLIGHT_EFFECT_SNAKE
// #define RGBLIGHT_EFFECT_KNIGHT
// #define RGBLIGHT_EFFECT_CHRISTMAS
#define RGBLIGHT_EFFECT_STATIC_GRADIENT
// #define RGBLIGHT_EFFECT_RGB_TEST
#define RGBLIGHT_EFFECT_TWINKLE //I like. Modes 0,1,2,3,4,5

#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
#define RGBLIGHT_LIMIT_VAL 195

