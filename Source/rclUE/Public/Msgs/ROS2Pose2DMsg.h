// Copyright 2021 Rapyuta Robotics Co., Ltd.
// This code has been autogenerated from geometry_msgs/Pose2D.msg - do not modify

#pragma once

#include "CoreMinimal.h"

#include "geometry_msgs/msg/pose2_d.h"

#include "Msgs/ROS2GenericMsg.h"
#include "rclcUtilities.h"

#include "ROS2Pose2DMsg.generated.h"

USTRUCT(Blueprintable)
struct RCLUE_API FROSPose2D
{
	GENERATED_BODY()

public:
	double x;

	double y;

	double theta;

	

	void SetFromROS2(geometry_msgs__msg__Pose2D rosdata)
	{
    	x = rosdata.x;

		y = rosdata.y;

		theta = rosdata.theta;

		
	}

	void SetROS2(geometry_msgs__msg__Pose2D& rosdata) const
	{
    	rosdata.x = x;

		rosdata.y = y;

		rosdata.theta = theta;

		
	}
};

UCLASS()
class RCLUE_API UROS2Pose2DMsg : public UROS2GenericMsg
{
	GENERATED_BODY()

public:
	virtual void Init() override;
	virtual void Fini() override;

	virtual const rosidl_message_type_support_t* GetTypeSupport() const override;
	
  	UFUNCTION(BlueprintCallable)
	void SetMsg(const FROSPose2D Input);
	
  	UFUNCTION(BlueprintCallable)
	void GetMsg(FROSPose2D& Output) const;
	
	virtual void* Get() override;

private:
	virtual FString MsgToString() const override;

	geometry_msgs__msg__Pose2D pose2_d_msg;
};