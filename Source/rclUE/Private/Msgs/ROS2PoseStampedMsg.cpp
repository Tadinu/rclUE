// Copyright 2021 Rapyuta Robotics Co., Ltd.
// This code has been autogenerated from geometry_msgs/PoseStamped.msg - do not modify

#include "Msgs/ROS2PoseStampedMsg.h"

#include "Kismet/GameplayStatics.h"

void UROS2PoseStampedMsg::Init()
{
	geometry_msgs__msg__PoseStamped__init(&pose_stamped_msg);
}

void UROS2PoseStampedMsg::Fini()
{
	geometry_msgs__msg__PoseStamped__fini(&pose_stamped_msg);
}

const rosidl_message_type_support_t* UROS2PoseStampedMsg::GetTypeSupport() const
{
	return ROSIDL_GET_MSG_TYPE_SUPPORT(geometry_msgs, msg, PoseStamped);
}

void UROS2PoseStampedMsg::SetMsg(const FROSPoseStamped Inputs)
{
    Inputs.SetROS2(pose_stamped_msg);
}

void UROS2PoseStampedMsg::GetMsg(FROSPoseStamped& Outputs) const
{
    Outputs.SetFromROS2(pose_stamped_msg);
}

void* UROS2PoseStampedMsg::Get()
{
	return &pose_stamped_msg;
}

FString UROS2PoseStampedMsg::MsgToString() const
{
    /* TODO: Fill here */
	checkNoEntry();
	return FString();
}