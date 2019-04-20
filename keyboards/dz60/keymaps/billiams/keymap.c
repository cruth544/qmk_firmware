#include QMK_KEYBOARD_H

#define ______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,-----------------------------------------------------------------------------------------.
   * |  `  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |   Bkspc   |
   * |-----------------------------------------------------------------------------------------+
   * | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |    \   |
   * |-----------------------------------------------------------------------------------------+
   * |   Fn    |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter    |
   * |-----------------------------------------------------------------------------------------+
   * | Shift     |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |Tap(/) Shft|  U  | ESC |
   * |-----------------------------------------------------------------------------------------+
   * | Ctrl |  Alt  |  Cmd  |              Space                | Cmd |  Fn  |  L  |  D  |  R  |
   * `-----------------------------------------------------------------------------------------'
   */

  LAYOUT_directional(
      KC_GRAVE, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, ______, KC_BSPC,
      KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
      MO(1), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
      KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, ______, RSFT_T(KC_SLSH) , KC_UP, KC_ESCAPE,
      KC_LCTL, KC_LALT, KC_LGUI, KC_SPC, KC_SPC, KC_SPC, KC_RGUI, MO(1), KC_LEFT, KC_DOWN, KC_RIGHT
      ),

  /* FN Layer
   * ,-----------------------------------------------------------------------------------------.
   * |     |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |    DEL    |
   * |-----------------------------------------------------------------------------------------+
   * |        |RBB T|RGB M| Hue+| Hue-| Sat+| Sat-| Val+| Val-|     |     |     | Prev | Next  |
   * |-----------------------------------------------------------------------------------------+
   * |         | BL T| BL M| BL- | BL+ |     |     |     |     |     | Vol-| Vol+|  Play/Pause |
   * |-----------------------------------------------------------------------------------------+
   * |           |     |     |     |     |     |     |     |Scr- |Scr+ |           |PG_UP|RESET|
   * |-----------------------------------------------------------------------------------------+
   * |      |       |       |            Play/Pause             |     |      | HOME|PG_DN| END |
   * `-----------------------------------------------------------------------------------------'
   */

  LAYOUT_directional(
      ______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, KC_F11, KC_F12, ______, KC_DEL,
      ______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, ______, ______, ______, KC_MEDIA_REWIND, KC_MEDIA_FAST_FORWARD,
      ______, BL_TOGG, BL_STEP, BL_DEC, BL_INC, ______, ______, ______, ______, ______, KC__VOLDOWN, KC__VOLUP,
      KC_MEDIA_PLAY_PAUSE, ______, ______, ______, ______, ______, ______, ______, ______, KC_BRIGHTNESS_DOWN, KC_BRIGHTNESS_UP, ______, ______, KC_PGUP, RESET,
      ______, ______, ______, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_PLAY_PAUSE, ______, ______, KC_HOME, KC_PGDOWN, KC_END
      ),
};
