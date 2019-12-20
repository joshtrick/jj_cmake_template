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
    void calculate();
    void instant();
    void average();
    void total();
  private:
    std::string proc_name;
    float instant_time, total_time, average_time, counter;
    timespec t_start, t_end, t_diff;
    void print_time(const std::string info, const float time);
  };
} //namespace joshtrick

#endif //JJ_TIMER_H
