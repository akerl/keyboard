// -*- mode: c++ -*-
// Copyright 2016 Keyboardio, inc. <jesse@keyboard.io>
// Copyright 2021 Les Aker <me@lesaker.org>
// See "LICENSE" for license details

#ifndef BUILD_INFORMATION
#define BUILD_INFORMATION "locally built on " __DATE__ " at " __TIME__
#endif

#include "Kaleidoscope.h"
#include "Kaleidoscope-HostPowerManagement.h"
#include "Kaleidoscope-Macros.h"
#include "Kaleidoscope-HardwareTestMode.h"
#include "Kaleidoscope-USB-Quirks.h"
#include "Kaleidoscope-MagicCombo.h"
#include "Kaleidoscope-LEDControl.h"
#include "Kaleidoscope-LEDEffect-SolidColor.h"

// Keymap Layers
enum { QWERTY, FUNCTION };

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
) // KEYMAPS
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

enum {
  COMBO_TOGGLE_NKRO_MODE,
  COMBO_ENTER_TEST_MODE
};

static void toggleKeyboardProtocol(uint8_t combo_index) {
  USBQuirks.toggleKeyboardProtocol();
}

static void enterHardwareTestMode(uint8_t combo_index) {
  HardwareTestMode.runTests();
}


USE_MAGIC_COMBOS(
  {
    .action = toggleKeyboardProtocol,
    // Left Fn + Esc + Shift
    .keys = { R3C6, R2C6, R3C7 }
  },
  {
    .action = enterHardwareTestMode,
    // Left Fn + Prog + LED
    .keys = { R3C6, R0C0, R0C6 }
  }
);

KALEIDOSCOPE_INIT_PLUGINS(
  HardwareTestMode,
  LEDControl,
  LEDOff,
  solidBlue,
  Macros,
  HostPowerManagement,
  MagicCombo,
  USBQuirks
);

void setup() {
  Kaleidoscope.setup();
  HardwareTestMode.setActionKey(R3C6);
  LEDOff.activate();
}

void loop() {
  Kaleidoscope.loop();
}
