#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>

void Usage() {
	printf("Usage:ej2 arg1 [arg2..argn]\n");
	printf("Has entrado mas parametros de los 						correctos\n");	
	exit(0);
}
void muta(char *a, char *i) {
	execlp("./ej3", a, i (char*)NULL);
	error_y_exit("Ha fallado la mutación al ps", 1);
}

main(int argc, char *argv[]) {
	int i,ret, proc= atoi(argv[1]);
	if (argc>2) Usage();

	for ( int i=0; i< proc; i++){
		ret=fork();
		if(ret==0){
			muta(argv[1],i);
		}
		if(ret<0){
			printf("Se ha prodcido une error\n");
			break;
		}

	}
	while (wait(NULL) > 0);


}
