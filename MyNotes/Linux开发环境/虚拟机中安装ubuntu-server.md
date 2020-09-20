# 虚拟机总安装ubuntu-server 20.04 并使用xshell远程连接进行开发

- 安装操作系统需要修改软件安装、更新源为国内服务器：http://mirrors.aliyun.com/ubuntu
- 修改配置， 支持Xshel远程连接
	vim /etc/ssh/sshd_config
	PasswordAuthentication 改为 yes
	/etc/init.d/ssh restart
	此时，可以使用xshell登录普通用户，若要使用root用户登录，继续做如下修改
	/etc/ssh/sshd_config中 PermitRootLogin以设置为yes
	/etc/init.d/ssh restart
	如果还是无法使用root远程登录， 可以reboot机器试试
