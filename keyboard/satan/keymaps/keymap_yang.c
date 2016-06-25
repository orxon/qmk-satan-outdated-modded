// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.

#include "satan.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BW 0
#define _FL 1
#define _NUM 2
#define _MOU 3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BW] = KEYMAP(
  KC_ESC,    KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,  KC_EQL,   KC_BSPC, \
  KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,  KC_RBRC,  KC_BSLS, \
  F(9),   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,            KC_ENT,  \
  KC_LSFT,         KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,            KC_RSFT, \
  KC_LCTL, KC_LGUI,KC_LALT,          KC_SPC,                                       MO(2),  KC_RALT, MO(3),  KC_RCTL),

  
[_FL] = KEYMAP(
  KC_GRV, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,   KC_F9,     KC_F10,    KC_F11,    KC_F12,    KC_DEL,  \
  KC_TRNS,KC_MPLY,KC_TRNS,  KC_UP,KC_TRNS,KC_MPRV, KC_MNXT,KC_TRNS,KC_TRNS, KC_TRNS,   KC_PSCR,   KC_SLCK,   KC_NUMLOCK,   KC_TRNS, \
  KC_TRNS,KC_TRNS,KC_LEFT,KC_DOWN,KC_RIGHT,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_PGUP,              KC_TRNS, \
  KC_TRNS,        KC_APP, KC_TRNS,KC_VOLD, KC_MUTE,   KC_VOLU,KC_TRNS,KC_TRNS, KC_HOME,   KC_END,   KC_PGDN,              KC_UP, \
  KC_TRNS,KC_TRNS,KC_TRNS,          KC_TRNS,                               KC_TRNS,    KC_LEFT,   KC_DOWN,              KC_RIGHT),
  
  
[_NUM] = KEYMAP(
  F(1),  KC_P1,  KC_P2,  KC_P3,  KC_P4,  KC_P5,  KC_P6,  KC_P7,  KC_P8,  KC_P9,  KC_P0,  KC_PMNS,  KC_PPLS,  KC_PDOT, \
  KC_NO,  F(4),  F(3),  F(2),  F(8),  F(7),  KC_NO,  KC_NO,  KC_INS,  KC_NO,  KC_PAUS,  KC_NO, KC_PAST, KC_PSLS, \
  KC_NO,  F(5),BL_DEC,BL_TOGG,BL_INC,  KC_NO,KC_NO,KC_NO,KC_NO,  KC_NO,KC_NO, KC_NO,          KC_PENT, \
  KC_TRNS,   F(6),   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_PDOT,  KC_PSLS,          KC_TRNS, \
  KC_TRNS,  KC_TRNS,  KC_TRNS,         KC_NO,                                         KC_TRNS,  KC_TRNS,KC_TRNS,KC_TRNS),
  
  
[_MOU] = KEYMAP(
	KC_NO,  KC_ACL0,  KC_ACL1,  KC_ACL2,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO, \
	KC_NO,  KC_WH_U,  KC_BTN1,  KC_MS_U,  KC_BTN2,  KC_MRWD,  KC_MFFD,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_MSEL, KC_MAIL, KC_CALC, \
	KC_NO,  KC_BTN3,  KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_WBAK,  KC_WFWD,          KC_NO, \
	KC_TRNS,   KC_WH_D,   KC_WH_L,   KC_WH_R,   KC_BTN4,   KC_BTN5,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,          KC_TRNS, \
	KC_TRNS,  KC_TRNS,  KC_TRNS,         KC_NO,                                         KC_TRNS,  KC_TRNS,KC_TRNS,KC_TRNS),


};


enum function_id {
    RGBLED_TOGGLE,
    RGBLED_STEP_MODE,
    RGBLED_INCREASE_HUE,
    RGBLED_DECREASE_HUE,
    RGBLED_INCREASE_SAT,
    RGBLED_DECREASE_SAT,
    RGBLED_INCREASE_VAL,
    RGBLED_DECREASE_VAL,
};

const uint16_t PROGMEM fn_actions[] = {
  [1]  = ACTION_FUNCTION(RGBLED_TOGGLE),
  [2]  = ACTION_FUNCTION(RGBLED_STEP_MODE),
  [3]  = ACTION_FUNCTION(RGBLED_INCREASE_HUE),
  [4]  = ACTION_FUNCTION(RGBLED_DECREASE_HUE),
  [5]  = ACTION_FUNCTION(RGBLED_INCREASE_SAT),
  [6]  = ACTION_FUNCTION(RGBLED_DECREASE_SAT),
  [7]  = ACTION_FUNCTION(RGBLED_INCREASE_VAL),
  [8]  = ACTION_FUNCTION(RGBLED_DECREASE_VAL),
  [9] = ACTION_LAYER_TAP_KEY(_FL, KC_CAPS),
};

#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))
void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  static uint8_t shift_esc_shift_mask;
  switch (id) {
    case RGBLED_TOGGLE:
      if (record->event.pressed) {
        rgblight_toggle();
      }

      break;
    case RGBLED_INCREASE_HUE:
      if (record->event.pressed) {
        rgblight_increase_hue();
      }
      break;
    case RGBLED_DECREASE_HUE:
      if (record->event.pressed) {
        rgblight_decrease_hue();
      }
      break;
    case RGBLED_INCREASE_SAT:
      if (record->event.pressed) {
        rgblight_increase_sat();
      }
      break;
    case RGBLED_DECREASE_SAT:
      if (record->event.pressed) {
        rgblight_decrease_sat();
      }
      break;
      case RGBLED_INCREASE_VAL:
        if (record->event.pressed) {
          rgblight_increase_val();
        }
        break;
      case RGBLED_DECREASE_VAL:
        if (record->event.pressed) {
          rgblight_decrease_val();
        }
        break;
      case RGBLED_STEP_MODE:
        if (record->event.pressed) {
          rgblight_step();
        }
        break;
  }
}


const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          return (record->event.pressed ? MACRO(D(LSFT) ,T(H) , U(LSFT), T(E), T(L), T(L), T(O), END ) :MACRO( END ));
          break;
        case 1:
          return (record->event.pressed ? MACRO(D(LSFT),T(A),T(S),T(D),U(LSFT),T(F),T(G),T(H), END ) :MACRO( END ));
          break;
      }
    return MACRO_NONE;
};
