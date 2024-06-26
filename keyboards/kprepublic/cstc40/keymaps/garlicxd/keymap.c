#include QMK_KEYBOARD_H
#include "features/layer_lock.h"

enum custom_layers {

    _DEFAULT,

    _QWERTY,
    _LEAGUE,
    _DJ,

    _CHAT,

    _DEFAULT_CAPS,
    _FUNCTION,
    _MACROS,
    _MOUSE,
    _NAVIGATION,
    _SYMBOLS,
    _SPECIAL,
    _SPECIAL_CAPS,

};
enum custom_keycodes {
    LLOCK = SAFE_RANGE,
    KCP_CHT,
    ENT_CHT,
    BYE_CHT,
    GIT_ALL,
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

// default layer keys
#define T_0 KC_LGUI
#define T_1 KC_TAB
#define T_2 KC_SPC
#define T_3 KC_ENT
#define T_4 KC_DOT
#define T_5 KC_R
#define T_6 KC_COMM
#define LT_0 LT(_FUNCTION,      T_0)
#define LT_1 LT(_MACROS,        T_1)
#define LT_2 LT(_NAVIGATION,    T_2)
#define LT_3 LT(_DEFAULT_CAPS,  T_3)
#define LT_4 LT(_SPECIAL,       T_4)
#define LT_5 LT(_SYMBOLS,       T_5)
#define LT_6 LT(_MOUSE,         T_6)

// additional layer keys
#define SCL_NAV LT(_NAVIGATION, KC_SCLN)
#define LT_SCA LT(_SPECIAL_CAPS, T_4)
#define LT_SPC LT(_SPECIAL_CAPS, KC_UNDS)

#define L_DEF TO(_DEFAULT)
#define L_QWE TO(_QWERTY)

#define REC KC_F13

#define SLOT_1 TO(_QWERTY)
#define SLOT_2 TO(_LEAGUE)
#define SLOT_3 TO(_DJ)
#define SLOT_4 _______
#define SLOT_5 _______
#define SLOT_6 _______

static uint16_t last_chatter = _______;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    // Layer Lock
    if (!process_layer_lock(keycode, record, LLOCK)) { return false; }

    switch (keycode) {
        case GIT_ALL:
            if (record->event.pressed) {
                SEND_STRING("git add .\ngit commit -a -m \"commit\"\ngit push");
            }
            return false;

        case KCP_CHT:
            if (record->event.pressed) {
                tap_code(KC_P);
                last_chatter = KC_P;
                layer_invert(_CHAT);
            }
            return false;

        case BYE_CHT:
            if (record->event.pressed) {
                tap_code(last_chatter);
                layer_invert(_CHAT);
            }
            return false;  

        case ENT_CHT:
            if (record->event.pressed) {
                tap_code(KC_ENT);
                last_chatter = KC_ENT;
                layer_invert(_CHAT);
            }
            return false;  
    }

    return true;
}

void process_combo_event(uint16_t combo_index, bool pressed) {

}

