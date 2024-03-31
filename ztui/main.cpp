#include "main.hpp";
#include "../imgui/imgui.h"

void loop()
{
	ImGui::GetBackgroundDrawList()->AddCircle({ 500, 500 }, 10.f, ImColor(1.f, 0.f, 0.f));
}