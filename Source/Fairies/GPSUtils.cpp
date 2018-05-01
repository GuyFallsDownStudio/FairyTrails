// Fill out your copyright notice in the Description page of Project Settings.

#include "GPSUtils.h"

int UGPSUtils::ConvertLatitudinalDistanceToFeet(float Latitude1, float Longitude1, float Latitude2, float Longitude2)
{
	float EarthRadius = 6371000;
	float Latitude1Radians = FMath::DegreesToRadians(Latitude1);
	float Latitude2Radians = FMath::DegreesToRadians(Latitude2);
	float DeltaLatitude = FMath::DegreesToRadians(Latitude2 - Latitude1);
	float DeltaLongitude = FMath::DegreesToRadians(Longitude2- Longitude1);

	float a = sin(DeltaLatitude / 2) * sin(DeltaLatitude / 2) + cos(Latitude1Radians) * cos(Latitude2Radians) * sin(DeltaLongitude / 2) * sin(DeltaLongitude / 2);
	float c = 2 * atan2(sqrt(a), sqrt(1 - a));

	return EarthRadius * c;
}
