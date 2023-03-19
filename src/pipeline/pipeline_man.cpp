/*****************************************************************
 * Copyright (C) 2017-2022 Robert Valler - All rights reserved.
 *
 * This file is part of the project: Comms
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#include "pipeline_man.h"
#include "pipeline.h"
#include "factory.h"
#include "types.h"

#include "Logger.h"

#include <string>
#include <vector>

namespace {

    struct _SPipeLine {
        EFlow ID;
        std::string func_name;
    };

    std::vector<_SPipeLine> SPipeLine {
        {EFlow::eNone, ""},
        {EFlow::eDefault, "Pipeline_ONE"}
    };
} // namespace


CPipelineMan::CPipelineMan(std::shared_ptr<CFactory> factory)
    : mp_factory(factory)
{

}

bool CPipelineMan::Init()
{
    CLOG(LOGLEV_RUN, "CPipelineMan::Init()");

    addModule("Pipeline_ONE", std::make_shared<CPipeLine>());



    return true;
}

bool CPipelineMan::Start()
{
    CLOG(LOGLEV_RUN, "CPipelineMan::Start()");
    return true;
}

bool CPipelineMan::Process()
{
    CLOG(LOGLEV_RUN, "CPipelineMan::Process()");

    SPipeBuffPayload s;

    std::shared_ptr<void> data;
    mp_factory->getModule("PipelineBuffer")->Read(data);


    for(const auto& it : SPipeLine) {
        if(s.id == it.ID) {
            mp_factory->getModule(it.func_name)->Process();

        }
    }


    return true;
}

bool CPipelineMan::Stop()
{
    CLOG(LOGLEV_RUN, "CPipelineMan::Stop()");
    return true;
}
