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



int main(int argc, char* argv[]){
	memset(&number, '\0', sizeof(number));
	number.next = 1;
	number.increment = 2;
	number.max = UINT_MAX;
	int var = 0;
	int opt, sflag, rflag, errflag;
	while ((opt = getopt(argc, argv, "s:e:r:")) != -1){
		switch (opt){
		case 's':
			sflag = 1;
			if (rflag == 1){
				errflag = 1;
			}
			var = atoi(optarg);
			number.next = var & 1 ? var : var + 1;
			break;
		case 'e':
			var = atoi(optarg);
			if ( var > 2){
				number.max = (unsigned int) var <= number.max ? (unsigned int) var : number.max;
			}
			break;
		case 'r':
			rflag = 1;
			if (sflag == 1){
				errflag = 1;
			}
			var = atoi(optarg);
			number.next = var & 1 ? var : var + 1;
			number.increment = -2;
			break;
		default:
			fprintf(stderr, "ERROR: bad usage/n");
			exit(0);
		}
	}
	if ( errflag == 1){
		fprintf(stdout, "ERROR: usage: -s and -r are mutually exclusive.");
		exit(0);
	}

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
