
task main()
{
	int ct = 0;

	while(ct < 11){

	motor[motorA] = 20;
	motor[motorB] = 20;

		if(ct % 2 == 0){
			motor[motorA] = 50;
			motor[motorB] = 0;
		}else if(ct % 2 != 0){
			motor[motorA] = 0;
			motor[motorB] = 50;
		}
		++ct;
	}


}
