#include <iostream>

#include "utility/jj_timer.h"
#include "utility/jj_msg_tag.h"

int main()
{
    ProcTimer global_timer("msn");
    global_timer.tic();
    global_timer.toc();

    std::cout << MSG_TAG \
        << "Hello world" \
        << std::endl;

    return 0;
}

