/*  -*-  eval: (turn-on-orgtbl); -*-
 * default HHKB Layout
 */
#include QMK_KEYBOARD_H

#define HHKB_FN MO(1)

const char* a =
{
#include "gp.glsl"
};

enum custom_keycodes {
  DEL_W = SAFE_RANGE,
  WIN_SWP,
  S_GP
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	/* Layer 0: Fn0 Default Layer
	 * ,--------------------------------------------------------------------------.
	 * |Esc |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 |  0 |  - |  = |  \ |  ` |
	 * |--------------------------------------------------------------------------|
	 * |Tab   |  Q |  W |  E |  R |  T |  Y |  U |  I |  O |  P |  [ |  ] | Backs |
	 * |--------------------------------------------------------------------------|
	 * |Ctrl   |  A |  S |  D |  F |  G |  H |  J |  K |  L |  ; |  ' |   Enter   |
	 * |--------------------------------------------------------------------------|
	 * |Shift    |  Z |  X |  C |  V |  B |  N |  M |  , |  . |  / |  Shift  |Fn1 |
	 * `--------------------------------------------------------------------------'
	 *       | Alt|   Gui  |             Space            |  Gui  |Alt |
	 *       `---------------------------------------------------------'
	 */
	[0] = LAYOUT_60_hhkb(
			KC_GESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , KC_BSLS, KC_GRV,
			KC_TAB   , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC,   KC_BSPC   ,
			KC_LCTL   , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,			KC_ENT			,
			KC_LSFT    , KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH,     KC_RSFT    , HHKB_FN ,
							 KC_LALT , KC_LGUI     ,														KC_SPC																	, KC_RGUI  , KC_RALT
	),
	/* Layer 1: HHKB Function Layer
	 * ,--------------------------------------------------------------------------.
	 * |PWR | F1 | F2 | F3 | F4 | F5 | F6 | F7 | F8 | F9 |F10 |F11 |F12 |Togl|DEL |
	 * |--------------------------------------------------------------------------|
	 * |Caps  |    |Prev|Play|Next|    |    |    |    |    |PgUp| Up |PgDn|       |
	 * |--------------------------------------------------------------------------|
	 * |       |    |VolD|Mute|VolU|    |  * |  / |BrUp|Home|Left|Rght|   Enter   |
	 * |--------------------------------------------------------------------------|
	 * |         |LTog|LMod|LMod|BTog|BStp|  + |  - |BrDn| End|Down|         |    |
	 * `--------------------------------------------------------------------------'
	 *       | Alt|   Gui  |             Space            |  Gui  |Alt |
	 *       `---------------------------------------------------------'
	 */
	[1] = LAYOUT_60_hhkb(
			KC_PWR  , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , WIN_SWP, KC_DEL,
			KC_CAPS  , KC_TRNS, KC_MPRV, KC_MPLY, KC_MNXT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_UP  , KC_END ,   KC_TRNS   ,
			KC_TRNS   , KC_TRNS, KC_VOLD, KC_MUTE, KC_VOLU, KC_TRNS, KC_PAST, KC_PSLS, KC_BRIU, KC_PGUP, KC_LEFT, KC_RGHT,   KC_PENT        ,
			KC_TRNS    , RGB_TOG, RGB_MOD, RGB_RMOD, BL_TOGG, BL_STEP, KC_PPLS, KC_PMNS, KC_BRID , KC_PGDN, KC_DOWN,  KC_TRNS      , KC_TRNS ,
							 KC_TRNS , KC_TRNS     ,														KC_TRNS																	, KC_TRNS  , KC_TRNS
	),
	/* Layer 2: CTRL + Space Function Layer
	 * ,--------------------------------------------------------------------------.
	 * |    |    |    |    | End |    | Home|    |    |    |    |    |    |    |    |
	 * |--------------------------------------------------------------------------|
	 * |Tab   |    |    |    |    |    |    |    |    |    |    |    |    |       |
	 * |--------------------------------------------------------------------------|
	 * |       |    |    |    |    |    |    |Rght|Down| Up |Left|    |   Enter   |
	 * |--------------------------------------------------------------------------|
	 * |         |    |    |    |    |    |    |    |    |    |    |         |    |
	 * `--------------------------------------------------------------------------'
	 *       | Alt|   Gui  |             Space            |  Gui  |Alt |
	 *       `---------------------------------------------------------'
	 */
	[2] = LAYOUT_60_hhkb(
			KC_NO   , KC_NO  , KC_NO  , KC_NO  , KC_END , KC_NO  , KC_HOME, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO ,
			KC_TAB   , KC_NO  , DEL_W  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,   KC_NO     ,
			KC_TRNS   , KC_NO  , KC_NO  , KC_DEL , KC_BSPC, KC_NO  , KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_NO  , KC_NO  ,   KC_ENT         ,
			KC_TRNS    , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   , KC_NO  , KC_NO  ,  KC_NO        , KC_TRNS ,
							 KC_TRNS , KC_TRNS     ,														KC_TRNS																	, KC_TRNS  , KC_TRNS
	),
	/* Layer 3: Extra Function Layer
	 * ,--------------------------------------------------------------------------.
	 * |    | F1 | F2 | F3 | F4 | F5 | F6 | F7 | F8 | F9 |F10 |F11 |F12 |    |    |
	 * |--------------------------------------------------------------------------|
	 * |      |    |    |    |    |    |    |    |    |    |    |    |    |       |
	 * |--------------------------------------------------------------------------|
	 * |       |    |    |    |    |    |    |    |    |    |    |    |           |
	 * |--------------------------------------------------------------------------|
	 * |         |    |    |    |    |    |    |    |    |    |    |         |    |
	 * `--------------------------------------------------------------------------'
	 *       |    |        |                              |       |    |
	 *       `---------------------------------------------------------'
	 */
  [3] = LAYOUT_60_hhkb(
			KC_NO   , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_NO  , KC_NO ,
			KC_NO    , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,   KC_NO     ,
			KC_NO     , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,   KC_NO          ,
			KC_NO      , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   , KC_NO  , KC_NO  ,  KC_NO        , KC_NO   ,
							 KC_NO   , KC_NO       ,														KC_NO  																	, KC_NO    , KC_NO

  ),
	/* Layer 32: Extra Function Layer
	 * ,--------------------------------------------------------------------------.
	 * |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
	 * |--------------------------------------------------------------------------|
	 * |      |    |    |    |    |    |    |    |    |    |    |    |    |       |
	 * |--------------------------------------------------------------------------|
	 * |       |    |    |    |    | GP |    |    |    |    |    |    |           |
	 * |--------------------------------------------------------------------------|
	 * |         |    |    |    |    |    |    |    |    |    |    |         |    |
	 * `--------------------------------------------------------------------------'
	 *       |    |        |                              |       |    |
	 *       `---------------------------------------------------------'
	 */
  [4] = LAYOUT_60_hhkb(
			KC_NO   , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO ,
			KC_NO    , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,   KC_NO     ,
			KC_NO     , KC_NO  , KC_NO  , KC_NO  , KC_NO  , S_GP   , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,   KC_NO          ,
			KC_NO      , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   , KC_NO  , KC_NO  ,  KC_NO        , KC_NO   ,
							 KC_NO   , KC_NO       ,														KC_NO  																	, KC_NO    , KC_NO

  )
};

