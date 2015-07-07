#include "process.h"

Process::Process(int arrival_time, int total_cpu, int cpu_burst, int io_burst, int prio, string _status)
  :AT(arrival_time),TC(total_cpu),CB(cpu_burst),IO(io_burst),priority(prio),rem_time(total_cpu),status(_status)
{}

Process::Process(string& init_str, int prio, string _status)
  :priority(prio),status(_status)
{
  stringstream ss(init_str);
  ss >> AT >> TC >> CB >> IO;
  rem_time = CB;
}

Process::~Process(){}



