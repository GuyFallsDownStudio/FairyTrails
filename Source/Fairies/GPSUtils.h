// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GPSUtils.generated.h"

/**
 * 
 */
UCLASS()
class FAIRIES_API UGPSUtils : public UObject
{
	GENERATED_BODY()

		UFUNCTION(BlueprintCallable)
		static int ConvertLatitudinalDistanceToFeet(float Latitude1, float Longitude1, float Latitude2, float Longitude2);
	
	
	
};
