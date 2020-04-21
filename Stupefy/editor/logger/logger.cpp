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
#include "editor/logger/colorboy.h"

namespace Stupefy
{
	const std::string currenttime(std::string s)
	{
		time_t now = time(0);
		tm* ltm = localtime(&now);
		struct tm tstruct;
		char buf[80];
		tstruct = *localtime(&now);
		if (s == "now")
		{
			strftime(buf, sizeof(buf), "[%Y-%m-%d][%X] ", &tstruct);
		}
		else if (s == "date")
		{
			strftime(buf, sizeof(buf), "[%Y-%m-%d] ", &tstruct);
		}
		return std::string(buf);
	}

	static void writeLogOnConsole(const char* prepend, const char* message, va_list &args)
	{
		// Log to console
		std::cout << currenttime("now");
		vprintf((std::string(prepend) + message + "\n").c_str(), args);
	}

	void Stupefy::Logger::Trace(const char* message, ...)
	{
		ColorBoy::setupConsole();
		ColorBoy::setTextColor(ColorBoy::WHITE_TXT);

		// Create buffer
		int ret;
		char log_buffer[256];
		va_list args;
		va_start(args, message);
		writeLogOnConsole("[TRACE]: ", message, args);
		ret = vsprintf(log_buffer, message, args);
		va_end(args);

		// Writing to log file
		std::string filepath = "..\\Logs\\Log--" + currenttime("date") + ".txt";
		std::ofstream ofs(filepath.c_str(), std::ios_base::out | std::ios_base::app);
		ofs << currenttime("now") << "\t" << "[TRACE]: " << log_buffer << "\n";
		ofs.close();

		ColorBoy::restoreConsole();
	}

	void Stupefy::Logger::Debug(const char* message, ...)
	{
		ColorBoy::setupConsole();
		ColorBoy::setTextColor(ColorBoy::CYAN_TXT);

		// Create buffer
		int ret;
		char log_buffer[256];
		va_list args;
		va_start(args, message);
		writeLogOnConsole("[DEBUG]: ", message, args);
		ret = vsprintf(log_buffer, message, args);
		va_end(args);

		// Writing to log file
		std::string filepath = "..\\Logs\\Log--" + currenttime("date") + ".txt";
		std::ofstream ofs(filepath.c_str(), std::ios_base::out | std::ios_base::app);
		ofs << currenttime("now") << "\t" << "[DEBUG]: " << log_buffer << "\n";
		ofs.close();

		ColorBoy::restoreConsole();
	}

	void Stupefy::Logger::Log(const char* message, ...)
	{
		ColorBoy::setupConsole();
		ColorBoy::setTextColor(ColorBoy::GREEN_TXT);
		
		// Create buffer
		int ret;
		char log_buffer[256];
		va_list args;
		va_start(args, message);
		writeLogOnConsole("[LOG]: ", message, args);
		ret = vsprintf(log_buffer, message, args);
		va_end(args);

		// Writing to log file
		std::string filepath = "..\\Logs\\Log--" + currenttime("date") + ".txt";
		std::ofstream ofs(filepath.c_str(), std::ios_base::out | std::ios_base::app);
		ofs << currenttime("now") << "\t" << "[LOG]: " << log_buffer <<"\n";
		ofs.close();

		ColorBoy::restoreConsole();
	}

	void Stupefy::Logger::Warn(const char* message, ...)
	{
		ColorBoy::setupConsole();
		ColorBoy::setColorAndStyle(ColorBoy::YELLOW_TXT, ColorBoy::BOLD);
		
		// Create buffer
		int ret;
		char log_buffer[256];
		va_list args;
		va_start(args, message);
		writeLogOnConsole("[WARN]: ", message, args);
		ret = vsprintf(log_buffer, message, args);
		va_end(args);

		// Writing to log file
		std::string filepath = "..\\Logs\\Log--" + currenttime("date") + ".txt";
		std::ofstream ofs(filepath.c_str(), std::ios_base::out | std::ios_base::app);
		ofs << currenttime("now") << "\t" << "[WARN]: " << log_buffer << "\n";
		ofs.close();

		ColorBoy::restoreConsole();
	}

	void Stupefy::Logger::Error(const char* message, ...)
	{
		ColorBoy::setupConsole();
		ColorBoy::setColorAndStyle(ColorBoy::RED_TXT, ColorBoy::BOLD);
		
		// Create buffer
		int ret;
		char log_buffer[256];
		va_list args;
		va_start(args, message);
		writeLogOnConsole("[ERROR]: ", message, args);
		ret = vsprintf(log_buffer, message, args);
		va_end(args);

		// Writing to log file
		std::string filepath = "..\\Logs\\Log--" + currenttime("date") + ".txt";
		std::ofstream ofs(filepath.c_str(), std::ios_base::out | std::ios_base::app);
		ofs << currenttime("now") << "\t" << "[ERROR]: " << log_buffer << "\n";
		ofs.close();
		
		ColorBoy::restoreConsole();
	}

	void Stupefy::Logger::Fatal(const char* message, ...)
	{
		ColorBoy::setupConsole();
		ColorBoy::setBackgroundColorBright(ColorBoy::RED_BKG);
		ColorBoy::setTextColor(ColorBoy::WHITE_TXT);
		
		// Create buffer
		int ret;
		char log_buffer[256];
		va_list args;
		va_start(args, message);
		writeLogOnConsole("[FATAL]: ", message, args);
		ret = vsprintf(log_buffer, message, args);
		va_end(args);

		// Writing to log file
		std::string filepath = "..\\Logs\\Log--" + currenttime("date") + ".txt";
		std::ofstream ofs(filepath.c_str(), std::ios_base::out | std::ios_base::app);
		ofs << currenttime("now") << "\t" << "[FATAL]: " << log_buffer << "\n";
		ofs.close();
		
		ColorBoy::restoreConsole();

		ASSERT(false);
	}
}