#pragma once
#include <windows.h>
#include <filesystem>

class UFunction;

class UObject
{
public:
	uint64_t GetVTable()
	{
		return *(uint64_t*)(this + 0x0); 
	}

	EObjectFlags GetObjectFlags()
	{
		return *(EObjectFlags*)(this + 0x8); 
	}

	int GetInternalIndex()
	{
		return *(int*)(this + 0xC); 
	}

	UObject* GetClassPrivate()
	{
		return *(UObject**)(this + 0x10); 
	}

	FName GetNamePrivate()
	{
		return *(FName*)(this + 0x18); 
	}

	UObject* GetOuterPrivate()
	{
		return *(UObject**)(this + 0x20); 
	}

	void ProcessEvent(UObject* UFunction, void* Params)
	{
		if (auto VTable = *(void***)this)
		{
			reinterpret_cast<void(__cdecl*)(UObject*, UObject*, void*)>(VTable[44])(this, UFunction, Params);
		}
	}

	/*void ProcessEvent(UObject* UFunction, void* Params)
	{
		static void* (*ProcessEvent)(UObject*, UObject*, void*) = nullptr;
		if (!ProcessEvent)
		{
			ProcessEvent = find_pattern<decltype(ProcessEvent)>(WindowsAPI::HMODULE(FortniteClientWin64Shipping), Encrypt("42 55 56 57 43 54 41 55 41 56 41 57 48 81 C4").decrypt()); 
		}

		if (!ProcessEvent)
		{
			WindowsAPI::MessageBoxA(0, Encrypt("failed to get pattern 2, game update?\r\n").decrypt(), 0, 0);
		}

		ProcessEvent(this, UFunction, Params);
	}*/
	

	static UObject* StaticFindObject(UObject* Class, UObject* Outer, const wchar_t* Name, bool ExactClass)
	{

		static auto SFOPattern = Encrypt("40 55 53 56 57 43 54 43 56 43 57 48 8D AC 24 ? ? ? ? 48 81 C4 50 FA FF FF");

		static void* (*StaticFindObject)(UObject * Class, UObject * InOuter, const wchar_t* Name, bool ExactClass) = nullptr;
		if (!StaticFindObject)
		{
			

			
			
			

			

			
			
			

			StaticFindObject = find_pattern<decltype(StaticFindObject)>(SFOPattern.decrypt());
			
			
		}

		if (!StaticFindObject)
		{
			WindowsAPI::MessageBoxA(0, Encrypt("failed to locate pattern 1. game update? try restarting your game..").decrypt(), 0, 0);
			SFOPattern.clear();
		}
		else
		{
			SFOPattern.clear();
			
			
		}


		return reinterpret_cast<UObject*> (StaticFindObject(Class, Outer, Name, ExactClass));
	}

	template <class Type>
	static Type FindObjectSingle(const wchar_t* Name, UObject* Outer = nullptr)
	{
		return reinterpret_cast<Type>(UObject::StaticFindObject(nullptr, Outer, Name, false));
	}

	template <class Type>
	static Type FindObjectSingle_Test(const wchar_t* Name, UObject* Outer = nullptr)
	{
		
	}
};

class USoundBase : public UObject
{
public:

};

class UFont : public UObject
{
public:
	int32_t LegacyFontSize()
	{
		return *(int32_t*)(this + 0x13c);
	}
};

class UTexture : public UObject
{
public:

};

class UTexture2D : public UTexture
{
public:

};

inline UFont* MediumFont = 0;

class UCanvas : public UObject
{
public:
	float ClipX()
	{
		return *(float*)(this + 0x30);
	}

	float ClipY()
	{
		return *(float*)(this + 0x34);
	}

	UTexture2D* DefaultTexture()
	{
		return *(UTexture2D**)(this + 0x70);
	}

	void K2_DrawLine(FVector2D ScreenPositionA, FVector2D ScreenPositionB, float Thickness, FLinearColor RenderColor)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"Canvas.K2_DrawLine");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			FVector2D ScreenPositionA;
			FVector2D ScreenPositionB;
			float Thickness;
			FLinearColor RenderColor;
		} Params = { ScreenPositionA, ScreenPositionB, Thickness, RenderColor };

		this->ProcessEvent(Function, &Params);
	}

	void K2_DrawText(FString RenderText, FVector2D ScreenPosition, double FontSize, FLinearColor RenderColor, bool bCentreX, bool bCentreY, bool bOutlined)
	{
		UFont* RenderFont = MediumFont;
		*(int32*)(RenderFont + 0x13c) = FontSize;

		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"Canvas.K2_DrawText");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			UObject* RenderFont;
			FString RenderText;
			FVector2D ScreenPosition;
			FVector2D Scale;
			FLinearColor RenderColor;
			float Kerning;
			FLinearColor ShadowColor;
			FVector2D ShadowOffset;
			bool bCentreX;
			bool bCentreY;
			bool bOutlined;
			FLinearColor OutlineColor;
		} Params = { RenderFont, RenderText, ScreenPosition, FVector2D(1.0, 1.0), RenderColor, 0.f, FLinearColor(), FVector2D(), bCentreX, bCentreY, bOutlined, FLinearColor(0.f, 0.f, 0.f, 1.f) };

		this->ProcessEvent(Function, &Params);
	}

	void K2_DrawPolygon(UTexture* RenderTexture, FVector2D ScreenPosition, FVector2D Radius, int32_t NumberOfSides, FLinearColor RenderColor)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"Canvas.K2_DrawPolygon");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			UTexture* RenderTexture;
			FVector2D ScreenPosition;
			FVector2D Radius;
			int32_t NumberOfSides;
			FLinearColor RenderColor;
		} Params = { RenderTexture, ScreenPosition, Radius, NumberOfSides, RenderColor };

		this->ProcessEvent(Function, &Params);
	}

	void K2_DrawTexture(UTexture* RenderTexture, FVector2D ScreenPosition, FVector2D ScreenSize, FVector2D CoordinatePosition, FVector2D CoordinateSize, FLinearColor RenderColor, EBlendMode BlendMode, float Rotation, FVector2D PivotPoint)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"Canvas.K2_DrawTexture");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct K2_DrawTexture_Params
		{
		public:
			UObject* RenderTexture;
			FVector2D ScreenPosition;
			FVector2D ScreenSize;
			FVector2D CoordinatePosition;
			FVector2D CoordinateSize;
			FLinearColor RenderColor;
			EBlendMode BlendMode;
			float Rotation;
			FVector2D PivotPoint;
		};

		K2_DrawTexture_Params Params;
		Params.RenderTexture = RenderTexture;
		Params.ScreenPosition = ScreenPosition;
		Params.ScreenSize = ScreenSize;
		Params.CoordinatePosition = CoordinatePosition;
		Params.CoordinateSize = CoordinateSize;
		Params.RenderColor = RenderColor;
		Params.BlendMode = BlendMode;
		Params.Rotation = Rotation;
		Params.PivotPoint = PivotPoint;

		this->ProcessEvent(Function, &Params);
	}

	FVector K2_Project(FVector WorldLocation)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"Canvas.K2_Project");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			FVector WorldLocation;
			FVector ReturnValue;
		} Params = { WorldLocation };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}
};



class UFortRuntimeOptions : public UObject
{
public:
	bool GetFixAimAssistDeadzoneExploit()
	{
		if (this)
		{
			return *(bool*)(this + Offsets::ExploitOffsets::bFixAimAssistDeadzoneExploit);
		}

		return true;
	}

	void SetFixAimAssistDeadzoneExploit(bool bNewValue)
	{
		if (this)
		{
			if (this->GetFixAimAssistDeadzoneExploit() != bNewValue)
			{
				*(bool*)(this + Offsets::ExploitOffsets::bFixAimAssistDeadzoneExploit) = bNewValue;
			}
		}
	}
};



class AHUD : public UObject
{
public:

};

class UActorComponent : public UObject
{
public:

};

class UCameraComponent : public UActorComponent
{
public:

};

class APlayerCameraManager : public UObject
{
public:

	void SetCustomTimeDilation(float NewTimeDilation)
	{
		if (this)
		{
			uintptr_t address = reinterpret_cast<uintptr_t>(this) + Offsets::ExploitOffsets::CustomTimeDilation;
			if (*reinterpret_cast<float*>(address) != NewTimeDilation)
			{
				*reinterpret_cast<float*>(address) = NewTimeDilation;
			}
		}
	}

	void ResetCustomTimeDilation()
	{
		if (this)
		{
			uintptr_t address = reinterpret_cast<uintptr_t>(this) + Offsets::ExploitOffsets::CustomTimeDilation;
			this->SetCustomTimeDilation(1.f);
		}
	}

	float GetCustomTimeDilation()
	{
		if (this)
		{
			uintptr_t address = reinterpret_cast<uintptr_t>(this) + Offsets::ExploitOffsets::CustomTimeDilation;
			return *reinterpret_cast<float*>(address);
		}
	}

	float GetFOVAngle()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"PlayerCameraManager.GetFOVAngle");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			float ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	



	FVector GetCameraLocation()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"PlayerCameraManager.GetCameraLocation");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			FVector ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	FRotator GetCameraRotation()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"PlayerCameraManager.GetCameraRotation");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			FRotator ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}
};

class AActor : public UObject
{
public:
	
	void SetCustomTimeDilation(float NewTimeDilation)
	{
		if (this)
		{
			uintptr_t address = reinterpret_cast<uintptr_t>(this) + Offsets::ExploitOffsets::CustomTimeDilation;
			if (*reinterpret_cast<float*>(address) != NewTimeDilation)
			{
				*reinterpret_cast<float*>(address) = NewTimeDilation;
			}
		}
	}

	void ResetCustomTimeDilation()
	{
		if (this)
		{
			uintptr_t address = reinterpret_cast<uintptr_t>(this) + Offsets::ExploitOffsets::CustomTimeDilation;
			this->SetCustomTimeDilation(1.f);
		}
	}

	float GetCustomTimeDilation()
	{
		if (this)
		{
			uintptr_t address = reinterpret_cast<uintptr_t>(this) + Offsets::ExploitOffsets::CustomTimeDilation;
			return *reinterpret_cast<float*>(address);
		}
	}

