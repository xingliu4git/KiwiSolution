#pragma once
#include "afxcmn.h"



// CPersonalSummary 窗体视图

class CPersonalSummary : public CFormView
{
	DECLARE_DYNCREATE(CPersonalSummary)

protected:
	CPersonalSummary();           // 动态创建所使用的受保护的构造函数
	virtual ~CPersonalSummary();

public:
	enum { IDD = IDD_PERSONAL_SUMMARY };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_strHeader;
	CString m_strBox1;
	CString m_strBox2;
	CString m_strCurrentFile;
	CString m_strCurrentFolder;
	CBitmap m_bmpClose;
protected:
	
public:
	CXTPListCtrl m_listSummary1;
	CXTPListCtrl m_listSummary2;
	virtual void OnInitialUpdate();
	afx_msg void OnClickedButtonClose();
};


