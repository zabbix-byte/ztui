#include <Windows.h>
#include <thread>

#include <dwmapi.h>
#include <d3d11.h>
#include <windowsx.h>
#include "../imgui/imgui.h"
#include "../imgui/imgui_impl_dx11.h"
#include "../imgui/imgui_impl_win32.h"

const static int WIDTH = GetSystemMetrics(SM_CXSCREEN);
const static int HEIGHT = GetSystemMetrics(SM_CYSCREEN);

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);


LRESULT CALLBACK window_procedure(HWND window, UINT message, WPARAM w_param, LPARAM l_param)
{
	if (ImGui_ImplWin32_WndProcHandler(window, message, w_param, l_param))
	{
		return 0L;
	}

	if (message == WM_DESTROY)
	{
		PostQuitMessage(0);
		return 0L;
	}

	switch (message)
	{
	case WM_NCHITTEST:
	{
		const LONG border_width = GetSystemMetrics(SM_CXSIZEFRAME);
		const LONG title_bar_height = GetSystemMetrics(SM_CYCAPTION);

		POINT cursor_pos = { GET_X_LPARAM(w_param), GET_Y_LPARAM(l_param) };
		RECT window_rect;

		GetWindowRect(window, &window_rect);

		if (cursor_pos.y >= window_rect.top && cursor_pos.y < window_rect.top + title_bar_height)
		{
			return HTCAPTION;
		}

		break;
	}
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0L;
	}

	return DefWindowProc(window, message, w_param, l_param);
}
