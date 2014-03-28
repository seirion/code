
// DebugTemplateDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DebugTemplate.h"
#include "DebugTemplateDlg.h"
#include <code/debug.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


#include <cstring>

using namespace std;
// CDebugTemplateDlg dialog




CDebugTemplateDlg::CDebugTemplateDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDebugTemplateDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDebugTemplateDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_ARGUMENT_EDIT, _argumentEdit);
}

BEGIN_MESSAGE_MAP(CDebugTemplateDlg, CDialog)
	ON_WM_PAINT()
    ON_WM_TIMER()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
    ON_BN_CLICKED(IDC_CLOSE, &CDebugTemplateDlg::OnBnClickedClose)
    ON_BN_CLICKED(IDC_RUN, &CDebugTemplateDlg::OnBnClickedRun)
END_MESSAGE_MAP()


// CDebugTemplateDlg message handlers

BOOL CDebugTemplateDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
    SetTimer(1234/*meaningless*/, 100, 0);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDebugTemplateDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDebugTemplateDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

////////////////////////////////////////////////////////////////////////////////
void CDebugTemplateDlg::OnTimer(UINT_PTR nIDEvent)
{
    KillTimer(nIDEvent);
    main(0, 0);
    //OnBnClickedRun();
}

void CDebugTemplateDlg::OnBnClickedRun()
{
    const INT32 MAX_ARGUMENT_NUM = 16;
    const INT32 MAX_ARGUMENT_SIZE = 256;
    INT32 argc = 0;
    char *argv[MAX_ARGUMENT_NUM];
    char str[MAX_ARGUMENT_SIZE];
    char *temp;
    

    _argumentEdit.GetWindowTextA(str, MAX_ARGUMENT_SIZE);
    temp = strtok(str, " ");

    argv[argc++] = "DebugTemplate";
    argv[argc++] = temp;
    while (temp = strtok(NULL, " ")) {
        TRACE("%s\n", temp);
        argv[argc++] = temp;
    }
    argv[argc] = NULL;

    main(argc, argv);
}


void CDebugTemplateDlg::OnBnClickedClose()
{
    ::exit(0);
}
