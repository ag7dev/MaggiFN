#pragma once
#include <Memory/Safety/Imports.h>

uintptr_t FortniteClientWin64Shipping = 0;
uintptr_t MainModule = 0;

#include <string>

namespace Offsets
{
	int bEnableRecoilDelay = 0x1c64;
	int GObjects = 0x126A7EB0;
	int GNames = 0x120A7A40;
	int StaticFindObject = 0x159CB5A;
	int GameInstance = 0x200;
	int GetCameraViewPoint = 90;
	int FireSingle = 274;
	int TryToFire = 170; 
	int GetDamageStartLocation = 250;  
	int GetSearchTime = 225; 
	int GetControlRotation = 237;
	int DetermineTraceChannel = 388;
	int GetWeaponTargetingTransform = 254;
	int GetPlayerViewPoint = 256;

	int GetWeaponTargetingTransformTest = 255;
	int GetDamageStartLocationTest = 249; 

	int GetPlayerViewPointTest = 255;
	int GetCameraViewPointTest = 89;
}

namespace Offsets::ExploitOffsets
{
	int bFixAimAssistDeadzoneExploit = 0x52c;
	int bADSWhileNotOnGround = 0x5719;
	int CharacterGender = 0x234a;
	int LastFireTime = 0xf04;
	int LastFireTimeVerified = 0xf08;
	int TriggerType = 0x244;
	int CurrentWeapon = 0x9d8;
	int WeaponData = 0x548;
	int RelativeRotation = 0x138;
	int CustomTimeDilation = 0x68;
	int GlobalAnimRateScale = 0x9f0;
	int bIsReloadingWeapon = 0;
	int bIsTargeting = 0;
	int bCooldownWhileOverheated = 0x1cd0;
	int OnSetFirstPersonCamera = 0x1100;
	int Wireframe = 0x1b0;
	int bDisableDepthTest = 0x1a0;
	int CurrentVehicle = 0x2a30;
	int ReticleSpreadZeroingDistanceFromMuzzle = 0x1c80;
	int FirstShotAccuracyMinWaitTime = 0x1be0;
	int BulletCountForPerBulletRecoil = 0x1be4;
	int BulletCountForPerBulletSpread = 0x1be8;
	int TimeRemainingForBulletSpread = 0x1bec;
	int bUseOverrideBaseSpread = 0x1869;
	int bUseOverrideSpreadDownsightsMultiplier = 0x1869;
	int bReticleCornerOutsideSpreadRadius = 0x249;
	int bShouldUsePerfectAimWhenTargetingMinSpread = 0x480;
	int ServerFuel = 0x110;
	int CachedFuelComponent = 0x1330;
	int DragCoefficient2 = 0x4c0;
	int FortPhysicsVehicleConfigs = 0x1bd0;
	int bIsJumping = 0x9d0;
	int bIsSliding = 0x6d3;
	int bThankedBusDriver = 0x13b5;
	int WeaponReloadMontage = 0x12e0;
	int ReloadAnimation = 0x12b0;
}

#include <Memory/Safety/SKCrypter.h>
#include <Memory/Custom/NoCRT.h>
#include <Memory/Signature.h>

#include <Memory/VTableHook.h>
Hook::VTableHook ViewportClientHook;

#include <Fortnite/Engine/Engine.h>
#include <Fortnite/Engine/Classes.h>

#include <Memory/Custom/Map.h>
#include <Memory/Custom/Vector.h>

static pair<int, UMaterialInterface*> Indexs;

namespace Variables
{

	UCanvas* Canvas = nullptr;
	APlayerController* PlayerController = nullptr;
	UWorld* World = nullptr;
	APlayerPawn_Athena_C* AcknowledgedPawn = nullptr;
	UGameViewportClient* ViewportClient = nullptr;


	UFont* Roboto = nullptr;
	UFont* MediumFont = nullptr;



	FVector VehiclePos = FVector();



	static bool DrawMenu = true;
	double FramesPerSecond = 0.0;
	unsigned __int64 CurrentFrame = 0;
	FLinearColor Rainbow = FLinearColor( );
	static FVector2D ScreenCenter = FVector2D( );
	static FVector2D ScreenSize = FVector2D( );
	static FVector2D ScreenTopLeft = FVector2D();


	static FVector CameraLocation = FVector( );
	static FRotator CameraRotation = FRotator( );
	static float FieldOfView = 0.f;

	namespace GetViewPoint
	{
		static FVector Location = FVector();
		static FRotator Rotation = FRotator();
		static bool bApplyModifiedData = false;
		static bool bSkipRotationForModification = false;
	}

