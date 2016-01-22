#pragma once

#include "SocketMessage.hpp"

/**
 * @class WashingProgramStatus
 * @author Waila Woe 
 * @date 21/01/16
 * @file WashingProgramStatus.hpp
 * @brief Status of washing program
 */

class WashingProgramStatus{
public:
	//! Rotation speed
	int rotationSpeed = 0;
	
	//! Water level
	int waterLevel = 0;
	
	//! Temperature
	int temperature = 0;

	//! Current step
	int currentStep = 0;

	//! Total steps in washing program
	int totalSteps = 0;
	
	//! Total time of steps combined
	int totalSteptime = 0;
    
    //! Time since start of program
    int duration = 0;

	//! Status of washing machine
	int status = 0x02;

	//! Returns a SocketMessage
	SocketMessage toSocketMessage();
};
