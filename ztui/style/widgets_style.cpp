#include "widgets_style.h"

void widgets_style::style_element_button(const bool no_hover_button, ImVec4 color)
{
	ImGuiStyle& style = ImGui::GetStyle();
	if (no_hover_button)
		style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.f, 0.f, 0.f, 0.f);
		style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.f, 0.f, 0.f, 0.f);
	style.Colors[ImGuiCol_Button] = color;
	
}


void widgets_style::style_padding(const float x, const float y)
{
	ImGuiStyle& style = ImGui::GetStyle();
	style.WindowPadding = ImVec2(x, y);
}