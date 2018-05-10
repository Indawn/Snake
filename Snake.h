// SNAKE.h : main header file for the SNAKE application
//

#if !defined(AFX_SNAKE_H__7C0E7530_9B24_41DB_9F25_0CDAD722CCB2__INCLUDED_)
#define AFX_SNAKE_H__7C0E7530_9B24_41DB_9F25_0CDAD722CCB2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CSNAKEApp:
// See SNAKE.cpp for the implementation of this class
//

class CSNAKEApp : public CWinApp
{
public:
	CSNAKEApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSNAKEApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CSNAKEApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SNAKE_H__7C0E7530_9B24_41DB_9F25_0CDAD722CCB2__INCLUDED_)
