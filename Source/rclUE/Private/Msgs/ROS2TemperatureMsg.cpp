// Copyright 2021 Rapyuta Robotics Co., Ltd.
// This code has been autogenerated from sensor_msgs/Temperature.msg - do not modify

#include "Msgs/ROS2TemperatureMsg.h"

#include "Kismet/GameplayStatics.h"

void UROS2TemperatureMsg::Init()
{
	sensor_msgs__msg__Temperature__init(&temperature_msg);
}

void UROS2TemperatureMsg::Fini()
{
	sensor_msgs__msg__Temperature__fini(&temperature_msg);
}

const rosidl_message_type_support_t* UROS2TemperatureMsg::GetTypeSupport() const
{
	return ROSIDL_GET_MSG_TYPE_SUPPORT(sensor_msgs, msg, Temperature);
}

void UROS2TemperatureMsg::SetMsg(const FROSTemperature Inputs)
{
    Inputs.SetROS2(temperature_msg);
}

void UROS2TemperatureMsg::GetMsg(FROSTemperature& Outputs) const
{
    Outputs.SetFromROS2(temperature_msg);
}

void* UROS2TemperatureMsg::Get()
{
	return &temperature_msg;
}

FString UROS2TemperatureMsg::MsgToString() const
{
    /* TODO: Fill here */
	checkNoEntry();
	return FString();
}