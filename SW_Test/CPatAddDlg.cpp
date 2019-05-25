// CPatAddDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "SW_Test.h"
#include "CPatAddDlg.h"
#include "afxdialogex.h"
#include "SW_TestDlg.h"
#include "Setting.h"
#include "Patient.h"
// CPatAddDlg 대화 상자

IMPLEMENT_DYNAMIC(CPatAddDlg, CDialogEx)
static CFont m_font;
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
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


// CPatAddDlg 메시지 처리기


BOOL CPatAddDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	HICON hIcon = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDR_MAINFRAME)); //icon 변경
	this->SetIcon(hIcon, FALSE);
	m_font.CreateFont(20, 8,            // 세로,가로 크기
		0, 0,
		FW_HEAVY,    //Font 굵기
		FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, OUT_DEFAULT_PRECIS,
		DEFAULT_QUALITY, DEFAULT_PITCH,
		L"맑은 고딕");
	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	int idc_button[8] = { IDC_BUTTON1,IDC_BUTTON2,IDC_BUTTON3,IDC_BUTTON4,IDC_BUTTON5,IDC_BUTTON6,IDC_BUTTON7,IDC_BUTTON8 };
	int idc_edit[7] = { IDC_EDIT1,IDC_EDIT2,IDC_EDIT3,IDC_EDIT4,IDC_EDIT5,IDC_EDIT6,IDC_EDIT7 };
	for (int i = 0; i < 7; i++) {
		pedit[i] = (CEdit*)GetDlgItem(idc_edit[i]);
	}
	for (int i = 0; i < 8; i++) {
		GetDlgItem(idc_button[i])->SetFont(&m_font);
	}
	for (int i = 0; i < 7; i++) {
		GetDlgItem(idc_edit[i])->SetFont(&m_font);
	}
	m_font.Detach();
	CString str;
	int last = set->pat->pcount - 1;
	int num = _ttoi(set->pat->patdata[last]->p_data[0]) + 1;
	str.Format(_T("%d"), num);

	pedit[0]->SetWindowText(str);
	
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


	void CPatAddDlg::OnBnClickedButton8()
	{
		// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
		CString str;
		CString temp[10];
		int blank = 0;

		for (int i = 0; i < 7; i++) {
			pedit[i]->GetWindowText(str);
			if (str == L"") {
				AfxMessageBox(L"비었어요");
				blank = 1;
				break;
			}
			else {
				temp[i] = str;
			}
		}
		if (blank == 0) {
			set->pat->patdata[set->pat->pcount++] = new pdata(temp);
			set->pat->WritePatFile();
			AfxMessageBox(L"추가되었습니다.");
			CDialogEx::OnOK();
		}
	}


	BOOL CPatAddDlg::OnEraseBkgnd(CDC* pDC)
	{
		// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
		CRect rt;
		GetClientRect(rt);
		pDC->FillSolidRect(rt, RGB(255, 255, 255));
		return TRUE;
	}
