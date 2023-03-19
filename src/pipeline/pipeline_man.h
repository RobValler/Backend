/*****************************************************************
 * Copyright (C) 2017-2022 Robert Valler - All rights reserved.
 *
 * This file is part of the project: Comms
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#include "IComponent.h"
#include "FactoryBase.h"


#include <memory>

class CFactory;

class CPipelineMan
        : public IComponent
        , public CFactoryBase
{
public:
    CPipelineMan(std::shared_ptr<CFactory> factory);
    ~CPipelineMan(){};

    bool Init() override;
    bool Start() override;
    bool Read(std::shared_ptr<void>) override { return false; }
    bool Write(const std::shared_ptr<void>) override { return false; }
    bool Process() override;
    bool Stop() override;

private:
    std::shared_ptr<CFactory> mp_factory;

};
