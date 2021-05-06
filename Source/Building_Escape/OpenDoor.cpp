// Fill out your copyright notice in the Description page of Project Settings.


#include "OpenDoor.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	this->InitialYaw = this->GetOwner()->GetActorRotation().Yaw;
	this->CurrentYaw = this->InitialYaw;
	this->TargetYaw += this->InitialYaw;
	
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	UE_LOG(LogTemp, Warning, TEXT("%s"), *this->GetOwner()->GetActorRotation().ToString());
	UE_LOG(LogTemp, Warning, TEXT("Yaw is: %f"), this->GetOwner()->GetActorRotation().Yaw);

	this->CurrentYaw = FMath::FInterpTo(this->CurrentYaw, this->TargetYaw, DeltaTime, 2);
	FRotator DoorRotation = this->GetOwner()->GetActorRotation();
	DoorRotation.Yaw = this->CurrentYaw;
	this->GetOwner()->SetActorRotation(DoorRotation);

	// this->CurrentYaw = GetOwner()->GetActorRotation().Yaw;
	// FRotator OpenDoor(0.f, this->TargetYaw, 0.f);
	// OpenDoor.Yaw = FMath::FInterpTo(this->CurrentYaw, this->TargetYaw, DeltaTime, 2);
	// this->GetOwner()->SetActorRotation(OpenDoor);
}

