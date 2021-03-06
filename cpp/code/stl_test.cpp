#include <iostream>
#include <array>
#include <ctime>
#include <cstdlib>

using namespace std;

namespace jj01
{
    const long ASIZE = 1000000;

    void test_array()
    {
        array<long ,ASIZE> c;

        clock_t startTime = clock();

        for(long i=0; i<ASIZE; ++i)
        {
            c[i] = rand();
        }
        cout<<"test"<<endl;

        cout<<"time used milli-seconds :"<<clock()-startTime<<endl;
        cout<<"array size"<<c.size()<<endl;
        cout<<"array front"<<c.front()<<endl;
        // cout<<"array data"<<c.data()<<endl;
    
    }
}

int main(int argc, char const *argv[])
{
    jj01::test_array();
    return 0;
}
