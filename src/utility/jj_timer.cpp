#include "utility/jj_timer.h"

using namespace std;
using namespace joshtrick;

// ********PUBLIC********
Timer::Timer(const string name)
{
  reset(name);
}

Timer::Timer()
{
  reset();
}

void Timer::reset(const string name)
{
  reset();
  this->proc_name = name;
}

void Timer::reset()
{
  this->proc_name = "Execucation";
  this->counter = 0;
  this->total_time = 0;
  this->instant_time = 0;
  this->average_time = 0;
  this->t_start.tv_nsec = 0;
  this->t_start.tv_sec = 0;
  this->t_end.tv_nsec = 0;
  this->t_end.tv_sec = 0;
  this->t_diff.tv_nsec = 0;
  this->t_diff.tv_sec = 0;
}

void Timer::tic()
{
  clock_gettime(CLOCK_REALTIME, &this->t_start);
}

void Timer::toc()
{
  clock_gettime(CLOCK_REALTIME, &this->t_end);
}

void Timer::calculate()
{
  if((this->t_end.tv_nsec - this->t_start.tv_nsec) < 0)
  {
    this->t_diff.tv_sec = this->t_end.tv_sec - this->t_start.tv_sec-1;
    this->t_diff.tv_nsec = 1e9 + this->t_end.tv_nsec - this->t_start.tv_nsec;
  }
  else
  {
    this->t_diff.tv_sec = this->t_end.tv_sec - this->t_start.tv_sec;
    this->t_diff.tv_nsec = this->t_end.tv_nsec - this->t_start.tv_nsec;
  }
  // in microsecond
  this->instant_time = this->t_diff.tv_sec * 1e6 + this->t_diff.tv_nsec / 1e3;
  this->total_time += this->instant_time;
  this->counter += 1;
  this->average_time = this->total_time / this->counter;
}


float Timer::instant()
{
  return print_time(" instant [", this->instant_time);
}

float Timer::average()
{
  return print_time(" average [", this->average_time);
}

float Timer::total()
{
  return print_time(" total   [", this->total_time);
}

// ********PRIVATE********
float Timer::print_time(const string info, const float time)
{
  // in microsecond
  if(time < 1e3)
  {
    cout << "[Timer] " << this->proc_name
      << info << this->counter <<"]: "
      << time << " us" << endl;
  }
  // in millisecond
  else if(time < 1e6)
  {
    cout << "[Timer] " << this->proc_name
      << info << this->counter <<"]: "
      << time / 1e3 << " ms" << endl;
  }
  // in second
  else if(time < 6e7)
  {
    cout << "[Timer] " << this->proc_name
      << info << this->counter <<"]: "
      << time / 1e6 << " s" << endl;
  }
  // in minute
  else if(time < 36e8)
  {
    cout << "[Timer] " << this->proc_name
      << info << this->counter <<"]: "
      << time / 6e7 << " min" << endl;
  }
  //in hour
  else if(time < 864e8)
  {
    cout << "[Timer] " << this->proc_name
      << info << this->counter <<"]: "
      << time / 36e8 << " hr" << endl;
  }
  // in day
  else
  {
    cout << "[Timer] " << this->proc_name
      << info << this->counter <<"]: "
      << time / 864e8 << " d" << endl;
  }
  return time;
}
