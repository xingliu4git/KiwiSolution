#pragma once



// CPersonalForm22 窗体视图

class CPersonalForm22 : public CFormView
{
	DECLARE_DYNCREATE(CPersonalForm22)

protected:
	CPersonalForm22();           // 动态创建所使用的受保护的构造函数
	virtual ~CPersonalForm22();

public:
	enum { IDD = IDD_PERSONAL_FORM22 };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

public:
	CString m_strCurrentFile;
	CString m_strCurrentFolder;
	void SetCurrentFile(CString filePath);
	CFont m_fontEdit;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCmdSaveForm();
	afx_msg void OnBnClickedCmdPrintForm();
	afx_msg void OnBnClickedButtonCloseForm3();
	virtual void OnInitialUpdate();
};


