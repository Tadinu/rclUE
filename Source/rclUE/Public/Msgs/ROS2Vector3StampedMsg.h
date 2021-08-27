// Copyright 2021 Rapyuta Robotics Co., Ltd.
// This code has been autogenerated from geometry_msgs/Vector3Stamped.msg - do not modify

#pragma once

#include "CoreMinimal.h"

#include "geometry_msgs/msg/vector3_stamped.h"

#include "Msgs/ROS2GenericMsg.h"
#include "rclcUtilities.h"

#include "ROS2Vector3StampedMsg.generated.h"

USTRUCT(Blueprintable)
struct RCLUE_API FROSVector3Stamped
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int header_stamp_sec;

	unsigned int header_stamp_nanosec;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString header_frame_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector vector;

	

	void SetFromROS2(geometry_msgs__msg__Vector3Stamped rosdata)
	{
    	header_stamp_sec = rosdata.header.stamp.sec;

		header_stamp_nanosec = rosdata.header.stamp.nanosec;

		header_frame_id.AppendChars(rosdata.header.frame_id.data, rosdata.header.frame_id.size);

		vector.X = rosdata.vector.x;
		vector.Y = rosdata.vector.y;
		vector.Z = rosdata.vector.z;

		
	}

	void SetROS2(geometry_msgs__msg__Vector3Stamped& rosdata) const
	{
    	rosdata.header.stamp.sec = header_stamp_sec;

		rosdata.header.stamp.nanosec = header_stamp_nanosec;

		if (rosdata.header.frame_id.data != nullptr)
		{
			free(rosdata.header.frame_id.data);
		}
		rosdata.header.frame_id.data = (char*)malloc((header_frame_id.Len()+1)*sizeof(char));
		memcpy(rosdata.header.frame_id.data, TCHAR_TO_ANSI(*header_frame_id), (header_frame_id.Len()+1)*sizeof(char));
		rosdata.header.frame_id.size = header_frame_id.Len();
		rosdata.header.frame_id.capacity = header_frame_id.Len() + 1;

		rosdata.vector.x = vector.X;
		rosdata.vector.y = vector.Y;
		rosdata.vector.z = vector.Z;

		
	}
};

UCLASS()
class RCLUE_API UROS2Vector3StampedMsg : public UROS2GenericMsg
{
	GENERATED_BODY()

public:
	virtual void Init() override;
	virtual void Fini() override;

	virtual const rosidl_message_type_support_t* GetTypeSupport() const override;
	
  	UFUNCTION(BlueprintCallable)
	void SetMsg(const FROSVector3Stamped Input);
	
  	UFUNCTION(BlueprintCallable)
	void GetMsg(FROSVector3Stamped& Output) const;
	
	virtual void* Get() override;

private:
	virtual FString MsgToString() const override;

	geometry_msgs__msg__Vector3Stamped vector3_stamped_msg;
};