// Copyright 2021 Rapyuta Robotics Co., Ltd.
// This code has been autogenerated from sensor_msgs/msg/MultiDOFJointState.msg
// - do not modify

#pragma once

// UE
#include "CoreMinimal.h"

// ROS
#include "sensor_msgs/msg/multi_dof_joint_state.h"

// rclUE
#include "Msgs/ROS2GenericMsg.h"
#include "rclcUtilities.h"

// Generated Msg/Srv/Action(can be empty)
#include "Msgs/ROS2Header.h"
#include "Msgs/ROS2Twist.h"
#include "Msgs/ROS2Wrench.h"

// Generated
#include "ROS2MultiDOFJointState.generated.h"

USTRUCT(Blueprintable)
struct RCLUE_API FROSMultiDOFJointState {
  GENERATED_BODY()

public:
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  FROSHeader Header;

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  TArray<FString> JointNames;

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  TArray<FTransform> Transforms;

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  TArray<FROSTwist> Twist;

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  TArray<FROSWrench> Wrench;

  FROSMultiDOFJointState() {}

  void SetFromROS2(const sensor_msgs__msg__MultiDOFJointState &in_ros_data) {
    Header.SetFromROS2(in_ros_data.header);

    UROS2Utils::StringSequenceROSToUEArray<rosidl_runtime_c__String>(
        in_ros_data.joint_names.data, JointNames, in_ros_data.joint_names.size);

    UROS2Utils::TransformSequenceROSToUEArray(
        in_ros_data.transforms.data, Transforms, in_ros_data.transforms.size);

    UROS2Utils::SequenceROSToUEArray<geometry_msgs__msg__Twist, FROSTwist>(
        in_ros_data.twist.data, Twist, in_ros_data.twist.size);

    UROS2Utils::SequenceROSToUEArray<geometry_msgs__msg__Wrench, FROSWrench>(
        in_ros_data.wrench.data, Wrench, in_ros_data.wrench.size);
  }

  void SetROS2(sensor_msgs__msg__MultiDOFJointState &out_ros_data) const {
    Header.SetROS2(out_ros_data.header);

    UROS2Utils::ROSSequenceResourceAllocation<
        rosidl_runtime_c__String__Sequence>(out_ros_data.joint_names,
                                            JointNames.Num());
    UROS2Utils::StringArrayUEToROSSequence<rosidl_runtime_c__String>(
        JointNames, out_ros_data.joint_names.data, JointNames.Num());

    UROS2Utils::ROSSequenceResourceAllocation<
        geometry_msgs__msg__Transform__Sequence>(out_ros_data.transforms,
                                                 Transforms.Num());
    UROS2Utils::TransformArrayUEToROSSequence(
        Transforms, out_ros_data.transforms.data, Transforms.Num());

    UROS2Utils::ROSSequenceResourceAllocation<
        geometry_msgs__msg__Twist__Sequence>(out_ros_data.twist, Twist.Num());
    UROS2Utils::ArrayUEToROSSequence<geometry_msgs__msg__Twist, FROSTwist>(
        Twist, out_ros_data.twist.data, Twist.Num());

    UROS2Utils::ROSSequenceResourceAllocation<
        geometry_msgs__msg__Wrench__Sequence>(out_ros_data.wrench,
                                              Wrench.Num());
    UROS2Utils::ArrayUEToROSSequence<geometry_msgs__msg__Wrench, FROSWrench>(
        Wrench, out_ros_data.wrench.data, Wrench.Num());
  }
};

UCLASS()
class RCLUE_API UROS2MultiDOFJointStateMsg : public UROS2GenericMsg {
  GENERATED_BODY()

public:
  virtual void Init() override;
  virtual void Fini() override;

  virtual const rosidl_message_type_support_t *GetTypeSupport() const override;

  UFUNCTION(BlueprintCallable)
  void SetMsg(const FROSMultiDOFJointState &Input);

  UFUNCTION(BlueprintCallable)
  void GetMsg(FROSMultiDOFJointState &Output) const;

  virtual void *Get() override;

private:
  virtual FString MsgToString() const override;

  sensor_msgs__msg__MultiDOFJointState multi_dof_joint_state_msg;
};