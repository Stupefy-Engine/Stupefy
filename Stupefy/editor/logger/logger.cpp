/****************************************************************************/
/*  logger.cpp                                                              */
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


#include "editor/logger/logger.h"

namespace Stupefy
{
	static void writeLog(const char* prepend, const char* message, va_list args)
	{
		vprintf((std::string(prepend) + message + "\n").c_str(), args);
	}

	void Stupefy::Logger::Trace(const char* message, ...)
	{
		va_list args;
		va_start(args, message);
		writeLog("[TRACE]: ", message, args);
		va_end(args);
	}

	void Stupefy::Logger::Log(const char* message, ...)
	{
		va_list args;
		va_start(args, message);
		writeLog("[LOG]: ", message, args);
		va_end(args);
	}

	void Stupefy::Logger::Warn(const char* message, ...)
	{
		va_list args;
		va_start(args, message);
		writeLog("[WARN]: ", message, args);
		va_end(args);
	}

	void Stupefy::Logger::Error(const char* message, ...)
	{
		va_list args;
		va_start(args, message);
		writeLog("[ERROR]: ", message, args);
		va_end(args);
	}

	void Stupefy::Logger::Fatal(const char* message, ...)
	{
		va_list args;
		va_start(args, message);
		writeLog("[FATAL]: ", message, args);
		va_end(args);

		ASSERT(false);
	}
}