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
  for(int i = 1; i < 5; i++)
  {
    global_timer.tic();
    global_timer.toc();
    global_timer.diff();
    global_timer.sum();
    global_timer.avg();
    std::cout << std::endl;
  }
  return 0;
}

