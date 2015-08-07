#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <iostream>
#include <cstdio>
#include <queue>
#include <stack>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <deque>
#include <cstdlib>

#include "event.h"
#include "process.h"
#include "sched.h"
#include "utility.h"

using namespace std;

class Simulator{
  //definition of the scheduling simulator
 public:
  priority_queue<Event, vector<Event>, GreaterEvent > event_queue;
  vector<Process> process_list;
  vector<int> randvals;
  deque<Process> ready_queue;

  int ofs;

  int myRandom(int burst);
  bool init_process_n_event(string input_filename); 
  bool init_randval_list(string& rand_filename);
  
  bool get_event();
  void put_event(int _timestamp, int _process_id, int _exec_time, string _old_state, string _new_state, int _event_count);

  //void decode_event(int _timestamp, int _proces s_id, int _old_state, int _new_state);

  //constructor & deconstructor
  Simulator();

  //Internal Methods
  
  int execute(string& input_filename, string& rand_filename, string& sched_type, bool verbose_tag); //run simulator by calling the execute() method, returns the exit status as a int

};

#endif
