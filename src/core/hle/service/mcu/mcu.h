// Copyright 2019 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#pragma once

#include <memory>
#include "common/common_types.h"
#include "core/hle/ipc_helpers.h"
#include "core/hle/service/service.h"

namespace Core {
class System;
}

namespace Service::MCU {
class Module final {
public:
    Module();

    class Interface : public ServiceFramework<Interface> {
    public:
        Interface(std::shared_ptr<Module> mcu, const char* name, u32 max_sessions);

    protected:
        /**
         * MCU::GetBatteryVoltage service function
         *  Outputs:
         *      1 : Result code
         *      2 : u8 value
         */
        void GetBatteryVoltage(Kernel::HLERequestContext& ctx);

        /**
         * MCU::GetBatteryLevel service function
         *  Outputs:
         *      1 : Result code
         *      2 : u8 battery_level
         */
        void GetBatteryLevel(Kernel::HLERequestContext& ctx);

        /**
         * MCU::GetMcuFwVerHigh service function
         *  Outputs:
         *      1 : Result code
         *      2 : MCU FW major version (+ 0x10)
         */
        void GetMcuFwVerHigh(Kernel::HLERequestContext& ctx);

        /**
         * MCU::GetMcuFwVerLow service function
         *  Outputs:
         *      1 : Result code
         *      2 : MCU FW minor version
         */
        void GetMcuFwVerLow(Kernel::HLERequestContext& ctx);

    private:
        std::shared_ptr<Module> mcu;
    };

private:
    // Empty
};

void InstallInterfaces(Core::System& system);

} // namespace Service::MCU