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
END_MESSAGE_MAP()


// CEmployeeDlg 메시지 처리기


BOOL CEmployeeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CString str;

	int idc_edit[9] = { IDC_EDIT1, IDC_EDIT2, IDC_EDIT3, IDC_EDIT4, IDC_EDIT5, IDC_EDIT6, IDC_EDIT7, IDC_EDIT8,IDC_EDIT9 };
	for (int i = 0; i < 9; i++) {
		pedit[i] = (CEdit*)GetDlgItem(idc_edit[i]);
	}
	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	
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

CEmployeeDlg::CEmployeeDlg(CEmployeeDlg * cempdlg)
{

}


void CEmployeeDlg::SetInformation(int idx)
{
	for (int i = 0; i < 9; i++) {
		pedit[i]->SetWindowText(set->emp->empdata[idx]->e_data[i + 1]);
	}
}

void CEmployeeDlg::Update()
{
	cet1->Update();
	cet2->Update();
	cet3->Update();
}

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


void CEmployeeDlg::OnBnClickedButton10()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CEmpAddDlg cempadddlg;
	cempadddlg.DoModal();
	cempadddlg.DestroyWindow();
	Update();
}
