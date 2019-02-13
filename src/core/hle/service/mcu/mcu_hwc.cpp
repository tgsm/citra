// Copyright 2019 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#include "core/hle/service/mcu/mcu_hwc.h"

namespace Service::MCU {

MCU_HWC::MCU_HWC(std::shared_ptr<Module> mcu) : Module::Interface(std::move(mcu), "mcu::HWC", 1) {
    static const FunctionInfo functions[] = {
        {0x00010082, nullptr, "ReadRegister"},
        {0x00020082, nullptr, "WriteRegister"},
        {0x00030042, nullptr, "GetInfoRegisters"},
        {0x00040000, &MCU_HWC::GetBatteryVoltage, "GetBatteryVoltage"},
        {0x00050000, &MCU_HWC::GetBatteryLevel, "GetBatteryLevel"},
        {0x00060040, nullptr, "SetPowerLEDPattern"},
        {0x00070040, nullptr, "SetWifiLEDState"},
        {0x00080040, nullptr, "SetCameraLEDPattern"},
        {0x00090040, nullptr, "Set3DLEDState"},
        {0x000A0640, nullptr, "SetInfoLEDPattern"},
        {0x000B0000, nullptr, "GetSoundVolume"},
        {0x000C0040, nullptr, "SetTopScreenFlicker"},
        {0x000D0040, nullptr, "SetBottomScreenFlicker"},
        // 0x000E0080 is currently unknown
        {0x000F00C0, nullptr, "GetRtcTime"},
        {0x00100000, &MCU_HWC::GetMcuFwVerHigh, "GetMcuFwVerHigh"},
        {0x00110000, &MCU_HWC::GetMcuFwVerLow, "GetMcuFwVerLow"},
    };
    RegisterHandlers(functions);
}

} // namespace Service::MCU
