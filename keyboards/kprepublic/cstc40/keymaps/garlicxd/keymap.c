/* Copyright 2023
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "features/layer_lock.h"

enum custom_layers {
    _DEFAULT,
    _DEFAULT_CAPS,
    _FUNCTION,
    _MOUSE,
    _NAVIGATION,
    _SYMBOLS,
    _SPECIAL,
    _SPECIAL_CAPS,
    _QWERTY,
    _LEAGUE,
    _CHAT
};
enum custom_keycodes {
    LLOCK = SAFE_RANGE,
    CHAT,
    ACHAT,
    ENTnLEA
};

// combos
enum combo_events {
  JUMP_UP,
  JUMP_DOWN,
};
const uint16_t PROGMEM ctrl_up[] = {KC_LCTL, KC_UP, COMBO_END};
const uint16_t PROGMEM ctrl_down[] = {KC_LCTL, KC_DOWN, COMBO_END};
combo_t key_combos[] = {
  [JUMP_UP] = COMBO_ACTION(ctrl_up),
  [JUMP_DOWN] = COMBO_ACTION(ctrl_down),
};

// unicode
enum unicode_names {
    SS,
    AA,
    AAA,
    AAAA,
    AE,
    EE,
    II,
    OO,
    OOO,
    OOOO,
    OOOOO,
    UU,
    UUU,
    UUUU,
    CSS,
    CAA,
    CAAA,
    CAAAA,
    CAE,
    CEE,
    CII,
    COO,
    COOO,
    COOOO,
    COOOOO,
    CUU,
    CUUU,
    CUUUU
};
const uint32_t PROGMEM unicode_map[] = {
    [SS] = 0x00DF, // ß
    [AA] = 0x00E1, // á
    [AAA] = 0x00E4, // ä
    [AAAA] = 0x00E5, // å
    [AE] = 0x00E6, // æ
    [EE] = 0x00E9, // é
    [II] = 0x00ED, // í
    [OO] = 0x00F3, // ó
    [OOO] = 0x00F6, // ö
    [OOOO] = 0x0151, // ő
    [OOOOO] = 0x00F8, // ø
    [UU] = 0x00FA, // ú
    [UUU] = 0x00FC, // ü
    [UUUU] = 0x0171, // ű
    [CSS] = 0x1E9E, // ẞ
    [CAA] = 0x00C1, // Á
    [CAAA] = 0x00C4, // Ä
    [CAAAA] = 0x00C5, // Å
    [CAE] = 0x00C6, // Æ
    [CEE] = 0x00C9, // É
    [CII] = 0x00CD, // Í
    [COO] = 0x00D3, // Ó
    [COOO] = 0x00D6, // Ö
    [COOOO] = 0x0150, // Ő
    [COOOOO] = 0x00D8, // Ø
    [CUU] = 0x00DA, // Ú
    [CUUU] = 0x00DC, // Ü
    [CUUUU] = 0x0170, // Ű
};

#define U_SS UP(SS, CSS)
#define U_A1 UP(AA, CAA)
#define U_A2 UP(AAA, CAAA)
#define U_A3 UP(AAAA, CAAAA)
#define U_AE UP(AE, CAE)
#define U_E1 UP(EE, CEE)
#define U_I1 UP(II, CII)
#define U_O1 UP(OO, COO)
#define U_O2 UP(OOO, COOO)
#define U_O3 UP(OOOO, COOOO)
#define U_O4 UP(OOOOO, COOOOO)
#define U_U1 UP(UU, CUU)
#define U_U2 UP(UUU, CUUU)
#define U_U3 UP(UUUU, CUUUU)

// default layer keys
#define TAB_SYM LT(_FUNCTION, KC_TAB)
#define KCR_NAV LT(_NAVIGATION, KC_R)
#define ENT_CAP LT(_DEFAULT_CAPS, KC_ENT)
#define BSP_MOU LT(_MOUSE, KC_BSPC)
#define SPC_SYM LT(_SYMBOLS, KC_SPC)
#define DEL_SPE LT(_SPECIAL, KC_DEL)

// additional layer keys
#define SCL_NAV LT(_NAVIGATION, KC_SCLN)
#define ENT_SCA LT(_SPECIAL_CAPS, KC_ENT)

#define L_DEF TO(_DEFAULT)
#define L_QWE TO(_QWERTY)

#define A_TAB A(KC_TAB)
#define C_TAB C(KC_TAB)

#define SLOT_1 TO(_QWERTY)
#define SLOT_2 TO(_LEAGUE)
#define SLOT_3 _______
#define SLOT_4 _______
#define SLOT_5 _______
#define SLOT_6 _______

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    switch (keycode) {
    case CHAT:
        if (record->event.pressed) {
            tap_code(KC_ENT);
            layer_move(_CHAT);
        }
        return false; // Skip all further processing of this key

    case ACHAT:
        if (record->event.pressed) {
            tap_code16(S(KC_ENT));
            layer_move(_CHAT);
        }
        return false; // Skip all further processing of this key

    case ENTnLEA:
        if (record->event.pressed) {
            tap_code(KC_ENT);
            layer_move(_LEAGUE);
        }
        return false; // Skip all further processing of this key

    case KC_ENT:
        if (record->event.pressed) {
            // rgb_matrix_set_color_all(0xFF,  0xFF, 0xFF);
        }
        return false;

    default:
        return true; // Process all other keycodes normally
    }

    // Layer Lock
    if (!process_layer_lock(keycode, record, LLOCK)) { return false; }
    
    return true;
}

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case JUMP_UP:
      if (pressed) {
        tap_code16(KC_PGUP);
        // tap_code(KC_UP);
        // tap_code(KC_UP);
        // tap_code(KC_UP);
        // tap_code(KC_UP);
        // tap_code(KC_UP);
      }
      break;
    case JUMP_DOWN:
      if (pressed) {
        tap_code16(KC_PGDN);
        // tap_code(KC_DOWN);
        // tap_code(KC_DOWN);
        // tap_code(KC_DOWN);
        // tap_code(KC_DOWN);
        // tap_code(KC_DOWN);
      }
      break;
  }
}

void matrix_scan_user(void) {
    layer_lock_task();
}

// layer_state_t layer_state_set_user(layer_state_t state) {
//     switch (get_highest_layer(state)) {
//     case _LEAGUE:
//         rgb_matrix_set_color_all(0x00,  0x00, 0xFF);
//         break;

//     default: //  for any other layers, or the default layer
//         rgb_matrix_set_color_all(0x00,  0xFF, 0xFF);
//         break;
//     }
//   return state;
// }

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_DEFAULT] = LAYOUT_planck_mit(
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    KC_X,   KC_P,   KC_D,   KC_M,   KC_Q,   SLOT_1, SLOT_2, KC_AMPR,KC_Y,   KC_O,   KC_U,   KC_QUOT,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    KC_S,   KC_N,   KC_T,   KC_H,   KC_V,   SLOT_3, SLOT_4, KC_G,   KC_C,   KC_A,   KC_E,   KC_I,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    KC_F,   KC_B,   KC_K,   KC_L,   KC_J,   SLOT_5, SLOT_6, KC_Z,   KC_W,   KC_DQUO,KC_COMM,KC_DOT,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    KC_PSCR,KC_LGUI,TAB_SYM,KCR_NAV,ENT_CAP,    _______,    BSP_MOU,SPC_SYM,DEL_SPE,KC_ESC, _______
//-+-------+-------+-------+-------+-------+---------------+-------+-------+-------+-------+-------+
),

[_DEFAULT_CAPS] = LAYOUT_planck_mit(
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    S(KC_X),S(KC_P),S(KC_D),S(KC_M),S(KC_Q),_______,_______,KC_HASH,S(KC_Y),S(KC_O),S(KC_U),KC_AT,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    S(KC_S),S(KC_N),S(KC_T),S(KC_H),S(KC_V),_______,_______,S(KC_G),S(KC_C),S(KC_A),S(KC_E),S(KC_I),
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    S(KC_F),S(KC_B),S(KC_K),S(KC_L),S(KC_J),_______,_______,S(KC_Z),S(KC_W),KC_BSLS,KC_GRV, KC_TILD,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    _______,_______,KC_UNDS,S(KC_R),KC_MINS,     LLOCK,     KC_BSPC, KC_SPC, KC_DEL, _______,_______
//-+-------+-------+-------+-------+-------+---------------+-------+-------+-------+-------+-------+
),

[_SYMBOLS] = LAYOUT_planck_mit(
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    KC_1,   KC_2,   KC_3,   KC_4,   KC_PERC,_______,_______,KC_DLR, KC_6,   KC_7,   KC_8,   KC_9,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    KC_LT,  KC_LBRC,KC_LCBR,KC_LPRN,KC_5,   _______,_______,KC_0,   KC_EQL, KC_SLSH,KC_EXLM,KC_QUES,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    KC_MINS,KC_PLUS,KC_CIRC,KC_COLN,KC_ASTR,_______,_______,KC_PIPE,KC_RPRN,KC_RCBR,KC_RBRC,KC_GT,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    _______,_______,KC_DOT, SCL_NAV,KC_COMM,     LLOCK,     _______,_______,_______,_______,_______
//-+-------+-------+-------+-------+-------+---------------+-------+-------+-------+-------+-------+
),

[_NAVIGATION] = LAYOUT_planck_mit(
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    _______,A_TAB,  KC_UP,  C_TAB,  KC_INS, _______,_______,_______,_______,_______,_______,_______,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    KC_HOME,KC_LEFT,KC_DOWN,KC_RGHT,KC_END, _______,_______,_______,KC_ENT, KC_LSFT,KC_LCTL,KC_LALT,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    C(KC_Z),C(KC_C),C(KC_X),C(KC_V),C(KC_Y),_______,_______,_______,_______,_______,_______,_______,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    _______,_______,_______,_______,_______,      LLOCK,    KC_BSPC,KC_SPC, KC_DEL, _______,_______
//-+-------+-------+-------+-------+-------+---------------+-------+-------+-------+-------+-------+
),

[_FUNCTION] = LAYOUT_planck_mit(
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    KC_F1,  KC_F2,  KC_F3,  KC_F4,  _______,_______,_______,_______,_______,RGB_TOG,QK_RBT, QK_BOOT,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    KC_F5,  KC_F6,  KC_F7,  KC_F8,  _______,_______,_______,_______,_______,_______,_______,_______,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    KC_F9,  KC_F10, KC_F11, KC_F12, _______,_______,_______,_______,_______,_______,_______,_______,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    _______,_______,_______,_______,_______,     LLOCK,     _______,_______,_______,_______,_______
//-+-------+-------+-------+-------+-------+---------------+-------+-------+-------+-------+-------+
),

[_SPECIAL] = LAYOUT_planck_mit(
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    _______,_______,_______,_______,_______,_______,_______,U_O3,   U_O2,   U_O1,   U_O4,   U_SS,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    _______,_______,_______,_______,_______,_______,_______,U_A3,   U_A2,   U_A1,   U_E1,   U_I1,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    _______,_______,_______,_______,_______,_______,_______,U_U3,   U_U2,   U_U1,   _______,_______,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    _______,_______,_______,_______,ENT_SCA,     LLOCK,     KC_BSPC,KC_SPC, KC_DEL, _______,_______
//-+-------+-------+-------+-------+-------+---------------+-------+-------+-------+-------+-------+
),

[_SPECIAL_CAPS] = LAYOUT_planck_mit(
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    _______,_______,_______,_______,_______,_______,_______,S(U_O3),S(U_O2),S(U_O1),S(U_O4),S(U_SS),
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    _______,_______,_______,_______,_______,_______,_______,S(U_A3),S(U_A2),S(U_A1),S(U_E1),S(U_I1),
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    _______,_______,_______,_______,_______,_______,_______,S(U_U3),S(U_U2),S(U_U1),_______,_______,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    _______,_______,_______,_______,ENT_SCA,     LLOCK,     KC_BSPC,KC_SPC, KC_DEL, _______,_______
//-+-------+-------+-------+-------+-------+---------------+-------+-------+-------+-------+-------+
),

[_QWERTY] = LAYOUT_planck_mit(
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    KC_TAB, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_BSPC,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    KC_ESC, KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,  KC_SCLN, KC_QUOT,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    KC_LSFT,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_ENT,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    KC_PSCR,KC_LCTL,KC_LALT,KC_ENT, KC_LGUI,     L_DEF,     KC_BSPC,KC_SPC, KC_DEL, KC_RCTL,KC_RALT
//-+-------+-------+-------+-------+-------+---------------+-------+-------+-------+-------+-------+
),

[_LEAGUE] = LAYOUT_planck_mit(
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   _______,_______,_______,_______,_______,_______,_______,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    KC_Q,   KC_W,   KC_E,   KC_R,   KC_LCTL,_______,_______,KC_ENT, _______,_______,_______,_______,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    KC_6,   KC_7,   KC_D,   KC_F,   KC_LSFT,_______,_______,_______,_______,_______,_______,_______,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    KC_F12, _______,KC_TAB, KC_SPC, CHAT,       L_DEF,     _______,_______,_______,_______,_______
//-+-------+-------+-------+-------+-------+---------------+-------+-------+-------+-------+-------+
),

[_CHAT] = LAYOUT_planck_mit(
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    KC_X,   KC_P,   KC_D,   KC_M,   KC_Q,   SLOT_1, SLOT_2, KC_AMPR,KC_Y,   KC_O,   KC_U,   KC_QUOT,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    KC_S,   KC_N,   KC_T,   KC_H,   KC_V,   SLOT_3, SLOT_4, KC_G,   KC_C,   KC_A,   KC_E,   KC_I,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    KC_F,   KC_B,   KC_K,   KC_L,   KC_J,   SLOT_5, SLOT_6, KC_Z,   KC_W,   KC_DQUO,KC_COMM,KC_DOT,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    _______,KC_LGUI,TAB_SYM,KCR_NAV,ENTnLEA,     L_DEF,     BSP_MOU,SPC_SYM,DEL_SPE,KC_ESC, _______
//-+-------+-------+-------+-------+-------+---------------+-------+-------+-------+-------+-------+
),

};

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
// [3] = LAYOUT_planck_mit(
//     _______,  QK_BOOT,  DB_TOGG,  RGB_TOG,  RGB_MOD,  RGB_HUI,  RGB_HUD,  RGB_SAI,  RGB_SAD,  RGB_VAI,  RGB_VAD,  KC_DEL,
//     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
//     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
//     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______   
// )
