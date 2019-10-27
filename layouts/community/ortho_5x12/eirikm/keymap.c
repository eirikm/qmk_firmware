#include QMK_KEYBOARD_H
//#include "keymap_nordic.h"
//#include "keymap_norwegian.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _COLEMAK 0
#define _NAV 1
#define _SYM 2
#define _ADJ 16

#define LS_Z MT(MOD_LSFT, KC_Z)
#define RS_SL MT(MOD_RSFT, KC_SLSH)
#define NAV_SPC LT(_NAV, KC_SPC)
#define SYM_BSP LT(_SYM, KC_BSPC)

enum custom_keycodes {
    MLARROW = SAFE_RANGE,
    MRARROW,
    MLPIPE,
    MRPIPE,
    MLCOMP,
    MRCOMP,
    MRFARRO
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

enum {
    TD_SC_AA = 0,
    TD_Y_OE,
    TD_U_AE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak
 * ,-----------------------------------------------------. ,-----------------------------------------------------.
 * | ESC    |   1    |   2    |   3    |   4    |   5    | |   6    |   7    |   8    |   9    |   0    | `      |
 * |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
 * | Tab    |   Q    |   W    |   F    |   P    |   G    | |   J    |   L    |   U    |   Y    |   ;    | '      |
 * |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
 * | LCTRL  |   A    |   R    |   S    |   T    |   D    | |   H    |   N    |   E    |   I    |   O    | Enter  |
 * |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
 * | LSHT/( |   Z    |   X    |   C    |   V    |   B    | |   K    |   M    |   ,    |   .    |   /    | RSHT/) |
 * |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
 * | Adjust |        |        | Alt    | GUI    | Bs/Sym | | SPC/NAV|        |        |        |        |        |
 * `-----------------------------------------------------' `-----------------------------------------------------'
 */
[_COLEMAK] = LAYOUT( \
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,   \
     KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,      KC_J,    KC_L,    TD(TD_U_AE),TD(TD_Y_OE),TD(TD_SC_AA),KC_QUOT,  \
     KC_LCTRL,KC_A,    KC_R,    KC_S,    KC_T,    KC_D,      KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_ENT,   \
     KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,      KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC,  \
     MO(_ADJ),XXXXXXX, XXXXXXX, KC_LALT, KC_LGUI, SYM_BSP,   NAV_SPC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX   \
),

/* NAVIGATION
 * ,-----------------------------------------------------. ,-----------------------------------------------------.
 * |        | F1     | F2     | F3     | F4     | F5     | | F6     | F7     | F8     | F9     | F10    | F11    |
 * |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        | | PG UP  |        | UP     |        |        | F12    |
 * |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        | | PG DN  | LEFT   | DOWN   | RIGHT  |        |        |
 * |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        | |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        | DEL    | |        |        |        |        |        |        |
 * `-----------------------------------------------------' `-----------------------------------------------------'
 */
[_NAV] = LAYOUT( \
     _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  \
     _______, _______, _______, _______, _______, _______,   KC_PGUP, _______, KC_UP,   _______, _______, KC_F12,  \
     _______, _______, _______, _______, _______, _______,   KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, \
     _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, \
     _______, _______, _______, _______, _______, KC_DEL,    _______, _______, _______, _______, _______, _______  \
),

/* Symbol
 * ,-----------------------------------------------------. ,-----------------------------------------------------.
 * |        |        |        |        |        |        | |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
 * |        | \      | {      | }      | +      | _      | |        |        | æ      | ø      | å      |        |
 * |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
 * |        | |      | [      | ]      | =      | -      | |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
 * |        | <<     | <|     | <-     |        |        | |        | =>     | ->     | |>     | >>     |        |
 * |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        | |        |        |        |        |        |        |
 * `-----------------------------------------------------' `-----------------------------------------------------'
 */
[_SYM] = LAYOUT( \
     _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, \
     _______, KC_BSLS, KC_LCBR, KC_RCBR, KC_PLUS, KC_UNDS,   _______, _______, _______, _______, _______, _______, \
     _______, KC_PIPE, KC_LBRC, KC_RBRC, KC_EQL,  KC_MINS,   _______, _______, _______, _______, _______, _______, \
     _______, MLCOMP,  MLPIPE,  MLARROW, _______, _______,   _______, MRFARRO, MRARROW, MRPIPE,  MRCOMP,  _______, \
     _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______  \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------. ,-----------------------------------------------------.
 * |        |        |        |        |        |        | |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
 * |        | Reset  |        |        |        |        | |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        | |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        | |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        | |        |        |        |        |        |        |
 * `-----------------------------------------------------' `-----------------------------------------------------'
 */
[_ADJ] =  LAYOUT( \
     _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, \
     _______, RESET  , _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, \
     _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, \
     _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, \
     _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______  \
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch(keycode) {
            case MLARROW:
                SEND_STRING("<-");
                return false;
            case MRARROW:
                SEND_STRING("->");
                return false;
            case MRFARRO:
                SEND_STRING("=>");
                return false;
            case MLPIPE:
                SEND_STRING("<|");
                return false;
            case MRPIPE:
                SEND_STRING("|>");
                return false;
            case MLCOMP:
                SEND_STRING("<<");
                return false;
            case MRCOMP:
                SEND_STRING(">>");
                return false;
        }
    }
    return true;
};

void dance_aa_finished (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code (KC_SCLN);
    } else {
        register_code (KC_LALT);
        register_code (KC_A);
    }
}

void dance_aa_reset (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code (KC_SCLN);
    } else {
        unregister_code (KC_LALT);
        unregister_code (KC_A);
    }
}

void dance_ae_finished (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code (KC_U);
    } else {
        register_code (KC_LALT);
        register_code (KC_QUOT);
    }
}

void dance_ae_reset (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code (KC_U);
    } else {
        unregister_code (KC_LALT);
        unregister_code (KC_QUOT);
    }
}

void dance_oe_finished (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code (KC_Y);
    } else {
        register_code (KC_LALT);
        register_code (KC_O);
    }
}

void dance_oe_reset (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code (KC_Y);
    } else {
        unregister_code (KC_LALT);
        unregister_code (KC_O);
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
        [TD_SC_AA] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_aa_finished, dance_aa_reset),
        [TD_Y_OE] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_oe_finished, dance_oe_reset),
        [TD_U_AE] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_ae_finished, dance_ae_reset)
};

