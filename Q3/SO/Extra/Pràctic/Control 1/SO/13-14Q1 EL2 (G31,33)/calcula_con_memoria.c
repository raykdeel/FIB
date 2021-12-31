#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#define SYSCALL_ERROR 1

// Esta funcion no es relevante, solo pierde tiempo 
int calcula(unsigned int i)
{
	int it;
	int ret=0;
	srand(i);
	for (it=0;it<i;it++){
		ret=ret+rand();
	}
	return ret;
}			

void usage()
{
	char b[128];
	sprintf(b,"usage:calcula_con_memoria semilla\n");
	write(1,b,strlen(b));
	exit(0);
}

void main(int argc,char *argv[])
{
	int i,ITERACIONES_MAIN=1,ITERACION_ACTUAL,semilla;
	char b[128];
	int res;
	if (argc==1) usage();
	semilla=atoi(argv[1]);
	for (i=0;i<ITERACIONES_MAIN;i++){
		ITERACION_ACTUAL=i;
		res=calcula((unsigned)semilla);
	}	
	sprintf(b,"resultado %d\n",res);
	write(1,b,strlen(b));
}
