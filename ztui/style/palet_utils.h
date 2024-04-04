#pragma once
#include "../utils/ini.h"
#include "../imgui/imgui.h"
#include "palet.h"


static const char* styles_declared_in_palet[11] = {
		"ImGuiCol_ButtonDefault",
		"ImGuiCol_WindowBgDefault",
		"ImGuiCol_ChildBgDefault",
		"ImGuiCol_ButtonHoveredDefault",
		"ImGuiCol_ButtonActiveDefault",
		"primary",
		"alert",
		"secundary",
		"active",
		"title",
		"logo"
};

static const char index[4] = { 'X', 'Y', 'Z', 'W' };

static ImVec4 get_style(std::string style, bool new_value = false, ImVec4 value = ImVec4(0, 0, 0, 0))
{
	if (style == "ImGuiCol_ButtonDefault")
	{
		if (new_value)
			ztui_theme_palet::ImGuiCol_ButtonDefault = value;
		return ztui_theme_palet::ImGuiCol_ButtonDefault;
	}
		

	if (style == "ImGuiCol_WindowBgDefault")
	{
		if (new_value)
			ztui_theme_palet::ImGuiCol_WindowBgDefault = value;
		return ztui_theme_palet::ImGuiCol_WindowBgDefault;
	}
		

	if (style == "ImGuiCol_ChildBgDefault")
	{
		if (new_value)
			ztui_theme_palet::ImGuiCol_ChildBgDefault = value;
		return ztui_theme_palet::ImGuiCol_ChildBgDefault;
	}
		

	if (style == "ImGuiCol_ButtonHoveredDefault")
	{
		if (new_value)
			ztui_theme_palet::ImGuiCol_ButtonHoveredDefault = value;
		return ztui_theme_palet::ImGuiCol_ButtonHoveredDefault;
	}
		

	if (style == "ImGuiCol_ButtonActiveDefault")
	{
		if (new_value)
			ztui_theme_palet::ImGuiCol_ButtonActiveDefault = value;
		return ztui_theme_palet::ImGuiCol_ButtonActiveDefault;
	}
		

	if (style == "primary")
	{
		if (new_value)
			ztui_theme_palet::primary = value;
		return ztui_theme_palet::primary;
	}
		

	if (style == "alert")
	{
		if (new_value)
			ztui_theme_palet::alert = value;
		return ztui_theme_palet::alert;
	}

	if (style == "secundary")
	{
		if (new_value)
			ztui_theme_palet::secundary = value;
		return ztui_theme_palet::secundary;
	}

	if (style == "active")
	{
		if (new_value)
			ztui_theme_palet::active = value;
		return ztui_theme_palet::active;
	}

	if (style == "title")
	{
		if (new_value)
			ztui_theme_palet::title = value;
		return ztui_theme_palet::title;
	}

	if (style == "logo")
	{
		if (new_value)
			ztui_theme_palet::logo = value;
		return ztui_theme_palet::logo;
	}

	return ImVec4(0, 0, 0, 0);
}


static void write_theme_to_ini()
{
	mINI::INIStructure ini_structure = INI::read("./ztui/style/gui.ini");
	std::string current;
	ImVec4 curernt_style;
	std::string current_sub;

	for (int i = 0; i < sizeof(styles_declared_in_palet) / sizeof(styles_declared_in_palet[0]); i++)
	{
		current = styles_declared_in_palet[i];
		curernt_style = get_style(current);

		for (int j = 0; j < sizeof(index); j++)
		{
			current_sub = current + '_' + index[j];
			if ('X' == index[j])
				ini_structure["GUI"][current_sub] = std::to_string(curernt_style.x);
			if ('Y' == index[j])
				ini_structure["GUI"][current_sub] = std::to_string(curernt_style.y);
			if ('Z' == index[j])
				ini_structure["GUI"][current_sub] = std::to_string(curernt_style.z);
			if ('W' == index[j])
				ini_structure["GUI"][current_sub] = std::to_string(curernt_style.w);
		}
	}

	INI::write("./ztui/style/gui.ini", ini_structure);
}


static void update_palet_ini()
{
	mINI::INIStructure ini_structure = INI::read("./ztui/style/gui.ini");
	ImVec4 current_vec;
	std::string current_sub;
	float temp_x;
	float temp_y;
	float temp_z;
	float temp_w;

	for (int i = 0; i < sizeof(styles_declared_in_palet) / sizeof(styles_declared_in_palet[0]); i++)
	{
		std::string current = styles_declared_in_palet[i];

		for (int j = 0; j < sizeof(index); j++)
		{
			current_sub = current + '_' + index[j];
			if ('X' == index[j])
			{
				std::string& current_index = ini_structure["GUI"][current_sub];
				temp_x = (float)std::stod(current_index);
			}
				
			if ('Y' == index[j])
			{
				std::string& current_index = ini_structure["GUI"][current_sub];
				temp_y = (float)std::stod(current_index);
			}
				
			if ('Z' == index[j])
			{
				std::string& current_index = ini_structure["GUI"][current_sub];
				temp_z = (float)std::stod(current_index);
			}
				
			if ('W' == index[j])
			{
				std::string& current_index = ini_structure["GUI"][current_sub];
				temp_w = (float)std::stod(current_index);
			}
			
		}

		current_vec = ImVec4(temp_x, temp_y, temp_z, temp_w);
		get_style(current, true, current_vec);
	}
}


