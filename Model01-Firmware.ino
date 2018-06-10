// -*- mode: c++ -*-
// Copyright 2016 Keyboardio, inc. <jesse@keyboard.io>
// Copyright 2018 Les Aker <me@lesaker.org>
// See "LICENSE" for license details

#ifndef BUILD_INFORMATION
#define BUILD_INFORMATION "locally built"
#endif

#include "Kaleidoscope.h"

// Keymap Layers
enum { QWERTY, FUNCTION };

// *INDENT-OFF*
KEYMAPS(

  [QWERTY] = KEYMAP_STACKED
  (___,                  Key_1,                 Key_2,                 Key_3,                 Key_4,                 Key_5,                 ___,
  Key_Backtick,          Key_Q,                 Key_W,                 Key_E,                 Key_R,                 Key_T,                 Key_Tab,
  Key_PageUp,            Key_A,                 Key_S,                 Key_D,                 Key_F,                 Key_G,
  Key_PageDown,          Key_Z,                 Key_X,                 Key_C,                 Key_V,                 Key_B,                 Key_Escape,
  Key_LeftControl,       Key_Backspace,         Key_LeftGui,           Key_LeftShift,
  ShiftToLayer(FUNCTION),

  ___,                   Key_6,                 Key_7,                 Key_8,                 Key_9,                 Key_0,                 ___,
  Key_Enter,             Key_Y,                 Key_U,                 Key_I,                 Key_O,                 Key_P,                 Key_Equals,
  /*blank*/              Key_H,                 Key_J,                 Key_K,                 Key_L,                 Key_Semicolon,         Key_Quote,
  ___,                   Key_N,                 Key_M,                 Key_Comma,             Key_Period,            Key_Slash,             Key_Minus,
  Key_RightShift,        Key_LeftAlt,           Key_Spacebar,          Key_RightControl,
  ShiftToLayer(FUNCTION)),

  [FUNCTION] =  KEYMAP_STACKED
  (___,                  Key_F1,                Key_F2,                Key_F3,                Key_F4,                Key_F5,                ___,
  ___,                   ___,                   ___,                   ___,                   ___,                   ___,                   ___,
  Key_Home,              ___,                   ___,                   ___,                   ___,                   ___,
  Key_End,               ___,                   ___,                   ___,                   ___,                   ___,                   ___,
  ___,                   Key_Delete,            ___,                   ___,
  ___,

  ___,                   Key_F6,                Key_F7,                Key_F8,                Key_F9,                Key_F10,               Key_F11,
  ___,                   ___,                   Key_LeftCurlyBracket,  Key_RightCurlyBracket, Key_LeftBracket,       Key_RightBracket,      Key_F12,
  /*blank*/              Key_LeftArrow,         Key_DownArrow,         Key_UpArrow,           Key_RightArrow,        ___,                   ___,
  ___,                   ___,                   ___,                   ___,                   ___,                   Key_Backslash,         Key_Pipe,
  ___,                   ___,                   Key_Enter,             ___,
  ___)
) // KEYMAPS
// *INDENT-ON*

void setup() {
  Kaleidoscope.setup();
}

void loop() {
  Kaleidoscope.loop();
}
