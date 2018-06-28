
task main()
{
	int tm = 500;
	int ct = 0;

	while(ct <5){
		if(ct % 2 == 0){
			motor[motorA] = 10;
			motor[motorB] = 0;

		}else{
			motor[motorA] = 0;
			motor[motorB] = 10;

		}
		wait1Msec(tm*2);
		++ct;
	}



}
