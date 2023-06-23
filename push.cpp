#include"./pub.h"
extern void tui(vector<string>cmdP);
string qkong(string a)
{
	string nok;
	bool clear=0;
	for(int j=0;j<a.size();j++)
	{
		if(a[j]!=' ')clear=1;
		if(clear==1)nok.push_back(a[j]);
	}

	int cnt=nok.size()-1;
	for(int j=nok.size()-1;j>=0;j--)
	{
		if(nok[j]!=' ')
		{
			cnt=j;
			break;
		}
	}
	string nok1;
	for(int j=0;j<cnt+1;j++)nok1.push_back(nok[j]);
	return nok1;
}
void pucmd_1(string cmd);
void pucmd(string cmd)
{
	vector<string> list; 
	string buf;
	for(int i=0;i<cmd.size();i++)
	{
		if(cmd[i]==';')
		{
			list.push_back(buf);
			buf.clear();
			continue;
		}
		buf.push_back(cmd[i]);
	}
	list.push_back(buf);
	for(int i=0;i<list.size();i++)pucmd_1(list[i]);
}
void pucmd_1(string cmd)
{
	vector<string>dui;
	string buf;
	for(int i=0;i<cmd.size();i++)
	{
		if(cmd[i]=='-')
		{
			if(cmd[i+1]=='>')
			{	
				if(cmd[i+2]=='>')//->>
				{
					if(buf.size()>0)dui.push_back(buf);
					buf.clear();
					dui.push_back("->>");
					i+=2;
					continue;
				}
				else if(cmd[i+2]!='>')//->
				{
					if(buf.size()>0)dui.push_back(buf);
					buf.clear();
					dui.push_back("->");
					i+=1;
					continue;
				}
			}
		}
		else if(cmd[i]=='>')
		{
			if(cmd[i+1]=='>')//>>
			{
				if(buf.size()>0)dui.push_back(buf);
				buf.clear();
				dui.push_back(">>");
				i++;
				continue;
			}
			else if(cmd[i+1]!='>')//>
			{
				if(buf.size()>0)dui.push_back(buf);
				buf.clear();
				string temp=">";
				dui.push_back(temp);
				continue;
			}
		}
		else if(cmd[i]=='|')
		{
			if(buf.size()>0)dui.push_back(buf);
			buf.clear();
			string temp="|";
			dui.push_back(temp);
			continue;
		}
		buf.push_back(cmd[i]);
	}
	if(buf.size()>0)dui.push_back(buf);
	vector<string>cmdL;
	cmdL.push_back("114514");
	for(int i=0;i<dui.size();i++)cmdL.push_back(dui[i]);
	cmdL.push_back("114514");
	for(int i=0;i<cmdL.size();i++)
	{
		string tem=qkong(cmdL[i]);
		if(tem.size()!=0)cmdL[i]=tem;
		else 
		{
			cout<<"出错: 命令是空格\n";
			return;
		}
	}
	tui(cmdL);
}
