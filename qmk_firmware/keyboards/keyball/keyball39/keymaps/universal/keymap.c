#include QMK_KEYBOARD_H
#include "quantum.h"

enum layers {
    _BASE,
    _MOUSE,
    _NUM,
    _SCROLL,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_universal(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,       KC_O,       KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,       KC_L,       KC_SCLN,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M,    KC_MS_BTN1, KC_MS_BTN2, KC_SLSH,
        KC_ESC,  KC_LALT, KC_LGUI, LT(_SCROLL, KC_TAB), MT(MOD_LCTL, KC_DEL), LT(_NUM, KC_SPC),
                                                                         LT(_NUM, KC_ENT), KC_BSPC, KC_NO, KC_NO, KC_NO, KC_RSFT
    ),

    [_MOUSE] = LAYOUT_universal(
        S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5),                     S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0),
        KC_TRNS, KC_PGUP, KC_UP,   KC_PGDN, KC_HOME,                      KC_QUOT, KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,
        KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,                       KC_SLSH, KC_COMM, KC_DOT,  KC_LBRC, KC_RBRC,
        KC_LSFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,             KC_TRNS, KC_MS_BTN1, KC_MS_BTN2, KC_TRNS, KC_TRNS, KC_RSFT
    ),

    [_NUM] = LAYOUT_universal(
        KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_TRNS,                          KC_KP_0, KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_SLASH,
        KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_TRNS,                          KC_KP_DOT, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_ASTERISK,
        KC_F9,  KC_F10, KC_F11, KC_F12, KC_TRNS,                          KC_KP_EQUAL, KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_MINUS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_KP_PLUS
    ),

    [_SCROLL] = LAYOUT_universal(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
};

void keyboard_post_init_user(void) {
    set_auto_mouse_layer(_MOUSE);
    set_auto_mouse_enable(true);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    keyball_set_scroll_mode(get_highest_layer(state) == _SCROLL);
    return state;
}

#ifdef OLED_ENABLE
#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif
