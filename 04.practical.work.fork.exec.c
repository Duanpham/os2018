#include <unistd.h>
#include <stdio.h>
int main() {
printf("Main before fork()\n");
int pid = fork();
if(pid<0){
	printf(" errr");}

else if (pid == 0) {
	printf("I am child after fork(), launching ps -ef \n");
	char*ps[]={"bin/ps", "-ef", NULL};
	execvp("/bin/ps",args);
	printf(" finished launching ps -ef");
}

int pid2=fork();
if(pid2<0){
	printf(" errr");}

else if (pid2 == 0) {
	printf("I am child after fork(), launching free -h \n");
	char*fr[]={"free", "-h", NULL};
	execvp("/bin/ps",args);
	printf(" finished launching free -h\n");
}


return 0;
}
