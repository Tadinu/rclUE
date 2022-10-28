// Copyright 2021 Rapyuta Robotics Co., Ltd.
// This code has been autogenerated from ue_msgs/srv/GetBoolFromId.srv - do not
// modify

#pragma once

// UE
#include "CoreMinimal.h"

// ROS
#include "ue_msgs/srv/get_bool_from_id.h"

// rclUE
#include "Srvs/ROS2GenericSrv.h"
#include "rclcUtilities.h"

// Generated Msg/Srv/Action(can be empty)

// Generated
#include "ROS2GetBoolFromId.generated.h"

// potential problem: if this struct is defined multiple times!
USTRUCT(Blueprintable)
struct RCLUE_API FROSGetBoolFromIdReq {
  GENERATED_BODY()

public:
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  int Id = 0;

  FROSGetBoolFromIdReq() {}

  void SetFromROS2(const ue_msgs__srv__GetBoolFromId_Request &in_ros_data) {
    Id = in_ros_data.id;
  }

  void SetROS2(ue_msgs__srv__GetBoolFromId_Request &out_ros_data) const {
    out_ros_data.id = Id;
  }
};

USTRUCT(Blueprintable)
struct RCLUE_API FROSGetBoolFromIdRes {
  GENERATED_BODY()

public:
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  bool bSuccess = false;

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  FString Remarks;

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  bool bData = false;

  FROSGetBoolFromIdRes() {}

  void SetFromROS2(const ue_msgs__srv__GetBoolFromId_Response &in_ros_data) {
    bSuccess = in_ros_data.success;

    Remarks = UROS2Utils::StringROSToUE<rosidl_runtime_c__String>(
        in_ros_data.remarks);

    bData = in_ros_data.data;
  }

  void SetROS2(ue_msgs__srv__GetBoolFromId_Response &out_ros_data) const {
    out_ros_data.success = bSuccess;

    UROS2Utils::StringUEToROS<rosidl_runtime_c__String>(Remarks,
                                                        out_ros_data.remarks);

    out_ros_data.data = bData;
  }
};

UCLASS()
class RCLUE_API UROS2GetBoolFromIdSrv : public UROS2GenericSrv {
  GENERATED_BODY()

public:
  UFUNCTION(BlueprintCallable)
  virtual void Init() override;

  UFUNCTION(BlueprintCallable)
  virtual void Fini() override;

  virtual const rosidl_service_type_support_t *GetTypeSupport() const override;

  // used by client
  UFUNCTION(BlueprintCallable)
  void SetRequest(const FROSGetBoolFromIdReq &Request);

  // used by service
  UFUNCTION(BlueprintCallable)
  void GetRequest(FROSGetBoolFromIdReq &Request) const;

  // used by service
  UFUNCTION(BlueprintCallable)
  void SetResponse(const FROSGetBoolFromIdRes &Response);

  // used by client
  UFUNCTION(BlueprintCallable)
  void GetResponse(FROSGetBoolFromIdRes &Response) const;

  virtual void *GetRequest() override;
  virtual void *GetResponse() override;

private:
  virtual FString SrvRequestToString() const override;
  virtual FString SrvResponseToString() const override;

  ue_msgs__srv__GetBoolFromId_Request GetBoolFromId_req;
  ue_msgs__srv__GetBoolFromId_Response GetBoolFromId_res;
};