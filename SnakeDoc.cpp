// SNAKEDoc.cpp : implementation of the CSNAKEDoc class
//

#include "stdafx.h"
#include "SNAKE.h"

#include "SNAKEDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSNAKEDoc

IMPLEMENT_DYNCREATE(CSNAKEDoc, CDocument)

BEGIN_MESSAGE_MAP(CSNAKEDoc, CDocument)
	//{{AFX_MSG_MAP(CSNAKEDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSNAKEDoc construction/destruction

CSNAKEDoc::CSNAKEDoc()
{
	// TODO: add one-time construction code here

}

CSNAKEDoc::~CSNAKEDoc()
{
}

BOOL CSNAKEDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSNAKEDoc serialization

void CSNAKEDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CSNAKEDoc diagnostics

#ifdef _DEBUG
void CSNAKEDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSNAKEDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSNAKEDoc commands
