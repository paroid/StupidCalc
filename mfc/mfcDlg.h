
// mfcDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcoll.h"

#include "calc.h"
// CmfcDlg �Ի���
class CmfcDlg : public CDialogEx
{
// ����
public:
	CmfcDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFC_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	CString m_Edit1;
	CString m_Edit2;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedOk();
	CString hisInput[FUNC];
	int hisCount;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	int hisCur;
	calc m_Func[FUNC];
	CString m_Fname[FUNC];
	bool m_Ftype[FUNC];
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	int Ftotal;
};
