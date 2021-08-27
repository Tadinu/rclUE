// Copyright 2021 Rapyuta Robotics Co., Ltd.
// This code has been autogenerated from geometry_msgs/PoseArray.msg - do not modify

#pragma once

#include "CoreMinimal.h"

#include "geometry_msgs/msg/pose_array.h"

#include "Msgs/ROS2GenericMsg.h"
#include "rclcUtilities.h"

#include "ROS2PoseArrayMsg.generated.h"

USTRUCT(Blueprintable)
struct RCLUE_API FROSPoseArray
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int header_stamp_sec;

	unsigned int header_stamp_nanosec;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString header_frame_id;

	TArray<double> poses_position_x;

	TArray<double> poses_position_y;

	TArray<double> poses_position_z;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FQuat> poses_orientation;

	

	void SetFromROS2(geometry_msgs__msg__PoseArray rosdata)
	{
    	header_stamp_sec = rosdata.header.stamp.sec;

		header_stamp_nanosec = rosdata.header.stamp.nanosec;

		header_frame_id.AppendChars(rosdata.header.frame_id.data, rosdata.header.frame_id.size);

		for (int i = 0; i < rosdata.poses.size; i++)
		{
			poses_position_x[i] = rosdata.poses.data[i].position.x;
		}

		for (int i = 0; i < rosdata.poses.size; i++)
		{
			poses_position_y[i] = rosdata.poses.data[i].position.y;
		}

		for (int i = 0; i < rosdata.poses.size; i++)
		{
			poses_position_z[i] = rosdata.poses.data[i].position.z;
		}

		for (int i = 0; i < rosdata.poses.size; i++)
		{
			poses_orientation[i].X = rosdata.poses.data[i].orientation.x;
			poses_orientation[i].Y = rosdata.poses.data[i].orientation.y;
			poses_orientation[i].Z = rosdata.poses.data[i].orientation.z;
			poses_orientation[i].W = rosdata.poses.data[i].orientation.w;
		}

		
	}

	void SetROS2(geometry_msgs__msg__PoseArray& rosdata) const
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

		for (int i = 0; i < poses_position_x.Num(); i++)
		{
			rosdata.poses.data[i].position.x = poses_position_x[i];
		}

		for (int i = 0; i < poses_position_y.Num(); i++)
		{
			rosdata.poses.data[i].position.y = poses_position_y[i];
		}

		for (int i = 0; i < poses_position_z.Num(); i++)
		{
			rosdata.poses.data[i].position.z = poses_position_z[i];
		}

		for (int i = 0; i < poses_orientation.Num(); i++)
		{
			rosdata.poses.data[i].orientation.x = poses_orientation[i].X;
			rosdata.poses.data[i].orientation.y = poses_orientation[i].Y;
			rosdata.poses.data[i].orientation.z = poses_orientation[i].Z;
			rosdata.poses.data[i].orientation.w = poses_orientation[i].W;
		}

		
	}
};

UCLASS()
class RCLUE_API UROS2PoseArrayMsg : public UROS2GenericMsg
{
	GENERATED_BODY()

public:
	virtual void Init() override;
	virtual void Fini() override;

	virtual const rosidl_message_type_support_t* GetTypeSupport() const override;
	
  	UFUNCTION(BlueprintCallable)
	void SetMsg(const FROSPoseArray Input);
	
  	UFUNCTION(BlueprintCallable)
	void GetMsg(FROSPoseArray& Output) const;
	
	virtual void* Get() override;

private:
	virtual FString MsgToString() const override;

	geometry_msgs__msg__PoseArray pose_array_msg;
};