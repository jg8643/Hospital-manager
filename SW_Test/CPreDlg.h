#pragma once


// PreDlg 대화 상자
class Setting;
class CSWTestDlg;
class CPreDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CPreDlg)

public:
	CPreDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CPreDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG9 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	Setting *set;
	CSWTestDlg *myswdlg;
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnDestroy();
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CMFCButton mbtn1;
	CMFCButton mbtn2;
	CMFCButton mbtn3;
	CMFCButton mbtn4;
	CMFCButton mbtn5;
	CMFCButton mbtn6;
	CMFCButton mbtn7;
	CListCtrl m_listctrl1;
	CMFCButton mbtn8;
	CMFCButton mbtn9;
	CMFCButton mbtn10;
	CEdit *pedit[5];
	CMFCButton mbtn11;
	afx_msg void OnBnClickedMfcbutton11();
	CListCtrl m_listctrl2;
};
