#include QMK_KEYBOARD_H
// #include "features/layer_lock.h"

enum custom_layers {

    _DEFAULT,

    _QWERTY,
    _GAMING,

    _CAPS,
    _TNAV,
    _SNAV,
    _SYMB,
    _FUNC,

};

// enum custom_keycodes {
//     // LLOCK = SAFE_RANGE,
//     // KCP_CHT,
//     // ENT_CHT,
//     // BYE_CHT,
//     // GIT_ALL,
// };

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
    [SS]        = 0x00DF, // ß
    [AA]        = 0x00E1, // á
    [AAA]       = 0x00E4, // ä
    [AAAA]      = 0x00E5, // å
    [AE]        = 0x00E6, // æ
    [EE]        = 0x00E9, // é
    [II]        = 0x00ED, // í
    [OO]        = 0x00F3, // ó
    [OOO]       = 0x00F6, // ö
    [OOOO]      = 0x0151, // ő
    [OOOOO]     = 0x00F8, // ø
    [UU]        = 0x00FA, // ú
    [UUU]       = 0x00FC, // ü
    [UUUU]      = 0x0171, // ű
    [CSS]       = 0x1E9E, // ẞ
    [CAA]       = 0x00C1, // Á
    [CAAA]      = 0x00C4, // Ä
    [CAAAA]     = 0x00C5, // Å
    [CAE]       = 0x00C6, // Æ
    [CEE]       = 0x00C9, // É
    [CII]       = 0x00CD, // Í
    [COO]       = 0x00D3, // Ó
    [COOO]      = 0x00D6, // Ö
    [COOOO]     = 0x0150, // Ő
    [COOOOO]    = 0x00D8, // Ø
    [CUU]       = 0x00DA, // Ú
    [CUUU]      = 0x00DC, // Ü
    [CUUUU]     = 0x0170, // Ű
};

#define U_SS UM(SS)
#define U_A1 UM(AA)
#define U_A2 UM(AAA)
#define U_A3 UM(AAAA)
#define U_AE UM(AE)
#define U_E1 UM(EE)
#define U_I1 UM(II)
#define U_O1 UM(OO)
#define U_O2 UM(OOO)
#define U_O3 UM(OOOO)
#define U_O4 UM(OOOOO)
#define U_U1 UM(UU)
#define U_U2 UM(UUU)
#define U_U3 UM(UUUU)

// caps unicode layer keys
#define U_CSS UM(CSS)
#define U_CA1 UM(CAA)
#define U_CA2 UM(CAAA)
#define U_CA3 UM(CAAAA)
#define U_CAE UM(CAE)
#define U_CE1 UM(CEE)
#define U_CI1 UM(CII)
#define U_CO1 UM(COO)
#define U_CO2 UM(COOO)
#define U_CO3 UM(COOOO)
#define U_CO4 UM(COOOOO)
#define U_CU1 UM(CUU)
#define U_CU2 UM(CUUU)
#define U_CU3 UM(CUUUU)

#define L_SNAV LT(_SNAV, KC_LGUI)
#define L_TNAV LT(_TNAV, KC_SPC)
#define L_CAPS LT(_CAPS, KC_ENT)
#define L_SYMB LT(_SYMB, KC_R)
#define L_FUNC LT(_FUNC, KC_ESC)

