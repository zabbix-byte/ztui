#include "widgets_style.h"
#include "palet.h"

void widgets_style::style_element_button(const bool no_hover_button, ImVec4 color)
{
	ImGuiStyle& style = ImGui::GetStyle();
	if (no_hover_button)
		style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.f, 0.f, 0.f, 0.f);
		style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.f, 0.f, 0.f, 0.f);
	style.Colors[ImGuiCol_Button] = color;
	
}

void widgets_style::reset_style_element_button()
{
	ImGuiStyle& style = ImGui::GetStyle();
	style.Colors[ImGuiCol_ButtonHovered] = ImGuiCol_ButtonHoveredDefault;
	style.Colors[ImGuiCol_ButtonActive] = ImGuiCol_ButtonActiveDefault;
	style.Colors[ImGuiCol_Button] = ImGuiCol_ButtonDefault;
}


void widgets_style::style_padding(const float x, const float y)
{
	ImGuiStyle& style = ImGui::GetStyle();
	style.WindowPadding = ImVec2(x, y);
}