// FILE_PATH.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Calculator.h"
#include "FILE_PATH.h"
#include "afxdialogex.h"
#include "Print.h"
#include "Scan.h"
#include "Calculation.h"
#include "string"
#include "sstream"


// CFILE_PATH �Ի���

IMPLEMENT_DYNAMIC(CFILE_PATH, CDialogEx)

CFILE_PATH::CFILE_PATH(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, get_file_path(_T(""))
	, put_file_path(_T(""))
{

}

CFILE_PATH::~CFILE_PATH()
{
}

void CFILE_PATH::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, get_file_path);
	DDX_Text(pDX, IDC_EDIT2, put_file_path);
}


BEGIN_MESSAGE_MAP(CFILE_PATH, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &CFILE_PATH::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON_GET_FILE_PATH, &CFILE_PATH::OnBnClickedButtonGetFilePath)
	ON_BN_CLICKED(IDC_BUTTON_PUT_FILE_PATH, &CFILE_PATH::OnBnClickedButtonPutFilePath)
	ON_BN_CLICKED(ID_START, &CFILE_PATH::OnBnClickedStart)
END_MESSAGE_MAP()


// CFILE_PATH ��Ϣ�������


void CFILE_PATH::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CFILE_PATH::OnBnClickedButtonGetFilePath()
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

		get_file_path = pathName;

		UpdateData(FALSE);
	}
}


void CFILE_PATH::OnBnClickedButtonPutFilePath()
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

		put_file_path = pathName;

		UpdateData(FALSE);
	}
}


void CFILE_PATH::OnBnClickedStart()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	if (get_file_path.GetLength()!=0)
	{
		if (put_file_path.GetLength() != 0)
		{
			ifstream infile(get_file_path);
			ofstream outfile(put_file_path);
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
