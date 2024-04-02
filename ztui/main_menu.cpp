#include "main_menu.h"
#include "imgui_elements_utils.h"
#include "style/style.h"
#include "style/palet.h"
#include "ztui.h"
#include "demo_menu.h"
#include "settings_menu.h"
#include "globals.h"

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
			if (imgui_elementes::button("X", 1.2f, 5.f, false, ztui_theme_palet::alert, ImVec2(60.f, 40.f)))
			{
				Gui.Quit();
			}
			ImGui::SameLine();
			imgui_elementes::text_centered("[HOME] TO HIDE MENU", 0.68f, 13.0f, ztui_theme_palet::primary);

			ImGui::SameLine();
			ImGui::SetCursorPosX(10.f);

			if (imgui_elementes::button("SETTINGS", 1.0f, 10.f, false, ztui_theme_palet::link))
			{
				SETTINGS_MENU = true;
				RAGE_MENU = false;
			}


		} ImGui::EndChild();

		ImGui::SetCursorPos(ImVec2(10, 10));

		if (ImGui::BeginChild(2, ImVec2(200, 578), false))
		{
			imgui_elementes::text_centered("ZT BASE CHEAT", 1.0f, 10.f, ztui_theme_palet::link);

			if (ImGui::BeginChild(3, ImVec2(200, 520), false))
			{
				imgui_elementes::text_centered("", 1.0f, -1.f, ztui_theme_palet::primary);
				ImGui::Separator();

				imgui_elementes::text_centered("AimBot", 1.0f, -1.f, ztui_theme_palet::primary);
				ImGui::SetCursorPosX(10.f);
				if (imgui_elementes::button("RAGE", 1.0f, -1.f, false, ztui_theme_palet::link))
				{
					SETTINGS_MENU = false;
					RAGE_MENU = true;
				}
				ImGui::SetCursorPosX(10.f);
				imgui_elementes::button("ANTI-AIM", 1.0f, -1.f, false, ztui_theme_palet::primary);
				ImGui::SetCursorPosX(10.f);
				imgui_elementes::button("LEGIT-BOT", 1.0f, -1.f, false, ztui_theme_palet::primary);

				imgui_elementes::text_centered("", 1.0f, -1.f, ztui_theme_palet::primary);
				ImGui::Separator();

				imgui_elementes::text_centered("Visuals", 1.0f, -1.f, ztui_theme_palet::primary);
				ImGui::SetCursorPosX(10.f);
				imgui_elementes::button("PLAYER", 1.0f, -1.f, false, ztui_theme_palet::primary);
				ImGui::SetCursorPosX(10.f);
				imgui_elementes::button("WEAPON", 1.0f, -1.f, false, ztui_theme_palet::primary);

				imgui_elementes::text_centered("", 1.0f, -1.f, ztui_theme_palet::primary);
				ImGui::Separator();

				imgui_elementes::text_centered("Misc", 1.0f, -1.f, ztui_theme_palet::primary);
				ImGui::SetCursorPosX(10.f);
				imgui_elementes::button("BHOP", 1.0f, -1.f, false, ztui_theme_palet::primary);
				ImGui::SetCursorPosX(10.f);

				imgui_elementes::text_centered("", 1.0f, -1.f, ztui_theme_palet::link);
				ImGui::Separator();
				imgui_elementes::text_centered("BY ZABBIX", 0.68f, 501.f, ztui_theme_palet::link);


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
