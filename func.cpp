#include"./pub.h"
bool strcan(int i, cstr p, cstr wor)
{
	int ch = 0;
	if (i > strlen(p))return 0;
	for (int j = i; j < strlen(wor) + i; j++)
		if (p[j] != wor[j - i])ch++;
	if (ch == 0)return 1;
	else return 0;
}
bool strhas(cstr p, cstr wor)
{
	for (int i = 0; i < strlen(p); i++)
		if (strcan(i, p, wor))return 1;
	return 0;
}
string ifss(string path)
{
	string tem;
    std::ifstream ifs(path);
    char temp;
    while (ifs.get(temp))
        tem.push_back(temp);
	return tem;
}

