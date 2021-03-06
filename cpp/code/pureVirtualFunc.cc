/* 命令行参数传递，或者说main函数参数 */

#include <iostream>

int main(int argc, char const *argv[])
{
    using namespace std;

    //argc:命令行中的实参个数,argc>=1
    cout<<"argc:"<<argc<<endl;

    for(int i=0; i<argc; i++){
        //argcv[0]目标文件exe的绝对路径 C:\Documents\GitHub\notes\cpp\code\003 cmd parameters.exe
        //对于i>0，argcv[i]传递给目标文件exe的参数
        cout<<argv[i]<<endl;
    }
    return 0;
}
