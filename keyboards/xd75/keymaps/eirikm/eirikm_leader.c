LEADER_EXTERNS();
void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_THREE_KEYS(KC_I, KC_B, KC_P) {
//      SEND_STRING("QMK is awesome.");
      register_code(KC_LGUI);
      register_code(KC_F9);
      unregister_code(KC_F9);
      unregister_code(KC_LGUI);
    }
  }
}
