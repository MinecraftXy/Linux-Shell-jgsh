<div align="center"><img src="https://img.shields.io/github/stars/MinecraftXy/Linux-Shell-jgsh">&nbsp; <img src="https://img.shields.io/github/forks/MinecraftXy/Linux-Shell-jgsh?color=%23f8e71c">&nbsp;<img src="https://img.shields.io/github/issues/MinecraftXy/Linux-Shell-jgsh?color=%237ed321"></div>

# jgsh
## Linux shell 持续更新
# 项目概述
#### jgsh,一个简单的LinuxShell,实现简单的交互功能
# 安装和部署
#### 下载项目文件夹,找到g++.sh 使用sh g++.sh编译
#### 编译完毕的产物是jgsh 使用./jgsh运行
# 使用示例
### 与bash大致一致,有以下不同点:
#### 1.只支持命令的形式,不支持shell脚本的形式
#### 2.操作符号不同 其中,|(管道符),>(重定向)>>(追加)不变
#### ->(导入)是新增的,用法是文件->程序,指把文件内容作为程序的stdin
#### &(异步)是新增的,在命令前面加上他,让命令后台运行
#### 你依然可以使用;(分割符)来执行不同的命令
#### 另外,这个shell只支持这些操作符
### 操作示例
ls |  grep c >>a.txt  ->grep  1  ;      &ls
# 其他信息
对于ls没有颜色的问题,并非bug 请加上--color=auto或alias "ls""ls --color=auto"
### jgsh是beta版,目前代码简陋且不完善,会有正式版的
### 代码开源可随意使用,无需授权,代码仅供参考,因为难以阅读
(作者太菜,还只是小学生水平)
### 代码可以供提供一些函数的用法,不必看每一步怎么运行的
### 作者 mcfgjg
# 运行逻辑
## 代码中的运行逻辑不明显且显得混乱,这里针对文件给出运行逻辑
### pub.h:
提供了用到的头和常量
主函数循环,循环执行命令,执行自带命令,alias,
并将一横个命令行传给下一级push.cpp的pucmd()
### push.cpp
对命令进行第一次处理,把命令,符号全部拆成部分,装入vector
检查命令全空格的情况,并传给下一级tui.cpp的tui()
### tui.cpp
最后一次处理,循环执行vector里的每一个命令<br>
并把命令的输出存起来供下一个命令使用<br>
具体结合当前传入的命令性质<br>
为了给当前要执行的命令做正确的操作,会先根据性质进行对in/out方向的定制,分别是:<br>
传入输入<br>
从/dev/null传入输入<br>
从控制台传入输入<br>
获取输出<br>
输出去/dev/null<br>
输出去控制台<br>
具体结合当前命令的位置和前后符号
命令最后由fork.cpp的fork()执行
### fork.cpp
shell的核心,执行命令<br>
可创建子进程,进行输入输出重定向,异步执行,获取输入输出的操作
