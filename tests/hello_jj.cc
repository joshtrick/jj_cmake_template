#include <iostream>
#include <string>
#include <unistd.h>

#include "utility/jj_msg_tag.h"
#include "utility/jj_timer.h"
#include "utility/jj_printer.h"

int main()
{
  joshtrick::Timer global_timer("Testing loop");
  print_joshtrick();
  std::cout << MSG_TAG
    << "Hello Joshtrick"
    << std::endl;
  while(true)
  {
  global_timer.tic();
  sleep(10);
  global_timer.toc();
  global_timer.calculate();
  global_timer.instant();
  global_timer.average();
  global_timer.total();
  std::cout << std::endl;
  }

  return 0;
}

