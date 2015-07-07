#ifndef PROCESS_H
#define PROCESS_H

#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Process{
 public:
   //properties
   int AT;
   int TC;
   int CB;
   int IO;

   int priority;
   int rem_time; 

   string status;

   //Constructor & Deconstructor
   Process(int arrival_time, int total_cpu, int cpu_burst, int io_burst, int prio = 1, string _status = "CREATED");
   Process(string& init_str, int prio = 1, string status = "CREATED");
   ~Process();
   //Methods
   
};

#endif
