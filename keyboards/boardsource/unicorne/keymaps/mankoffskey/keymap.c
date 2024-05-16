#include QMK_KEYBOARD_H

#include "keymap_dvorak.h"




/* // Copyright 2022 Mark Stosberg (@markstos) */
/* // SPDX-License-Identifier: GPL-2.0-or-later */
/* #include QMK_KEYBOARD_H */
/* #pragma once */
/* enum custom_keycodes { */
/*   QWERTY = SAFE_RANGE, */
/*   LOWER, */
/*   RAISE, */
/*   FUNC, */
/*   BACKLIT */
/* }; */

/* enum combos { */
/*   THREE_FOUR_DASH, */
/*   DF_DASH, */
/*   JK_ESC */
/* }; */

/* const uint16_t PROGMEM three_four_combo[] = {KC_3, KC_4, COMBO_END}; */
/* const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END}; */
/* const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END}; */

/* combo_t key_combos[COMBO_COUNT] = { */
/*   // Add commonly used dash to home row */
/*   [DF_DASH]    = COMBO(df_combo, KC_MINS), */
/*   [THREE_FOUR_DASH]    = COMBO(three_four_combo, KC_MINS), */
/*   // For Vim, put Escape on the home row */
/*   [JK_ESC]    = COMBO(jk_combo, KC_ESC), */
/* }; */

/* // Each layer gets a name for readability, which is then used in the keymap matrix below. */
/* // The underscores don't mean anything - you can have a layer called STUFF or any other name. */
/* // Layer names don't all need to be of the same length, obviously, and you can also skip them */
/* // entirely and just use numbers. */
/* enum custom_layers { */
/*   _QWERTY, */
/*   _LOWER, */
/*   _RAISE, */
/*   _FUNC, */
/* }; */

/* // For _QWERTY layer */
/* #define OSM_LCTL OSM(MOD_LCTL) */
/* #define OSM_AGR  OSM(MOD_RALT) */
/* #define OSL_FUN  OSL(_FUNC) */
/* #define GUI_ENT  GUI_T(KC_ENT) */
/* #define LOW_TAB  LT(_LOWER, KC_TAB) */
/* #define RSE_BSP  LT(_RAISE, KC_BSPC) */
/* #define OSM_SFT  OSM(MOD_LSFT) */
/* #define CTL_ESC  LCTL_T(KC_ESC) */



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // Dvorak base
  [0] = LAYOUT_split_3x6_3(
   LT(2,KC_TAB), DV_QUOT, DV_COMM, DV_DOT, DV_P, DV_Y,    DV_F, DV_G, DV_C, DV_R, DV_L, KC_BSPC,
   KC_LCTL, DV_A, DV_O, DV_E, DV_U, DV_I,           DV_D, DV_H, DV_T, DV_N, DV_S, DV_MINS,
   KC_LSFT, DV_SCLN, DV_Q, DV_J, DV_K, DV_X,        DV_B, DV_M, DV_W, DV_V, DV_Z, LT(2, DV_SLSH),
                  LT(3, KC_NO), KC_LALT, KC_ENT,     KC_LSFT, LT(1,KC_SPC), KC_BSPC),

  // Num
  [1] = LAYOUT_split_3x6_3(
   _______, _______, DV_COMM, DV_LPRN, DV_RPRN, DV_SLSH,      DV_PLUS, KC_7, KC_8, KC_9, KC_0, DV_PLUS,
   _______, _______, DV_DOT, DV_LBRC, DV_RBRC, DV_ASTR,       DV_MINS, KC_4, KC_5, KC_6, KC_0, DV_MINS,
   _______, _______, _______, DV_LCBR, DV_RCBR, DV_BSLS,      DV_EQL, KC_1, KC_2, KC_3, KC_0, DV_COLN,
                               KC_SPC, KC_BSPC, KC_LALT,       _______, _______, _______),

  // Nav
  [2] = LAYOUT_split_3x6_3(
   _______, _______, _______, _______, _______, _______,          _______, _______, KC_UP, _______, _______, _______,
   _______, _______, _______, _______, KC_MS_WH_DOWN, KC_PGUP,    _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, KC_LGUI,
   _______, _______, KC_PGUP, KC_PGDN, KC_MS_WH_UP, KC_PGDN,      _______, _______, _______, _______, _______, _______,   
                                _______, _______, _______,       _______, _______, _______),
  
  // Sym
  [3] = LAYOUT_split_3x6_3(
   _______, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_F12,
   _______, _______, _______, _______, _______, _______,      _______, KC_F7, KC_F8, KC_F9, _______, KC_F11,
   _______, _______, _______, _______, _______, _______,      _______, KC_F4, KC_F5, KC_F6, _______, KC_F10,
                               _______, _______, _______,      KC_F1, KC_F2, KC_F3),

  // Function
  [4] = LAYOUT_split_3x6_3(
   QK_BOOT, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______,
   _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______,
   _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______,   
                              _______, _______, _______,      _______, _______, _______)

};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)





/*
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
      case LT(_RAISE, KC_BSPC):
            return TAPPING_TERM_THUMB;
      case LT(_LOWER, KC_TAB):
            return TAPPING_TERM_THUMB;
      default:
            return TAPPING_TERM;
    }
}
*/
