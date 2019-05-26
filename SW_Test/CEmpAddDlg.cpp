// CEmpAddDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "SW_Test.h"
#include "CEmpAddDlg.h"
#include "afxdialogex.h"
#include "Setting.h"
#include "SW_TestDlg.h"
#include "Employee.h"
#include "CEmployeeDlg.h"
// CEmpAddDlg 대화 상자
IMPLEMENT_DYNAMIC(CEmpAddDlg, CDialogEx)
static CFont m_font;

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
	ON_BN_CLICKED(IDOK, &CEmpAddDlg::OnBnClickedOk)
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


// CEmpAddDlg 메시지 처리기


BOOL CEmpAddDlg::OnInitDialog()
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
	m_combo.AddString(_T("의사"));
	m_combo.AddString(_T("간호사"));
	m_combo.AddString(_T("기술스태프"));

	m_combo.SetCurSel(0);
	int idc_button[11] = { IDC_BUTTON1,IDC_BUTTON2,IDC_BUTTON3,IDC_BUTTON4,IDC_BUTTON5,IDC_BUTTON6,IDC_BUTTON7,IDC_BUTTON8, IDC_BUTTON10, IDC_BUTTON11, IDC_BUTTON12 };
	int idc_edit[9] = { IDC_EDIT1,IDC_EDIT2,IDC_EDIT3,IDC_EDIT4,IDC_EDIT5,IDC_EDIT6,IDC_EDIT7,IDC_EDIT8,IDC_EDIT9 };
	for (int i = 0; i < 9; i++) {
		pedit[i] = (CEdit*)GetDlgItem(idc_edit[i]);
	}
	for (int i = 0; i < 11; i++) {
		GetDlgItem(idc_button[i])->SetFont(&m_font);
	}
	for (int i = 0; i < 9; i++) {
		GetDlgItem(idc_edit[i])->SetFont(&m_font);
	}
	GetDlgItem(IDC_COMBO1)->SetFont(&m_font);
	m_font.Detach();
	CString str;
	int last = set->emp->ecount -1 ;
	int num = _ttoi(set->emp->empdata[last]->e_data[1]) + 1;
	str.Format(_T("%d"),num);

	pedit[0]->SetWindowText(str);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

// 등록 버튼
void CEmpAddDlg::OnBnClickedButton12()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str, combo;
	CString temp[10];
	int blank = 0;
	m_combo.GetLBText(m_combo.GetCurSel(), combo);
	temp[0] = combo;

	for (int i = 0; i < 9; i++) {
		pedit[i]->GetWindowText(str);
		// Edit이 비었을 때
		if (str == L"") {
			AfxMessageBox(L"비었습니다.");
			blank = 1;
			break;
		}
		else {
			temp[i+1] = str;
		}
	}
	if (blank == 0) {
		if (combo == L"의사")
			set->emp->dcount++;
		else if (combo == L"간호사")
			set->emp->ncount++;
		else
			set->emp->scount++;
		set->emp->empdata[set->emp->ecount++] = new edata(temp);
		set->emp->WriteEmpFile();
		AfxMessageBox(L"추가되었습니다.");
		CDialogEx::OnOK();
	}
}

// 확인
void CEmpAddDlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnOK();
}

// 배경
BOOL CEmpAddDlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CRect rt;
	GetClientRect(rt);
	pDC->FillSolidRect(rt, RGB(255, 255, 255));
	return TRUE;
}
