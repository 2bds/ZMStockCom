// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//  are changed infrequently
//

#pragma once

// Change these values to use different versions
#define WINVER			0x0500
#define _WIN32_WINNT	0x0501
#define _WIN32_IE		0x0501
#define _RICHEDIT_VER	0x0500

#include <atlbase.h>
/// ����ʹ��ATL��CString
#define _CSTRING_NS	ATL
#define _WTL_NEW_PAGE_NOTIFY_HANDLERS

#include "WTL\\atlapp.h"

extern CAppModule _Module;

#include <atlcom.h>
#include <atlhost.h>
#include <atlwin.h>
#include <atlctl.h>

#include "WTL\\atlframe.h"
#include "WTL\\atlctrls.h"
#include "WTL\\atldlgs.h"

#if defined _M_IX86
  #pragma comment(linker, "/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_IA64
  #pragma comment(linker, "/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='ia64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
  #pragma comment(linker, "/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
  #pragma comment(linker, "/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif

/// ʹ��EXE��COM�����֧��64λ�������
#import "..\\Bin\\ZMStockCom.exe" no_namespace, raw_interfaces_only, raw_native_types, named_guids
/// ʹ��DLL��COM����������COM���BINĿ¼�����ļ�������ִ�г����һ��
//#import "..\\Bin\\ZMTradeCom.dll" no_namespace, raw_interfaces_only, raw_native_types, named_guids

/// ��׼��ֻ֧�ֵ�����
#define		ZM_ACCOUNT_CONNMAXCOUNT	1
/// �߼����֧�������������
//#define	ZM_ACCOUNT_CONNMAXCOUNT	32