	void K2_SetActorRelativeRotation(FRotator NewRelativeRotation, bool bTeleport = true)
	{
		
		static UObject* Function;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"Actor.K2_SetActorRelativeRotation");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}
		
		struct {
			FRotator NewRelativeRotation;
			bool bSweep;
			FHitResult SweepHitResult;
			bool bTeleport;
		} Params = { NewRelativeRotation, false, FHitResult(), bTeleport };

		this->ProcessEvent(Function, &Params);
	}


	FString GetPlayerNameSafe(AActor* AActor, UObject* playernameprivate)
	{
		struct {
			UObject* AActor;
			FString return_value;
		} params = { AActor };

		static UObject* function;
		if (!function) function = playernameprivate;
		this->ProcessEvent(function, &params);
		return params.return_value;
	}

	FString GetPlayerOrObjectNameSafe(AActor* AActor)
	{
		struct {
			UObject* AActor;
			FString ReturnValue;
		} params = { AActor };

		static UObject* Function;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortKismetLibrary.GetPlayerOrObjectNameSafe");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		this->ProcessEvent(Function, &params);
		return params.ReturnValue;
	}

	FString GetPlayerNameSafe2(AActor* AActor, UObject* FunctionPtr)
	{
		struct {
			UObject* AActor;
			FString return_value;
		} params = { AActor };

		static UObject* function;

		if (FunctionPtr && !function)
		{
			function = FunctionPtr;
		}

		if (function)
		{
			this->ProcessEvent(function, &params);
			return params.return_value;
		}

		return FString(L"error");
	}


	void DisableInput(UObject* PlayerController)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"Actor.DisableInput");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			UObject* PlayerController;
		} Params = { PlayerController };

		this->ProcessEvent(Function, &Params);
	}

	void EnableInput(UObject* PlayerController)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"Actor.EnableInput");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			UObject* PlayerController;
		} Params = { PlayerController };

		this->ProcessEvent(Function, &Params);
	}

	FVector GetVelocity()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"Actor.GetVelocity");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			FVector ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	bool K2_TeleportTo(FVector DestLocation, FRotator DestRotation)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"Actor.K2_TeleportTo");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			FVector DestLocation;
			FRotator DestRotation;
			bool ReturnValue;
		} Params = { DestLocation, DestRotation };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	FVector K2_GetActorLocation()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"Actor.K2_GetActorLocation");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			FVector ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	bool K2_SetActorLocationAndRotation(FVector NewLocation, FRotator NewRotation)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"Actor.K2_SetActorLocationAndRotation");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			FVector NewLocation;
			FRotator NewRotation;
			bool bSweep;
			FHitResult SweepHitResult;
			bool bTeleport;
			bool ReturnValue;
		} Params = { NewLocation, NewRotation, false, FHitResult(), true };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	bool K2_SetActorLocation(FVector new_location, bool sweep, uint8_t sweep_hit_result, bool teleport) {
		static UObject* function;
		if (!function)
			function = UObject::FindObjectSingle<UObject*>(L"Actor.K2_SetActorLocation");

		struct { FVector a1; bool a2; uint8_t a3; bool a4; bool ret; } params;
		params.a1 = new_location;
		params.a2 = sweep;
		params.a3 = sweep_hit_result;
		params.a4 = teleport;

		this->ProcessEvent(function, &params);
		return params.ret;
	}

	bool SetActorLocation(FVector new_location, bool sweep, uint8_t sweep_hit_result, bool teleport) {
		static UObject* function;
		if (!function)
			function = UObject::FindObjectSingle<UObject*>(L"Actor.K2_SetActorLocation");

		struct { FVector a1; bool a2; uint8_t a3; bool a4; bool ret; } params;
		params.a1 = new_location;
		params.a2 = sweep;
		params.a3 = sweep_hit_result;
		params.a4 = teleport;

		this->ProcessEvent(function, &params);
		return params.ret;
	}

	bool K2_SetActorRotation(FRotator NewRotation, bool bTeleportPhysics)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"Actor.K2_SetActorRotation");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			FRotator& NewRotation;
			bool bTeleportPhysics;
			bool ReturnValue;
		} Params = { NewRotation, bTeleportPhysics };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	FRotator K2_GetActorRotation()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"Actor.K2_GetActorRotation");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			FRotator ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	void SetActorTickEnabled(bool bEnabled)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"Actor.SetActorTickEnabled");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			bool bEnabled;
		} Params = { bEnabled };

		this->ProcessEvent(Function, &Params);
	}

	void SetActorTickInterval(float TickInterval)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"Actor.SetActorTickInterval");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			float TickInterval;
		} Params = { TickInterval };

		this->ProcessEvent(Function, &Params);
	}

	
	
	FVector GetActorScale3D()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"Actor.GetActorScale3D");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			FVector ReturnValue;
		} Params;

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	void SetActorScale3D(FVector NewScale3D)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"Actor.SetActorScale3D");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			FVector& NewScale3D;
		} Params = { NewScale3D };

		this->ProcessEvent(Function, &Params);
	}

	void SetNetDormancy(ENetDormancy NewDormancy)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"Actor.SetNetDormancy");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			ENetDormancy NewDormancy;
		} Params = { NewDormancy };

		this->ProcessEvent(Function, &Params);
	}
};



struct FMinimalViewInfo {
	FVector Location; 
	FRotator Rotation; 
	float FOV; 
	float DesiredFOV; 
	float OrthoWidth; 
	bool bAutoCalculateOrthoPlanes; 
	char pad_3D[0x3]; 
	float AutoPlaneShift; 
	bool bUpdateOrthoPlanes; 
	bool bUseCameraHeightAsViewTarget; 
	char pad_46[0x2]; 
	float OrthoNearClipPlane; 
	float OrthoFarClipPlane; 
	float PerspectiveNearClipPlane; 
	float AspectRatio; 
	char pad_58[0x8]; 
	char bConstrainAspectRatio : 1; 
	char bUseFieldOfViewForLOD : 1; 
	char pad_60_2 : 6; 
	char pad_61[0x3]; 
	void* ProjectionMode; 
	char pad_65[0x3]; 
	float PostProcessBlendWeight; 
	char pad_6C[0x4]; 
	void* PostProcessSettings; 
	FVector2D OffCenterProjectionOffset; 
	char pad_770[0x90]; 
};

class UFortPlayerStateComponent_Habanero : public AActor
{
public:
	FRankedProgressReplicatedData GetRankedProgress()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortPlayerStateComponent_Habanero.GetRankedProgress");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			FRankedProgressReplicatedData ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}
};


enum class EFortCustomGender : uint8 {
	Invalid = 0,
	Male = 1,
	Female = 2,
	Both = 3,
	EFortCustomGender_MAX = 4
};

class AFortPlayerStateAthena : public AActor
{
public:

	bool bThankedBusDriver()
	{
		return *(char*)(this + Offsets::ExploitOffsets::bThankedBusDriver);
	}

	int32_t SeasonLevelUIDisplay()
	{
		return *(int32_t*)(this + 0x1228);
	}

	int32_t GetKillScore()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortPlayerStateAthena.GetKillScore");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			int32_t ReturnValue;
		} Params;

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}
};



struct AFortClientOnlyActor : AActor
{
	char pad_290[0x8]; 
};



struct UCurveTable : UObject {
	char pad_28[0x78]; 
};

struct FCurveTableRowHandle {
	struct UCurveTable* CurveTable; 
	struct FName RowName; 
	char pad_C[0x4]; 
};



struct AFortTracerBase : AFortClientOnlyActor
{
	struct UMovementComp_Tracer* TracerMovementComponent; 
	struct UStaticMeshComponent* TracerMesh; 
	struct UBulletWhipTrackerComponentBase* BulletWhipTrackerComponent; 
	struct FCurveTableRowHandle Speed; 
	float SpeedScaleMinRange; 
	float SpeedScaleMaxRange; 
	float SpeedScaleMinMultiplier; 
	float SpeedScaleMaxMultiplier; 
	struct FVector MeshScaleMult; 
	float MeshScaleTime; 
	char pad_2EC[0x4]; 
	struct UBulletWhipTrackerComponentBase* BulletWhipTrackerComponentClass; 
	char bScaleOnDeath : 1; 
	char bScaleSpeed : 1; 
	char bScaledUp : 1; 
	char bDead : 1; 
	char bOwnedByPool : 1; 
	char pad_2F8_5 : 3; 
	char pad_2F9[0x67]; 
	float currentScale; 
	char pad_364[0xc]; 

	
	void Init(struct FVector& Start, struct FVector& End)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortTracerBase.Init");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			FVector& Start;
			FVector& End;
		} Params = { Start, End };

		if (Function)
		{
			this->ProcessEvent(Function, &Params);

			if (Params.Start)
			{
				Start = Params.Start;
			}

			if (Params.End)
			{
				End = Params.End;
			}
		}
	}

};

class AFortPlayerState : public AFortPlayerStateAthena
{
public:
	UFortPlayerStateComponent_Habanero* HabaneroComponent()
	{
		return *(UFortPlayerStateComponent_Habanero**)(this + 0xa10);
	}

	FString GetRankStr() {
		FString rankStr = L"Unranked";
		auto HC = this->HabaneroComponent(); 
		if (HC)
		{
			int32_t RankProgress = HC->GetRankedProgress().Rank; 
			if (RankProgress >= 0 && RankProgress < 18) 
			{
				static const FString ranks[] = 
				{
					FString(L"Bronze 1"),
					FString(L"Bronze 2"),
					FString(L"Bronze 3"),
					FString(L"Silver 1"),
					FString(L"Silver 2"),
					FString(L"Silver 3"),
					FString(L"Gold 1"),
					FString(L"Gold 2"),
					FString(L"Gold 3"),
					FString(L"Platinum 1"),
					FString(L"Platinum 2"),
					FString(L"Platinum 3"),
					FString(L"Diamond 1"),
					FString(L"Diamond 2"),
					FString(L"Diamond 3"),
					FString(L"Elite"),
					FString(L"Champion"),
					FString(L"Unreal"),
					FString(L"Unranked")
				};

				rankStr = ranks[RankProgress];
			}
			else
			{
				rankStr = FString(L"Unranked");
			}
		}
		else
		{
			return FString(L'\0');
		}
		return rankStr;
	}

	FString GetPlatformSDK()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortPlayerState.GetPlatform");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct {
			FString ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);
		if (Params.ReturnValue)
		{
			return Params.ReturnValue;
		}

		return FString(L"BOT/AI");
	}

	FString GetPlatform()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortPlayerState.GetPlatform");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			FString ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}
};

class AFortPlayerStateZone : public AFortPlayerState
{
public:
	int32_t GetSpectatorCount()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortPlayerStateZone.GetSpectatorCount");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			int32_t ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	void GetHealthAndShields(float& Health, float& HealthMax, float& Shield, float& ShieldMax)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortPlayerStateZone.GetHealthAndShields");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			float Health;
			float HealthMax;
			float Shield;
			float ShieldMax;

		} Params = { };

		this->ProcessEvent(Function, &Params);

		Health = Params.Health;
		HealthMax = Params.HealthMax;
		Shield = Params.Shield;
		ShieldMax = Params.ShieldMax;

	}
};

class APlayerState : public AFortPlayerStateZone
{
public:

	FString GetPlatform()
	{
		if (this + 0x3f0)
		{
			FString PlatformItem = *(FString*)(this + 0x3f0);
			if (PlatformItem)
			{
				if (PlatformItem.c_str())
				{
					return *(FString*)(this + 0x3f0);
				}
				else
				{
					return L"BOT/AI";
				}
			}
		}

		return L"BOT/AI";
	}

	EFortCustomGender GetCharacterGender()
	{
		return static_cast<EFortCustomGender>(*(uint8_t*)(this + Offsets::ExploitOffsets::CharacterGender));
	}


	void GetPlayerNameGayMethod(AActor* AcknowledgedPawn, wchar_t* PlayerName)
	{
		uint64_t FTextOut = 0;
		uint32_t Length = 0;

		if (!AcknowledgedPawn)
		{
			
			if (this)
			{
				Length = *(uint32_t*)(this + 0x328);
				FTextOut = *(uint64_t*)(this + 0x328);
			}
		}
		else
		{
			
			if (this)
			{
				uint64_t fstring = *(uint64_t*)(this + 0xAA8); 
				if (fstring)
				{
					Length = *(uint32_t*)(fstring + 16);
					FTextOut = *(uint64_t*)(fstring + 8);
				}
				else
				{
					Length = 0;
					FTextOut = 0;
				}
			}
		}

		
		if (PlayerName && FTextOut) 
		{
			NoCRT::__memcpy(PlayerName, (void*)FTextOut, Length * sizeof(wchar_t)); 
		}
		else
		{
			
			if (PlayerName) 
			{
				*PlayerName = FString(L"NPC/Bot"); 
			}
			return;
		}

		auto v6 = Length;
		if (!v6)
		{
			if (PlayerName)
			{
				*PlayerName = FString(L"NPC/Bot");
			}
			return;
		}

		char v21; 
		int v22;
		int i;

		int v25;
		WindowsAPI::UINT16* v23;

		v21 = v6 - 1;
		if (!(WindowsAPI::UINT32)v6) 
			v21 = 0;
		v22 = 0;
		v23 = (WindowsAPI::UINT16*)PlayerName;
		for (i = (v21) & 3; ; *v23++ += i & 7)
		{
			v25 = v6 - 1;
			if (!(WindowsAPI::UINT32)v6) 
				v25 = 0;
			if (v22 >= v25)
				break;
			i += 3;
			++v22;
		}
	}

	FString GetPlayerName()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"PlayerState.GetPlayerName");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			FString ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;




	}
	

	bool IsABot()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"PlayerState.IsABot");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			FString ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}
};

class UMaterialInterface : public UObject
{
public:
	void* GetMaterial() 
	{
		if (auto VTable = *(void***)this)
		{
			int GetMaterial = 0x2D0 / 0x8;

			return reinterpret_cast<void*>(reinterpret_cast<void* (__cdecl*)(UMaterialInterface*)>(VTable[GetMaterial])(this)); 
		}

		return nullptr;
	}
};

class UMaterial : public UMaterialInterface
{
public:

	void SetBlendMode(EBlendMode Value)
	{
		*(EBlendMode*)(this + 0x129) = Value;
	}

