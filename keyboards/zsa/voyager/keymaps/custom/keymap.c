#include QMK_KEYBOARD_H
#include "version.h"
#include "process_key_override.h"

#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

// Shift + esc = ~
const key_override_t tilde_esc_override = ko_make_basic(MOD_MASK_SHIFT, ALL_T(KC_ESCAPE), S(KC_GRV));

// GUI + esc = `
const key_override_t grave_esc_override = ko_make_basic(MOD_MASK_GUI, ALL_T(KC_ESCAPE), KC_GRV);

// SHIFT + backspace = del
const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, LT(3,KC_BSPC), KC_DEL);

// GUI + / = backslash
const key_override_t forward_slash_override = ko_make_basic(MOD_MASK_GUI, KC_SLASH, KC_BACKSLASH);

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
    &tilde_esc_override,
    &grave_esc_override,
    &delete_key_override,
    &forward_slash_override,
    NULL // Null terminate the array of overrides!
};

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
};

#define DUAL_FUNC_0 LT(14, KC_F23)
#define DUAL_FUNC_1 LT(6, KC_F16)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // QWERTY Layer
  [0] = LAYOUT_voyager(
    ALL_T(KC_ESCAPE), KC_1, KC_2,               KC_3,               KC_4,               KC_5,                                       KC_6,      KC_7,               KC_8,                   KC_9,                 KC_0,     KC_MINUS,
    KC_TAB,           KC_Q, KC_W,               KC_E,               KC_R,               KC_T,                                       KC_Y,      KC_U,               KC_I,                   KC_O,                 KC_P,     KC_HYPR,
    DUAL_FUNC_0,      KC_A, KC_S,               KC_D,               KC_F,               KC_G,                                       KC_H,      KC_J,               KC_K,                   KC_L,                 KC_SCLN,  KC_QUOTE,
    KC_LEFT_SHIFT,    KC_Z, MT(MOD_LCTL, KC_X), MT(MOD_LALT, KC_C), MT(MOD_LGUI, KC_V), KC_B,                                       KC_N,      MT(MOD_RGUI, KC_M), MT(MOD_RALT, KC_COMMA), MT(MOD_RCTL, KC_DOT), KC_SLASH, KC_RIGHT_SHIFT,
                                                                    LT(4, KC_ENTER),    LT(3, KC_BSPC),                             KC_DELETE, LT(2, KC_SPACE)
  ),
  // Mouse Layer
  [1] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_MS_WH_LEFT,  KC_MS_WH_UP,    KC_MS_WH_DOWN,  KC_MS_WH_RIGHT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, MS_ACL0,        MS_ACL2,        KC_MS_BTN2,     KC_MS_BTN1,     KC_TRANSPARENT,                                 KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_UP,       KC_MS_RIGHT,    KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  // Symbols Layer
  [2] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,         KC_TRANSPARENT, KC_TRANSPARENT,         KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_PIPE,                KC_LBRC,        KC_RBRC,                KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_LCBR,        KC_LPRN,                KC_RPRN,        KC_RCBR,                KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, MT(MOD_LCTL, KC_MINUS), DUAL_FUNC_1,    MT(MOD_LGUI, KC_EQUAL), KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                            KC_TRANSPARENT,         KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  // Media Layer
  [3] = LAYOUT_voyager(
    RGB_TOG,        RGB_MODE_FORWARD,    RGB_HUI,        RGB_HUD,             RGB_VAI,             RGB_VAD,                         KC_TRANSPARENT, KC_KP_7,       KC_KP_8,        KC_KP_9,        KC_TRANSPARENT, KC_TRANSPARENT,
    RGB_SAI,        KC_MEDIA_PREV_TRACK, KC_PAUSE,       KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK, KC_BRIGHTNESS_UP,                KC_TRANSPARENT, KC_KP_4,       KC_KP_5,        KC_KP_6,        KC_KP_PLUS,     KC_KP_ASTERISK,
    RGB_SAD,        KC_TRANSPARENT,      KC_AUDIO_MUTE,  KC_AUDIO_VOL_DOWN,   KC_AUDIO_VOL_UP,     KC_BRIGHTNESS_DOWN,              KC_TRANSPARENT, KC_KP_1,       KC_KP_2,        KC_KP_3,        KC_KP_EQUAL,    KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT,      KC_TRANSPARENT, KC_TRANSPARENT,      KC_TRANSPARENT,      KC_TRANSPARENT,                  KC_TRANSPARENT, KC_KP_0,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                              KC_TRANSPARENT,      KC_TRANSPARENT,                  KC_TRANSPARENT, KC_TRANSPARENT
  ),
  // Navigation Layer
  [4] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_HOME,        KC_PGDN,        KC_PAGE_UP,     KC_END,         KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, LGUI(KC_LBRC),  KC_TRANSPARENT, RGUI(KC_RBRC),  KC_TRANSPARENT, KC_TRANSPARENT,
                                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
};

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = LAYOUT(
  'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R',
  'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R',
  'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R',
  'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R',
  'L', 'L', 'R', 'R'
);

const uint16_t PROGMEM combo0[] = { LT(4,KC_ENTER), LT(2,KC_SPACE), COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, TG(1)),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case QK_MODS ... QK_MODS_MAX:
    // Mouse and consumer keys (volume, media) with modifiers work inconsistently across operating systems,
    // this makes sure that modifiers are always applied to the key that was pressed.
    if (IS_MOUSE_KEYCODE(QK_MODS_GET_BASIC_KEYCODE(keycode)) || IS_CONSUMER_KEYCODE(QK_MODS_GET_BASIC_KEYCODE(keycode))) {
      if (record->event.pressed) {
        add_mods(QK_MODS_GET_MODS(keycode));
        send_keyboard_report();
        wait_ms(2);
        register_code(QK_MODS_GET_BASIC_KEYCODE(keycode));
        return false;
      } else {
        wait_ms(2);
        del_mods(QK_MODS_GET_MODS(keycode));
      }
    }
    break;

    case DUAL_FUNC_0:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_LEFT_CTRL);
        } else {
          unregister_code16(KC_LEFT_CTRL);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_CAPS);
        } else {
          unregister_code16(KC_CAPS);
        }
      }
      return false;
    case DUAL_FUNC_1:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_PLUS);
        } else {
          unregister_code16(KC_PLUS);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_LEFT_ALT);
        } else {
          unregister_code16(KC_LEFT_ALT);
        }
      }
      return false;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}
