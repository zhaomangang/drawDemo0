
// drawDemo0Dlg.cpp: 实现文件
//

#include <math.h>

#include "stdafx.h"
#include "drawDemo0.h"
#include "drawDemo0Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CdrawDemo0Dlg 对话框



CdrawDemo0Dlg::CdrawDemo0Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DRAWDEMO0_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CdrawDemo0Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CdrawDemo0Dlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CdrawDemo0Dlg 消息处理程序

BOOL CdrawDemo0Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	pWnd = GetDlgItem(IDC_MYSTATIC);
	ShowWindow(SW_SHOWMAXIMIZED);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。
//CPoi

void CdrawDemo0Dlg::OnPaint()
{
	//mypaint
	CString str;
	int i, j;
	//强制更新
	pWnd->Invalidate();
	//更新窗口
	pWnd->UpdateWindow();
	CDC *pDC = pWnd->GetDC();	//获取控件的CDC指针
	pDC->Rectangle(0, 0, 1300, 1000);	//画一个矩形框
	pDC->Rectangle(1320, 0, 1900, 500);	//画一个矩形框
	pDC->FillSolidRect(0, 0, 1300, 1000,RGB(0,0,0));
	CPen *pPenRed = new CPen(); //创建画笔对象
	pPenRed->CreatePen(PS_SOLID, 2, RGB(255, 255, 0)); //黄色画笔
	CPen *pPen = NULL;
	//选中当前红色画笔,并保存以前的画笔
	CGdiObject *pOldPen = pDC->SelectObject(pPenRed);
	pDC->MoveTo(500,500); //绘制坐标轴
	pDC->LineTo(500,100); //z轴
	pDC->MoveTo(500,500);
	pDC->LineTo(1500,500); //水平轴
	pDC->MoveTo(500,500);
	pDC->LineTo(300,700);//y
	
	//写X轴刻度值
	for (i = 0; i <= 10; i++)
	{
		str.Format(_T("%d"),i);
		pDC->TextOut(500 + 60 * i, 515, str);
		//绘制X轴刻度
		pDC->MoveTo(i*60+500, 500);
		pDC->LineTo(i*60+500, 485);
	}
	//写Y轴刻度值
	for (i = 1; i <= 10; i++)
	{
		str.Format(_T("%d"), i);
		pDC->TextOut(2, 360 - 30 * i - 5, str);
		//绘制Y轴刻度
		pDC->MoveTo(25, 360 - 30 * i);
		pDC->LineTo(20, 360 - 30 * i);
	}
	//绘制X箭头
	pDC->MoveTo(1490, 490);
	pDC->LineTo(1500, 500);
	pDC->LineTo(1490, 510);
	//绘制Y箭头 
	pDC->MoveTo(17, 30);
	pDC->LineTo(20, 20);                   //绘制左边箭头
	pDC->LineTo(23, 30); //绘制右边箭头
	CPen *pPenBlue = new CPen(); //创建画笔对象
	pPenBlue->CreatePen(PS_SOLID, 1, RGB(0, 0, 255)); //蓝色画笔
	CPen *pPenred = new CPen(); //创建画笔对象
	pPenred->CreatePen(PS_SOLID, 3, RGB(255, 0, 0)); //蓝色画笔
//	CPen *pPen = NULL;
	//选中当前红色画笔,并保存以前的画笔
	CGdiObject *pOldPen_1 = pDC->SelectObject(pPenBlue);
	pDC->Arc(1000, 700, 0, 300, 800, 400, 500, 200);
	pDC->Arc(900, 700, 0, 300, 830, 400, 530, 200);
	pDC->Arc(830, 350, 900, 370, 830, 400, 900, 350);
	
	pDC->AngleArc(500,1000, 700, 45, 90);
	
	pDC->Ellipse(1400, 100, 1700, 300);



	pOldPen_1 = pDC->SelectObject(pPenred);
	pDC->Rectangle(1500, 150, 1530, 170);
	pDC->FillSolidRect(1500, 150, 30, 20, RGB(0, 0, 0));
	double posx = 0;
	double posy = 0.1;
	

	//恢复以前的画笔
	pDC->SelectObject(pOldPen);
	delete pPenRed;
	if (pPen != NULL)
		delete pPen;
	ReleaseDC(pDC);



	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		//SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		//// 使图标在工作区矩形中居中
		//int cxIcon = GetSystemMetrics(SM_CXICON);
		//int cyIcon = GetSystemMetrics(SM_CYICON);
		//CRect rect;
		//GetClientRect(&rect);
		//int x = (rect.Width() - cxIcon + 1) / 2;
		//int y = (rect.Height() - cyIcon + 1) / 2;

		//// 绘制图标
		//dc.DrawIcon(x, y, m_hIcon);
		
		
		
	}
	else
	{
		CDialog::OnPaint();
	}


}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CdrawDemo0Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

