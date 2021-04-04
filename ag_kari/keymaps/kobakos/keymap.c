#include QMK_KEYBOARD_H
#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

#define TAPPING_TOGGLE 2

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  LYR3
};

#define KC_ KC_TRNS
#define KC_RST RESET

#define KC_L_SPC LT(1, KC_SPC) // lower
#define KC_R_ENT LT(2, KC_ENT) // raise
#define KC_M_H LSFT_T(KC_F23)
#define KC_M_M RSFT_T(KC_F24)
#define KC_M_O LCTL_T(KC_O)
#define KC_M_T RCTL_T(KC_T)
#define KC_A_DL LALT_T(KC_DEL)
#define KC_W_BS RWIN_T(KC_BSPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT( \
  //,--------+--------+---------+--------+---------+--------.   ,--------+---------+--------+---------+--------+--------.
     KC_ESC , KC_Q   , KC_V    , KC_COMM, KC_DOT  , KC_SLSH,     KC_G   , KC_Y    , KC_D   , KC_J    , KC_P   , KC_MINS,
  //|--------+--------+---------+--------+---------+--------|   |--------+---------+--------+---------+--------+--------|
     KC_HOME, KC_A   , KC_M_O  , KC_E   , KC_I    , KC_U   ,     KC_R   , KC_N    , KC_S   , KC_M_T  , KC_L   , KC_END,
  //|--------+--------+---------+--------+---------+--------|   |--------+---------+--------+---------+--------+--------|
     KC_TAB , KC_Z   , KC_X    , KC_C   , KC_W    , KC_F   ,     KC_B   , KC_H    , KC_K   , KC_M    , KC_COLN, KC_LANG5,
  //`--------+--------+---------+--------+---------+--------/   \--------+---------+--------+---------+--------+--------'
                       KC_M_H,  KC_M_H , KC_L_SPC, KC_A_DL,      KC_W_BS, KC_R_ENT, TT(3) , KC_M_M
  //                 `----------+--------+---------+--------'   `--------+---------+--------+---------'
  ),

  [1] = LAYOUT( \
  //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------.
     _______, _______, KC_BSLS, KC_TILD ,KC_DLR  , KC_QUES,     KC_JYEN, KC_AMPR,KC_PERC, KC_PIPE, _______, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
     _______, KC_EXLM, KC_AT  , KC_HASH, KC_UNDS , KC_PLUS,     KC_ASTR, KC_EQL ,KC_LPRN, KC_RPRN, KC_MINS, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
     _______, KC_CIRC, KC_LABK, KC_DQUO, KC_LBRC, KC_LCBR,     KC_RCBR, KC_RBRC, KC_QUOT , KC_RABK,KC_SCLN, _______,
  //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------'
                       _______, _______, _______, _______,     _______, _______, _______, _______
  //                  `--------+--------+--------+--------'   `--------+--------+--------+--------'
  ),

  [2] = LAYOUT( \
  //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------.
     KC_LABK, KC_ASTR, KC_MINS, KC_COMM, KC_DOT,  KC_SLSH,     _______, _______, KC_PERC, KC_EQL , KC_PLUS, KC_RABK, 
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
     _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,     KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
     KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  ,     KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,
  //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------'
                       _______, _______, _______, _______,     _______, _______, _______, _______
  //                  `--------+--------+--------+--------'   `--------+--------+--------+--------'
  ),
 
  [3] = LAYOUT( \
  //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------.
     _______, _______, KC_WH_D, KC_MS_U, KC_WH_U, _______,     _______, KC_PGDN, KC_UP  , KC_PGUP, _______, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
     _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______,     KC_VOLU, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
     _______, _______, _______, _______, _______, _______,     KC_VOLD, KC_ACL0, KC_ACL1, KC_ACL2, _______, _______,
  //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------'
                       KC_BTN2, KC_BTN2, KC_BTN1, _______,     _______, KC_BTN2 ,_______, _______
  //                  `--------+--------+--------+--------'   `--------+--------+--------+--------'
  ),
};
bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_L_SPC:
            return true;
        default:
            return false;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_L_SPC:
            return 150;
        case KC_R_ENT:
            return 150;
        case KC_M_T:
            return 200;
        case KC_M_O:
            return 200;
        default:
            return TAPPING_TERM;
    }
}
