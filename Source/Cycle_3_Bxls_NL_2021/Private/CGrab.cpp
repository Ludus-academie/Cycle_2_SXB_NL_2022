// Fill out your copyright notice in the Description page of Project Settings.


#include "CGrab.h"
#include "CollisionQueryParams.h"
#include "DrawDebugHelpers.h"

/****************************************************************************************************
Description : Constructor, Sets default values for this component's properties
Input : None

Output : None

Note ://

******************************************************************************************************/
UCGrab::UCGrab()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	fltDistance = 200;

	// ...
}


/****************************************************************************************************
Description : Call when game start
Input : None

Output : None

Note ://

******************************************************************************************************/
void UCGrab::BeginPlay()
{
	Super::BeginPlay();
	
	FindPhysicsHandleComponent();

	/*SetInputComponent();

	if (inputComponent) {
		inputComponent->BindAction("Grab", IE_Pressed, this, &UCGrab::Grab);
		inputComponent->BindAction("Grab", IE_Released, this, &UCGrab::Release);
	}
	*/
	// ...
	
}


/****************************************************************************************************
Description : Call every frame
Input : DeltaTime,TickType, ThisFunctionTick

Output : ThisFunctionTick

Note :Delta time is the time between two frames

******************************************************************************************************/
void UCGrab::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	//UE_LOG(LogTemp, Warning, TEXT("Point Line Start : %s"), *PointLineStart().ToString());
	//UE_LOG(LogTemp, Warning, TEXT("Point Line End : %s"), *PointLineEnd().ToString());

	UpdateGrabLocation();
	
	// ...
}

/****************************************************************************************************
Description : This function return the Hit result of the component that is hit by the ray tracing in case of
collision withe an object having as collision channel ECC:TYPE PhysicsBody

Input : None

Output : HitResult

Note ://

******************************************************************************************************/
FHitResult UCGrab::GetFirstPhysicsBodyInReach()
{
	UWorld* World = GetWorld();

	FHitResult HitResult;

	FCollisionQueryParams TraceParameters(FName(TEXT("")), false, GetOwner());

	if (World->LineTraceSingleByChannel(HitResult, PointLineStart(), PointLineEnd(),ECollisionChannel::ECC_PhysicsBody,TraceParameters)) {
		DrawDebugLine(World, PointLineStart(), PointLineEnd(), FColor::Green, false, 5.f);

	}
	else {
		DrawDebugLine(World, PointLineStart(), PointLineEnd(), FColor::Red, false, 5.f);
	}
	
	
	return HitResult;
}
/****************************************************************************************************
Description : This function return the position of line trace start point

Input : None

Output : None

Note :Private function

******************************************************************************************************/

FVector UCGrab::PointLineStart() const
{
	//ou GetPlayerViewPoint()
	FVector vStartPoint=GetOwner()->GetActorLocation();

	return vStartPoint;
}

/****************************************************************************************************
Description : This function return the position of line trace end point

Input : None

Output : None

Note :Private function

******************************************************************************************************/
FVector UCGrab::PointLineEnd() const
{
	AActor* Actor = GetOwner();
	//ou GetPlayerViewPoint()
	FVector vEndPoint = Actor->GetActorForwardVector()*fltDistance + PointLineStart();

	return vEndPoint;
}

void UCGrab::SetInputComponent()
{
	inputComponent = GetOwner()->FindComponentByClass<UInputComponent>();
	
	if (ensure(inputComponent)) {
		UE_LOG(LogTemp, Warning, TEXT("Component Input Find"));
	}
}

/****************************************************************************************************
Description : This function get physicsHandle component from Blueprint, if you find it! Caution!! Always
do be carfull to secure your pointer!

Input : None

Output : None

Note ://

******************************************************************************************************/

void UCGrab::FindPhysicsHandleComponent()
{

	physicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();

	if (ensure(physicsHandle)) {
		UE_LOG(LogTemp, Warning, TEXT("PhysicsHandle Component find"));

	}
	else {
		return;
	}
	
}


/****************************************************************************************************
Description : This function Grab component from yhe scene, if you find it! Caution!! Always
do be carfull to secure your pointer!

Input : None

Output : None

Note ://

******************************************************************************************************/

void UCGrab::Handle()
{

	FHitResult Hit = GetFirstPhysicsBodyInReach();

	UPrimitiveComponent* ComponentToGrab = Hit.GetComponent();
	AActor* ActorHit = Hit.GetActor();

	if (ActorHit) {

		physicsHandle->GrabComponentAtLocation(ComponentToGrab, NAME_None, ComponentToGrab->GetOwner()->GetActorLocation());
	}
}

void UCGrab::Grab()
{
	Handle();
}

/****************************************************************************************************
Description : This function set  physicsHandle (Loose Component)

Input : None

Output : None

Note ://
******************************************************************************************************/

void UCGrab::Release()
{
	physicsHandle->ReleaseComponent();
}

/****************************************************************************************************
Description : This function update Target Location

Input : None

Output : None

Note ://
******************************************************************************************************/

void UCGrab::UpdateGrabLocation()const
{
	//Update ref PhysicsHandle component
	if (physicsHandle->GrabbedComponent) {

		physicsHandle->SetTargetLocation(PointLineEnd());
	}
}