// static uint16_t last_chatter = _______;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    // switch (keycode) {

    //     // case GIT_ALL:
    //     //     if (record->event.pressed) {
    //     //         SEND_STRING("git add .\ngit commit -a -m \"commit\"\ngit push");
    //     //     }
    //     //     return false;

    //     // case KCP_CHT:
    //     //     if (record->event.pressed) {
    //     //         tap_code(KC_P);
    //     //         last_chatter = KC_P;
    //     //         layer_invert(_CHAT);
    //     //     }
    //     //     return false;

    //     // case BYE_CHT:
    //     //     if (record->event.pressed) {
    //     //         tap_code(last_chatter);
    //     //         layer_invert(_CHAT);
    //     //     }
    //     //     return false;  

    //     // case ENT_CHT:
    //     //     if (record->event.pressed) {
    //     //         tap_code(KC_ENT);
    //     //         last_chatter = KC_ENT;
    //     //         layer_invert(_CHAT);
    //     //     }
    //     //     return false;

    //     // case BIT_BRW:
    //     //     if (record->event.pressed) {
    //     //             tap_code16(TOGBROW);
    //     //             last_chatter = TOGBROW;
    //     //             layer_invert(_CHAT);
    //     //         }
    //     //         return false;
    //     // case BIT_MID:
    //     //     if (record->event.pressed) {
    //     //             tap_code16(TOGMIDI);
    //     //             layer_move(_MIDI);
    //     //         }
    //     //         return false;
    //     // case BIT_DJL:
    //     //     if (record->event.pressed) {
    //     //             tap_code16(TOGMIDI);
    //     //             layer_move(_DJ);
    //     //         }
    //     //         return false;
    // }

    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_DEFAULT] = LAYOUT_planck_mit(
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    KC_PSCR, KC_B,   KC_Y,   KC_O,   KC_U, KC_BSPC, KC_X,   KC_L,   KC_D,   KC_W,   KC_V,   KC_DEL,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
KC_QUES,ALT_T(KC_C),CTL_T(KC_I),GUI_T(KC_E),SFT_T(KC_A),KC_MINS,KC_K,SFT_T(KC_H),GUI_T(KC_T),CTL_T(KC_N),ALT_T(KC_S),KC_QUOT,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    KC_Z,   KC_COMM,KC_COLN,KC_SLSH,KC_DOT,KC_BSLS, KC_J,   KC_M,   KC_G,   KC_P,   KC_F,   KC_Q,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    KC_LGUI,_______,_______,L_SNAV, L_TNAV,      L_CAPS,    L_SYMB, L_FUNC, _______,_______,_______
//-+-------+-------+-------+-------+-------+---------------+-------+-------+-------+-------+-------+
),

[_CAPS] = LAYOUT_planck_mit(
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    _______,S(KC_B),S(KC_Y),S(KC_O),S(KC_U),KC_BSPC,S(KC_X),S(KC_L),S(KC_D),S(KC_W),S(KC_V),_______,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    _______,S(KC_C),S(KC_I),S(KC_E),S(KC_A),KC_UNDS,S(KC_K),S(KC_H),S(KC_T),S(KC_N),S(KC_S),_______,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    S(KC_Z),KC_AT,  KC_AMPR,KC_GRV, KC_HASH,_______,S(KC_J),S(KC_M),S(KC_G),S(KC_P),S(KC_F),S(KC_Q),
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    _______,_______,_______,_______,_______,    _______,    S(KC_R),_______,_______,_______,_______
//-+-------+-------+-------+-------+-------+---------------+-------+-------+-------+-------+-------+
),

[_SYMB] = LAYOUT_planck_mit(
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    _______,KC_3,   KC_2,   KC_1,   KC_0,   _______,_______,KC_5,   KC_6,   KC_7,   KC_8,   _______,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    KC_EXLM,KC_PLUS,KC_DQT, KC_DLR, KC_EQL, KC_MINS, KC_4,   KC_LT,  KC_LPRN,KC_RPRN,KC_GT,  KC_9,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    KC_PERC,KC_COMM,KC_ASTR,KC_SLSH,KC_DOT, KC_CIRC,KC_PIPE,KC_LBRC,KC_LCBR,KC_RCBR,KC_RBRC,KC_SCLN,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    _______,_______,_______,KC_UNDS,_______,    KC_TILD,    _______,_______,_______,_______,_______
//-+-------+-------+-------+-------+-------+---------------+-------+-------+-------+-------+-------+
),

[_TNAV] = LAYOUT_planck_mit(
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    _______,KC_3,   KC_2,   KC_1,   KC_0,   _______,_______,KC_5,   KC_6,   KC_7,   KC_8,   _______,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    _______,_______,_______,_______,_______,_______,KC_4,   KC_LEFT,KC_DOWN,KC_UP,  KC_RGHT,KC_9,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    _______,_______,_______,_______,_______,_______,_______,KC_HOME,KC_PGDN,KC_PGUP,KC_END,_______,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    _______,_______,_______,_______,_______,    _______,    _______,_______,_______,_______,_______
//-+-------+-------+-------+-------+-------+---------------+-------+-------+-------+-------+-------+
),

