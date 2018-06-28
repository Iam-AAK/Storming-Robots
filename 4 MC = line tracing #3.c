// robot trace a line until it detects an object within 10 cm
// After you have tested out this sample program, you should try to do the
//    exercises listed at the bottom of this code.

#define LM motorA
#define RM motorB

const tSensors Eye = (tSensors) S1;
const tSensors OBSTEYE = (tSensors) S2;

void turnaround(){

	// 180 degree turn

	// 90 degree turn (point)
	motor[LM] = 100;
	motor[RM] = -100;
	wait1Msec(1000);
  motor[LM] = -100;
  motor[RM] = 100;
  wait1Msec(1000);

  // 90 degree turn (point)
  motor[LM] = 100;
	motor[RM] = -100;
	wait1Msec(1000);
  motor[LM] = -100;
  motor[RM] = 100;
  wait1Msec(1000);

}


task main()
{
	int black = 40, white=50;
	int dist = 10;
	int threshold = (black + white)/2;

	SensorType[Eye] = sensorLightActive;
	SensorType[OBSTEYE] = sensorSONAR;

	while(SensorValue[OBSTEYE]> dist)  // check if the ultrasonic sensor detects > dist
	{
		if (SensorValue[Eye] < threshold)
		{ // light sensor detects dark
			motor[RM] = -20;
			motor[LM] = 75;
		}
		else
		{ // light sensor sees bright
			motor[RM] = 75;
			motor[LM] = -20;
		}
	}
	motor[RM] = motor[LM] = 0; // stops


	// Challenge 4
	// turn around and go back to start
	turnaround();

	// go back to start
	while(SensorValue(Eye) < threshold){
		motor[LM] = 50;
		motor[RM] = 50;
	}

	motor[LM] = 0;
	motor[RM] = 0;

}

// Exercise/ Modification: ==================
// Modification 1: ...............
// Program your robot:
// - trace left side of a line until it detects an object within 10 cm
// - make a left turn around to line trace back

// Modification 2: ...............
// Program your robot:
// - trace left side of a line until it detects an object within 10 cm
// - make a right turn around to line trace back

// Modification 3: ...............
// Program your robot:
// - line trace until it detects an object within 10 cm
// - turns around to line trace back and stops when it detects silver tape
