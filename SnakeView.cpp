// SNAKEView.cpp : implementation of the CSNAKEView class
//

#include "stdafx.h"
#include "SNAKE.h"

#include "SNAKEDoc.h"
#include "SNAKEView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////

struct Snake
{
       int x,y;
       int len;
       int direct;
}Snake[50];
struct Food
{
       int x;
       int y;
       int isfood;
}Food;


/////////////////////////////////////////////////////////////////////////////




/////////////////////////////////////////////////////////////////////////////
// CSNAKEView

IMPLEMENT_DYNCREATE(CSNAKEView, CView)

BEGIN_MESSAGE_MAP(CSNAKEView, CView)
	//{{AFX_MSG_MAP(CSNAKEView)
	ON_WM_KEYDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_TIMER()
	ON_COMMAND(ID_GAME_START, OnGameStart)
	ON_COMMAND(ID_GAME_PAUSE, OnGamePause)
	ON_COMMAND(ID_GAME_CONTINUE, OnGameContinue)
	ON_COMMAND(ID_GAME_EXIT, OnGameExit)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSNAKEView construction/destruction

CSNAKEView::CSNAKEView()
{
	// TODO: add construction code here

}

CSNAKEView::~CSNAKEView()
{
}

BOOL CSNAKEView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSNAKEView drawing

void CSNAKEView::OnDraw(CDC* pDC)
{
	CSNAKEDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CBrush backBrush(RGB(0,0,0));
	CBrush* pOldBrush = pDC->SelectObject(&backBrush);
	CRect rect;
	pDC->GetClipBox(&rect);
	pDC->PatBlt(rect.left, rect.top, rect.Width(), rect.Height(),PATCOPY);
	pDC->SelectObject(pOldBrush);
 
	pDC->Rectangle(19,19,501,501);
	Oninit();
}

/////////////////////////////////////////////////////////////////////////////
// CSNAKEView printing

BOOL CSNAKEView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSNAKEView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSNAKEView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CSNAKEView diagnostics

#ifdef _DEBUG
void CSNAKEView::AssertValid() const
{
	CView::AssertValid();
}

void CSNAKEView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSNAKEDoc* CSNAKEView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSNAKEDoc)));
	return (CSNAKEDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSNAKEView message handlers

void CSNAKEView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	switch(nChar)
	{
		case VK_UP:if(Snake[0].direct!=2)Snake[0].direct=1;		break; 
		case VK_DOWN:if(Snake[0].direct!=1)Snake[0].direct=2;	break;
		case VK_LEFT:if(Snake[0].direct!=4)Snake[0].direct=3;	break;  
		case VK_RIGHT:if(Snake[0].direct!=3)Snake[0].direct=4;	break;
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);	//??????????????????
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CSNAKEView::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CString str;
	str.Format("%d,%d",point.x,point.y);
	AfxMessageBox(str);
	CView::OnRButtonDown(nFlags, point);	//??????????????????
	CView::OnRButtonDown(nFlags, point);
	CView::OnRButtonDown(nFlags, point);
}

