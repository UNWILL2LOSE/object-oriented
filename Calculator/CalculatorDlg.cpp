
// CalculatorDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Calculator.h"
#include "CalculatorDlg.h"
#include "afxdialogex.h"
#include "Print.h"
#include "Scan.h"
#include "Calculation.h"
#include "string"
#include "sstream"
#include "FILE_PATH.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#define VK_RETURN 0x0D
#define VK_ESCAPE 0x1B
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();
	

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChose();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	
END_MESSAGE_MAP()


// CCalculatorDlg �Ի���



CCalculatorDlg::CCalculatorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CALCULATOR_DIALOG, pParent)
	, input(_T(""))
	, demo(_T(""))
	, file_path(_T(""))
	, file_path_put(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}


void CCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_SHOW, input);
	DDX_Text(pDX, IDC_EDIT1, demo);
	DDX_Text(pDX, IDC_EDIT2, file_path);
	DDX_Text(pDX, IDC_EDIT3, file_path_put);
}

BEGIN_MESSAGE_MAP(CCalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_1, &CCalculatorDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON_2, &CCalculatorDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON_3, &CCalculatorDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON_4, &CCalculatorDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON_5, &CCalculatorDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON_6, &CCalculatorDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON_7, &CCalculatorDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON_8, &CCalculatorDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON_9, &CCalculatorDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON_0, &CCalculatorDlg::OnBnClickedButton0)
	ON_BN_CLICKED(IDC_BUTTON_POINT, &CCalculatorDlg::OnBnClickedButtonPoint)
	ON_BN_CLICKED(IDC_BUTTON_SUM, &CCalculatorDlg::OnBnClickedButtonSum)
	ON_BN_CLICKED(IDC_BUTTON_SUB, &CCalculatorDlg::OnBnClickedButtonSub)
	ON_BN_CLICKED(IDC_BUTTON_MUL, &CCalculatorDlg::OnBnClickedButtonMul)
	ON_BN_CLICKED(IDC_BUTTON_DIV, &CCalculatorDlg::OnBnClickedButtonDiv)
	ON_BN_CLICKED(IDC_BUTTON_LEFT_PAR, &CCalculatorDlg::OnBnClickedButtonLeftPar)
	ON_BN_CLICKED(IDC_BUTTON_RIGHT_PAR, &CCalculatorDlg::OnBnClickedButtonRightPar)
	ON_BN_CLICKED(IDC_BUTTON_EQUAL, &CCalculatorDlg::OnBnClickedButtonEqual)
	ON_BN_CLICKED(IDC_BUTTON_DEL, &CCalculatorDlg::OnBnClickedButtonDel)
	ON_EN_CHANGE(IDC_EDIT_SHOW, &CCalculatorDlg::OnEnChangeEditShow)
	ON_BN_CLICKED(IDC_BUTTON_GET, &CCalculatorDlg::OnBnClickedButtonGet)
	ON_BN_CLICKED(IDC_BUTTON_PUT_FILE, &CCalculatorDlg::OnBnClickedButtonPutFile)
	ON_BN_CLICKED(IDC_BUTTON_START, &CCalculatorDlg::OnBnClickedButtonStart)
	ON_COMMAND(ID_CHANGE, &CCalculatorDlg::OnChange)
	ON_COMMAND(ID_32778, &CCalculatorDlg::On32778)
END_MESSAGE_MAP()


// CCalculatorDlg ��Ϣ�������

BOOL CCalculatorDlg::OnInitDialog()
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
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CCalculatorDlg::OnPaint()
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
HCURSOR CCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCalculatorDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	input += "1";
	demo += "1";
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	input += "2";
	demo += "2";
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	input += "3";
	demo += "3";
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	input += "4";
	demo += "4";
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	input += "5";
	demo += "5";
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButton6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	input += "6";
	demo += "6";
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButton7()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	input += "7";
	demo += "7";
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButton8()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	input += "8";
	demo += "8";
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButton9()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	input += "9";
	demo += "9";
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButton0()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	input += "0";
	demo += "0";
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButtonPoint()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	input += ".";
	demo += ".";
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButtonSum()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	input += "+";
	demo += "+";
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButtonSub()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	input += "-";
	demo += "-";
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButtonMul()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	input += "��";
	demo += "*";
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButtonDiv()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	input += "��";
	demo += "/";
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButtonLeftPar()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	input += "(";
	demo += "(";
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButtonRightPar()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	input += ")";
	demo += ")";
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButtonEqual()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	Scan s;
	Calculation c;
	queue<string> temp = s.ToStringQueue(demo.GetBuffer());
	input.ReleaseBuffer();
	c.sortStack(temp);
	stringstream stream;
	stream << c.solve();
	string result;
	stream >> result;
	input = result.c_str();
	demo = result.c_str();
	UpdateData(FALSE);
}





