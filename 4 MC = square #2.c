// forwards
void forward(){
	motor[motorA] = 20;
	motor[motorB] = 20;
	wait1Msec(1500);
}

// backwards
void backward(){
	motor[motorA] = -20;
	motor[motorB] = -20;
	wait1Msec(1500);
}

// right
void rightturn(){
	motor[motorA] = 20;
	motor[motorB] = -20;
	wait1Msec(1200);
}

// left
void leftturn(){
	motor[motorA] = 0;
	motor[motorB] = -20;
	wait1Msec(1200);
}

// backwards and forwards
void goStraight(int ct){
	if(ct % 2 == 0){ // go forward
		motor[motorA] = 20;
		motor[motorB] = 20;
		wait1Msec(1500);
	}else{ // go backwards
		motor[motorA] = -20;
		motor[motorB] = -20;
		wait1Msec(1500);
	}
}

// left and right
void Turn(int ct){
	if(ct % 2 == 0){ // go right
		motor[motorA] = 37;
		motor[motorB] = -20;
		wait1Msec(1200);
	}else{ // go left
		motor[motorA] = -20;
		motor[motorB] = 37;
		wait1Msec(1200);
	}
}

task main()
{
	int ct = 0;
	while(ct < 4){

		// can only go forwards
		ct = ct * 2;
		goStraight(ct);
		ct = ct / 2;

		wait1Msec(1200);

		// has to turn in one direction
		ct = ct * 2;
		Turn(ct);
		ct = ct / 2;

		wait1Msec(1200);
		++ct;
	}
	wait1Msec(3000);

	motor[motorA] = 0;
	motor[motorB] = 0;

}
