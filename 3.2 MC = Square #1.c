task main()
{
  int ct = 0;
	while (ct < 4)  {
		// go 20 cm straight  =========================
		motor[motorA] = 20;
		motor[motorB] = 20;
		wait1Msec(1500);

		// R90 degrees turn  =========================
		motor[motorA] = 30;
		motor[motorB] = -63;
		wait1Msec(1200);

		++ct;
	}


}
