
void goForward(int distInCm){
	float target = 751;//(360 / 3.77) * (distInCm / );
	nMotorEncoder[motorA] = 0;
	nMotorEncoder[motorB] = 0;

	while(true){
		motor[motorA] = 40;
		motor[motorB] = 40;

		if(nMotorEncoder[motorA] == target){
			break;
		}

	}

  motor[motorA] = motor[motorB] = 0;
  wait1Msec(2000); // wait for complete stop
  displayTextLine(4, "Actual:%4d  %4d", nMotorEncoder[motorA],nMotorEncoder[motorB]);
}


task main()
{
	int distInCm = 20; // travel 20 cm
	goForward(distInCm);

	wait1Msec(3000);

}
