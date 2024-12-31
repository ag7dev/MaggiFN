#pragma once


void(*GetViewPointOriginal)(ULocalPlayer*, FMinimalViewInfo*, void*) = nullptr; 
void GetViewPoint(ULocalPlayer* LocalPlayer, FMinimalViewInfo* OutViewInfo, void* StereoPass)
{
	GetViewPointOriginal(LocalPlayer, OutViewInfo, StereoPass);

	if (Variables::GetViewPoint::bApplyModifiedData && Variables::GetViewPoint::Location)
	{
		OutViewInfo->Location = Variables::GetViewPoint::Location;
	}

	if (Variables::GetViewPoint::bApplyModifiedData && !Variables::GetViewPoint::bSkipRotationForModification && Variables::GetViewPoint::Rotation)
	{
		OutViewInfo->Rotation = Variables::GetViewPoint::Rotation;
	}


	
}