void CSNAKEView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	CDC *pDC=GetDC();
	CString soure;
 
	if(Snake[0].len==2)SetTimer(1,370,NULL);
	if(Snake[0].len==3)SetTimer(1,270,NULL);
	if(Snake[0].len==6)SetTimer(1,200,NULL);
	if(Snake[0].len==9)SetTimer(1,100,NULL);
 
	soure.Format("得分:%d!",(Snake[0].len-3)*10); 
	//撞界判断
	if(Snake[0].x*20<=37||Snake[0].y*20<=37||Snake[0].x*20>=462||Snake[0].y*20>=462)
	{
	KillTimer(1);
	AfxMessageBox(soure);
	// s=0;
	}
    //蛇身相撞判断
	if(Snake[0].len>3)
		for(int sn=Snake[0].len-1;sn>0;sn--)
		{
		if(Snake[0].x*20==Snake[sn].x*20&&Snake[0].y*20==Snake[sn].y*20)
		{
			KillTimer(1);
			AfxMessageBox(soure);
	//  s=0;
		}
	}
  ///////////////////////////////////////////////////////////////////////////
  pDC->SelectStockObject(WHITE_PEN);
  pDC->Rectangle(Snake[Snake[0].len-1].x*20,Snake[Snake[0].len-1].y*20,(Snake[Snake[0].len-1].x+1)*20,(Snake[Snake[0].len-1].y+1)*20);
  for(int i=Snake[0].len-1;i>0;i--)
  {
   Snake[i].x=Snake[i-1].x;
   Snake[i].y=Snake[i-1].y;
  }
  //行走方向判断
  if(Snake[0].direct==1)Snake[0].y--;
  if(Snake[0].direct==2)Snake[0].y++;
  if(Snake[0].direct==3)Snake[0].x--;
  if(Snake[0].direct==4)Snake[0].x++;
  pDC->SelectStockObject(BLACK_PEN);
  
  CBrush DrawBrush=(RGB(100,100,100));
  CBrush *Drawbrush=pDC->SelectObject(&DrawBrush);
  pDC->Rectangle(Snake[0].x*20,Snake[0].y*20,(Snake[0].x+1)*20,(Snake[0].y+1)*20);
  pDC->SelectObject(DrawBrush);

  //判断吃豆的条件,撞到就吃
  if(Snake[0].x*20==Food.x*20&&Snake[0].y*20==Food.y*20)
  {
   Snake[0].len++;
   Food.isfood=1;
   Snake[Snake[0].len-1].x=Snake[Snake[0].len-2].x;
   Snake[Snake[0].len-1].y=Snake[Snake[0].len-2].y;
  }
  //如果食物被吃了 就生成
  if(Food.isfood==1)
  {
   srand((unsigned)time(NULL));
   do
   {
    for(int isfo=Snake[0].len-1;isfo>=0;isfo--)
     if(Snake[0].x*20==Snake[isfo].x*20&&Snake[0].y*20==Snake[isfo].y*20)
     {
      Food.x=rand()%25;
      Food.y=rand()%25;
     }
   }
   while(Food.x*20<70||Food.y*20<70||Food.x*20>430||Food.y*20>430);
   pDC->Rectangle(Food.x*20,Food.y*20,(Food.x+1)*20,(Food.y+1)*20);
   Food.isfood=0;
  }
 

	CView::OnTimer(nIDEvent);
}

void CSNAKEView::OnInitialUpdate() 
{
	CView::OnInitialUpdate();
	Snake[0].x=10;
	Snake[0].y=10;
	Snake[1].x=11;
	Snake[1].y=10;
	Snake[2].x=12;
	Snake[2].y=10;
	Snake[0].direct=3;
	Snake[0].len=3;
	Food.isfood=1;

	// TODO: Add your specialized code here and/or call the base class
	
}

void CSNAKEView::OnGameStart() 
{
	// TODO: Add your command handler code here	
	AfxMessageBox("1秒后开始游戏!");
	SetTimer(1,1000,NULL);
}

void CSNAKEView::OnGamePause() 
{
	// TODO: Add your command handler code here
	KillTimer(1);
	AfxMessageBox("暂停游戏...");
}

void CSNAKEView::OnGameContinue() 
{
	// TODO: Add your command handler code here
	SetTimer(1,10,NULL);
}

void CSNAKEView::OnGameExit() 
{
	// TODO: Add your command handler code here
	AfxMessageBox("退出游戏...");
	exit (0);
}

//DEL CSNAKEView::Oninit()
//DEL {
//DEL 
//DEL }

//DEL int CSNAKEView::Oninit()
//DEL {
//DEL 
//DEL }

void CSNAKEView::Oninit()
{
	CDC *pDC=GetDC();
	CBrush DrawBrush=(RGB(100,100,100));
	CBrush *Drawbrush=pDC->SelectObject(&DrawBrush);
	for(int i=0;i<=Snake[0].len-1;i++)
		pDC->Rectangle(Snake[i].x*20,Snake[i].y*20,(Snake[i].x+1)*20,(Snake[i].y+1)*20);
	pDC->SelectObject(DrawBrush);

}
