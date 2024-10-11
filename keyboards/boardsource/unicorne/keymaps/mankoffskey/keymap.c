#include QMK_KEYBOARD_H

#include "keymap_dvorak.h"
#ifdef JOYSTICK_ENABLE
#   include "analog.h"
#endif

// TAP DANCE
enum {
    TD_SLSH_TILDE,
};
tap_dance_action_t tap_dance_actions[] = {
  [TD_SLSH_TILDE] = ACTION_TAP_DANCE_DOUBLE(DV_SLSH, KC_TILDE), // 1:/ 2:~ 3:~/ :)
};


// KEYMAP
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // Dvorak base
  [0] = LAYOUT_split_3x6_3(
   LT(2,KC_TAB), DV_QUOT, DV_COMM, DV_DOT, DV_P, DV_Y,    DV_F, DV_G, DV_C, DV_R, DV_L, KC_BSPC,
   KC_LCTL, DV_A, DV_O, DV_E, DV_U, DV_I,           DV_D, DV_H, DV_T, DV_N, DV_S, DV_MINS,
   KC_ESC, DV_SCLN, DV_Q, DV_J, DV_K, DV_X,        DV_B, DV_M, DV_W, DV_V, DV_Z, TD(TD_SLSH_TILDE),
                  LT(3, KC_NO), KC_LALT, KC_ENT,     KC_LSFT, LT(1,KC_SPC), _______),

  // Num
  [1] = LAYOUT_split_3x6_3(
   KC_ESC, _______, DV_COMM, DV_LBRC, DV_RBRC, DV_SLSH,      DV_PLUS, KC_7, KC_8, KC_9, KC_0, DV_PLUS,
   _______, _______, DV_DOT, DV_LPRN, DV_RPRN, DV_ASTR,       DV_MINS, KC_4, KC_5, KC_6, KC_0, DV_MINS,
   _______, _______, _______, DV_LCBR, DV_RCBR, DV_BSLS,      DV_EQL, KC_1, KC_2, KC_3, KC_0, DV_COLN,
                              KC_SPC, KC_BSPC, KC_LALT,       LT(3,_______), _______, _______),

  // Nav
  [2] = LAYOUT_split_3x6_3(
   _______, KC_LGUI, _______, _______, _______, _______,          _______, _______, KC_UP, _______, _______, KC_DEL,
   OSM(MOD_RALT), _______, _______, _______, KC_MS_WH_DOWN, KC_PGUP,    _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______,
   _______, _______, KC_PGUP, KC_PGDN, KC_MS_WH_UP, KC_PGDN,      _______, _______, _______, _______, _______, _______,   
                                _______, _______, _______,       _______, _______, _______),
  
  // Sym
  [3] = LAYOUT_split_3x6_3(
   KC_GRAVE, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_F12,
   _______, KC_PIPE, _______, _______, _______, _______,      _______, KC_F7, KC_F8, KC_F9, _______, KC_F11,
   KC_ESC, _______, _______, _______, _______, QK_BOOT,      _______, KC_F4, KC_F5, KC_F6, _______, KC_F10,
                               _______, _______, _______,      KC_F1, KC_F2, KC_F3),

  // Function
  [4] = LAYOUT_split_3x6_3(
   QK_BOOT, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______,
   _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______,
   _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______,   
                              _______, _______, _______,      _______, _______, _______)

};


/* Joystick Debug */
bool joystick_debug = false;
bool enable_mouse_pointer = false;

static bool left_pointer_tap_code_sent = false;
#if defined(SPLIT_POINTING_ENABLE)
#  if defined(POINTING_DEVICE_COMBINED)
     static bool right_pointer_tap_code_sent = false;
#  endif
#define LEFT_POINTER_X_ARRAY_SIZE 12
#define RIGHT_POINTER_X_ARRAY_SIZE 18
int arrLeftX[LEFT_POINTER_X_ARRAY_SIZE]   = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int arrLeftY[LEFT_POINTER_X_ARRAY_SIZE]   = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int arrRightX[RIGHT_POINTER_X_ARRAY_SIZE] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int arrRightY[RIGHT_POINTER_X_ARRAY_SIZE] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

