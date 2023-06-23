#include"./pub.h"
#include <locale>
string pub_user_name;
bool idio=0;
extern string fork(type_t stdin_,type_t stdout_,type_t asy,string cmd,string last="");
extern string output;
extern void pucmd(string cmd);
extern void zu(vector<string>duan,type_t type,string input="");
extern void sub(pid_t pid);
extern bool strhas(cstr p, cstr wor);
extern bool strcan(int i, cstr p, cstr wor);
extern string ifss(string path);
extern string qkong(string a);
string logs="114514";
extern vector<string>fduan(string cmd);
string buf;
struct tihuan
{
	string yuan;
	string xian;
};
int main(int num,char* p[])
{
	string xinxi="\033[32m欢迎使用jgsh beta版\n\033[33mshell处于测试阶段,部分功能还不完善\n\033[34mbug反馈,新功能更新,代码开源请去github查看\n\033[35m(代码仅限参考,难以阅读,可随意自用无需授权)\n\033[36m不要忘了一键三连呀!\n\033[0m";
	cout<<xinxi;
	vector<tihuan>ali_dui;
	while(1){
		if(idio==1)return 0;
		filesystem::path pat = filesystem::current_path();
		char host[255];
		gethostname(host,sizeof(host));
		uid_t uid=getuid();
		passwd* user=getpwuid(uid);
		pub_user_name=string(user->pw_name);
		string pats=pat.string();
		string user_dir="/home/"+pub_user_name;
		if(strcan(0,pats.c_str(),user_dir.c_str()))
		{
			string show="~";
			for(int i=user_dir.size();i<pats.size();i++)
				show.push_back(pats[i]);
			pats=show;
		}
		cout<<"\n\033[32m┌──("<<"\033[34;1m"<<user->pw_name<<"\033[34m->\033[34m"<<host<<"\033[32m)-[\033[36m";
		cout<<pats<<"\033[32m]\033[35m[jgsh]\033[32m\n└─\033[34;1m$ \033[0m";
		string cmd;
		getline(cin,cmd);
		cmd=qkong(cmd);
		for(int i=0;i<ali_dui.size();i++)
		{
			for(int j=0;j<cmd.size();j++)
			{
				if(strcan(j,cmd.c_str(),ali_dui[i].yuan.c_str()))
				{
					cmd.erase(j,ali_dui[i].yuan.size());
					cmd.insert(j,ali_dui[i].xian);
					break;
				}
			}
		}
		if(strcan(0,cmd.c_str(),"cd")||strcan(0,cmd.c_str(),"&cd"))
		{
			string ph;
			if(strcan(0,cmd.c_str(),"cd"))for(int i=3;i<cmd.size();i++)ph.push_back(cmd[i]);
			else for(int i=4;i<cmd.size();i++)ph.push_back(cmd[i]);
			if (chdir(ph.c_str()) != 0)cout<<"\033[33m错误,cd找不到了\033[0m";
			continue;
		}
		if(strcan(0,cmd.c_str(),"exit"))
		{
			cout <<"\033[31m已退出\n\033[0m";
			return 0;
		}
		if(strcan(0,cmd.c_str(),""))
		if(strcan(0,cmd.c_str(),"alias"))
		{
			cmd=qkong(cmd);
			string cs1,cs2;
			bool st1=0;
			int pos1=0;
			for(int i=0;i<cmd.size();i++)
			{
				if(cmd[i]=='\"'&&st1==1)
				{
					st1=0;
					pos1=i;
					break;
				}
				if(cmd[i]=='\"'&&st1==0)st1=1;
				if(st1==1)cs1.push_back(cmd[i]);
			}
			st1=0;
			for(int i=pos1+1;i<cmd.size();i++)
            {
                if(cmd[i]=='\"'&&st1==1)
                {
                    st1=0;
                    pos1=i;
                    break;
                }
                if(cmd[i]=='\"'&&st1==0)st1=1;
                if(st1==1)cs2.push_back(cmd[i]);
            }
			cs1.erase(0,1);
			cs2.erase(0,1);
			cs1=qkong(cs1);
			cs2=qkong(cs2);
			tihuan temp;
			temp.yuan=cs1;
			temp.xian=cs2;
			bool flag1=0;
			for(int i=0;i<ali_dui.size();i++)
			{
				if(ali_dui[i].yuan==cs1)
				{
					ali_dui[i].xian=cs2;
					flag1=1;
					break;
				}
			}
			if(flag1==0)ali_dui.push_back(temp);
			continue;
		}
		pucmd(cmd);
	}
}

