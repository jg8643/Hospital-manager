// CFrontDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "SW_Test.h"
#include "CFrontDlg.h"
#include "afxdialogex.h"
#include "SW_TestDlg.h"
#include "Setting.h"
#include "Patient.h"
#include "CPatAddDlg.h"
// CFrontDlg 대화 상자

IMPLEMENT_DYNAMIC(CFrontDlg, CDialogEx)
static CFont m_font1, m_font2;
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
	DDX_Control(pDX, IDC_LIST3, m_listctrl3);
}


BEGIN_MESSAGE_MAP(CFrontDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON9, &CFrontDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CFrontDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON7, &CFrontDlg::OnBnClickedButton7)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, &CFrontDlg::OnNMDblclkList1)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, &CFrontDlg::OnNMClickList1)
	ON_BN_CLICKED(IDC_BUTTON11, &CFrontDlg::OnBnClickedButton11)
	ON_NOTIFY(NM_CLICK, IDC_LIST2, &CFrontDlg::OnNMClickList2)
	ON_BN_CLICKED(IDOK, &CFrontDlg::OnBnClickedOk)
	ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CFrontDlg 메시지 처리기


BOOL CFrontDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	HICON hIcon = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDR_MAINFRAME)); //icon 변경
	this->SetIcon(hIcon, FALSE);
	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	m_font1.CreateFont(40, 15,            // 세로,가로 크기
		0, 0,
		FW_HEAVY,    //Font 굵기
		FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, OUT_DEFAULT_PRECIS,
		DEFAULT_QUALITY, DEFAULT_PITCH,
		L"맑은 고딕");
	m_font2.CreateFont(20, 8,            // 세로,가로 크기
		0, 0,
		FW_HEAVY,    //Font 굵기
		FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, OUT_DEFAULT_PRECIS,
		DEFAULT_QUALITY, DEFAULT_PITCH,
		L"맑은 고딕");
	int idc_static[4] = { IDC_STATIC1,IDC_STATIC2,IDC_STATIC3,IDC_STATIC4 };
	int idc_list[3] = { IDC_LIST1, IDC_LIST2, IDC_LIST3 };
	int idc_button[12] = { IDC_COMBO1,IDC_BUTTON1,IDC_BUTTON2,IDC_BUTTON3,IDC_BUTTON4,IDC_BUTTON5,IDC_BUTTON6,IDC_BUTTON7,IDC_BUTTON8,IDC_BUTTON9,IDC_BUTTON10,IDC_BUTTON11 };
	int idc_edit[7] = { IDC_EDIT1,IDC_EDIT2,IDC_EDIT3,IDC_EDIT4,IDC_EDIT5,IDC_EDIT6,IDC_EDIT7 };
	for (int i = 0; i < 4; i++) {
		GetDlgItem(idc_static[i])->SetFont(&m_font1);
	}
	for (int i = 0; i < 12; i++) {
		GetDlgItem(idc_button[i])->SetFont(&m_font2);
	}
	for (int i = 0; i < 3; i++) {
		GetDlgItem(idc_list[i])->SetFont(&m_font2);
	}
	for (int i = 0; i < 7; i++) {
		GetDlgItem(idc_edit[i])->SetFont(&m_font2);
	}
	m_font1.Detach();
	m_font2.Detach();
	m_combo.AddString(_T("이름"));
	m_combo.AddString(_T("환자번호"));
	m_combo.SetCurSel(0);
	
	GetDlgItem(IDC_BUTTON10)->EnableWindow(FALSE);

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

	CRect rt3;
	m_listctrl3.GetWindowRect(&rt3);
	m_listctrl3.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	m_listctrl3.InsertColumn(0, TEXT("환자번호"), LVCFMT_LEFT, rt3.Width()*0.2);
	m_listctrl3.InsertColumn(1, TEXT("이름"), LVCFMT_LEFT, rt3.Width()*0.2);
	m_listctrl3.InsertColumn(2, TEXT("성별"), LVCFMT_LEFT, rt3.Width()*0.2);
	m_listctrl3.InsertColumn(3, TEXT("주민등록번호"), LVCFMT_LEFT, rt3.Width()*0.4);
	
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
	for (int i = 0; i < set->complet_count; i++) {
		for (int j = 0; j < set->pat->pcount; j++) {
			if (set->complet[i] == set->pat->patdata[j]->p_data[0]) {
				m_listctrl3.InsertItem(i, set->pat->patdata[j]->p_data[0]);
				m_listctrl3.SetItem(i, 1, LVIF_TEXT, set->pat->patdata[j]->p_data[1], NULL, NULL, NULL, NULL);
				m_listctrl3.SetItem(i, 2, LVIF_TEXT, set->pat->patdata[j]->p_data[2], NULL, NULL, NULL, NULL);
				m_listctrl3.SetItem(i, 3, LVIF_TEXT, set->pat->patdata[j]->p_data[3], NULL, NULL, NULL, NULL);
			}
		}
	}
	return FALSE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CFrontDlg::OnBnClickedButton9()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CPatAddDlg cpatadddlg;
	cpatadddlg.DoModal();
	cpatadddlg.DestroyWindow();
}


