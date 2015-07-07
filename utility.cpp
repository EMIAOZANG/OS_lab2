//implementation of class GreaterEvent
#include "utility.h"

bool GreaterEvent::operator() (const Event& e_1, const Event& e_2){
  if (e_1.timestamp != e_2.timestamp){
    return e_1.timestamp > e_2.timestamp;
  }
  return e_1.event_count > e_2.event_count;
}
