
// drawDemo0Dlg.h: 头文件
//

#pragma once


// CdrawDemo0Dlg 对话框
class CdrawDemo0Dlg : public CDialog
{
// 构造
public:
	CdrawDemo0Dlg(CWnd* pParent = NULL);	// 标准构造函数
	CWnd *pWnd;		//获取空间窗口类指针
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DRAWDEMO0_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
};
