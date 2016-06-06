#pragma once


// CFILE_PATH 对话框

class CFILE_PATH : public CDialogEx
{
	DECLARE_DYNAMIC(CFILE_PATH)

public:
	CFILE_PATH(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CFILE_PATH();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	CString get_file_path;
	CString put_file_path;
	afx_msg void OnBnClickedButtonGetFilePath();
	afx_msg void OnBnClickedButtonPutFilePath();
	afx_msg void OnBnClickedStart();
};
