#include"./pub.h"
extern string ifss(string path);
extern string fork(type_t stdin_,type_t stdout_,type_t asy,string cmd,string last="normal");
bool isfile(vector<string>cmd,int i)
{
	if(cmd[i+1]=="->")return 1;
	if(cmd[i-1]==">")return 1;
	if(cmd[i-1]==">>")return 1;
	if(cmd[i-1]=="->>")return 1;
	if(cmd[i+1]=="->>")return 1;
	if(cmd[i-1]=="->>>")return 1;
	if(cmd[i+1]=="->>>")return 1;
	return 0;
}
/*
   程|程
   程>文
   程>>文
   文->程
*/
void tui(vector<string>cmdP)
{
	vector<string>cmd;
	cmd.push_back("114514");
	for(int i=0;i<cmdP.size();i++)cmd.push_back(cmdP[i]);
	cmd.push_back("114514");
	for(int i=2;i<cmd.size()-2;i++)
	{
		bool isas=0;
        for(int j=0;j<cmd[i].size();j++)
            if(cmd[i][j]=='&')isas=1;
		if(cmd[i]=="|"||cmd[i]==">"||cmd[i]==">>"||cmd[i]=="->")continue;
		if(cmd[i-1]==">"||cmd[i-1]==">>")
		{
			if(cmd[i-1]==">")
			{
				ofstream ofs;
				ofs.open(cmd[i],ios::out);
				ofs<<cmd[i-2];
			}
			else if(cmd[i-1]==">>")
			{
				ofstream ofs;
                ofs.open(cmd[i],ios::out|ios::app);
                ofs<<cmd[i-2];
			}
		}
		if(cmd[i+1]=="->")cmd[i]=ifss(cmd[i]);
		if(cmd[i+1]=="|"||cmd[i+1]==">"||cmd[i+1]==">>"||cmd[i-1]=="->"||cmd[i-1]=="|"||(cmd[i-1]=="114514"&&cmd[i+1]=="114514"))//程序
		{
			type_t stdin_;
			type_t stdout_;
			if(isas==1)
			{
				string temp3;
				bool flag1=0;
				for(int j=1;j<cmd[i].size();j++){
					if(cmd[i][j]!=' ')flag1=1;
					if(cmd[i][j]==' '&&flag1==0)continue;
					temp3.push_back(cmd[i][j]);
				}
				if(cmd[i+1]=="114514")stdout_=out::null;
				if(cmd[i-1]=="114514")stdin_=in::null;
				if(cmd[i-1]=="|"||cmd[i-1]=="->")stdin_=in::last;
				if(cmd[i+1]=="|"||cmd[i+1]==">>"||cmd[i+1]==">")stdout_=out::get;
				cmd[i]=fork(stdin_,stdout_,true,temp3,cmd[i-2]);
			}
			else
			{
				if(cmd[i+1]=="114514")stdout_=out::cons;
				if(cmd[i-1]=="114514")stdin_=in::cons;
				if(cmd[i-1]=="|"||cmd[i-1]=="->")stdin_=in::last;
				if(cmd[i+1]=="|"||cmd[i+1]==">>"||cmd[i+1]==">")stdout_=out::get;
				cmd[i]=fork(stdin_,stdout_,false,cmd[i],cmd[i-2]);
			}
		}
	}
}

