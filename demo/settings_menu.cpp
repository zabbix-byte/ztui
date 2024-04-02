#include "settings_menu.h"
#include "imgui_elements_utils.h"

// ztui
#include "../ztui/style/palet.h"
#include "../ztui/ztui.h"


void settings_menu()
{
	imgui_elementes::text_centered("SETTINGS", 1.0f, 50.f, ztui_theme_palet::link);
}