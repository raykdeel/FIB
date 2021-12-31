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
void calcula(int i)
{
	int it;
	int fd;
	for (it=0;it<i;it++){
		fd=open("F",O_WRONLY|O_CREAT|O_TRUNC,S_IRWXU);
		if (fd<0){
			perror("Error en el open");
			exit(SYSCALL_ERROR);
		}
		write(fd,&it,sizeof(it));
		close(fd);
	}
}			

void main(int argc,char *argv[])
{
	int i,ITERACIONES_MAIN=10,ITERACION_ACTUAL,ITERACIONES_CALCULA=100; 
	char b[128];
	for (i=0;i<ITERACIONES_MAIN;i++){
		ITERACION_ACTUAL=i;
		calcula(ITERACIONES_CALCULA);
	}	
}
