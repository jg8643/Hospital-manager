// CFrontDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "SW_Test.h"
#include "CFrontDlg.h"
#include "afxdialogex.h"
#include "SW_TestDlg.h"
#include "Setting.h"
#include "Patient.h"

// CFrontDlg 대화 상자

IMPLEMENT_DYNAMIC(CFrontDlg, CDialogEx)

CFrontDlg::CFrontDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG5, pParent)
{
	myswdlg = (CSWTestDlg*)::AfxGetMainWnd();
	set = myswdlg->set;
}

CFrontDlg::~CFrontDlg()
{
}

void CFrontDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_combo);
	DDX_Control(pDX, IDC_LIST1, m_listctrl1);
	DDX_Control(pDX, IDC_LIST2, m_listctrl2);
}


BEGIN_MESSAGE_MAP(CFrontDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON9, &CFrontDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CFrontDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON7, &CFrontDlg::OnBnClickedButton7)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, &CFrontDlg::OnNMDblclkList1)
END_MESSAGE_MAP()


// CFrontDlg 메시지 처리기


BOOL CFrontDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	m_combo.AddString(_T("이름"));
	m_combo.AddString(_T("환자번호"));
	m_combo.SetCurSel(0);
	
	CRect rt1;
	m_listctrl1.GetWindowRect(&rt1);
	m_listctrl1.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	m_listctrl1.InsertColumn(0, TEXT("환자번호"), LVCFMT_LEFT, rt1.Width()*0.2);
	m_listctrl1.InsertColumn(1, TEXT("이름"), LVCFMT_LEFT, rt1.Width()*0.2);
	m_listctrl1.InsertColumn(2, TEXT("성별"), LVCFMT_LEFT, rt1.Width()*0.2);
	m_listctrl1.InsertColumn(3, TEXT("주민등록번호"), LVCFMT_LEFT, rt1.Width()*0.4);

	CRect rt2;
	m_listctrl2.GetWindowRect(&rt2);
	m_listctrl2.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	m_listctrl2.InsertColumn(0, TEXT("환자번호"), LVCFMT_LEFT, rt2.Width()*0.2);
	m_listctrl2.InsertColumn(1, TEXT("이름"), LVCFMT_LEFT, rt2.Width()*0.2);
	m_listctrl2.InsertColumn(2, TEXT("성별"), LVCFMT_LEFT, rt2.Width()*0.2);
	m_listctrl2.InsertColumn(3, TEXT("주민등록번호"), LVCFMT_LEFT, rt2.Width()*0.4);

	int idc_edit[7] = { IDC_EDIT1,IDC_EDIT2,IDC_EDIT3,IDC_EDIT4,IDC_EDIT5,IDC_EDIT6,IDC_EDIT7 };
	for (int i = 0; i < 7; i++) {
		pedit[i] = (CEdit*)GetDlgItem(idc_edit[i]);
	}

	for (int i = 0; i < set->wait_count; i++) {
		for (int j = 0; j < set->pat->pcount; j++) {
			if (set->wait[i] == set->pat->patdata[j]->p_data[0]) {
				m_listctrl2.InsertItem(i, set->pat->patdata[j]->p_data[0]);
				m_listctrl2.SetItem(i, 1, LVIF_TEXT, set->pat->patdata[j]->p_data[1], NULL, NULL, NULL, NULL);
				m_listctrl2.SetItem(i, 2, LVIF_TEXT, set->pat->patdata[j]->p_data[2], NULL, NULL, NULL, NULL);
				m_listctrl2.SetItem(i, 3, LVIF_TEXT, set->pat->patdata[j]->p_data[3], NULL, NULL, NULL, NULL);
			}
		}
	}
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CFrontDlg::OnBnClickedButton9()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CFrontDlg::OnBnClickedButton10()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	for (int i = 0; i < 6 ; i++) {
		pedit[i]->GetWindowText(str);
		if (str == L"") {
			AfxMessageBox(L"비었어요");
			break;
		}
	}
}


void CFrontDlg::OnBnClickedButton7()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_listctrl1.DeleteAllItems();
	CString str1, str2;
	m_combo.GetLBText(m_combo.GetCurSel(), str1);
	pedit[6]->GetWindowText(str2);
	search = 0;
	if (str1 == L"이름") {
		for (int i = 0; i < set->pat->pcount; i++) {
			if (set->pat->patdata[i]->p_data[1] == str2) {
				m_listctrl1.InsertItem(i, set->pat->patdata[i]->p_data[0]);
				m_listctrl1.SetItem(search, 1, LVIF_TEXT, set->pat->patdata[i]->p_data[1], NULL, NULL, NULL, NULL);
				m_listctrl1.SetItem(search, 2, LVIF_TEXT, set->pat->patdata[i]->p_data[2], NULL, NULL, NULL, NULL);
				m_listctrl1.SetItem(search++, 3, LVIF_TEXT, set->pat->patdata[i]->p_data[3], NULL, NULL, NULL, NULL);
			}
		}
	}
	else {

	}
}


void CFrontDlg::OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	select = pNMLV->iItem;
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	set->wait[set->wait_count] = m_listctrl1.GetItemText(select, 0);
	m_listctrl2.InsertItem(set->wait_count, m_listctrl1.GetItemText(select, 0));
	m_listctrl2.SetItem(set->wait_count, 1, LVIF_TEXT, m_listctrl1.GetItemText(select, 1), NULL, NULL, NULL, NULL);
	m_listctrl2.SetItem(set->wait_count, 2, LVIF_TEXT, m_listctrl1.GetItemText(select, 2), NULL, NULL, NULL, NULL);
	m_listctrl2.SetItem(set->wait_count++, 3, LVIF_TEXT, m_listctrl1.GetItemText(select, 3), NULL, NULL, NULL, NULL);
	*pResult = 0;
}
