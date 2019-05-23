// CPatAddDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "SW_Test.h"
#include "CPatAddDlg.h"
#include "afxdialogex.h"
#include "SW_TestDlg.h"
#include "Setting.h"

// CPatAddDlg 대화 상자

IMPLEMENT_DYNAMIC(CPatAddDlg, CDialogEx)

CPatAddDlg::CPatAddDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG8, pParent)
{
	myswdlg = (CSWTestDlg*)::AfxGetMainWnd();
	set = myswdlg->set;
}

CPatAddDlg::~CPatAddDlg()
{
}

void CPatAddDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPatAddDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON8, &CPatAddDlg::OnBnClickedButton8)
END_MESSAGE_MAP()


// CPatAddDlg 메시지 처리기


BOOL CPatAddDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	int idc_edit[7] = { IDC_EDIT1,IDC_EDIT2,IDC_EDIT3,IDC_EDIT4,IDC_EDIT5,IDC_EDIT6,IDC_EDIT7 };
	for (int i = 0; i < 7; i++) {
		pedit[i] = (CEdit*)GetDlgItem(idc_edit[i]);
	}

	
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


	void CPatAddDlg::OnBnClickedButton8()
	{
		// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
		CString str;
		for (int i = 0; i < 7; i++) {
			pedit[i]->GetWindowText(str);
			if (str == L"") {
				AfxMessageBox(L"비었어요");
				break;
			}
		}
	}
