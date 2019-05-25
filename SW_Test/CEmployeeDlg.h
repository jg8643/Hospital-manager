#pragma once


// CEmployeeDlg 대화 상자
class Setting;
class CSWTestDlg;
class CEmpTab1Dlg;
class CEmpTab2Dlg;
class CEmpTab3Dlg;
class CEmployeeDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CEmployeeDlg)

public:
	CEmployeeDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CEmployeeDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CEmployeeDlg(CEmployeeDlg*);
	Setting *set;
	CSWTestDlg *myswdlg;
	CEdit  *pedit[9];
	CTabCtrl m_tabctrl;
	CEmpTab1Dlg *cet1;
	CEmpTab2Dlg *cet2;
	CEmpTab3Dlg *cet3;
	void SetInformation(int);  // 직원 탭에서 직원 더블 클릭 시 직원 정보 셋팅
	void Update();             // 탭컨트롤 정보 업데이트
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton12();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedOk();
};
