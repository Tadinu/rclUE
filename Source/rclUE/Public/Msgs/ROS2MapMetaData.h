// Copyright 2021 Rapyuta Robotics Co., Ltd.
// This code has been autogenerated from nav_msgs/msg/MapMetaData.msg - do not
// modify

#pragma once

// UE
#include "CoreMinimal.h"

// ROS
#include "nav_msgs/msg/map_meta_data.h"

// rclUE
#include "Msgs/ROS2GenericMsg.h"
#include "rclcUtilities.h"

// Generated Msg/Srv/Action(can be empty)
#include "Msgs/ROS2Pose.h"
#include "Msgs/ROS2Time.h"

// Generated
#include "ROS2MapMetaData.generated.h"

USTRUCT(Blueprintable)
struct RCLUE_API FROSMapMetaData {
  GENERATED_BODY()

public:
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  FROSTime MapLoadTime;

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  float Resolution = 0.f;

  UPROPERTY(EditAnywhere)
  unsigned int Width = 0;

  UPROPERTY(EditAnywhere)
  unsigned int Height = 0;

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  FROSPose Origin;

  FROSMapMetaData() {}

  void SetFromROS2(const nav_msgs__msg__MapMetaData &in_ros_data) {
    MapLoadTime.SetFromROS2(in_ros_data.map_load_time);

    Resolution = in_ros_data.resolution;

    Width = in_ros_data.width;

    Height = in_ros_data.height;

    Origin.SetFromROS2(in_ros_data.origin);
  }

  void SetROS2(nav_msgs__msg__MapMetaData &out_ros_data) const {
    MapLoadTime.SetROS2(out_ros_data.map_load_time);

    out_ros_data.resolution = Resolution;

    out_ros_data.width = Width;

    out_ros_data.height = Height;

    Origin.SetROS2(out_ros_data.origin);
  }
};

UCLASS()
class RCLUE_API UROS2MapMetaDataMsg : public UROS2GenericMsg {
  GENERATED_BODY()

public:
  virtual void Init() override;
  virtual void Fini() override;

  virtual const rosidl_message_type_support_t *GetTypeSupport() const override;

  UFUNCTION(BlueprintCallable)
  void SetMsg(const FROSMapMetaData &Input);

  UFUNCTION(BlueprintCallable)
  void GetMsg(FROSMapMetaData &Output) const;

  virtual void *Get() override;

private:
  virtual FString MsgToString() const override;

  nav_msgs__msg__MapMetaData map_meta_data_msg;
};