task main()
{

	// Chapter 1
		// mini challenge 1
		displayTextLine(2, "Arya Kulkarni");
		playSound(soundBeepBeep);
		wait1Msec(60);
		displayTextLine(4, "Rutgers");
		playSound(soundBeepBeep);
		wait1Msec(60);

		// mini challenge 2
  	for(int ct = 0; ct < 9; ++ct){
			displayTextLine(ct, "%d", ct);
		}

		eraseDisplay();

		// mini challenge 3
		drawRect(10, 20, 30, 5);
		// draw circle inside rectangle
		// center of screen = 50, 32
		drawRect(45,35,55,30);

		eraseDisplay();

		// mini challenge 5
		int linenum = 0;
		for(int radius = 7; radius <= 28; radius+=7){
			++linenum;
			int circ = 2*3.14*radius;
			int area = 3.14*(pow(radius, 2));

			displayTextLine(linenum, "%d", radius);
			displayTextLine(linenum, " %d", circ);
			displayTextLine(linenum, " %d", area);

		}

		// mini challenge
		drawEllipse(10,20,30,5);

	// Chapter 2
		// basics in array
		char grades[5];
		grades[0] = 'A';
		grades[1] = 'C';
		grades[2] = 'D';
		grades[3] = 'E';
		grades[4] = 'F';

		eraseDisplay();
		*/

		// Tenary Operation
		int a = 2;
		int b = 4;
		int x = 1;
		int y = 0;
		int result = (a > b ? x:y);
		/**
		This is similar to...

		if(a > b){
			result = x;
		}else{
			result = y;
		}
		**/

		displayTextLine(0,"%d", result);



}
