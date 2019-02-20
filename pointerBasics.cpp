#include <iostream>
using namespace std;

int main(){
    int myInt = 15;
    int *myPointer;
    myPointer = &myInt;
    
    cout << myPointer<< endl;
    
    cout << myInt << endl;
    
    cout << &myPointer << endl;
    
    cout << *myPointer << endl;
    
    myInt = 10;
    
    cout << myPointer<< endl;
    
    cout << myInt << endl;
    
    cout << &myPointer << endl;
    
    cout << *myPointer << endl;
    return 0; 
    
}