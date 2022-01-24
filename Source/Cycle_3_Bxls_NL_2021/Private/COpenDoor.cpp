// Fill out your copyright notice in the Description page of Project Settings.


#include "COpenDoor.h"
#include "Components/StaticMeshComponent.h"

/****************************************************************************************************
Description : Constructor, Sets default values for this component's properties
Input : None

Output : None

Note ://

******************************************************************************************************/
UCOpenDoor::UCOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	fltMassTest = 0.f;
	


	// ...
}


/****************************************************************************************************
Description : Call when game start
Input : None

Output : None

Note ://

******************************************************************************************************/
void UCOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	
	
	// ...
	
}

/****************************************************************************************************
Description : Call every frame
Input : DeltaTime,TickType, ThisFunctionTick

Output : ThisFunctionTick

Note :Delta time is the time between two frames

******************************************************************************************************/
void UCOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	GetOverlappingActors();
	
	UE_LOG(LogTemp, Warning, TEXT("Mass : %f"), SetTotalMass());

	if (Tvolume) {
		if (SetTotalMass() > fltMassTest) {
			UE_LOG(LogTemp, Warning, TEXT("Open door"));
			OpendDoor();
			fltLastDoorOpenTime = GetWorld()->GetTimeSeconds();
			

		}
		else if ((timeLastDoorOpen = GetWorld()->GetTimeSeconds() - fltLastDoorOpenTime) > fltDelay) {
			UE_LOG(LogTemp, Warning, TEXT("Close door"));
			CloseDoor();
		
		}
	}
	
	
	// ...
}
/****************************************************************************************************
Description : Get Actors in TriggerVolume
Input : 

Output : Actors references

Note :This fonction set actors references in TArray<Actor*>

******************************************************************************************************/
void UCOpenDoor::GetOverlappingActors()
{
	if (Tvolume != nullptr) {
		Tvolume->GetOverlappingActors(Actors);
	}

	return;
	


}
/****************************************************************************************************
Description : Set total mass Actors in TArray<Actor*>
Input : 

Output : Float total mass

Note : This fonction set total mass in TArray<Actor*>

******************************************************************************************************/
float UCOpenDoor::SetTotalMass()
{
	UStaticMeshComponent* Mesh;
	float fltTotalMass = 0;
	for (AActor* actors : Actors) {

		 Mesh = actors->FindComponentByClass<UStaticMeshComponent>();
		 if (Mesh)
			 fltTotalMass = fltTotalMass + Mesh->GetMass();
		
	}
	
	return fltTotalMass;

}
/****************************************************************************************************
Description : Multicast delegate	
Input : 

Output : delegate broadcast

Note : Call delegate Broadcast to call event in blueprint 

******************************************************************************************************/
void UCOpenDoor::OpendDoor() const
{
	openDoor.Broadcast();

}
/****************************************************************************************************
Description : Multicast delegate
Input : 

Output : delegate broadcast

Note :Call delegate Broadcast to call event in blueprint

******************************************************************************************************/
void UCOpenDoor::CloseDoor() const
{
	closeDoor.Broadcast();
}

