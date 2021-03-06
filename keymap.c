/* Copyright 2015-2017 Jack Humbert
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
#include "muse.h"


enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _FUNC,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  FUNC,
  BACKLIT
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  `   |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Func |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | GUI  |      |  Alt | Lower| Ctrl |   -  | SPC  | Shift| Raise|   '  |      |Hangle|
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
  KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
  KC_GRV,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, FUNC,
  KC_LGUI, XXXXXXX, KC_LALT, LOWER,   KC_LCTL, KC_MINS, KC_SPC,  KC_RSFT, RAISE,   KC_QUOT, XXXXXXX, KC_RALT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * | Vol+ |      |   7  |   8  |   9  |      |      |  [   |  +   |  ]   |  Ins | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Vol- |      |   4  |   5  |   6  |      | Left | Down |  Up  |Right |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Mute |      |   1  |   2  |   3  |   0  |      |  (   |  =   |  )   |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |------|      |------|------|------|      |      |------|------|      |      |------|
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
  KC_VOLU, XXXXXXX, KC_7,    KC_8,    KC_9,    XXXXXXX, XXXXXXX, KC_LBRC, KC_PLUS, KC_RBRC, KC_INS,  KC_DEL,
  KC_VOLD, XXXXXXX, KC_4,    KC_5,    KC_6,    XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
  KC_MUTE, XXXXXXX, KC_1,    KC_2,    KC_3,    KC_0,    XXXXXXX, KC_LPRN, KC_EQL,  KC_RPRN, XXXXXXX, XXXXXXX,
  _______, XXXXXXX, _______, _______, _______, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, _______
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * | Pause|      |      |      |      |      |      |  &   |  *   |  |   |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | SLock|      |      |      |      |      |      |  $   |  %   |  ^   |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Prsc |      |      |      |      |      |  \   |  !   |  @   |  #   |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |------|      |------|------|------|      |      |------|------|      |      |------|
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
  KC_PAUS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_AMPR, KC_ASTR, KC_PIPE, XXXXXXX, XXXXXXX,
  KC_SLCK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DLR,  KC_PERC, KC_CIRC, XXXXXXX, XXXXXXX,
  KC_PSCR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSLS, KC_EXLM, KC_AT,   KC_HASH, XXXXXXX, XXXXXXX,
  _______, XXXXXXX, _______, _______, _______, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, _______
),

/* Func
 * ,-----------------------------------------------------------------------------------.
 * |      |      |  F7  |  F8  |  F9  |  F12 |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |  F7  |  F8  |  F9  |  F11 |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |  F1  |  F2  |  F3  |  F10 |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |------|      |------|------|------|      |      |------|------|      |      |------|
 * `-----------------------------------------------------------------------------------'
 */
[_FUNC] = LAYOUT_planck_grid(
  XXXXXXX, XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, KC_F4,   KC_F5,   KC_F6,   KC_F11,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F10,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  _______, XXXXXXX, _______, _______, _______, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, _______
),


/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|TermOn|TermOf|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  XXXXXXX,  XXXXXXX, XXXXXXX, _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
)

};


layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case FUNC:
      if (record->event.pressed) {
	layer_on(_FUNC);
      } else {
        layer_off(_FUNC);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        #ifdef KEYBOARD_planck_rev5
          writePinLow(E6);
        #endif
      } else {
        unregister_code(KC_RSFT);
        #ifdef KEYBOARD_planck_rev5
          writePinHigh(E6);
        #endif
      }
      return false;
      break;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool encoder_update(bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_DOWN);
      #else
        tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_UP);
      #else
        tap_code(KC_PGUP);
      #endif
    }
  }
    return true;
}

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
            if (active) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            break;
        }
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
