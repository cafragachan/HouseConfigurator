// Fill out your copyright notice in the Description page of Project Settings.

using System.IO;
using UnrealBuildTool;

public class HouseConfiguratorV02 : ModuleRules
{
    private string ModulePath
    {
        get { return ModuleDirectory; }
    }

    private string zSpacePath
    {
        get { return Path.GetFullPath("C:/Users/cesar.fragachan/source/repos/venumb/ZSPACE"); }
    }

    public HouseConfiguratorV02(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "ProceduralMeshComponent" });

        PrivateDependencyModuleNames.AddRange(new string[] { });

        // Uncomment if you are using Slate UI
        // PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        // Uncomment if you are using online features
        // PrivateDependencyModuleNames.Add("OnlineSubsystem");

        // To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true

        LoadzSpace(Target);
    }

    public bool LoadzSpace(ReadOnlyTargetRules Target)
    {
        bool isLibrarySupported = false;

        if ((Target.Platform == UnrealTargetPlatform.Win64) || (Target.Platform == UnrealTargetPlatform.Win32))
        {
            isLibrarySupported = true;

            string PlatformString = (Target.Platform == UnrealTargetPlatform.Win64) ? "x64" : "x86";
            string LibrariesPath = Path.Combine(zSpacePath, "cpp/compiled/UnrealLib");

            PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "zSpace_Core" + ".lib"));
            PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "zSpace_Interface" + ".lib"));
            PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "zSpace_Toolsets" + ".lib"));
            PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "zSpace_ArchGeom" + ".lib"));
            PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "zSpace_Housing" + ".lib"));

        }

        if (isLibrarySupported)
        {
            // Include path
            PublicIncludePaths.Add(Path.Combine(zSpacePath, "/cpp"));
        }

        return isLibrarySupported;
    }
}
