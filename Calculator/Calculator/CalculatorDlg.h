
// CalculatorDlg.h : ͷ�ļ�
//

#pragma once
#include "string.h"


// CCalculatorDlg �Ի���
class CCalculatorDlg : public CDialogEx
{
// ����
public:
	CCalculatorDlg(CWnd* pParent = NULL);	// ��׼���캯��


// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULATOR_DIALOG };
#endif

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
	afx_msg void OnBnClickedButton1();
	CString input;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton0();
	afx_msg void OnBnClickedButtonPoint();
	afx_msg void OnBnClickedButtonSum();
	afx_msg void OnBnClickedButtonSub();
	afx_msg void OnBnClickedButtonMul();
	afx_msg void OnBnClickedButtonDiv();
	afx_msg void OnBnClickedButtonLeftPar();
	afx_msg void OnBnClickedButtonRightPar();
	afx_msg void OnBnClickedButtonEqual();
	afx_msg void OnBnClickedButtonDel();
	CString demo;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CString file_path;
	afx_msg void OnBnClickedButtonWave();
	afx_msg void OnEnChangeEditShow();
	afx_msg void OnBnClickedButtonGet();
	afx_msg void OnBnClickedButtonPutFile();
	CString file_path_put;
	afx_msg void OnBnClickedButtonStart();
};
