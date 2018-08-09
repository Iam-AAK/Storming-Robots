int getCode(long r,long g,long b){
	int binarycode=0;
	if(r>230){
		binarycode=1*100000;
		}else{
		binarycode=0*100000;
	}
	if(r>31){
		binarycode=1*10000+binarycode;
		}else{
		binarycode=0*10000+binarycode;
	}
	if(g<=210&& g>=170){
		binarycode=1*1000+binarycode;
		}else{
		binarycode=0*1000+binarycode;
	}
	if(r/g>3){
		binarycode=1*100+binarycode;
		}else{
		binarycode=0*100+binarycode;
	}
	if(g>=152&&g<=154){
		binarycode=1*10+binarycode;
		}else{
		binarycode=0*10+binarycode;
	}
	if(r>31&&r<78){
		binarycode=1*1+binarycode;
		}else{
		binarycode=0*1+binarycode;
	}
	displayBigTextLine(8,"%d",binarycode)
	return binarycode;

}
task main()
getCode(long r,long g,long b)

}
