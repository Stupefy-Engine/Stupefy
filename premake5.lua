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
IncludeDir["GLFW"] = "Stupefy/thirdparty/glfw/include"
IncludeDir["glad"] = "Stupefy/thirdparty/glad/include"

group "thirdparty"
    include "Stupefy/thirdparty/glad"
    include "Stupefy/thirdparty/glfw"

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

    includedirs
    {
        "%{prj.name}",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.glad}"
    }

    links
    {
        "GLFW",
        "Glad",
        "opengl32.lib"
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