#include QMK_KEYBOARD_H
#include "quantum.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _GAMER  1

// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LSFT_T(KC_D)
#define HOME_F LCTL_T(KC_F)

// Right-hand home row mods
#define HOME_J RCTL_T(KC_J)
#define HOME_K RSFT_T(KC_K)
#define HOME_L RALT_T(KC_L)
#define HOME_SCLN RGUI_T(KC_SCLN)

// Tap Dance declarations
enum {
    TD_COMM_DSFT,
	TD_C_V,
	TD_PRNT_GAME,
};

// TD_COMM_DSFT logic
void comm_dsft(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code(KC_COMM);
    } else {
        tap_code(KC_RSFT);
		tap_code(KC_RSFT);
    }
}

// TD_C_V logic
void c_v(qk_tap_dance_state_t *state, void *user_data) {
	// only tap V if C was double tapped and "ctrl" is held 
	if (state->count == 2 && (get_mods() & MOD_MASK_CTRL)) {
		tap_code(KC_V);
	// else send c the number of times the key was tapped
	} else {
		int i = 0;
		while (i < state->count) {
		  tap_code(KC_C);
		  i++;
		}
	}
}

// Tap dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_COMM_DSFT] = ACTION_TAP_DANCE_FN(comm_dsft),
	[TD_C_V] = ACTION_TAP_DANCE_FN(c_v),
	[TD_PRNT_GAME] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_PSCR, _GAMER),
};

// macro custom keycodes
enum custom_keycodes {
    WHAT_A_SAVE = SAFE_RANGE,
};

// custom functionality for each keypress (register) and depress (unregister)
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case WHAT_A_SAVE:
        if (record->event.pressed) {
            // when keycode WHAT_A_SAVE is pressed
            SEND_STRING("tWhat a save! (not toxic)"SS_TAP(X_ENT));
        } else {
            // when keycode WHAT_A_SAVE is released
        }
        break;
    }
    return true;
};

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=false;
  debug_matrix=false;
  debug_keyboard=false;
  //debug_mouse=true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
		case HOME_D:
			return TAPPING_TERM - 20;
		case HOME_K:
			return TAPPING_TERM - 20;
		//case KC_C:
		//	return TAPPING_TERM;
        default:
            return TAPPING_TERM;
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_5x7(
        // left hand
        KC_F5, 		KC_1, 	KC_2, 	KC_3, 		KC_4, 	KC_5, 	KC_GRV,        
		KC_TAB,   	KC_Q, 	KC_W, 	KC_E, 		KC_R, 	KC_T, 	KC_MINS,
        KC_CAPS,  	HOME_A, HOME_S, HOME_D, 	HOME_F, KC_G,	KC_LBRC,
        _______,  	KC_Z, 	KC_X, 	TD(TD_C_V), KC_V, KC_B,
        _______,  _______, KC_LEFT, KC_DOWN,
										KC_BSPC,  			KC_DELETE,
										TD(TD_PRNT_GAME),   KC_LWIN,
										QK_BOOT,   			KC_PGUP,
        // right hand
                          KC_EQUAL, KC_6,    KC_7,    KC_8,     		KC_9,  	KC_0,  		KC_GRV,
                          KC_EQUAL, KC_Y,    KC_U,    KC_I,     		KC_O,   KC_P,   	KC_BSLS,
						  KC_RBRC,  KC_H,    HOME_J,  HOME_K,   		HOME_L, HOME_SCLN,	KC_QUOT,
									KC_N,    KC_M,    TD(TD_COMM_DSFT), KC_DOT,	KC_SLSH,	_______,
																KC_UP, 	KC_RGHT, 	KC_INS, KC_RGHT,
             KC_ENT, KC_SPACE,
             KC_ESC, KC_RWIN,
             KC_PGDN, QK_BOOT
    ),

    [_GAMER] = LAYOUT_5x7(
        // left hand
        WHAT_A_SAVE, 	_______, 	_______, 	_______, 	_______, 	_______, 	_______,        
		_______,   		_______, 	_______, 	_______, 	_______, 	_______, 	_______,
        _______,  		KC_A, 		KC_S, 		KC_D, 		KC_F, 		KC_G, 		_______,
        KC_LSFT,  		_______, 	_______, 	_______, 	_______, 	_______,
        KC_LCTL,  KC_LALT, _______, _______,
										_______,  	_______,
										TG(_GAMER), _______,
										_______,   	KC_ESC,
        // right hand	
                          _______, 	_______,	_______,    _______, _______,  	_______,  	WHAT_A_SAVE,
                          _______,	_______,    _______,    _______, _______,   _______,	_______,
						  _______, 	_______,  	_______,  	_______, _______, 	_______,	_______,
									_______,    _______,    _______, _______,	_______,	KC_RSFT,
															_______, _______, 	_______, 	_______,
             _______, _______,
             _______, _______,
             _______, _______
    ),
};
