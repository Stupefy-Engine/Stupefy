workspace "Stupefy"
    architecture "x64"
    startproject "Sandbox"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

    flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

os.mkdir("Stupefy/../Logs")

IncludeDir = {}
IncludeDir["GLFW"] = "Stupefy/Thirdparty/GLFW/include"
IncludeDir["Glad"] = "Stupefy/Thirdparty/Glad/include"
IncludeDir["ImGui"] = "Stupefy/Thirdparty/imgui"
IncludeDir["glm"] = "Stupefy/Thirdparty/glm"
IncludeDir["vulkan"] = "Stupefy/Thirdparty/vulkan/include"

group "Dependencies"
    include "Stupefy/Thirdparty/GLFW"
    include "Stupefy/Thirdparty/Glad"
    include "Stupefy/Thirdparty/imgui"
    include "Stupefy/Thirdparty/vulkan"

    group ""
    
project "Stupefy"
    location "Stupefy"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"
    
    targetdir("bin/"..outputdir.."/%{prj.name}")
    objdir("bin-int/"..outputdir.."/%{prj.name}")

   files
    {
        "%{prj.name}/**.h",
        "%{prj.name}/Core/**.cpp",
        "%{prj.name}/Editor/**.cpp",
        "%{prj.name}/Main/**.cpp",
        "%{prj.name}/Platform/**.cpp",
        "%{prj.name}/Systems/**.cpp",
--        "%{prj.name}/Thirdparty/glm/glm/**.hpp",
--        "%{prj.name}/Thirdparty/glm/glm/**.inl",
    }

    defines
	{
        "_CRT_SECURE_NO_WARNINGS",
        "GLFW_INCLUDE_NONE"
	}

    includedirs
    {
        "%{prj.name}",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.ImGui}",
        "%{IncludeDir.glm}",
        "%{IncludeDir.vulkan}"
    }

    links
    {
        "GLFW",
        "Glad",
        "ImGui",
        "opengl32.lib",
        "Stupefy/Thirdparty/vulkan/Lib/vulkan-1.lib"
    }

    filter "system:windows"
        systemversion "latest"

        defines
        {
            "SF_PLATFORM_WINDOWS",
            "SF_BUILD_DLL"
        }
        
	filter "configurations: Debug"
        defines "SF_DEBUG"
        runtime "Debug"
        symbols "on"
        
	filter "configurations: Release"
        defines "SF_RELEASE"
        runtime "Release"
        optimize "on"
        
	filter "configurations: Dist"
        defines "SF_DIST"
        runtime "Release"
        optimize "on"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"
    
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
    
    files
    {
        "%{prj.name}/**.h",
        "%{prj.name}/**.cpp"
    }
    
    includedirs
    {
        "Stupefy",
        "Stupefy/Thirdparty",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.ImGui}",
        "%{IncludeDir.glm}",
        "%{IncludeDir.vulkan}"
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
    
	filter "configurations: Debug"
		defines "SF_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations: Release"
		defines "SF_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations: Dist"
		defines "SF_DIST"
		runtime "Release"
		optimize "on"
        