//#include "sched.h"

#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <unistd.h>
#include <getopt.h>

using namespace std;

int parse_args(int& argc, char **argv){
  /*This function parses the command line args according to the following specifications:*/
  /*<Program> [-v] [-s<F|L|S|R<num>|P<num>],
   *where F = FCFS, L = LCFS, S = SJF, and P<num> and R<num> = PRIO and RR with quantum <num>
   */
  int opt_ch;
  while ((opt_ch = getopt(argc, argv, "s:v"))!= -1){
    switch (opt_ch){
      //add your operations here
      case 's': cout << "opt = " << char(opt_ch) << ", optarg = " << optarg << "\n\r"; break;
      case 'v': cout << "opt = " << char(opt_ch) << "\r\n";
    }
    //cout << "opt = " << char(opt_ch) << ", optarg = " << optarg << "\n"; 
  }
  return opt_ch;
}

int main(int argc, char **argv){
  parse_args(argc, argv);
  return 0;  
}

