// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class Cycle_3_Bxls_NL_2021Target : TargetRules
{
	public Cycle_3_Bxls_NL_2021Target( TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.AddRange( new string[] { "Cycle_3_Bxls_NL_2021" } );
	}
}
