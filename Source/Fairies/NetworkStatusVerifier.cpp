// Fill out your copyright notice in the Description page of Project Settings.

#include "NetworkStatusVerifier.h"
#include "Networking.h"
#include "Sockets.h"
#include "SocketSubsystem.h"

// Sets default values
ANetworkStatusVerifier::ANetworkStatusVerifier()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ANetworkStatusVerifier::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANetworkStatusVerifier::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FIPv4Address makeIP()
{
    FString address = TEXT("172.217.24.110");
    FIPv4Address ip;
    FIPv4Address::Parse(address, ip);
    return ip;
}

TSharedRef<FInternetAddr> makeAddress()
{
    FIPv4Address ip = makeIP();
    int32 port = 80;
    TSharedRef<FInternetAddr> addr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
    addr->SetIp(ip.Value);
    addr->SetPort(port);
    return addr;
}

bool ANetworkStatusVerifier::IsNetworkConnected()
{
    FSocket* Socket = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateSocket(NAME_Stream, TEXT("default"), false);
    TSharedRef<FInternetAddr> addr = makeAddress();
    bool connected = Socket->Connect(*addr);
    return connected;
}