void updateLeftX(int arrLeftX[], int newValue) {
    // Shift elements to the left
    for (int i = 0; i < LEFT_POINTER_X_ARRAY_SIZE - 1; i++) {
        arrLeftX[i] = arrLeftX[i + 1];
    }
    // Add the newest integer
    arrLeftX[LEFT_POINTER_X_ARRAY_SIZE - 1] = newValue;
}
void updateLeftY(int arrLeftY[], int newValue) {
    // Shift elements to the left
    for (int i = 0; i < LEFT_POINTER_X_ARRAY_SIZE - 1; i++) {
        arrLeftY[i] = arrLeftY[i + 1];
    }
    // Add the newest integer
    arrLeftY[LEFT_POINTER_X_ARRAY_SIZE - 1] = newValue;
}

void updateRightX(int arrRightX[], int newValue) {
    // Shift elements to the left
    for (int i = 0; i < RIGHT_POINTER_X_ARRAY_SIZE - 1; i++) {
        arrRightX[i] = arrRightX[i + 1];
    }
    // Add the newest integer
    arrRightX[RIGHT_POINTER_X_ARRAY_SIZE - 1] = newValue;
}
void updateRightY(int arrRightY[], int newValue) {
    // Shift elements to the left
    for (int i = 0; i < RIGHT_POINTER_X_ARRAY_SIZE - 1; i++) {
        arrRightY[i] = arrRightY[i + 1];
    }
    // Add the newest integer
    arrRightY[RIGHT_POINTER_X_ARRAY_SIZE - 1] = newValue;
}

bool checkAllZeros(int arr[]) {
    for (int i = 0; i < LEFT_POINTER_X_ARRAY_SIZE; i++) {
        if (arr[i] != 0) {
            return false; // Not all zeros
        }
    }
    return true; // All zeros
}
#endif

#if defined(SPLIT_POINTING_ENABLE)
report_mouse_t pointing_device_task_combined_kb(report_mouse_t left_report, report_mouse_t right_report) {
  dprintf("=========================================================================================\n");
  dprintf("Left Pointing Device ==> left_report.x: %d, left_report.y: %d\n", left_report.x, left_report.y);
  dprintf("Right Pointing Device ==> right_report.x: %d, right_report.y: %d\n", right_report.x, right_report.y);

  updateLeftX(arrLeftX, left_report.x);
  updateLeftY(arrLeftY, left_report.y);
  updateRightX(arrRightX, right_report.x);
  updateRightY(arrRightY, right_report.y);
  if(checkAllZeros(arrLeftX) && checkAllZeros(arrLeftY)) {
    left_pointer_tap_code_sent = false;
  }
  if(checkAllZeros(arrRightX) && checkAllZeros(arrRightY)) {
    right_pointer_tap_code_sent = false;
  }

  if (!enable_mouse_pointer) {
    dprintf("Left Mouse already_sent: %d\n", left_pointer_tap_code_sent);
    if (!left_pointer_tap_code_sent) {
      dprintf("About to send keys...\n");
      dprintf("left_report.x: %d,left_report.y: %d\n", left_report.x, left_report.y);
      if (left_report.x == 7) {
	tap_code(KC_RIGHT);
	/* // left_pointer_tap_code_sent = true; */
      } else if (left_report.x == -7) {
	tap_code(KC_LEFT);
	// left_pointer_tap_code_sent = true;
	/* if((get_mods() & MOD_BIT(KC_LALT)) == MOD_BIT(KC_LALT)) { */
	/*   left_pointer_tap_code_sent = true; */
	/* } */
      }

      if (left_report.y == 7) {
	tap_code(KC_DOWN);
	// left_pointer_tap_code_sent = true;
      } else if (left_report.y == -7) {
	tap_code(KC_UP);
	// left_pointer_tap_code_sent = true;
      }
    }
    // =================================================================================
    dprintf("Right Mouse already_sent: %d\n", right_pointer_tap_code_sent);
    if (!right_pointer_tap_code_sent) {
      dprintf("About to send keys...\n");
      dprintf("right_report.x: %d,right_report.y: %d\n", right_report.x, right_report.y);
      if (right_report.x == 7) {
	tap_code(KC_WH_D);
	right_pointer_tap_code_sent = true;
      } else if (right_report.x == -7) {
	tap_code(KC_WH_U);
	right_pointer_tap_code_sent = true;
      }

      if (right_report.y == 7) {
	tap_code(KC_UP);
	right_pointer_tap_code_sent = true;
      } else if (right_report.y == -7) {
	tap_code(KC_DOWN);
	right_pointer_tap_code_sent = true;
      }
    }
    left_report.x = 0;
    left_report.y = 0;
    right_report.x = 0;
    right_report.y = 0;
  }

  return pointing_device_task_combined_user(left_report, right_report);
}
#endif

