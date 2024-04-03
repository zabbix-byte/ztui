#include "widgets.h"
#include "style/widgets_style.h"
#include "style/style.h"

void widgets::text_centered(const char* fmt, const float size, const float margin, ImVec4 rgba)
{
	ImGui::SetCursorPosX(((ImGui::GetWindowSize().x - ImGui::CalcTextSize(fmt).x) * 0.5f) / size);
	widgets::text(fmt, size, margin, rgba);
}

void widgets::text(const char* fmt, const float size, const float margin, ImVec4 rgba)
{
	ImGui::SetWindowFontScale(size);
	if (margin != -1.f)
		ImGui::SetCursorPosY(margin);
	ImGui::PushStyleColor(ImGuiCol_Text, rgba);
	ImGui::Text(fmt);
	ImGui::SetWindowFontScale(1.0f);
	ImGui::PopStyleColor();
}


bool widgets::button(
	const char* fmt,
	const float size_font,
	const float margin,
	const bool centered,
	ImVec4 rgba, 
	const ImVec2 size_button,
	const bool no_hover,
	const ImVec4 color
)
{
	widgets_style::style_element_button(no_hover, color);
	ImGui::SetWindowFontScale(size_font);
	if (centered)
		ImGui::SetCursorPosX((ImGui::GetWindowSize().x - ImGui::CalcTextSize(fmt).x) * 0.35f);
	if (margin != -1.f)
		ImGui::SetCursorPosY(margin);
	ImGui::PushStyleColor(ImGuiCol_Text, rgba);
	bool val = ImGui::Button(fmt, size_button);
	ImGui::PopStyleColor();
	ImGui::SetWindowFontScale(1.0f);
	widgets_style::reset_style_element_button();
	return val;
}


void widgets::space_separator()
{
	widgets::text_centered("", 1.0f, -1.f, ztui_theme_palet::primary);
}

