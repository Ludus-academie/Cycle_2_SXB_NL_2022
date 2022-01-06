// Fill out your copyright notice in the Description page of Project Settings.


#include "CPawn.h"
#include "GameFramework/PawnMovementComponent.h"

// Sets default values
ACPawn::ACPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

UPawnMovementComponent* ACPawn::GetMovementComponent() const
{

	UE_LOG(LogTemp, Warning, TEXT("Get movementComponent class CPawn"));
	return  FindComponentByClass<UPawnMovementComponent>();

}
