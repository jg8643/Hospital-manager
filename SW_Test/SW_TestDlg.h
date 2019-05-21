
// SW_TestDlg.h: 헤더 파일
//

#pragma once
class Setting;
// CSWTestDlg 대화 상자
class CSWTestDlg : public CDialogEx
{
// 생성입니다.
public:
	CSWTestDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SW_TEST_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	Setting *set;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
};
