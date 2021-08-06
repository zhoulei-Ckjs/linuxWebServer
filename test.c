#include<stdio.h>
#include<mysql/mysql.h>

int main()
{
	MYSQL *con = NULL ;
	printf("未初始化\n") ;
	con = mysql_init(con) ;
	if(con == NULL) 
	{
		printf("初始化失败\n") ;
		exit(1) ;
	}
	con = mysql_real_connect(con , "localhost" , "zhoulei" , "zhoulei83" , "yourdb" , 3306 , NULL , 0);
	if(con == NULL)
		printf("if中\n") ;
	printf("成功\n") ;
	return 0 ;
}
