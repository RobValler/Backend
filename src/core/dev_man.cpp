/*****************************************************************
 * Copyright (C) 2017-2022 Robert Valler - All rights reserved.
 *
 * This file is part of the project: Comms
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#include "dev_man.h"

#include "ros2_wrap.h"

#include "Logger.h"


bool CDeviceMan::Init()
{
    CLOG(LOGLEV_RUN, "CDeviceMan::Init()");
    mp_proto_ros = std::make_shared<CProtocolROS>();

    return true;
}

bool CDeviceMan::Start()
{
    CLOG(LOGLEV_RUN, "CDeviceMan::Start()");
    return true;
}

bool CDeviceMan::Process()
{
    CLOG(LOGLEV_RUN, "CDeviceMan::Process()");
    return true;
}

bool CDeviceMan::Stop()
{
    CLOG(LOGLEV_RUN, "CDeviceMan::Stop()");
    return true;
}
