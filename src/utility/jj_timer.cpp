#include "utility/jj_timer.h"

using namespace std;
using namespace joshtrick;

// ********PUBLIC********
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

  float current_time = this->t_diff.tv_sec * 1e6 + this->t_diff.tv_nsec / 1e3;
  this->time += current_time;
  this->counter += 1;
  print_time(" instant [", current_time);
}

void Timer::sum()
{
  print_time(" total   [", this->time);
}

void Timer::avg()
{
  float avg_time = 0;
  if(this->counter > 0)
  {
    avg_time = time / counter;
  }
  print_time(" average [", avg_time);
}

// ********PRIVATE********
void Timer::print_time(const string info, const float time)
{
  if(time < 1e3)
  {
    cout << "[Timer] " << this->proc_name
      << info << this->counter <<"]: "
      << time << " us" << endl;
  }
  else if(time < 1e6)
  {
    cout << "[Timer] " << this->proc_name
      << info << this->counter <<"]: "
      << time / 1e3 << " ms" << endl;
  }
  else
  {
    cout << "[Timer] " << this->proc_name
      << info << this->counter <<"]: "
      << time / 1e6 << " s" << endl;
  }
}
