
// DebugTemplateDlg.h : header file
//

#pragma once
#include "afxwin.h"


// CDebugTemplateDlg dialog
class CDebugTemplateDlg : public CDialog
{
// Construction
public:
	CDebugTemplateDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_DEBUGTEMPLATE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
    afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedClose();
private:
    CEdit _argumentEdit;
public:
    afx_msg void OnBnClickedRun();
};
