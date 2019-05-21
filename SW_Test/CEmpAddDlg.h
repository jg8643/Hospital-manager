#pragma once


// CEmpAddDlg 대화 상자
class Setting;
class CSWTestDlg;
class CEmpAddDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CEmpAddDlg)

public:
	CEmpAddDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CEmpAddDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG7 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_combo;
	Setting *set;
	CSWTestDlg *myswdlg;
	CEdit *pedit[9];
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton12();
	afx_msg void OnBnClickedOk();
};
