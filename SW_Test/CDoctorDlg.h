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
	CListCtrl m_listctrl1;
	CListCtrl m_listctrl2;
	CListCtrl m_listctrl3;
	virtual BOOL OnInitDialog();
	afx_msg void OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult);
};
