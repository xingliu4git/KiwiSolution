#pragma once



// CPersonalForm13 窗体视图

class CPersonalForm13 : public CFormView
{
	DECLARE_DYNCREATE(CPersonalForm13)

protected:
	CPersonalForm13();           // 动态创建所使用的受保护的构造函数
	virtual ~CPersonalForm13();

public:
	enum { IDD = IDD_PERSONAL_FORM13 };
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
	int m_Radio12_3_0;
};