void CFrontDlg::OnBnClickedButton10()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	pedit[0]->GetWindowText(str);
	for (int i = 0; i < set->pat->pcount; i++) {
		if (set->pat->patdata[i]->p_data[0] == str) {
			for (int j = 1; j < 6; j++) {
				pedit[j]->GetWindowText(set->pat->patdata[i]->p_data[j]);
			}
		}
	}
	set->pat->WritePatFile();
	AfxMessageBox(L"수정되었습니다.");
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
	else if(str1 == L"환자번호"){
		for (int i = 0; i < set->pat->pcount; i++) {
			if (set->pat->patdata[i]->p_data[0] == str2) {
				m_listctrl1.InsertItem(i, set->pat->patdata[i]->p_data[0]);
				m_listctrl1.SetItem(search, 1, LVIF_TEXT, set->pat->patdata[i]->p_data[1], NULL, NULL, NULL, NULL);
				m_listctrl1.SetItem(search, 2, LVIF_TEXT, set->pat->patdata[i]->p_data[2], NULL, NULL, NULL, NULL);
				m_listctrl1.SetItem(search++, 3, LVIF_TEXT, set->pat->patdata[i]->p_data[3], NULL, NULL, NULL, NULL);
			}
		}
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


void CFrontDlg::OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	select = pNMLV->iItem;
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	for (int i = 0; i < set->pat->pcount; i++) {
		if (m_listctrl1.GetItemText(select, 0) == set->pat->patdata[i]->p_data[0]) {
			for (int j = 0; j < 6; j++) {
				pedit[j]->SetWindowText(set->pat->patdata[i]->p_data[j]);
			}
			GetDlgItem(IDC_BUTTON10)->EnableWindow(TRUE);
		}
	}
	*pResult = 0;
}


void CFrontDlg::OnBnClickedButton11()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (mark >= 0) {
		for (int i = 0; i < set->wait_count; i++) {
			if (set->wait[i] == m_listctrl2.GetItemText(mark, 0)) {
				for (int j = i; j < set->wait_count; j++) {
					set->wait[j] = set->wait[j + 1];
				}
				break;
			}
		}
		set->wait_count--;
		m_listctrl2.DeleteItem(mark);
	}
}


void CFrontDlg::OnNMClickList2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	mark = pNMLV->iItem;
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
}


void CFrontDlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnOK();
}


BOOL CFrontDlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CRect rt;
	GetClientRect(rt);
	pDC->FillSolidRect(rt, RGB(255, 255, 255));
	return TRUE;
	//return CDialogEx::OnEraseBkgnd(pDC);
}


HBRUSH CFrontDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  여기서 DC의 특성을 변경합니다.
	if (nCtlColor == CTLCOLOR_STATIC) {
		pDC->SetBkColor(RGB(255, 255, 255));
	}
	// TODO:  기본값이 적당하지 않으면 다른 브러시를 반환합니다.
	return hbr;
}
