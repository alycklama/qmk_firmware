/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR
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

#define FIRMWARE_VERSION u8"6RaDq/xOZxK"
#define RAW_USAGE_PAGE 0xFF60
#define RAW_USAGE_ID 0x61
#define LAYER_STATE_8BIT
#define COMBO_COUNT 1

#define RGB_MATRIX_STARTUP_SPD 30
#define RGB_MATRIX_TIMEOUT 300000 // number of milliseconds to wait until RGB automatically turns off
