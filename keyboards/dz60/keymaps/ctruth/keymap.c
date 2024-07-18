#include QMK_KEYBOARD_H

/* LAYERS */
#define BASE 0
#define HHKB 1
#define VIM  2
#define GAME 3
#define PLYR 4
#define MOUS 5
#define NONE 7


/* FN KEYS */
#define HHKB_FN MO(HHKB)
#define VIM_FN LT(VIM, KC_SPC)
#define LSFT_FN MO(VIM)
#define MOUS_FN LT(MOUS, KC_SPC)

const char* gp =
{
#include "gp.glsl"
};

const char* tp =
{
#include "tp.glsl"
};

enum custom_keycodes {
  WIN_SWP = SAFE_RANGE,
  DEL_W,
	FOR_W,
	BCK_W,
  S_GP,
  S_TP
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT(
        QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,
				KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        LSFT_FN, KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, HHKB_FN,
        KC_LCTL, KC_LALT, KC_LGUI,          KC_SPC,  MOUS_FN,        KC_SPC,             KC_RGUI, KC_RALT, KC_RCTL, KC_RCTL, HHKB_FN
    ),

    [HHKB] = LAYOUT(
        KC_SLEP,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, WIN_SWP, KC_DEL,
        KC_CAPS, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______, _______, _______, KC_HOME, KC_UP  ,  KC_END, _______,
        _______, _______, KC_VOLD, KC_MUTE, KC_VOLU, _______, _______, _______, KC_BRIU, KC_PGUP, KC_LEFT, KC_RGHT,          KC_TRNS,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BRID, KC_PGDN, KC_DOWN, _______, KC_TRNS,
        _______, _______, _______,          _______, _______,          _______,          _______, _______, _______, _______, _______
    ),

    [VIM] = LAYOUT(
        KC_GRV , _______, _______, _______, KC_END , _______, KC_HOME, _______, _______, _______, _______, _______, _______, _______, _______,
        KC_TAB , _______, DEL_W  , FOR_W  , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        KC_TRNS, _______, _______, KC_DEL , KC_BSPC, _______, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, _______,          KC_ENT ,
        KC_TRNS, KC_TRNS, _______, _______, _______, _______, BCK_W  , _______, _______, _______, _______, _______, KC_TRNS, KC_TRNS,
        KC_LCTL, KC_LALT, KC_LGUI,          _______, _______,          _______,          KC_RGUI, _______, KC_RCTL, KC_RCTL, _______
    ),

    [GAME] = LAYOUT(
        _______,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        KC_TRNS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_ENT ,
        KC_TRNS, KC_TRNS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_TRNS, KC_TRNS,
        KC_LCTL, KC_LALT, KC_LGUI,          _______, _______,          KC_SPC ,          KC_RGUI, KC_RALT, KC_RCTL, KC_RCTL, _______
    ),

    [MOUS] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, KC_BTN2, KC_MS_U, KC_BTN1, _______, _______, KC_BTN1, KC_MS_U, KC_BTN2, _______, _______, _______, _______,
        _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,          _______, _______,          _______,          _______, _______, _______, _______, _______
    ),

    [PLYR] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, S_TP   , _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, S_GP   , _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,          _______, _______,          _______,          _______, _______, _______, _______, _______
    ),

    [NONE] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,          _______, _______,          _______,          _______, _______, _______, _______, _______
    )
};

static bool lgui_down = false;
static bool rgui_down = false;
static bool lalt_down = false;
static bool ralt_down = false;
static bool rsft_down = false;
static bool lsft_down = false;
static bool ctrl_down = false;
static bool fn_down   = false;
static bool vfn_down  = false;
static bool lsfn_down = false;
static bool spc_down  = false;
static bool win_swap  = false;

