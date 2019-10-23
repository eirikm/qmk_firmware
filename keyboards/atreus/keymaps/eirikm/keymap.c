// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _COL 0
#define _QW 1
#define _RS 2
#define _LW 3
#define _NAV 4
#define _SYM 5


#define KC_AE LALT(KC_QUOT)
#define KC_OE LALT(KC_O)
#define KC_AA LALT(KC_A)

#define LS_Z MT(MOD_LSFT, KC_Z)
#define RS_SLSH MT(MOD_RSFT, KC_SLSH)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Colemak
* .--------------------------------------------.                 .--------------------------------------------.
* | Q      | W      | F      | P      | G      |                 | J      | L      | U      | Y      | ;      |
* +--------+--------+--------+--------+--------+                 +--------+--------+--------+-----------------+
* | A      | R      | S      | T      | D      |                 | H      | N      | E      | I      | O      |
* +--------+--------+--------+--------+--------+                 +--------+--------+--------------------------+
* | LSHT/Z | X      | C      | V      | B      |                 | K      | M      | ,      | .      | RSHT / |
* +--------+--------+--------+--------+-----------------+--------+--------+--------+-----------------+--------+
* | esc    | tab    | gui    | shift  | bspace | SYM_L  | NAV_L  | space  | raise  | -      | '      | enter  |
* '-----------------------------------------------------------------------------------------------------------'
*/

[_COL] = LAYOUT( /* Colemak */
    KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                      KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN ,
    KC_A,    KC_R,    KC_S,    KC_T,    KC_D,                      KC_H,    KC_N,    KC_E,    KC_I,    KC_O ,
    LS_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_K,    KC_M,    KC_COMM, KC_DOT,  RS_SLSH ,
    KC_ESC,  KC_TAB,  KC_LGUI, KC_LSFT, KC_BSPC, MO(_SYM),MO(_NAV),KC_SPC,  MO(_RS), KC_MINS, KC_QUOT, KC_ENT
),

/* QWERTY
* .--------------------------------------------.                 .--------------------------------------------.
* | Q      | W      | E      | R      | T      |                 | Y      | U      | I      | O      | P      |
* +--------+--------+--------+--------+--------+                 +--------+--------+--------+-----------------+
* | A      | S      | D      | F      | G      |                 | H      | J      | K      | L      | ;      |
* +--------+--------+--------+--------+--------+                 +--------+--------+--------------------------+
* | LSHT/Z | X      | C      | V      | B      |                 | N      | M      | ,      | .      | RSHT / |
* +--------+--------+--------+--------+-----------------+--------+--------+--------+-----------------+--------+
* | esc    | tab    | gui    | shift  | bspace | SYM_L  | alt    | space  | raise  | -      | '      | enter  |
* '-----------------------------------------------------------------------------------------------------------'
*/

[_QW] = LAYOUT( /* Qwerty */
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P    ,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN ,
    LS_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  RS_SLSH ,
    KC_ESC,  KC_TAB,  KC_LGUI, KC_LSFT, KC_BSPC, MO(_SYM),KC_LALT, KC_SPC,  MO(_RS), KC_MINS, KC_QUOT, KC_ENT
  ),


/* RAISE
* .--------------------------------------------.                 .--------------------------------------------.
* | !      | @      | up     | {      | }      |                 | pgup   | 7      | 8      | 9      | *      |
* +--------+--------+--------+--------+--------+                 +--------+--------+--------+-----------------+
* | #      | left   | down   | right  | $      |                 | pgdn   | 4      | 5      | 6      | +      |
* +--------+--------+--------+--------+--------+                 +--------+--------+--------------------------+
* | [      | ]      | (      | )      | &      |                 | `      | 1      | 2      | 3      | \      |
* +--------+--------+--------+--------+-----------------+--------+--------+--------+-----------------+--------+
* | lower  | insert | super  | shift  | bspace | ctrl   | alt    | space  | raise  | .      | 0      | =      |
* '-----------------------------------------------------------------------------------------------------------'
*/
  [_RS] = LAYOUT( /* [> RAISE <] */
    KC_EXLM, KC_AT,   KC_UP,   KC_LCBR, KC_RCBR,                   KC_PGUP, KC_7,    KC_8,   KC_9, KC_ASTR ,
    KC_HASH, KC_LEFT, KC_DOWN, KC_RGHT, KC_DLR,                    KC_PGDN, KC_4,    KC_5,   KC_6, KC_PLUS ,
    KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_AMPR,                   KC_GRV,  KC_1,    KC_2,   KC_3, KC_BSLS ,
    TG(_LW), KC_INS,  KC_LGUI, KC_LSFT, KC_BSPC, KC_LCTL, KC_LALT, KC_SPC,  _______, KC_DOT, KC_0, KC_EQL  ),

