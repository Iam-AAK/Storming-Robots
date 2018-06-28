task main()
{
  motor[motorA] = 20;
  motor[motorB] = 20;
  wait1Msec(4000);
  motor[motorA] = -20;
  motor[motorB] = -20;
  wait1Msec(4000);
}
