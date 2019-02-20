//
//  Processes.cpp
//  ITSC 3146
//
//  Created by Bahamon, Julio on 1/12/17.
//
/*
 @file Processes.cpp
 @author student name, student@uncc.edu
 @author student name, student@uncc.edu
 @author student name, student@uncc.edu
 @description: <ADD DESCRIPTION>
 @course: ITSC 3146
 @assignment: in-class activity [n]
 */
#include <stdlib.h> 
#include <sys/types.h>
#include <sys/wait.h>
#ifndef Processes_cpp
#define Processes_cpp
#include "Processes.h"
using namespace std;
// Part 1: Working With Process IDs
pid_t getProcessID(void)
{
   // TODO: Add your code here
   if(process_id == 0){
      return getppid();
   }else{
   return -1;
   }
}
// Part 2: Working With Multiple Processes
string createNewProcess(void)
{
   pid_t id = fork();
   
   // DO NOT CHANGE THIS LINE OF CODE
   process_id = id;
   int status;
   
   if(id == -1)
   {
      return "Error creating process";
   }
   else if (id == 0)
   {
      // TODO: Add your code here
      cout << "I am a child process" << endl;
      return "I'm bored of my parent, switching programs now";
      exit(0);
   }
   else
   {
      // TODO: Add your code here
      cout << "I am a parent process" << endl;
      wait(&status);
      if(WIFEXITED(status)){
         return "My child process just terminated";
      }
      
   }
}
// Part 3: Working With External Commands"
void replaceProcess(char * args[])
{
   // Spawn a process to execute the user's command.
   pid_t id = fork();
   execvp("ls", (char* const*) args);
   
   
   
   // TODO: Add your code here
}
#endif /* TestProg_cpp */
