#include "drawn_cheat.h";
#include "../ztui/ztui.h"


void drawn_cheat()
{
	// Example of drawn circle: Gui.ShadowRectFilled({ 50,50 }, { 100,100 }, ImColor(220, 190, 99, 255), ImColor(50, 50, 50, 255), 9, { 0,0 }, 10);
	// Example of drawn circle: Gui.ShadowCircle({ 200,200 }, 30, ImColor(220, 190, 99, 255), ImColor(50, 50, 50, 255), 9, { 0,0 });

	//...

	Gui.ShadowRectFilled({ 50,50 }, { 100,100 }, ImColor(220, 190, 99, 255), ImColor(50, 50, 50, 255), 9, { 0,0 }, 10);
}