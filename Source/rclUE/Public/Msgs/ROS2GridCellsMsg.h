// Copyright 2021 Rapyuta Robotics Co., Ltd.
// This code has been autogenerated from nav_msgs/GridCells.msg - do not modify

#pragma once

#include <CoreMinimal.h>

#include "nav_msgs/msg/grid_cells.h"

#include "Msgs/ROS2GenericMsg.h"
#include "rclcUtilities.h"

#include "ROS2GridCellsMsg.generated.h"

USTRUCT(Blueprintable)
struct RCLUE_API FROSGridCells
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int header_stamp_sec;

	unsigned int header_stamp_nanosec;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString header_frame_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float cell_width;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float cell_height;

	TArray<double> cells_x;

	TArray<double> cells_y;

	TArray<double> cells_z;

	

	void SetFromROS2(const nav_msgs__msg__GridCells& in_ros_data)
	{
    	header_stamp_sec = in_ros_data.header.stamp.sec;

		header_stamp_nanosec = in_ros_data.header.stamp.nanosec;

		header_frame_id.AppendChars(in_ros_data.header.frame_id.data, in_ros_data.header.frame_id.size);

		cell_width = in_ros_data.cell_width;

		cell_height = in_ros_data.cell_height;

		for (int i = 0; i < in_ros_data.cells.size; i++)
		{
			cells_x[i] = in_ros_data.cells.data[i].x;
		}

		for (int i = 0; i < in_ros_data.cells.size; i++)
		{
			cells_y[i] = in_ros_data.cells.data[i].y;
		}

		for (int i = 0; i < in_ros_data.cells.size; i++)
		{
			cells_z[i] = in_ros_data.cells.data[i].z;
		}

		
	}

	void SetROS2(nav_msgs__msg__GridCells& out_ros_data) const
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

		out_ros_data.cell_width = cell_width;

		out_ros_data.cell_height = cell_height;

		if (out_ros_data.cells.data != nullptr)
		{
			free(out_ros_data.cells.data);
		}
		out_ros_data.cells.data = (decltype(out_ros_data.cells.data))malloc((cells_x.Num())*sizeof(decltype(*out_ros_data.cells.data)));
		
		for (int i = 0; i < cells_x.Num(); i++)
		{
			out_ros_data.cells.data[i].x = cells_x[i];
		}

		out_ros_data.cells.size = cells_x.Num();
		out_ros_data.cells.capacity = cells_x.Num();

		if (out_ros_data.cells.data != nullptr)
		{
			free(out_ros_data.cells.data);
		}
		out_ros_data.cells.data = (decltype(out_ros_data.cells.data))malloc((cells_y.Num())*sizeof(decltype(*out_ros_data.cells.data)));
		
		for (int i = 0; i < cells_y.Num(); i++)
		{
			out_ros_data.cells.data[i].y = cells_y[i];
		}

		out_ros_data.cells.size = cells_y.Num();
		out_ros_data.cells.capacity = cells_y.Num();

		if (out_ros_data.cells.data != nullptr)
		{
			free(out_ros_data.cells.data);
		}
		out_ros_data.cells.data = (decltype(out_ros_data.cells.data))malloc((cells_z.Num())*sizeof(decltype(*out_ros_data.cells.data)));
		
		for (int i = 0; i < cells_z.Num(); i++)
		{
			out_ros_data.cells.data[i].z = cells_z[i];
		}

		out_ros_data.cells.size = cells_z.Num();
		out_ros_data.cells.capacity = cells_z.Num();

		
	}
};

UCLASS()
class RCLUE_API UROS2GridCellsMsg : public UROS2GenericMsg
{
	GENERATED_BODY()

public:
	virtual void Init() override;
	virtual void Fini() override;

	virtual const rosidl_message_type_support_t* GetTypeSupport() const override;
	
  	UFUNCTION(BlueprintCallable)
	void SetMsg(const FROSGridCells& Input);
	
  	UFUNCTION(BlueprintCallable)
	void GetMsg(FROSGridCells& Output) const;
	
	virtual void* Get() override;

private:
	virtual FString MsgToString() const override;

	nav_msgs__msg__GridCells grid_cells_msg;
};