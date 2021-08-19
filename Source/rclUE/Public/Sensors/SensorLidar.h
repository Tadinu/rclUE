// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <random>

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Msgs/ROS2LaserScanMsg.h"
#include "SensorLidar.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogROS2Sensor, Log, All);

class AROS2Node;
class UROS2Publisher;

#define TRACE_ASYNC 1

UCLASS()
class RCLUE_API ASensorLidar : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASensorLidar();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UFUNCTION()
	void LidarMessageUpdate(UROS2GenericMsg *TopicMessage);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void Run();

	UFUNCTION(BlueprintCallable)
	void Scan();

	UFUNCTION(BlueprintCallable)
	void InitLidar(AROS2Node* Node, FString TopicName);

	UFUNCTION(BlueprintCallable)
	void InitToNode(AROS2Node *Node);

	// adding the rest of the necessary information might be tedious
	// eventually split into multiple getters
	UFUNCTION(BlueprintCallable)
	void GetData(TArray<FHitResult>& hits, float& time);

	// this should probably be removed so that the sensor can be decoupled from the message types
	UFUNCTION(BlueprintCallable)
	FLaserScanData GetROS2Data() const;

	UFUNCTION(BlueprintCallable)
	float GetMinAngleRadians() const;

	UFUNCTION(BlueprintCallable)
	float GetMaxAngleRadians() const;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UROS2Publisher *LidarPublisher;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FString FrameId = FString("scan_base");

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	int nSamplesPerScan;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	int ScanFrequency;

	// [degrees]
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float StartAngle;

	// scan goes from StartAngle to StartAngle+FOVHorizontal
	// [degrees]
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float FOVHorizontal;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float MinRange;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float MaxRange;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Intensity")
	FLinearColor ColorMiss = FColor(255, 127, 0, 255);

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Intensity")
	FLinearColor ColorMin = FColor(255, 0, 0, 255);

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Intensity")
	FLinearColor ColorMid = FColor(255, 0, 0, 255);

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Intensity")
	FColor ColorMax = FColor(255, 255, 255, 255);


	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	float TimeOfLastScan = 0.f;

	// [degrees]
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	float DHAngle;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
  	TArray<FHitResult> RecordedHits;

#if TRACE_ASYNC
 	TArray<FTraceHandle> TraceHandles;
#endif
	
	UPROPERTY()
	FTimerHandle timerHandle;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	bool ShowLidarRays = true;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Intensity")
	float IntensityNonReflective = 1000;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Intensity")
	float IntensityReflective = 6000;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Intensity")
	float IntensityMin = 0;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Intensity")
	float IntensityMax = 10000;

	FLinearColor GetColorFromIntensity(const float Intensity);

private:
	float dt;

	// C++11 RNG for noise
	std::random_device Rng;
	std::mt19937 Gen;
	std::normal_distribution<> GaussianRNGPosition;
	std::normal_distribution<> GaussianRNGIntensity;

	UPROPERTY(EditAnywhere)
	float PositionalNoiseMean = 0;
	
	UPROPERTY(EditAnywhere)
	float PositionalNoiseVariance = 1;

	UPROPERTY(EditAnywhere)
	float IntensityNoiseMean = 0;
	
	UPROPERTY(EditAnywhere)
	float IntensityNoiseVariance = .1;

	FLinearColor InterpolateColor(float x);
};
