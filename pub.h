#define BUFFER_SIZE 1145
#define READ_END 0
#define WRITE_END 1
#pragma once
#ifndef _PUB_H_
#define _PUB_H_
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <filesystem>
#include <fcntl.h>
#include <fstream>
#include <future>
#include <iostream>
#include <math.h>
#include <pwd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <vector>
#include <string>
#include <time.h>
#include <sstream>
#include <csignal>

using namespace std;
typedef const char* cstr;
typedef short type_t;
namespace in
{
	const type_t null=1;
	const type_t last=2;
	const type_t cons=3;
}
namespace out
{
	const type_t null=4;
	const type_t get=5;
	const type_t cons=6;
}
#endif

