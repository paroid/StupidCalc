
// mfcDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "mfc.h"
#include "mfcDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include "calc.h"
#include "DlgHelp.h"

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
public:
//	virtual BOOL PreTranslateMessage(MSG* pMsg);
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CmfcDlg �Ի���




CmfcDlg::CmfcDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CmfcDlg::IDD, pParent)
	, m_Edit1(_T(""))
	, m_Edit2(_T(""))
	, hisCount(0)
	, hisCur(0)
	, Ftotal(0)
{
	//m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_hIcon = AfxGetApp()->LoadIconW(IDI_ICON1);

	m_Edit1.LoadString(IDS_STRING102);
	m_Edit2.LoadStringW(IDS_STRING103);
	for(int i=0;i<FUNC;i++){
		m_Func[i].change(" ");
		m_Fname[i].Empty();
		m_Ftype[i] = TRUE;
	}
}

void CmfcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_Edit1);
	DDV_MaxChars(pDX, m_Edit1, 200);
	DDX_Text(pDX, IDC_EDIT2, m_Edit2);
}

BEGIN_MESSAGE_MAP(CmfcDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CmfcDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDOK, &CmfcDlg::OnBnClickedOk)
//	ON_WM_CHAR()
	ON_BN_CLICKED(IDC_BUTTON2, &CmfcDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CmfcDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CmfcDlg ��Ϣ�������

BOOL CmfcDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX,strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CmfcDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CmfcDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CmfcDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CmfcDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here

    /*int strLength = m_Edit1.GetLength() + 1;
    char *pChar = new char[strLength];
    strncpy(pChar, m_Edit1, strLength);*/
	//char *exp = (LPCTSTR)m_Edit1;

	UpdateData();
	CString strTmp;
	strTmp.LoadString(IDS_STRING102);
	if(m_Edit1 ==strTmp){
		GetDlgItem(IDC_EDIT1)->SetFocus();
		SendDlgItemMessage(IDC_EDIT1, EM_SETSEL,0,-1);
		return;
	}

	m_Edit2.Empty();
	char pstr[MAX],ctmp[MAX];
	CString cstr;
	calc Tcal;
	double res = 0,x=0,y=0;
	int len = m_Edit1.GetLength();
	bool isF=FALSE;
	int mark=0,i=0,j=0;
	if(m_Edit1.IsEmpty()){
		m_Edit2.LoadStringW(IDS_STRING103);
		goto POS;
	}
	for(i=0;i<len;i++){
		if(':' == m_Edit1[i]){
			isF=TRUE;
			mark=i;
		}
		if(m_Edit1[i] != ' ')
			pstr[j++]=m_Edit1[i];
	}
	pstr[len=j]='\0';
	if(!strcmp(pstr,"clear")){   //clear
		for(i=0;i<FUNC;i++){
			m_Func[i].change(" ");
			m_Fname[i].Empty();
			Ftotal = 0;
		}
		m_Edit2 = "All Function clear !";
	}
	else if(!strcmp(pstr,"allfunc")){
		for(i=0;i<Ftotal && !m_Fname[i].IsEmpty();i++){
			m_Edit2 += m_Fname[i];
			m_Edit2 += m_Ftype[i]?"(x)= ":"(x,y)= ";
			m_Edit2 += m_Func[i].esp;
			m_Edit2 += "\r\n";
		}
		cstr += "Total: ";
		char chtmp[100];
		itoa(i,chtmp,10);
		cstr += chtmp;
		cstr += "\r\n";
		m_Edit2.Insert(0,cstr);
	}
	else if('?' == pstr[0]){
		cstr.Empty();
		for(i=1;i<len;i++)
			cstr += pstr[i];
		for(i=0;i<Ftotal && !m_Fname[i].IsEmpty() && cstr!=m_Fname[i] ;i++);
		if(cstr == m_Fname[i]){
			m_Edit2 += cstr;
			m_Edit2 += m_Ftype[i]?"(x)= ":"(x,y)= ";
			m_Edit2 += m_Func[i].esp;
			m_Edit2 += "\r\n";
		}
		else{
			m_Edit2 += "No Function Named:\r\n";
			m_Edit2 +=cstr;
			m_Edit2 +="()";
		}
	}
	else{
		if(pstr[0]=='f'){    // f(x,y)

			if(isF){
				cstr.Empty();
				for(i=0;i<mark;i++)
					cstr += pstr[i];
				for(i=0;i<Ftotal;i++)
					if(m_Fname[i] == cstr){
						j=i;
						break;
					}
				if(i == Ftotal){
					j=Ftotal++;
					m_Fname[j] = cstr;
					if(128 == Ftotal){
						m_Edit2 = "128 Functions All Occupied ��     Next Will OverWrite From Start";
						Ftotal = 0;
					}
				}
				m_Func[j].change(&pstr[mark+1]);
				m_Edit2 = m_Fname[j];
				for(i=mark+1;i<len;i++)
					if(pstr[i] == 'y')
						break;
				m_Ftype[j] = (i==len);
				m_Edit2 += i==len?"(x)= ":"(x,y)= ";
				m_Edit2 += &pstr[mark+1];	
			}
			else{
				i=0;
				j=0;
				for(i=0;i<len;i++){
					if('(' == pstr[i]){
						mark = i;
						break;
					}
					ctmp[i] = pstr[i];
				}
				ctmp[i++]='\0';
				for(i=0;i<Ftotal;i++){
					if(m_Fname[i] == ctmp)
						break;
				}
				if( i == Ftotal){
					m_Edit2 = "No Function Named:\r\n";
					m_Edit2 += ctmp;
					m_Edit2 += "() ";
					goto POS;
				}
				hisCur = i;
				i=mark + 1;
				while(pstr[i] != ',' && i<len-1){
					ctmp[j++]=pstr[i++];
				}
				ctmp[j]='\0';
				Tcal.change(ctmp);
				x=Tcal.cal();
				j=0;
				if(',' == pstr[i])	
					i++;
				while(i<len-1){
					ctmp[j++]=pstr[i++];
				}
				ctmp[j]='\0';
				if(j){
					Tcal.change(ctmp);
					y=Tcal.cal();
				}
				res= m_Func[hisCur].cal(x,y);
			}
		}
		else{
			Tcal.change(pstr);
			res = Tcal.cal(2,3);
		}
	
		if(!isF){
			sprintf(pstr,"%lf",res);
			len = strlen(pstr);
			for(i=len-1;i>0; i--){
				if('0'!=pstr[i]&&'.'!=pstr[i])
					break;
				if('.'==pstr[i]){
					pstr[i]='\0';
					break;
				}
				pstr[i]='\0';
			}
			m_Edit2 += pstr;
		}
	}

POS:
	UpdateData(FALSE);
	GetDlgItem(IDC_EDIT1)->SetFocus();
	SendDlgItemMessage(IDC_EDIT1, EM_SETSEL,0,-1);
	//hisInput[hisCount++%FUNC] = pstr;
	//hisCur = hisCount;
}


void CmfcDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	OnBnClickedButton1();	
	//CDialogEx::OnOK();
}


//void CmfcDlg::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
//{
//	// TODO: Add your message handler code here and/or call default
//	if( 24 == nChar){
//		hisCur = (hisCur+FUNC)%FUNC;
//		m_Edit1 = hisInput[hisCur - 1];
//		hisCur--;
//		UpdateData(FALSE);
//	}
//	else if( 25 == nChar){
//		hisCur = (hisCur+FUNC)%FUNC;
//		m_Edit1 = hisInput[hisCur + 1];
//		hisCur++;
//	}
//	else{
//		GetDlgItem(IDC_EDIT1)->SetFocus();
//		SendDlgItemMessage(IDC_EDIT1, EM_SETSEL,0,-1);
//	}
//	CDialogEx::OnChar(nChar, nRepCnt, nFlags);
//}


void CmfcDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	m_Edit2.LoadStringW(IDS_STRING103);
	UpdateData(FALSE);
	CAboutDlg dlgAbout;
	dlgAbout.DoModal();
}


void CmfcDlg::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
	m_Edit2.LoadStringW(IDS_STRING103);
	UpdateData(FALSE);
	CDlgHelp dlg;
	dlg.DoModal();
}


//BOOL CAboutDlg::PreTranslateMessage(MSG* pMsg)
//{
//	// TODO: Add your specialized code here and/or call the base class
//	
//	return CDialogEx::PreTranslateMessage(pMsg);
//}


BOOL CmfcDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: Add your specialized code here and/or call the base class
	/*if(pMsg->message == WM_KEYDOWN){
		if( 24 == pMsg->wParam){
			hisCur = (hisCur+32)%32;
			m_Edit1 = hisInput[hisCur - 1];
			hisCur--;
			UpdateData(FALSE);
		}
		else if( 25 == pMsg->wParam){
			hisCur = (hisCur+32)%32;
			m_Edit1 = hisInput[hisCur + 1];
			hisCur++;
		}
	}*/
	return CDialogEx::PreTranslateMessage(pMsg);
}
