// Board pin maps. Pick the board with a build flag (see platformio.ini):
//   (default)            Guition JC3636K718  - LED ring, DRV2605 ERM, PCM5100A on the S3
//   -DBOARD_JC3636K518   Guition JC3636K518C / Waveshare ESP32-S3-Knob-Touch-LCD-1.8
#pragma once

#define LCD_W 360
#define LCD_H 360

#if defined(BOARD_JC3636K518)
// ---------------------------------------------------------------- JC3636K518C
// Pins from the Waveshare/Guition community configs (lcdwizard preset,
// KrX3D WaveShare-Knob-Esp32S3, HA forum JC3636K518C-I-YR thread).
#define BOARD_NAME "JC3636K518"

// ST77916 QSPI panel
#define PIN_LCD_SCK 13
#define PIN_LCD_CS 14
#define PIN_LCD_D0 15
#define PIN_LCD_D1 16
#define PIN_LCD_D2 17
#define PIN_LCD_D3 18
#define PIN_LCD_RST 21
#define PIN_LCD_BL 47

// CST816S touch (I2C 0x15); the DRV2605 haptic shares this bus
#define PIN_TP_SDA 11
#define PIN_TP_SCL 12
#define PIN_TP_INT 9
#define PIN_TP_RST 10

// Knob: same two-pin pulse scheme as the K718, on different pins.
// GPIO8 = clockwise, GPIO7 = anticlockwise. No push switch.
#define PIN_KNOB_CW 8
#define PIN_KNOB_CCW 7

// PCM5100A I2S DAC. Its mute line and the headphone/speaker switch belong to
// the board's second chip (ESP32-U4WDH), so there's no mute pin here.
#define PIN_I2S_BCK 39
#define PIN_I2S_WS 40
#define PIN_I2S_DO 41
#define PIN_DAC_MUTE -1

// No LED ring on this board.
#define PIN_LED_RING -1
#define LED_RING_COUNT 0

// Battery: ADC1_CH0 behind a 2:1 divider.
#define PIN_BAT_ADC 1
#define BAT_DIVIDER 2.0f

// DRV2605 drives an LRA here (ERM on the K718).
#define HAPTIC_LRA 1

#else
// ---------------------------------------------------------------- JC3636K718
// Guition JC3636K718 pin map (from the manufacturer demo pincfg.h).
#define BOARD_NAME "JC3636K718"

// ST77916 QSPI panel
#define PIN_LCD_SCK 11
#define PIN_LCD_CS 12
#define PIN_LCD_D0 13
#define PIN_LCD_D1 14
#define PIN_LCD_D2 15
#define PIN_LCD_D3 16
#define PIN_LCD_RST 17
#define PIN_LCD_BL 21

// CST816 touch (I2C)
#define PIN_TP_SDA 9
#define PIN_TP_SCL 10
#define PIN_TP_INT 7
#define PIN_TP_RST 8

// Knob: not quadrature. Each detent pulses one pin LOW:
// GPIO1 = clockwise (right), GPIO2 = anticlockwise (left).
#define PIN_KNOB_CW 1
#define PIN_KNOB_CCW 2

// PCM5100A I2S DAC (for the audio phase)
#define PIN_I2S_BCK 3
#define PIN_I2S_WS 45
#define PIN_I2S_DO 42
#define PIN_DAC_MUTE 46  // LOW = mute

// WS2812 ring, 13 LEDs, GRB (GPIO0 is also the BOOT strap)
#define PIN_LED_RING 0
#define LED_RING_COUNT 13

// Battery ADC behind a 2:1 divider.
#define PIN_BAT_ADC 6
#define BAT_DIVIDER 2.0f

#define HAPTIC_LRA 0
#endif
