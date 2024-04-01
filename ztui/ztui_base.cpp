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
        (void)io;

        ImFontAtlas* fontAtlas = new ImFontAtlas();

        ImFontConfig arialConfig;
        arialConfig.FontDataOwnedByAtlas = false;
        // Todo: And check this to, becouse i dont like Verdana.
        ImFont* arialFont = fontAtlas->AddFontFromFileTTF("C:\\Windows\\Fonts\\Verdana.ttf", 25.f, &arialConfig);

        ImFontConfig iconConfig;
        static const ImWchar iconRanges[] = { ICON_MIN_FA, ICON_MAX_FA, 0 };
        iconConfig.MergeMode = true;
        iconConfig.PixelSnapH = true;
        iconConfig.OversampleH = 3;
        iconConfig.OversampleV = 3;
        iconConfig.GlyphRanges = iconRanges;
        iconConfig.FontDataOwnedByAtlas = false;
        // Todo: Check this some problems with TTF
        ImFont* iconFont = fontAtlas->AddFontFromMemoryTTF((void*)rawData, sizeof(rawData), 16.f, &iconConfig, iconRanges);
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