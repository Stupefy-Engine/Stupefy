/****************************************************************************/
/*  KeyCodes.h                                                              */
/****************************************************************************/
/*                          This file is a part of:                         */
/*                              STUPEFY ENGINE                              */
/*                                                                          */
/****************************************************************************/
/*  Copyright[2020] Harshit Bargujar                                        */
/*                                                                          */
/*  Licensed under the Apache License, Version 2.0 (the "License");         */
/*  you may not use this file except in compliance with the License.        */
/*  You may obtain a copy of the License at                                 */
/*                                                                          */
/*  http://www.apache.org/licenses/LICENSE-2.0                              */
/*                                                                          */
/*  Unless required by applicable law or agreed to in writing, software     */
/*  distributed under the License is distributed on an "AS IS" BASIS,       */
/*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.*/
/*  See the License for the specific language governing permissions and     */
/*  limitations under the License.                                          */
/****************************************************************************/


#pragma once

//namespace Stupefy
//{
//	typedef enum class KeyCode : uint16_t
//	{
//		Space = 32,
//		Apostrophe = 39, /* ' */
//		Comma = 44, /* , */
//		Minus = 45, /* - */
//		Period = 46, /* . */
//		Slash = 47, /* / */
//
//		D0 = 48, /* 0 */
//		D1 = 49, /* 1 */
//		D2 = 50, /* 2 */
//		D3 = 51, /* 3 */
//		D4 = 52, /* 4 */
//		D5 = 53, /* 5 */
//		D6 = 54, /* 6 */
//		D7 = 55, /* 7 */
//		D8 = 56, /* 8 */
//		D9 = 57, /* 9 */
//
//		Semicolon = 59, /* ; */
//		Equal = 61, /* = */
//
//		A = 65,
//		B = 66,
//		C = 67,
//		D = 68,
//		E = 69,
//		F = 70,
//		G = 71,
//		H = 72,
//		I = 73,
//		J = 74,
//		K = 75,
//		L = 76,
//		M = 77,
//		N = 78,
//		O = 79,
//		P = 80,
//		Q = 81,
//		R = 82,
//		S = 83,
//		T = 84,
//		U = 85,
//		V = 86,
//		W = 87,
//		X = 88,
//		Y = 89,
//		Z = 90,
//
//		LeftBracket = 91,  /* [ */
//		Backslash = 92,  /* \ */
//		RightBracket = 93,  /* ] */
//		GraveAccent = 96,  /* ` */
//
//		World1 = 161, /* non-US #1 */
//		World2 = 162, /* non-US #2 */
//
//		/* Function keys */
//		Escape = 256,
//		Enter = 257,
//		Tab = 258,
//		Backspace = 259,
//		Insert = 260,
//		Delete = 261,
//		Right = 262,
//		Left = 263,
//		Down = 264,
//		Up = 265,
//		PageUp = 266,
//		PageDown = 267,
//		Home = 268,
//		End = 269,
//		CapsLock = 280,
//		ScrollLock = 281,
//		NumLock = 282,
//		PrintScreen = 283,
//		Pause = 284,
//		F1 = 290,
//		F2 = 291,
//		F3 = 292,
//		F4 = 293,
//		F5 = 294,
//		F6 = 295,
//		F7 = 296,
//		F8 = 297,
//		F9 = 298,
//		F10 = 299,
//		F11 = 300,
//		F12 = 301,
//		F13 = 302,
//		F14 = 303,
//		F15 = 304,
//		F16 = 305,
//		F17 = 306,
//		F18 = 307,
//		F19 = 308,
//		F20 = 309,
//		F21 = 310,
//		F22 = 311,
//		F23 = 312,
//		F24 = 313,
//		F25 = 314,
//
//		/* Keypad */
//		KP0 = 320,
//		KP1 = 321,
//		KP2 = 322,
//		KP3 = 323,
//		KP4 = 324,
//		KP5 = 325,
//		KP6 = 326,
//		KP7 = 327,
//		KP8 = 328,
//		KP9 = 329,
//		KPDecimal = 330,
//		KPDivide = 331,
//		KPMultiply = 332,
//		KPSubtract = 333,
//		KPAdd = 334,
//		KPEnter = 335,
//		KPEqual = 336,
//
//		LeftShift = 340,
//		LeftControl = 341,
//		LeftAlt = 342,
//		LeftSuper = 343,
//		RightShift = 344,
//		RightControl = 345,
//		RightAlt = 346,
//		RightSuper = 347,
//		Menu = 348
//	}Key;
//
//	inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode)
//	{
//		os << static_cast<int32_t>(keyCode);
//		return os;
//	}
//}
//
//// From glfw3.h
//#define SF_KEY_SPACE           ::Stupefy::Key::Space
//#define SF_KEY_APOSTROPHE      ::Stupefy::Key::Apostrophe    /* ' */
//#define SF_KEY_COMMA           ::Stupefy::Key::Comma         /* , */
//#define SF_KEY_MINUS           ::Stupefy::Key::Minus         /* - */
//#define SF_KEY_PERIOD          ::Stupefy::Key::Period        /* . */
//#define SF_KEY_SLASH           ::Stupefy::Key::Slash         /* / */
//#define SF_KEY_0               ::Stupefy::Key::D0
//#define SF_KEY_1               ::Stupefy::Key::D1
//#define SF_KEY_2               ::Stupefy::Key::D2
//#define SF_KEY_3               ::Stupefy::Key::D3
//#define SF_KEY_4               ::Stupefy::Key::D4
//#define SF_KEY_5               ::Stupefy::Key::D5
//#define SF_KEY_6               ::Stupefy::Key::D6
//#define SF_KEY_7               ::Stupefy::Key::D7
//#define SF_KEY_8               ::Stupefy::Key::D8
//#define SF_KEY_9               ::Stupefy::Key::D9
//#define SF_KEY_SEMICOLON       ::Stupefy::Key::Semicolon     /* ; */
//#define SF_KEY_EQUAL           ::Stupefy::Key::Equal         /* = */
//#define SF_KEY_A               ::Stupefy::Key::A
//#define SF_KEY_B               ::Stupefy::Key::B
//#define SF_KEY_C               ::Stupefy::Key::C
//#define SF_KEY_D               ::Stupefy::Key::D
//#define SF_KEY_E               ::Stupefy::Key::E
//#define SF_KEY_F               ::Stupefy::Key::F
//#define SF_KEY_G               ::Stupefy::Key::G
//#define SF_KEY_H               ::Stupefy::Key::H
//#define SF_KEY_I               ::Stupefy::Key::I
//#define SF_KEY_J               ::Stupefy::Key::J
//#define SF_KEY_K               ::Stupefy::Key::K
//#define SF_KEY_L               ::Stupefy::Key::L
//#define SF_KEY_M               ::Stupefy::Key::M
//#define SF_KEY_N               ::Stupefy::Key::N
//#define SF_KEY_O               ::Stupefy::Key::O
//#define SF_KEY_P               ::Stupefy::Key::P
//#define SF_KEY_Q               ::Stupefy::Key::Q
//#define SF_KEY_R               ::Stupefy::Key::R
//#define SF_KEY_S               ::Stupefy::Key::S
//#define SF_KEY_T               ::Stupefy::Key::T
//#define SF_KEY_U               ::Stupefy::Key::U
//#define SF_KEY_V               ::Stupefy::Key::V
//#define SF_KEY_W               ::Stupefy::Key::W
//#define SF_KEY_X               ::Stupefy::Key::X
//#define SF_KEY_Y               ::Stupefy::Key::Y
//#define SF_KEY_Z               ::Stupefy::Key::Z
//#define SF_KEY_LEFT_BRACKET    ::Stupefy::Key::LeftBracket   /* [ */
//#define SF_KEY_BACKSLASH       ::Stupefy::Key::Backslash     /* \ */
//#define SF_KEY_RIGHT_BRACKET   ::Stupefy::Key::RightBracket  /* ] */
//#define SF_KEY_GRAVE_ACCENT    ::Stupefy::Key::GraveAccent   /* ` */
//#define SF_KEY_WORLD_1         ::Stupefy::Key::World1        /* non-US #1 */
//#define SF_KEY_WORLD_2         ::Stupefy::Key::World2        /* non-US #2 */
//
///* Function keys */
//#define SF_KEY_ESCAPE          ::Stupefy::Key::Escape
//#define SF_KEY_ENTER           ::Stupefy::Key::Enter
//#define SF_KEY_TAB             ::Stupefy::Key::Tab
//#define SF_KEY_BACKSPACE       ::Stupefy::Key::Backspace
//#define SF_KEY_INSERT          ::Stupefy::Key::Insert
//#define SF_KEY_DELETE          ::Stupefy::Key::Delete
//#define SF_KEY_RIGHT           ::Stupefy::Key::Right
//#define SF_KEY_LEFT            ::Stupefy::Key::Left
//#define SF_KEY_DOWN            ::Stupefy::Key::Down
//#define SF_KEY_UP              ::Stupefy::Key::Up
//#define SF_KEY_PAGE_UP         ::Stupefy::Key::PageUp
//#define SF_KEY_PAGE_DOWN       ::Stupefy::Key::PageDown
//#define SF_KEY_HOME            ::Stupefy::Key::Home
//#define SF_KEY_END             ::Stupefy::Key::End
//#define SF_KEY_CAPS_LOCK       ::Stupefy::Key::CapsLock
//#define SF_KEY_SCROLL_LOCK     ::Stupefy::Key::ScrollLock
//#define SF_KEY_NUM_LOCK        ::Stupefy::Key::NumLock
//#define SF_KEY_PRINT_SCREEN    ::Stupefy::Key::PrintScreen
//#define SF_KEY_PAUSE           ::Stupefy::Key::Pause
//#define SF_KEY_F1              ::Stupefy::Key::F1
//#define SF_KEY_F2              ::Stupefy::Key::F2
//#define SF_KEY_F3              ::Stupefy::Key::F3
//#define SF_KEY_F4              ::Stupefy::Key::F4
//#define SF_KEY_F5              ::Stupefy::Key::F5
//#define SF_KEY_F6              ::Stupefy::Key::F6
//#define SF_KEY_F7              ::Stupefy::Key::F7
//#define SF_KEY_F8              ::Stupefy::Key::F8
//#define SF_KEY_F9              ::Stupefy::Key::F9
//#define SF_KEY_F10             ::Stupefy::Key::F10
//#define SF_KEY_F11             ::Stupefy::Key::F11
//#define SF_KEY_F12             ::Stupefy::Key::F12
//#define SF_KEY_F13             ::Stupefy::Key::F13
//#define SF_KEY_F14             ::Stupefy::Key::F14
//#define SF_KEY_F15             ::Stupefy::Key::F15
//#define SF_KEY_F16             ::Stupefy::Key::F16
//#define SF_KEY_F17             ::Stupefy::Key::F17
//#define SF_KEY_F18             ::Stupefy::Key::F18
//#define SF_KEY_F19             ::Stupefy::Key::F19
//#define SF_KEY_F20             ::Stupefy::Key::F20
//#define SF_KEY_F21             ::Stupefy::Key::F21
//#define SF_KEY_F22             ::Stupefy::Key::F22
//#define SF_KEY_F23             ::Stupefy::Key::F23
//#define SF_KEY_F24             ::Stupefy::Key::F24
//#define SF_KEY_F25             ::Stupefy::Key::F25
//
///* Keypad */
//#define SF_KEY_KP_0            ::Stupefy::Key::KP0
//#define SF_KEY_KP_1            ::Stupefy::Key::KP1
//#define SF_KEY_KP_2            ::Stupefy::Key::KP2
//#define SF_KEY_KP_3            ::Stupefy::Key::KP3
//#define SF_KEY_KP_4            ::Stupefy::Key::KP4
//#define SF_KEY_KP_5            ::Stupefy::Key::KP5
//#define SF_KEY_KP_6            ::Stupefy::Key::KP6
//#define SF_KEY_KP_7            ::Stupefy::Key::KP7
//#define SF_KEY_KP_8            ::Stupefy::Key::KP8
//#define SF_KEY_KP_9            ::Stupefy::Key::KP9
//#define SF_KEY_KP_DECIMAL      ::Stupefy::Key::KPDecimal
//#define SF_KEY_KP_DIVIDE       ::Stupefy::Key::KPDivide
//#define SF_KEY_KP_MULTIPLY     ::Stupefy::Key::KPMultiply
//#define SF_KEY_KP_SUBTRACT     ::Stupefy::Key::KPSubtract
//#define SF_KEY_KP_ADD          ::Stupefy::Key::KPAdd
//#define SF_KEY_KP_ENTER        ::Stupefy::Key::KPEnter
//#define SF_KEY_KP_EQUAL        ::Stupefy::Key::KPEqual
//
//#define SF_KEY_LEFT_SHIFT      ::Stupefy::Key::LeftShift
//#define SF_KEY_LEFT_CONTROL    ::Stupefy::Key::LeftControl
//#define SF_KEY_LEFT_ALT        ::Stupefy::Key::LeftAlt
//#define SF_KEY_LEFT_SUPER      ::Stupefy::Key::LeftSuper
//#define SF_KEY_RIGHT_SHIFT     ::Stupefy::Key::RightShift
//#define SF_KEY_RIGHT_CONTROL   ::Stupefy::Key::RightControl
//#define SF_KEY_RIGHT_ALT       ::Stupefy::Key::RightAlt
//#define SF_KEY_RIGHT_SUPER     ::Stupefy::Key::RightSuper
//#define SF_KEY_MENU            ::Stupefy::Key::Menu

