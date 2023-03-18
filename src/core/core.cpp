/*****************************************************************
 * Copyright (C) 2017-2022 Robert Valler - All rights reserved.
 *
 * This file is part of the project: Comms
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/


#include "core.h"

// local
#include "dev_man.h"
#include "pipeline_man.h"
#include "input_man.h"

// conan packages
#include "factory.h"
#include "IComponent.h"
#include "Logger.h"

#include <memory>

CCore::CCore()
{
    mp_factory = std::make_shared<CFactory>();

    mp_factory->addModule("DeviceMan", std::make_shared<CDeviceMan>(mp_factory));
    mp_factory->addModule("PipelineMan", std::make_shared<CPipelineMan>(mp_factory));
    mp_factory->addModule("InputMan", std::make_shared<CInputMan>(mp_factory));

    mp_factory->init();
}

void CCore::Start()
{
    CLOG(LOGLEV_RUN, "Core Start");

    mp_factory->start();

    mp_factory->getModule("PipelineMan")->Process();
    mp_factory->getModule("InputMan")->Process();
    mp_factory->getModule("doesnotexist")->Process();
}

void CCore::Stop()
{
    mp_factory->stop();
    mp_factory->removeAll();
}
