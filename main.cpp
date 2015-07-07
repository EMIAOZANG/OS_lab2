#include "sched.h"
#include "event.h"

#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <unistd.h>
#include <getopt.h>
#include <string>
#include <regex>
#include <cstring>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

string parse_args(int& argc, char **argv, int& subarg){
  /*This function parses the command line args according to the following specifications:*/
  /*<Program> [-v] [-s<F|L|S|R<num>|P<num>],
   *where F = FCFS, L = LCFS, S = SJF, and P<num> and R<num> = PRIO and RR with quantum <num>
   */
  int opt_ch;
  while ((opt_ch = getopt(argc, argv, "s:v"))!= -1){
    if (opt_ch == 's'){
      cout << "opt = " << char(opt_ch) << ", optarg = " << optarg << "\n\r";
      if (regex_match(string(optarg), regex("^F$"))){ 
        cout << "Entering FCFS";
        return "F";
      }
      else if (regex_match(string(optarg),regex("^L$"))){
        cout << "Entering LCFS";
        return "L";
      }
      else if (regex_match(string(optarg),regex("^S$"))){
        cout << "Entering SJF";
        return "S";
      }
      else if (regex_match(string(optarg),regex("^P\\d+$"))){
        cout << "Entering PRIO";
        subarg = stoi(string(optarg).substr(1)); //returns the updated <num>
        return "P";
      }
      else if (regex_match(string(optarg),regex("^R\\d+$"))){
        cout << "Entering RR";
        subarg = stoi(string(optarg).substr(1)); //returns the updated <num>
        return "R";
      }
      else return "";
    }
//    switch (opt_ch){
//      //add your operations here
//      case 's': cout << "opt = " << char(opt_ch) << ", optarg = " << optarg << "\n\r"; break;
//      case 'v': cout << "opt = " << char(opt_ch) << "\r\n";
//    }
    //cout << "opt = " << char(opt_ch) << ", optarg = " << optarg << "\n"; 
  }
  return "";
}

int main(int argc, char **argv){
  //declaration of variable and containers
  queue<Event> event_queue;
  int num = 0;//subarg <num> 
  string type_str = parse_args(argc, argv, num);//type indicator of schedulers
  if (type_str == "F"){
    FCFS_Scheduler sch; 
  }
  else if (type_str == "L"){
    LCFS_Scheduler sch;
  }
  else if (type_str == "S"){
    SJF_Scheduler sch;
  }
  else if (type_str == "P"){
  }
  else if (type_str == "R"){
  }
  else{
    //expect correct parameter input
  }
  cout << num << "\n\r";
  return 0;  
}