	void SetbDisableDepthTest(bool Value)
	{
		char bDisableDepthTest = *(BYTE*)(this + Offsets::ExploitOffsets::bDisableDepthTest);
		bDisableDepthTest |= (Value << 0);
		*(BYTE*)(this + Offsets::ExploitOffsets::bDisableDepthTest) = bDisableDepthTest;
	}

	void SetWireframe(bool Value)
	{
		char Wireframe = *(BYTE*)(this + Offsets::ExploitOffsets::Wireframe);
		Wireframe |= (Value << 6);
		*(BYTE*)(this + Offsets::ExploitOffsets::Wireframe) = Wireframe;
	}
};

class UMaterialInstance : public UMaterialInterface
{
	
};


class UMaterialInstanceDynamic : public UMaterialInstance
{
public:
	void SetVectorParameterValue(FName ParameterName, FLinearColor& Value)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"MaterialInstanceDynamic.SetVectorParameterValue");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			FName ParameterName;
			FLinearColor Value;
		} Params = { };

		Params.ParameterName = ParameterName;
		Params.Value = Value;

		this->ProcessEvent(Function, &Params);
	}

	FLinearColor K2_GetVectorParameterValue(FName ParameterName)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"MaterialInstanceDynamic.K2_GetVectorParameterValue");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			FName ParameterName;
			FLinearColor ReturnValue;
		} Params = { ParameterName };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	void SetScalarParameterValue(FName ParameterName, float Value)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"MaterialInstanceDynamic.SetScalarParameterValue");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			FName ParameterName;
			float Value;
		} Params = { };

		Params.ParameterName = ParameterName;
		Params.Value = Value;

		this->ProcessEvent(Function, &Params);
	}

	float K2_GetScalarParameterValue(FName ParameterName)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"MaterialInstanceDynamic.K2_GetScalarParameterValue");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			FName ParameterName;
			float ReturnValue;
		} Params = { ParameterName };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}
};

class UPrimitiveComponent : public UObject
{
public:
	void SetCustomDepthStencilValue(int Value)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"PrimitiveComponent.SetCustomDepthStencilValue");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			int Value;
		} Params = { Value };

		this->ProcessEvent(Function, &Params);
	}

	void SetRenderCustomDepth(bool bValue)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"PrimitiveComponent.SetRenderCustomDepth");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			bool bValue;
		} Params = { bValue };

		this->ProcessEvent(Function, &Params);
	}

	UMaterialInstanceDynamic* CreateDynamicMaterialInstance(int32 ElementIndex, UMaterialInterface* Parent, FName OptionalName)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"PrimitiveComponent.CreateDynamicMaterialInstance");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			int32 ElementIndex;
			UMaterialInterface* Parent;
			FName OptionalName;
			UMaterialInstanceDynamic* ReturnValue;
		} Params = { ElementIndex, Parent, OptionalName };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	void SetMaterial(int32_t ElementIndex, UMaterialInterface* Material)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"PrimitiveComponent.SetMaterial");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			int32_t ElementIndex;
			UMaterialInterface* Material;
		} Params = { ElementIndex, Material };

		this->ProcessEvent(Function, &Params);
	}

	UMaterialInterface* GetMaterial(int32_t ElementIndex)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"PrimitiveComponent.GetMaterial");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			int32_t ElementIndex;
			UMaterialInterface* ReturnValue;
		} Params = { ElementIndex };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}
};

class USceneComponent : public UPrimitiveComponent
{
public:
	FVector GetSocketLocation(FName InSocketName)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"SceneComponent.GetSocketLocation");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			FName InSocketName;
			FVector ReturnValue;
		} Params{ InSocketName };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	FVector GetForwardVector()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"SceneComponent.GetForwardVector");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			FVector ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	FVector K2_GetComponentLocation()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"SceneComponent.K2_GetComponentLocation");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			FVector ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}
};

class UMeshComponent : public USceneComponent
{
public:
	TArray<UMaterialInterface*> GetMaterials()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"MeshComponent.GetMaterials");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			TArray<UMaterialInterface*> ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}
};

class UStaticMeshComponent : public UMeshComponent
{
public:

};

class USkinnedMeshComponent : public UStaticMeshComponent
{
public:
	FName GetBoneName(int32 BoneIndex)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"SkinnedMeshComponent.GetBoneName");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			int32 BoneIndex;
			FName ReturnValue;
		} Params{ BoneIndex };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	int GetNumBones()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"SkinnedMeshComponent.GetNumBones");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			int ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}
};

class USkeletalMeshComponent : public USkinnedMeshComponent
{
public:
	void SetGlobalAnimRateScale(float Value)
	{

		*(float*)(this + Offsets::ExploitOffsets::GlobalAnimRateScale) = Value;
	}


	FVector GetBoneLocation(int BoneID)
	{
		return this->GetSocketLocation(this->GetBoneName(BoneID));
	}
};

class UItemDefinitionBase : public UObject
{
public:
	FText ItemName()
	{
		return *(FText*)(this + 0x40);
	}
};

class AFortLightweightProjectileConfig : public AActor
{
public:

};

class AFortLightweightProjectileManager : public UObject
{
public:

};




enum class EFortWeaponTriggerType : uint8_t
{
	OnPress = 0,
	Automatic = 1,
	OnRelease = 2,
	OnPressAndRelease = 3,
	Custom = 4,
	EFortWeaponTriggerType_MAX = 5
};

class UFortItemDefinition : public UItemDefinitionBase
{
public:
	
	
	
	
	
	EFortRarity GetRarity()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortItemDefinition.GetRarity");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			EFortRarity ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	EFortRarity Rarity()
	{
		return this->GetRarity();
		
	}

	TSoftObjectPtr<UTexture2D> GetSmallPreviewImage()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortItemDefinition.GetSmallPreviewImage");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			TSoftObjectPtr<UTexture2D> ReturnValue;
		} Params = { true };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}
};

class UFortWeaponRangedItemDefinition : public UFortItemDefinition
{
public:

	bool ShouldUsePerfectAimWhenTargetingMinSpread()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortWeaponRangedItemDefinition.ShouldUsePerfectAimWhenTargetingMinSpread");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			float ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;

		return 0.f;
	}

	bool HasLightweightProjectile()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortWeaponRangedItemDefinition.HasLightweightProjectile");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			bool ReturnValue;
		} Params = { true };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}
};

class UFortWeaponItemDefinition : public UFortWeaponRangedItemDefinition
{
public:
	

	EFortWeaponTriggerType GetTriggerType()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortWeaponItemDefinition.GetTriggerType");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		if (Function)
		{
			struct
			{
				EFortWeaponTriggerType ReturnValue;
			} Params;

			this->ProcessEvent(Function, &Params);

			return Params.ReturnValue;
		}

		return EFortWeaponTriggerType::EFortWeaponTriggerType_MAX; 
	}
};

class FFortBaseWeaponStats : public UObject
{
public:

};


enum class EFortWeaponOverheatState : uint8 {
	None = 0,
	Heating = 1,
	Cooling = 2,
	Overheated = 3,
	EFortWeaponOverheatState_MAX = 4
};


class AFortWeapon : public AActor
{
public:
	float GetProjectileGravity()
	{
		return *(float*)(this + 0x1CE4);
	}

