#include QMK_KEYBOARD_H
//#include "print.h"  //This is for debugging. Comment out when done.

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _COLEMAK 0
#define _SYMB 1
#define _ARROW 2
#define _ADJUST 3
#define _CAD 4
#define _QWERTY 5


enum custom_keycodes {
  COLEMAK = SAFE_RANGE,
  SYMB,
  ARROW,
  ADJUST,
  QWERTY,
  //MACROS
  COPY,
  PASTE,
  FIND,
  ITEMNOTE,
  CADCOPY,
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

#define KC_MEHK MEH(KC_NO)//MEH
#define KC_HYPR HYPR(KC_NO)//Hyper triggers office on win10
#define KC_HYPE HYPR(KC_F24)//Hyper

//  ----------Layers----------
#define COL_L   TO(_COLEMAK)
#define SYM_L   TG(_SYMB)
#define SYM_LMO MO(_SYMB)
#define ARW_L   MO(_ARROW)
#define CAD_L   TO(_CAD)
#define QWE_L   TO(_QWERTY)
//  ----------Layers----------

//  ----------HOME ROW MODS---------- GASC
#define KC_GUIA LGUI_T(KC_A)
#define KC_ALTR LALT_T(KC_R)
#define KC_SFTS LSFT_T(KC_S)
#define KC_CTLT LCTL_T(KC_T)

#define KC_CTLN RCTL_T(KC_N)
#define KC_SFTE RSFT_T(KC_E)
#define KC_ALTI LALT_T(KC_I)
#define KC_GUIO RGUI_T(KC_O)

//  ----------HOME ROW MODS----------
#define KC_GUIZ LGUI_T(KC_Z)

#define KC_SFTC LSFT_T(KC_C)

#define KC_STCM RSFT_T(KC_COMM)

//  ----------BOTTOM ROW MODS----------



//  ----------BOTTOM ROW MODS----------

//  ----------MISC----------
#define KC_ALBS LALT_T(KC_BSLS)

#define KC_ADEN LT(_ADJUST, KC_END)
#define KC_ADPU LT(_ADJUST, KC_PGUP)

#define KC_ARW0 LT(_ARROW, KC_P0)

#define KC_CTDL LCTL_T(KC_DEL)
#define KC_CTET LCTL_T(KC_ENT)

#define KC_COBP LSFT(LCTL(KC_C))

//#define KC_ALAS LALT_T(KC_PAST)
//#define KC_CTPL LCTL_T(KC_BSLS)

//#define KC_NAGR LT(_NAV, KC_GRV)
//#define KC_NAMI LT(_NAV, KC_MINS)
//  ----------MISC----------

/*
add copy and paste buttons - done 220306
add JDE short cuts
add home row mods
home row mods are a little weird the tap function triggers to fast on the first tap. see if I can intercept those keypresses and send the key
on release if under the tapping term or send at 80ms

221010 - try to move home row mods to lower row

Make hyper key for autohotkey program shortcuts

Need key to lock numpad layer

add print screen button

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
     KC_ESC  ,KC_A     ,KC_R   ,KC_S    ,KC_T    ,KC_G    ,XXXXXXX ,                          SYM_L   ,KC_M    ,KC_N    ,KC_E    ,KC_I    ,KC_O    ,KC_QUOT ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT ,KC_GUIZ ,KC_X    ,KC_SFTC ,KC_D    ,KC_V    ,KC_ADPU ,KC_PGDN ,        KC_HOME ,KC_ADEN ,KC_K    ,KC_H    ,KC_STCM ,KC_DOT  ,KC_SLSH ,KC_RSFT ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     KC_LGUI ,FIND    ,COPY    ,PASTE   ,     KC_MEHK,     KC_BSPC ,KC_CTDL ,        KC_CTET ,KC_SPC  ,    ARW_L   ,     KC_HOME ,KC_END  ,KC_PGUP ,KC_PGDN
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_SYMB] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                            KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,KC_F11  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_EXLM ,KC_AT   ,KC_LCBR ,KC_RCBR ,KC_PIPE ,_______ ,                          _______ ,KC_PSLS ,KC_P7   ,KC_P8   ,KC_P9   ,KC_PMNS ,KC_F12  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_HASH ,KC_DLR  ,KC_LBRC ,KC_RBRC ,KC_GRV  ,COL_L   ,                          SYM_L   ,KC_PAST ,KC_P4   ,KC_P5   ,KC_P6   ,KC_PPLS ,SYM_L   ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_PERC ,KC_CIRC ,KC_LPRN ,KC_RPRN ,KC_TILD ,_______ ,_______ ,        _______ ,_______ ,XXXXXXX ,KC_P1   ,KC_P2   ,KC_P3   ,KC_PENT ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,     _______ ,    _______ ,_______ ,        _______ ,_______ ,    KC_ARW0 ,     KC_P0   ,KC_PDOT ,KC_PENT ,XXXXXXX
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_ARROW] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                            KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,KC_F11  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_F19  ,KC_F20  ,XXXXXXX ,XXXXXXX ,XXXXXXX ,_______ ,                          _______ ,XXXXXXX ,XXXXXXX ,KC_UP   ,XXXXXXX ,XXXXXXX ,KC_F12  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_GUIA ,KC_ALTR ,KC_SFTS ,KC_CTLT ,XXXXXXX ,_______ ,                          _______ ,XXXXXXX ,KC_LEFT ,KC_DOWN ,KC_RGHT ,XXXXXXX ,KC_CAPS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,_______ ,_______ ,        _______ ,_______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,     _______ ,    _______ ,_______ ,        _______ ,_______ ,    ARW_L   ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
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
     KC_ESC  ,KC_S    ,CADCOPY ,KC_M    ,KC_L    ,MTHPROP ,XXXXXXX ,                          COL_L   ,KC_QUOT ,KC_P4   ,KC_P5   ,KC_P6   ,XXXXXXX ,XXXXXXX ,
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
     KC_LGUI ,FIND    ,COPY    ,PASTE   ,     KC_ALBS ,    KC_BSPC ,KC_CTDL ,        KC_CTET ,KC_SPC  ,    KC_RALT ,     KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  )
};


// void keyboard_post_init_user(void) {
//     debug_enable = true;
//     debug_matrix = true;
// }


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_GUIA:
            return TAPPING_TERM + 50;
        case KC_ALTR:
            return TAPPING_TERM + 50;
        case KC_SFTS:
            return TAPPING_TERM + 50;
        case KC_CTLT:
            return TAPPING_TERM + 50;
        case KC_CTLN:
            return TAPPING_TERM + 50;
        case KC_SFTE:
            return TAPPING_TERM + 50;
        case KC_ALTI:
            return TAPPING_TERM + 50;
        case KC_GUIO:
            return TAPPING_TERM + 50;
        case KC_GUIZ:
            return TAPPING_TERM + 50;
        default:
            return TAPPING_TERM;
    }
}

//  ----------Combos----------
const uint16_t PROGMEM caps_combo[] = {KC_T, KC_N, COMBO_END};
const uint16_t PROGMEM numpad_combo[] = {KC_W, KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM itemNotes_combo[] = {KC_LGUI, COPY, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(caps_combo, KC_CAPS),
    COMBO(numpad_combo, SYM_L),
    COMBO(itemNotes_combo, ITEMNOTE),
};
//  ----------Combos----------

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
//  ----------LED MODES----------
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
//  ----------HOME ROW MOD FIX----------
    // case KC_S:
    //     if (record->event.pressed) {

    //     } else {
    //         tap_code_delay(KC_S, 100);
    //     }
    //     break;

    // case KC_R:
    //     if (record->event.pressed) {

    //     } else {
    //         tap_code_delay(KC_R, 100);
    //     }
    //     break;

//  ----------MACROS----------
    case COPY:
        if (record->event.pressed) {
            // when keycode COPY is pressed
            register_code(KC_LCTL);
            tap_code(KC_C);
        } else {
            unregister_code(KC_LCTL);
        }
        break;

    case PASTE:
        if (record->event.pressed) {
            // when keycode COPY is pressed
            register_code(KC_LCTL);
            tap_code(KC_V);
        } else {
            unregister_code(KC_LCTL);
        }
        break;

    case FIND:
        if (record->event.pressed) {
            // when keycode COPY is pressed
            register_code(KC_LCTL);
            register_code(KC_LALT);
            tap_code(KC_I);
        } else {
            unregister_code(KC_LCTL);
            unregister_code(KC_LALT);
        }
        break;

    case ITEMNOTE:
        if (record->event.pressed) {
            register_code(KC_LCTL);
            register_code(KC_LALT);
            tap_code(KC_R);
        } else {
            unregister_code(KC_LCTL);
            unregister_code(KC_LALT);
            tap_code(KC_DOWN);
            tap_code(KC_DOWN);
            tap_code(KC_DOWN);
            tap_code(KC_DOWN);
            tap_code(KC_DOWN);
            tap_code(KC_DOWN);
            tap_code(KC_DOWN);
            tap_code(KC_DOWN);
            tap_code(KC_DOWN);
            tap_code(KC_ENT);
        }
        break;

    case CADCOPY:
        if (record->event.pressed) {
            tap_code(KC_C);
            tap_code(KC_O);
        }
        break;

    case SCALE:
        if (record->event.pressed) {
            tap_code(KC_S);
            tap_code(KC_C);
        } else {
            tap_code(KC_ENT);
        }
        break;

    case MIRROR:
        if (record->event.pressed) {
            tap_code(KC_M);
            tap_code(KC_I);
        } else {
            tap_code(KC_ENT);
        }
        break;

    case ROTATE:
        if (record->event.pressed) {
            tap_code(KC_R);
            tap_code(KC_O);
        } else {
            tap_code(KC_ENT);
        }
        break;

    case TRIM:
        if (record->event.pressed) {
            tap_code(KC_T);
            tap_code(KC_R);
        } else {
            tap_code(KC_ENT);
        }
        break;

    case EXTEND:
        if (record->event.pressed) {
            tap_code(KC_E);
            tap_code(KC_X);
        } else {
            tap_code(KC_ENT);
        }
        break;

    case TRIMCIR:
        if (record->event.pressed) {
            tap_code(KC_T);
            tap_code(KC_X);
        } else {
            tap_code(KC_ENT);
        }
        break;

    case MTHPROP:
        if (record->event.pressed) {
            tap_code(KC_M);
            tap_code(KC_A);
        } else {
            tap_code(KC_ENT);
        }
        break;

    case REC:
        if (record->event.pressed) {
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
