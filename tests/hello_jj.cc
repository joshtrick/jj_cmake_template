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
  print_joshtrick();
  cout << MSG_TAG
    << "Hello Joshtrick"
    << endl;
  while(true)
  {
  global_timer.tic();
  sleep(1);
  global_timer.toc();
  global_timer.calculate();
  cout << global_timer.instant() << endl;
  cout << global_timer.average() << endl;
  cout << global_timer.total() << endl;
  cout << endl;
  }

  return 0;
}

