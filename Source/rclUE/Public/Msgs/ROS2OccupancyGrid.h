// Copyright 2021 Rapyuta Robotics Co., Ltd.
// This code has been autogenerated from nav_msgs/msg/OccupancyGrid.msg - do not
// modify

#pragma once

// UE
#include "CoreMinimal.h"

// ROS
#include "nav_msgs/msg/occupancy_grid.h"

// rclUE
#include "Msgs/ROS2GenericMsg.h"
#include "rclcUtilities.h"

// Generated Msg/Srv/Action(can be empty)
#include "Msgs/ROS2Header.h"
#include "Msgs/ROS2MapMetaData.h"

// Generated
#include "ROS2OccupancyGrid.generated.h"

USTRUCT(Blueprintable)
struct RCLUE_API FROSOccupancyGrid {
  GENERATED_BODY()

public:
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  FROSHeader Header;

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  FROSMapMetaData Info;

  UPROPERTY(EditAnywhere)
  TArray<int8> Data;

  FROSOccupancyGrid() {}

  void SetFromROS2(const nav_msgs__msg__OccupancyGrid &in_ros_data) {
    Header.SetFromROS2(in_ros_data.header);

    Info.SetFromROS2(in_ros_data.info);

    UROS2Utils::SequenceROSToUEArray<int8, int8>(in_ros_data.data.data, Data,
                                                 in_ros_data.data.size);
  }

  void SetROS2(nav_msgs__msg__OccupancyGrid &out_ros_data) const {
    Header.SetROS2(out_ros_data.header);

    Info.SetROS2(out_ros_data.info);

    UROS2Utils::ROSSequenceResourceAllocation<rosidl_runtime_c__int8__Sequence>(
        out_ros_data.data, Data.Num());
    UROS2Utils::ArrayUEToROSSequence<int8, int8>(Data, out_ros_data.data.data,
                                                 Data.Num());
  }
};

UCLASS()
class RCLUE_API UROS2OccupancyGridMsg : public UROS2GenericMsg {
  GENERATED_BODY()

public:
  virtual void Init() override;
  virtual void Fini() override;

  virtual const rosidl_message_type_support_t *GetTypeSupport() const override;

  UFUNCTION(BlueprintCallable)
  void SetMsg(const FROSOccupancyGrid &Input);

  UFUNCTION(BlueprintCallable)
  void GetMsg(FROSOccupancyGrid &Output) const;

  virtual void *Get() override;

private:
  virtual FString MsgToString() const override;

  nav_msgs__msg__OccupancyGrid occupancy_grid_msg;
};