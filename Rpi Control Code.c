#include <stdio.h>
#include <wiringPi.h>
#include <wiringSerial.h>

int main() {
	char a[5],u,d,r,l,ldirection,rdirection;
	char string[12];
	int max=3,state=0,lpos,rpos;
	int rmotor=0,lmotor=0,variable=80;
	int port;

	printf("Starting..");
	
	port= serialOpen ("/dev/ttyAMA0",9600);

	while (1) {
		printf("Waiting for input:");
		scanf("%s", a);
		printf("Key Pressed: %s\n", a);


		if (strcmp(a,"u",1)==0) {
		
			if (state==max) {
				printf("at max speed\n");
			} else state++;
			
			rmotor=lmotor=state*variable;
			

			if (state>=0){
				ldirection=rdirection='F';
			}else ldirection=rdirection='B';
			
			lpos=lmotor;
			rpos=rmotor;
			
			sprintf(string, "L%03.3hd%cR%03.3hd%c", lpos, ldirection, rpos, rdirection);
			printf("L%03.3hd%cR%03.3hd%c\n", lpos,ldirection,rpos,rdirection);
			serialPuts(port, string);
		}
			
		

		if (strcmp(a,"d",1)==0) {
		
			if (state==-1){
				printf("already going backwards\n");
			}else state--;
			
			rmotor=lmotor=state*variable;
			
			if (state>=0){
				ldirection=rdirection='F';
				lpos= lmotor;
				rpos= rmotor;
			}else {
				ldirection=rdirection='B';
				lpos= -lmotor;
				rpos= -rmotor;
			}
			
			printf("L%3.d%cR%3.d%c\n", lpos,ldirection,rpos,rdirection);
			sprintf(string, "L%3.d%cR%3.d%c", lpos, ldirection, rpos, rdirection);
			serialPuts(port, string);
		}
		
		
		

		if (strcmp(a,"r",1)==0) {
		
				rmotor=0.5*variable*state;
				lmotor=1.5*variable*state;
				
				printf("right motor = %d\nleft motor = %d\n\n",rmotor,lmotor);
				

				if (state>=0){
					ldirection=rdirection='F';
					lpos= lmotor;
					rpos= rmotor;
				}else {
					ldirection=rdirection='B';
					lpos= -lmotor;
					rpos= -rmotor;
				}
			
				printf("L%3.d%cR%3.d%c\n", lpos,ldirection,rpos,rdirection);
				sprintf(string, "L%3.d%cR%3.d%c", lpos, ldirection, rpos, rdirection);
				serialPuts(port, string);
				
			rmotor=lmotor=state*variable;
			

			if (state>=0){
				ldirection=rdirection='F';
				lpos= lmotor;
				rpos= rmotor;
			}else {
				ldirection=rdirection='B';
				lpos= -lmotor;
				rpos= -rmotor;
			}
			
			printf("L%3.d%cR%3.d%c\n", lpos,ldirection,rpos,rdirection);
			sprintf(string, "L%3.d%cR%3.d%c", lpos, ldirection, rpos, rdirection);
			serialPuts(port, string);
		}


		if (strcmp(a,"l",1)==0) {
		
				lmotor= 0.5*variable*state;
				rmotor=1.5*variable*state;
				
				printf("right motor = %d\nleft motor = %d\n\n",rmotor,lmotor);
				

				if (state>=0){
					ldirection=rdirection='F';
					lpos= lmotor;
					rpos= rmotor;
				}else {
					ldirection=rdirection='B';
					lpos= -lmotor;
					rpos= -rmotor;
				}
			
				printf("L%3.d%cR%3.d%c\n", lpos,ldirection,rpos,rdirection);
				sprintf(string, "L%3.d%cR%3.d%c", lpos, ldirection, rpos, rdirection);
				serialPuts(port, string);
				
			rmotor=lmotor=state*variable;
			
			if (state>=0){
				ldirection=rdirection='F';
				lpos= lmotor;
				rpos= rmotor;
			}else {
				ldirection=rdirection='B';
				lpos= -lmotor;
				rpos= -rmotor;
			}
			
			printf("L%3.d%cR%3.d%c\n", lpos,ldirection,rpos,rdirection);
			sprintf(string, "L%3.d%cR%3.d%c", lpos, ldirection, rpos, rdirection);
			serialPuts(port, string);
		}
		
		printf("state=%d\n",state);
		printf("right motor = %d\nleft motor = %d\n\n",rmotor,lmotor);
				
	}
	
	serialClose (port);
	return 0;
}

