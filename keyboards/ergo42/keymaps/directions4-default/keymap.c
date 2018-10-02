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
   * ,-----------------------------------------------------.   ,-----------------------------------------------------.
   * | ESC  | Tab  |   Q  |   W  |   E  |   R  |  T        |   |  Y        |   U  |   I  |   O  |   P  |   [  | Bksp |
   * |------+------+------+------+------+------+-----------|   |-----------+------+------+------+------+------+------|
   * | LSft | LCtrl|   A  |   S  |   D  |   F  |  G        |   |  H        |   J  |   K  |   L  |   ;  |   ]  | Enter|
   * |------+------+------+------+------+------+-----------|   |-----------|------+------+------+------+------+------|
   * | META | SYMB |   Z  |   X  |   C  |   V  |  B        |   |  N        |   M  |   ,  |   .  |   /  |   (  |   )  |
   * |------+------+------+------+------+------+-----------|   |-----------+------+------+------+------+------+------|
   * | META | SYMB |   `  |   \  | LAlt | LGUI |Space/shift|   |Space/shift|R_GUI | RAlt |   '  |  -   |   =  | SYMB |
   * `-----------------------------------------------------'   `-----------------------------------------------------'
   */
  [BASE] = LAYOUT( \
    KC_ESC,   KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,     KC_T,          KC_Y,          KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,  KC_BSPC, \
    KC_LSFT,  KC_LCTL,  KC_A,   KC_S,    KC_D,    KC_F,     KC_G,          KC_H,          KC_J,    KC_K,    KC_L,    KC_SCLN, KC_RBRC,  KC_ENT, \
    MO(META), MO(SYMB), KC_Z,   KC_X,    KC_C,    KC_V,     KC_B,          KC_N,          KC_M,    KC_COMM, KC_DOT,  KC_SLSH, S(KC_9),  S(KC_0), \
    TG(META), TG(SYMB), KC_GRV, KC_BSLS, KC_LALT, KC_LGUI,  SFT_T(KC_SPC), SFT_T(KC_SPC), KC_RGUI, KC_RALT, KC_QUOT, KC_MINS, KC_EQL,   MO(SYMB) \
  ),

  /* META
   * ,------------------------------------------------.   ,------------------------------------------------.
   * | HOME |   1  |   2  |   3  |   4  |   5  | PGUP |   | PGDN |   6  |   7  |   8  |   9  |   0  | Del  |
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * | F1   |  F2  | Left | Down | Up   | Righ |  <-  |   |  ->  | Left | Down | Up   |Right |      | Enter|
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * | META | SYMB |  F3  |  F4  |  F5  |  F6  | HOME |   | END  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * | META | SYMB |   `  |   \  | LAlt | LGUI |Space |   |Space | RGUI | RAlt |  '   |  -   |  =   | SYMB |
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [META] = LAYOUT( \
    KC_HOME, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_PGUP,  KC_PGDN, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, \
    KC_F1,   KC_F2,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_LEFT,  KC_RGHT, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_RCTL, _______,\
    _______, _______, KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_HOME,  KC_END,  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
    _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______ \
  ),

  /* SYMB
   * ,------------------------------------------------.   ,------------------------------------------------.
   * | ESC  |   !  |   @  |   #  |   $  |   %  |  [   |   |  ]   |   ^  |   &  |   *  |   (  |   )  | Bksp |
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * | LSft |      |      |      |      |      |  (   |   |  )   |      |      |      |      |      | Enter|
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * | META | SYMB |      |      |      |      |  {   |   |  }   |      |      |      |      |  UP  | RSft |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * | META | SYMB |   `  |   \  | LAlt | LGUI |Space |   |Space |   '  |   -  |   =  | LEFT | DOWN | RIGHT|
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [SYMB] = LAYOUT( \
    _______, S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5), KC_LBRC,    KC_RBRC,    S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), _______, \
    _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, S(KC_9),    S(KC_0),    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
    _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, S(KC_LBRC), S(KC_RBRC), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_UP,   _______, \
    _______, _______, _______, _______, _______, _______, _______,    _______,    _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT  \
  )

};
