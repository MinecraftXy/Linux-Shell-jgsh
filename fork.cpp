#include"./pub.h"
extern string qkong(string a);
const int du=0,xie=1;
void sub(pid_t pid)
{
    int temp;
    if(waitpid(pid,&temp,0)<1)cout<<"\033[33m故障,非常严重:异步等待子进程结束时崩溃\033[0m";
}
vector<string>fduan(string cmd)
{
	vector<string>temp;
	string buf;
	bool T;
	for(int i=0;i<cmd.size();i++)
	{
		if(cmd[i]==' ')
		{
			if(T==0){
				temp.push_back(buf);
				buf.clear();
				T=1;
			}
		}
		else
		{
			buf.push_back(cmd[i]);
			T=0;
		}
	}
	temp.push_back(buf);
	return temp;
}
string fork(type_t stdin_,type_t stdout_,type_t asy,string cmd,string last="__114514__")
{
	int saved_stdout = dup(STDOUT_FILENO);  // 保存原始的 stdout 文件描述符
	string result="";
    int out_null=open("/dev/null",O_WRONLY);
    int in_null=open("/dev/null",O_RDONLY);
    int dad_son[2];
    int son_dad[2];
    if (pipe(dad_son) == -1)exit(114);
    if (pipe(son_dad) == -1)exit(114);
    pid_t pid=fork();
    if(pid>0)//父进程
    {
        if(stdin_==in::last)
        {
            close(dad_son[du]);
			const char *buffer = last.c_str();
            size_t len = strlen(buffer);
            ssize_t written = write(dad_son[1], buffer, len);
            close(dad_son[xie]);
        }
        if(stdout_==out::get)
        {
            char buf[1024]{};
            close(son_dad[xie]);//父不可写
            while (read(son_dad[0], buf, 1024) > 0) { // 从管道读取子进程输出的数据
				result+=buf;//
                memset(buf, 0, sizeof(buf));
            }
            close(son_dad[du]);
        }
        int itemp=0;//
        if(asy==0)if(waitpid(pid,&itemp,0)<1)cout<<"\033[33m故障,非常严重:等待子进程结束时崩溃\033[0m";//
        else if(asy==1&&stdout_!=out::get)future<void>fu=async(sub,pid);//
        if(result.size()!=0)return result;//
    }
    else if(pid==0)//子进程
    {
        if(stdin_==in::null)
        {
            dup2(in_null,STDIN_FILENO);
            close(in_null);
        }
        else if(stdin_==in::last)//读父写
        {
            close(dad_son[xie]);
            dup2(dad_son[du],STDIN_FILENO);
            close(dad_son[du]);
        }
        if(stdout_==out::null)
        {
            dup2(out_null,STDOUT_FILENO);
            close(out_null);
        }
        else if(stdout_==out::get)
        {
            close(son_dad[du]);//子不可读
            dup2(son_dad[xie],STDOUT_FILENO);//stdout成为写端
            close(son_dad[1]);//原装写端关闭
        }
		vector<string>duan=fduan(cmd);//
		char* args[255];//
        for(int i=0;i<duan.size();i++)args[i]=const_cast<char*>(duan[i].c_str());//
        args[duan.size()]=NULL;//
        execvp(args[0],args);//
		dup2(saved_stdout, STDOUT_FILENO);
		cout<<"\033[33m故障,创建子进程时失败,请确保您提供的可执行程序存在\033[0m";//
		close(saved_stdout);
        exit(1);//
    }

    return "非正常显示,故障,非常严重!请联系开发者\n";
}

