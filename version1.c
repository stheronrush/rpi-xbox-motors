#include <stdio.h>

int main() {
	char a[5],u,d,r,l,ldirection,rdirection;
	int max=3,state=0,lpos,rpos;
	int rmotor=0,lmotor=0,variable=2;
	
	printf("Starting..");
	
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
			
			
			printf("L%3.d%cR%3.d%c\n", lpos,ldirection,rpos,rdirection);
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
		}
		
		printf("state=%d\n",state);
		printf("right motor = %d\nleft motor = %d\n\n",rmotor,lmotor);
				
	}
	return 0;
}

