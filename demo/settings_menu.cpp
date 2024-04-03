#include "settings_menu.h"
#include "../ztui/widgets.h"

// ztui
#include "../ztui/style/palet.h"
#include "../ztui/ztui.h"


void settings_menu()
{
	widgets::text_centered("SETTINGS", 1.0f, 50.f, ztui_theme_palet::link);
}