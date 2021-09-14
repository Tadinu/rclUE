// Copyright 2021 Rapyuta Robotics Co., Ltd.
// This code has been autogenerated from sensor_msgs/Illuminance.msg - do not modify

#pragma once

#include <CoreMinimal.h>

#include "sensor_msgs/msg/illuminance.h"

#include "Msgs/ROS2GenericMsg.h"
#include "rclcUtilities.h"

#include "ROS2IlluminanceMsg.generated.h"

USTRUCT(Blueprintable)
struct RCLUE_API FROSIlluminance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int header_stamp_sec;

	unsigned int header_stamp_nanosec;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString header_frame_id;

	double illuminance;

	double variance;

	

	void SetFromROS2(const sensor_msgs__msg__Illuminance& in_ros_data)
	{
    	header_stamp_sec = in_ros_data.header.stamp.sec;

		header_stamp_nanosec = in_ros_data.header.stamp.nanosec;

		header_frame_id.AppendChars(in_ros_data.header.frame_id.data, in_ros_data.header.frame_id.size);

		illuminance = in_ros_data.illuminance;

		variance = in_ros_data.variance;

		
	}

	void SetROS2(sensor_msgs__msg__Illuminance& out_ros_data) const
	{
    	out_ros_data.header.stamp.sec = header_stamp_sec;

		out_ros_data.header.stamp.nanosec = header_stamp_nanosec;

		{
			FTCHARToUTF8 strUtf8( *header_frame_id );
			int32 strLength = strUtf8.Length();
			if (out_ros_data.header.frame_id.data != nullptr)
		{
			free(out_ros_data.header.frame_id.data);
		}
		out_ros_data.header.frame_id.data = (decltype(out_ros_data.header.frame_id.data))malloc((strLength+1)*sizeof(decltype(*out_ros_data.header.frame_id.data)));
		memcpy(out_ros_data.header.frame_id.data, TCHAR_TO_UTF8(*header_frame_id), (strLength+1)*sizeof(char));
			out_ros_data.header.frame_id.size = strLength;
			out_ros_data.header.frame_id.capacity = strLength + 1;
		}

		out_ros_data.illuminance = illuminance;

		out_ros_data.variance = variance;

		
	}
};

UCLASS()
class RCLUE_API UROS2IlluminanceMsg : public UROS2GenericMsg
{
	GENERATED_BODY()

public:
	virtual void Init() override;
	virtual void Fini() override;

	virtual const rosidl_message_type_support_t* GetTypeSupport() const override;
	
  	UFUNCTION(BlueprintCallable)
	void SetMsg(const FROSIlluminance& Input);
	
  	UFUNCTION(BlueprintCallable)
	void GetMsg(FROSIlluminance& Output) const;
	
	virtual void* Get() override;

private:
	virtual FString MsgToString() const override;

	sensor_msgs__msg__Illuminance illuminance_msg;
};