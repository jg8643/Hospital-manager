// CEmployeeDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "SW_Test.h"
#include "CEmployeeDlg.h"
#include "afxdialogex.h"
#include "Setting.h"
#include "SW_TestDlg.h"
#include "Employee.h"
#include "CEmpTab1Dlg.h"
#include "CEmpTab2Dlg.h"
#include "CEmpTab3Dlg.h"
#include "CEmpAddDlg.h"
// CEmployeeDlg 대화 상자

IMPLEMENT_DYNAMIC(CEmployeeDlg, CDialogEx)
CFont m_font1, m_font2, m_font3;
CEmployeeDlg::CEmployeeDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{
	myswdlg = (CSWTestDlg*)::AfxGetMainWnd();
	set = myswdlg->set;

}

CEmployeeDlg::~CEmployeeDlg()
{
}

void CEmployeeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_tabctrl);
}


BEGIN_MESSAGE_MAP(CEmployeeDlg, CDialogEx)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CEmployeeDlg::OnTcnSelchangeTab1)
	ON_BN_CLICKED(IDC_BUTTON10, &CEmployeeDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &CEmployeeDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON12, &CEmployeeDlg::OnBnClickedButton12)
	ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDOK, &CEmployeeDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CEmployeeDlg 메시지 처리기


BOOL CEmployeeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CString str;
	HICON hIcon = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDR_MAINFRAME)); //icon 변경
	this->SetIcon(hIcon, FALSE);

	int idc_button[12] = { IDC_BUTTON1,IDC_BUTTON2,IDC_BUTTON3,IDC_BUTTON4,IDC_BUTTON5,IDC_BUTTON6,IDC_BUTTON7,IDC_BUTTON8,IDC_BUTTON9, IDC_BUTTON10, IDC_BUTTON11, IDC_BUTTON12 };
	int idc_edit[9] = { IDC_EDIT1, IDC_EDIT2, IDC_EDIT3, IDC_EDIT4, IDC_EDIT5, IDC_EDIT6, IDC_EDIT7, IDC_EDIT8,IDC_EDIT9 };
	// 폰트 설정
	m_font1.CreateFont(40, 15,            // 세로,가로 크기
		0, 0,
		FW_HEAVY,    //Font 굵기
		FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, OUT_DEFAULT_PRECIS,
		DEFAULT_QUALITY, DEFAULT_PITCH,
		L"맑은 고딕");
	m_font2.CreateFont(30, 10,            // 세로,가로 크기
		0, 0,
		FW_HEAVY,    //Font 굵기
		FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, OUT_DEFAULT_PRECIS,
		DEFAULT_QUALITY, DEFAULT_PITCH,
		L"맑은 고딕");
	m_font3.CreateFont(20, 8,            // 세로,가로 크기
		0, 0,
		FW_HEAVY,    //Font 굵기
		FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, OUT_DEFAULT_PRECIS,
		DEFAULT_QUALITY, DEFAULT_PITCH,
		L"맑은 고딕");

	GetDlgItem(IDC_STATIC)->SetFont(&m_font1);
	GetDlgItem(IDC_STATIC1)->SetFont(&m_font1);
	GetDlgItem(IDC_TAB1)->SetFont(&m_font3);

	for (int i = 0; i < 9; i++) {
		GetDlgItem(idc_button[i])->SetFont(&m_font2);
		GetDlgItem(idc_edit[i])->SetFont(&m_font2);
	}
	for (int i = 9; i < 12; i++) {
		GetDlgItem(idc_button[i])->SetFont(&m_font2);
	}
	m_font1.Detach();
	m_font2.Detach();
	m_font3.Detach();
	for (int i = 0; i < 9; i++) {
		pedit[i] = (CEdit*)GetDlgItem(idc_edit[i]);
	}
	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	
	//탭 컨트롤 셋팅
	m_tabctrl.InsertItem(0, _T("의사"));
	m_tabctrl.InsertItem(1, _T("간호사"));
	m_tabctrl.InsertItem(2, _T("기술스태프"));
	m_tabctrl.SetCurSel(0);

	CRect rect;
	m_tabctrl.GetWindowRect(&rect);
	cet1 = new CEmpTab1Dlg(this);
	cet1->Create(IDD_DIALOG2, &m_tabctrl);
	cet1->MoveWindow(0, 25, rect.Width(), rect.Height());
	cet1->ShowWindow(SW_SHOW);

	cet2 = new CEmpTab2Dlg(this);
	cet2->Create(IDD_DIALOG3, &m_tabctrl);
	cet2->MoveWindow(0, 25, rect.Width(), rect.Height());
	cet2->ShowWindow(SW_HIDE);

	cet3 = new CEmpTab3Dlg(this);
	cet3->Create(IDD_DIALOG4, &m_tabctrl);
	cet3->MoveWindow(0, 25, rect.Width(), rect.Height());
	cet3->ShowWindow(SW_HIDE);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