/* SYMBOL
* .--------------------------------------------.                 .--------------------------------------------.
* | QWERTY | TARMAK1|        |   +    |   _    |                 |        |        | æ      | ø      | å      |
* +--------+--------+--------+--------+--------+                 +--------+--------+--------+-----------------+
* |        |        |        |   =    |   -    |                 |        |        |        |        |        |
* +--------+--------+--------+--------+--------+                 +--------+--------+--------------------------+
* |        |        |        |        |        |                 |        |        |        |        |        |
* +--------+--------+--------+--------+-----------------+--------+--------+--------+-----------------+--------+
* |        |        |        |        |        |        |        |        |        |        |        |        |
* '-----------------------------------------------------------------------------------------------------------'
*/
  [_SYM] = LAYOUT( /* [> SYMBOL <] */
    DF(_QW), DF(_COL),_______, _______, _______,                   _______, _______, KC_AE  , KC_OE  , KC_AA   ,
    _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______ ,
    _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______ ,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ ),

/* NAVIGATION
* .--------------------------------------------.                 .--------------------------------------------.
* |        |        |        |        |        |                 |        |        |   up   |        |        |
* +--------+--------+--------+--------+--------+                 +--------+--------+--------+-----------------+
* |        |        |        |        |        |                 |        |  left  |  down  | right  |        |
* +--------+--------+--------+--------+--------+                 +--------+--------+--------------------------+
* |        |        |        |        |        |                 |        |        |        |        |        |
* +--------+--------+--------+--------+-----------------+--------+--------+--------+-----------------+--------+
* |        |        |        |        |        |        |        |        |        |        |        |        |
* '-----------------------------------------------------------------------------------------------------------'
*/
  [_NAV] = LAYOUT( /* [> NAVIGATION <] */
    _______, _______, _______, _______, _______,                   _______, _______, KC_UP  , _______, _______ ,
    _______, _______, _______, _______, _______,                   _______, KC_LEFT, KC_DOWN, KC_RGHT, _______ ,
    _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______ ,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ ),

/* LOWER
* .--------------------------------------------.                 .--------------------------------------------.
* | insert | home   | up     | end    | pgup   |                 | up     | F7     | F8     | F9     | F10    |
* +--------+--------+--------+--------+--------+                 +--------+--------+--------+-----------------+
* | del    | left   | down   | right  | pgdn   |                 | down   | F4     | F5     | F6     | F11    |
* +--------+--------+--------+--------+--------+                 +--------+--------+--------------------------+
* |        | volup  |        |        | reset  |                 |        | F1     | F2     | F3     | F12    |
* +--------+--------+--------+--------+-----------------+--------+--------+--------+-----------------+--------+
* |        | voldn  | super  | shift  | bspace | ctrl   | alt    | space  | L0     | prtsc  | scroll | pause  |
* '-----------------------------------------------------------------------------------------------------------'
*/
  [_LW] = LAYOUT( /* [> LOWER <] */
    KC_INS,  KC_HOME, KC_UP,   KC_END,  KC_PGUP,                   KC_UP,   KC_F7,   KC_F8,   KC_F9,   KC_F10  ,
    KC_DELT, KC_LEFT, KC_DOWN, KC_RGHT, KC_DOWN,                   KC_DOWN, KC_F4,   KC_F5,   KC_F6,   KC_F11  ,
    KC_NO,   KC_VOLU, KC_NO,   KC_NO,   RESET,                     KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F12  ,
    KC_NO,   KC_VOLD, KC_LGUI, KC_LSFT, KC_BSPC, KC_LCTL, KC_LALT, KC_SPC,  TO(_QW), KC_PSCR, KC_SLCK, KC_PAUS )
};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        register_code(KC_RSFT);
      } else {
        unregister_code(KC_RSFT);
      }
    break;
  }
  return MACRO_NONE;
};
