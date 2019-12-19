#include "utility/jj_timer.h"

using namespace std;
using namespace joshtrick;


Timer::Timer(const string name)
{
  this->proc_name = name;
  this->counter = 0;
  this->time = 0;
}

Timer::Timer()
{
  this->proc_name = "Execucation";
  this->counter = 0;
  this->time = 0;
}

void Timer::reset(const string name)
{
  this->proc_name = name;
  this->counter = 0;
  this->time = 0;
  this->t_start.tv_nsec = 0;
  this->t_start.tv_sec = 0;
  this->t_end.tv_nsec = 0;
  this->t_end.tv_sec = 0;
  this->t_diff.tv_nsec = 0;
  this->t_diff.tv_sec = 0;
}

void Timer::reset()
{
  this->proc_name = "Execucation";
  this->counter = 0;
  this->time = 0;
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

void Timer::diff()
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

  float current_time = this->t_diff.tv_sec * 1e3 + this->t_diff.tv_nsec / 1e6;
  this->time += current_time;
  this->counter += 1;
  cout << "[Timer] " << this->proc_name
    << " instant [" << this->counter <<"]: "
    << current_time << " ms" << endl;
}

void Timer::sum()
{
  cout << "[Timer] " << this->proc_name
    << " total   [" << this->counter << "]: "
    << this->time << " ms" << endl;
}

void Timer::avg()
{
  float avg_time = 0;
  if(this->counter > 0)
  {
    avg_time = time / counter;
  }
  cout << "[Timer] " << this->proc_name
    << " average [" << this->counter << "]: "
    << avg_time << " ms" << endl;
}
