// Copyright 2019 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#pragma once

#include "core/hle/service/service.h"

namespace Core {
class System;
}

namespace Service::MP {

class MP_U final : public ServiceFramework<MP_U> {
public:
    MP_U();
    ~MP_U() = default;

private:
    // function declarations go here
};

void InstallInterfaces(Core::System& system);

} // namespace Service::MP