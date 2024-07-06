
// Calculator++Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Calculator++.h"
#include "Calculator++Dlg.h"
#include "afxdialogex.h"
#include <cmath>
#include <stack>
#include <string>
#include <sstream>
#include <vector>
#include <map>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &CAboutDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CCalculatorDlg dialog



CCalculatorDlg::CCalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULATOR_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON9, &CCalculatorDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CCalculatorDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &CCalculatorDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON5, &CCalculatorDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CCalculatorDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CCalculatorDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON1, &CCalculatorDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CCalculatorDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON13, &CCalculatorDlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON2, &CCalculatorDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON14, &CCalculatorDlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON12, &CCalculatorDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON15, &CCalculatorDlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON16, &CCalculatorDlg::OnBnClickedButton16)
	ON_BN_CLICKED(IDC_BUTTON8, &CCalculatorDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON4, &CCalculatorDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON17, &CCalculatorDlg::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON18, &CCalculatorDlg::OnBnClickedButton18)
	ON_BN_CLICKED(IDC_BUTTON19, &CCalculatorDlg::OnBnClickedButton19)
END_MESSAGE_MAP()


// CCalculatorDlg message handlers

BOOL CCalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	CFont m_font;
	m_font.CreatePointFont(220, _T("Arial"));

	GetDlgItem(IDC_EDIT1)->SetFont(&m_font);
	for (int i = IDC_BUTTON1; i <= IDC_BUTTON19; ++i)
	{
		GetDlgItem(i)->SetFont(&m_font);
	}

	SetWindowText(_T("Calculator++"));


	return TRUE;  // return TRUE  unless you set the focus to a control
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCalculatorDlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCalculatorDlg::OnBnClickedButton9()
{
	CString text;
	GetDlgItemText(IDC_EDIT1, text);
	CString newText = _T("1");			// Change this to the button equivlent number
	text += newText;
	SetDlgItemText(IDC_EDIT1, text);
}


void CCalculatorDlg::OnBnClickedButton10()
{
	// TODO: Add your control notification handler code here
	CString text;
	GetDlgItemText(IDC_EDIT1, text);
	CString newText = _T("2");			// Change this to the button equivlent number
	text += newText;
	SetDlgItemText(IDC_EDIT1, text);
}


void CCalculatorDlg::OnBnClickedButton11()
{
	// TODO: Add your control notification handler code here
	CString text;
	GetDlgItemText(IDC_EDIT1, text);
	CString newText = _T("3");			// Change this to the button equivlent number
	text += newText;
	SetDlgItemText(IDC_EDIT1, text);
}


void CCalculatorDlg::OnBnClickedButton5()
{
	// TODO: Add your control notification handler code here
	CString text;
	GetDlgItemText(IDC_EDIT1, text);
	CString newText = _T("4");			// Change this to the button equivlent number
	text += newText;
	SetDlgItemText(IDC_EDIT1, text);
}


void CCalculatorDlg::OnBnClickedButton6()
{
	// TODO: Add your control notification handler code here
	CString text;
	GetDlgItemText(IDC_EDIT1, text);
	CString newText = _T("5");			// Change this to the button equivlent number
	text += newText;
	SetDlgItemText(IDC_EDIT1, text);
}


void CCalculatorDlg::OnBnClickedButton7()
{
	// TODO: Add your control notification handler code here
	CString text;
	GetDlgItemText(IDC_EDIT1, text);
	CString newText = _T("6");			// Change this to the button equivlent number
	text += newText;
	SetDlgItemText(IDC_EDIT1, text);
}


void CCalculatorDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	CString text;
	GetDlgItemText(IDC_EDIT1, text);
	CString newText = _T("7");			// Change this to the button equivlent number
	text += newText;
	SetDlgItemText(IDC_EDIT1, text);
}


void CAboutDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	CString text;
	GetDlgItemText(IDC_EDIT1, text);
	CString newText = _T("8");			// Change this to the button equivlent number
	text += newText;
	SetDlgItemText(IDC_EDIT1, text);
}


void CCalculatorDlg::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
	CString text;
	GetDlgItemText(IDC_EDIT1, text);
	CString newText = _T("9");			// Change this to the button equivlent number
	text += newText;
	SetDlgItemText(IDC_EDIT1, text);
}


void CCalculatorDlg::OnBnClickedButton13()
{
	// TODO: Add your control notification handler code here
	CString text;
	GetDlgItemText(IDC_EDIT1, text);
	CString newText = _T(".");			// Change this to the button equivlent number
	text += newText;
	SetDlgItemText(IDC_EDIT1, text);
}


void CCalculatorDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	CString text;
	GetDlgItemText(IDC_EDIT1, text);
	CString newText = _T("8");			// Change this to the button equivlent number
	text += newText;
	SetDlgItemText(IDC_EDIT1, text);
}


void CCalculatorDlg::OnBnClickedButton14()
{
	// TODO: Add your control notification handler code here
	CString text;
	GetDlgItemText(IDC_EDIT1, text);
	CString newText = _T("0");			// Change this to the button equivlent number
	text += newText;
	SetDlgItemText(IDC_EDIT1, text);

}


