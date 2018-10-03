#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define BASE 0
#define META 1
#define SYMB 2
#define GAME 3

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* BASE
   * ,--------------------------------------------------.   ,--------------------------------------------------.
   * | Tab  |   Q  |   W  |   E  |   R  |  T   |   (    |   |    )   |  Y   |   U  |   I  |   O  |   P  | Bksp |
   * |------+------+------+------+------+------+--------|   |--------+------+------+------+------+------+------|
   * | LCtrl|   A  |   S  |   D  |   F  |  G   |   {    |   |    }   |  H   |  J   |   K  |   L  |   ;  | Enter|
   * |------+------+------+------+------+------+--------|   |--------|------+------+------+------+------+------|
   * | LSft |   Z  |   X  |   C  |   V  |  B   |   [    |   |    ]   |  N   |   M  |   ,  |   .  |   /  | RSft |
   * |------+------+------+------+------+------+--------|   |--------+------+------+------+------+------+------|
   * | RCtrl|   `  |   \  |ESCAlt| META | LGUI | Spc/Sft|   | Spc/Sft| RGUI | SYMB |EntAlt|   '  |   -  |   =  |
   * `--------------------------------------------------'   `--------------------------------------------------'
   */
  [BASE] = LAYOUT( \
    KC_TAB,   KC_Q,   KC_W,    KC_E,           KC_R,             KC_T,    KC_LPRN,        KC_RPRN,        KC_Y,    KC_U,             KC_I,            KC_O,    KC_P,    KC_BSPC, \
    KC_LCTL,  KC_A,   KC_S,    KC_D,           KC_F,             KC_G,    KC_LCBR,        KC_RCBR,        KC_H,    KC_J,             KC_K,            KC_L,    KC_SCLN, KC_ENT, \
    KC_LSFT,  KC_Z,   KC_X,    KC_C,           KC_V,             KC_B,    KC_LBRC,        KC_RBRC,        KC_N,    KC_M,             KC_COMM,         KC_DOT,  KC_SLSH, KC_RSFT, \
    KC_RCTL,  KC_GRV, KC_BSLS, LALT_T(KC_DEL), LT(META, KC_ESC), KC_LGUI, LSFT_T(KC_SPC), RSFT_T(KC_SPC), KC_RGUI, LT(SYMB, KC_ENT), RALT_T(KC_BSPC), KC_QUOT, KC_MINS, KC_EQL \
  ),

  /* META
   * ,--------------------------------------------------.   ,--------------------------------------------------.
   * | HOME |   !  |   @  |   #  |   $  |   %  |  PGUP  |   |  PGDN  |   ^  |   &  |   *  |   (  |   )  | Del  |
   * |------+------+------+------+------+------+--------|   |--------+------+------+------+------+------+------|
   * | LCtrl|   1  |   2  |   3  |   4  |   5  |  HOME  |   |  END   |   6  |   7  |   8  |   9  |   0  | Enter|
   * |------+------+------+------+------+------+--------|   |--------+------+------+------+------+------+------|
   * | LSft | ---- | ---- | ---- | ---- |  UP  |  LEFT  |   |  RIGHT | DOWN | ---- | ---- | ---- |  UP  | RSft |
   * |------+------+------+------+------+------+--------|   |--------+------+------+------+------+------+------|
   * | RCtrl|   `  |   \  | LAlt | META | LGUI | Spc/Sft|   | Spc/Sft| RGUI | SYMB | RAlt | LEFT | DOWN | RIGHT|
   * `--------------------------------------------------'   `--------------------------------------------------'
   */
  [META] = LAYOUT( \
    KC_HOME, S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5), KC_PGUP,  KC_PGDN, S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), KC_DEL, \
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_HOME,  KC_END,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,\
    _______, _______, _______, _______, _______, KC_UP,   KC_LEFT,  KC_RGHT, KC_DOWN, _______, _______, _______, KC_UP,   _______, \
    _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT \
  ),

  /* SYMB
   * ,--------------------------------------------------.   ,--------------------------------------------------.
   * | END  |   !  |   @  |   #  |   $  |   %  |  PGUP  |   |  PGDN  |   ^  |   &  |   *  |   (  |   )  | Del  |
   * |------+------+------+------+------+------+--------|   |--------+------+------+------+------+------+------|
   * | LCtrl|  F1  |  F2  |  F3  |  F4  |  F5  |  HOME  |   |  END   |  F6  |  F7  |  F8  |  F9  |  F10 | Enter|
   * |------+------+------+------+------+------+--------|   |--------+------+------+------+------+------+------|
   * | LSft |  F11 |  F12 | F13  | F14  |  UP  |  LEFT  |   |  RIGHT | DOWN | ---- | ---- | ---- |  UP  | RSft |
   * |------+------+------+------+------+------+--------|   |--------+------+------+------+------+------+------|
   * | RCtrl|   `  |   \  | LAlt | META | LGUI | Spc/Sft|   | Spc/Sft| RGUI | SYMB | RAlt | LEFT | DOWN | RIGHT|
   * `--------------------------------------------------'   `--------------------------------------------------'
   */
  [SYMB] = LAYOUT( \
    KC_END,  S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5), KC_PGUP, KC_PGDN,  S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), KC_DEL, \
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_HOME, KC_END,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, \
    _______, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_UP,   KC_LEFT, KC_RGHT,  KC_DOWN, XXXXXXX, XXXXXXX, XXXXXXX, KC_UP,   _______, \
    _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT  \
  )
};
