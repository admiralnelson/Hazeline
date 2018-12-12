workspace "HazelGameEngine"
	architecture "x64"
	
	configurations 
	{
		"Debug",
		"Release",
		"Dist"
	}

output = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Hazel"
	location "Hazel"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. output .. "/%{prj.name}")
	objdir("obj/" .. output .. "/%{prj.name}")

	pchheader "%{prj.name}/hzpch.h"
	pchsource "%{prj.name}/Hazel/src/Hazel/hzpch.cpp"
	
	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"

	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:linux"
		cppdialect "c++17"
		-- staticruntime "On"
		-- systemversion "latest"
		
		defines
		{
			"HZ_PLATFORM_LINUX",
			"HZ_BUILD_SO",
		}
	
		postbuildcommands
		{
			("cp %{cfg.buildtarget.relpath} ../bin/" .. output .. "/Sandbox")
		}

	filter "system:windows"
		cppdialect "c++17"
		staticruntime "On"
		systemversion "latest"
		
		defines
		{
			"HZ_PLATFORM_WINDOWS",
			"HZ_BUILD_SO",
		}
	
		postbuildcommands
		{
			("cp %{cfg.buildtarget.relpath} ../bin/" .. output .. "/Sandbox")
		}

	
	filter "configurations:Debug"
		defines "HZ_DEBUG"
		symbols "On"
		
	filter "configurations:Release"
		defines "HZ_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "HZ_DIST"
		optimize "On"
		
project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. output .. "/%{prj.name}")
	objdir("obj/" .. output .. "/%{prj.name}")
	
	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"

	}

	includedirs
	{
		"Hazel/vendor/spdlog/include",
		"Hazel/src"
	}

	links
	{
		"Hazel"
	}

	filter "system:linux"
		cppdialect "c++17"
		-- staticruntime "On"
		-- systemversion "latest"
		
		defines
		{
			"HZ_PLATFORM_LINUX",
			"HZ_BUILD_SO",
		}
	
	filter "system:windows"
		cppdialect "c++17"
		staticruntime "On"
		systemversion "latest"
		
		defines
		{
			"HZ_PLATFORM_WINDOWS",
			"HZ_BUILD_SO",
		}
	
	
	filter "configurations:Debug"
		defines "HZ_DEBUG"
		symbols "On"
		
	filter "configurations:Release"
		defines "HZ_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "HZ_DIST"
		optimize "On"
