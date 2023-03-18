/*****************************************************************
 * Copyright (C) 2017-2022 Robert Valler - All rights reserved.
 *
 * This file is part of the project: Comms
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#include "input_man.h"

#include "factory.h"
#include "ros_wrap.h"

#include "Logger.h"

#include <chrono>

CInputMan::CInputMan(std::shared_ptr<CFactory> factory)
    : mp_factory(factory)
{

}

bool CInputMan::Init()
{
    CLOG(LOGLEV_RUN, "CInputMan::Init()");

    return true;
}

bool CInputMan::Start()
{
    CLOG(LOGLEV_RUN, "CInputMan::Start()");

    t_thread = std::thread(&CInputMan::ThreadFunc, this);

    return true;
}

bool CInputMan::Process()
{
    CLOG(LOGLEV_RUN, "CInputMan::Process()");
    return true;
}

bool CInputMan::Stop()
{
    CLOG(LOGLEV_RUN, "CInputMan::Stop()");
    m_isExitCalled = true;

    t_thread.join();

    return true;
}

void CInputMan::ThreadFunc()
{
    while(!m_isExitCalled) {

    //    std::static_pointer_cast<CRosWrap>(mp_factory->getModule("DeviceMan")



        std::this_thread::sleep_for(std::chrono::milliseconds (500));
    }
}

