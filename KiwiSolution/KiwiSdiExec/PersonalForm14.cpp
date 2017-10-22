// PersonalForm14.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "KiwiSdiExec.h"
#include "PersonalForm14.h"
#include <sstream>
using namespace std;
#include "Utility.h"
#include "SQLiteHelper.h"
#include "msword/msword.h"
#include "MainFrm.h"

// CPersonalForm14

IMPLEMENT_DYNCREATE(CPersonalForm14, CFormView)

CPersonalForm14::CPersonalForm14()
: CFormView(CPersonalForm14::IDD)
, m_Radio13_0(0)
{
	LOGFONT lf; memset(&lf, 0, sizeof(LOGFONT)); lf.lfHeight = 25;  _tcsncpy_s(lf.lfFaceName, LF_FACESIZE, _T("������"), 3); lf.lfWeight = 400;
	m_fontEdit.CreateFontIndirect(&lf);
}

CPersonalForm14::~CPersonalForm14()
{
	m_fontEdit.DeleteObject();
}

void CPersonalForm14::SetCurrentFile(CString filePath)
{
	m_strCurrentFolder = filePath.Left(filePath.Find(_T("/"), 0));
	m_strCurrentFile = filePath.Right(filePath.GetLength() - filePath.Find(_T("/"), 0) - 1);
}

void CPersonalForm14::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RADIO15, m_Radio13_0);
}

BEGIN_MESSAGE_MAP(CPersonalForm14, CFormView)
	ON_BN_CLICKED(IDC_CMD_SAVE_FORM2, &CPersonalForm14::OnBnClickedCmdSaveForm2)
	ON_BN_CLICKED(IDC_CMD_PRINT_FORM2, &CPersonalForm14::OnBnClickedCmdPrintForm2)
	ON_BN_CLICKED(IDC_BUTTON_CLOSE_FORM4, &CPersonalForm14::OnBnClickedButtonCloseForm4)
END_MESSAGE_MAP()


// CPersonalForm14 ���

#ifdef _DEBUG
void CPersonalForm14::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CPersonalForm14::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CPersonalForm14 ��Ϣ��������


void CPersonalForm14::OnBnClickedCmdSaveForm2()
{
	UpdateData();
	// TODO:  �ڴ����ӿؼ�֪ͨ�����������
	stringstream ss;
	ss << "select file_id from orgnization_file where file_name='" << CW2A(m_strCurrentFile.GetBuffer(), CP_UTF8) << "' and folder_name='" <<
		CW2A(m_strCurrentFolder.GetBuffer(), CP_UTF8) << "';";
	TRACE(CA2W(ss.str().c_str(), CP_UTF8));

	CSQLiteHelper *help = new CSQLiteHelper();
	help->openDB("kiwi.db3");
	int row, col;
	char *eee = "i"; char **result = &eee;
	char **re = help->rawQuery(ss.str().c_str(), &row, &col, result);
	int file_id = atoi(re[1 * col + 0]);
	ss.str(""); ss.clear();

	ss << "select count(*) from file_form_flags where file_id=" << file_id << ";";
	re = help->rawQuery(ss.str().c_str(), &row, &col, result);
	int hasRecord = atoi(re[1 * col + 0]);
	if (!hasRecord) {
		ss << "insert into file_form_flags(file_id) values(" << file_id << ")";
		help->execSQL(ss.str().c_str());
		ss.str(""); ss.clear();
	}

	CString strText;
#pragma region FillForm9_1
FillForm9 :

#pragma endregion

#pragma region FillForm14
FillForm14 :

#pragma endregion

#pragma region FillForm14
FillForm14 :

#pragma endregion


FillComplete :
	help->closeDB(); delete help;
			 ss.str("");  ss.clear();
			 GetDlgItem(IDC_CMD_SAVE_FORM)->EnableWindow(FALSE);
}


void CPersonalForm14::OnBnClickedCmdPrintForm2()
{
	// TODO:  �ڴ����ӿؼ�֪ͨ�����������
}


void CPersonalForm14::OnBnClickedButtonCloseForm4()
{
	// TODO:  �ڴ����ӿؼ�֪ͨ�����������
	CMainFrame* pWnd = (CMainFrame*)AfxGetApp()->m_pMainWnd;

	::PostMessage(pWnd->m_hWnd, WM_SHOW_DEFAULT_SUMMARY, 0l, LPARAM(&m_strCurrentFolder));
}