// CDoctorDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "SW_Test.h"
#include "CDoctorDlg.h"
#include "afxdialogex.h"
#include "Setting.h"
#include "SW_TestDlg.h"
#include "Patient.h"
#include "Prescription.h"
// CDoctorDlg 대화 상자

IMPLEMENT_DYNAMIC(CDoctorDlg, CDialogEx)

CDoctorDlg::CDoctorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG6, pParent)
{
	myswdlg = (CSWTestDlg*)::AfxGetMainWnd();
	set = myswdlg->set;
}

CDoctorDlg::~CDoctorDlg()
{
}

void CDoctorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_listctrl1);
	DDX_Control(pDX, IDC_LIST2, m_listctrl2);
}


BEGIN_MESSAGE_MAP(CDoctorDlg, CDialogEx)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, &CDoctorDlg::OnNMDblclkList1)
	ON_BN_CLICKED(IDC_BUTTON9, &CDoctorDlg::OnBnClickedButton9)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST2, &CDoctorDlg::OnNMDblclkList2)
	ON_BN_CLICKED(IDC_BUTTON8, &CDoctorDlg::OnBnClickedButton8)
	ON_NOTIFY(NM_CLICK, IDC_LIST2, &CDoctorDlg::OnNMClickList2)
	ON_BN_CLICKED(IDC_BUTTON12, &CDoctorDlg::OnBnClickedButton12)
END_MESSAGE_MAP()


// CDoctorDlg 메시지 처리기


BOOL CDoctorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	int idc_edit[8] = { IDC_EDIT1,IDC_EDIT2 ,IDC_EDIT3 ,IDC_EDIT4 ,IDC_EDIT5 ,IDC_EDIT6 , IDC_EDIT7, IDC_EDIT8};
	for (int i = 0; i < 8; i++) {
		pedit[i] = (CEdit*)GetDlgItem(idc_edit[i]);
	}
	// TODO:  여기에 추가 초기화 작업을 추가합니다.
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
	m_listctrl2.InsertColumn(0, TEXT("이름"), LVCFMT_LEFT, rt2.Width()*0.8);
	m_listctrl2.InsertColumn(1, TEXT("개수"), LVCFMT_LEFT, rt2.Width()*0.2);
	m_listctrl2.InsertItem(0, L"붕대");
	m_listctrl2.InsertItem(1, L"기침약");
	m_listctrl2.InsertItem(2, L"두통약");
	m_listctrl2.InsertItem(3, L"주사");

	for (int i = 0; i < 4; i++) {
		m_listctrl2.SetItem(i,1, LVIF_TEXT, L"0", NULL, NULL, NULL, NULL);
	}
	for (int i = 0; i < set->wait_count; i++) {
		for (int j = 0; j < set->pat->pcount; j++) {
			if (set->wait[i] == set->pat->patdata[j]->p_data[0]) {
				m_listctrl1.InsertItem(i, set->pat->patdata[j]->p_data[0]);
				m_listctrl1.SetItem(i, 1, LVIF_TEXT, set->pat->patdata[j]->p_data[1], NULL, NULL, NULL, NULL);
				m_listctrl1.SetItem(i, 2, LVIF_TEXT, set->pat->patdata[j]->p_data[2], NULL, NULL, NULL, NULL);
				m_listctrl1.SetItem(i, 3, LVIF_TEXT, set->pat->patdata[j]->p_data[3], NULL, NULL, NULL, NULL);
			}
		}
	}
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CDoctorDlg::OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	select = pNMLV->iItem;
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	for (int i = 0; i < set->pat->pcount; i++) {
		if (set->pat->patdata[i]->p_data[0] == m_listctrl1.GetItemText(select, 0)) {
			for (int j = 0; j < 7; j++) {
				pedit[j]->SetWindowText(set->pat->patdata[i]->p_data[j]);
			}
		}
	}
	*pResult = 0;
}


void CDoctorDlg::OnBnClickedButton9()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString temp[2];
	int count = 0;
	pedit[0]->GetWindowText(temp[0]);
	pedit[7]->GetWindowText(temp[1]);
	CString str[5][2];
	for (int i = 0; i < 4; i++) {
		if (m_listctrl2.GetItemText(i, 1) != L"0") {
			str[count][0] = m_listctrl2.GetItemText(i, 0);
			str[count++][1] = m_listctrl2.GetItemText(i, 1);
		}
	}
	set->pre->CreatePre(temp, str);

	for (int i = 0; i < set->wait_count; i++) {
		set->wait[i] = set->wait[i + 1];
	}
	
	set->complet[set->complet_count++] = m_listctrl1.GetItemText(select,0);

	set->wait_count--;
	m_listctrl1.DeleteItem(select);
}


void CDoctorDlg::OnNMDblclkList2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	/*
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	mark = pNMLV->iItem;
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str1;
	str1 = m_listctrl2.GetItemText(mark,0);
	*/
	*pResult = 0;
}


void CDoctorDlg::OnBnClickedButton8()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int temp;
	CString str;
	str = m_listctrl2.GetItemText(mark, 1);
	temp = _ttoi(str) + 1;
	str.Format(L"%d", temp);
	m_listctrl2.SetItem(mark, 1, LVIF_TEXT, str, NULL, NULL, NULL, NULL);
}


void CDoctorDlg::OnNMClickList2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	mark = pNMLV->iItem;
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
}


void CDoctorDlg::OnBnClickedButton12()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int temp;
	CString str;
	str = m_listctrl2.GetItemText(mark, 1);
	if (str != L"0") {
		temp = _ttoi(str) - 1;
		str.Format(L"%d", temp);
		m_listctrl2.SetItem(mark, 1, LVIF_TEXT, str, NULL, NULL, NULL, NULL);
	}
}
