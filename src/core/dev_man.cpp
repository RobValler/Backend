/*****************************************************************
 * Copyright (C) 2017-2022 Robert Valler - All rights reserved.
 *
 * This file is part of the project: Comms
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#include "dev_man.h"

#include "ros_wrap.h"
#include "proto_dummy.h"

#include "Logger.h"


CDeviceMan::CDeviceMan(std::shared_ptr<CFactory> factory)
    : mp_factory(factory)
{

}

bool CDeviceMan::Init()
{
    CLOG(LOGLEV_RUN, "CDeviceMan::Init()");
    mp_proto_ros = std::make_shared<CRosWrap>();
    mp_proto_dummy = std::make_shared<CProtoDummy>();

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
    mp_proto_ros.reset();
    mp_proto_dummy.reset();
    CLOG(LOGLEV_RUN, "CDeviceMan::Stop()");
    return true;
}