static bool lgui_down = false;
static bool rgui_down = false;
static bool lalt_down = false;
static bool ralt_down = false;
static bool rsft_down = false;
static bool lsft_down = false;
static bool ctrl_down = false;
static bool fn_down = false;
static bool spc_down = false;
static bool win_swap = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
		uint16_t key        = keycode,
						 lgui_key   = win_swap ? KC_LALT : KC_LGUI,
             lalt_key   = win_swap ? KC_LGUI : KC_LALT,
             ralt_key   = win_swap ? KC_RCTRL : KC_RALT;

    switch (keycode)
    {
    case KC_SPC:
        if (record->event.pressed)
        {
            if (ctrl_down && !fn_down)
            {
                unregister_code(KC_LCTRL);
                layer_on(2);
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
            layer_off(2);
						spc_down = false;
            if (ctrl_down)
            {
                register_code(KC_LCTRL);
            }

            if (fn_down)
            {
                layer_on(1);
            }

        }

        return false;
        break;
    case KC_LCTRL:
        if (record->event.pressed)
        {
            /* Look into making this a bit less redundant */
            ctrl_down = true;
            if (spc_down || lgui_down)
            {
                if (!fn_down)
                {
                    if (spc_down)
                    {
                        unregister_code(KC_SPC);
                        layer_on(2);
                    }
                    if (lgui_down)
                    {
                        unregister_code(lgui_key);
                        layer_on(3);
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
            layer_off(2);
            layer_off(3);

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
							layer_on(1);
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
                unregister_code(KC_LCTRL);
                layer_on(3);
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
            layer_off(3);
						lgui_down = false;
            if (ctrl_down)
            {
                register_code(KC_LCTRL);
            }

            if (fn_down)
            {
                layer_on(1);
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
		case KC_LSFT:
				if (record->event.pressed)
				{
            register_code(key);
						lsft_down = true;
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

        break;
		case HHKB_FN:
				if (record->event.pressed)
				{
						fn_down = true;
						if (spc_down && ctrl_down)
						{
								register_code(KC_SPC);
								register_code(KC_LCTRL);
								layer_on(0);
						}
						else
						{
								layer_on(1);
						}
				}
				else
				{
					fn_down = false;
					if (spc_down && ctrl_down)
					{
							unregister_code(KC_SPC);
							unregister_code(KC_LCTRL);
							layer_on(2);
					}
					else
					{
							layer_off(1);
					}
				}

        return false;
				break;
    case DEL_W:
        if (record->event.pressed)
        {
            register_code16(A(KC_BSPC));
        }
        else
        {
            unregister_code16(A(KC_BSPC));
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
        send_string(a);
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
            layer_on(4);
        }
    }
    else
    {
        if (!record->event.pressed)
        {
            layer_off(4);
        }
    }
}

