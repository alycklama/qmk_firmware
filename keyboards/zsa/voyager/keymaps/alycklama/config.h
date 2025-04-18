/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/

#define CHORDAL_HOLD
#define RETRO_TAPPING

#undef TAPPING_TERM
#define TAPPING_TERM 150

#define PERMISSIVE_HOLD

#define USB_SUSPEND_WAKEUP_DELAY 0
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY 100

#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED 5

#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX 30

#undef MOUSEKEY_WHEEL_MAX_SPEED
#define MOUSEKEY_WHEEL_MAX_SPEED 5

#undef MOUSEKEY_WHEEL_TIME_TO_MAX
#define MOUSEKEY_WHEEL_TIME_TO_MAX 20

#define SERIAL_NUMBER "6RaDq/Wv4zMl"
#define LAYER_STATE_8BIT
#define COMBO_COUNT 1

#define RGB_MATRIX_STARTUP_SPD 30
#define RGB_MATRIX_TIMEOUT 300000 // number of milliseconds to wait until RGB automatically turns off

#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 250
