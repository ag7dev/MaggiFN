#pragma once

double* ( *GetWeaponTargetingTransformOriginal )( AFortWeapon* , double* , double* );
double* GetWeaponTargetingTransform( AFortWeapon* CurrentWeapon , double* StartLocation , double* Angles )
{
	double* ReturnValue = GetWeaponTargetingTransformOriginal( CurrentWeapon , StartLocation , Angles );
	if ( Variables::GetWeaponTargetingTransform::bSilentAimActive && Variables::GetWeaponTargetingTransform::SilentLocationTarget )
	{
		Angles[ 0 ] = Variables::GetWeaponTargetingTransform::SilentLocationTarget.X - StartLocation[ 0 ];
		Angles[ 1 ] = Variables::GetWeaponTargetingTransform::SilentLocationTarget.Y - StartLocation[ 1 ];
		Angles[ 2 ] = Variables::GetWeaponTargetingTransform::SilentLocationTarget.Z - StartLocation[ 2 ];
	}

	return ReturnValue;
}