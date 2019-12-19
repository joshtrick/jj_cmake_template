#ifndef JJ_TIMER_H
#define JJ_TIMER_H

#include <iostream>
#include <string>
#include <string.h>
#include <unistd.h>
#include <time.h>

namespace joshtrick
{
  class Timer
  {
  public:
    Timer(const std::string name);
    Timer();
    void reset(const std::string name);
    void reset();
    void tic();
    void toc();
    void diff();
    void sum();
    void avg();
  private:
    std::string proc_name;
    float time, counter;
    timespec t_start, t_end, t_diff;
  };
} //namespace joshtrick

#endif //JJ_TIMER_H
