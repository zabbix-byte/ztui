#include "ztui_base.h"
#include "font/font_array.h"
#include "font/icons_font_awesome.h"

namespace Ztui
{
    bool ZtuiBase::InitImGui(ID3D11Device* device, ID3D11DeviceContext* device_context)
    {
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO();
        io.Fonts->AddFontDefault();

        ImFontAtlas* fontAtlas = new ImFontAtlas();

        ImFontConfig msyhbd_config;
        msyhbd_config.FontDataOwnedByAtlas = false;
        ImFont* msyhbd_font = fontAtlas->AddFontFromFileTTF("ztui\\font\\Roboto-Medium.ttf", 18.f, &msyhbd_config);

        ImFontConfig icon_config;
        static const ImWchar iconRanges[] = { ICON_MIN_FA, ICON_MAX_FA, 0 };
        icon_config.MergeMode = true;
        icon_config.PixelSnapH = true;
        icon_config.GlyphMinAdvanceX = 20.f;
        ImFont* icon_font = fontAtlas->AddFontFromFileTTF("ztui\\font\\fa-solid-900.ttf", 23.f, &icon_config, iconRanges);
        io.Fonts = fontAtlas;

        ImGui::StyleColorsDark();
        io.LogFilename = nullptr;

        if (!ImGui_ImplWin32_Init(Window.hWnd))
            throw OSException("ImGui_ImplWin32_Init() call failed.");
        if (!ImGui_ImplDX11_Init(device, device_context))
            throw OSException("ImGui_ImplDX11_Init() call failed.");

        return true;
    }

    void ZtuiBase::CleanImGui()
    {
        ImGui_ImplDX11_Shutdown();
        ImGui_ImplWin32_Shutdown();
        ImGui::DestroyContext();

        g_Device.CleanupDeviceD3D();
        DestroyWindow(Window.hWnd);
        UnregisterClassA(Window.ClassName.c_str(), Window.hInstance);
    }

    std::wstring ZtuiBase::StringToWstring(std::string& str)
    {
        std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
        return converter.from_bytes(str);
    }

}