#define SF_KEY_SPACE              32
#define SF_KEY_APOSTROPHE         39  /* ' */
#define SF_KEY_COMMA              44  /* , */
#define SF_KEY_MINUS              45  /* - */
#define SF_KEY_PERIOD             46  /* . */
#define SF_KEY_SLASH              47  /* / */
#define SF_KEY_0                  48
#define SF_KEY_1                  49
#define SF_KEY_2                  50
#define SF_KEY_3                  51
#define SF_KEY_4                  52
#define SF_KEY_5                  53
#define SF_KEY_6                  54
#define SF_KEY_7                  55
#define SF_KEY_8                  56
#define SF_KEY_9                  57
#define SF_KEY_SEMICOLON          59  /* ; */
#define SF_KEY_EQUAL              61  /* = */
#define SF_KEY_A                  65
#define SF_KEY_B                  66
#define SF_KEY_C                  67
#define SF_KEY_D                  68
#define SF_KEY_E                  69
#define SF_KEY_F                  70
#define SF_KEY_G                  71
#define SF_KEY_H                  72
#define SF_KEY_I                  73
#define SF_KEY_J                  74
#define SF_KEY_K                  75
#define SF_KEY_L                  76
#define SF_KEY_M                  77
#define SF_KEY_N                  78
#define SF_KEY_O                  79
#define SF_KEY_P                  80
#define SF_KEY_Q                  81
#define SF_KEY_R                  82
#define SF_KEY_S                  83
#define SF_KEY_T                  84
#define SF_KEY_U                  85
#define SF_KEY_V                  86
#define SF_KEY_W                  87
#define SF_KEY_X                  88
#define SF_KEY_Y                  89
#define SF_KEY_Z                  90
#define SF_KEY_LEFT_BRACKET       91  /* [ */
#define SF_KEY_BACKSLASH          92  /* \ */
#define SF_KEY_RIGHT_BRACKET      93  /* ] */
#define SF_KEY_GRAVE_ACCENT       96  /* ` */
#define SF_KEY_WORLD_1            161 /* non-US #1 */
#define SF_KEY_WORLD_2            162 /* non-US #2 */

