/*****************************************************************
 * Copyright (C) 2017-2022 Robert Valler - All rights reserved.
 *
 * This file is part of the project: Comms
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/


#pragma once

#include <cstdint>
#include <string>

enum class EFlow: std::uint8_t
{
    eNone =0,
    eDefault,
    eDummyToROS
};

struct SPipeBuffPayload {
    EFlow id;
    std::string test_string;
};
