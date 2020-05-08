/****************************************************************************/
/*  colorboy.h                                                              */
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

#include "Core/CoreCommon.h"

namespace ColorBoy
{
	enum Colors
	{
		RESET_COLOR = 0,
		BOLD = 1,
		DARK = 2,
		UNDERLINE = 4,
		BLINK = 5,
		REVERSE = 7,
		CONCEALED = 8,

		BLACK_TXT = 30,
		RED_TXT = 31,
		GREEN_TXT = 32,
		YELLOW_TXT = 33,
		BLUE_TXT = 34,
		MAGENTA_TXT = 35,
		CYAN_TXT = 36,
		WHITE_TXT = 37,

		BLACK_BKG = 40,
		RED_BKG = 41,
		GREEN_BKG = 42,
		YELLOW_BKG = 43,
		BLUE_BKG = 44,
		MAGENTA_BKG = 45,
		CYAN_BKG = 46,
		WHITE_BKG = 47
	};

	void setupConsole(void);
	void restoreConsole(void);

	static inline void setTextColor(int code)
	{
		printf("\x1b[%dm", code);
	}

	static inline void setTextColorBright(int code)
	{
		printf("\x1b[%d;1m", code);
	}

	static inline void setBackgroundColor(int code)
	{
		printf("\x1b[%dm", code);
	}

	static inline void setBackgroundColorBright(int code)
	{
		printf("\x1b[%d;1m", code);
	}

	static inline void setStyle(int code)
	{
		printf("\x1b[%dm", code);
	}

	static inline void setColorAndStyle(int colcode, int stylecode)
	{
		printf("\x1b[%dm\x1b[%dm", colcode, stylecode);
	}
}