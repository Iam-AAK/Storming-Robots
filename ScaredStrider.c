#pragma config(Sensor, S2,     sonar,          sensorSONAR)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	while(true){ // then walk forward until its within 20 cm of object, then turn around

		if(SensorValue[sonar] < 20){
			// forwards
			motor[motorA] = -50;
			motor[motorB] = 50;
			motor[motorC] = -50;

			}else{// sonar if
			// backwards
			motor[motorA] = 50;
			motor[motorB] = -50;
			motor[motorC] = 50;
			playSound(soundDownwardTones);
		}

	}
}
