/*****************************************************************
 * Copyright (C) 2017-2019 Robert Valler - All rights reserved.
 *
 * This file is part of the project: StarterApp
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#include "core.h"
#include <chrono>
#include <thread>


int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    CCore core;

    core.Start();

    std::this_thread::sleep_for(std::chrono::seconds (1));

    core.Stop();

}
