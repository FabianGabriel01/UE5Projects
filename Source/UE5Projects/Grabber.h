// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Grabber.generated.h"

#define Draw_SphereHitResult(FColor, HitResult) if(GetWorld())  DrawDebugSphere(GetWorld(), HitResult,10,10, FColor,false,5);
#define Draw_Line(Start, End, FColor) if(GetWorld()) DrawDebugLine(GetWorld(), Start, End, FColor, false);


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UE5PROJECTS_API UGrabber : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void DoGrab();

	UFUNCTION(BlueprintCallable)
	void ReleaseGrab();

	UPROPERTY(EditDefaultsOnly)
	float MaxGrabDistance = 1000.f;

	UPROPERTY(EditDefaultsOnly)
	float GrabRadius = 100.f;

	UPROPERTY(EditDefaultsOnly)
	float HoldDistance = 200.f;

	UPROPERTY(EditDefaultsOnly)
	float Impulse = 500.f;

	UPhysicsHandleComponent* GetPhysicsHandle() const;

	bool GetGrabbableInReach(FHitResult& OutHitResult) const;


		
};
