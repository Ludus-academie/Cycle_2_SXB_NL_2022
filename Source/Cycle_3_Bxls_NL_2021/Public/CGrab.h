// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "CGrab.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CYCLE_3_BXLS_NL_2021_API UCGrab : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCGrab();

	

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "Grab")
	FHitResult GetFirstPhysicsBodyInReach();

	FVector PointLineStart() const;

	FVector PointLineEnd()const;

	void SetInputComponent();

	void FindPhysicsHandleComponent();

	void Handle();

	UFUNCTION(BlueprintCallable, Category = "Grab")
		void Grab(); 
	
	UFUNCTION(BlueprintCallable, Category = "Grab")
		void Release();

	void UpdateGrabLocation()const;

	


private :

	UPROPERTY(EditDefaultsOnly, Category = "Dist Property")
		float fltDistance;

	UInputComponent* inputComponent;

	UPhysicsHandleComponent* physicsHandle;

		
};
