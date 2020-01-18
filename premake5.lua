workspace "Stupefy"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Stupefy"
	location "Stupefy"
	kind "SharedLib"
	language "C++"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "sfpch.h"
	pchsource "Stupefy/Src/sfpch.cpp"

	files
	{
		"%{prj.name}/Src/**.h",
		"%{prj.name}/Src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include;"
	}

	filter "system:windows"
		cppdialect	"C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"SF_PLATFORM_WINDOWS",
			"SF_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations: Debug"
		defines "SF_DEBUG"
		symbols "On"
	filter "configurations: Release"
		defines "SF_RELEASE"
		optimize "On"
	filter "configurations: Dist"
		defines "SF_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/Src/**.h",
		"%{prj.name}/Src/**.cpp"
	}

	includedirs
	{
		"Stupefy/vendor/spdlog/include;",
		"Stupefy/Src"
	}

	links
	{
		"Stupefy"
	}

	filter "system:windows"
		cppdialect    "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"SF_PLATFORM_WINDOWS"
		}

	filter "configurations: Debug"
		defines "SF_DEBUG"
		symbols "On"
	filter "configurations: Release"
		defines "SF_RELEASE"
		optimize "On"
	filter "configurations: Dist"
		defines "SF_DIST"
		optimize "On"
