// DlgHelp.cpp : implementation file
//

#include "stdafx.h"
#include "mfc.h"
#include "DlgHelp.h"
#include "afxdialogex.h"


// CDlgHelp dialog

IMPLEMENT_DYNAMIC(CDlgHelp, CDialogEx)

CDlgHelp::CDlgHelp(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgHelp::IDD, pParent)
{

}

CDlgHelp::~CDlgHelp()
{
}

void CDlgHelp::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgHelp, CDialogEx)
END_MESSAGE_MAP()


// CDlgHelp message handlers
