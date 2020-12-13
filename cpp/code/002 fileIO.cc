/* 
文件读写——字符串: ?fstream
    ifstrem:read file
    ofstream:write file
    todo:fstream

文件模式:
*/

#include <fstream> //?fstream

#include <iostream>

int main(int argc, char const *argv[])
{
    using namespace std;
    // write string to file
    ofstream fout("file.txt");
    fout << "Those text from cpp" << endl;
    fout << "first line" << endl;
    fout.close();

    // read character from file
    ifstream fin("file.txt");
    if (fin.is_open())
    {
        char ch;
        //按字节读入,直到文件结束符EOL
        while (fin.get(ch))
        {
            cout << ch;
        }
        
        fin.close();
    }

    return 0;
}