void CCalculatorDlg::OnBnClickedButton12()
{
	// TODO: Add your control notification handler code here
	CString text;
	GetDlgItemText(IDC_EDIT1, text);
	CString newText = _T("/");			// Change this to the button equivlent number
	text += newText;
	SetDlgItemText(IDC_EDIT1, text);
}


void CCalculatorDlg::OnBnClickedButton15()
{
	// TODO: Add your control notification handler code here
	CString text;
	GetDlgItemText(IDC_EDIT1, text);
	CString newText = _T("+");			// Change this to the button equivlent number
	text += newText;
	SetDlgItemText(IDC_EDIT1, text);
}


void CCalculatorDlg::OnBnClickedButton16()
{
	// TODO: Add your control notification handler code here
	CString text;
	GetDlgItemText(IDC_EDIT1, text);
	CString newText = _T("-");			// Change this to the button equivlent number
	text += newText;
	SetDlgItemText(IDC_EDIT1, text);
}


void CCalculatorDlg::OnBnClickedButton8()
{
	// TODO: Add your control notification handler code here
	CString text;
	GetDlgItemText(IDC_EDIT1, text);
	CString newText = _T("*");			// Change this to the button equivlent number
	text += newText;
	SetDlgItemText(IDC_EDIT1, text);
}


void CCalculatorDlg::OnBnClickedButton4()
{
	// TODO: Add your control notification handler code here
	CString text;
	GetDlgItemText(IDC_EDIT1, text);
	CString newText = _T("^");			// Change this to the button equivlent number
	text += newText;
	SetDlgItemText(IDC_EDIT1, text);
}


void CCalculatorDlg::OnBnClickedButton17()
{
	CString currentText;
	GetDlgItemText(IDC_EDIT1, currentText);

	// Check if the text is not empty
	if (!currentText.IsEmpty()) {
		// Remove the last character
		currentText = currentText.Left(currentText.GetLength() - 1);

		// Set the updated text back to the edit control
		SetDlgItemText(IDC_EDIT1, currentText);
	}
	else {
		AfxMessageBox(_T("The edit control is already empty."));
	}
}


void CCalculatorDlg::OnBnClickedButton18()
{
	// TODO: Add your control notification handler code here
	CString text;
	text = "";
	SetDlgItemText(IDC_EDIT1, text);
}


void CCalculatorDlg::OnBnClickedButton19()
{
	// Get the current text from the edit control
	CString currentText;
	GetDlgItemText(IDC_EDIT1, currentText);

	// Convert CString to std::string
	std::string expression = CT2A(currentText);

	// Helper function to split expression into tokens
	auto tokenize = [](const std::string& exp) {
		std::vector<std::string> tokens;
		std::string num;
		for (char c : exp) {
			if (isdigit(c) || c == '.') {
				num += c;
			}
			else {
				if (!num.empty()) {
					tokens.push_back(num);
					num.clear();
				}
				tokens.push_back(std::string(1, c));
			}
		}
		if (!num.empty()) {
			tokens.push_back(num);
		}
		return tokens;
		};

	auto getPrecedence = [](char op) {
		switch (op) {
		case '+': case '-':
			return 1;
		case '*': case '/':
			return 2;
		case '^':
			return 3;
		default:
			return 0;
		}
	};

	// Helper function to perform an operation
	auto applyOp = [](double a, double b, char op) {
		switch (op) {
			case '+': 
				return a + b;
			case '-': 
				return a - b;
			case '*': 
				return a * b;
			case '/': 
				return a / b;
			case '^': 
				return std::pow(a, b);
			default: 
				return a - a;
		}
	};

	// Convert infix expression to RPN using Shunting Yard algorithm
	auto toRPN = [&](const std::vector<std::string>& tokens) {
		std::vector<std::string> output;
		std::stack<char> ops;
		for (const auto& token : tokens) {
			if (isdigit(token[0]) || (token[0] == '.' && token.length() > 1)) {
				output.push_back(token);
			}
			else if (token == "(") {
				ops.push('(');
			}
			else if (token == ")") {
				while (!ops.empty() && ops.top() != '(') {
					output.push_back(std::string(1, ops.top()));
					ops.pop();
				}
				ops.pop();
			}
			else {
				char op = token[0];
				while (!ops.empty() && getPrecedence(ops.top()) >= getPrecedence(op)) {
					output.push_back(std::string(1, ops.top()));
					ops.pop();
				}
				ops.push(op);
			}
		}
		while (!ops.empty()) {
			output.push_back(std::string(1, ops.top()));
			ops.pop();
		}
		return output;
		};

	// Evaluate RPN expression
	auto evaluateRPN = [&](const std::vector<std::string>& rpn) {
		std::stack<double> values;
		for (const auto& token : rpn) {
			if (isdigit(token[0]) || (token[0] == '.' && token.length() > 1)) {
				values.push(std::stod(token));
			}
			else {
				double b = values.top(); values.pop();
				double a = values.top(); values.pop();
				values.push(applyOp(a, b, token[0]));
			}
		}
		return values.top();
		};

	// Tokenize the expression
	auto tokens = tokenize(expression);

	// Convert the tokens to RPN
	auto rpn = toRPN(tokens);

	// Evaluate the RPN expression
	double result = evaluateRPN(rpn);

	// Convert the result to CString
	CString resultStr;
	resultStr.Format(_T("%g"), result);

	// Set the result back to the edit control
	SetDlgItemText(IDC_EDIT1, resultStr);
}