	namespace BulletTraces
	{
		static AFortWeapon* CurrentWeapon;
		static bool bEnableBulletTraces = false;
		static FLinearColor BulletTraceColor = FLinearColor(0.f, 1.f, 1.f, 1.f);

		static int PlacedShotsIndex = 0;

		static FVector WorldTraceLocations3D[5];
		static FVector MuzzleWorldTraceLocations3D[5];

	}

	namespace GetWeaponTargetingTransform
	{
		static bool bSilentAimActive = false;
		static FVector SilentLocationTarget = FVector( );
	}

	namespace GetCameraViewPoint
	{
		static bool bFreecamActive = false;
		static FRotator ModdedStickyRotation = FRotator();
		static FRotator LastStickyRotation = FRotator();
		static FVector StickyLocation = FVector();
		static FVector CachedFreecamLocation = FVector();
	}

	namespace GetPlayerViewPoint
	{
		static bool bSilentAimActive = false;
		static bool bShouldStartAtLocationTarget = false;
		static FVector OriginalLocation = FVector();
		static FRotator OriginalRotation = FRotator();

		static FVector SilentLocationTarget = FVector();

		static FVector LastTargetLocation = FVector();
		static FRotator LastTargetRotation = FRotator();

	}

	namespace GetControlRotation
	{
		static bool bAimbotActive = false;
		static FRotator AimbotRotationTarget = FRotator( );
	}
}

namespace Keys
{
	FKey LeftMouseButton;
	FKey RightMouseButton;
	FKey GamepadLeftTrigger;
	FKey Insert;
	FKey F8;
	FKey F7;
	FKey W;
	FKey A;
	FKey S;
	FKey D;
	FKey X;
	FKey Right;
	FKey SpaceBar;
	FKey LeftShift;
	FKey LeftAlt;
	FKey Capslock;
	FKey Tab;

	namespace Other
	{
	
		FKey B;
		FKey C;
		FKey E;
		FKey F;
		FKey G;
		FKey H;
		FKey I;
		FKey J;
		FKey K;
		FKey L;
		FKey M;
		FKey N;
		FKey O;
		FKey P;
		FKey Q;
		FKey R;
		FKey T;
		FKey U;
		FKey V;
		FKey Y;
		FKey Z;

	

		FKey ThumbMouseButton;
		FKey ThumbMouseButton2;
		FKey MiddleMouseButton;
		FKey Gamepad_LeftTrigger;
		FKey Gamepad_FaceButton_Right;
	

		FKey Underscore;
		FKey Period;
		FKey Slash;
	}
}

namespace Classes
{
	UObject* MarkerClass = nullptr;
	UObject* PlayerPawn = nullptr;
	UObject* FortPickup = nullptr;
	UObject* BuildingTrap = nullptr;
	UObject* BuildingContainer = nullptr;
	UObject* BuildingWeakSpot = nullptr;
	UObject* AthenaSuperDingo = nullptr;
	UObject* FortAthenaVehicle = nullptr;
	UObject* AthenaSupplyDrop = nullptr;
	UObject* FortWeaponRanged = nullptr;
	UObject* FortWeapon = nullptr;
	UObject* WeaponPickaxeAthena = nullptr;
	UObject* BaseWeaponStats = nullptr;
	UObject* Material = nullptr;
	UObject* Texture = nullptr;
	UObject* SoundBase = nullptr;
	UObject* LocalPlayer = nullptr;
	UObject* PlayerController = nullptr;
	UObject* GameViewportClient = nullptr;
	UObject* PlayerCameraManager = nullptr;
	UObject* DynamicMaterialInstance = nullptr;
	UObject* ActorPlayerNamePrivate = nullptr;

}

#include <Fortnite/Settings.h>
#include <Fortnite/Features/GetSearchTime.h>
#include <Fortnite/Features/HasInfiniteAmmo.h>
#include <Fortnite/Features/GetControlRotation.h>
#include <Fortnite/Features/DetermineTraceChannel.h>
#include <Fortnite/Features/GetWeaponTargetingTransform.h>
#include <Fortnite/Features/GetPlayerViewPoint.h>
#include <Fortnite/Features/GetCameraViewPoint.h>
#include <Fortnite/Features/GetDamageStartLocation.h>
#include <Fortnite/Features/FireSingle.h>
#include <Fortnite/Features/TryToFire.h>
#include <Fortnite/Features/Cosmetics.h>
#include <Fortnite/Features/GetViewPoint.h>

#include <Fortnite/Framework/Wrapper.h>
#include <Fortnite/Framework/Framework.h>

#include <Fortnite/Exploits.h>
#include <Fortnite/Features/DrawTransition.h>