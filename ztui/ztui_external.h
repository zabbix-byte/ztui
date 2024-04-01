#pragma once
#include "ztui_base.h"


namespace Ztui
{
	class ZtuiExternal : public ZtuiBase
	{
	private:
		WindowType Type = NEW;
	public:
		void NewWindow(std::string WindowName, Vec2 WindowSize, std::function<void()> CallBack);
		void AttachAnotherWindow(std::string DestWindowName, std::string DestWindowClassName, std::function<void()> CallBack);
	private:
		void MainLoop();
		bool UpdateWindowData();
		bool CreateMyWindow();
		bool PeekEndMessage();
	};
}