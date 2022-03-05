#include QMK_KEYBOARD_H
//#include "print.h"  //This is for debugging. Comment out when done.

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _COLEMAK 0
#define _SYMB 1
#define _ADJUST 2
#define _CAD 3
#define _QWERTY 4


enum custom_keycodes {
  COLEMAK = SAFE_RANGE,
  SYMB,
  ADJUST,
  QWERTY,
  //MACROS
  COPY,
  SCALE,
  MIRROR,
  ROTATE,
  TRIM,
  EXTEND,
  TRIMCIR,
  MTHPROP,
  REC,
  //LED MODES
  LED_B_0,
  LED_B_1,
  LED_SW_5,
  LED_TW_1,
  LED_G_7,
  LED_G_9,
  GETHSV,
  GETMODE,
};

// Shortcut to make keymap more readable
#define COL_L   TO(_COLEMAK)
#define SYM_L   TG(_SYMB)
#define SYM_LMO MO(_SYMB)
#define CAD_L   TO(_CAD)
#define QWE_L   TO(_QWERTY)


#define KC_ALAS LALT_T(KC_PAST)
#define KC_CTPL LCTL_T(KC_BSLS)

//#define KC_NAGR LT(_NAV, KC_GRV)
//#define KC_NAMI LT(_NAV, KC_MINS)

#define KC_ADEN LT(_ADJUST, KC_END)
#define KC_ADPU LT(_ADJUST, KC_PGUP)

#define KC_CTDL LCTL_T(KC_DEL)
#define KC_CTET LCTL_T(KC_ENT)

#define KC_COBP LSFT(LCTL(KC_C))


