#include <iostream>
#include <string>
#include <unistd.h>

#include "utility/jj_msg_tag.h"
#include "utility/jj_timer.h"
#include "utility/jj_printer.h"

int main()
{
  joshtrick::Timer global_timer("Loop_0");
  print_joshtrick();
  std::cout << MSG_TAG
    << "Hello Joshtrick"
    << std::endl;
  global_timer.tic();
  usleep(1);
  global_timer.toc();
  global_timer.diff();
  std::cout << std::endl;

  global_timer.tic();
  usleep(1000);
  global_timer.toc();
  global_timer.diff();
  std::cout << std::endl;

  global_timer.tic();
  usleep(1000000);
  global_timer.toc();
  global_timer.diff();
  std::cout << std::endl;

  global_timer.tic();
  usleep(10000000);
  global_timer.toc();
  global_timer.diff();
  global_timer.sum();
  global_timer.avg();
  std::cout << std::endl;

  return 0;
}

