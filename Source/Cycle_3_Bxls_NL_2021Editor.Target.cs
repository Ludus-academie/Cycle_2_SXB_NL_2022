// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class Cycle_3_Bxls_NL_2021EditorTarget : TargetRules
{
	public Cycle_3_Bxls_NL_2021EditorTarget( TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.AddRange( new string[] { "Cycle_3_Bxls_NL_2021" } );
	}
}
