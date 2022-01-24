// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "COpenDoor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDoorEvent);
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CYCLE_3_BXLS_NL_2021_API UCOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void GetOverlappingActors();

	float SetTotalMass();

	void OpendDoor()const;

	void CloseDoor()const;

	

private :



	UPROPERTY(EditAnywhere, Category = "TriggerVolume")
		ATriggerVolume *Tvolume;

	UPROPERTY(EditAnywhere, Category = "TriggerVolume")
		float fltMassTest;
	
	UPROPERTY(EditAnywhere, Category = "TriggerVolume")
		float fltDelay;

	float fltLastDoorOpenTime;

	float timeLastDoorOpen;
	 
	TArray<AActor*> Actors;

	UPROPERTY(BlueprintAssignable)
		FDoorEvent openDoor;

	UPROPERTY(BlueprintAssignable)
		FDoorEvent closeDoor;

	


		
};
