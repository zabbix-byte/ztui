#include "widgets_style.h"
#include "../imgui/imgui.h"

void widgets_style::style_element_button(const bool no_hover_button)
{
	ImGuiStyle& style = ImGui::GetStyle();
	if (no_hover_button)
	{
		style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.f, 0.f, 0.f, 0.f);
		style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.f, 0.f, 0.f, 0.f);
	}
}