void matrix_scan_user(void) {
    layer_lock_task();
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// [_DEFAULT] = LAYOUT_planck_mit(
// //-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
//     KC_X,   KC_P,   KC_D,   KC_M,   KC_Q,   SLOT_1, SLOT_2, KC_AMPR,KC_Y,   KC_O,   KC_U,   KC_QUOT,
// //-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
//     KC_S,   KC_N,   KC_T,   KC_H,   KC_V,   SLOT_3, SLOT_4, KC_G,   KC_C,   KC_A,   KC_E,   KC_I,
// //-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
//     KC_F,   KC_B,   KC_K,   KC_L,   KC_J,   SLOT_5, SLOT_6, KC_Z,   KC_W,   KC_DQUO,KC_COMM, KC_DOT,
// //-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
//     _______,LT_0,   LT_1,   LT_2,   LT_3,       _______,    LT_4,   LT_5,   LT_6,   KC_LGUI,_______
// //-+-------+-------+-------+-------+-------+---------------+-------+-------+-------+-------+-------+
// ),

[_DEFAULT] = LAYOUT_planck_mit(
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    KC_DEL, KC_U,   KC_O,   KC_Y,   KC_MINS,SLOT_1, SLOT_2, KC_Q,   KC_M,   KC_D,   KC_P,   KC_X,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    KC_I,   KC_E,   KC_A,   KC_C,   KC_G,   SLOT_3, SLOT_4, KC_V,   KC_H,   KC_T,   KC_N,   KC_S,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    KC_BSPC,KC_EQL, KC_DQUO,KC_W,   KC_Z,   SLOT_5, SLOT_6, KC_J,   KC_L,   KC_K,   KC_B,   KC_F,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    KC_ESC, LT_0,   LT_1,   LT_2,   LT_3,        LLOCK,     LT_4,   LT_5,   LT_6,   _______,_______
//-+-------+-------+-------+-------+-------+---------------+-------+-------+-------+-------+-------+
),

// [_DEFAULT_CAPS] = LAYOUT_planck_mit(
// //-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
//     S(KC_X),S(KC_P),S(KC_D),S(KC_M),S(KC_Q),_______,_______,KC_DLR, S(KC_Y),S(KC_O),S(KC_U),KC_GRV,
// //-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
//     S(KC_S),S(KC_N),S(KC_T),S(KC_H),S(KC_V),_______,_______,S(KC_G),S(KC_C),S(KC_A),S(KC_E),S(KC_I),
// //-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
//     S(KC_F),S(KC_B),S(KC_K),S(KC_L),S(KC_J),_______,_______,S(KC_Z),S(KC_W),KC_HASH,KC_AT, KC_TILD,
// //-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
//     _______,_______,_______,_______,_______,     LLOCK,     KC_MINS,S(KC_R),KC_UNDS,_______,_______
// //-+-------+-------+-------+-------+-------+---------------+-------+-------+-------+-------+-------+
// ),

[_DEFAULT_CAPS] = LAYOUT_planck_mit(
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    KC_BSPC,S(KC_U),S(KC_O),S(KC_Y),KC_HASH,SLOT_1, SLOT_2, S(KC_Q),S(KC_M),S(KC_D),S(KC_P),S(KC_X),
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    S(KC_I),S(KC_E),S(KC_A),S(KC_C),S(KC_G),SLOT_3, SLOT_4, S(KC_V),S(KC_H),S(KC_T),S(KC_N),S(KC_S),
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    KC_DEL, KC_AT,  KC_QUOT,S(KC_W),S(KC_Z),SLOT_5, SLOT_6, S(KC_J),S(KC_L),S(KC_K),S(KC_B),S(KC_F),
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    _______,_______,KC_GRV, _______,LT_SPC,      LLOCK,     _______,_______,_______,_______,_______
//-+-------+-------+-------+-------+-------+---------------+-------+-------+-------+-------+-------+
),

[_SYMBOLS] = LAYOUT_planck_mit(
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    KC_1,   KC_2,   KC_3,   KC_4,   KC_PERC,_______,_______,KC_CIRC, KC_6,   KC_7,   KC_8,   KC_9,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    KC_LT,  KC_LBRC,KC_LCBR,KC_LPRN,KC_5,   _______,_______,KC_0,   KC_SCLN,KC_COLN,KC_EXLM,KC_QUES,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    KC_PLUS,KC_MINS,KC_ASTR,KC_SLSH,KC_BSLS,_______,_______,KC_PIPE,KC_RPRN,KC_RCBR,KC_RBRC,KC_GT,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    _______,_______,KC_AMPR,_______,KC_TILD,     LLOCK,     _______,_______,_______,_______,_______
//-+-------+-------+-------+-------+-------+---------------+-------+-------+-------+-------+-------+
),

[_NAVIGATION] = LAYOUT_planck_mit(
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    _______,_______,_______,_______,_______,_______,_______,KC_INS, KC_PGUP,KC_UP,  KC_PGDN,_______,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    KC_LSFT,KC_LALT,KC_TAB, KC_LCTL, KC_ENT, _______,_______,KC_HOME,KC_LEFT,KC_DOWN,KC_RGHT,KC_END,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    C(KC_Z),C(KC_C),C(KC_X),C(KC_V),C(KC_Y),_______,_______,_______,_______,_______,_______,_______,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    _______,_______,_______,_______,_______,     LLOCK,     _______,_______,_______,_______,_______
//-+-------+-------+-------+-------+-------+---------------+-------+-------+-------+-------+-------+
),

[_MACROS] = LAYOUT_planck_mit(
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    GIT_ALL,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    _______,_______,_______,_______,_______,     LLOCK,     _______,_______,_______,_______,_______
//-+-------+-------+-------+-------+-------+---------------+-------+-------+-------+-------+-------+
),

[_FUNCTION] = LAYOUT_planck_mit(
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    KC_F1,  KC_F2,  KC_F3,  KC_F4,  _______,_______,_______,_______,_______,RGB_TOG,QK_RBT, QK_BOOT,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_PSCR,_______,_______,_______,_______,_______,_______,_______,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    KC_F9,  KC_F10, KC_F11, KC_F12, _______,_______,_______,_______,_______,_______,_______,_______,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    _______,_______,_______,_______,_______,     LLOCK,     _______,_______,_______,_______,_______
//-+-------+-------+-------+-------+-------+---------------+-------+-------+-------+-------+-------+
),

[_SPECIAL] = LAYOUT_planck_mit(
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    U_SS,   U_O4,   U_O1,   U_O2,   U_O3,   _______,_______,_______,_______,_______,_______,_______,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    U_I1,   U_E1,   U_A1,   U_A2,   U_A3,   _______,_______,_______,_______,_______,_______,_______,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    _______,_______,U_U1,   U_U2,   U_U3,   _______,_______,_______,_______,_______,_______,_______,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    _______,_______,_______,_______,_______,     LLOCK,     LT_SPC, _______,_______,_______,_______
//-+-------+-------+-------+-------+-------+---------------+-------+-------+-------+-------+-------+
),

[_SPECIAL_CAPS] = LAYOUT_planck_mit(
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    _______,_______,_______,_______,_______,_______,_______,U_CO3,  U_CO2,  U_CO1,  U_CO4,  U_CSS,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    _______,_______,_______,_______,_______,_______,_______,U_CA3,  U_CA2,  U_CA1,  U_CE1,  U_CI1,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    _______,_______,_______,_______,_______,_______,_______,U_CU3,  U_CU2,  U_CU1,  _______,_______,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    _______,_______,_______,_______,_______,     LLOCK,     _______,_______,_______,_______,_______
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
    KC_LGUI,KC_LCTL,KC_LALT,KC_SPC, KC_ENT,      L_DEF,     KC_BSPC,KC_SPC, KC_DEL, KC_RCTL,KC_RALT
//-+-------+-------+-------+-------+-------+---------------+-------+-------+-------+-------+-------+
),

[_LEAGUE] = LAYOUT_planck_mit(
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_T,   KC_U,   REC,    KC_F12, _______,_______,_______,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    KC_Q,   KC_W,   KC_E,   KC_R,   KC_LALT,KC_B,   _______,_______,_______,_______,_______,_______,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    KC_6,   KC_D,   KC_F,   KC_F13, KC_LCTL,KC_J,   KCP_CHT,_______,_______,_______,_______,_______,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    KC_LSFT,KC_ESC, KC_TAB, KC_SPC, ENT_CHT,     L_DEF,     _______,_______,_______,_______,_______
//-+-------+-------+-------+-------+-------+---------------+-------+-------+-------+-------+-------+
),

[_CHAT] = LAYOUT_planck_mit(
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    KC_X,   KC_P,   KC_D,   KC_M,   KC_Q,   _______,_______,KC_AMPR,KC_Y,   KC_O,   KC_U,   KC_QUOT,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    KC_S,   KC_N,   KC_T,   KC_H,   KC_V,   _______,_______,KC_G,   KC_C,   KC_A,   KC_E,   KC_I,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    KC_F,   KC_B,   KC_K,   KC_L,   KC_J,   _______,_______,KC_Z,   KC_W,   KC_DQUO,KC_COMM,KC_DOT,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    _______,LT_0,   LT_1,   LT_2,   BYE_CHT,     L_DEF,     LT_4,   LT_5,   LT_6,   _______,_______
//-+-------+-------+-------+-------+-------+---------------+-------+-------+-------+-------+-------+
),

[_DJ] = LAYOUT_planck_mit(
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
//-+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    _______,KC_ESC, KC_TAB, KC_SPC, LT_3,        LLOCK,     LT_4,   LT_5,   LT_6,   _______,_______
//-+-------+-------+-------+-------+-------+---------------+-------+-------+-------+-------+-------+
),

};
