#ifndef JJ_TIMER_H
#define JJ_TIMER_H

#include <iostream>
#include <string>
#include <string.h>
#include <unistd.h>
#include <time.h>

class ProcTimer
{
public:
    ProcTimer(std::string name);
    ProcTimer();
    void tic();
    float toc();
private:
    std::string proc_name;
    long time_ms, time_us, time_ns, dt_ns;
    time_t time_s, dt_s;
    float time;
    timespec t_start, t_end;
};


#endif //JJ_TIMER_H
