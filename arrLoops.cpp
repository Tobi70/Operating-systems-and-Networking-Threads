#include <iostream>
using namespace std;

int main()
{
    int numbers[10];
    int x;
    int n,i,j,temp;

    for (int i = 0; i < 10; i++)
    {
        cout << "Enter a number: ";
        cin >> numbers[i];
    }

    for (int i = 9; i>=0; i--)
    {
        cout << numbers[i] << ", ";
    }
    cout << endl;
    for(i = 1; i < 10; ++i)
    {
        for(j = 0; j < (10-i);++j)
            if(numbers[j] > numbers[j+1])
            {
                temp=numbers[j];
                numbers[j]=numbers[j+1];
                numbers[j+1]=temp;
            }
    }
    
    cout << "The array form lowest to highest is: " << endl;
    for(i = 0; i < 10; ++i){
        
        cout<<""<< numbers[i] << ",";
    }
    return 0;
}