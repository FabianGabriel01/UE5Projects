// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "PlayerCharacter.generated.h"


class UInputMappingContext;
class UInputAction;

UCLASS()
class UE5PROJECTS_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputMappingContext* ContextInput;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* LookAction;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:

	void Movement(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);

	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);

	void SprintAC();
	void SprintRelease();
	void JumpAc();
	void OnGrab();
	void OnReleaseGrab();

	//ControllerSection
	void LookupRate(float AxisValue);
	void LookRightRate(float AxisValue);

	UPROPERTY(EditAnywhere)
	float _Sens = 10.f;

	UPROPERTY(EditDefaultsOnly)
	class UCameraComponent* _Camera;

	UPROPERTY(EditDefaultsOnly)
	class UPhysicsHandleComponent* _Physics;



	


};
