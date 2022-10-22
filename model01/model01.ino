// -*- mode: c++ -*-
// Copyright 2016 Keyboardio, inc. <jesse@keyboard.io>
// Copyright 2022 Les Aker <me@lesaker.org>
// See "LICENSE" for license details

#ifndef BUILD_INFORMATION
#define BUILD_INFORMATION "locally built on " __DATE__ " at " __TIME__
#endif

#include <Kaleidoscope.h>
#include <Kaleidoscope-HostPowerManagement.h>
#include <Kaleidoscope-IdleLEDs.h>
#include <Kaleidoscope-LEDControl.h>
#include <Kaleidoscope-LEDEffect-SolidColor.h>
#include <Kaleidoscope-Qukeys.h>

enum { QWERTY, FUNCTION }; // layers

// *INDENT-OFF*

KEYMAPS(

  [QWERTY] = KEYMAP_STACKED
  (___,                       Key_1,                      Key_2,                      Key_3,                      Key_4,                      Key_5,                      ___,
  Key_Backtick,               Key_Q,                      Key_W,                      Key_E,                      Key_R,                      Key_T,                      Key_Tab,
  Key_PageUp,                 Key_A,                      Key_S,                      Key_D,                      Key_F,                      Key_G,
  Key_PageDown,               Key_Z,                      Key_X,                      Key_C,                      Key_V,                      Key_B,                      Key_Escape,
  Key_LeftControl,            Key_LeftAlt,                Key_LeftGui,                Key_LeftShift,
  ShiftToLayer(FUNCTION),

  ___,                        Key_6,                      Key_7,                      Key_8,                      Key_9,                      Key_0,                      ___,
  Key_Enter,                  Key_Y,                      Key_U,                      Key_I,                      Key_O,                      Key_P,                      Key_Equals,
  /*blank*/                   Key_H,                      Key_J,                      Key_K,                      Key_L,                      Key_Semicolon,              Key_Quote,
  ___,                        Key_N,                      Key_M,                      Key_Comma,                  Key_Period,                 Key_Slash,                  Key_Minus,
  Key_RightShift,             Key_RightAlt,               Key_RightGui,               Key_RightControl,
  ShiftToLayer(FUNCTION)),

  [FUNCTION] =  KEYMAP_STACKED
  (___,                       Key_F1,                     Key_F2,                     Key_F3,                     Key_F4,                     Key_F5,                     Key_LEDEffectNext,
  ___,                        ___,                        Key_Mute,                   Consumer_VolumeDecrement,   Consumer_VolumeIncrement,   Consumer_ScanNextTrack,     ___,
  Key_Home,                   ___,                        ___,                        ___,                        ___,                        Consumer_PlaySlashPause,
  Key_End,                    ___,                        ___,                        ___,                        ___,                        Consumer_ScanPreviousTrack, ___,
  ___,                        Key_Delete,                 ___,                        ___,
  ___,

  ___,                        Key_F6,                     Key_F7,                     Key_F8,                     Key_F9,                     Key_F10,                    Key_F11,
  ___,                        ___,                        ___,                        ___,                        ___,                        ___,                        Key_F12,
  /*blank*/                   Key_LeftArrow,              Key_DownArrow,              Key_UpArrow,                Key_RightArrow,             ___,                        ___,
  ___,                        ___,                        ___,                        ___,                        ___,                        ___,                        ___,
  ___,                        ___,                        ___,                        ___,
  ___)
) // KEYMAPS(
// *INDENT-ON*

void hostPowerManagementEventHandler(kaleidoscope::plugin::HostPowerManagement::Event event) {
  switch (event) {
  case kaleidoscope::plugin::HostPowerManagement::Suspend:
    LEDControl.disable();
    break;
  case kaleidoscope::plugin::HostPowerManagement::Resume:
    LEDControl.enable();
    break;
  case kaleidoscope::plugin::HostPowerManagement::Sleep:
    break;
  }
}

static kaleidoscope::plugin::LEDSolidColor solidBlue(0, 70, 130);

KALEIDOSCOPE_INIT_PLUGINS(
  LEDControl,
  IdleLEDs,
  solidBlue,
  LEDOff,
  HostPowerManagement,
  Qukeys
);

void setup() {
  Kaleidoscope.setup();
  IdleLEDs.setIdleTimeoutSeconds(60);

  QUKEYS(
    kaleidoscope::plugin::Qukey(0, KeyAddr(3, 6), Key_Backspace),
    kaleidoscope::plugin::Qukey(0, KeyAddr(3, 9), Key_Space),

    kaleidoscope::plugin::Qukey(0, KeyAddr(3, 7), Key_LeftBracket),
    kaleidoscope::plugin::Qukey(0, KeyAddr(3, 8), Key_RightBracket),

    kaleidoscope::plugin::Qukey(0, KeyAddr(2, 7), Key_KeypadLeftParen),
    kaleidoscope::plugin::Qukey(0, KeyAddr(2, 8), Key_KeypadRightParen),

    kaleidoscope::plugin::Qukey(0, KeyAddr(1, 7), Key_LeftCurlyBracket),
    kaleidoscope::plugin::Qukey(0, KeyAddr(1, 8), Key_RightCurlyBracket),

    kaleidoscope::plugin::Qukey(0, KeyAddr(0, 7), Key_Backslash),
    kaleidoscope::plugin::Qukey(0, KeyAddr(0, 8), Key_Pipe),
  )
}

void loop() {
  Kaleidoscope.loop();
}