[_SNAV] = LAYOUT_planck_mit(
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    _______,G(KC_3),G(KC_2),G(KC_1),C(KC_Z),_______,_______,KC_5,   KC_6,   KC_7,   KC_8,   _______,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    G(KC_TAB),_______,_______,_______,_______,_______,KC_4,   KC_LEFT,KC_DOWN,KC_UP,  KC_RGHT,KC_9,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    _______,C(KC_C),C(KC_X),C(KC_V),C(KC_Y),_______,_______,KC_HOME,KC_PGDN,KC_PGUP,KC_END,_______,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    _______,_______,_______,_______,_______,    _______,    _______,_______,_______,_______,_______
//-+-------+-------+-------+-------+-------+---------------+-------+-------+-------+-------+-------+
),

[_FUNC] = LAYOUT_planck_mit(
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    KC_F4,  KC_F3,  KC_F2,  KC_F1,  _______,_______,_______,_______,_______,_______,QK_RBT, QK_BOOT,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    KC_F8,  KC_F7,  KC_F6,  KC_F5,  _______,_______,_______,_______,_______,_______,_______,_______,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    KC_F12, KC_F11, KC_F10, KC_F9,  _______,_______,_______,_______,_______,_______,_______,_______,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    _______,_______,_______,_______,_______,    _______,    _______,_______,_______,_______,_______
//-+-------+-------+-------+-------+-------+---------------+-------+-------+-------+-------+-------+
),

[_QWERTY] = LAYOUT_planck_mit( // WIP
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    KC_DEL, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_BSPC,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    KC_LCTL,KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,  KC_SCLN, KC_QUOT,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    KC_BSPC,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_ENT,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    KC_LGUI,KC_ESC, KC_TAB, KC_SPC, KC_LSFT,    _______,   KC_LSFT,KC_SPC, KC_LALT,KC_RCTL,KC_RALT
//-+-------+-------+-------+-------+-------+---------------+-------+-------+-------+-------+-------+
),

[_GAMING] = LAYOUT_planck_mit( // WIP
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    KC_DEL, KC_3,   KC_2,   KC_1,   KC_0,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_BSPC,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    KC_LCTL,KC_G,   KC_A,   KC_W,   KC_D,   KC_F,   KC_H,   KC_J,   KC_K,   KC_L,  KC_SCLN, KC_QUOT,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    KC_BSPC,KC_Z,   KC_C,   KC_S,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_ENT,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    KC_LGUI,KC_ESC, KC_TAB, KC_SPC, KC_LSFT,    _______,     KC_LSFT,KC_SPC, KC_LALT,KC_RCTL,KC_RALT
//-+-------+-------+-------+-------+-------+---------------+-------+-------+-------+-------+-------+
),

// [_DEFAULT_CAPS] = LAYOUT_planck_mit(
// //-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
//     _______,S(KC_U),S(KC_O),S(KC_Y),KC_GRV, SLOT_1, SLOT_2, S(KC_Q),S(KC_M),S(KC_D),S(KC_P),S(KC_X),
// //-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
//     S(KC_I),S(KC_E),S(KC_A),S(KC_C),S(KC_G),SLOT_3, SLOT_4, S(KC_V),S(KC_H),S(KC_T),S(KC_N),S(KC_S),
// //-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
//     _______,KC_AT,  KC_HASH,S(KC_W),S(KC_Z),SLOT_5, SLOT_6, S(KC_J),S(KC_L),S(KC_K),S(KC_B),S(KC_F),
// //-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
//     _______,_______,_______,_______,_______,     LLOCK,     LT_SPC, S(KC_R),KC_UNDS,_______,_______
// //-+-------+-------+-------+-------+-------+---------------+-------+-------+-------+-------+-------+
// ),

