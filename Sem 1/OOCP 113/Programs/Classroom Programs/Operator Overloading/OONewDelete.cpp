// overloading new and delete operator

#include <iostream>
using namespace std;

class Test
{
private:
    int i;

public:
    Test() : i(0) { cout << "Constructor is called\n"; };
    ~Test() { cout << "Destructor is called\n"; };

    void *operator new(size_t size); // Overload new
    void operator delete(void *p);   // Overload delete
};
void *Test::operator new(size_t size)
{
    void *p = malloc(size); // allocate raw memory of required size
    if (!p)
    {
        cout << "memory allocation failure";
        exit(0);
    }
    return p; // return memory address to caller
}
void Test::operator delete(void *p)
{
    free(p); // free the memory
}
int main()
{
    Test *t1 = new Test; // Step 1: call overloaded new
                         // Step 2: constructor is called
    delete (t1);         // Step 1: destructor is called
                         // Step 2: overloaded delete is called
    return 0;
}
