/****************************************************************************/
/*  Log.h                                                                   */
/****************************************************************************/
/*                          This file is a part of:                         */
/*                              STUPEFY ENGINE                              */
/*                                                                          */
/****************************************************************************/
/*  Copyright[2019] Harshit Bargujar , Sujay Kumar Suman                    */
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
/*  See the License for the specific language governing permissionsand      */
/*  limitations under the License.                                          */
/****************************************************************************/


#pragma once

#include "sfpch.h"
#include "Core.h"
#include "spdlog/spdlog.h"

namespace Stupefy {
	class STUPEFY_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger()
		{
			return s_CoreLogger;
		}

		inline static std::shared_ptr<spdlog::logger>& GetClientLogger()
		{
			return s_ClientLogger;
		}

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

//-----CORE LOG MACROS----------------------------
//------------------------------------------------
#define SF_CORE_TRACE(...)		::Stupefy::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SF_CORE_INFO(...)		::Stupefy::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SF_CORE_WARN(...)		::Stupefy::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SF_CORE_ERROR(...)		::Stupefy::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SF_CORE_FATAL(...)		::Stupefy::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//-----CLIENT LOG MACROS--------------------------
//------------------------------------------------
#define SF_CLIENT_TRACE(...)	::Stupefy::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SF_CLIENT_INFO(...)		::Stupefy::Log::GetClientLogger()->info(__VA_ARGS__)
#define SF_CLIENT_WARN(...)		::Stupefy::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SF_CLIENT_ERROR(...)	::Stupefy::Log::GetClientLogger()->error(__VA_ARGS__)
#define SF_CLIENT_FATAL(...)	::Stupefy::Log::GetClientLogger()->fatal(__VA_ARGS__)