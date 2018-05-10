// SNAKEDoc.h : interface of the CSNAKEDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SNAKEDOC_H__660BB69E_46BD_4194_8E76_F12B126A394A__INCLUDED_)
#define AFX_SNAKEDOC_H__660BB69E_46BD_4194_8E76_F12B126A394A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSNAKEDoc : public CDocument
{
protected: // create from serialization only
	CSNAKEDoc();
	DECLARE_DYNCREATE(CSNAKEDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSNAKEDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSNAKEDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSNAKEDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SNAKEDOC_H__660BB69E_46BD_4194_8E76_F12B126A394A__INCLUDED_)
