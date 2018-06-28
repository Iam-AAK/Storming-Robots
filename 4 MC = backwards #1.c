#define  LM  motorA
#define  RM  motorB

task main()
{ int target = -700;

  // go forward for 1800 encoder degrees
  displayTextLine(0, "      Left  Right");
  displayTextLine(1, "      ====  ====");
  displayTextLine(3, "Target:%4d  %4d", target, target);

  nMotorEncoder[LM] = 0;
  nMotorEncoder[RM] = 0;

  while(nMotorEncoder[LM]>target || nMotorEncoder[RM]>target)
  {
    motor[LM] = -70;
    motor[RM] = -70;
  }

  motor[LM] = motor[RM] = 0;
  wait1Msec(2000); // wait for complete stop
  displayTextLine(4, "Actual:%4d  %4d", nMotorEncoder[LM],nMotorEncoder[RM]);

  wait1Msec(4000);
}
