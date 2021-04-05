/* Copyright 2021 kobakos
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
#define TAPPING_TOGGLE 2

// Defines names for use in layer keycodes and the keymap

// Defines the keycodes used by our macros in process_record_user

#define KC_RST RESET
#define KC_M_SPC LT(1,KC_SPC)
#define KC_M_ENT LT(2,KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT( \
  //,--------+--------+---------+--------+---------+--------.   ,--------+---------+--------+---------+--------+--------.
     KC_ESC , KC_Q   , KC_W    , KC_E   , KC_R    , KC_T   ,     KC_Y   , KC_U    , KC_I   , KC_O    , KC_P   , KC_MINS,
  //|--------+--------+---------+--------+---------+--------|   |--------+---------+--------+---------+--------+--------|
     KC_LCTL, KC_A   , KC_S    , KC_D   , KC_F    , KC_G   ,     KC_H   , KC_J    , KC_K   , KC_L    , KC_   , KC_RCTL,
  //|--------+--------+---------+--------+---------+--------|   |--------+---------+--------+---------+--------+--------|
     KC_TAB , KC_Z   , KC_X    , KC_C   , KC_V    , KC_B   ,     KC_N   , KC_M    , KC_COMM, KC_DOT  , KC_SLSH, _______,
  //`--------+--------+---------+--------+---------+--------/   \--------+---------+--------+---------+--------+--------'
              TT(3)  , KC_LSFT , KC_M_SPC,KC_DEL  , KC_ALT ,     KC_WIN , KC_BSCP , KC_M_ENT,KC_RSFT , TT(3)
  //                 `----------+--------+---------+--------'   `--------+---------+--------+---------'
  ),

  [1] = LAYOUT( \
  //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------.
     _______, _______, KC_BSLS, KC_TILD ,KC_DLR  , KC_QUES,    KC_JYEN, KC_AMPR,KC_PERC, KC_PIPE, _______, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
     _______, KC_EXLM, KC_AT  , KC_HASH, KC_UNDS , KC_PLUS,    KC_ASTR, KC_EQL ,KC_LPRN, KC_RPRN, KC_MINS, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
     _______, KC_CIRC, KC_LABK, KC_DQUO, KC_LBRC, KC_LCBR,     KC_RCBR, KC_RBRC, KC_QUOT , KC_RABK,KC_SCLN, _______,
  //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------'
              _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
  //                  `--------+--------+--------+--------'   `--------+--------+--------+--------'
  ),

  [2] = LAYOUT( \
  //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------.
     _______, KC_ASTR, KC_MINS, KC_COMM, KC_DOT,  KC_SLSH,     _______, _______, KC_PERC, KC_EQL , KC_PLUS, _______, 
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
     KC_LABK, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,     KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_RABK,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
     KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  ,     KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,
  //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------'
              _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
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
              _______, KC_BTN2, KC_BTN1, KC_BTN1, _______,     _______, _______, _______, KC_RST , _______
  //                  `--------+--------+--------+--------'   `--------+--------+--------+--------'
  ),
};


/*
void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool led_update_user(led_t led_state) {
    return true;
}
*/