/*
add copy and paste buttons


Add control to right hand, make it a home row mod
Add LED layer indication
https://docs.qmk.fm/#/feature_rgblight?id=lighting-layers
https://docs.qmk.fm/#/custom_quantum_functions?id=layer-change-code
*/


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAK] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_MINS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB  ,KC_Q    ,KC_W    ,KC_F    ,KC_P    ,KC_B    ,SYM_LMO ,                          SYM_LMO ,KC_J    ,KC_L    ,KC_U    ,KC_Y    ,KC_SCLN ,KC_EQL  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_ESC  ,KC_A    ,KC_R    ,KC_S    ,KC_T    ,KC_G    ,XXXXXXX ,                          SYM_L   ,KC_M    ,KC_N    ,KC_E    ,KC_I    ,KC_O    ,KC_QUOT ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_D    ,KC_V    ,KC_ADPU ,KC_PGDN ,        KC_HOME ,KC_ADEN ,KC_K    ,KC_H    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_RSFT ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     KC_LGUI ,KC_PPLS ,KC_PMNS ,KC_ALAS ,     KC_CTPL ,    KC_BSPC ,KC_CTDL ,        KC_CTET ,KC_SPC  ,    KC_RALT ,     KC_LEFT ,KC_RGHT ,KC_UP   ,KC_DOWN
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_SYMB] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                            KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_EXLM ,KC_AT   ,KC_LCBR ,KC_RCBR ,KC_PIPE ,_______ ,                          _______ ,KC_PSLS ,KC_P7   ,KC_P8   ,KC_P9   ,KC_PMNS ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_HASH ,KC_DLR  ,KC_LBRC ,KC_RBRC ,KC_GRV  ,COL_L   ,                          SYM_L   ,KC_PAST ,KC_P4   ,KC_P5   ,KC_P6   ,KC_PPLS ,KC_CAPS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_PERC ,KC_CIRC ,KC_LPRN ,KC_RPRN ,KC_TILD ,_______ ,_______ ,        _______ ,_______ ,XXXXXXX ,KC_P1   ,KC_P2   ,KC_P3   ,KC_PENT ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,     _______ ,    _______ ,_______ ,        _______ ,_______ ,    KC_P0   ,     KC_P0   ,KC_PDOT ,KC_PENT ,XXXXXXX
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     RESET   ,XXXXXXX ,XXXXXXX ,RGB_HUI ,RGB_SAI ,RGB_VAI ,                                            KC_MUTE ,KC_VOLD ,KC_VOLU ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_TOG ,RGB_M_P ,XXXXXXX ,RGB_HUD ,RGB_SAD ,RGB_VAD ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_M_B ,RGB_M_SW,RGB_M_TW,RGB_M_G ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     LED_B_0 ,LED_SW_5,LED_TW_1,LED_G_7 ,XXXXXXX ,GETMODE ,_______ ,XXXXXXX ,        XXXXXXX ,_______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     LED_B_1 ,XXXXXXX ,XXXXXXX ,LED_G_9 ,      GETHSV ,    XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,    XXXXXXX ,     XXXXXXX ,CAD_L   ,QWE_L   ,XXXXXXX
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_CAD] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_F3   ,KC_F8   ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,KC_D    ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_R    ,SCALE   ,KC_S    ,MIRROR  ,KC_O    ,ROTATE  ,XXXXXXX ,                          XXXXXXX ,KC_MINS ,KC_P7   ,KC_P8   ,KC_P9   ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_ESC  ,KC_S    ,COPY    ,KC_M    ,KC_L    ,MTHPROP ,XXXXXXX ,                          COL_L   ,KC_QUOT ,KC_P4   ,KC_P5   ,KC_P6   ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT ,KC_J    ,KC_F    ,EXTEND  ,TRIM    ,TRIMCIR ,_______ ,XXXXXXX ,        XXXXXXX ,_______ ,KC_DQUO ,KC_P1   ,KC_P2   ,KC_P3   ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     KC_COBP ,XXXXXXX ,KC_C    ,REC     ,     KC_LSFT ,    KC_ENT  ,KC_DEL  ,        KC_ENT  ,XXXXXXX ,    KC_P0   ,     XXXXXXX ,KC_PDOT ,XXXXXXX ,XXXXXXX
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

    [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐'
     KC_GRV  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_MINS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,SYM_LMO ,                          SYM_LMO ,KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_EQL  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_ESC  ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,COL_L   ,                          KC_RBRC ,KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_SCLN ,KC_QUOT ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,KC_ADPU ,KC_PGDN ,        KC_HOME ,KC_ADEN ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_RSFT ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     KC_LGUI ,KC_PPLS ,KC_PMNS ,KC_ALAS ,     KC_CTPL ,    KC_BSPC ,KC_CTDL ,        KC_CTET ,KC_SPC  ,    KC_RALT ,     KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  )
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case LED_B_0:
        if (record->event.pressed) {
            rgblight_mode(2);
        }
        break;

    case LED_B_1:
        if (record->event.pressed) {
            rgblight_mode(3);
        }
        break;

    case LED_SW_5:
        if (record->event.pressed) {
            rgblight_mode(11);
        }
        break;

    case LED_TW_1:
        if (record->event.pressed) {
            rgblight_mode(23);
        }
        break;

    case LED_G_7:
        if (record->event.pressed) {
            rgblight_mode(20);
        }
        break;

    case LED_G_9:
        if (record->event.pressed) {
            rgblight_mode(21);
        }
        break;

    case GETHSV:
        if (record->event.pressed) {
            uprintf("Hue:%d\n", rgblight_get_hue());
            uprintf("Sat:%d\n", rgblight_get_sat());
            uprintf("Val:%d\n", rgblight_get_val());
        } else {
        }
        break;

    case GETMODE:
        if(record->event.pressed){
            uprintf("Mode Number:%d\n", rgblight_get_mode());
        }

    case COPY:
        if (record->event.pressed) {
            // when keycode M_TEST is pressed
            tap_code(KC_C);
            tap_code(KC_O);
        } else {
            tap_code(KC_ENT);
        }
        break;

    case SCALE:
        if (record->event.pressed) {
            // when keycode M_TEST is pressed
            tap_code(KC_S);
            tap_code(KC_C);
        } else {
            tap_code(KC_ENT);
        }
        break;

    case MIRROR:
        if (record->event.pressed) {
            // when keycode M_TEST is pressed
            tap_code(KC_M);
            tap_code(KC_I);
        } else {
            tap_code(KC_ENT);
        }
        break;

    case ROTATE:
        if (record->event.pressed) {
            // when keycode M_TEST is pressed
            tap_code(KC_R);
            tap_code(KC_O);
        } else {
            tap_code(KC_ENT);
        }
        break;

    case TRIM:
        if (record->event.pressed) {
            // when keycode M_TEST is pressed
            tap_code(KC_T);
            tap_code(KC_R);
        } else {
            tap_code(KC_ENT);
        }
        break;

    case EXTEND:
        if (record->event.pressed) {
            // when keycode M_TEST is pressed
            tap_code(KC_E);
            tap_code(KC_X);
        } else {
            tap_code(KC_ENT);
        }
        break;

    case TRIMCIR:
        if (record->event.pressed) {
            // when keycode M_TEST is pressed
            tap_code(KC_T);
            tap_code(KC_X);
        } else {
            tap_code(KC_ENT);
        }
        break;

    case MTHPROP:
        if (record->event.pressed) {
            // when keycode M_TEST is pressed
            tap_code(KC_M);
            tap_code(KC_A);
        } else {
            tap_code(KC_ENT);
        }
        break;

    case REC:
        if (record->event.pressed) {
            // when keycode M_TEST is pressed
            tap_code(KC_R);
            tap_code(KC_E);
            tap_code(KC_C);
        } else {
            tap_code(KC_ENT);
        }
        break;
    }
    return true;
};
