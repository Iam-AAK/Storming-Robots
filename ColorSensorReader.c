task main()
{

	SensorType[S1] = sensorEV3_Color;
	SensorMode[S1] = modeEV3Color_RGB_Raw;

	// array
	string arr[5];
	int i = 0; // counter


	long r,g,b;
	delay(100);

	// inital mesurement
	long minBlack = 21;
	long maxBlack = 46; // use green and blue to use this (Mostly green)
	long maxWhite = 190;
	long minWhite = 170;
	//
	long Black = (minBlack + maxBlack) / 2;
	long White = (minWhite + maxWhite) / 2;

	while(i < 5){

			getColorRawRGB(S1, r, g, b);
			displayTextLine(1, "Red is   %d" , r);
			displayTextLine(2, "Green is %d" , g);
			displayTextLine(3, "Blue is  %d" , b);

		// if see white
		if(g > White){

			motor[motorA] = 0;
			motor[motorB] = 0;

			arr[i] = "White";


			}else if(g < Black){ // black

			motor[motorA] = 3;
			motor[motorB] = 3;

			arr[i] = "Black";


			}else{ // sees different colors

			motor[motorA] = 8;
			motor[motorB] = 8;

			// ratios
			g = g+1;
		/**	if(r/g > 1){

				arr[i] = "red";

				}else if((r/g) < 1){

				arr[i] = "yellow";

				}else if((g/b) > 1){

				arr[i] = "green";

				}else if((g/b) < 1){

				arr[i] = "blue";

			}**/

			// yellow: difference less than 10 then it has to be yellow.

		}

		wait1Msec(1000);

		i++; // increment
	}

	for(int i = 2; i < 5; i++){

		displayTextLine(i, arr[i-2]);
		wait1Msec(1000);

	}

}
