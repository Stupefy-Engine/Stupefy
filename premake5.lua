workspace "Stupefy"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Stupefy/thirdparty/GLFW/include"
IncludeDir["Glad"] = "Stupefy/thirdparty/Glad/include"
IncludeDir["vulkan"] = "Stupefy/thirdparty/vulkan/include"

group "thirdparty"
    include "Stupefy/thirdparty/GLFW"
    include "Stupefy/thirdparty/Glad"
    include "Stupefy/thirdparty/vulkan"

group ""

project "Stupefy"
    location "Stupefy"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"

    targetdir("bin/"..outputdir.."/%{prj.name}")
    objdir("bin-int/"..outputdir.."/%{prj.name}")

   files
    {
        "%{prj.name}/**.h",
        "%{prj.name}/**.cpp"
    }

    defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

    includedirs
    {
        "%{prj.name}",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.vulkan}"
    }

    links
    {
        "GLFW",
        "Glad",
        "opengl32.lib",
        "Stupefy/thirdparty/vulkan/Lib/vulkan-1.lib"
    }

    filter "system:windows"
        systemversion "latest"
        
	filter "configurations: Debug"
		defines "SF_DEBUG"
		symbols "On"
	filter "configurations: Release"
		defines "SF_RELEASE"
		optimize "On"
	filter "configurations: Dist"
		defines "SF_DIST"
		optimize "On"