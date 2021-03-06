// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ANeedleslyHardGame : ModuleRules
{
	public ANeedleslyHardGame(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "ApexDestruction"});
	}
}