	float GetProjectileSpeed()
	{
		return *(float*)(this + 0x1A78);
	}

	
	
	
	UFortWeaponItemDefinition* GetWeaponData()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortWeapon.GetWeaponData");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			UFortWeaponItemDefinition* ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	void SetTraceThroughPawnsLimit(int32_t NewTraceThroughPawnsLimit)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortWeapon.SetTraceThroughPawnsLimit");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			int32_t NewTraceThroughPawnsLimit;
		} Params = { NewTraceThroughPawnsLimit };

		this->ProcessEvent(Function, &Params);
	}

	void SetTraceThroughPawns(bool bNewTraceThroughPawns)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortWeapon.SetTraceThroughPawns");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			bool bNewTraceThroughPawns;
		} Params = { bNewTraceThroughPawns };

		this->ProcessEvent(Function, &Params);
	}
	
	
	

	void SetTraceThroughLandscapeLimit(int32_t NewTraceThroughTerrainLimit)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortWeapon.SetTraceThroughLandscapeLimit");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			int32_t NewTraceThroughTerrainLimit;
		} Params = { NewTraceThroughTerrainLimit };

		this->ProcessEvent(Function, &Params);
	}

	void SetTraceThroughBuildingsLimit(int32_t NewTraceThroughBuildingsLimit)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortWeapon.SetTraceThroughBuildingsLimit");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			int32_t NewTraceThroughBuildingsLimit;
		} Params = { NewTraceThroughBuildingsLimit };

		this->ProcessEvent(Function, &Params);
	}

	UFortWeaponItemDefinition* WeaponData()
	{
		return *(UFortWeaponItemDefinition**)(this + Offsets::ExploitOffsets::WeaponData);
	}

	EFortWeaponCoreAnimation WeaponCoreAnimation()
	{
		return *(EFortWeaponCoreAnimation*)(this + 0x5cc);
	}

	

	

	float GetTimeToNextFire()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortWeapon.GetTimeToNextFire");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			float ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}
	
	

	


	

	

	EFortWeaponOverheatState GetOverheatState()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortWeapon.GetChargePercent");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			EFortWeaponOverheatState ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	
	bool GetIsChargingWeapon()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortWeapon.GetIsChargingWeapon");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			bool ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	bool DoesWeaponOverheat()
	{

		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortWeaponRanged.DoesWeaponOverheat");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			bool ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	bool IsProjectileWeapon()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortWeapon.IsProjectileWeapon");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			bool ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}


	

	
	AFortTracerBase* GetTracerTemplate()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortWeaponRanged.GetTracerTemplate");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			AFortTracerBase* ReturnValue;
		} Params = { };


		this->ProcessEvent(Function, &Params);
		return Params.ReturnValue;
	}

	void SetUseTracers(bool bNewUseTracers)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortWeaponRanged.SetUseTracers");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			bool bNewUseTracers;
		} Params = { bNewUseTracers };

		if (Function)
		{
			this->ProcessEvent(Function, &Params);
		}
	}
	
	
	
	
	float GetCurrentOverheatValue()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortWeaponRanged.GetCurrentOverheatValue");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			float ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	float GetCurrentSpreadInDegrees()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortWeaponRanged.GetCurrentSpreadInDegrees");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			float ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	float GetCurrentReticleSpreadMultiplier()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortWeaponRanged.GetCurrentReticleSpreadMultiplier");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			float ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	float GetCalculatedReticleSpread()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortWeaponRanged.GetCalculatedReticleSpread");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			float ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	float GetMaxAdditionalPatternSpreadDegrees()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortWeaponRanged.GetMaxAdditionalPatternSpreadDegrees");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			float ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	float ReticleSpreadZeroingDistanceFromMuzzle()
	{
		if (this)
		{
			return *(float*)(this + Offsets::ExploitOffsets::ReticleSpreadZeroingDistanceFromMuzzle);
		}

		return 0.f;
	}

	float FirstShotAccuracyMinWaitTime()
	{
		if (this)
		{
			return *(float*)(this + Offsets::ExploitOffsets::FirstShotAccuracyMinWaitTime);
		}

		return 0.f;
	}

	int32_t BulletCountForPerBulletRecoil()
	{
		if (this)
		{
			return *(int32_t*)(this + Offsets::ExploitOffsets::BulletCountForPerBulletRecoil);
		}

		return 0.f;
	}

	float BulletCountForPerBulletSpread()
	{
		if (this)
		{
			return *(float*)(this + Offsets::ExploitOffsets::BulletCountForPerBulletSpread);
		}

		return 0.f;
	}

	float TimeRemainingForBulletSpread()
	{
		if (this)
		{
			return *(float*)(this + Offsets::ExploitOffsets::TimeRemainingForBulletSpread);
		}

		return 0.f;
	}

	bool bUseOverrideBaseSpread()
	{
		if (this)
		{
			return *(float*)(this + Offsets::ExploitOffsets::bUseOverrideBaseSpread);
		}

		return 0.f;
	}

	bool bUseOverrideSpreadDownsightsMultiplier()
	{
		if (this)
		{
			return *(float*)(this + Offsets::ExploitOffsets::bUseOverrideSpreadDownsightsMultiplier + 0x1);
		}

		return 0.f;
	}

	bool bReticleCornerOutsideSpreadRadius()
	{
		if (this)
		{
			return *(float*)(this + Offsets::ExploitOffsets::bReticleCornerOutsideSpreadRadius + 0x1);
		}

		return 0.f;
	}


	bool bShouldUsePerfectAimWhenTargetingMinSpread()
	{
		if (this)
		{
			return *(float*)(this + Offsets::ExploitOffsets::bShouldUsePerfectAimWhenTargetingMinSpread);
		}

		return 0.f;
	}

	/*
	float GetCurrentSpreadInDegrees(); 
	float GetCurrentReticleSpreadMultiplier(); 
	float GetCurrentOverheatValue(); 
	float GetCalculatedReticleSpread(); 
	float GetMaxAdditionalPatternSpreadDegrees(); 
	void SetUseTracers(bool bNewUseTracers); 
	void SetUseShellsParticles(bool bNewUseShellsParticles); 
	void SetUseOverrideSpreadDownsightsMultiplier(bool bUseOverride); 
	void SetUseOverrideBaseSpread(bool bUseOverride); 
	void SetUseImpactDecals(bool bNewUseImpactDecals); 
	void SetUseBeamParticles(bool bNewUseBeamParticles); 

	float ReticleSpreadZeroingDistanceFromMuzzle; 
	float FirstShotAccuracyMinWaitTime; 
	int32_t BulletCountForPerBulletRecoil; 
	float BulletCountForPerBulletSpread; 
	float TimeRemainingForBulletSpread; 

	char bUseImpactDecals : 1; 
	char bUsePersistentBeam : 1; 
	char bUseShellsParticles : 1; 
	char bUseTracers : 1; 
	char bUseOverrideBaseSpread : 1; 
	char bUseOverrideSpreadDownsightsMultiplier : 1; 
	char pad_1829_3 : 2; 

	char bReticleCornerOutsideSpreadRadius : 1; 
	char bShouldUsePerfectAimWhenTargetingMinSpread : 1; 
	bool ShouldUsePerfectAimWhenTargetingMinSpread(); 
	*/

	bool IsOverheated()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortWeaponRanged.IsOverheated");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			bool ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	float GetChargePercent()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortWeaponRanged.GetChargePercent");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			float ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	float GetChargeTime()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortWeapon.GetChargeTime");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			float ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	float GetOverheatingMaxValue()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortWeaponRanged.GetOverheatingMaxValue");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			float ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}


	
	FColor GetReticleColor()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortWeapon.GetReticleColor");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			FColor ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	

	bool IsTargeting()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortWeapon.IsTargeting");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			bool ReturnValue;
		} Params = { true };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	
	void SetTargeting(bool bNewIsTargeting)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortWeapon.SetTargeting");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			float ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);
	}

	
	FLinearColor GetReticleColorAsLinear()
	{
		if (this) {
			FLinearColor Color = ToLinearColor(this->GetReticleColor());

			return Color;
		}
		return FLinearColor(0.f, 0.f, 0.f, 0.f);
	}

	void SetPrimaryFireSound1P(USoundBase* Value)
	{
		*(USoundBase**)(this + 0x8d8) = Value;
	}

	void SetImpactPhysicalSurfaceSounds(USoundBase* Value)
	{
		for (int32_t i = 0x0; i < 0x23; i++)
		{
			*(USoundBase**)(this + 0x998 + (i * 0x8)) = Value;
		}
	}

	void SetTargetingStartSound(USoundBase* Value)
	{
		*(USoundBase**)(this + 0x978) = Value;
	}

	void SetTargetingEndSound(USoundBase* Value)
	{
		*(USoundBase**)(this + 0x980) = Value;
	}

	void SetPrimaryFireStopSound1P(USoundBase* Value)
	{
		*(USoundBase**)(this + 0x8f8) = Value;
	}

	void SetPrimaryFireSound(USoundBase* Value)
	{
		for (int32_t i = 0x0; i < 0x3; i++)
		{
			*(USoundBase**)(this + 0x8e0 + (i * 0x8)) = Value;
		}
	}

	void SetPrimaryFireStopSound(USoundBase* Value)
	{
		for (int32_t i = 0x0; i < 0x3; i++)
		{
			*(USoundBase**)(this + 0x900 + (i * 0x8)) = Value;
		}
	}

	void SetSecondaryFireSound(USoundBase* Value)
	{
		for (int32_t i = 0x0; i < 0x3; i++)
		{
			*(USoundBase**)(this + 0x918 + (i * 0x8)) = Value;
		}
	}

	void SetChargeFireSound1P(USoundBase* Value)
	{
		for (int32_t i = 0x0; i < 0x3; i++)
		{
			*(USoundBase**)(this + 0x948 + (i * 0x8)) = Value;
		}
	}

	void SetChargeFireSound(USoundBase* Value)
	{
		for (int32_t i = 0x0; i < 0x3; i++)
		{
			*(USoundBase**)(this + 0x960 + (i * 0x8)) = Value;
		}
	}

	void SetSecondaryFireStopSound(USoundBase* Value)
	{
		for (int32_t i = 0x0; i < 0x3; i++)
		{
			*(USoundBase**)(this + 0x930 + (i * 0x8)) = Value;
		}
	}

	FVector GetTargetingSourceLocation()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortWeapon.GetTargetingSourceLocation");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			FVector ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	void EnableAltCenterReticle(bool bNewEnabled)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortWeaponRanged.EnableAltCenterReticle");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			bool bNewEnabled;
		} Params = { bNewEnabled };

		this->ProcessEvent(Function, &Params);
	}

	void EnableAltOuterReticle(bool bNewEnabled)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortWeaponRanged.EnableAltOuterReticle");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			bool bNewEnabled;
		} Params = { bNewEnabled };

		this->ProcessEvent(Function, &Params);
	}

	void EnableCornersReticle(bool bNewEnabled)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortWeaponRanged.EnableCornersReticle");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			bool bNewEnabled;
		} Params = { bNewEnabled };

		this->ProcessEvent(Function, &Params);
	}

	bool CanFire()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortWeapon.CanFire");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			bool bPrimaryFire;
			bool ReturnValue;
		} Params = { true };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	FVector GetMuzzleLocation()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortWeapon.GetMuzzleLocation");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			int PatternIndex;
			FVector ReturnValue;
		} Params{ 0 };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	int GetBulletsPerClip()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortWeapon.GetBulletsPerClip");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			int ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}
	
	

	void SetIsReloadingWeapon(bool bReloading = false)
	{
		
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortWeapon.SetIsReloadingWeapon");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			bool bReloading;
		} Params = { };

		this->ProcessEvent(Function, &Params);
	}

	bool IsReloading()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortWeapon.IsReloading");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			bool ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	int GetMagazineAmmoCount()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortWeapon.GetMagazineAmmoCount");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			int ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	int GetRemainingAmmo()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortWeapon.GetRemainingAmmo");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			int ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}
};











class UFortVehicleFuelComponent : public AActor
{
public:
	void SetServerFuel(float Value)
	{
		*(float*)(this + Offsets::ExploitOffsets::ServerFuel) = Value;
	}

	void SetInfiniteFuel(float Value)
	{
		*(float*)(this + 0x280) = Value;
	}

	float GetFuelCapacity()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortVehicleFuelComponent.GetFuelCapacity");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			float ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}
};

class UFortPhysicsVehicleConfigs : public AActor
{
public:
	void SetDragCoefficient2(float Value)
	{
		*(float*)(this + Offsets::ExploitOffsets::DragCoefficient2) = Value;
	}
};

class AFortAthenaVehicle : public AActor
{
public:
	UFortVehicleFuelComponent* CachedFuelComponent()
	{
		return *(UFortVehicleFuelComponent**)(this + Offsets::ExploitOffsets::CachedFuelComponent);
	}


	

	FString GetDisplayName()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortAthenaVehicle.GetDisplayName");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct {
			FString ReturnValue;
		} Params = { };


		this->ProcessEvent(Function, &Params);
		return Params.ReturnValue;
	}

	UFortPhysicsVehicleConfigs* FortPhysicsVehicleConfigs()
	{
		return *(UFortPhysicsVehicleConfigs**)(this + Offsets::ExploitOffsets::FortPhysicsVehicleConfigs);
	}

	bool SetVehicleStencilHighlighted(AActor* PotentialVehicle, bool bHighlighted, int32_t StencilValueOverride)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortAthenaVehicle.SetVehicleStencilHighlighted");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			AActor* PotentialVehicle;
			bool bHighlighted;
			int32_t StencilValueOverride;
			bool ReturnValue;
		} Params = { PotentialVehicle, bHighlighted, StencilValueOverride };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	float GetSteeringAngle()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortAthenaVehicle.GetSteeringAngle");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			float ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	bool CanContainPlayers()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortAthenaVehicle.CanContainPlayers");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			bool ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	float GetHealth()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortAthenaVehicle.GetHealth");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			float ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	float GetMaxHealth()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortAthenaVehicle.GetMaxHealth");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			float ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}
};

class APawn : public AActor
{
public:
	USceneComponent* RootComponent()
	{
		return *(USceneComponent**)(this + 0x1b0);
	}

	APlayerState* PlayerState()
	{
		return *(APlayerState**)(this + 0x2c8);
	}

	void AddMovementInput(FVector WorldDirection, float ScaleValue, bool bForce)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"Pawn.AddMovementInput");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			FVector& WorldDirection;
			float ScaleValue;
			bool bForce;
		} Params = { WorldDirection, ScaleValue, bForce };

		this->ProcessEvent(Function, &Params);
	}
};

class ACharacter : public APawn
{
public:
	USkeletalMeshComponent* Mesh()
	{
		return *(USkeletalMeshComponent**)(this + 0x328);
	}
	

	
	
	

	void Jump()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"Character.Jump");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{

		} Params = { };

		this->ProcessEvent(Function, &Params);
	}

	bool CanCrouch()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"Character.CanCrouch");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			bool ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	bool CanJump()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"Character.CanJump");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			bool ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}
};

class AFortPawn : public ACharacter
{
public:

	AFortWeapon* CurrentWeapon()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortPawn.GetCurrentWeapon");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			AFortWeapon* ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;

		
		
	}

	AFortWeapon* CurrentWeaponGay()
	{
		return *(AFortWeapon**)(this + Offsets::ExploitOffsets::CurrentWeapon);
	}

	void PrototypeCharacterMovement(EMovementMode MovementMode, FVector LaunchVelocity)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortPawn.PrototypeCharacterMovement");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			EMovementMode MovementMode;
			FVector& LaunchVelocity;
		} Params = { MovementMode, LaunchVelocity };

		this->ProcessEvent(Function, &Params);
	}

	float GetHealth()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortPawn.GetHealth");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			float ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	float GetShield()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortPawn.GetShield");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			float ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	TArray<AFortWeapon*> GetCurrentWeaponList()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortPawn.GetCurrentWeaponList");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			TArray<AFortWeapon*> ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	bool IsDead()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortPawn.IsDead");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			bool ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}
	
	
	

	bool bIsJumping()
	{
		if (this)
		{
			return *(bool*)(this + Offsets::ExploitOffsets::bIsJumping);
		}

		return false;
	}

	bool bIsSliding()
	{
		if (this)
		{
			return *(bool*)(this + Offsets::ExploitOffsets::bIsSliding + 0x3); 
		}

		return false;
	}

	bool IsSlidingEnabled()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortPawn.IsSlidingEnabled");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			bool ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	bool IsDBNO()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortPawn.IsDBNO");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			bool ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	char GetTeam()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortPawn.GetTeam");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			char ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	void PawnStartFire()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortPawn.PawnStartFire");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			char FireModeNum;
		} Params = { 1 };

		this->ProcessEvent(Function, &Params);
	}

	void PawnStopFire()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortPawn.PawnStopFire");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			char FireModeNum;
		} Params = { 1 };

		this->ProcessEvent(Function, &Params);
	}
};

