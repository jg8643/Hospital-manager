// CEmpTab3Dlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "SW_Test.h"
#include "CEmpTab3Dlg.h"
#include "afxdialogex.h"
#include "Setting.h"
#include "SW_TestDlg.h"
#include "Employee.h"
#include "CEmployeeDlg.h"
// CEmpTab3Dlg 대화 상자

IMPLEMENT_DYNAMIC(CEmpTab3Dlg, CDialogEx)

CEmpTab3Dlg::CEmpTab3Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG4, pParent)
{
}

CEmpTab3Dlg::~CEmpTab3Dlg()
{
}

void CEmpTab3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_listctrl);
}

CEmpTab3Dlg::CEmpTab3Dlg(CEmployeeDlg *cempdlg)
{
	myswdlg = (CSWTestDlg*)::AfxGetMainWnd();
	set = myswdlg->set;

	this->cempdlg = new CEmployeeDlg();
	for (int i = 0; i < 9; i++) {
		this->cempdlg->pedit[i] = cempdlg->pedit[i];
	}
}


BEGIN_MESSAGE_MAP(CEmpTab3Dlg, CDialogEx)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, &CEmpTab3Dlg::OnNMDblclkList1)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, &CEmpTab3Dlg::OnNMClickList1)
END_MESSAGE_MAP()


// CEmpTab3Dlg 메시지 처리기


void CEmpTab3Dlg::Update()
{
	m_listctrl.DeleteAllItems();
	int j = 0;
	for (int i = 0; i < set->emp->ecount; i++) {
		if (set->emp->empdata[i]->e_data[0] == L"기술스태프" || set->emp->empdata[i]->e_data[0] == L"\n기술스태프") {
			m_listctrl.InsertItem(j, set->emp->empdata[i]->e_data[1]);
			m_listctrl.SetItem(j, 1, LVIF_TEXT, set->emp->empdata[i]->e_data[2], NULL, NULL, NULL, NULL);
			m_listctrl.SetItem(j, 2, LVIF_TEXT, set->emp->empdata[i]->e_data[3], NULL, NULL, NULL, NULL);
			m_listctrl.SetItem(j++, 3, LVIF_TEXT, set->emp->empdata[i]->e_data[4], NULL, NULL, NULL, NULL);
		}
	}
}

void CEmpTab3Dlg::Delete()
{
	int temp;
	if (mark >= 0) {
		for (int i = 0; i < set->emp->ecount; i++) {
			if (set->emp->empdata[i]->e_data[1] == m_listctrl.GetItemText(mark, 0)) {

				for (int j = i; j < set->emp->ecount; j++) {
					if (!(j == set->emp->ecount - 1)) {
						temp = _ttoi(set->emp->empdata[j + 1]->e_data[1]) - 1;
						set->emp->empdata[j + 1]->e_data[1].Format(_T("%d"), temp);
					}
					set->emp->empdata[j] = set->emp->empdata[j + 1];
				}
				set->emp->dcount--;
				set->emp->ecount--;
			}
		}
		m_listctrl.DeleteItem(mark);
		mark = -1;
		set->emp->WriteEmpFile();
	}
	else {
		AfxMessageBox(L"선택 ㄱㄱ");
	}
	Update();
}

BOOL CEmpTab3Dlg::OnInitDialog()
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
		if (set->emp->empdata[i]->e_data[0] == L"기술스태프") {
			m_listctrl.InsertItem(j, set->emp->empdata[i]->e_data[1]);
			m_listctrl.SetItem(j, 1, LVIF_TEXT, set->emp->empdata[i]->e_data[2], NULL, NULL, NULL, NULL);
			m_listctrl.SetItem(j, 2, LVIF_TEXT, set->emp->empdata[i]->e_data[3], NULL, NULL, NULL, NULL);
			m_listctrl.SetItem(j++, 3, LVIF_TEXT, set->emp->empdata[i]->e_data[4], NULL, NULL, NULL, NULL);
			set->emp->scount++;
		}
	}
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CEmpTab3Dlg::OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	select = pNMLV->iItem;
	for (int i = 0; i < set->emp->ecount; i++) {
		for (int j = 0; j < set->emp->scount; j++) {
			if (set->emp->empdata[i]->e_data[1] == m_listctrl.GetItemText(select, 0)) {
				cempdlg->SetInformation(i);
			}
		}
	}
	*pResult = 0;
}


void CEmpTab3Dlg::OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	mark = pNMLV->iItem;
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
}
