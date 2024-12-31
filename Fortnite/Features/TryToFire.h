#pragma once



void (*TryToFireOriginal)(AFortWeapon*);
void TryToFire(AFortWeapon* FortWeapon)
{

	reinterpret_cast<void(__cdecl*)(AFortWeapon*, uintptr_t)>(FortWeapon, TryToFireOriginal);
}