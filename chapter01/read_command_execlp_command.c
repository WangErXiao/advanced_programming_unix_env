#include <apue.h>
#include <sys/wait.h>

int main(void){
	char buf[MAXLINE];
	int status;
	pid_t pid;
	
	printf("%% ");
	while(fgets(buf,MAXLINE,stdin)!=NULL){
		if(buf[strlen(buf)-1]=='\n')
			buf[strlen(buf)-1]=0;
		pid=fork();
		if(pid<0)
			err_sys("fork erro!!");
		else if(pid==0){
			execlp(buf,buf, (char*)0);
			err_ret("couldn't execute:%s",buf);
			exit(127);
		} 
		if( (pid=waitpid(pid,&status,0)) <0)	
			err_sys("waitpid error!!");
		printf("%% ");
	}
	exit(0);
}
