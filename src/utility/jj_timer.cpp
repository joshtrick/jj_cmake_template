#include "utility/jj_timer.h"

using namespace std;
//using namespace joshtrick;

joshtrick::Timer::Timer(const string name)
{
  proc_name = name;
}

joshtrick::Timer::Timer()
{
  proc_name = "Execucation";
}

void joshtrick::Timer::tic()
{
  clock_gettime(CLOCK_REALTIME, &t_start);
}

float joshtrick::Timer::toc()
{
  clock_gettime(CLOCK_REALTIME, &t_end);
  dt_s = t_end.tv_sec-t_start.tv_sec;
  dt_ns = t_end.tv_nsec-t_start.tv_nsec;
  time = dt_s+dt_ns/1e9;
  if(dt_ns < 0)
  {
    time_s = dt_s-1;
    time_ms = dt_ns/1e6+1e3;
    time_us = dt_ns/1e3+1e6-time_ms*1e3;
    time_ns = dt_ns+1e9-time_us*1e3-time_ms*1e6;
  }
  else
  {
    time_s = dt_s;
    time_ms = dt_ns/1e6;
    time_us = dt_ns/1e3-time_ms*1e3;
    time_ns = dt_ns-time_us*1e3-time_ms*1e6;
  }
  cout << "[Speed Test] "
    << proc_name << " time: "
    << time_s << " s, "
    << time_ms << " ms, "
    << time_us <<" us, "
    << time_ns << " ns." << endl;
  return time;
}
