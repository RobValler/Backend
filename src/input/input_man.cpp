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
#include "types.h"
#include "Logger.h"

#include "pipeline_man.h"
#include "buffer.h"


#include <chrono>
#include <memory>

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

    if(t_thread.joinable()) {
            t_thread.join();
     } else {
        t_thread.detach();
        CLOG(LOGLEV_RUN, "Thread join failed");
        return false;
    }

    return true;
}

void CInputMan::ThreadFunc()
{
    while(!m_isExitCalled) {

        SPipeBuffPayload s;
//        std::static_pointer_cast<CPipelineBuffer<SPipeBuffPayload>>(mp_factory->getModule("PipelineBuffer"))->Write(s);




        if(GET_MODULE(CPipelineBuffer<SPipeBuffPayload>, mp_factory, "PipelineBuffer")->Read(s)) {

        }

        GET_MODULE(CPipelineBuffer<SPipeBuffPayload>, mp_factory, "PipelineBuffer")->Write(s);




        std::this_thread::sleep_for(std::chrono::milliseconds (500));
    }
}

