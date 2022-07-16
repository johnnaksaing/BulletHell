workspace "BulletHell"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

--targetdir ("bin/" .. outputdir .. "/%{prj.name}")
--objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

project "BulletHell"
	location "BulletHell"
	kind "ConsoleApp"
	language "C++"


	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/../Externals/SDL2-2.0.22/include",
		"$(SolutionDir)/Externals/SDL2-2.0.22/include"
	}

	links
	{
		"SDL2",
		"SDL2main",
		"SDL2test"
	}

	libdirs
	{
		"%{prj.name}/Externals/SDL2-2.0.22/lib/x64",
		"$(SolutionDir)/Externals/SDL2-2.0.22/lib/x64"
	}

	filter "system:windows"
		cppdialect "C++14"
		staticruntime "On"
		
		
	defines
	{

	}

	filter "configurations:Debug"
		defines "DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "RELEASE"
		optimize "On"