// Copyright 2021 Rapyuta Robotics Co., Ltd.
// This code has been autogenerated from tf2_msgs/msg/TFMessage.msg - do not modify

#pragma once

#include <CoreMinimal.h>

#include "tf2_msgs/msg/tf_message.h"

#include "Msgs/ROS2GenericMsg.h"
#include "rclcUtilities.h"

#include "ROS2TFMessageMsg.generated.h"

USTRUCT(Blueprintable)
struct RCLUE_API FROSTFMessage
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> TransformsHeaderStampSec;

	UPROPERTY(EditAnywhere)
	TArray<unsigned int> TransformsHeaderStampNanosec;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> TransformsHeaderFrameId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> TransformsChildFrameId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FVector> TransformsTransformTranslation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FQuat> TransformsTransformRotation;

	

	void SetFromROS2(const tf2_msgs__msg__TFMessage& in_ros_data)
	{
    	for (auto i = 0; i < in_ros_data.transforms.size; ++i)
		{
			TransformsHeaderStampSec.Emplace(in_ros_data.transforms.data[i].header.stamp.sec);
		}

		for (auto i = 0; i < in_ros_data.transforms.size; ++i)
		{
			TransformsHeaderStampNanosec.Emplace(in_ros_data.transforms.data[i].header.stamp.nanosec);
		}

		for (auto i = 0; i < in_ros_data.transforms.size; ++i)
		{
			TransformsHeaderFrameId.Emplace("");
			TransformsHeaderFrameId[i].AppendChars(in_ros_data.transforms.data[i].header.frame_id.data,in_ros_data.transforms.data[i].header.frame_id.size);
		}

		for (auto i = 0; i < in_ros_data.transforms.size; ++i)
		{
			TransformsChildFrameId.Emplace("");
			TransformsChildFrameId[i].AppendChars(in_ros_data.transforms.data[i].child_frame_id.data,in_ros_data.transforms.data[i].child_frame_id.size);
		}

		for (auto i = 0; i < in_ros_data.transforms.size; ++i)
		{
			TransformsTransformTranslation.Emplace(FVector::ZeroVector);
			TransformsTransformTranslation[i].X = in_ros_data.transforms.data[i].transform.translation.x;
			TransformsTransformTranslation[i].Y = in_ros_data.transforms.data[i].transform.translation.y;
			TransformsTransformTranslation[i].Z = in_ros_data.transforms.data[i].transform.translation.z;
		}

		for (auto i = 0; i < in_ros_data.transforms.size; ++i)
		{
			TransformsTransformRotation.Emplace(FQuat::Identity);
			TransformsTransformRotation[i].X = in_ros_data.transforms.data[i].transform.rotation.x;
			TransformsTransformRotation[i].Y = in_ros_data.transforms.data[i].transform.rotation.y;
			TransformsTransformRotation[i].Z = in_ros_data.transforms.data[i].transform.rotation.z;
			TransformsTransformRotation[i].W = in_ros_data.transforms.data[i].transform.rotation.w;
		}

		
	}

	void SetROS2(tf2_msgs__msg__TFMessage& out_ros_data) const
	{
    	if (out_ros_data.transforms.data != nullptr)
		{
			free(out_ros_data.transforms.data);
		}
		out_ros_data.transforms.data = (decltype(out_ros_data.transforms.data))malloc(TransformsHeaderStampSec.Num() * (sizeof(TransformsHeaderStampSec) + sizeof(TransformsHeaderStampNanosec) + sizeof(TransformsHeaderFrameId) + sizeof(TransformsChildFrameId) + sizeof(TransformsTransformTranslation) + sizeof(TransformsTransformRotation)));
		out_ros_data.transforms.size = TransformsHeaderStampSec.Num();
		out_ros_data.transforms.capacity = TransformsHeaderStampSec.Num();
		for (auto i = 0; i < TransformsHeaderStampSec.Num(); ++i)
		{
			out_ros_data.transforms.data[i].header.stamp.sec = TransformsHeaderStampSec[i];

			out_ros_data.transforms.data[i].header.stamp.nanosec = TransformsHeaderStampNanosec[i];

			{
				FTCHARToUTF8 strUtf8( *TransformsHeaderFrameId[i] );
			int32 strLength = strUtf8.Length();
				out_ros_data.transforms.data[i].header.frame_id.data = (decltype(out_ros_data.transforms.data[i].header.frame_id.data))malloc((strLength+1)*sizeof(decltype(*out_ros_data.transforms.data[i].header.frame_id.data)));
		memcpy(out_ros_data.transforms.data[i].header.frame_id.data, TCHAR_TO_UTF8(*TransformsHeaderFrameId[i]), (strLength+1)*sizeof(char));
				out_ros_data.transforms.data[i].header.frame_id.size = strLength;
				out_ros_data.transforms.data[i].header.frame_id.capacity = strLength + 1;
			}

			{
				FTCHARToUTF8 strUtf8( *TransformsChildFrameId[i] );
			int32 strLength = strUtf8.Length();
				out_ros_data.transforms.data[i].child_frame_id.data = (decltype(out_ros_data.transforms.data[i].child_frame_id.data))malloc((strLength+1)*sizeof(decltype(*out_ros_data.transforms.data[i].child_frame_id.data)));
		memcpy(out_ros_data.transforms.data[i].child_frame_id.data, TCHAR_TO_UTF8(*TransformsChildFrameId[i]), (strLength+1)*sizeof(char));
				out_ros_data.transforms.data[i].child_frame_id.size = strLength;
				out_ros_data.transforms.data[i].child_frame_id.capacity = strLength + 1;
			}

			out_ros_data.transforms.data[i].transform.translation.x = TransformsTransformTranslation[i].X;
			out_ros_data.transforms.data[i].transform.translation.y = TransformsTransformTranslation[i].Y;
			out_ros_data.transforms.data[i].transform.translation.z = TransformsTransformTranslation[i].Z;

			out_ros_data.transforms.data[i].transform.rotation.x = TransformsTransformRotation[i].X;
			out_ros_data.transforms.data[i].transform.rotation.y = TransformsTransformRotation[i].Y;
			out_ros_data.transforms.data[i].transform.rotation.z = TransformsTransformRotation[i].Z;
			out_ros_data.transforms.data[i].transform.rotation.w = TransformsTransformRotation[i].W;

			}
	
	}
};

UCLASS()
class RCLUE_API UROS2TFMessageMsg : public UROS2GenericMsg
{
	GENERATED_BODY()

public:
	virtual void Init() override;
	virtual void Fini() override;

	virtual const rosidl_message_type_support_t* GetTypeSupport() const override;
	
  	UFUNCTION(BlueprintCallable)
	void SetMsg(const FROSTFMessage& Input);
	
  	UFUNCTION(BlueprintCallable)
	void GetMsg(FROSTFMessage& Output) const;
	
	virtual void* Get() override;

private:
	virtual FString MsgToString() const override;

	tf2_msgs__msg__TFMessage tf_message_msg;
};