#pragma once
#include "../imgui/imgui.h"


namespace widgets_style
{
	void style_element_button(const bool no_hover, ImVec4 color);
	void style_padding(const float x, const float y);
	void reset_style_element_button();
}