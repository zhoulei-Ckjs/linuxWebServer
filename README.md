Linux下C++轻量级Web服务器，助力初学者快速实践网络编程，搭建属于自己的服务器.

* 使用**线程池 + epoll(ET和LT均实现) + 模拟Proactor模式**的并发模型
* 使用**状态机**解析HTTP请求报文，支持解析**GET和POST**请求
* 通过访问服务器数据库实现web端用户**注册、登录**功能，可以请求服务器**图片和视频文件**
* 实现**同步/异步日志系统**，记录服务器运行状态
* 经Webbench压力测试可以实现**上万的并发连接**数据交换

基础测试
------------
* 服务器测试环境
	* Ubuntu版本16.04
	* MySQL版本5.7.29
* 浏览器测试环境
	* Windows、Linux均可
	* Chrome
	* FireFox
	* 其他浏览器暂无测试

* 测试前确认已安装MySQL数据库

    	sudo apt-get update
	sudo apt-get install mysql-server
	sudo mysql
	create database yourdb;
	CREATE TABLE user(
        	username char(50) NULL,
        	passwd char(50) NULL
	)ENGINE=InnoDB;
	INSERT INTO user(username, passwd) VALUES('name', 'passwd');
	create user 'wen'@'localhost' identified by '123456';
	GRANT Insert ON `yourdbname`.* TO `zhoulei`@`localhost`;``

* 修改main.c中的数据库初始化信息

    connPool->init("localhost", "账号名", "密码", "数据库名", 3306, 8);

* 修改http_conn.cpp中的root路径

	// 修改为root文件夹所在路径
    const char* doc_root="/home/qgy/TinyWebServer/root";
* 测试
	test.c是测试数据库是否连接成功的程序
	运行测试需要修改test.c中相应部分：
		mysql_real_connect(con , "localhost" , "用户名" , "密码" , "数据库名" , 3306 , NULL , 0);
	需要编译：
		gcc test.c -o test
	运行test:
		./test
* 运行
	make
	sudo ./server 80
* 浏览器端
	Ip:端口号
