#include "event.h"


Event::Event(int _timestamp, int _process_id, int _exec_time, string _old_state, string _new_state, int _event_count)//initialze member variables
  :timestamp(_timestamp),process_id(_process_id),exec_time(_exec_time),old_state(_old_state),new_state(_new_state),event_count(_event_count)
{}

Event::Event(Event& e){
  timestamp = e.timestamp;
  process_id = e.process_id;
  exec_time = e.exec_time;
  old_state = e.old_state;
  new_state = e.new_state;
  event_count = e.event_count;
}

Event::~Event(){}

//arrival_time based comparison
bool operator<(Event& a, Event& b){
  return (a.timestamp < b.timestamp);
}

bool operator>(Event& a, Event& b){
  //stable operator > based on line number order
  if (a.timestamp != b.timestamp){
    return a.timestamp > b.timestamp;
  }
  return a.event_count > b.event_count;
}

ostream& operator<< (ostream& ost, Event& e){
  //output event in the following format: 0 0 0: OLD -> NEW, no appending \n\r
  return ost << e.timestamp << " " << e.process_id << " " << e.exec_time << ": " << e.old_state << " -> " << e.new_state;
}

////testing class Event
//int main(){
//  cout << "Please enter the test event:" << "\n\r";
//  int ts, pid, et;
//  string old_str;
//  string new_str;
//  cin >> ts >> pid >> et >> old_str >> new_str;
//  Event test_evt(ts,pid,et,old_str,new_str);
//  cout << test_evt << "\r\n"; 
//  return 0; 
//}
