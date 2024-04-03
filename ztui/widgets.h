#pragma once
#include "imgui/imgui.h"

namespace widgets
{
	void text_centered(const char* fmt, const float size, const float margin, ImVec4 rgba);
	bool button(
		const char* fmt,
		const float size_font,
		const float margin,
		const bool centered,
		ImVec4 rgba,
		const ImVec2 size_button = ImVec2(0, 0),
		const bool no_hover = false
	);
}