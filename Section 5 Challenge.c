#define  LM  motorA
#define  RM  motorB
#define  TireDia     5.6
#define  WheelBase   12.5

const float EncPerCm = 360 / (PI*TireDia);
const float EncPerDeg = WheelBase / TireDia;

void goBackwardsWmath(){
	float  target;

	target = (-1) * 120 * EncPerCm; // convert cm to encoder value

	displayTextLine(0, "      Left  Right");
	displayTextLine(1, "      ====  ====");
	displayTextLine(3, "Target:%4d %4d", target, target);

	nMotorEncoder[LM] = nMotorEncoder[RM]=0;

	motor[LM]=-75;
	motor[RM]=-75;
	while(nMotorEncoder[LM]>target)
	{
		displayTextLine(5, "Actual:%4d %4d", nMotorEncoder[LM],nMotorEncoder[RM]);
		delay(100);
	}
	motor[LM] = motor[RM] = 0;
	delay(4000);
}

void goRightWmath(){
	float target;
	int degrees = 90;

	target = 90 * EncPerDeg; // convert 90 degrees of rotation to encoder value with gear ratio 1:1

	displayTextLine(3, "Spin Right: %.2f", degrees);

	displayTextLine(0, "      Left  Right");
	displayTextLine(1, "      ====  ====");
	displayTextLine(3, "Target:%4d  %4d", target, -target);

	nMotorEncoder[RM] = nMotorEncoder[LM]=0;
	motor[RM] = 75;
  motor[LM] = 0;

	while(nMotorEncoder[RM]< target || nMotorEncoder[LM]> -target)
	{
		displayTextLine(5, "Actual:%4d %4d", nMotorEncoder[LM],nMotorEncoder[RM]);
		delay(10);
	}
	motor[RM]= motor[LM]=0;

	delay(5000);
}


task main()
{
	goBackwardsWmath();
	goRightWmath();
}
