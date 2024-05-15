#include QMK_KEYBOARD_H

#include "keymap_dvorak.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // Dvorak base
  [0] = LAYOUT_split_3x6_3(
   KC_TAB, DV_QUOT, DV_COMM, DV_DOT, DV_P, DV_Y,    DV_F, DV_G, DV_C, DV_R, DV_L, DV_SLSH,
   KC_LCTL, DV_A, DV_O, DV_E, DV_U, DV_I,           DV_D, DV_H, DV_T, DV_N, DV_S, DV_MINS,
   KC_LSFT, DV_SCLN, DV_Q, DV_J, DV_K, DV_X,        DV_B, DV_M, DV_W, DV_V, DV_Z, LT(1, _______),
                    KC_LGUI, KC_LALT, KC_ENT,     KC_LSFT, LT(2,KC_SPC), KC_BSPC),

  // Nav
  [1] = LAYOUT_split_3x6_3(
   _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, TO(3),
   _______, _______, _______, _______, KC_MS_WH_DOWN, KC_PGUP,      _______, _______, _______, _______, _______, TO(2),
   _______, _______, KC_PGUP, KC_PGDN, KC_MS_WH_UP, KC_PGDN,      _______, _______, _______, _______, _______, _______,   
                          _______, _______, _______,       _______, _______, _______),

  // Num
  [2] = LAYOUT_split_3x6_3(
   _______, _______, KC_COMM, KC_LPRN, KC_RPRN, KC_SLSH,      KC_PLUS, KC_7, KC_8, KC_9, KC_0, DV_PLUS,
   _______, _______, KC_DOT, KC_LBRC, KC_RBRC, KC_ASTR,       KC_MINS, KC_4, KC_5, KC_6, KC_0, DV_MINS,
   _______, _______, _______, KC_LCBR, KC_RCBR, KC_BSLS,      KC_EQL, KC_1, KC_2, KC_3, KC_0, DV_COLN,
                               KC_SPC, KC_BSPC, KC_LALT,       _______, _______, _______),

  // Sym
  [3] = LAYOUT_split_3x6_3(
   _______, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, TO(0),			   
   _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______,
   _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______,
                               _______, _______, _______,      _______, _______, _______),

  // Function
  [4] = LAYOUT_split_3x6_3(
   QK_BOOT, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, TO(0),
   _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______,
   _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______,   
                              _______, _______, _______,      _______, _______, _______)

};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)





