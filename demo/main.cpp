#include <thread>

#include <iostream>
#include "main_menu.h"
#include "globals.h"
#include "drawn_cheat.h"

// ztui
#include "../ztui/ztui.h"

static std::string dest_window_name = "Counter-Strike 2";
static std::string dest_window_class_name = "SDL_app";


void callback()
{
	drawn_cheat();

	// handling main menu
	static std::chrono::time_point LastTimePoint = std::chrono::steady_clock::now();
	auto CurTimePoint = std::chrono::steady_clock::now();
	
	if (GetAsyncKeyState(VK_HOME) && CurTimePoint - LastTimePoint >= std::chrono::milliseconds(150))
	{
		if (MENU)
			MENU = false;
		else
			MENU = true;

		LastTimePoint = CurTimePoint;
	}

	if (MENU)
		main_menu();
}

int main()
{
	try {
		Gui.AttachAnotherWindow(dest_window_name, dest_window_class_name, callback);
	}
	catch (Ztui::OSException& e)
	{
		std::cout << e.what() << std::endl;
	}

	system("pause");
	return 0;
}