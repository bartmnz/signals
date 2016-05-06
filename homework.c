#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <limits.h>
#include <math.h>


struct prime{
	unsigned int next;
	unsigned int max;
	int increment;
};

struct prime number;

void next_prime(){
	

}


void handler(int signum, siginfo_t *siginfo, void* context){
	siginfo +=1;
	if (context == NULL){}
	switch (signum){
	}
}



int main(void){
	
	struct sigaction psa;
	memset (&psa, '\0', sizeof(psa));

	psa.sa_sigaction = &handler;

	psa.sa_flags = SA_SIGINFO;

	if(sigaction(SIGHUP, &psa, NULL) < 0){
		printf("ERROR: 1\n");
	}
	else if( sigaction(SIGUSR1, &psa, NULL) < 0 ){
		printf("shouldn't be here\n");
	}
	else if(sigaction(SIGUSR2, &psa, NULL) < 0 ){
		printf("bad places\n");
	}

	while(1){
		next_prime();
		fprintf(stdout, "next prime is %d\n", number.next);
		sleep(1);
	}

}