class AFortAIPawn : public AFortPawn
{
public:
	void ResetAIRotationRateToDefault()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortAIPawn.ResetAIRotationRateToDefault");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{

		} Params = { };

		this->ProcessEvent(Function, &Params);
	}

	void SetCanInteract(bool CanInteract)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortAIPawn.SetCanInteract");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			bool CanInteract;
		} Params = { CanInteract };

		this->ProcessEvent(Function, &Params);
	}

	void SetCanSleep(bool InCanSleep)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortAIPawn.SetCanSleep");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			bool InCanSleep;
		} Params = { InCanSleep };

		this->ProcessEvent(Function, &Params);
	}
};


class AFortPlayerPawn : public AFortPawn
{
public:
	AFortAthenaVehicle* CurrentVehicle()
	{
		return *(AFortAthenaVehicle**)(this + Offsets::ExploitOffsets::CurrentVehicle); 
	}

	

	void OnTacticalSprintStarted()
	{
		static UObject* Function;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortPlayerPawn.OnTacticalSprintStarted");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{

		} Params = { };

		if (Function)
		{
			this->ProcessEvent(Function, &Params);
		}
	}

	bool IsPassengerInVehicle()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortPlayerPawn.IsPassengerInVehicle");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			bool ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	bool IsParachuteOpen()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortPlayerPawn.IsParachuteOpen");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			bool ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	bool IsParachuteOpenAndVisible()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortPlayerPawn.IsParachuteOpenAndVisible");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			bool ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}
	
	
	
	float GetMaxStamina()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortPlayerPawn.GetMaxStamina");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			float ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	


	float GetStamina()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortPlayerPawn.GetStamina");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			float ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	bool IsInVehicle()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortPlayerPawn.IsInVehicle");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			bool ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	

	AActor* GetVehicleActor()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortPlayerPawn.GetVehicleActor");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			AActor* ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}
	

	EFortCustomGender GetCharacterGender()
	{

		if (this)
		{
			if (APlayerState* PlayerState = this->PlayerState())
			{
				return PlayerState->GetCharacterGender();
			}
		}

		return EFortCustomGender::Invalid;
	}

	

	bool GetHeroDisplayNameStringSDK(FString& HeroDisplayName)
	{

		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortPlayerPawn.GetHeroDisplayNameString");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			FString ReturnValue;
		} Params = { };

		if (Function)
		{
			this->ProcessEvent(Function, &Params);

			HeroDisplayName = Params.ReturnValue;
			return true;
		}

		return false;
	}

	bool GetHeroDisplayNameString(FString& HeroName)
	{

		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortPlayerPawn.GetHeroDisplayNameString");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			FString HeroName;
			bool ReturnValue;
		} Params;

		if (Function)
		{
			this->ProcessEvent(Function, &Params);
			if (Params.ReturnValue)
			{
				HeroName = Params.HeroName;
				return Params.ReturnValue;
			}
		}

		return (FString)L"Error";
	}

	bool IsCharacterFemale()
	{
		if (this)
		{
			return (this->GetCharacterGender() == EFortCustomGender::Female);
		}

		return false;
	}


	bool IsDrivingVehicle()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortPlayerPawn.IsDrivingVehicle");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			bool ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	

	
	void SetCrouch(bool bNewValue, bool bUseActionOnHoldInput = false)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortPlayerPawn.SetCrouch");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			bool bNewValue;
			bool bUseActionOnHoldInput;
		} Params = { bNewValue, bUseActionOnHoldInput };

		this->ProcessEvent(Function, &Params);
	}

	bool IsSprinting()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortPlayerPawn.IsSprinting");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			bool ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}


	bool IsSkyDiving()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortPlayerPawn.IsSkyDiving");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			bool ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	bool IsSkydivingFromBus()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortPlayerPawn.IsSkydivingFromBus");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			bool ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}
};

struct FPawnHighlight                                                                                           
{
	float                                              Priority_28_E2E1B5344846E187B9C11B863A7F0698;             
	FLinearColor                                Inner_21_4CC2801147EA190DE16F59B34F36853E;                
	FLinearColor                                Outer_22_5A1D7D0543D303E8B54B66A7F7BD2E2E;                
	float                                              FresnelBrightness_23_52B0F96447FF640F47DF2895B0602E92;    
	float                                              FresnelExponent_24_B427CF0C441AA37ED49833BF7579DE6D;      
	float                                              UsesPulse_25_E29229F64E540F0617E4C4987AD77605;            
};

class AFortPlayerPawnAthena : public AFortPlayerPawn
{
public:
	void ApplyPawnHighlight(FLinearColor InnerCol, FLinearColor OuterCol)
	{


		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"PlayerPawn_Athena_C.ApplyPawnHighlight");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		
		struct APlayerPawn_Athena_C_ApplyPawnHighlight_Params
		{
			uintptr_t Source; 
			FPawnHighlight HitGlow; 
		} params;

		FPawnHighlight HitGlow;

		HitGlow.FresnelBrightness_23_52B0F96447FF640F47DF2895B0602E92 = 0.f;
		HitGlow.FresnelExponent_24_B427CF0C441AA37ED49833BF7579DE6D = 0;
		HitGlow.Inner_21_4CC2801147EA190DE16F59B34F36853E = { (float)InnerCol.R, (float)InnerCol.G, (float)InnerCol.B, (float)InnerCol.A };
		HitGlow.Outer_22_5A1D7D0543D303E8B54B66A7F7BD2E2E = { (float)OuterCol.R, (float)OuterCol.G, (float)OuterCol.B, (float)OuterCol.A };
		HitGlow.Priority_28_E2E1B5344846E187B9C11B863A7F0698 = 0.f;
		HitGlow.UsesPulse_25_E29229F64E540F0617E4C4987AD77605 = 0.f;


		params.Source = uintptr_t(this);
		params.HitGlow = HitGlow;

		this->ProcessEvent(Function, &params);

	}

	void SetAdsWhileNotOnGround(bool newValue)
	{
		if (this)
		{
			*(bool*)(this + Offsets::ExploitOffsets::bADSWhileNotOnGround) = newValue;
		}
	}

	void ResetAdsWhileNotOnGround()
	{
		if (this)
		{
			*(bool*)(this + Offsets::ExploitOffsets::bADSWhileNotOnGround) = false;
		}
	}

	bool GetAdsWhileNotOnGround()
	{
		if (this)
		{
			return (*(bool*)(this + Offsets::ExploitOffsets::bADSWhileNotOnGround));
		}

		return false;
	}
};

class APlayerPawn_Athena_Generic_Parent_C : public AFortPlayerPawnAthena
{
public:
	TArray<USkeletalMeshComponent*> SkeletalMeshes()
	{
		return *(TArray<USkeletalMeshComponent*>*)(this + 0x5e30);
	}
};

class APlayerPawn_Athena_Generic_C : public APlayerPawn_Athena_Generic_Parent_C
{
public:
	TArray<UMaterialInstanceDynamic*> PawnMaterials_ALL()
	{
		
		
		return *(TArray<UMaterialInstanceDynamic*>*)(this + 0x5e40);
		

		
	}
};

class APlayerPawn_Athena_C : public APlayerPawn_Athena_Generic_C
{
public:
	

};

class ASpectatorPawn : public APlayerPawn_Athena_C
{
public:

};

class BGA_Athena_SCMachine_C : public AActor
{
public:

};

class AFortPickupEffect : public AActor
{
public:
	UStaticMeshComponent* StaticMesh()
	{
		return *(UStaticMeshComponent**)(this + 0x290);
	}
};

class AFortPlayerMarkerBase : public AActor
{
public:

};


class AFortPickup : public AActor
{
public:
	UFortItemDefinition* PrimaryPickupItemEntry()
	{
		return *(UFortItemDefinition**)(this + 0x348 + 0x18);
	}

	AFortPickupEffect* PickupEffectBlueprint()
	{
		return *(AFortPickupEffect**)(this + 0x5c0);
	}
};

class UBaseBuildingStaticMeshComponent : public UMeshComponent
{
public:

};

class ABuildingSMActor : public AActor
{
public:
	UBaseBuildingStaticMeshComponent* StaticMeshComponent()
	{
		return *(UBaseBuildingStaticMeshComponent**)(this + 0x8a0);
	}
};

struct BuildingContainer_Bitfield
{
	char bForceSpawnLootOnDestruction : 1;
	char bForceTossLootOnSpawn : 1;
	char bAlreadySearched : 1;
	char bGivePickupsDirectlyToPlayer : 1;
	char bDisableSpawnLoot : 1;
	char bDoNotDropLootOnDestruction : 1;
	char bSkipRollForDestruction : 1;
};

class ABuildingContainer : public ABuildingSMActor
{
public:
	bool bAlreadySearched()
	{
		BuildingContainer_Bitfield bAlreadySearched_Struct = *(BuildingContainer_Bitfield*)(this + 0xd9a);
		return bAlreadySearched_Struct.bAlreadySearched;
	}
};

struct BuildingWeakSpot_Bitfield
{
	char bHit : 1;
	char bFadeOut : 1;
	char bActive : 1;
};

class ABuildingWeakSpot : public AActor
{
public:
	bool bHit()
	{
		BuildingWeakSpot_Bitfield bHit_Struct = *(BuildingWeakSpot_Bitfield*)(this + 0x2c0);
		return bHit_Struct.bHit;
	}

	bool bActive()
	{
		BuildingWeakSpot_Bitfield bActive_Struct = *(BuildingWeakSpot_Bitfield*)(this + 0x2c0);
		return bActive_Struct.bActive;
	}
};

class AFortAthenaSupplyDrop : public AActor
{
public:

};

class ABuildingTrap : public AActor
{
public:
	float GetArmTime()
	{
		static UObject* Function;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"BuildingTrap.GetArmTime");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			float ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}
};

class AAthenaSuperDingo : public AActor
{
public:

};

class ABuildingActor : public AActor
{
public:
	EFortBuildingType BuildingType()
	{
		return *(EFortBuildingType*)(this + 0x4d5);
	}

	uint8 TeamIndex()
	{
		return *(uint8*)(this + 0x4d7);
	}

	bool IsPlayerBuilt()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"BuildingActor.IsPlayerBuilt");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			bool ReturnValue;
		} Params;

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	bool HasHealthLeft()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"BuildingActor.HasHealthLeft");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			bool ReturnValue;
		} Params;

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	void SetQuestHighlight(bool Enabled)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"BuildingActor.SetQuestHighlight");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			bool Enabled;
		} Params = { Enabled };

		this->ProcessEvent(Function, &Params);
	}

	void SetSuppressHealthBar(bool bNewValue)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"BuildingActor.SetSuppressHealthBar");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			bool bNewValue;
		} Params = { bNewValue };

		this->ProcessEvent(Function, &Params);
	}

	float GetHealth()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"BuildingActor.GetHealth");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			float ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	float GetMaxHealth()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"BuildingActor.GetMaxHealth");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			float ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	void ForceBuildingHealth(float NewHealth)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"BuildingActor.ForceBuildingHealth");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			float NewHealth;
		} Params = { NewHealth };

		this->ProcessEvent(Function, &Params);
	}

	void SetHealth(float NewHealth)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"BuildingActor.SetHealth");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			float NewHealth;
		} Params = { NewHealth };

		this->ProcessEvent(Function, &Params);
	}
};

class AController : public AActor
{
public:
	APlayerState* PlayerState()
	{
		return *(APlayerState**)(this + 0x298);
	}

	void SetIgnoreLookInput(bool bNewLookInput)
	{
		static UObject* Function;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"Controller.SetIgnoreLookInput");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			bool bNewLookInput;
		} Params = { bNewLookInput };

		this->ProcessEvent(Function, &Params);
	}
};

class AFortPlayerController : public AController
{
public:
	TArray<ABuildingActor*> HighlightedPrimaryBuildings()
	{
		return *(TArray<ABuildingActor*>*)(this + 0x18c8);
	}

	UFortRuntimeOptions* GetRuntimeOptions()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortRuntimeOptions.GetRuntimeOptions");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			UFortRuntimeOptions* ReturnValue;
		} Params = { };

		if (Function)
		{
			this->ProcessEvent(Function, &Params);
			return Params.ReturnValue;
		}
	}

	
	
	void ServerEmote(FName AssetName)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortPlayerController.ServerEmote");

			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			FName AssetName;
		} params = { AssetName };

		this->ProcessEvent(Function, &params);
	}

	FVector GetLocationUnderReticle()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortPlayerController.GetLocationUnderReticle");

			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			FVector ReturnValue;
		} params = { };

		this->ProcessEvent(Function, &params);

		return params.ReturnValue;
	}
};
class APlayerController : public AFortPlayerController
{
private:

