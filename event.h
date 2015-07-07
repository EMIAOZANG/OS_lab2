#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Event{
 public:
   //Variables
   int timestamp;
   int process_id;
   int exec_time;//execution time of the operation
   string old_state;
   string new_state;
   
   int event_count;//line number of the event that appeared 

   //Methods
   Event(int _timestamp, int _process_id, int _exec_time, string _old_state, string _new_state, int _event_count);
   Event(Event& e);//copy constructor
   Event();//void constructor
   ~Event();
};

bool operator<(Event& a, Event& b);
bool operator>(Event& a, Event& b);
ostream& operator<< (ostream& ost, Event& e);


#endif