// [_SYMBOLS] = LAYOUT_planck_mit(
// //-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
//     KC_1,   KC_2,   KC_3,   KC_4,   KC_PERC,_______,_______,KC_CIRC, KC_6,   KC_7,   KC_8,   KC_9,
// //-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
//     KC_LT,  KC_LBRC,KC_LCBR,KC_LPRN,KC_5,   _______,_______,KC_0,   KC_SCLN,KC_COLN,KC_EXLM,KC_QUES,
// //-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
//     KC_PLUS,KC_MINS,KC_ASTR,KC_SLSH,KC_BSLS,_______,_______,KC_PIPE,KC_RPRN,KC_RCBR,KC_RBRC,KC_GT,
// //-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
//     _______,KC_DLR, KC_AMPR,_______,KC_TILD,     LLOCK,     _______,_______,_______,_______,_______
// //-+-------+-------+-------+-------+-------+---------------+-------+-------+-------+-------+-------+
// ),

// [_NAVIGATION] = LAYOUT_planck_mit(
// //-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
//     _______,_______,_______,_______,_______,_______,_______,KC_INS, KC_PGUP,KC_UP,  KC_PGDN,_______,
// //-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
//     KC_LSFT,KC_LALT,KC_TAB, KC_LCTL, KC_ENT, _______,_______,KC_HOME,KC_LEFT,KC_DOWN,KC_RGHT,KC_END,
// //-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
//     C(KC_Z),C(KC_C),C(KC_X),C(KC_V),C(KC_Y),_______,_______,_______,_______,_______,_______,_______,
// //-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
//     _______,_______,_______,_______,_______,     LLOCK,     _______,_______,_______,_______,_______
// //-+-------+-------+-------+-------+-------+---------------+-------+-------+-------+-------+-------+
// ),

// [_MACROS] = LAYOUT_planck_mit(
// //-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
//     GIT_ALL,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
// //-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
//     _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
// //-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
//     _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
// //-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
//     _______,_______,_______,_______,_______,     LLOCK,     _______,_______,_______,_______,_______
// //-+-------+-------+-------+-------+-------+---------------+-------+-------+-------+-------+-------+
// ),

// [_FUNCTION] = LAYOUT_planck_mit(
// //-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
//     KC_F1,  KC_F2,  KC_F3,  KC_F4,  _______,_______,_______,_______,_______,RGB_TOG,QK_RBT, QK_BOOT,
// //-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
//     KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_PSCR,_______,_______,_______,_______,_______,_______,_______,
// //-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
//     KC_F9,  KC_F10, KC_F11, KC_F12, _______,_______,_______,_______,_______,_______,_______,_______,
// //-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
//     _______,_______,_______,_______,_______,     LLOCK,     _______,_______,_______,_______,_______
// //-+-------+-------+-------+-------+-------+---------------+-------+-------+-------+-------+-------+
// ),

// [_SPECIAL] = LAYOUT_planck_mit(
// //-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
//     U_SS,   U_O4,   U_O1,   U_O2,   U_O3,   _______,_______,_______,_______,_______,_______,_______,
// //-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
//     U_I1,   U_E1,   U_A1,   U_A2,   U_A3,   _______,_______,_______,_______,_______,_______,_______,
// //-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
//     _______,_______,U_U1,   U_U2,   U_U3,   _______,_______,_______,_______,_______,_______,_______,
// //-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
//     _______,_______,_______,_______,LT_SPC,      LLOCK,     _______,_______,_______,_______,_______
// //-+-------+-------+-------+-------+-------+---------------+-------+-------+-------+-------+-------+
// ),

// [_SPECIAL_CAPS] = LAYOUT_planck_mit(
// //-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
//     U_CSS,  U_CO4,  U_CO1,  U_CO2,  U_CO3,  _______,_______,_______,_______,_______,_______,_______,
// //-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
//     U_CI1,  U_CE1,  U_CA1,  U_CA2,  U_CA3,  _______,_______,_______,_______,_______,_______,_______,
// //-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
//     KC_Q,   _______,U_CU1,  U_CU2,  U_CU3,  _______,_______,_______,_______,_______,_______,_______,
// //-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
//     _______,_______,_______,_______,_______,     LLOCK,     _______,_______,_______,_______,_______
// //-+-------+-------+-------+-------+-------+---------------+-------+-------+-------+-------+-------+
// ),

