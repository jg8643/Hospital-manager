// CEmpAddDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "SW_Test.h"
#include "CEmpAddDlg.h"
#include "afxdialogex.h"
#include "Setting.h"
#include "SW_TestDlg.h"
#include "Employee.h"
// CEmpAddDlg 대화 상자

IMPLEMENT_DYNAMIC(CEmpAddDlg, CDialogEx)

CEmpAddDlg::CEmpAddDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG7, pParent)
{
	myswdlg = (CSWTestDlg*)::AfxGetMainWnd();
	set = myswdlg->set;
}

CEmpAddDlg::~CEmpAddDlg()
{
}

void CEmpAddDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_combo);
}


BEGIN_MESSAGE_MAP(CEmpAddDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON12, &CEmpAddDlg::OnBnClickedButton12)
END_MESSAGE_MAP()


// CEmpAddDlg 메시지 처리기


BOOL CEmpAddDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	m_combo.AddString(_T("의사"));
	m_combo.AddString(_T("간호사"));
	m_combo.AddString(_T("기술스태프"));

	m_combo.SetCurSel(0);
	int idc_edit[9] = { IDC_EDIT1,IDC_EDIT2,IDC_EDIT3,IDC_EDIT4,IDC_EDIT5,IDC_EDIT6,IDC_EDIT7,IDC_EDIT8,IDC_EDIT9 };
	for (int i = 0; i < 9; i++) {
		pedit[i] = (CEdit*)GetDlgItem(idc_edit[i]);
	}

	CString str;
	int last = set->emp->ecount -1 ;
	int num = _ttoi(set->emp->empdata[last]->e_data[1]) + 1;
	str.Format(_T("%d"),num);

	pedit[0]->SetWindowText(str);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CEmpAddDlg::OnBnClickedButton12()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	for (int i = 1; i < 9; i++) {
		pedit[i]->GetWindowText(str);
		if (str == L"") {
			AfxMessageBox(L"비었어요");
			break;
		}
	}
}
