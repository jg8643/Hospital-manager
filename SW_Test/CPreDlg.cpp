// PreDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "SW_Test.h"
#include "CPreDlg.h"
#include "afxdialogex.h"
#include "Setting.h"
#include "SW_TestDlg.h"
#include "Patient.h"
#include "Prescription.h"

// PreDlg 대화 상자

IMPLEMENT_DYNAMIC(CPreDlg, CDialogEx)
static CFont m_font1, m_font2;
CPreDlg::CPreDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG9, pParent)
{
	myswdlg = (CSWTestDlg*)::AfxGetMainWnd();
	set = myswdlg->set;
}

CPreDlg::~CPreDlg()
{
}

void CPreDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MFCBUTTON1, mbtn1);
	DDX_Control(pDX, IDC_MFCBUTTON2, mbtn2);
	DDX_Control(pDX, IDC_MFCBUTTON3, mbtn3);
	DDX_Control(pDX, IDC_MFCBUTTON7, mbtn4);
	DDX_Control(pDX, IDC_MFCBUTTON4, mbtn5);
	DDX_Control(pDX, IDC_MFCBUTTON5, mbtn6);
	DDX_Control(pDX, IDC_MFCBUTTON6, mbtn7);
	DDX_Control(pDX, IDC_LIST1, m_listctrl1);
	DDX_Control(pDX, IDC_MFCBUTTON8, mbtn8);
	DDX_Control(pDX, IDC_MFCBUTTON9, mbtn9);
	DDX_Control(pDX, IDC_MFCBUTTON10, mbtn10);
	DDX_Control(pDX, IDC_MFCBUTTON11, mbtn11);
	DDX_Control(pDX, IDC_LIST2, m_listctrl2);
}


BEGIN_MESSAGE_MAP(CPreDlg, CDialogEx)
	ON_WM_ERASEBKGND()
	ON_WM_DESTROY()
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_MFCBUTTON11, &CPreDlg::OnBnClickedMfcbutton11)
END_MESSAGE_MAP()


// PreDlg 메시지 처리기


BOOL CPreDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
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
	GetDlgItem(IDC_STATIC1)->SetFont(&m_font1);
	int idc_mbutton[11] = { IDC_MFCBUTTON1,IDC_MFCBUTTON2,IDC_MFCBUTTON3,IDC_MFCBUTTON4,IDC_MFCBUTTON5,IDC_MFCBUTTON6,IDC_MFCBUTTON7,IDC_MFCBUTTON8,IDC_MFCBUTTON9,IDC_MFCBUTTON10, IDC_MFCBUTTON11 };
	int idc_edit[5] = { IDC_EDIT1, IDC_EDIT2, IDC_EDIT3, IDC_EDIT4, IDC_EDIT5 };
	for (int i = 0; i < 11; i++) {
		GetDlgItem(idc_mbutton[i])->SetFont(&m_font2);
	}
	for (int i = 0; i < 5; i++) {
		GetDlgItem(idc_edit[i])->SetFont(&m_font2);
		pedit[i] = (CEdit*)GetDlgItem(idc_edit[i]);
	}
	pedit[2]->SetWindowText(L"정규병원");
	pedit[3]->SetWindowText(L"010-2669-8543");
	pedit[4]->SetWindowText(L"wjdrb8643@naver.com");
	mbtn1.EnableWindowsTheming(FALSE);
	mbtn2.EnableWindowsTheming(FALSE);
	mbtn3.EnableWindowsTheming(FALSE);
	mbtn4.EnableWindowsTheming(FALSE);
	mbtn5.EnableWindowsTheming(FALSE);
	mbtn6.EnableWindowsTheming(FALSE);
	mbtn7.EnableWindowsTheming(FALSE);
	mbtn8.EnableWindowsTheming(FALSE);
	mbtn9.EnableWindowsTheming(FALSE);
	mbtn10.EnableWindowsTheming(FALSE);
	mbtn11.EnableWindowsTheming(FALSE);
	mbtn1.SetFaceColor(RGB(255, 255, 255), true);
	mbtn2.SetFaceColor(RGB(255, 255, 255), true);
	mbtn3.SetFaceColor(RGB(255, 255, 255), true);
	mbtn4.SetFaceColor(RGB(255, 255, 255), true);
	mbtn5.SetFaceColor(RGB(255, 255, 255), true);
	mbtn6.SetFaceColor(RGB(255, 255, 255), true);
	mbtn7.SetFaceColor(RGB(255, 255, 255), true);
	mbtn8.SetFaceColor(RGB(255, 255, 255), true);
	mbtn9.SetFaceColor(RGB(255, 255, 255), true);
	mbtn10.SetFaceColor(RGB(255, 255, 255), true);
	mbtn11.SetFaceColor(RGB(255, 255, 255), true);

	CRect rt1;
	m_listctrl1.GetWindowRect(&rt1);
	m_listctrl1.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	m_listctrl1.InsertColumn(0, TEXT("처 방 의 약 품 명 칭"), LVCFMT_LEFT, rt1.Width()*0.69);
	m_listctrl1.InsertColumn(1, TEXT("개 수"), LVCFMT_LEFT, rt1.Width()*0.3);
	CRect rt2;
	m_listctrl2.GetWindowRect(&rt2);
	m_listctrl2.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	m_listctrl2.InsertColumn(0, TEXT("진 료 내 용"), LVCFMT_LEFT, rt2.Width()*0.99);
	GetDlgItem(IDC_LIST1)->SetFont(&m_font2);
	GetDlgItem(IDC_LIST2)->SetFont(&m_font2);
	m_font1.Detach();
	m_font2.Detach();
	
	CString str;
	for (int i = 0; i < set->pre->tcount; i++) {
		if (set->pat_num == set->pre->pre_data[i]->patnum) {
			for (int j = 0; j < 4; j++) {
				m_listctrl1.InsertItem(j, set->pre->pre_data[i]->medication[j][0]);
				m_listctrl1.SetItem(j, 1, LVIF_TEXT, set->pre->pre_data[i]->medication[j][1], NULL, NULL, NULL, NULL);
			}
			m_listctrl2.InsertItem(0, set->pre->pre_data[i]->treat);
		}
	}
	for(int i = 0; i < set->pat->pcount; i++){
		if (set->pat_num == set->pat->patdata[i]->p_data[0]) {
			pedit[0]->SetWindowText(set->pat->patdata[i]->p_data[1]);
			pedit[1]->SetWindowText(set->pat->patdata[i]->p_data[3]);
		}
	}
	GotoDlgCtrl(GetDlgItem(IDC_MFCBUTTON11));
	return FALSE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


BOOL CPreDlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CRect rt;
	GetClientRect(rt);
	pDC->FillSolidRect(rt, RGB(255, 255, 255));
	return TRUE;
}


void CPreDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}


void CPreDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CDialogEx::OnPaint()을(를) 호출하지 마십시오.
}


HBRUSH CPreDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  여기서 DC의 특성을 변경합니다.
	if (nCtlColor == CTLCOLOR_STATIC) {
		pDC->SetBkColor(RGB(255, 255, 255));
	}
	// TODO:  기본값이 적당하지 않으면 다른 브러시를 반환합니다.
	return hbr;
}


void CPreDlg::OnBnClickedMfcbutton11()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	for (int i = 0; i < set->pre->tcount; i++) {
		set->pre->pre_data[i] = set->pre->pre_data[i + 1];
	}
	set->pre->tcount--;
	for (int i = 0; i < set->complet_count; i++) {
		set->complet[i] = set->complet[i + 1];
	}
	set->complet_count--;
	CDialogEx::OnOK();
}
