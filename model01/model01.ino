// -*- mode: c++ -*-
// Copyright 2016 Keyboardio, inc. <jesse@keyboard.io>
// Copyright 2022 Les Aker <me@lesaker.org>
// See "LICENSE" for license details

#ifndef BUILD_INFORMATION
#define BUILD_INFORMATION "locally built on " __DATE__ " at " __TIME__
#endif

#include "Kaleidoscope.h"
#include "Kaleidoscope-HostPowerManagement.h"
#include <Kaleidoscope-IdleLEDs.h>
#include "Kaleidoscope-LEDControl.h"
#include "Kaleidoscope-LEDEffect-SolidColor.h"
#include <Kaleidoscope-SpaceCadet.h>


enum { QWERTY, FUNCTION }; // layers

// *INDENT-OFF*

KEYMAPS(

  [QWERTY] = KEYMAP_STACKED
  (___,                       Key_1,                      Key_2,                      Key_3,                      Key_4,                      Key_5,                      Key_LEDEffectNext,
  Key_Backtick,               Key_Q,                      Key_W,                      Key_E,                      Key_R,                      Key_T,                      Key_Tab,
  Key_PageUp,                 Key_A,                      Key_S,                      Key_D,                      Key_F,                      Key_G,
  Key_PageDown,               Key_Z,                      Key_X,                      Key_C,                      Key_V,                      Key_B,                      Key_Escape,
  Key_LeftControl,            Key_Backspace,              Key_LeftGui,                Key_LeftShift,
  ShiftToLayer(FUNCTION),

  ___,                        Key_6,                      Key_7,                      Key_8,                      Key_9,                      Key_0,                      ___,
  Key_Enter,                  Key_Y,                      Key_U,                      Key_I,                      Key_O,                      Key_P,                      Key_Equals,
  /*blank*/                   Key_H,                      Key_J,                      Key_K,                      Key_L,                      Key_Semicolon,              Key_Quote,
  ___,                        Key_N,                      Key_M,                      Key_Comma,                  Key_Period,                 Key_Slash,                  Key_Minus,
  Key_RightShift,             Key_LeftAlt,                Key_Spacebar,               Key_RightControl,
  ShiftToLayer(FUNCTION)),

  [FUNCTION] =  KEYMAP_STACKED
  (___,                       Key_F1,                     Key_F2,                     Key_F3,                     Key_F4,                     Key_F5,                     ___,
  ___,                        ___,                        Key_Mute,                   Consumer_VolumeDecrement,   Consumer_VolumeIncrement,   Consumer_ScanNextTrack,     ___,
  Key_Home,                   ___,                        ___,                        ___,                        ___,                        Consumer_PlaySlashPause,
  Key_End,                    ___,                        ___,                        ___,                        ___,                        Consumer_ScanPreviousTrack, ___,
  ___,                        Key_Delete,                 ___,                        ___,
  ___,

  ___,                        Key_F6,                     Key_F7,                     Key_F8,                     Key_F9,                     Key_F10,                    Key_F11,
  ___,                        ___,                        Key_LeftCurlyBracket,       Key_RightCurlyBracket,      Key_LeftBracket,            Key_RightBracket,           Key_F12,
  /*blank*/                   Key_LeftArrow,              Key_DownArrow,              Key_UpArrow,                Key_RightArrow,             ___,                        ___,
  ___,                        ___,                        ___,                        ___,                        ___,                        Key_Backslash,              Key_Pipe,
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
  SpaceCadet
);

void setup() {
  Kaleidoscope.setup();
  IdleLEDs.setIdleTimeoutSeconds(10000)

  static kaleidoscope::plugin::SpaceCadet::KeyBinding spacecadetmap[] = {
    {Key_LeftShift, Key_LeftParen, 250}
    , {Key_RightShift, Key_RightParen, 250}
    , {Key_LeftGui, Key_LeftCurlyBracket, 250}
    , {Key_RightAlt, Key_RightCurlyBracket, 250}
    , {Key_LeftControl, Key_LeftBracket, 250}
    , {Key_RightControl, Key_RightBracket, 250}
    , SPACECADET_MAP_END
  };
  SpaceCadet.setMap(spacecadetmap);
}

void loop() {
  Kaleidoscope.loop();
}