// [_QWERTY] = LAYOUT_planck_mit(
// //-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
//     KC_DEL, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_BSPC,
// //-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
//     KC_LCTL,KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,  KC_SCLN, KC_QUOT,
// //-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
//     KC_BSPC,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_ENT,
// //-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
//     KC_LGUI,KC_ESC, KC_TAB, KC_SPC, KC_LSFT,     L_DEF,     KC_LSFT,KC_SPC, KC_LALT,KC_RCTL,KC_RALT
// //-+-------+-------+-------+-------+-------+---------------+-------+-------+-------+-------+-------+
// ),

// [_DEFAULT_MOD] = LAYOUT_planck_mit(
// //-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
//     KC_DEL, KC_U,   KC_O,   KC_Y,   KC_MINS,KC_LALT,KC_F13, KC_Q,   KC_M,   KC_D,   KC_P,   KC_X,
// //-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
//     KC_I,   KC_E,   KC_A,   KC_C,   KC_G,   KC_LSFT,KC_HASH,KC_V,   KC_H,   KC_T,   KC_N,   KC_S,
// //-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
//     KC_BSPC,KC_EQL, KC_DQUO,KC_W,   KC_Z,   KC_LCTL,KC_AT,  KC_J,   KC_L,   KC_K,   KC_B,   KC_F,
// //-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
//     KC_LGUI,KC_ESC, KC_TAB, KC_SPC, KC_ENT,      L_DEF,     LT_4,   LT_5,   LT_6,   _______,_______
// //-+-------+-------+-------+-------+-------+---------------+-------+-------+-------+-------+-------+
// ),

// [_LEAGUE] = LAYOUT_planck_mit(
// //-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
//     KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_T,   KC_U,   REC,    KC_F12, _______,_______,_______,
// //-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
//     KC_Q,   KC_W,   KC_E,   KC_R,   KC_LALT,KC_B,   _______,_______,_______,_______,_______,_______,
// //-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
//     KC_6,   KC_D,   KC_F,   KC_F13, KC_LCTL,KC_J,   KCP_CHT,_______,_______,_______,_______,_______,
// //-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
//     KC_LSFT,KC_ESC, KC_TAB, KC_SPC, ENT_CHT,     L_DEF,     _______,_______,_______,_______,_______
// //-+-------+-------+-------+-------+-------+---------------+-------+-------+-------+-------+-------+
// ),

// [_CHAT] = LAYOUT_planck_mit(
// //-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
//     KC_DEL, KC_U,   KC_O,   KC_Y,   KC_MINS,SLOT_1, SLOT_2, KC_Q,   KC_M,   KC_D,   KC_P,   KC_X,
// //-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
//     KC_I,   KC_E,   KC_A,   KC_C,   KC_G,   SLOT_3, SLOT_4, KC_V,   KC_H,   KC_T,   KC_N,   KC_S,
// //-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
//     KC_BSPC,KC_EQL, KC_DQUO,KC_W,   KC_Z,   SLOT_5, SLOT_6, KC_J,   KC_L,   KC_K,   KC_B,   KC_F,
// //-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
//     KC_LGUI,LT_0,   LT_1,   LT_2,   LT_3,        LLOCK,     LT_4,   LT_5,   LT_6,   _______,_______
// //-+-------+-------+-------+-------+-------+---------------+-------+-------+-------+-------+-------+
// ),


// [_MIDI] = LAYOUT_planck_mit(
// //-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
//     KC_K,   KC_L,   KC_0,   _______,_______,_______,_______,_______,_______,_______,_______,_______,
// //-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
//     KC_A,   KC_W,   KC_S,   KC_E,   KC_D,   KC_F,   KC_T,   KC_G,   KC_J,   KC_H,   KC_U,   KC_J,
// //-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
//     TOGOUTM,TOGCLIP,TOGRECD,_______,_______,GAIM6DB,GAIM1DB,GAIN1DB,GAIN6DB,TRANODN,TRANOUP,_______,
// //-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
//     _______,_______,_______,_______,_______,     L_DEF,     _______,_______,_______,_______,_______
// //-+-------+-------+-------+-------+-------+---------------+-------+-------+-------+-------+-------+
// ),

};