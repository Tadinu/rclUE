// Copyright 2021 Rapyuta Robotics Co., Ltd.
// This code has been autogenerated from nav_msgs/Path.msg - do not modify

#pragma once

#include <CoreMinimal.h>

#include "nav_msgs/msg/path.h"

#include "Msgs/ROS2GenericMsg.h"
#include "rclcUtilities.h"

#include "ROS2PathMsg.generated.h"

USTRUCT(Blueprintable)
struct RCLUE_API FROSPath
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int header_stamp_sec;

	unsigned int header_stamp_nanosec;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString header_frame_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> poses_header_stamp_sec;

	TArray<unsigned int> poses_header_stamp_nanosec;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> poses_header_frame_id;

	TArray<double> poses_pose_position_x;

	TArray<double> poses_pose_position_y;

	TArray<double> poses_pose_position_z;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FQuat> poses_pose_orientation;

	

	void SetFromROS2(const nav_msgs__msg__Path& in_ros_data)
	{
    	header_stamp_sec = in_ros_data.header.stamp.sec;

		header_stamp_nanosec = in_ros_data.header.stamp.nanosec;

		header_frame_id.AppendChars(in_ros_data.header.frame_id.data, in_ros_data.header.frame_id.size);

		for (int i = 0; i < in_ros_data.poses.size; i++)
		{
			poses_header_stamp_sec[i] = in_ros_data.poses.data[i].header.stamp.sec;
		}

		for (int i = 0; i < in_ros_data.poses.size; i++)
		{
			poses_header_stamp_nanosec[i] = in_ros_data.poses.data[i].header.stamp.nanosec;
		}

		for (int i = 0; i < in_ros_data.poses.size; i++)
		{
			poses_header_frame_id[i].AppendChars(in_ros_data.poses.data[i].header.frame_id.data,in_ros_data.poses.data[i].header.frame_id.size);
		}

		for (int i = 0; i < in_ros_data.poses.size; i++)
		{
			poses_pose_position_x[i] = in_ros_data.poses.data[i].pose.position.x;
		}

		for (int i = 0; i < in_ros_data.poses.size; i++)
		{
			poses_pose_position_y[i] = in_ros_data.poses.data[i].pose.position.y;
		}

		for (int i = 0; i < in_ros_data.poses.size; i++)
		{
			poses_pose_position_z[i] = in_ros_data.poses.data[i].pose.position.z;
		}

		for (int i = 0; i < in_ros_data.poses.size; i++)
		{
			poses_pose_orientation[i].X = in_ros_data.poses.data[i].pose.orientation.x;
			poses_pose_orientation[i].Y = in_ros_data.poses.data[i].pose.orientation.y;
			poses_pose_orientation[i].Z = in_ros_data.poses.data[i].pose.orientation.z;
			poses_pose_orientation[i].W = in_ros_data.poses.data[i].pose.orientation.w;
		}

		
	}

	void SetROS2(nav_msgs__msg__Path& out_ros_data) const
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

		if (out_ros_data.poses.data != nullptr)
		{
			free(out_ros_data.poses.data);
		}
		out_ros_data.poses.data = (decltype(out_ros_data.poses.data))malloc((poses_header_stamp_sec.Num())*sizeof(decltype(*out_ros_data.poses.data)));
		
		for (int i = 0; i < poses_header_stamp_sec.Num(); i++)
		{
			out_ros_data.poses.data[i].header.stamp.sec = poses_header_stamp_sec[i];
		}

		out_ros_data.poses.size = poses_header_stamp_sec.Num();
		out_ros_data.poses.capacity = poses_header_stamp_sec.Num();

		if (out_ros_data.poses.data != nullptr)
		{
			free(out_ros_data.poses.data);
		}
		out_ros_data.poses.data = (decltype(out_ros_data.poses.data))malloc((poses_header_stamp_nanosec.Num())*sizeof(decltype(*out_ros_data.poses.data)));
		
		for (int i = 0; i < poses_header_stamp_nanosec.Num(); i++)
		{
			out_ros_data.poses.data[i].header.stamp.nanosec = poses_header_stamp_nanosec[i];
		}

		out_ros_data.poses.size = poses_header_stamp_nanosec.Num();
		out_ros_data.poses.capacity = poses_header_stamp_nanosec.Num();

		for (int i = 0; i < poses_header_frame_id.Num(); i++)
		{
			{
			FTCHARToUTF8 strUtf8( *poses_header_frame_id[i] );
			int32 strLength = strUtf8.Length();
			if (out_ros_data.poses.data != nullptr)
				{
					free(out_ros_data.poses.data);
				}
				out_ros_data.poses.data[i].header.frame_id.data = (char*)malloc((strLength+1)*sizeof(char));
				memcpy(out_ros_data.poses.data[i].header.frame_id.data, TCHAR_TO_UTF8(*poses_header_frame_id[i]), (strLength+1)*sizeof(char));
				out_ros_data.poses.size = strLength;
				out_ros_data.poses.capacity = strLength + 1;
			}
		}

		if (out_ros_data.poses.data != nullptr)
		{
			free(out_ros_data.poses.data);
		}
		out_ros_data.poses.data = (decltype(out_ros_data.poses.data))malloc((poses_pose_position_x.Num())*sizeof(decltype(*out_ros_data.poses.data)));
		
		for (int i = 0; i < poses_pose_position_x.Num(); i++)
		{
			out_ros_data.poses.data[i].pose.position.x = poses_pose_position_x[i];
		}

		out_ros_data.poses.size = poses_pose_position_x.Num();
		out_ros_data.poses.capacity = poses_pose_position_x.Num();

		if (out_ros_data.poses.data != nullptr)
		{
			free(out_ros_data.poses.data);
		}
		out_ros_data.poses.data = (decltype(out_ros_data.poses.data))malloc((poses_pose_position_y.Num())*sizeof(decltype(*out_ros_data.poses.data)));
		
		for (int i = 0; i < poses_pose_position_y.Num(); i++)
		{
			out_ros_data.poses.data[i].pose.position.y = poses_pose_position_y[i];
		}

		out_ros_data.poses.size = poses_pose_position_y.Num();
		out_ros_data.poses.capacity = poses_pose_position_y.Num();

		if (out_ros_data.poses.data != nullptr)
		{
			free(out_ros_data.poses.data);
		}
		out_ros_data.poses.data = (decltype(out_ros_data.poses.data))malloc((poses_pose_position_z.Num())*sizeof(decltype(*out_ros_data.poses.data)));
		
		for (int i = 0; i < poses_pose_position_z.Num(); i++)
		{
			out_ros_data.poses.data[i].pose.position.z = poses_pose_position_z[i];
		}

		out_ros_data.poses.size = poses_pose_position_z.Num();
		out_ros_data.poses.capacity = poses_pose_position_z.Num();

		if (out_ros_data.poses.data != nullptr)
		{
			free(out_ros_data.poses.data);
		}
		out_ros_data.poses.data = (decltype(out_ros_data.poses.data))malloc((poses_pose_orientation.Num() * 4)*sizeof(decltype(*out_ros_data.poses.data)));
		
		for (int i = 0; i < poses_pose_orientation.Num(); i++)
		{
			out_ros_data.poses.data[i].pose.orientation.x = poses_pose_orientation[i].X;
			out_ros_data.poses.data[i].pose.orientation.y = poses_pose_orientation[i].Y;
			out_ros_data.poses.data[i].pose.orientation.z = poses_pose_orientation[i].Z;
			out_ros_data.poses.data[i].pose.orientation.w = poses_pose_orientation[i].W;
		}

		out_ros_data.poses.size = poses_pose_orientation.Num();
		out_ros_data.poses.capacity = poses_pose_orientation.Num();

		
	}
};

UCLASS()
class RCLUE_API UROS2PathMsg : public UROS2GenericMsg
{
	GENERATED_BODY()

public:
	virtual void Init() override;
	virtual void Fini() override;

	virtual const rosidl_message_type_support_t* GetTypeSupport() const override;
	
  	UFUNCTION(BlueprintCallable)
	void SetMsg(const FROSPath& Input);
	
  	UFUNCTION(BlueprintCallable)
	void GetMsg(FROSPath& Output) const;
	
	virtual void* Get() override;

private:
	virtual FString MsgToString() const override;

	nav_msgs__msg__Path path_msg;
};