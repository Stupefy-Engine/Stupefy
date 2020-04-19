workspace "Stupefy"
    architecture "x64"
    startproject "Sandbox"

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
    kind "SharedLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"
    
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
        runtime "Debug"
        symbols "On"
        
	filter "configurations: Release"
        defines "SF_RELEASE"
        runtime "Release"
        optimize "On"
        
	filter "configurations: Dist"
        defines "SF_DIST"
        runtime "Release"
        optimize "On"


project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "On"
    
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
    
    files
    {
        "%{prj.name}/**.h",
        "%{prj.name}/**.cpp"
    }
    
    includedirs
    {
        "Stupefy/thirdparty",
        "Stupefy"
    }
    
    links
    {
        "Stupefy"
    }
    
    filter "system:windows"
        systemversion "latest"

        defines
        {
            "SF_PLATFORM_WINDOWS"
        }
    
	filter "configurations:Debug"
		defines "SF_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "SF_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "SF_DIST"
		runtime "Release"
		optimize "on"