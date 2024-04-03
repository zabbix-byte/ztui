#include "main_menu.h"
#include "../ztui/widgets.h"
#include "demo_menu.h"
#include "settings_menu.h"
#include "globals.h"

// ztui
#include "../ztui/style/style.h"
#include "../ztui/style/palet.h"
#include "../ztui/ztui.h"
#include "../ztui/font/icons_font_awesome.h"

void main_menu()
{


	ImGui::SetNextWindowSize(ImVec2(1200, 600));
	ImGui::Begin("ZT BASE CHEAT", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar);
	{
		ztui_styling();

		ImGui::SetCursorPos(ImVec2(220, 10));

		if (ImGui::BeginChild(1, ImVec2(970, 50), false))
		{
			ImGui::SameLine();
			ImGui::SetCursorPosX(900.f);

			if (widgets::button(ICON_FA_TIMES, 1.f, 15.f, false, ztui_theme_palet::alert, ImVec2(50.f, 35.f), true))
			{
				Gui.Quit();
			}

			ImGui::SameLine();
			widgets::text_centered("[HOME] TO HIDE MENU", 1.f, 13.0f, ztui_theme_palet::primary);

			ImGui::SameLine();
			ImGui::SetCursorPosX(10.f);

			if (widgets::button("SETINGS", 1.0f, 10.f, false, ztui_theme_palet::link))
			{
				SETTINGS_MENU = true;
				RAGE_MENU = false;
			}


		} ImGui::EndChild();

		ImGui::SetCursorPos(ImVec2(10, 10));

		if (ImGui::BeginChild(2, ImVec2(200, 578), false))
		{
			widgets::text_centered("ZT BASE CHEAT", 1.0f, 10.f, ztui_theme_palet::link);

			if (ImGui::BeginChild(3, ImVec2(200, 520), false))
			{
				widgets::text_centered("", 1.0f, -1.f, ztui_theme_palet::primary);
				ImGui::Separator();

				widgets::text_centered("AimBot", 1.0f, -1.f, ztui_theme_palet::primary);
				ImGui::SetCursorPosX(10.f);
				if (widgets::button("RAGE", 1.0f, -1.f, false, ztui_theme_palet::link))
				{
					SETTINGS_MENU = false;
					RAGE_MENU = true;
				}
				ImGui::SetCursorPosX(10.f);
				widgets::button("ANTI-AIM", 1.0f, -1.f, false, ztui_theme_palet::primary);
				ImGui::SetCursorPosX(10.f);
				widgets::button("LEGIT-BOT", 1.0f, -1.f, false, ztui_theme_palet::primary);

				widgets::text_centered("", 1.0f, -1.f, ztui_theme_palet::primary);
				ImGui::Separator();

				widgets::text_centered("Visuals", 1.0f, -1.f, ztui_theme_palet::primary);
				ImGui::SetCursorPosX(10.f);
				widgets::button("PLAYER", 1.0f, -1.f, false, ztui_theme_palet::primary);
				ImGui::SetCursorPosX(10.f);
				widgets::button("WEAPON", 1.0f, -1.f, false, ztui_theme_palet::primary);

				widgets::text_centered("", 1.0f, -1.f, ztui_theme_palet::primary);
				ImGui::Separator();

				widgets::text_centered("Misc", 1.0f, -1.f, ztui_theme_palet::primary);
				ImGui::SetCursorPosX(10.f);
				widgets::button("BHOP", 1.0f, -1.f, false, ztui_theme_palet::primary);
				ImGui::SetCursorPosX(10.f);

				widgets::text_centered("", 1.0f, -1.f, ztui_theme_palet::link);
				ImGui::Separator();
				widgets::text_centered("BY ZABBIX", 1.f, 501.f, ztui_theme_palet::link);
			} ImGui::EndChild();

		} ImGui::EndChild();

		
		ImGui::SetCursorPos(ImVec2(220, 70));
		if (ImGui::BeginChild(6, ImVec2(970, 517), false))
		{
			if (SETTINGS_MENU)
				settings_menu();
			if (RAGE_MENU)
				demo_menu();
		} ImGui::EndChild();
		
	}ImGui::End();

}