	FText PlayerController_Conv_StringToText(FString InString)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"KismetTextLibrary.Conv_StringToText");

			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			FString InString;
			FText ReturnValue;
		} Params = { InString };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

public:
	void AddYawInput(float Val) {
		static UObject* Function;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"APlayerControllerController.AddYawInput");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			float Val;
		} Params = { Val };

		this->ProcessEvent(Function, &Params);
	}
	void AddRollInput(float Val) {
		static UObject* Function;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"APlayerControllerController.AddRollInput");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			float Val;
		} Params = { Val };

		this->ProcessEvent(Function, &Params);
	}
	void AddPitchInput(float Val) {
		static UObject* Function;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"APlayerControllerController.AddPitchInput");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			float Val;
		} Params = { Val };

		this->ProcessEvent(Function, &Params);
	}

	void ClientKickWithText(FString Reason)
	{
		if (this)
		{
			FText TextReason = this->PlayerController_Conv_StringToText(Reason);

			this->ClientReturnToMainMenuWithTextReason(TextReason);
		}
	}

	void ClientReturnToMainMenuWithTextReason(FText ReturnReason)
	{
		static UObject* Function;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"APlayerControllerController.ClientReturnToMainMenuWithTextReason");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();

			if (!Function)
			{
				auto Enc_Function2 = Encrypt(L"PlayerController.ClientReturnToMainMenuWithTextReason");
				Function = FindObjectSingle<UObject*>(Enc_Function2.decrypt()); Enc_Function2.clear();
				if (!Function)
				{
					return;
				}
			}

		}

		struct
		{
			FText ReturnReason;
		} params = { ReturnReason };

		this->ProcessEvent(Function, &params);
	}
	
	void SetAim(FRotator Rotation) {
		static UObject* Function = nullptr;

		Rotation = Rotation.Normalize();

		if (!Function)
		{
			auto Enc_Function = Encrypt(L"Engine.Controller.ClientSetRotation");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt());
			Enc_Function.clear();

			if (!Function)
			{
				return;
			}
		}

		struct
		{
			FRotator NewRotation;
			bool bResetCamera;
		} Params = { Rotation, false };

		if (this && Function)
		{
			try
			{
				this->ProcessEvent(Function, &Params);
			}
			catch (...)
			{
			}
		}
	}
	APlayerPawn_Athena_C* AcknowledgedPawn()
	{
		return *(APlayerPawn_Athena_C**)(this + 0x350);
	}

	APlayerCameraManager* PlayerCameraManager()
	{
		return *(APlayerCameraManager**)(this + 0x360);
	}

	ASpectatorPawn* GetSpectatorPawn()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"PlayerController.GetSpectatorPawn");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			ASpectatorPawn* ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	bool w2s(FVector world_location, FVector2D* screen_location) {
		struct {
			FVector world_location;
			FVector2D screen_location;
			bool return_value;
		} params = { world_location, FVector2D(), true };

		static UObject* function;
		if (!function) function = FindObjectSingle<UObject*>(L"PlayerController.ProjectWorldLocationToScreen");
		this->ProcessEvent(function, &params);
		if (params.screen_location) {
			*screen_location = params.screen_location;
		}
		return params.return_value;
	}

	AHUD* GetHUD()
	{
		static UObject* Function;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"PlayerController.GetHUD");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			AHUD* ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	void FOV(float NewFOV)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"PlayerController.FOV");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			float NewFOV;
		} Params = { NewFOV };

		this->ProcessEvent(Function, &Params);
	}

	FVector2D GetMousePosition()
	{
		static UObject* Function;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"PlayerController.GetMousePosition");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			float LocationX;
			float LocationY;
			bool ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return FVector2D(double(Params.LocationX), double(Params.LocationY));
	}

	bool IsInputKeyDown(FKey key)
	{
		static UObject* Function;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"PlayerController.IsInputKeyDown");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			FKey key;
			bool ReturnValue;
		} Params = { key };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	void ClientIgnoreMoveInput(bool bIgnore)
	{
		static UObject* Function;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"PlayerController.ClientIgnoreMoveInput");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			bool bIgnore;
		} Params = { bIgnore };

		this->ProcessEvent(Function, &Params);
	}

	bool WasInputKeyJustPressed(FKey key)
	{
		static UObject* Function;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"PlayerController.WasInputKeyJustPressed");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			FKey key;
			bool ReturnValue;
		} Params = { key };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	void SetMouseLocation(int32_t X, int32_t Y)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"PlayerController.SetMouseLocation");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			int32_t X;
			int32_t Y;
		} Params = { X, Y };

		this->ProcessEvent(Function, &Params);
	}
};

class UGameViewportClient : public UObject
{
public:
	bool LineTraceSingle(UObject* World, const FVector& Start, const FVector& End)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"KismetSystemLibrary.LineTraceSingle");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			UObject* WorldContextObject;                                       
			struct FVector                                     Start;                                                    
			struct FVector                                     End;                                                      
			TEnumAsByte<ETraceTypeQuery>                       TraceChannel;                                             
			bool                                               bTraceComplex;                                            
			TArray<uint64_t>                                   ActorsToIgnore;                                           
			TEnumAsByte<EDrawDebugTrace>                       DrawDebugType;                                            
			struct FHitResult                                  OutHit;                                                   
			bool                                               bIgnoreSelf;                                              
			struct FLinearColor                                TraceColor;                                               
			struct FLinearColor                                TraceHitColor;                                            
			float                                              DrawTime;                                                 
			unsigned char                                      Padding[0x8];                                       
			bool                                               ReturnValue;
		} params;
		params.WorldContextObject = World;
		params.Start = Start;
		params.End = End;
		params.TraceChannel = ETraceTypeQuery::TraceTypeQuery2;
		params.bTraceComplex = true;
		params.ActorsToIgnore = TArray<uint64_t>();
		params.DrawDebugType = EDrawDebugTrace::None;
		params.bIgnoreSelf = true;
		params.TraceColor = FLinearColor();
		params.TraceHitColor = FLinearColor();
		params.DrawTime = 0.0f;

		this->ProcessEvent(Function, &params);

		return !params.ReturnValue;
	}

	UObject* World()
	{
		return *(UObject**)(this + 0x78);
	}
};

class UPlayer : public UObject
{
public:
	APlayerController* PlayerController()
	{
		return *(APlayerController**)(this + 0x30);
	}
};

class UFortClientSettingsRecord : public UObject
{
public:
	float HUDScale()
	{
		return *(float*)(this + 0x548);
	}



	void SetAimAssistStrength(uint32_t NewValue)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortClientSettingsRecord.SetAimAssistStrength");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			uint32_t NewValue;
		} Params = { NewValue };

		if (Function)
		{
			this->ProcessEvent(Function, &Params);
		}
	}

	void SetUseLegacyControls(bool NewUseLegacyControls)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortClientSettingsRecord.SetUseLegacyControls");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			bool NewUseLegacyControls;
		} Params = { NewUseLegacyControls };

		if (Function)
		{
			this->ProcessEvent(Function, &Params);
		}
	}

	

	void SetSmartBuildEnabled(bool bNewSmartBuildEnabled)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortClientSettingsRecord.SetSmartBuildEnabled");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			bool bNewSmartBuildEnabled;
		} Params = { bNewSmartBuildEnabled };

		if (Function)
		{
			this->ProcessEvent(Function, &Params);
		}
	}
	
	

	

	bool GetContextTutorialEnabled()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortClientSettingsRecord.GetContextTutorialEnabled");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			bool ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}
	
	
	
	void SetMasterVolume(float InVolume) 
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortClientSettingsRecord.SetMasterVolume");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			float InVolume;
		} Params = { InVolume };

		this->ProcessEvent(Function, &Params);
	}
	
	void SetMouseSensitivityY(float InSensitivityY) 
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortClientSettingsRecord.SetMouseSensitivityY");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			float InSensitivityY;
		} Params = { InSensitivityY };

		this->ProcessEvent(Function, &Params);
	}

	void SetMouseSensitivityX(float InSensitivityX) 
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortClientSettingsRecord.SetMouseSensitivityX");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			float InSensitivityX;
		} Params = { InSensitivityX };

		this->ProcessEvent(Function, &Params);
	
	}
	
	
	
	
	float GetMouseSensitivityX()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortClientSettingsRecord.GetMouseSensitivityX");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			float ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	
	void SetUsePowerSavingMode(bool bNewUsePowerSavingMode)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortClientSettingsRecord.SetUsePowerSavingMode");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			bool bNewUsePowerSavingMode;
		} Params = { bNewUsePowerSavingMode };

		if (Function)
		{
			this->ProcessEvent(Function, &Params);
		}
	}
	

	

	


	float GetMouseSensitivityY()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortClientSettingsRecord.GetMouseSensitivityY");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			float ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	

	float GetMasterVolume()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortClientSettingsRecord.GetMasterVolume");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			float ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}


	bool GetUsePowerSavingMode()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortClientSettingsRecord.GetUsePowerSavingMode");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			bool ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}


	void SetContextTutorialEnabled(bool bEnabled)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortClientSettingsRecord.SetContextTutorialEnabled");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			bool bEnabled;
		} Params = { bEnabled };

		this->ProcessEvent(Function, &Params);

	}
	
	
	
	void SetPeripheralLightingEnabled(bool bEnable)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortClientSettingsRecord.SetPeripheralLightingEnabled");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			bool bEnable;
		} Params = { bEnable };

		if (Function)
		{
			this->ProcessEvent(Function, &Params);
		}
	}

	bool GetPeripheralLightingEnabled()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortClientSettingsRecord.GetPeripheralLightingEnabled");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			bool ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	



	void SetShowSessionIDWatermark(bool bInSessionIDWatermark)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortClientSettingsRecord.SetShowSessionIDWatermark");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			bool bInSessionIDWatermark;
		} Params = { bInSessionIDWatermark };

		if (Function)
		{
			this->ProcessEvent(Function, &Params);
		}
	}

	void SetAimAssistEnabled(bool bNewValue)
	{
		
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortClientSettingsRecord.SetAimAssistEnabled");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			bool bNewValue;
		} Params = { bNewValue };

		if (Function)
		{
			this->ProcessEvent(Function, &Params);
		}
	}
};

class UFortLocalPlayer : public UPlayer
{
public:

	

	UFortClientSettingsRecord* ClientSettingsRecord()
	{
		return *(UFortClientSettingsRecord**)(this + 0x378);
	}
};





class USceneViewState : public UObject
{
public:
	FMatrix Projection()
	{
		return *(FMatrix*)(this + 0x900);
	}
};

class ULocalPlayer : public UFortLocalPlayer
{
public:
	UGameViewportClient* ViewportClient()
	{
		return *(UGameViewportClient**)(this + 0x78); 
	}

	USceneViewState* GetViewState()
	{
		TArray <USceneViewState*> ViewState = *(TArray <USceneViewState*>*)(this + 0xd0);

		return ViewState[1];
	}
};

class UGameInstance : public UObject
{
public:
	TArray <ULocalPlayer*> LocalPlayers()
	{
		return *(TArray <ULocalPlayer*>*)(this + 0x38);
	}
};

class UGameUserSettings : public UObject
{
public:

};

class UFortGameUserSettings : public UGameUserSettings
{
public:

};

