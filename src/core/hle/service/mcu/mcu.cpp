// Copyright 2019 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#include "core/core.h"
#include "core/hle/service/mcu/mcu.h"
#include "core/hle/service/mcu/mcu_hwc.h"

namespace Service::MCU {

void Module::Interface::GetBatteryVoltage(Kernel::HLERequestContext& ctx) {
    IPC::RequestParser rp(ctx, 0x4, 0, 0);

    IPC::RequestBuilder rb = rp.MakeBuilder(2, 0);
    rb.Push(RESULT_SUCCESS);
    // ~4.1v, when the charger is plugged into a fully charged O3DS
    rb.Push<u8>(0xD1);

    LOG_DEBUG(Service_MCU, "(STUBBED) called");
}

void Module::Interface::GetBatteryLevel(Kernel::HLERequestContext& ctx) {
    IPC::RequestParser rp(ctx, 0x5, 0, 0);

    IPC::RequestBuilder rb = rp.MakeBuilder(2, 0);
    rb.Push(RESULT_SUCCESS);
    rb.Push<u8>(100); // Fully charged (0x64)

    LOG_DEBUG(Service_MCU, "(STUBBED) called");
}

void Module::Interface::GetMcuFwVerHigh(Kernel::HLERequestContext& ctx) {
    IPC::RequestParser rp(ctx, 0x10, 0, 0);

    IPC::RequestBuilder rb = rp.MakeBuilder(2, 0);
    rb.Push(RESULT_SUCCESS);
    // Old3DS v6145 to v8192 (latest) used MCU FW 2.37
    rb.Push<u8>(2 + 0x10);

    LOG_DEBUG(Service_MCU, "(STUBBED) called");
}

void Module::Interface::GetMcuFwVerLow(Kernel::HLERequestContext& ctx) {
    IPC::RequestParser rp(ctx, 0x10, 0, 0);

    IPC::RequestBuilder rb = rp.MakeBuilder(2, 0);
    rb.Push(RESULT_SUCCESS);
    // Old3DS v6145 to v8192 (latest) used MCU FW 2.37
    rb.Push<u8>(37);

    LOG_DEBUG(Service_MCU, "(STUBBED) called");
}

Module::Module() {
    // empty
}

Module::Interface::Interface(std::shared_ptr<Module> mcu, const char* name, u32 max_sessions)
    : ServiceFramework(name, max_sessions), mcu(std::move(mcu)) {}

void InstallInterfaces(Core::System& system) {
    auto& service_managaer = system.ServiceManager();
    auto mcu = std::make_shared<Module>();
    std::make_shared<MCU_HWC>(mcu)->InstallAsService(service_managaer);
}

} // namespace Service::MCU