#pragma once


// CPatAddDlg 대화 상자
class Setting;
class CSWTestDlg;
class CPatAddDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CPatAddDlg)

public:
	CPatAddDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CPatAddDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG8 };
#endif

protected:
	Setting *set;
	CSWTestDlg *myswdlg;
	CEdit *pedit[7];
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton8();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};
