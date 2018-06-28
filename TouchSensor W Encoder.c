#define  LM  motorA
#define  RM  motorB

const tSensors bumper               = (tSensors) S3;   //sensorTouch        //*!!!!*//

task main()
{
	nMotorEncoder[LM] = 0;
	nMotorEncoder[RM] = 0;

	SensorType[bumper] = sensorTouch;
	SensorType[S2] = sensorSONAR;

	while(true){
		motor[LM] = 20;
		motor[RM] = 20;

		if (SensorValue[S2] < 10){ // within 10 cm of obstacle
     	 playSound(soundBeepBeep);
    }
		if (SensorValue[bumper] == 1)
		{
			break;
		}

		motor[motorC] = 5;
		motor[motorC] = -5;

	}
	clearSounds();
	motor[LM] = 0;
	motor[RM] = 0;

	wait1Msec(2000); // wait for complete stop

	displayTextLine(4, "E.V. :%4d  %4d", nMotorEncoder[LM],nMotorEncoder[RM]);
  displayTextLine(5, "Distance mesured in.");
  displayTextLine(6, "D.T. :%4d  %4d", ((nMotorEncoder[LM]/360) * 9.5758), ((nMotorEncoder[RM]/360) * 9.5758));

  wait1Msec(4000);// wait at the end
}
