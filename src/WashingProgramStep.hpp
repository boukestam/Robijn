#pragma once

/**
 * @class WashingProgramStep
 * @author Waila Woe 
 * @date 21/01/16
 * @file WashingProgramStep.hpp
 * @brief A step in a washing program
 */

class WashingProgramStep{
public:
	//! Rotation speed
	int rotationSpeed;
	
	//! Water level
	int waterLevel;
	
	//! Temperature
	int temperature;
	
	//! Duration of step
	int duration;
	
	//! Interval between rotation switch (left or right)
    int rotationInterval;

	//! Equals operator
	bool operator==(WashingProgramStep& rhs){
		return rhs.rotationSpeed == rotationSpeed && rhs.waterLevel == waterLevel && rhs.temperature == temperature && rhs.duration == duration;
	}

	//! Not equals operator
	bool operator!=(WashingProgramStep& rhs){
		return rhs.rotationSpeed != rotationSpeed || rhs.waterLevel != waterLevel || rhs.temperature != temperature || rhs.duration != duration;
	}
};
