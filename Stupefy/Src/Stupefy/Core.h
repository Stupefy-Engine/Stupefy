#pragma once

#ifdef SF_PLATFORM_WINDOWS
	#ifdef SF_BUILD_DLL
		#define STUPEFY_API __declspec(dllexport)
	#else
		#define STUPEFY_API __declspec(dllimport)
	#endif
#else
	#error Stupefy supports Windows only!
#endif