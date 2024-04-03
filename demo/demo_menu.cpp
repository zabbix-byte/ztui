#include "demo_menu.h"
#include "../ztui/widgets.h"

#include "../ztui/style/palet.h"
#include "../ztui/ztui.h"


static ImVec4 color_base_text = ztui_theme_palet::alert;
static bool color_base_text_actived = false;

void demo_menu()
{
	widgets::text_centered("THIS IS A CENTERED TEXT", 1.0f, -1.f, color_base_text);
	widgets::space_separator();
	widgets::text("THIS IS A NOT CENTERED TEXT", 1.0f, -1.f, ztui_theme_palet::primary);
	widgets::space_separator();
	widgets::text("THIS IS A BIGGER TEXT", 1.2f, -1.f, ztui_theme_palet::primary);
	widgets::space_separator();

	if (widgets::button(
		"This is a button >> click me to change text centered text color",
		1.0f,
		-1.f,
		false,
		ztui_theme_palet::link,
		ImVec2(0, 0),
		false,
		ImVec4(0.1176470592617989f, 0.1333333402872086f, 0.1490196138620377f, 1.0f)
	))
	{
		if (!color_base_text_actived)
		{
			color_base_text = ztui_theme_palet::link;
			color_base_text_actived = true;
		}
		else
		{
			color_base_text = ztui_theme_palet::alert;
			color_base_text_actived = false;
		}
		
	}
	widgets::space_separator();
	static bool a = false, b = false, c = false, d = false;
	static float Value = 0;
	float min = 0, max = 100;
	Gui.MyCheckBox("     CheckBox1", &a);
	widgets::space_separator();
	Gui.MyCheckBox2("    CheckBox2", &b);
	widgets::space_separator();
	Gui.MyCheckBox3("    CheckBox3", &c);
	widgets::space_separator();
	Gui.MyCheckBox4("    CheckBox4", &d);
	widgets::space_separator();
	Gui.SliderScalarEx1("[Slider]", ImGuiDataType_Float, &Value, &min, &max, "%.1f", ImGuiSliderFlags_None);
}