#include "utility/cr_printer.h"
#include "utility/cr_timer.h"
#define LOGO_ENABLE 1
int main()
{
  print_program_info(__FILE__, 1);
  //print_cr_header(1);
  float time;

  Proctimer timer;

  timer.get_start_time();
  print_debug("Something wrong: %s\n", "Hello");
  time = timer.get_end_time("Hello");

  printf("[CORERAIN] Time = %f\n", time);
  printf("[CORERAIN] End of the program\n");
  return 0;
}
