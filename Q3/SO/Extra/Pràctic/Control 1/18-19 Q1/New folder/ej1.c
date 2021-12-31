#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>

void Usage() {
	printf("Usage:ej1 arg1 [arg2..argn]\n");
	printf("Este programa recibe dos enteros,El 
programa comenzará mostrando el valor del primer parámetro, 
a partir del cual a cada segundo lo irá incrementando en 1 
y mostrando por pantalla. En caso de recibir un SIGUSR1, 
mostrará el mensaje: “RESTAN POR ACABAR XXX SEGUNDOS”, 
siendo XXX el número de incrementos que faltan para mostrar 
tantos números como indica el segundo parámetro y continuar l
a ejecución.\n");	
exit(0);
}
int num1;
int num2;

void error_y_exit(char *s, int error) {
	perror(s);
	exit(error);
}

void funcion_alarma(int s)
{
    char buff[256];
    if (s == SIGALRM) {
        num1++;
        printf("%d \n", num1); 
        num2--;
    }
    else if (s == SIGUSR1) {
        sprintf(buff, "RESTAN POR ACABAR %d SEGUNDOS s\n",num2);
        write(1, buff, strlen(buff));
    }
    
}
int main(int argc, char *argv[])
{	
	num1=atoi(argv[1]);
	num2=atoi(argv[2]);
	if(argc>3 ) Usage();
	printf("primer entero %d \n", num1);

	
	
	struct sigaction sa;
    sigset_t mask;

    sigemptyset(&mask);
    sigaddset(&mask, SIGALRM);
    sigaddset(&mask, SIGUSR1);
    sigprocmask(SIG_BLOCK,&mask, NULL);

    /* REPROGRAMAMOS EL SIGNAL SIGALRM */
    sa.sa_handler = &funcion_alarma;
    sa.sa_flags = SA_RESTART; 
    sigfillset(&sa.sa_mask);

    if (sigaction(SIGALRM, &sa, NULL) < 0) error_y_exit("sigaction", 1);
    if (sigaction(SIGUSR1, &sa, NULL) < 0) error_y_exit("sigaction", 1);
    
    while (num2>0)
    {
    	alarm(1); 	/* Programamos la alarma para dentro de 1 segundos */
    		  	/* Nos bloqueamos a esperar que nos llegue un evento */
    	sigfillset(&mask);
        sigdelset(&mask, SIGALRM);
    	sigdelset(&mask, SIGINT);
        sigdelset(&mask, SIGUSR1);
        sigsuspend(&mask);
    }
    exit(1);
}
