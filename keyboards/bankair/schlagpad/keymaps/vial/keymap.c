#include QMK_KEYBOARD_H

#define TAP_TAPPING_TERM 260

void keyboard_post_init_user(void) {
    vial_tap_dance_entry_t td0 = { KC_1,
                                   KC_1,
                                   KC_0,
                                   KC_1,
                                   TAP_TAPPING_TERM };
    dynamic_keymap_set_tap_dance(0, &td0);
    vial_tap_dance_entry_t td1 = { KC_5,
                                   KC_5,
                                   KC_ENTER,
                                   KC_5,
                                   TAP_TAPPING_TERM };
    dynamic_keymap_set_tap_dance(1, &td1);
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* LAYER 0
 * ,-----------------------.
 * |   7   |   8   |   9   |
 * |-------+-------+-------|
 * |   4   | 5/ENT |   6   | Dbl Tap 5 for Enter
 * |-------+-------+-------|
 * |   1   |   2   | 3/FN  | 1/0 = Dbl Tap 1 for 0  -  3/FN = Hold 3 for FN
 * `-----------------------'
 */
[0] = LAYOUT(
  KC_7,       KC_8,      KC_9,
  KC_4,       TD(1),     KC_6,
  TD(0),      KC_2,      LT(1, KC_3)
),

/* LAYER 1
 * ,-----------------------.
 * |  ESC  |   +   |   -   |
 * |-------+-------+-------|
 * |  BSPC |   *   |   /   |
 * |-------+-------+-------|
 * |  0    |   .   |       |
 * `-----------------------'
 */
[1] = LAYOUT(
  KC_ESC,   KC_PLUS, KC_MINS,
  KC_ENTER, KC_ASTR, KC_SLSH,
  KC_0,     KC_DOT,  KC_TRNS
)

};
