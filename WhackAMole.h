
// WhackAMole.h : main header file for the WhackAMole application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CWhackAMoleApp:
// See WhackAMole.cpp for the implementation of this class
//

class CWhackAMoleApp : public CWinAppEx
{
public:
	CWhackAMoleApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CWhackAMoleApp theApp;
