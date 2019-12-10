// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class HouseConfiguratorV02Target : TargetRules
{
	public HouseConfiguratorV02Target(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "HouseConfiguratorV02" } );
	}
}
