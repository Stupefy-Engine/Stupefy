/****************************************************************************/
/*  colorboy.cpp                                                            */
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


#include "Core/CoreCommon.h"
#include "Editor/Logger/ColorBoy.h"

namespace ColorBoy
{
#ifdef _WIN32
#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif

	static HANDLE stdoutHandle;
	static DWORD outModeINit;

	void setupConsole(void)
	{
		DWORD outMode = 0;
		stdoutHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		if (stdoutHandle == INVALID_HANDLE_VALUE)
		{
			exit(GetLastError());
		}

		if (!GetConsoleMode(stdoutHandle, &outMode))
		{
			exit(GetLastError());
		}

		outModeINit = outMode;

		outMode = outMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING;

		if (!SetConsoleMode(stdoutHandle, outMode))
		{
			exit(GetLastError());
		}
	}

	void restoreConsole(void)
	{
		std::cout << "\x1b[0m";

		if (!SetConsoleMode(stdoutHandle, outModeINit))
		{
			exit(GetLastError());
		}
	}
#else
	void setupConsole(void) {}

	void restoreConsole(void)
	{
		std::cout << "\x1b[0m";
	}
#endif
}