void CCalculatorDlg::OnBnClickedButtonDel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	input.Delete(input.GetLength() - 1, input.GetLength());
	demo.Delete(demo.GetLength() - 1, demo.GetLength());
	UpdateData(FALSE);
}




BOOL CCalculatorDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
	
	
	if (pMsg->message == WM_KEYDOWN   &&   pMsg->wParam == VK_ESCAPE)
	{
		if (input.GetLength()>0)
		{
			UpdateData(TRUE);
			input.Delete(0, input.GetLength());
			demo.Delete(0, demo.GetLength());
			UpdateData(FALSE);
		}
		return TRUE;
	}
	if (pMsg->message == WM_KEYDOWN   &&   pMsg->wParam == VK_RETURN)
	{
		if (input.GetLength()!=0)
		{
			UpdateData(TRUE);
			Scan s;
			Calculation c;
			queue<string> temp = s.ToStringQueue(demo.GetBuffer());
			input.ReleaseBuffer();
			c.sortStack(temp);
			stringstream stream;
			stream << c.solve();
			string result;
			stream >> result;
			input = result.c_str();
			demo = result.c_str();
			UpdateData(FALSE);
		}
		else
		{
			MessageBox("��������ʽ!!!");
		}
		return TRUE;
	}
	
	
	if (pMsg->message == WM_KEYDOWN   &&   pMsg->wParam == VK_BACK)
	{
		if (input.GetLength() > 0)
		{
			UpdateData(TRUE);
			input.Delete(input.GetLength() - 1, input.GetLength());
			demo.Delete(demo.GetLength() - 1, demo.GetLength());
			UpdateData(FALSE);
		}
	}
	
	return CDialogEx::PreTranslateMessage(pMsg);
}



void CCalculatorDlg::OnEnChangeEditShow()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CCalculatorDlg::OnBnClickedButtonGet()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	char szFilters[] =
		"MyType Files (*.txt)|*.txt|All Files (*.*)|*.*||";

	// Create an Open dialog; the default file name extension is ".my". 
	CFileDialog fileDlg(TRUE, "txt", "*.txt",
		OFN_FILEMUSTEXIST | OFN_HIDEREADONLY, szFilters, this);

	// Display the file dialog. When user clicks OK, fileDlg.DoModal() 
	// returns IDOK. 
	if (fileDlg.DoModal() == IDOK)
	{
		CString pathName = fileDlg.GetPathName();

		file_path = pathName;

		UpdateData(FALSE);
	}
}


void CCalculatorDlg::OnBnClickedButtonPutFile()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	char szFilters[] =
		"MyType Files (*.txt)|*.txt|All Files (*.*)|*.*||";

	// Create an Open dialog; the default file name extension is ".my". 
	CFileDialog fileDlg(TRUE, "txt", "*.txt",
		OFN_FILEMUSTEXIST | OFN_HIDEREADONLY, szFilters, this);

	// Display the file dialog. When user clicks OK, fileDlg.DoModal() 
	// returns IDOK. 
	if (fileDlg.DoModal() == IDOK)
	{
		CString pathName = fileDlg.GetPathName();

		file_path_put = pathName;

		UpdateData(FALSE);
	}
}


void CCalculatorDlg::OnBnClickedButtonStart()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	if (file_path)
	{
		if (file_path_put)
		{
			ifstream infile(file_path);
			ofstream outfile(file_path_put);
			string getArgv;
			if (!infile)
			{
				cout << "�ļ�������" << endl;
			}
			else
			{
				while (getline(infile, getArgv))
				{
					Scan *s = new Scan();
					Calculation *c = new Calculation();
					queue<string> temp = s->ToStringQueue(getArgv);
					c->sortStack(temp);
					double ans = c->solve();
					outfile << ans;
					outfile << "\n";
					delete c; c = NULL;
				}
			}
			infile.close();
			outfile.close();
			MessageBox("�������");
		}
		else
		{
			MessageBox("����ļ�Ϊ��!!!");
		}
	}
	else 
	{
		MessageBox("�����ļ�Ϊ��!!!");
	}

}








void CCalculatorDlg::OnChange()
{

	// TODO: �ڴ���������������
	INT_PTR nRes;             // ���ڱ���DoModal�����ķ���ֵ   

	CFILE_PATH tipDlg;           // ����Ի�����CTipDlg��ʵ��   
	nRes = tipDlg.DoModal();  // �����Ի���   
}


void CCalculatorDlg::On32778()
{
	// TODO: �ڴ���������������
	MessageBox("���������ǲ���ɵ������");
}
