#include QMK_KEYBOARD_H

#define HHKB_FN MO(1)

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
			KC_LSFT    , KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH,     KC_RSFT    , HHKB_FN   ,
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
			KC_PWR  , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_INS , KC_DEL,
			KC_CAPS  , KC_TRNS, KC_MPRV, KC_MPLY, KC_MNXT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGDN, KC_UP  , KC_PGUP,   KC_TRNS   ,
			KC_TRNS   , KC_TRNS, KC_VOLD, KC_MUTE, KC_VOLU, KC_TRNS, KC_PAST, KC_PSLS, KC_BRIU, KC_HOME, KC_LEFT, KC_RGHT,   KC_PENT        ,
			KC_TRNS    , RGB_TOG, RGB_MOD, RGB_RMOD, BL_TOGG, BL_STEP, KC_PPLS, KC_PMNS, KC_BRID , KC_END, KC_DOWN,  KC_TRNS      , KC_TRNS ,
							 KC_TRNS , KC_TRNS     ,														KC_TRNS																	, KC_TRNS  , KC_TRNS
	),
	/* Layer 2: HHKB Function Layer
	 * ,--------------------------------------------------------------------------.
	 * |PWR | F1 | F2 | F3 | F4 | F5 | F6 | F7 | F8 | F9 |F10 |F11 |F12 |    |    |
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
			KC_PWR  , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_NO  , KC_NO ,
			KC_TAB   , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,   KC_NO     ,
			KC_TRNS   , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_NO  , KC_NO  ,   KC_ENT         ,
			KC_TRNS    , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   , KC_NO  , KC_NO  ,  KC_NO        , KC_TRNS ,
							 KC_TRNS , KC_TRNS     ,														KC_TRNS																	, KC_TRNS  , KC_TRNS
	)
};

static bool gui_down = false;
static bool ctrl_down = false;
static bool fn_down = false;
static bool ag_swap = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
		uint16_t key,
						 gui_key = ag_swap ? KC_LALT : KC_LGUI;

    switch (keycode)
    {
		/* Layer 2 with Gui + Ctrl */
		case KC_LGUI:
				key = ag_swap ? KC_LALT : KC_LGUI;
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
						gui_down = true;
				}
				else
				{
						/* Alt x Gui Swap */
						unregister_code(key);
            layer_off(2);
						gui_down = false;
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
				key = KC_LCTRL;
        if (record->event.pressed)
        {
            if (gui_down && !fn_down)
            {
								unregister_code(gui_key);
                layer_on(2);
            }
            else
            {
                register_code(key);
            }
            ctrl_down = true;
        }
        else
        {
            layer_off(2);
            unregister_code(key);
            ctrl_down = false;

						if (gui_down)
						{
							register_code(gui_key);
						}
						if (fn_down)
						{
							layer_on(1);
						}
        }

        return false;
        break;
		/* End Layer 2 with Gui + Ctrl */
    case KC_LALT:
				/* Alt x Gui Swap */
				key = ag_swap ? KC_LGUI : KC_LALT;
        if (record->event.pressed)
        {
						register_code(key);
        }
        else
        {
						unregister_code(key);
        }

        return false;
        break;
		case KC_RALT:
				key = ag_swap ? KC_RCTRL : KC_RALT;
				if (record->event.pressed)
				{
					register_code(key);
				}
				else
				{
					unregister_code(key);
				}

        return false;
        break;
		case HHKB_FN:
				key = HHKB_FN;
				if (record->event.pressed)
				{
						fn_down = true;
						if (gui_down && ctrl_down)
						{
								register_code(gui_key);
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
					if (gui_down && ctrl_down)
					{
							unregister_code(gui_key);
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
		case KC_INS:
				if (record->event.pressed)
				{
						ag_swap = !ag_swap;
				}

				return false;
				break;
    }

    return true;
};

