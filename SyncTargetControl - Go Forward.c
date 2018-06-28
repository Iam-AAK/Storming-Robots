
// motors chassis config
#define  LM         motorA
#define  RM         motorB

#if defined(NXT)
#define  SYNC_RM    synchBA  // B as the master motor, A as the secondary motor
#define  SYNC_LM    synchAB  // B as the master motor, A as the secondary motor
#endif

const float TireDia= 5.6;
const float GearRatio=5.0/3.0;     // motor gear = 24, tire gear= 40

float EncPerCM = 360.0*GearRatio/(PI*TireDia);


task main()
{
	float target;
	int pwr = 75;

	float cm = 20.0;  // 20 cm.
	long syncPerCent = 100.0; // slave motor's speed should run at 100% of master motor's.
	// i.e. at the same speed

	target = cm * EncPerCM; // convert cm to encoder value with gear ratio 1:1
	motor[RM] =	motor[LM] = 75;

	displayTextLine(0, "      Left  Right");
	displayTextLine(1, "      ====  ====");
	displayTextLine(3, "Cal.:%4d  %4d", (int)target, (int)target);

	nMotorEncoder[LM] = nMotorEncoder[RM]=0; //must reset

#if defined(NXT)
	nSyncedMotors= SYNC_RM;               //active motor feedback control, and
	//    determine which is the master motor
	nSyncedTurnRatio=syncPerCent;                 //secondary motor's power level is 100% of the master motor's
	nMotorEncoderTarget[RM]=target;       //set the target encoder. Note that motor
	//    is not running yet
	motor[RM] = pwr;
	while (nMotorRunState[RM] != runStateIdle)
	{
		wait1Msec(10);                      //small delay to avoid over-hauling the cpu
	}

	wait1Msec(100);                      // give the motor feedback control stop the motor
	nSyncedMotors= synchNone;             //deactive motor feedback control

#else  // EV3

	setMotorSyncEncoder( RM, LM, syncPerCent, target, pwr);

	while ( getMotorRunning(RM))
		delay(10);


#endif
	displayTextLine(6, "Actual:%4d  %4d", nMotorEncoder[LM], nMotorEncoder[RM]);
	wait1Msec(4000);
}
