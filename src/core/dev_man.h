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

class CRosWrap;

class CDeviceMan : public IComponent
{
public:
    CDeviceMan() =default;
    ~CDeviceMan(){};

    bool Init() override;
    bool Start() override;
    bool Process() override;
    bool Stop() override;

private:
    std::shared_ptr<CRosWrap> mp_proto_ros;

};
