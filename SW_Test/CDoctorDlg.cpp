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
static CFont m_font1, m_font2;
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
	ON_BN_CLICKED(IDC_BUTTON8, &CDoctorDlg::OnBnClickedButton8)
	ON_NOTIFY(NM_CLICK, IDC_LIST2, &CDoctorDlg::OnNMClickList2)
	ON_BN_CLICKED(IDC_BUTTON12, &CDoctorDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON13, &CDoctorDlg::OnBnClickedButton13)
	ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CDoctorDlg 메시지 처리기


BOOL CDoctorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	HICON hIcon = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDR_MAINFRAME)); //icon 변경
	this->SetIcon(hIcon, FALSE);
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
	int idc_static[2] = { IDC_STATIC1, IDC_STATIC2 };
	int idc_list[2] = { IDC_LIST1, IDC_LIST2 };
	int idc_edit[8] = { IDC_EDIT1,IDC_EDIT2 ,IDC_EDIT3 ,IDC_EDIT4 ,IDC_EDIT5 ,IDC_EDIT6 , IDC_EDIT7, IDC_EDIT8};
	int idc_button[12] = { IDC_BUTTON1,IDC_BUTTON2,IDC_BUTTON3,IDC_BUTTON4,IDC_BUTTON5,IDC_BUTTON6,IDC_BUTTON7,IDC_BUTTON8,IDC_BUTTON9,IDC_BUTTON10,IDC_BUTTON11,IDC_BUTTON12 };
	for (int i = 0; i < 8; i++) {
		pedit[i] = (CEdit*)GetDlgItem(idc_edit[i]);
	}
	for (int i = 0; i < 2; i++) {
		GetDlgItem(idc_static[i])->SetFont(&m_font1);
		GetDlgItem(idc_list[i])->SetFont(&m_font2);
	}
	for (int i = 0; i < 12; i++) {
		GetDlgItem(idc_button[i])->SetFont(&m_font2);
	}
	m_font1.Detach();
	m_font2.Detach();
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
	m_listctrl2.InsertColumn(0, TEXT("이름"), LVCFMT_LEFT, rt2.Width()*0.7);
	m_listctrl2.InsertColumn(1, TEXT("개수"), LVCFMT_LEFT, rt2.Width()*0.3);
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

// 진료 완료
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

	for (int i = select; i < set->wait_count; i++) {
		set->wait[i] = set->wait[i + 1];
	}
	
	set->complet[set->complet_count++] = m_listctrl1.GetItemText(select,0);

	set->wait_count--;
	m_listctrl1.DeleteItem(select);
	
	for (int i = 0; i < 8; i++) {
		pedit[i]->SetWindowText(L"");
	}

	for (int i = 0; i < 4; i++) {
		m_listctrl2.SetItem(i, 1, LVIF_TEXT, L"0", NULL, NULL, NULL, NULL);
	}
	mark = -1;
	select = -1;
}


// 약재목록 클릭 시
void CDoctorDlg::OnNMClickList2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	mark = pNMLV->iItem;
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
}


// +버튼
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
// -버튼
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

void CDoctorDlg::OnBnClickedButton13()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnOK();
}

// 배경
BOOL CDoctorDlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CRect rt;
	GetClientRect(rt);
	pDC->FillSolidRect(rt, RGB(255, 255, 255));
	return TRUE;
}

// 글자 배경
HBRUSH CDoctorDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  여기서 DC의 특성을 변경합니다.
	if (nCtlColor == CTLCOLOR_STATIC) {
		pDC->SetBkColor(RGB(255, 255, 255));
	}
	// TODO:  기본값이 적당하지 않으면 다른 브러시를 반환합니다.
	return hbr;
}