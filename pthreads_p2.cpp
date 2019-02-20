/*
 @file: pthreads_skeleton.cpp
 
 @author: student name1, student2@uncc.edu
 @author: student name2, student2@uncc.edu
 @author: student name3, student3@uncc.edu
 
 @description: A program that demonstrates processes.
 
 @course: ITSC 3146
 @assignment: in-class activity [n]
 */

#include <pthread.h>
#include <iostream>

using namespace std;


// This function shows the skeleton that pthread 
// functions must adhere to. 
// Copy this skeleton for any pthread function 
// you need to define. 
// In the copy, modify the name of the function 
// and the function body as needed. 
int arr[10];
void *countNegatives(void *arg)
{
   // TODO: Add code that implements
   //       the thread's functionality
   int NumberOfNegatives = 0;
   
   for (int i = 0; i < 10; i++) {
      if (arr[i] < 0) {
                NumberOfNegatives++;
            }
        }
        
    
   cout << "Total negative numbers: " << NumberOfNegatives << "\n";
   cout << "Thread is running..." << endl;
   return 0;
}

void *average(void *arg)
{
   // TODO: Add code that implements
   //       the thread's functionality
   int avg = 0; 
   int sum = 0;
   for (int i = 0; i < 10; i++)
   {
     sum += arr[i];
   }
   avg = (sum/10);
   
   cout << "Average: " << avg << "\n";
   cout << "Thread is running..." << endl;
   return 0;
}

void *reverse(void *arg)
{
   // TODO: Add code that implements
   //       the thread's functionality
   int temporary;
  for (int i = 0; i < (10 / 2); i++)
   {
      temporary = arr[i];
      arr[i] = arr[(10 - 1) - i];
      arr[(10 - 1) - i] = temporary;
   }
   cout << "The new array order is " << endl;

   for (int i = 0; i < 10; i++)
   { 
      cout << arr[i] << endl;
   }


   
   cout << "Thread is running..." << endl;
   return 0;
}


int main()
{
   // id is used to store a unique thread identifier,
   // returned by the call to create a new POSIX thread
   pthread_t id;
   
   // rc is used to store the code returned by the
   // call to create a new POSIX thread. The value is
   // zero (0) if the call succeeds.
   int rc;
   int input;
   
   // TODO: Add code to perform any needed initialization
   //       or to process user input
   cout << "Enter 10 integers \n ";
   for(int x = 0; x < 10; x++){
      cin >> input;
      arr[x] = input;
   }
   
   // Create thread(s)
   // TODO: Modify according to assignment requirements
   
   rc = pthread_create(&id, NULL, countNegatives, NULL);
   int rd = pthread_create(&id, NULL, average, NULL);
   int re = pthread_create(&id, NULL, reverse, NULL);
   
   
   
   

   if (rc){
      cout << "ERROR; return code from pthread_create() is " << rc << endl;
      return -1;
   }
   

   // NOTE: Using exit here will immediately end execution of all threads
   pthread_exit(0);
}
