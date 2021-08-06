#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
	pid_t pid;
	pid=fork();
	if(pid==0)
	execl("/root/TinyWebServer-raw_version/server","/root/TinyWebServer-raw_version/server","80");
	return 0;
}
