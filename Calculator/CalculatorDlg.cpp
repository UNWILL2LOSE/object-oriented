
// CalculatorDlg.cpp : 实现文件
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


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();
	

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CCalculatorDlg 对话框



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


// CCalculatorDlg 消息处理程序

BOOL CCalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCalculatorDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	input += "1";
	demo += "1";
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	input += "2";
	demo += "2";
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	input += "3";
	demo += "3";
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	input += "4";
	demo += "4";
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	input += "5";
	demo += "5";
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	input += "6";
	demo += "6";
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	input += "7";
	demo += "7";
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	input += "8";
	demo += "8";
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	input += "9";
	demo += "9";
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButton0()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	input += "0";
	demo += "0";
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButtonPoint()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	input += ".";
	demo += ".";
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButtonSum()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	input += "+";
	demo += "+";
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButtonSub()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	input += "-";
	demo += "-";
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButtonMul()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	input += "×";
	demo += "*";
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButtonDiv()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	input += "÷";
	demo += "/";
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButtonLeftPar()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	input += "(";
	demo += "(";
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButtonRightPar()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	input += ")";
	demo += ")";
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButtonEqual()
{
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	input.Delete(input.GetLength() - 1, input.GetLength());
	demo.Delete(demo.GetLength() - 1, demo.GetLength());
	UpdateData(FALSE);
}




BOOL CCalculatorDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	
	
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
			MessageBox("请输入表达式!!!");
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
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CCalculatorDlg::OnBnClickedButtonGet()
{
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码
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
				cout << "文件不存在" << endl;
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
			MessageBox("运算完成");
		}
		else
		{
			MessageBox("输出文件为空!!!");
		}
	}
	else 
	{
		MessageBox("输入文件为空!!!");
	}

}








void CCalculatorDlg::OnChange()
{

	// TODO: 在此添加命令处理程序代码
	INT_PTR nRes;             // 用于保存DoModal函数的返回值   

	CFILE_PATH tipDlg;           // 构造对话框类CTipDlg的实例   
	nRes = tipDlg.DoModal();  // 弹出对话框   
}


void CCalculatorDlg::On32778()
{
	// TODO: 在此添加命令处理程序代码
	MessageBox("！！！你是不是傻！！！");
}