class UFortKismetLibrary : public UObject
{
public:
	FString GetHumanReadableName(AActor* Actor)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortKismetLibrary.GetHumanReadableName");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			AActor* Actor;
			FString ReturnValue;
		} Params = { Actor };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	
	AFortTracerBase* SpawnTracerFromPool(UObject* WorldContextObject, AFortTracerBase* TracerClass, FVector& Origin, FVector& Destination, AFortPawn* Instigator)
	{
		
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortKismetLibrary.GetHumanReadableName");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			UObject* WorldContextObject;
			AFortTracerBase* TracerClass;
			FVector& Origin;
			FVector& Destination;
			AFortPawn* Instigator;
			AFortTracerBase* ReturnValue;
		} Params = { WorldContextObject, TracerClass, Origin, Destination, Instigator };

		this->ProcessEvent(Function, &Params);
		return Params.ReturnValue;
	}

	FHitResult GetPlayerAimPointHit(AFortPlayerController* SourcePlayer, float MaxRange, TArray<AActor*>& IgnoredActors)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortKismetLibrary.CheckLineOfSightToActorWithChannel");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			AFortPlayerController* SourcePlayer;
			float MaxRange;
			TArray<AActor*>& IgnoredActors;
			FHitResult ReturnValue;
		} Params = { SourcePlayer, MaxRange, IgnoredActors };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	bool OnSameTeam(AActor* ActorA, AActor* ActorB)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortKismetLibrary.OnSameTeam");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			AActor* ActorA;
			AActor* ActorB;
			bool ReturnValue;
		} Params = { ActorA, ActorB };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	bool CheckLineOfSightToActorWithChannel(FVector SourcePos, AActor* Target, ECollisionChannel TargetFilterChannel, AActor* Source)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortKismetLibrary.CheckLineOfSightToActorWithChannel");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			FVector SourcePos;
			AActor* Target;
			ECollisionChannel TargetFilterChannel;
			AActor* Source;
			bool ReturnValue;
		} Params = { SourcePos, Target, TargetFilterChannel, Source };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	bool GetSafeZoneLocation(UObject* WorldContextObject, int32_t SafeZoneIndex, FVector& OutLocation)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortKismetLibrary.GetSafeZoneLocation");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			UObject* WorldContextObject;
			int32_t SafeZoneIndex;
			FVector& OutLocation;
			bool ReturnValue;
		} Params = { WorldContextObject, SafeZoneIndex, OutLocation };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	int32_t GetCurrentSafeZonePhase(UObject* WorldContextObject)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"FortKismetLibrary.GetCurrentSafeZonePhase");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			UObject* WorldContextObject;
			int32_t ReturnValue;
		} Params = { WorldContextObject };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

};

class UKismetMathLibrary : public UObject
{
public:
	FVector VLerp(FVector A, FVector B, float Alpha)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"KismetMathLibrary.VLerp");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			FVector A; FVector B; float Alpha;
			FVector ReturnValue;
		} Params = { A, B, Alpha };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	int32_t round(double A)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"KismetMathLibrary.round");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			int32_t A;
			int32_t ReturnValue;
		} Params = { A };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	FLinearColor LinearColorLerpUsingHSV(FLinearColor A, FLinearColor B, float Alpha)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"KismetMathLibrary.LinearColorLerpUsingHSV");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
		public:
			FLinearColor A;
			FLinearColor B;
			float Alpha;
			FLinearColor ReturnValue;
		}Parameters;

		Parameters.A = A;
		Parameters.B = B;
		Parameters.Alpha = Alpha;

		this->ProcessEvent(Function, &Parameters);

		return Parameters.ReturnValue;
	}

	FVector Vector_ClampSize2D(FVector& A, float Min, float Max)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"KismetMathLibrary.Vector_ClampSize2D");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			FVector& A;
			float Min;
			float Max;
		} Params = { A, Min, Max };

		this->ProcessEvent(Function, &Params);

		return Params.A;
	}

	FVector Conv_RotatorToVector(FRotator InRot)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"KismetMathLibrary.Conv_RotatorToVector");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			FRotator InRot;
			FVector ReturnValue;
		} Params = { InRot };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	float NormalizeAxis(float Angle)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"KismetMathLibrary.NormalizeAxis");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			float Angle;
			float ReturnValue;
		} Params = { Angle };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	int32_t FMod(double Dividend, double Divisor, double& Remainder)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"KismetMathLibrary.FMod");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			double Dividend; double Divisor; double& Remainder;
			int32_t ReturnValue;
		} Params = { Dividend, Divisor, Remainder };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	double FMin(double A, double B)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"KismetMathLibrary.FMin");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			double A, B;
			double ReturnValue;
		} Params = { A, B };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	int32_t Max(int32_t A, int32_t B)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"KismetMathLibrary.Max");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			int32_t A, B;
			int32_t ReturnValue;
		} Params = { A, B };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	double FMax(double A, double B)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"KismetMathLibrary.FMax");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			double A, B;
			double ReturnValue;
		} Params = { A, B };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	FRotator RLerp(FRotator A, FRotator B, float Alpha, bool bShortestPath)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"KismetMathLibrary.Lerp");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			FRotator A; FRotator B; float Alpha; bool bShortestPath;
			FRotator ReturnValue;
		} Params = { A, B, Alpha, bShortestPath };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	double Lerp(double A, double B, double Alpha)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"KismetMathLibrary.Lerp");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			double A, B, Alpha;
			double ReturnValue;
		} Params = { A, B, Alpha };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	double Clamp(double Value, double Min, double Max)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"KismetMathLibrary.FClamp");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			double Value, Min, Max;
			double ReturnValue;
		} Params = { Value, Min, Max };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	double sin(double A)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"KismetMathLibrary.sin");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			double A;
			double ReturnValue;
		} Params = { A };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	double cos(double A)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"KismetMathLibrary.cos");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			double A;
			double ReturnValue;
		} Params = { A };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	double acos(double A)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"KismetMathLibrary.acos");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			double A;
			double ReturnValue;
		} Params = { A };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	double tan(double A)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"KismetMathLibrary.tan");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			double A;
			double ReturnValue;
		} Params = { A };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	double asin(double A)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"KismetMathLibrary.asin");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			double A;
			double ReturnValue;
		} Params = { A };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	double atan(double A)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"KismetMathLibrary.atan");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			double A;
			double ReturnValue;
		} Params = { A };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	double Atan2(double Y, double X)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"KismetMathLibrary.Atan2");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			double Y;
			double X;
			double ReturnValue;
		} Params = { Y, X };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	double abs(double A)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"KismetMathLibrary.abs");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			double A;
			double ReturnValue;
		} Params = { A };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	double Pow(double Base, double exp)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"KismetMathLibrary.MultiplyMultiply_FloatFloat");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			double Base;
			double exp;
			double ReturnValue;
		} Params = { Base, exp };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	double Vector_Distance(FVector V1, FVector V2)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"KismetMathLibrary.Vector_Distance");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			FVector v1;
			FVector v2;
			double ReturnValue;
		} Params = { V1, V2 };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	double Vector_Distance2D(FVector2D v1, FVector2D v2)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"KismetMathLibrary.Vector_Distance2D");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			FVector v1;
			FVector v2;
			double ReturnValue;
		} Params = { FVector(v1.X, v1.Y, 0.0), FVector(v2.X, v2.Y, 0.0) };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	double sqrt(double A)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"KismetMathLibrary.sqrt");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			double A;
			double ReturnValue;
		} Params = { A };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	int32 RandomIntegerInRange(int32 Min, int32 Max)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"KismetMathLibrary.RandomIntegerInRange");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			int32 Min;
			int32 Max;
			int32 ReturnValue;
		} Params = { Min, Max };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	double RandomFloatInRange(double Min, double Max)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"KismetMathLibrary.RandomFloatInRange");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			double Min;
			double Max;
			double ReturnValue;
		} Params = { Min, Max };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	float DegreesToRadians(float A)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"KismetMathLibrary.DegreesToRadians");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			float A;
			float ReturnValue;
		} Params = { A };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	FVector GetRightVector(FRotator InRot)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"KismetMathLibrary.GetRightVector");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			FRotator InRot;
			FVector ReturnValue;
		} Params = { InRot };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	FVector GetForwardVector(FRotator InRot)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"KismetMathLibrary.GetForwardVector");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			FRotator InRot;
			FVector ReturnValue;
		} Params = { InRot };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	FRotator FindLookAtRotation(FVector& Start, FVector& Target)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"KismetMathLibrary.FindLookAtRotation");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			FVector Start;
			FVector Target;
			FRotator ReturnValue;
		} Params = { Start, Target };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}



	FRotator RInterpTo_Constant(FRotator& Current, FRotator& Target, float DeltaTime, float InterpSpeed)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"KismetMathLibrary.RInterpTo_Constant");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			FRotator Current;
			FRotator Target;
			float DeltaTime;
			float InterpSpeed;
			FRotator ReturnValue;
		} Params = { Current, Target, DeltaTime, InterpSpeed };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	FRotator RInterpTo(FRotator& Current, FRotator& Target, float DeltaTime, float InterpSpeed)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"KismetMathLibrary.RInterpTo");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			FRotator Current;
			FRotator Target;
			float DeltaTime;
			float InterpSpeed;
			FRotator ReturnValue;
		} Params = { Current, Target, DeltaTime, InterpSpeed };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	FVector VInterpTo(FVector& Current, FVector& Target, float DeltaTime, float InterpSpeed)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"KismetMathLibrary.VInterpTo");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			FVector Current;
			FVector Target;
			float DeltaTime;
			float InterpSpeed;
			FVector ReturnValue;
		} Params = { Current, Target, DeltaTime, InterpSpeed };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}
};

class UGameplayStatics : public UObject
{
public:

	UGameInstance* GetGameInstance(UObject* WorldContextObject)
	{

		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"GameplayStatics.GetGameInstance");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			UObject* WorldContextObject;
			UGameInstance* ReturnValue;
		} Params = { WorldContextObject };

		this->ProcessEvent(Function, &Params);

		

		return Params.ReturnValue;
	}

	TArray<UObject*> GetAllActorsOfClass(UObject* WorldContextObject, UObject* ActorClass)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"GameplayStatics.GetAllActorsOfClass");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			UObject* WorldContextObject;
			UObject* ActorClass;
			TArray<UObject*> OutActors;
		} Params = { WorldContextObject, ActorClass };

		this->ProcessEvent(Function, &Params);

		return Params.OutActors;
	}

	bool ObjectIsA(UObject* Object, UObject* ObjectClass)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"GameplayStatics.ObjectIsA");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			UObject* Object;
			UObject* ObjectClass;
			bool ReturnValue;
		} Params = { Object, ObjectClass };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	double GetWorldDeltaSeconds(UObject* WorldContextObject)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"GameplayStatics.GetWorldDeltaSeconds");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			UObject* WorldContextObject;
			double ReturnValue;
		} Params = { WorldContextObject };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	double GetTimeSeconds(UObject* WorldContextObject)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"GameplayStatics.GetTimeSeconds");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			UObject* WorldContextObject;
			double ReturnValue;
		} Params = { WorldContextObject };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}
};

class UKismetSystemLibrary : public UObject
{
public:

	
	
