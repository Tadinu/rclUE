// Fill out your copyright notice in the Description page of Project Settings.


#include "ROS2ActionServer.h"


// Sets default values for this component's properties
UROS2ActionServer::UROS2ActionServer() : Super()
{
}

void UROS2ActionServer::InitializeActionComponent()
{
	const rosidl_action_type_support_t * action_type_support = Action->GetTypeSupport();

	server = rcl_action_get_zero_initialized_server();
	rcl_action_server_options_t server_opt = rcl_action_server_get_default_options();
	rcl_allocator_t allocator = rcl_get_default_allocator();
	rcl_ret_t rc = rcl_ros_clock_init(&ros_clock, &allocator);
	rc = rcl_action_server_init(&server, ownerNode->GetNode(), &ros_clock, action_type_support, TCHAR_TO_ANSI(*ActionName), &server_opt);
	
	if (rc != RCL_RET_OK)
	{
		UE_LOG(LogTemp, Error, TEXT("Failed status on line %d: %d (ROS2ActionServer). Terminating."),__LINE__,(int)rc);
		UKismetSystemLibrary::QuitGame(GetOwner()->GetWorld(), nullptr, EQuitPreference::Quit, true);
	}

	ensure(rcl_action_server_is_valid(&server));
}

void UROS2ActionServer::Destroy()
{
	Super::Destroy();

	if (ownerNode != nullptr)
	{
		RCSOFTCHECK(rcl_action_server_fini(&server, ownerNode->GetNode()));
	}
}


void UROS2ActionServer::ProcessReady(rcl_wait_set_t* wait_set)
{
	rcl_ret_t rc = rcl_action_server_wait_set_get_entities_ready(wait_set, &server,
		&GoalRequestReady,
		&CancelRequestReady,
		&ResultRequestReady,
		&GoalExpired);

	if (GoalRequestReady)
	{
		HandleGoalRequestReady();
	}

	if (ResultRequestReady)
	{
		HandleResultRequestReady();
	}

	if (CancelRequestReady)
	{
		HandleCancelRequestReady();
	}

	if (GoalExpired)
	{
		UE_LOG(LogTemp, Error, TEXT("Action Server goal expired not implemented yet"));
		GoalExpired = false;
	}
}


void UROS2ActionServer::SendGoalResponse()
{
	UE_LOG(LogROS2Action, Warning, TEXT("3. Action Server - Send goal response"));
	check(State == UROS2State::Initialized);
	check(IsValid(ownerNode));
	
	ue4_interfaces__action__Fibonacci_SendGoal_Response* GoalResponse = (ue4_interfaces__action__Fibonacci_SendGoal_Response*) Action->GetGoalResponse();
	GoalResponse->accepted = true;
	float TimeOfResponse = UGameplayStatics::GetTimeSeconds(GWorld);
	GoalResponse->stamp.sec = (int32_t)TimeOfResponse;
	unsigned long long ns = (unsigned long long)(TimeOfResponse * 1000000000.0f);
	GoalResponse->stamp.nanosec = (uint32_t)(ns - (GoalResponse->stamp.sec * 1000000000ul));

	RCSOFTCHECK(rcl_action_send_goal_response(&server, &goal_req_id, Action->GetGoalResponse()));
}

void UROS2ActionServer::ProcessAndSendCancelResponse()
{
	UE_LOG(LogROS2Action, Warning, TEXT("C. Action Server - Send cancel response"));
	check(State == UROS2State::Initialized);
	check(IsValid(ownerNode));

	rcl_action_cancel_request_t cancel_request = rcl_action_get_zero_initialized_cancel_request();
	float TimeOfCancelProcess = UGameplayStatics::GetTimeSeconds(GWorld);
	cancel_request.goal_info.stamp.sec = (int32_t)TimeOfCancelProcess;
	unsigned long long ns = (unsigned long long)(TimeOfCancelProcess * 1000000000.0f);
	cancel_request.goal_info.stamp.nanosec = (uint32_t)(ns - (cancel_request.goal_info.stamp.sec * 1000000000ul));
	rcl_action_cancel_response_t cancel_response = rcl_action_get_zero_initialized_cancel_response();
	RCSOFTCHECK(rcl_action_process_cancel_request(&server, &cancel_request, &cancel_response));
	
	action_msgs__srv__CancelGoal_Response* CancelResponse = (action_msgs__srv__CancelGoal_Response*) Action->GetCancelResponse();
	CancelResponse = &cancel_response.msg;
	RCSOFTCHECK(rcl_action_send_cancel_response(&server, &cancel_req_id, Action->GetCancelResponse()));
}

void UROS2ActionServer::UpdateAndSendFeedback()
{
	UE_LOG(LogROS2Action, Warning, TEXT("7. Action Server - Publish feedback"));
	check(State == UROS2State::Initialized);
	check(IsValid(ownerNode));

	UpdateFeedbackDelegate.ExecuteIfBound(Action);

	rcl_ret_t rc = rcl_action_publish_feedback(&server, Action->GetFeedbackMessage());
}

void UROS2ActionServer::UpdateAndSendResult()
{
	UE_LOG(LogROS2Action, Warning, TEXT("9. Action Server - Send result response"));
	check(State == UROS2State::Initialized);
	check(IsValid(ownerNode));

	UpdateResultDelegate.ExecuteIfBound(Action);

	rcl_ret_t rc = rcl_action_send_result_response(&server, &result_req_id, Action->GetResultResponse());
}

void UROS2ActionServer::HandleGoalRequestReady()
{
	UE_LOG(LogROS2Action, Warning, TEXT("2. Action Server - Received goal request"));
	void* data = Action->GetGoalRequest();
	rcl_ret_t rc = rcl_action_take_goal_request(&server, &goal_req_id, data);
	HandleAcceptedDelegate.ExecuteIfBound();
	GoalRequestReady = false;
}

void UROS2ActionServer::HandleResultRequestReady()
{
	UE_LOG(LogROS2Action, Warning, TEXT("6. Action Server (Node) - Received result request"));
	void* data = Action->GetResultRequest();
	rcl_ret_t rc = rcl_action_take_result_request(&server, &result_req_id, data);
	HandleGoalDelegate.ExecuteIfBound(Action);
	ResultRequestReady = false;
}

void UROS2ActionServer::HandleCancelRequestReady()
{
	UE_LOG(LogROS2Action, Warning, TEXT("B. Action Server (Node) - Received cancel action request"));
	void* data = Action->GetCancelRequest();
	rcl_ret_t rc = rcl_action_take_cancel_request(&server, &cancel_req_id, data);
	HandleCancelDelegate.ExecuteIfBound();
	CancelRequestReady = false;
}


void UROS2ActionServer::SetDelegates(FActionCallback UpdateFeedback,
									 FActionCallback UpdateResult, 
									 FActionCallback HandleGoal, 
									 FSimpleCallback HandleCancel, 
									 FSimpleCallback HandleAccepted)
{
	UpdateFeedbackDelegate = UpdateFeedback;
	UpdateResultDelegate = UpdateResult;
	HandleGoalDelegate = HandleGoal;
	HandleCancelDelegate = HandleCancel;
	HandleAcceptedDelegate = HandleAccepted;
}