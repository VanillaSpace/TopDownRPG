// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Unreal_Assignment3Character.generated.h"

UCLASS(Blueprintable)
class AUnreal_Assignment3Character : public ACharacter
{
	GENERATED_BODY()

public:
	AUnreal_Assignment3Character();

	// Called every frame.
	virtual void Tick(float DeltaSeconds) override;

	/** Returns TopDownCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns CursorToWorld subobject **/
	FORCEINLINE class UDecalComponent* GetCursorToWorld() { return CursorToWorld; }

	/** This is for the projectile **/
	UPROPERTY(VisibleAnywhere)
	USceneComponent* ProjectileOrigin;
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> ProjectileActor;

	void Shoot();

	UFUNCTION(BlueprintImplementableEvent)
		void ShootAnim();

	/** This is for the AOE  **/
	UPROPERTY(VisibleAnywhere)
		USceneComponent* AOEOrigin;

	UPROPERTY(EditAnywhere)
		TSubclassOf<AActor> AOEActor;

	void AOE();

	/** Player Health **/
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float HP = 1.0f;

	/** Current Health **/
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float currHP;

	/** Enemy DMG **/
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float enemyDMG = 0.1f;

	/** Player MANA **/
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float Mana = 1.0f;

	UFUNCTION(BlueprintCallable)
		void Dodging();

	UFUNCTION(BlueprintCallable)
		void hitsPlayer();

	//### Field created to store the actor receiver of an action when pressing input 'E' (assigned when overlapped)
	AActor* OnActionReceiver = nullptr;

	//### Properties to store the "Inventory" of Potions;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		int HPPotions = 0;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		int ManaPotions = 0;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		int SpeedPotions = 0;

	//### Methods called when using the potions binded to inputs on the ...controller.cpp
	UFUNCTION(BlueprintCallable)
		void UseHPPotion();
	UFUNCTION(BlueprintCallable)
		void UseManaPotion();
	UFUNCTION(BlueprintCallable)
		void UseSpeedPotion();

	//### Property to handle Speed state of Player
	UPROPERTY(BlueprintReadWrite)
		bool bIsInSpeedState = false;

private:
	/** Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* TopDownCameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** A decal that projects to the cursor location. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UDecalComponent* CursorToWorld;
};

