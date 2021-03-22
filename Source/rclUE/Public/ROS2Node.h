// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Containers/Map.h"

#include "ROS2Context.h"
#include "ROS2Topic.h"

#include "ROS2Node.generated.h"

class UROS2Publisher;

DECLARE_DYNAMIC_DELEGATE_OneParam(FSubscriptionCallback, const UROS2GenericMsg *, Message);

/**
 * ROS2 Node that additionally acts as a factory for Publishers, Subscribers, Clients, Services
 */
UCLASS(Blueprintable)
class RCLUE_API AROS2Node : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AROS2Node();
	~AROS2Node();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
public:
	UFUNCTION(BlueprintCallable)
	void Init();

	rcl_node_t* GetNode();

	UFUNCTION(BlueprintCallable)
	void Subscribe();

	// this is meant as a helper for BP
	UFUNCTION(BlueprintCallable)
	void AddSubscription(FString TopicName, TSubclassOf<UROS2GenericMsg> MsgClass, FSubscriptionCallback Callback);

	UFUNCTION(BlueprintCallable)
	void AddPublisher(UROS2Publisher* Publisher);

	UFUNCTION(BlueprintCallable)
	TMap<FString, FString> GetListOfNodes();

	UFUNCTION(BlueprintCallable)
	TMap<FString, FString> GetListOfTopics();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Name = TEXT("node");
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Namespace = TEXT("ros_global");

	UPROPERTY(VisibleAnywhere,Category="Diagnostics")
	int NSubscriptions = 0;

	UPROPERTY(VisibleAnywhere,Category="Diagnostics")
	int NGuardConditions = 0;

	UPROPERTY(VisibleAnywhere,Category="Diagnostics")
	int NTimers = 0;

	UPROPERTY(VisibleAnywhere,Category="Diagnostics")
	int NClients = 0;

	UPROPERTY(VisibleAnywhere,Category="Diagnostics")
	int NServices = 0;

	UPROPERTY(VisibleAnywhere,Category="Diagnostics")
	int NEvents = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TEnumAsByte<UROS2State> State = UROS2State::Created;

protected:
	UFUNCTION()
	UROS2Context* GetContext();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FString, TSubclassOf<UROS2GenericMsg>> TopicsToSubscribe;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FString, FSubscriptionCallback> TopicsToCallback;		// Are these maps necessary?

	// this will be handled by the executor as anything related to the wait_set
	UFUNCTION() // uint64 is apparently not supported by BP - might need some changes here
	void SpinSome();

	UPROPERTY()
	UROS2Context* context;

	rcl_node_t node;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<UROS2Publisher*> pubs;

	TMap<UROS2GenericMsg *, rcl_subscription_t> subs; // map topic to sub to avoid double subs
	
	UPROPERTY()
	TMap<UROS2GenericMsg *, FSubscriptionCallback> callbacks; // could be combined with above
	
	rcl_wait_set_t wait_set;
	
	UPROPERTY()
	FTimerHandle timerHandle;

	// int NSpinCalls = 0;
	// int NSubMsgGets = 0;

private:
};
