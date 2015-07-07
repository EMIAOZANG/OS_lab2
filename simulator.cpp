#include "simulator.h"
#include "event.h"
#include "utility.h"

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

bool Simulator::init_process_n_event(string& input_filename){
  //initialize the input file stream
  ifstream fin;
  fin.open(input_filename.c_str());
  if (!fin.is_open()){
    cout << "cannot open input file!" << "\n\r";
    return false;//return false if file cannot be opened
  }
  string temp_process_str = "";
  int line_counter = 0;
  while (getline(fin, temp_process_str)){
    Process new_process(temp_process_str);
    //modify process status
    new_process.status = "READY";
    //add process to the process list
    process_list.push_back(new_process);
    //create CREATED -> READY event
    put_event(new_process.AT, process_list.size()-1, 0, "CREATED", "READY", line_counter);
    line_counter++;
  }
  return true;
}

bool Simulator::get_event(){
  return true;
}

void Simulator::put_event(int _timestamp, int _process_id, int _exec_time, string _old_state, string _new_state, int _event_count){
  Event e(_timestamp, _process_id, _exec_time, _old_state, _new_state, _event_count);
  cout << e << endl;
}
//
//int Simulator::decode_event(int _timestamp, int _process_id, int _old_state, int _new_state){
//
//}
//testing simulator functions
int main(){
  Simulator s;
  s.put_event(30,1,20,"CREATED","READY",0);
  return 0;
}
