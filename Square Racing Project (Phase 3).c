
const tSensors bumper               = (tSensors) S3;   //sensorTouch

task main()
{

	SensorType[bumper] = sensorTouch;

	int bumperCount = 0;
	int TurnCount = 0;

	motor[motorA] = 10;
	motor[motorB] = 10;

	while(TurnCount < 4){
			if (SensorValue[bumper] == 1)
		{
			motor[motorA] = 30;
			motor[motorB] = -10;

			++bumperCount;
			++TurnCount;
		}else{
			motor[motorA] = 10;
			motor[motorB] = 10;
		}
	}

		motor[motorA] = 0;
		motor[motorB] = 0;
		wait1Msec(3000);

}
