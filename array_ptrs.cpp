#include <iostream>
using namespace std;

int main(){
    
    int my_ints [4];
    int *my_ptrs [4];
    
    for(int i = 0; i < 4; i++){
        cin >> my_ints[i];
    }
    
    for (int i = 0; i < 4; i++){
        my_ptrs [i] = &my_ints[i];
    }
    
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < (4-i-1); j++)
        {
            if(*my_ptrs[j] > *my_ptrs[j +1])
            {
                int temp = *my_ptrs[j];
                *my_ptrs[j] = *my_ptrs[j + 1];
                *my_ptrs[j + 1] = temp;
            }
        }
        
    }        
    cout << "Array sorted with pointes are: " << endl;        
    for(int i = 0; i < 4; i++)
    {
        cout << *my_ptrs[i] << endl; 
    }
    
    return 0;
}