	FString GetUniqueDeviceId()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"KismetSystemLibrary.GetUniqueDeviceId");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct {
			FString ReturnValue;
		} Params = { };


		this->ProcessEvent(Function, &Params);
		return Params.ReturnValue;
	}

	

	FString GetDisplayName(UObject* Object)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"KismetSystemLibrary.GetDisplayName");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct {
			FString ReturnValue;
		} Params = { };


		this->ProcessEvent(Function, &Params);
		return Params.ReturnValue;
	}

	

	FString GetPlatformUserDir()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"KismetSystemLibrary.GetPlatformUserDir");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct {
			FString ReturnValue;
		} Params = { };


		this->ProcessEvent(Function, &Params);
		return Params.ReturnValue;
	}

	
	
	
	
	
	void LogString(FString InString, bool bPrintToLog = true)
	{
		
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"KismetSystemLibrary.LogString");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			FString InString;
			bool bPrintToLog;
		} Params = { InString, bPrintToLog };

		if (Function)
		{
			this->ProcessEvent(Function, &Params);
		}
	}

	bool FileExists(FString InPath)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"BlueprintPathsLibrary.FileExists");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			FString InPath;
			bool ReturnValue;
		} Params = { InPath };

		if (Function)
		{
			this->ProcessEvent(Function, &Params);
			return Params.ReturnValue;
		}

		return false;
	}

	bool DirectoryExists(FString InPath)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"BlueprintPathsLibrary.DirectoryExists");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			FString InPath;
			bool ReturnValue;
		} Params = { InPath };

		if (Function)
		{
			this->ProcessEvent(Function, &Params);
			return Params.ReturnValue;
		}

		return false;
	}

	FString GetPlatformUserName()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"KismetSystemLibrary.GetPlatformUserName");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct {
			FString ReturnValue;
		} Params = { };


		this->ProcessEvent(Function, &Params);
		return Params.ReturnValue;
	}

	FString GetDeviceId()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"KismetSystemLibrary.GetDeviceId");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct {
			FString ReturnValue;
		} Params = { };


		this->ProcessEvent(Function, &Params);
		return Params.ReturnValue;
	}

	double GetGameTimeInSeconds(UObject* WorldContextObject)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"KismetSystemLibrary.GetGameTimeInSeconds");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct {
			UObject* WorldContextObject;
			double ReturnValue;
		} Params = { WorldContextObject };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	void GetComponentBounds(USceneComponent* Component, FVector* Origin, FVector* BoxExtent, float* SphereRadius)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"KismetSystemLibrary.GetComponentBounds");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
		public:
			USceneComponent* Component;
			FVector Origin;
			FVector BoxExtent;
			float SphereRadius;
		}Parameters;

		Parameters.Component = Component;

		this->ProcessEvent(Function, &Parameters);

		if (Origin != nullptr)
			*Origin = Parameters.Origin;

		if (BoxExtent != nullptr)
			*BoxExtent = Parameters.BoxExtent;

		if (SphereRadius != nullptr)
			*SphereRadius = Parameters.SphereRadius;
	}

	bool LineTraceSingle(UObject* WorldContextObject, FVector Start, FVector End, ETraceTypeQuery TraceChannel, bool bTraceComplex, TArray<AActor*> ActorsToIgnore, EDrawDebugTrace DrawDebugType, FHitResult* OutHit, bool bIgnoreSelf, FLinearColor TraceColor, FLinearColor TraceHitColor, float DrawTime)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"KismetSystemLibrary.LineTraceSingle");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
		public:
			UObject* WorldContextObject;
			FVector Start;
			FVector End;
			ETraceTypeQuery TraceChannel;
			bool bTraceComplex;
			uint8 Pad_1C02[0x6];
			TArray<AActor*> ActorsToIgnore;
			EDrawDebugTrace DrawDebugType;
			uint8 Pad_1C04[0x3];
			FHitResult OutHit;
			bool bIgnoreSelf;
			uint8 Pad_1C05[0x3];
			FLinearColor TraceColor;
			FLinearColor TraceHitColor;
			float DrawTime;
			bool ReturnValue;
			uint8 Pad_1C06[0x7];
		}Parms;

		Parms.WorldContextObject = WorldContextObject;
		Parms.Start = Start;
		Parms.End = End;
		Parms.TraceChannel = TraceChannel;
		Parms.bTraceComplex = bTraceComplex;
		Parms.ActorsToIgnore = ActorsToIgnore;
		Parms.DrawDebugType = DrawDebugType;
		Parms.bIgnoreSelf = bIgnoreSelf;
		Parms.TraceColor = TraceColor;
		Parms.TraceHitColor = TraceHitColor;
		Parms.DrawTime = DrawTime;

		this->ProcessEvent(Function, &Parms);

		*OutHit = Parms.OutHit;

		return Parms.ReturnValue;
	}
	
	
	
	
	FString GetEngineVersion()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"KismetSystemLibrary.GetGameName");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			FString ReturnValue;
		} Params = { };

		if (Function)
		{
			this->ProcessEvent(Function, &Params);


			return Params.ReturnValue;
		}

		return FString(L"Error");
	}

	FString GetGameName()
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"KismetSystemLibrary.GetGameName");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			FString ReturnValue;
		} Params = { };

		if (Function)
		{
			this->ProcessEvent(Function, &Params);


			return Params.ReturnValue;
		}

		return FString(L"Error");
	}


	FString GetObjectName(UObject* Object)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"KismetSystemLibrary.GetObjectName");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			UObject* Object;
			FString ReturnValue;
		} Params = { Object };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	FString GetPathName(UObject* Object)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"KismetSystemLibrary.GetPathName");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			UObject* Object;
			FString ReturnValue;
		} Params = { Object };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}
};

class UKismetStringLibrary : public UObject
{
public:
	
	
	FString Concat_StrStr(struct FString A, struct FString B)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"KismetStringLibrary.Concat_StrStr");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			FString A;
			FString B;
			FString ReturnValue;
		} Params = { A, B };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}
	
	
	FString TimeSecondsToString(float InSeconds)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"KismetStringLibrary.TimeSecondsToString");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			float InSeconds;
			FString ReturnValue;
		} Params = { InSeconds };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	FString Conv_IntToString(int32 InInt)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"KismetStringLibrary.Conv_IntToString");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			int32 InInt;
			FString ReturnValue;
		} Params = { InInt };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	FText Conv_StringToText(FString InString)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"KismetTextLibrary.Conv_StringToText");

			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			FString InString;
			FText ReturnValue;
		} Params = { InString };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	FString Conv_TextToString(FText InText)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"KismetTextLibrary.Conv_TextToString");

			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct {
			FText InText;
			FString ReturnValue;
		} Params = { InText };


		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	bool Contains(FString SearchIn, FString Substring, bool bUseCase, bool bSearchFromEnd)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"KismetStringLibrary.Contains");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			FString SearchIn;
			FString Substring;
			bool bUseCase;
			bool bSearchFromEnd;
			bool ReturnValue;
		} Params = { SearchIn, Substring, bUseCase, bSearchFromEnd };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	FName Conv_StringToName(FString InString)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"KismetStringLibrary.Conv_StringToName");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			FString InString;
			FName ReturnValue;
		} Params = { InString };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	FString Conv_NameToString(FName InName)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"KismetStringLibrary.Conv_NameToString");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			FName InName;
			FString ReturnValue;
		} Params = { InName };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	FString BuildString_Int(FString AppendTo, FString Prefix, int InInt, FString Suffix)
	{
		static UObject* Function = 0;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"KismetStringLibrary.BuildString_Int");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			FString AppendTo;
			FString Prefix;
			int InInt;
			FString Suffix;
			FString ReturnValue;
		} Params = { AppendTo, Prefix, InInt, Suffix };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}

	FString BuildString_Double(FString AppendTo, FString Prefix, double InDouble, FString Suffix)
	{
		static UObject* Function;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"KismetStringLibrary.BuildString_Double");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			FString AppendTo;
			FString Prefix;
			double InDouble;
			FString Suffix;
			FString ReturnValue;
		} Params = { AppendTo, Prefix, InDouble, Suffix };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}
};

namespace StaticClasses
{
	static UFortKismetLibrary* FortKismetLibrary = nullptr;
	static UKismetSystemLibrary* KismetSystemLibrary = nullptr;
	static UKismetMathLibrary* KismetMathLibrary = nullptr;
	static UGameplayStatics* GameplayStatics = nullptr;
	static UKismetStringLibrary* KismetStringLibrary = nullptr;
}

class UEngine : public UObject
{
public:
	UFont* MediumFont()
	{
		return *(UFont**)(this + 0x70);
	}

	void ExecuteConsoleCommand(UObject* WorldContextObject, FString Command, APlayerController* SpecificPlayer)
	{
		static UObject* Function;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"KismetSystemLibrary.ExecuteConsoleCommand");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			UObject* WorldContextObject;
			FString Command;
			APlayerController* SpecificPlayer;
		} Params = { WorldContextObject, Command, SpecificPlayer };

		this->ProcessEvent(Function, &Params);
	}
};

class ULevel : public UObject
{
public:
	TArray<AActor*> Actors()
	{
		return *(TArray<AActor*>*)(this + 0xA0); 
	}
};

class AGameModeBase : public UObject
{
public:
	int32_t GetNumSpectators()
	{
		static UObject* Function;
		if (!Function)
		{
			auto Enc_Function = Encrypt(L"GameModeBase.GetNumSpectators");
			Function = FindObjectSingle<UObject*>(Enc_Function.decrypt()); Enc_Function.clear();
		}

		struct
		{
			int32_t ReturnValue;
		} Params = { };

		this->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}
};




struct FGameplayTag { char Pad[0x0004]; };
struct FCosmeticCustomizationInfo { char Pad[0x0018]; };
struct FCosmeticLoadoutSlot { char Pad[0x0020]; };
struct FCosmeticLoadout { char Pad[0x0010]; };
struct FFortAthenaLoadout { char Pad[0x0130]; };

struct FGameplayTagContainer final
{
public:
	TArray<struct FGameplayTag>                   GameplayTags;                                      
	TArray<struct FGameplayTag>                   ParentTags;                                        
};

struct FCosmeticVariantInfo
{
public:
	struct FGameplayTag                           VariantChannelTag;                                 
	struct FGameplayTag                           ActiveVariantTag;                                  
};

struct FMcpVariantChannelInfo final : public FCosmeticVariantInfo
{
public:
	struct FGameplayTagContainer                  OwnedVariantTags;                                  
	class UObject* ItemVariantIsUsedFor;                              
	class FString                                 CustomData;                                        
};


class AFortGameState : public UObject
{
public:

};

class AGameStateBase : public UObject
{
public:

};

class UWorld : public UObject
{
public:
	AGameModeBase* AuthorityGameMode()
	{
		return *(AGameModeBase**)(this + 0x158);
	}

	AGameStateBase* GameState()
	{
		return *(AGameStateBase**)(this + 0x188);
	}

	UGameInstance* OwningGameInstance()
	{
		if (this)
		{
			if (UGameInstance* GameInstance = StaticClasses::GameplayStatics->GetGameInstance(this))
				return GameInstance;

			if (this + Offsets::GameInstance)
			{
				return *(UGameInstance**)(this + Offsets::GameInstance);
			}



			return nullptr;
			
		}

		return nullptr;

		return *(UGameInstance**)(this + Offsets::GameInstance);
	}

	FVector GetCameraLocation()
	{
		return *(FVector*)(*(uintptr_t*)(this + 0x110));
	}

	FRotator GetCameraRotation()
	{
		uintptr_t RotationPointer = *(uintptr_t*)(this + 0x120);
		FRotator ReturnValue = FRotator(*(double*)(RotationPointer), *(double*)(RotationPointer + 0x20), *(double*)(RotationPointer + 0x1D0));

		ReturnValue.Yaw = ((StaticClasses::KismetMathLibrary->Atan2(ReturnValue.Pitch * -1.0, ReturnValue.Yaw) * (180.0 / M_PI)) * -1.0) * -1.0;
		ReturnValue.Pitch = StaticClasses::KismetMathLibrary->asin(ReturnValue.Roll) * (180.0 / M_PI);
		ReturnValue.Roll = 0.0;

		return ReturnValue;
	}

	TArray<ULevel*> Levels()
	{
		return *(TArray<ULevel*>*)(this + 0x178);
	}
};

class TUObjectArray
{
public:
	enum
	{
		ElementsPerChunk = 0x10000,
	};
public:
	struct FUObjectItem
	{
		class UObject* Object;
		uint8_t Pad[0x10];
	};

	FUObjectItem** Objects;
	uint8_t Pad_0[0x08];
	uint32_t MaxElements;
	uint32_t NumElements;
	uint32_t MaxChunks;
	uint32_t NumChunks;

	UObject* GetByIndex(const uint32_t Index) const
	{
		if (Index < 0 || Index > this->NumElements)
			return nullptr;

		const uint32_t ChunkIndex = Index / ElementsPerChunk;
		const uint32_t InChunkIdx = Index % ElementsPerChunk;

		return this->Objects[ChunkIndex][InChunkIdx].Object;
	}

	template <class Type>
	Type FindObject(FName Name, UObject* Class) const
	{
		for (auto i = 0u; i < this->NumElements; i++)
		{
			UObject* Object = this->GetByIndex(i);
			if (Object && Object->GetNamePrivate() == Name && StaticClasses::GameplayStatics->ObjectIsA(Object, Class)) { return reinterpret_cast<Type>(Object); }
		}

		return nullptr;
	}
}; TUObjectArray* ObjectArray;

UObject* FWeakObjectPtr::Get()
{
	return ObjectArray->GetByIndex(ObjectIndex);
}

UObject* FWeakObjectPtr::operator->() const
{
	return ObjectArray->GetByIndex(ObjectIndex);
}

inline static bool TryFindObjects()
{
	
	
	

	ObjectArray = find_pattern<TUObjectArray*>(Encrypt("48 83 EC 28 E8 ? ? ? ? 48 83 C4 28").decrypt());
	if (ObjectArray)
	{
		return true;
	}
	else
	{
		return false;
	}
}