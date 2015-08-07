#include <vector>
#include "simulator.h"
#include "event.h"
#include "utility.h"

//implementation of constructor
Simulator::Simulator(){}

int Simulator::myRandom(int burst){
  return (1 + (randvals.at(ofs)% burst));
}

bool Simulator::init_randval_list(string& rand_filename){
  ifstream fin;
  fin.open(rand_filename.c_str());

  if (fin.is_open() == false){
    return false;
  }
  int curr_randval = 0;
  while (fin >> curr_randval){
    randvals.push_back(curr_randval);
  }
  return true;
}

bool Simulator::init_process_n_event(string input_filename){
  //initialize the input file stream
  ifstream fin;
  fin.open(input_filename.c_str());
  if (!fin.is_open()){
    cout << "cannot open input file!" << "\n\r";
    exit(1);
    return false;//return false if file cannot be opened
  }
  int line_counter = 0;

  int curr_timestamp = 0;
  int curr_TC = 0;
  int curr_CB = 0;
  int curr_IO = 0;

  while (fin >> curr_timestamp >> curr_TC >> curr_CB >> curr_IO ) {
    Process new_process(line_counter,curr_timestamp, curr_TC, curr_CB, curr_IO, myRandom(4));
    //add process to the process list
    process_list.push_back(new_process);
    cout << new_process << endl;
    //create CREATED -> READY event
    put_event(new_process.AT, process_list.size()-1, 0, "CREATED", "READY", line_counter);
    line_counter++;
  }

  while (!event_queue.empty()) {
    cout << event_queue.top() << endl;
    event_queue.pop();
  }

  return true;
}

bool Simulator::get_event(){
  return true;
}

void Simulator::put_event(int _timestamp, int _process_id, int _exec_time, string _old_state, string _new_state, int _event_count){
  Event new_event(_timestamp, _process_id, _exec_time, _old_state, _new_state, _event_count);
  event_queue.push(new_event);
}
//
//int Simulator::decode_event(int _timestamp, int _process_id, int _old_state, int _new_state){
//
//}
//testing simulator functions
