#include "process.h"

Process::Process(int _process_id, int arrival_time, int total_cpu, int cpu_burst, int io_burst, int prio, int rem)
  :process_id(_process_id),AT(arrival_time),TC(total_cpu),CB(cpu_burst),IO(io_burst),priority(prio),rem_time(rem)
{}

//Process::Process(string& init_str, int prio)
//  :priority(prio)
//{
//  stringstream ss(init_str);
//  ss >> AT >> TC >> CB >> IO;
//  rem_time = CB;
//}

ostream& operator<< (ostream& ost, Process& p){
  ost << "Process " << p.process_id << ":\t" << "AT: " << p.AT << " TC: " << p.TC << " CB: " << p.CB << " IO: " << p.IO << endl;
  ost << "rem: " << p.rem_time << " prio: " << p.priority << endl;
  return ost;
}



