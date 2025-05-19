// C++ program to demonstrate object slicing
#include <iostream>
using namespace std;

class Base
{
protected:
    int i;

public:
    explicit Base(int a) { i = a; }
    virtual ~Base() = default;
    virtual void display()
    {
        cout << "Base class:\n"
             << "\ti = " << i << endl;
    }
};

class Derived : public Base
{
    int j;

public:
    Derived(int a, int b) : Base(a), j(b) {}

    virtual void display()
    {
        cout << "Derived class:\n"
             << "\ti = " << i
             << "\tj = " << j << endl;
    }
};

void slicer(Base obj)
{
    obj.display();
}

int main()
{
    Base base(33); // NOLINT
    std::cout << "base-";
    base.display();
    Derived derived(45, 54); // NOLINT
    std::cout << "derived-";
    derived.display();
    std::cout << "Slicing base\n";
    slicer(base);
    std::cout << "Slicing derived\n";
    slicer(derived);
    return 0;
}