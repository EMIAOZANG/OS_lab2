#include <iostream>

using namespace std;

class Event{
 public:
   //Variables
   int AT;
   int TC;
   int CB;
   int IO;

   //Methods
   Event(int arrival_time, int total, int cpu_burst, int io_burst);
   Event();//void constructor
   ~Event();
};



