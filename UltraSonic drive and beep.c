// it beeps whenever ultrasonic sensor detects < 10 cm
task main()
{
  SensorType[S2] = sensorSONAR;
  while (1)
  {
    motor[motorA] = 20;
    motor[motorB] = 20;

    if (SensorValue[S2] < 10)
       playSound(soundBeepBeep);
   }

}
