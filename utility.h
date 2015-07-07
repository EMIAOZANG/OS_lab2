#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include <string>
#include "event.h"
#include "process.h"

class GreaterEvent{
  //Comparator of Event Objects
 public:
  bool operator() (const Event& e_1, const Event& e_2);
};

#endif
