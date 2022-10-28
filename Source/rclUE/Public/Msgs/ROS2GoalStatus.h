// Copyright 2021 Rapyuta Robotics Co., Ltd.
// This code has been autogenerated from actionlib_msgs/msg/GoalStatus.msg - do
// not modify

#pragma once

// UE
#include "CoreMinimal.h"

// ROS
#include "actionlib_msgs/msg/goal_status.h"

// rclUE
#include "Msgs/ROS2GenericMsg.h"
#include "rclcUtilities.h"

// Generated Msg/Srv/Action(can be empty)
#include "Msgs/ROS2GoalID.h"

// Generated
#include "ROS2GoalStatus.generated.h"

USTRUCT(Blueprintable)
struct RCLUE_API FROSGoalStatus {
  GENERATED_BODY()

public:
  static constexpr uint8 PENDING = 0;
  static constexpr uint8 ACTIVE = 1;
  static constexpr uint8 PREEMPTED = 2;
  static constexpr uint8 SUCCEEDED = 3;
  static constexpr uint8 ABORTED = 4;
  static constexpr uint8 REJECTED = 5;
  static constexpr uint8 PREEMPTING = 6;
  static constexpr uint8 RECALLING = 7;
  static constexpr uint8 RECALLED = 8;
  static constexpr uint8 LOST = 9;

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  FROSGoalID GoalId;

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  uint8 Status = 0;

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  FString Text;

  FROSGoalStatus() {}

  void SetFromROS2(const actionlib_msgs__msg__GoalStatus &in_ros_data) {
    GoalId.SetFromROS2(in_ros_data.goal_id);

    Status = in_ros_data.status;

    Text =
        UROS2Utils::StringROSToUE<rosidl_runtime_c__String>(in_ros_data.text);
  }

  void SetROS2(actionlib_msgs__msg__GoalStatus &out_ros_data) const {
    GoalId.SetROS2(out_ros_data.goal_id);

    out_ros_data.status = Status;

    UROS2Utils::StringUEToROS<rosidl_runtime_c__String>(Text,
                                                        out_ros_data.text);
  }
};

UCLASS()
class RCLUE_API UROS2GoalStatusMsg : public UROS2GenericMsg {
  GENERATED_BODY()

public:
  virtual void Init() override;
  virtual void Fini() override;

  virtual const rosidl_message_type_support_t *GetTypeSupport() const override;

  UFUNCTION(BlueprintCallable)
  void SetMsg(const FROSGoalStatus &Input);

  UFUNCTION(BlueprintCallable)
  void GetMsg(FROSGoalStatus &Output) const;

  virtual void *Get() override;

  UFUNCTION(BlueprintCallable)
  static uint8 CONST_PENDING() { return FROSGoalStatus::PENDING; }
  UFUNCTION(BlueprintCallable)
  static uint8 CONST_ACTIVE() { return FROSGoalStatus::ACTIVE; }
  UFUNCTION(BlueprintCallable)
  static uint8 CONST_PREEMPTED() { return FROSGoalStatus::PREEMPTED; }
  UFUNCTION(BlueprintCallable)
  static uint8 CONST_SUCCEEDED() { return FROSGoalStatus::SUCCEEDED; }
  UFUNCTION(BlueprintCallable)
  static uint8 CONST_ABORTED() { return FROSGoalStatus::ABORTED; }
  UFUNCTION(BlueprintCallable)
  static uint8 CONST_REJECTED() { return FROSGoalStatus::REJECTED; }
  UFUNCTION(BlueprintCallable)
  static uint8 CONST_PREEMPTING() { return FROSGoalStatus::PREEMPTING; }
  UFUNCTION(BlueprintCallable)
  static uint8 CONST_RECALLING() { return FROSGoalStatus::RECALLING; }
  UFUNCTION(BlueprintCallable)
  static uint8 CONST_RECALLED() { return FROSGoalStatus::RECALLED; }
  UFUNCTION(BlueprintCallable)
  static uint8 CONST_LOST() { return FROSGoalStatus::LOST; }

private:
  virtual FString MsgToString() const override;

  actionlib_msgs__msg__GoalStatus goal_status_msg;
};