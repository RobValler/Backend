/*****************************************************************
 * Copyright (C) 2017-2022 Robert Valler - All rights reserved.
 *
 * This file is part of the project: Comms
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#include "IComponent.h"

#include <memory>
#include <atomic>
#include <thread>

class CFactory;

class CInputMan : public IComponent
{
public:
    CInputMan(std::shared_ptr<CFactory> factory);
    ~CInputMan(){};

    bool Init() override;
    bool Start() override;
    bool Process() override;
    bool Stop() override;

private:
    void ThreadFunc();
    std::thread t_thread;
    std::atomic<bool> m_isExitCalled{false};

    std::shared_ptr<CFactory> mp_factory;


};
