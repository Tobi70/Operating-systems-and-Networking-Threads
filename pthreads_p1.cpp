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
const char* my_messages[4] = {"English: Hello!", "French: Bonjour!", "Spanish: Hola!", "German: Guten tag!"};

//struct my_args
//{
  // int index;
   //char* message;
//};

void *printMessage(void *arg)
{
   // TODO: Add code that implements
   //       the thread's functionality
   int actual_arg = *((int*) arg);
   std::cout << "Your index is " << actual_arg << " and the message is " << my_messages[actual_arg] << "!\n"; 
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
   //my_args args;
   
   // TODO: Add code to perform any needed initialization
   //       or to process user input
   int index1 = 0;
   int index2 = 1;
   int index3 = 2;
   int index4 = 3;
   
   
   // Create thread(s)
   // TODO: Modify according to assignment requirements
   
   rc = pthread_create(&id, NULL, printMessage,(void*) &index1);
   int rd = pthread_create(&id, NULL, printMessage,(void*) &index2);
   int re = pthread_create(&id, NULL, printMessage,(void*) &index3);
   int rf = pthread_create(&id, NULL, printMessage,(void*) &index4);
   if (rc){
      cout << "ERROR; return code from pthread_create() is " << rc << endl;
      return -1;
   }
   if (rd){
      cout << "ERROR; return code from pthread_create() is " << rd << endl;
      return -1;
   }
   if (re){
      cout << "ERROR; return code from pthread_create() is " << re << endl;
      return -1;
   }
   if (rf){
      cout << "ERROR; return code from pthread_create() is " << rf << endl;
      return -1;
   }
   

   // NOTE: Using exit here will immediately end execution of all threads
   pthread_exit(0);
}
