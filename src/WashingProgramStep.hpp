#pragma once

class WashingProgramStep{
public:
	int rotationSpeed;
	int waterLevel;
	int temperature;
	int duration;

	bool operator==(WashingProgramStep& rhs){
		return rhs.rotationSpeed == rotationSpeed && rhs.waterLevel == waterLevel && rhs.temperature == temperature && rhs.duration == duration;
	}

	bool operator!=(WashingProgramStep& rhs){
		return rhs.rotationSpeed != rotationSpeed || rhs.waterLevel != waterLevel || rhs.temperature != temperature || rhs.duration != duration;
	}
};
