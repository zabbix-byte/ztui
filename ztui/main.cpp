#include <iostream>
#include "ztui.h"
#include "imgui_elements_utils.h"
#include "style/style.h"
#include "font/icons_font_awesome.h"

void DrawCallBack()
{
	ImGui::SetNextWindowSize(ImVec2(900, 500));
	ImGui::Begin("ZT BASE CHEAT", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar);
	{
		ztui_styling();

		ImGui::SetCursorPos(ImVec2(220, 10));

		if (ImGui::BeginChild(1, ImVec2(670, 50), false))
		{
			imgui_elementes::button(ICON_FA_WINDOW_CLOSE, 1.f, -1.f, true, ztui_theme_palet::primary, ImVec2(60.f, 30.f));
		} ImGui::EndChild();

		ImGui::SetCursorPos(ImVec2(10, 10));

		if (ImGui::BeginChild(2, ImVec2(200, 475), false))
		{
			imgui_elementes::text_centered("ZT BASE CHEAT", 1.0f, 10.f, ztui_theme_palet::link);

			if (ImGui::BeginChild(3, ImVec2(200, 420), false))
			{
				imgui_elementes::text_centered("", 1.0f, -1.f, ztui_theme_palet::link);
				imgui_elementes::text_centered("Aimbot", 1.0f, -1.f, ztui_theme_palet::link);
				imgui_elementes::button("Ragebot", 1.0f, -1.f, true, ztui_theme_palet::primary);
				imgui_elementes::button("Anti Aim", 1.0f, -1.f, true, ztui_theme_palet::primary);
				imgui_elementes::button("Legitbot", 1.0f, -1.f, true, ztui_theme_palet::primary);
				imgui_elementes::text_centered("", 1.0f, -1.f, ztui_theme_palet::link);
				imgui_elementes::text_centered("Visuals", 1.0f, -1.f, ztui_theme_palet::link);
				imgui_elementes::button("Player", 1.0f, -1.f, true, ztui_theme_palet::primary);
				imgui_elementes::button("Weapon", 1.0f, -1.f, true, ztui_theme_palet::primary);
			} ImGui::EndChild();

		} ImGui::EndChild();

		

		// Example of text ImGui::Text("This is a text.");

		/* example of button 
		if (ImGui::Button("Button"))
		{
			//...
		}
		*/
		
		

		// static bool a = false
		// Example of checkbox Gui.MyCheckBox("CheckBox1", &a);

		//static float Value = 0;
		// float min = 0, max = 100;
		// Example of slider Gui.SliderScalarEx1("[Slider]", ImGuiDataType_Float, &Value, &min, &max, "%.1f", ImGuiSliderFlags_None);
	}ImGui::End();

	// Example of drawn circle: Gui.ShadowRectFilled({ 50,50 }, { 100,100 }, ImColor(220, 190, 99, 255), ImColor(50, 50, 50, 255), 9, { 0,0 }, 10);
	// Example of drawn circle: Gui.ShadowCircle({ 200,200 }, 30, ImColor(220, 190, 99, 255), ImColor(50, 50, 50, 255), 9, { 0,0 });

	//...
}

int main()
{
	try {
		Gui.AttachAnotherWindow("Counter-Strike 2","SDL_app", DrawCallBack);
	}
	catch (Ztui::OSException& e)
	{
		std::cout << e.what() << std::endl;
	}

	system("pause");
	return 0;
}