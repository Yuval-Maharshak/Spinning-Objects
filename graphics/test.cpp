#include <sys/ioctl.h>
#include <iostream>
using namespace std;

int main () 
{
    cout << "Hello ";
    cout.seekp(5);   
    cout << "meow\n";
}