/* Function keys */
#define SF_KEY_ESCAPE             256
#define SF_KEY_ENTER              257
#define SF_KEY_TAB                258
#define SF_KEY_BACKSPACE          259
#define SF_KEY_INSERT             260
#define SF_KEY_DELETE             261
#define SF_KEY_RIGHT              262
#define SF_KEY_LEFT               263
#define SF_KEY_DOWN               264
#define SF_KEY_UP                 265
#define SF_KEY_PAGE_UP            266
#define SF_KEY_PAGE_DOWN          267
#define SF_KEY_HOME               268
#define SF_KEY_END                269
#define SF_KEY_CAPS_LOCK          280
#define SF_KEY_SCROLL_LOCK        281
#define SF_KEY_NUM_LOCK           282
#define SF_KEY_PRINT_SCREEN       283
#define SF_KEY_PAUSE              284
#define SF_KEY_F1                 290
#define SF_KEY_F2                 291
#define SF_KEY_F3                 292
#define SF_KEY_F4                 293
#define SF_KEY_F5                 294
#define SF_KEY_F6                 295
#define SF_KEY_F7                 296
#define SF_KEY_F8                 297
#define SF_KEY_F9                 298
#define SF_KEY_F10                299
#define SF_KEY_F11                300
#define SF_KEY_F12                301
#define SF_KEY_F13                302
#define SF_KEY_F14                303
#define SF_KEY_F15                304
#define SF_KEY_F16                305
#define SF_KEY_F17                306
#define SF_KEY_F18                307
#define SF_KEY_F19                308
#define SF_KEY_F20                309
#define SF_KEY_F21                310
#define SF_KEY_F22                311
#define SF_KEY_F23                312
#define SF_KEY_F24                313
#define SF_KEY_F25                314
#define SF_KEY_KP_0               320
#define SF_KEY_KP_1               321
#define SF_KEY_KP_2               322
#define SF_KEY_KP_3               323
#define SF_KEY_KP_4               324
#define SF_KEY_KP_5               325
#define SF_KEY_KP_6               326
#define SF_KEY_KP_7               327
#define SF_KEY_KP_8               328
#define SF_KEY_KP_9               329
#define SF_KEY_KP_DECIMAL         330
#define SF_KEY_KP_DIVIDE          331
#define SF_KEY_KP_MULTIPLY        332
#define SF_KEY_KP_SUBTRACT        333
#define SF_KEY_KP_ADD             334
#define SF_KEY_KP_ENTER           335
#define SF_KEY_KP_EQUAL           336
#define SF_KEY_LEFT_SHIFT         340
#define SF_KEY_LEFT_CONTROL       341
#define SF_KEY_LEFT_ALT           342
#define SF_KEY_LEFT_SUPER         343
#define SF_KEY_RIGHT_SHIFT        344
#define SF_KEY_RIGHT_CONTROL      345
#define SF_KEY_RIGHT_ALT          346
#define SF_KEY_RIGHT_SUPER        347
#define SF_KEY_MENU               348