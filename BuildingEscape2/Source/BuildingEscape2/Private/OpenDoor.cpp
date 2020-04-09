// Social Cube Media 2020


#include "OpenDoor.h"
#include "GameFramework/Actor.h"
#include "Math/Rotator.h"

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

	InitialYaw = GetOwner()->GetActorRotation().Yaw;
	CurrentYaw = InitialYaw;
	TargetYaw += CurrentYaw;
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	UE_LOG(LogTemp, Warning, TEXT("Object is at: %s"), *GetOwner()->GetActorRotation().ToString());
	UE_LOG(LogTemp, Warning, TEXT("Object Yaw is: %f"), GetOwner()->GetActorRotation().Yaw);

	CurrentYaw = FMath::Lerp(CurrentYaw, TargetYaw, DeltaTime * 1.f);
	FRotator DoorRotation = GetOwner()->GetActorRotation();
	DoorRotation.Yaw = CurrentYaw;
	GetOwner()->SetActorRotation(DoorRotation);

	// float CurrentYaw = GetOwner()->GetActorRotation().Yaw;
	// FRotator OpenDoor(0.f, TargetYaw, 0.2f);
	// OpenDoor.Yaw = FMath::FInterpConstantTo(CurrentYaw, TargetYaw, DeltaTime, 45);
	// GetOwner()->SetActorRotation(OpenDoor);
}

