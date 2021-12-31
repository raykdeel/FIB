#include <unistd.h>
#include <stdio.h>
#include <stdio.h>
void Usage() {
	printf("Usage:ej2 arg1 [arg2..argn]\n");
	printf("Has entrado mas parametros de los correctos\n");	
exit(0);
}
main(int argc , char *argv[]) {
int i,ret, num=atoi(argv[1]);
if (num==0) exit(0);
if (argc>2) Usage();
i=0;
ret =fork();
if (ret == 0) {
	fprintf(stdout, "Soy %d y mi posicion es %d\n", getpid(), i+1);
}
i++;

while ((i<num) && (ret == 0)) {
	ret=fork();
	if (ret == 0) {
		fprintf(stdout, "Soy %d y mi posicion es %d\n", getpid(), i+1);
	}
	i++;
}
while(waitpid(-1,NULL,0)>0);
}
