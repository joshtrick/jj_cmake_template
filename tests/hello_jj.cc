#include <iostream>
#include <string>
#include <unistd.h>

#include "utility/jj_msg_tag.h"
#include "utility/jj_timer.h"
#include "utility/jj_printer.h"
using namespace std;

int main()
{
  joshtrick::Timer global_timer("Testing loop");
  float instant_t = 0;
  float average_t = 0;
  float total_t   = 0;

  print_joshtrick();
  cout << MSG_TAG
    << "Hello Joshtrick"
    << endl;
  while(true)
  {
    global_timer.tic();
    sleep(5);
    global_timer.toc();
    global_timer.calculate();
    instant_t = global_timer.instant();
    average_t = global_timer.average();
    total_t = global_timer.total();
    cout << endl;
    cout << "Instant: " << instant_t << " us" << endl;
    cout << "Average: " << average_t << " us" << endl;
    cout << "Total  : " << total_t << " us" << endl;
    cout << "~~~~~~~~" << endl;
  }

  return 0;
}