// 직원 더블 클릭 시 정보 셋팅
void CEmployeeDlg::SetInformation(int idx)
{
	for (int i = 0; i < 9; i++) {
		pedit[i]->SetWindowText(set->emp->empdata[idx]->e_data[i + 1]);
	}
	GetDlgItem(IDC_BUTTON12)->EnableWindow(TRUE);
}
// 업데이트
void CEmployeeDlg::Update()
{
	cet1->Update();
	cet2->Update();
	cet3->Update();
}
// 탭 컨트롤 처리
void CEmployeeDlg::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int sel = m_tabctrl.GetCurSel();

	switch (sel) {
	case 0:
		cet1->ShowWindow(SW_SHOW);
		cet2->ShowWindow(SW_HIDE);
		cet3->ShowWindow(SW_HIDE);
		break;

	case 1:
		cet1->ShowWindow(SW_HIDE);
		cet2->ShowWindow(SW_SHOW);
		cet3->ShowWindow(SW_HIDE);
		break;
	case 2:
		cet1->ShowWindow(SW_HIDE);
		cet2->ShowWindow(SW_HIDE);
		cet3->ShowWindow(SW_SHOW);
		break;
	}
	*pResult = 0;
}

// 직원 등록 다이얼로그 생성
void CEmployeeDlg::OnBnClickedButton10()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CEmpAddDlg cempadddlg;
	cempadddlg.DoModal();
	cempadddlg.DestroyWindow();
	Update();
}

// 삭제
void CEmployeeDlg::OnBnClickedButton11()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (cet1->mark >= 0)
		cet1->Delete();
	else if (cet2->mark >= 0)
		cet2->Delete();
	else if (cet3->mark >= 0)
		cet3->Delete();
	else
		AfxMessageBox(L"선택해주세요");
	Update();
}

// 수정
void CEmployeeDlg::OnBnClickedButton12()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	pedit[0]->GetWindowText(str);
	for (int i = 0; i < set->emp->ecount; i++) {
		if (set->emp->empdata[i]->e_data[1] == str) {
			for (int j = 1; j < 9; j++) {
				pedit[j]->GetWindowText(set->emp->empdata[i]->e_data[j+1]);
			}
		}
	}
	set->emp->WriteEmpFile();
	AfxMessageBox(L"수정되었습니다.");
	Update();
}

// 배경
BOOL CEmployeeDlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CRect rt;
	GetClientRect(rt);
	pDC->FillSolidRect(rt, RGB(255, 255, 255));
	return TRUE;
	//return CDialogEx::OnEraseBkgnd(pDC);
}

// 스태틱 배경색
HBRUSH CEmployeeDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  여기서 DC의 특성을 변경합니다.
	if (nCtlColor == CTLCOLOR_STATIC){
		pDC->SetBkColor(RGB(255, 255, 255));
	}
	// TODO:  기본값이 적당하지 않으면 다른 브러시를 반환합니다.
	return hbr;
}


void CEmployeeDlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnOK();
}
