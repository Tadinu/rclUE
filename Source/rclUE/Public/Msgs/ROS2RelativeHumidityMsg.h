// Copyright 2021 Rapyuta Robotics Co., Ltd.
// This code has been autogenerated from sensor_msgs/RelativeHumidity.msg - do not modify

#pragma once

#include "CoreMinimal.h"

#include "sensor_msgs/msg/relative_humidity.h"

#include "Msgs/ROS2GenericMsg.h"
#include "rclcUtilities.h"

#include "ROS2RelativeHumidityMsg.generated.h"

USTRUCT(Blueprintable)
struct RCLUE_API FROSRelativeHumidity
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int header_stamp_sec;

	unsigned int header_stamp_nanosec;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString header_frame_id;

	double relative_humidity;

	double variance;

	

	void SetFromROS2(sensor_msgs__msg__RelativeHumidity rosdata)
	{
    	header_stamp_sec = rosdata.header.stamp.sec;

		header_stamp_nanosec = rosdata.header.stamp.nanosec;

		header_frame_id.AppendChars(rosdata.header.frame_id.data, rosdata.header.frame_id.size);

		relative_humidity = rosdata.relative_humidity;

		variance = rosdata.variance;

		
	}

	void SetROS2(sensor_msgs__msg__RelativeHumidity& rosdata) const
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

		rosdata.relative_humidity = relative_humidity;

		rosdata.variance = variance;

		
	}
};

UCLASS()
class RCLUE_API UROS2RelativeHumidityMsg : public UROS2GenericMsg
{
	GENERATED_BODY()

public:
	virtual void Init() override;
	virtual void Fini() override;

	virtual const rosidl_message_type_support_t* GetTypeSupport() const override;
	
  	UFUNCTION(BlueprintCallable)
	void SetMsg(const FROSRelativeHumidity Input);
	
  	UFUNCTION(BlueprintCallable)
	void GetMsg(FROSRelativeHumidity& Output) const;
	
	virtual void* Get() override;

private:
	virtual FString MsgToString() const override;

	sensor_msgs__msg__RelativeHumidity relative_humidity_msg;
};