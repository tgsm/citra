// Copyright 2014 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#include "core/hle/service/ac/ac_u.h"

namespace Service {
namespace AC {

AC_U::AC_U(std::shared_ptr<Module> ac) : Module::Interface(std::move(ac), "ac:u", 10) {
    static const FunctionInfo functions[] = {
        {0x00010000, &AC_U::CreateDefaultConfig, "CreateDefaultConfig"},
        {0x00015004, nullptr, "ExclusiveAsync"},
        {0x00020042, nullptr, "DebugSetApType"},
        {0x00030042, nullptr, "DebugSetNetworkArea"},
        {0x00040006, &AC_U::ConnectAsync, "ConnectAsync"},
        {0x00050002, &AC_U::GetConnectResult, "GetConnectResult"},
        {0x000600C6, nullptr, "DebugSetNetworkSetting1"},
        {0x00070002, nullptr, "CancelConnectAsync"},
        {0x00080004, &AC_U::CloseAsync, "CloseAsync"},
        {0x00090002, &AC_U::GetCloseResult, "GetCloseResult"},
        {0x000A0000, nullptr, "GetLastErrorCode"},
        {0x000B0000, nullptr, "GetLastDetailErrorCode"},
        {0x000C0000, nullptr, "GetStatus"},
        {0x000D0000, &AC_U::GetWifiStatus, "GetWifiStatus"},
        {0x000E0042, nullptr, "GetCurrentAPInfo"},
        {0x000F0000, nullptr, "GetConnectingInfraPriority"},
        {0x00100042, nullptr, "GetCurrentNZoneInfo"},
        {0x00110042, nullptr, "GetNZoneApNumService"},
        {0x00120042, nullptr, "GetConnectingHotspot"},
        {0x00130042, nullptr, "GetConnectingHotspotSubset"},
        {0x00140002, nullptr, "GetConnectingLocation"},
        {0x00160002, nullptr, "GetExclusiveResult"},
        {0x00170004, nullptr, "UnExclusiveAsync"},
        {0x00180002, nullptr, "GetUnExclusiveResult"},
        {0x00190004, nullptr, "CloseAllAsync"},
        {0x001A0002, nullptr, "GetCloseAllResult"},
        {0x001B0004, nullptr, "LogoutHotspotAsync"},
        {0x001C0002, nullptr, "GetLogoutHotspotResult"},
        {0x001D0042, nullptr, "ScanAPs"},
        {0x00240042, nullptr, "AddDenyApType"},
        {0x00270002, &AC_U::GetInfraPriority, "GetInfraPriority"},
        {0x002D0082, &AC_U::SetRequestEulaVersion, "SetRequestEulaVersion"},
        {0x00300004, &AC_U::RegisterDisconnectEvent, "RegisterDisconnectEvent"},
        {0x00310002, nullptr, "GetStatusChangeEvent"},
        {0x00320042, nullptr, "SetAuthServerType"},
        {0x00330000, nullptr, "GetConnectingSecurityMode"},
        {0x00340000, nullptr, "GetConnectingSsid"},
        {0x00350000, nullptr, "GetConnectingSsidLength"},
        {0x00360000, nullptr, "GetConnectingProxyEnable"},
        {0x00370000, nullptr, "GetConnectingProxyAuthType"},
        {0x00380000, nullptr, "GetConnectingProxyPort"},
        {0x00390000, nullptr, "GetConnectingProxyHost"},
        {0x003A0000, nullptr, "GetConnectingProxyUserName"},
        {0x003B0000, nullptr, "GetConnectingProxyPassword"},
        {0x003C0042, nullptr, "GetAPSSIDList"},
        {0x003D0042, nullptr, "SetZoneMacFilter"},
        {0x003E0042, &AC_U::IsConnected, "IsConnected"},
        {0x003F0040, nullptr, "GetNotAwakeMacFilter"},
        {0x00400042, &AC_U::SetClientVersion, "SetClientVersion"},
        {0x004100C6, nullptr, "SetTemporaryNetworkSettings"},
    };
    RegisterHandlers(functions);
}

} // namespace AC
} // namespace Service
