// Copyright 2021 Rapyuta Robotics Co., Ltd.
// This code has been autogenerated from example_interfaces/msg/WString.msg - do
// not modify

#pragma once

// UE
#include "CoreMinimal.h"

// ROS
#include "example_interfaces/msg/w_string.h"

// rclUE
#include "Msgs/ROS2GenericMsg.h"
#include "rclcUtilities.h"

// Generated Msg/Srv/Action(can be empty)

// Generated
#include "ROS2WStr.generated.h"

USTRUCT(Blueprintable)
struct RCLUE_API FROSWStr {
  GENERATED_BODY()

public:
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  FString Data;

  FROSWStr() {}

  void SetFromROS2(const example_interfaces__msg__WString &in_ros_data) {
    Data = UROS2Utils::StringROSToUE<rosidl_runtime_c__U16String>(
        in_ros_data.data);
  }

  void SetROS2(example_interfaces__msg__WString &out_ros_data) const {
    UROS2Utils::StringUEToROS<rosidl_runtime_c__U16String>(Data,
                                                           out_ros_data.data);
  }
};

UCLASS()
class RCLUE_API UROS2WStrMsg : public UROS2GenericMsg {
  GENERATED_BODY()

public:
  virtual void Init() override;
  virtual void Fini() override;

  virtual const rosidl_message_type_support_t *GetTypeSupport() const override;

  UFUNCTION(BlueprintCallable)
  void SetMsg(const FROSWStr &Input);

  UFUNCTION(BlueprintCallable)
  void GetMsg(FROSWStr &Output) const;

  virtual void *Get() override;

private:
  virtual FString MsgToString() const override;

  example_interfaces__msg__WString w_string_msg;
};