#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"

namespace Stupefy {
	class STUPEFY_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger>	s_ClientLogger;
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

