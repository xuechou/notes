#include <iostream>


int main(int argc, char const *argv[])
{
    using namespace std;

    int n =9;
     int& r1 = n;
    const int & r2 = r1;

    r1=10;
    cout<<n<<endl;
    cout<<r1<<endl;
    cout<<r2<<endl;


    return 0;
}

