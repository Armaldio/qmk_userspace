#include QMK_KEYBOARD_H
#include "rgb_matrix.h"

// extern keymap_config_t keymap_config;

// #if __has_include("keymap.h")
// #    include "keymap.h"
// #endif

#define LAYER_LOCK_IDLE_TIMEOUT 60000 // Turn off after 60 seconds.

#define _AZERTY 0
#define _AZERTY_EN 10
#define _COLEMAK 1
#define _FUNC 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Qwerty
    * .-----------------------------------------------------------------------------------.
    * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
    * |------+------+------+------+------+-------------+------+------+------+------+------|
    * | Func |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
    * |------+------+------+------+------+------|------+------+------+------+------+------|
    * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Ctrl | GUI  | Esc  | Alt  |Lower |  Esc |Space |Raise | Left | Up   | Down |Right |
    * .-----------------------------------------------------------------------------------.
    */
    [_AZERTY] = LAYOUT_ortho_5x15(
        KC_ESC,       KC_1,    KC_2,    KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,    KC_9,    KC_0,      KC_MINS, KC_EQL,  KC_BSPC,        KC_BSPC,
        KC_TAB,       KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,      KC_LBRC, KC_RBRC, TG(_AZERTY_EN), MO(_AZERTY),
        TG(_COLEMAK), KC_A,    KC_S,    KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN,   KC_QUOT, KC_ENT,  KC_ENT,         KC_HOME,
        KC_LSFT,      KC_NUBS, KC_Z,    KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,    KC_COMM, KC_DOT,    KC_SLSH, KC_NUHS, KC_UP,          KC_END,
        KC_LCTL,      KC_LGUI, KC_LOPT, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_DEL, KC_BSPC, KC_RALT, MO(_FUNC), BL_UP,   KC_LEFT, KC_DOWN,        KC_RGHT
    ),
    [_AZERTY_EN] = LAYOUT_ortho_5x15(
        KC_ESC,       KC_1,    KC_2,    KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,    KC_9,    KC_0,      KC_MINS, KC_EQL,  KC_BSPC,        KC_BSPC,
        KC_TAB,       KC_A,    KC_Z,    KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,      KC_LBRC, KC_RBRC, TG(_AZERTY_EN), MO(_AZERTY),
        TG(_COLEMAK), KC_Q,    KC_S,    KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    KC_M,      KC_QUOT, KC_ENT,  KC_ENT,         KC_HOME,
        KC_LSFT,      KC_NUBS, KC_W,    KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_COMM, KC_DOT,  KC_SLSH,   KC_SLSH, KC_NUHS, KC_UP,          KC_END,
        KC_LCTL,      KC_LGUI, KC_LOPT, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_DEL, KC_BSPC, KC_RALT, MO(_FUNC), BL_UP,   KC_LEFT, KC_DOWN,        KC_RGHT
    ),
    [_COLEMAK] = LAYOUT_ortho_5x15(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_A,    KC_Z,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_Q,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_W,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [_FUNC] = LAYOUT_ortho_5x15(
        KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR,   KC_PSCR,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,
        KC_RCTL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, QK_REBOOT, QK_BOOT
    )
};

void azerty_color(void) {
    // Blue
    rgb_matrix_sethsv_noeeprom(170, 255, 255);
}

void azerty_en_color(void) {
    // Orange
    rgb_matrix_sethsv_noeeprom(120, 100, 100);
}

void colemak_color(void) {
    // Yellow
    rgb_matrix_sethsv_noeeprom(43, 255, 255);
}

void func_color(void) {
    // Purple
    rgb_matrix_sethsv_noeeprom(213, 255, 255);
}

void keyboard_post_init_user(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    azerty_color();
}

void matrix_init_user(void) {
    azerty_color();
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _AZERTY:
            azerty_color();
            break;
        case _AZERTY_EN:
            azerty_en_color();
            break;
        case _COLEMAK:
            colemak_color();
            break;
        case _FUNC:
            func_color();
            break;
        default:
            azerty_color();
            break;
    }
    return state;
}

