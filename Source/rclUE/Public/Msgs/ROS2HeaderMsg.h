// Copyright 2021 Rapyuta Robotics Co., Ltd.
// This code has been autogenerated from std_msgs/Header.msg - do not modify

#pragma once

#include "CoreMinimal.h"

#include "std_msgs/msg/header.h"

#include "Msgs/ROS2GenericMsg.h"
#include "rclcUtilities.h"

#include "ROS2HeaderMsg.generated.h"

USTRUCT(Blueprintable)
struct RCLUE_API FROSHeader
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int stamp_sec;

	unsigned int stamp_nanosec;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString frame_id;

	

	void SetFromROS2(std_msgs__msg__Header rosdata)
	{
    	stamp_sec = rosdata.stamp.sec;

		stamp_nanosec = rosdata.stamp.nanosec;

		frame_id.AppendChars(rosdata.frame_id.data, rosdata.frame_id.size);

		
	}

	void SetROS2(std_msgs__msg__Header& rosdata) const
	{
    	rosdata.stamp.sec = stamp_sec;

		rosdata.stamp.nanosec = stamp_nanosec;

		if (rosdata.frame_id.data != nullptr)
		{
			free(rosdata.frame_id.data);
		}
		rosdata.frame_id.data = (char*)malloc((frame_id.Len()+1)*sizeof(char));
		memcpy(rosdata.frame_id.data, TCHAR_TO_ANSI(*frame_id), (frame_id.Len()+1)*sizeof(char));
		rosdata.frame_id.size = frame_id.Len();
		rosdata.frame_id.capacity = frame_id.Len() + 1;

		
	}
};

UCLASS()
class RCLUE_API UROS2HeaderMsg : public UROS2GenericMsg
{
	GENERATED_BODY()

public:
	virtual void Init() override;
	virtual void Fini() override;

	virtual const rosidl_message_type_support_t* GetTypeSupport() const override;
	
  	UFUNCTION(BlueprintCallable)
	void SetMsg(const FROSHeader Input);
	
  	UFUNCTION(BlueprintCallable)
	void GetMsg(FROSHeader& Output) const;
	
	virtual void* Get() override;

private:
	virtual FString MsgToString() const override;

	std_msgs__msg__Header header_msg;
};