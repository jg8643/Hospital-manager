#pragma once


// CDoctorDlg 대화 상자
class Setting;
class CSWTestDlg;
class CDoctorDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CDoctorDlg)

public:
	CDoctorDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDoctorDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG6 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	Setting *set;
	CSWTestDlg *myswdlg;
	CEdit *pedit[8];
	int select;
	int mark;
	int count[5] = { 0 };
	CListCtrl m_listctrl1;
	CListCtrl m_listctrl2;
	virtual BOOL OnInitDialog();
	afx_msg void OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton9();
	afx_msg void OnNMDblclkList2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton8();
	afx_msg void OnNMClickList2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton12();
	afx_msg void OnBnClickedButton13();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
