/*
RTTI: runtime type identification
------------------------------------
1. dynamic_cast
2. typeid
3. type_info

*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <typeinfo>
using std::cout;

class Grand
{
private:
    int hold;

public:
    Grand(int h = 0) : hold(h) {}
    virtual void Speak() const { cout << "I am a grand class:\n"; }
    virtual int Value() const { return hold; }
};

class Superb : public Grand
{
public:
    Superb(int h = 0) : Grand(h) {}
    void Speak() const { cout << "I am a superb class:\n"; }
    virtual void Say() const
    {
        cout << "I hold th superb vaule of " << Value() << "!\n";
    }
};

class Magnificent : public Superb
{
private:
    char ch;

public:
    Magnificent(int h = 0, char c = 'A') : Superb(h), ch(c) {}
    void Speak() const { cout << "I am a Magnificent class:\n"; }
    void Say() const
    {
        cout << "I hold the character " << ch << "and the interger " << Value() << "!\n";
    }
};

Grand *GetOne()
{
    Grand *p;

    switch (std::rand() % 3)
    {
    case 0:
        p = new Grand(std::rand() % 100);
        break;
    case 1:
        p = new Superb(std::rand() % 100);
        break;
    case 2:
        p = new Magnificent(std::rand() % 100, 'A' + std::rand() % 26);
        break;
    }
    return p;
}

int main(int argc, char const *argv[])
{
    std::srand(std::time(0));

    Grand *pg;
    Superb *ps;

    for (int i = 0; i < 5; i++)
    {
        pg = GetOne();
        pg->Speak();

        // using dynamic_cast
        if (ps = dynamic_cast<Superb *>(pg))
        {
            ps->Say();
        }

        cout<<"type name is : " <<  typeid(*pg).name() << ".\n";
        cout<<"int name is : " <<  typeid(1U).name() << ".\n";
        cout<<"int name is : " <<  typeid(1.0).name() << ".\n";
    }
    return 0;
}