// Function Pointers to conditionally use macros
uint16_t l_alt_macro(uint16_t kc) 
{
	return LALT(kc);
}
uint16_t l_ctl_macro(uint16_t kc) 
{
	return LCTL(kc);
}
bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
		uint16_t (*mod_func)(uint16_t) = NULL;
		uint16_t key        = keycode,
						 lgui_key   = win_swap ? KC_LALT : KC_LGUI,
             lalt_key   = win_swap ? KC_LGUI : KC_LALT,
             ralt_key   = win_swap ? KC_RCTL : KC_RALT;

    switch (keycode)
    {
    case KC_SPC:
        if (record->event.pressed)
        {
            if (ctrl_down && !fn_down)
            {
                unregister_code(KC_LCTL);
                layer_on(VIM);
            }
            else
            {
                register_code(key);
            }
						spc_down = true;
        }
        else
        {
						unregister_code(key);
            layer_off(VIM);
						spc_down = false;
            if (ctrl_down)
            {
                register_code(KC_LCTL);
            }

            if (fn_down)
            {
                layer_on(HHKB);
            }

        }

        return false;
        break;
    case VIM_FN:
        if (record->event.pressed)
        {
						vfn_down = true;
            if (ctrl_down && !fn_down)
            {
                unregister_code(KC_LCTL);
                layer_on(VIM);
            }
        }
        else
        {
            layer_off(VIM);
						vfn_down = false;
            if (ctrl_down)
            {
                register_code(KC_LCTL);
            }

            if (fn_down)
            {
                layer_on(HHKB);
            }

        }

        break;
    case KC_LCTL:
        if (record->event.pressed)
        {
            /* Look into making this a bit less redundant */
            ctrl_down = true;
            if (spc_down || lgui_down || vfn_down)
            {
                if (!fn_down)
                {
                    if (spc_down)
                    {
                        unregister_code(KC_SPC);
                        layer_on(VIM);
                    }
                    if (vfn_down)
                    {
                        layer_off(VIM);
                        layer_on(GAME);
                    }
                    if (lgui_down)
                    {
                        unregister_code(lgui_key);
                        layer_on(GAME);
                    }
                }
                else
                {
                    register_code(key);
                }
            }
            else
            {
                register_code(key);
            }
        }
        else
        {
            ctrl_down = false;
            unregister_code(key);
            layer_off(VIM);
            layer_off(GAME);

						if (spc_down)
						{
							unregister_code(KC_SPC);
						}
            if (lgui_down)
            {
							register_code(lgui_key);
            }
						if (fn_down)
						{
							layer_on(HHKB);
						}
        }

        return false;
        break;
		/* Layer 3 with Gui + Ctrl */
		case KC_LGUI:
				key = lgui_key;
				if (record->event.pressed)
				{
						lgui_down = true;
            if (ctrl_down && !fn_down)
            {
                unregister_code(KC_LCTL);
                layer_on(GAME);
            }
            else
            {
                register_code(key);
            }
				}
				else
				{
						/* Alt x Gui Swap */
						unregister_code(key);
            layer_off(GAME);
						lgui_down = false;
            if (ctrl_down)
            {
                register_code(KC_LCTL);
            }

            if (fn_down)
            {
                layer_on(HHKB);
            }
				}

        return false;
        break;
		case KC_RGUI:
				if (record->event.pressed)
				{
            register_code(key);
            rgui_down = true;
				}
				else
				{
            unregister_code(key);
            rgui_down = true;
				}

        break;
    case LSFT_FN:
        if (record->event.pressed)
        {
          lsfn_down = true;
        }
        else
        {
          lsfn_down = false;
					if (!lsft_down) {
						unregister_code(KC_LSFT);
					}
        }

        break;
		case KC_LSFT:
				if (record->event.pressed)
				{
            register_code(key);
						if (!lsfn_down) {
							lsft_down = true;
						}
				}
				else
				{
            unregister_code(key);
						lsft_down = false;
				}

        break;
		case KC_RSFT:
				if (record->event.pressed)
				{
            register_code(key);
						rsft_down = true;
				}
				else
				{
            unregister_code(key);
						rsft_down = false;
				}

        break;
    case KC_LALT:
				/* Alt x Gui Swap */
				key = lalt_key;
        if (record->event.pressed)
        {
						register_code(key);
						lalt_down = true;
        }
        else
        {
						unregister_code(key);
						lalt_down = false;
        }

        return false;
        break;
		/* End Layer 2 with Gui + Ctrl */
		case KC_RALT:
				key = ralt_key;
				if (record->event.pressed)
				{
            register_code(key);
            ralt_down = true;
				}
				else
				{
            unregister_code(key);
            ralt_down = false;
				}

        return false;
        break;
    case KC_TAB:
        if (record->event.pressed)
        {
          if (lsfn_down)
          {
            register_code(KC_LSFT);
          }
          else
          {
            if (!lsft_down)
            {
              unregister_code(KC_LSFT);
            }
          }
        }
        else
        {
          if (lsfn_down && !lsft_down)
          {
            unregister_code(KC_LSFT);
          }
        }

        break;
    case KC_GRV:
    case QK_GESC:
        if (record->event.pressed)
        {
          if (lsfn_down)
          {
            register_code(KC_LSFT);
          }
          else
          {
            if (!lsft_down)
            {
              unregister_code(KC_LSFT);
            }
          }
        }
        else
        {
          if (lsfn_down && !lsft_down)
          {
            unregister_code(KC_LSFT);
          }
        }

        break;
		case HHKB_FN:
				if (record->event.pressed)
				{
						fn_down = true;
						if (spc_down && ctrl_down)
						{
								register_code(KC_SPC);
								register_code(KC_LCTL);
								layer_on(BASE);
						}
						else
						{
								layer_on(HHKB);
						}
				}
				else
				{
					fn_down = false;
					if (spc_down && ctrl_down)
					{
							unregister_code(KC_SPC);
							unregister_code(KC_LCTL);
							layer_on(VIM);
					}
					else
					{
							layer_off(HHKB);
					}
				}

        return false;
				break;
    case DEL_W:
    case FOR_W:
    case BCK_W:
				mod_func = win_swap ? l_ctl_macro : l_alt_macro;
				uint16_t action = KC_NO;
				switch (key) 
				{
					case DEL_W:
						action = KC_BSPC;
						break;
					case FOR_W:
						action = KC_RGHT;
						break;
					case BCK_W:
						action = KC_LEFT;
						break;
				}
        if (record->event.pressed)
        {
					register_code16(mod_func(action));
        }
        else
        {
					unregister_code16(mod_func(action));
        }

        return false;
        break;
		case WIN_SWP:
				if (record->event.pressed)
				{
						win_swap = !win_swap;
				}

				return false;
				break;
    case S_GP:
      if (record->event.pressed)
      {
        send_string(gp);
      }

      return false;
      break;

      case S_TP:
        if (record->event.pressed)
        {
          send_string(tp);
        }

        return false;
        break;
    }

    return true;
};

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
		uint16_t lgui_key   = win_swap ? KC_LALT : KC_LGUI;

    if (lsft_down && rsft_down && lgui_down && rgui_down)
    {
        if (record->event.pressed)
        {
            unregister_code(KC_LSFT);
            unregister_code(KC_RSFT);
            unregister_code(lgui_key);
            unregister_code(KC_RGUI);
            layer_on(PLYR);
        }
    }
    else
    {
        if (!record->event.pressed)
        {
            layer_off(PLYR);
        }
    }
}

