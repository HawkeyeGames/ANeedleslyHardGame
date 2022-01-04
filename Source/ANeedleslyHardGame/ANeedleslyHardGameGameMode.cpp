// Copyright Epic Games, Inc. All Rights Reserved.

#include "ANeedleslyHardGameGameMode.h"
#include "ANeedleslyHardGameCharacter.h"
#include "UObject/ConstructorHelpers.h"

AANeedleslyHardGameGameMode::AANeedleslyHardGameGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/SideScrollerCPP/Blueprints/SideScrollerCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
