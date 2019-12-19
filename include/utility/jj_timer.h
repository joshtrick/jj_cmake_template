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
    void tic();
    float toc();
  private:
    std::string proc_name;
    long time_ms, time_us, time_ns, dt_ns;
    time_t time_s, dt_s;
    float time;
    timespec t_start, t_end;
  };
} //namespace joshtrick

#endif //JJ_TIMER_H
