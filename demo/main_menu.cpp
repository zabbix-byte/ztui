#include "main_menu.h"

#include "demo_menu.h"
#include "settings_menu.h"
#include "globals.h"

// ztui
#include "../ztui/widgets.h"
#include "../ztui/style/widgets_style.h"
#include "../ztui/style/style.h"
#include "../ztui/style/palet.h"
#include "../ztui/ztui.h"
#include "../ztui/font/icons_font_awesome.h"

void main_menu()
{
	ImVec4 settigs_actived = ztui_theme_palet::primary;
	ImVec4 demo_actived = ztui_theme_palet::primary;

	if (SETTINGS_MENU == true)
		settigs_actived = ztui_theme_palet::link;

	if (DEMO_MENU == true)
		demo_actived = ztui_theme_palet::link;

	ImGui::SetNextWindowSize(ImVec2(1200, 600));
	ImGui::Begin("ZT BASE CHEAT", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar);
	{
		ztui_styling();

		ImGui::SetCursorPos(ImVec2(220, 10));

		if (ImGui::BeginChild(1, ImVec2(970, 50), false))
		{
			ImGui::SameLine();
			ImGui::SetCursorPosX(900.f);

			if (widgets::button(ICON_FA_TIMES, 1.3f, 10.f, false, ztui_theme_palet::alert, ImVec2(50.f, 35.f), true))
			{
				Gui.Quit();
			}

			ImGui::SameLine();
			widgets::text_centered("[HOME] TO HIDE MENU", 1.f, 13.0f, ztui_theme_palet::primary);

			ImGui::SameLine();
			ImGui::SetCursorPosX(10.f);

			if (widgets::button(ICON_FA_COGS" SETINGS", 1.0f, 10.f, false, settigs_actived))
			{
				SETTINGS_MENU = true;
				DEMO_MENU = false;
			}


		} ImGui::EndChild();

		ImGui::SetCursorPos(ImVec2(10, 10));
		if (ImGui::BeginChild(2, ImVec2(200, 578), false))
		{

			widgets::text_centered(ICON_FA_DRAGON"  ZTUI", 1.f, 32.f, ztui_theme_palet::link);
			widgets::text_centered("BY ZABBIX", 0.8f, 55.f, ztui_theme_palet::secundary);
			widgets::space_separator();
			ImGui::Separator();

			widgets_style::style_padding(14.f, 20.f);
			if (ImGui::BeginChild(3, ImVec2(200, 450), false, ImGuiWindowFlags_AlwaysUseWindowPadding))
			{
				widgets::text("Main menu", 1.24f, -1.f, ztui_theme_palet::primary);
				widgets::space_separator();

				if (widgets::button(ICON_FA_WINDOW_RESTORE"   Elements", 1.0f, -1.f, false, demo_actived))
				{
					SETTINGS_MENU = false;
					DEMO_MENU = true;
				}

				

				widgets::space_separator();
				widgets::text("Dummy Menu", 1.20f, -1.f, ztui_theme_palet::primary);
				widgets::space_separator();

				if (widgets::button(ICON_FA_BASKETBALL_BALL"   Dummy1", 1.0f, -1.f, false, ztui_theme_palet::secundary)) {}
				if (widgets::button(ICON_FA_BASKETBALL_BALL"   Dummy2", 1.0f, -1.f, false, ztui_theme_palet::secundary)) {}
				if (widgets::button(ICON_FA_BASKETBALL_BALL"   Dummy3", 1.0f, -1.f, false, ztui_theme_palet::secundary)) {}
				if (widgets::button(ICON_FA_BASKETBALL_BALL"   Dummy4", 1.0f, -1.f, false, ztui_theme_palet::secundary)) {}
				if (widgets::button(ICON_FA_BASKETBALL_BALL"   Dummy6", 1.0f, -1.f, false, ztui_theme_palet::secundary)) {}
				if (widgets::button(ICON_FA_BASKETBALL_BALL"   Dummy7", 1.0f, -1.f, false, ztui_theme_palet::secundary)) {}
				if (widgets::button(ICON_FA_BASKETBALL_BALL"   Dummy8", 1.0f, -1.f, false, ztui_theme_palet::secundary)) {}


			} ImGui::EndChild();
			ztui_styling();
		} ImGui::EndChild();

		widgets_style::style_padding(30.f, 30.f);
		ImGui::SetCursorPos(ImVec2(220, 70));
		if (ImGui::BeginChild(6, ImVec2(970, 517), false, ImGuiWindowFlags_AlwaysUseWindowPadding))
		{
			if (SETTINGS_MENU)
				settings_menu();
			if (DEMO_MENU)
				demo_menu();
		} ImGui::EndChild();
		ztui_styling();
		
	}ImGui::End();

}
