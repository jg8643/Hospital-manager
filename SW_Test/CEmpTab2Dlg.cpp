// CEmpTab2Dlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "SW_Test.h"
#include "CEmpTab2Dlg.h"
#include "afxdialogex.h"
#include "Setting.h"
#include "SW_TestDlg.h"
#include "Employee.h"
#include "CEmployeeDlg.h"
// CEmpTab2Dlg 대화 상자

IMPLEMENT_DYNAMIC(CEmpTab2Dlg, CDialogEx)

CEmpTab2Dlg::CEmpTab2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG3, pParent)
{
}

CEmpTab2Dlg::~CEmpTab2Dlg()
{
}

void CEmpTab2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_listctrl);
}

CEmpTab2Dlg::CEmpTab2Dlg(CEmployeeDlg * cempdlg)
{
	myswdlg = (CSWTestDlg*)::AfxGetMainWnd();
	set = myswdlg->set;

	this->cempdlg = new CEmployeeDlg();
	for (int i = 0; i < 9; i++) {
		this->cempdlg->pedit[i] = cempdlg->pedit[i];
	}
}


BEGIN_MESSAGE_MAP(CEmpTab2Dlg, CDialogEx)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, &CEmpTab2Dlg::OnNMDblclkList1)
END_MESSAGE_MAP()


// CEmpTab2Dlg 메시지 처리기


void CEmpTab2Dlg::Update()
{
	m_listctrl.DeleteAllItems();
	int j = 0;
	for (int i = 0; i < set->emp->ecount; i++) {
		if (set->emp->empdata[i]->e_data[0] == L"간호사" || set->emp->empdata[i]->e_data[0] == L"\n간호사") {
			m_listctrl.InsertItem(j, set->emp->empdata[i]->e_data[1]);
			m_listctrl.SetItem(j, 1, LVIF_TEXT, set->emp->empdata[i]->e_data[2], NULL, NULL, NULL, NULL);
			m_listctrl.SetItem(j, 2, LVIF_TEXT, set->emp->empdata[i]->e_data[3], NULL, NULL, NULL, NULL);
			m_listctrl.SetItem(j++, 3, LVIF_TEXT, set->emp->empdata[i]->e_data[4], NULL, NULL, NULL, NULL);
		}
	}
}

BOOL CEmpTab2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	
	select = -1;
	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	CRect rt1;
	m_listctrl.GetWindowRect(&rt1);
	m_listctrl.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	m_listctrl.InsertColumn(0, TEXT("직원번호"), LVCFMT_LEFT, rt1.Width()*0.2);
	m_listctrl.InsertColumn(1, TEXT("이름"), LVCFMT_LEFT, rt1.Width()*0.2);
	m_listctrl.InsertColumn(2, TEXT("성별"), LVCFMT_LEFT, rt1.Width()*0.2);
	m_listctrl.InsertColumn(3, TEXT("주민등록번호"), LVCFMT_LEFT, rt1.Width()*0.4);

	m_listctrl.DeleteAllItems();
	int j = 0;
	for (int i = 0; i < set->emp->ecount; i++) {
		if (set->emp->empdata[i]->e_data[0] == L"간호사") {
			m_listctrl.InsertItem(j, set->emp->empdata[i]->e_data[1]);
			m_listctrl.SetItem(j, 1, LVIF_TEXT, set->emp->empdata[i]->e_data[2], NULL, NULL, NULL, NULL);
			m_listctrl.SetItem(j, 2, LVIF_TEXT, set->emp->empdata[i]->e_data[3], NULL, NULL, NULL, NULL);
			m_listctrl.SetItem(j++, 3, LVIF_TEXT, set->emp->empdata[i]->e_data[4], NULL, NULL, NULL, NULL);
			set->emp->ncount++;
		}
	}
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CEmpTab2Dlg::OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	select = pNMLV->iItem;
	for (int i = 0; i < set->emp->ecount; i++) {
		for (int j = 0; j < set->emp->ncount; j++) {
			if (set->emp->empdata[i]->e_data[1] == m_listctrl.GetItemText(select, 0)) {
				cempdlg->SetInformation(i);
			}
		}
	}
	*pResult = 0;
}
