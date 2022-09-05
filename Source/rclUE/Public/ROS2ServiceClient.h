/**
 * @file ROS2ServiceClient.h
 * @brief Class implementing ROS2 service clients.
 *  Service type is defined by SrvClass
 * @copyright Copyright 2020-2022 Rapyuta Robotics Co., Ltd.
 */

// Class implementing ROS2 service clients
// Service type is defined by SrvClass

#pragma once

// UE
#include "Components/ActorComponent.h"
#include "CoreMinimal.h"

// rclUE
#include "ROS2NodeComponent.h"
#include "ROS2Service.h"
#include "Srvs/ROS2GenericSrv.h"

#include "ROS2ServiceClient.generated.h"

//! Servoce call back delegate.  BP requires a custom-made callback thus it must be Dynamic
DECLARE_DYNAMIC_DELEGATE_OneParam(FServiceClientCallback, UROS2GenericSrv*, InService);
/**
 * @brief Class implementing ROS2 service clients.
 *  Service type is defined by SrvClass
 *
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class RCLUE_API UROS2ServiceClient : public UROS2Service
{
    GENERATED_BODY()

public:

    /**
     * @brief Destroy publisher with rcl_client_fini
     *
     */
    virtual void Destroy();

    /**
     * @brief Update Srv with delegate and send request.
     *
     */
    UFUNCTION(BlueprintCallable)
    void UpdateAndSendRequest();

    /**
     * @brief Determine the relevant action client functions to call.
     *
     * @param wait_set
     */
    virtual void ProcessReady() override;

    //! used to pass data for the request
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FServiceClientCallback RequestDelegate;

    //! used to receive the answer
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FServiceClientCallback ResponseDelegate;

    //! ROS2 Service client
    rcl_client_t client;

    //! Service is ready or not
    bool Ready;

    UFUNCTION(BlueprintCallable)
    void SetDelegates(const FServiceClientCallback& InRequestDelegate, const FServiceClientCallback& InResponseCallback);

protected :

    /**
     * @brief Send service request
     *
     */
    UFUNCTION() 
    void SendRequest();

    const void* req;
    const void* res;

    /**
     * @brief Initialize ROS2 action client with rcl_action_client_init.
     * Set QOS for all goal, result, cancel, feedback and status
     *
     * @param QoS Quality of Service
     * @sa [ROS2 QoS](https://docs.ros.org/en/rolling/Concepts/About-Quality-of-Service-Settings.html)
     */
    virtual void InitializeServiceComponent(const TEnumAsByte<UROS2QoS> QoS) override;
};
