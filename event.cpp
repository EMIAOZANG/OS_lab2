#include <iostream>
#include "event.h"

using namespace std;

Event::Event(int arrival_time, int total, int cpu_burst, int io_burst){
  AT = arrival_time;
  TC = total;
  CB = cpu_burst;
  IO = io_burst;
}

Event::~Event(){}

//arrival_time based comparison
bool operator<(Event& a, Event& b){
  return (a.AT < b.AT);
}

ostream& operator<< (ostream& ost, Event& e){
  return ost << e.AT << " " << e.TC << " " << e.CB << " " << e.IO;
}

//testing class Event
int main(){
  cout << "Please enter the test event:" << "\n\r";
  int AT , TC , CB , IO;
  cin >> AT>> TC>> CB>> IO;
  Event test_evt(AT, TC, CB, IO);
  cout << test_evt << "\r\n"; 
  return 0; 
}
