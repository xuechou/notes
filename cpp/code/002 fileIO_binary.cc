/* 
文件读写——二进制: ?fstream
    ifstrem:read file
    ofstream:write file
    todo:fstream

文件模式:
*/

#include <fstream> //?fstream

#include <iostream>
#include <cstdlib> //for exit()
#include <iomanip> //for what?
#include <string>
inline void eatline()
{
    while(std::cin.get() != '\n')
    {
        continue;
    }
}

struct planet
{
    std::string name;
    double polulation;
    double g; 
};

const char * file = "planets.dat";

int main(int argc, char const *argv[])
{
    using namespace std;

    planet p1;
    
    // write string to file
    ofstream fout(file, ios::out|ios::binary|ios::app);
    if(fout.is_open())
    {
        p1.name = "this ia a palnet naem\n";
        p1.polulation = 3.14;
        p1.g = 0.01;
        fout.write((char*)&p1, sizeof p1);

        fout.close();
    }

    ifstream fin;
    fin.open(file, ios::in|ios::binary); //open binary file

    if(fin.is_open())
    {
        while(fin.read((char *) &p1, sizeof p1))
        {
            cout<<p1.name
                <<"\npopulation:"<<p1.polulation
                <<"\ngravity:"<<p1.g<<endl;
        }
        fin.close();
    }


    return 0;
}
