// Copyright 2021 Rapyuta Robotics Co., Ltd.
// This code has been autogenerated from std_msgs/Empty.msg - do not modify

#pragma once

#include "CoreMinimal.h"

#include "std_msgs/msg/empty.h"

#include "Msgs/ROS2GenericMsg.h"
#include "rclcUtilities.h"

#include "ROS2EmptyMsg.generated.h"

USTRUCT(Blueprintable)
struct RCLUE_API FROSEmpty
{
	GENERATED_BODY()

public:
	

	void SetFromROS2(std_msgs__msg__Empty rosdata)
	{
    	
	}

	void SetROS2(std_msgs__msg__Empty& rosdata) const
	{
    	
	}
};

UCLASS()
class RCLUE_API UROS2EmptyMsg : public UROS2GenericMsg
{
	GENERATED_BODY()

public:
	virtual void Init() override;
	virtual void Fini() override;

	virtual const rosidl_message_type_support_t* GetTypeSupport() const override;
	
  	UFUNCTION(BlueprintCallable)
	void SetMsg(const FROSEmpty Input);
	
  	UFUNCTION(BlueprintCallable)
	void GetMsg(FROSEmpty& Output) const;
	
	virtual void* Get() override;

private:
	virtual FString MsgToString() const override;

	std_msgs__msg__Empty empty_msg;
};