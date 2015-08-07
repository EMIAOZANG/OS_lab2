#include <iostream>
#include <cstdio>
#include <iostream>
#include <deque>
#include <queue>

#include "process.h"
#include "event.h"

using namespace std;

class Scheduler{
 public:
   //constructor & deconstructor

   Scheduler();

   //methods
//   virtual bool add_process()=0;//adding process 
   virtual bool pick_process()=0;
};

class FCFS_Scheduler: public Scheduler{
 public:

   FCFS_Scheduler();

   Process* pick_process(Event& e); //the core function of scheduler, picks the process that is supposed to be added to the ready queue

   bool add_process();
   bool get_next_process();


};

class LCFS_Scheduler: public Scheduler{
};

class SJF_Scheduler: public Scheduler{
};

class PRIO_Scheduler: public Scheduler{
};

class RR_Scheduler: public Scheduler{
};


