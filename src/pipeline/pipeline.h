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


class CPipeLine
        : public IComponent
{
public:
    CPipeLine() =default;
    ~CPipeLine(){};

    bool Init() override { return true; }
    bool Start() override { return true; }
    bool Read(std::shared_ptr<void>) override { return false; }
    bool Write(const std::shared_ptr<void>) override;
    bool Process() override;
    bool Stop() override  { return true; }

};

