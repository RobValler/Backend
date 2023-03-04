/*****************************************************************
 * Copyright (C) 2017-2022 Robert Valler - All rights reserved.
 *
 * This file is part of the project: Comms
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/


#pragma once

#include <memory>

class CFactory;
class CProtocolROS;

class CCore
{
public:
    CCore();
    ~CCore() =default;

    void Start();
    void Stop();

private:
    std::shared_ptr<CFactory> mp_factory;

};
