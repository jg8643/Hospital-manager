#pragma once


// CFrontDlg 대화 상자
class Setting;
class CSWTestDlg;
class CFrontDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CFrontDlg)

public:
	CFrontDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CFrontDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG5 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	Setting *set;
	CSWTestDlg *myswdlg;
	CComboBox m_combo;
	CEdit *pedit[7];
	int search;
	int select;
	virtual BOOL OnInitDialog();
	CListCtrl m_listctrl1;
	CListCtrl m_listctrl2;
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult);
};
