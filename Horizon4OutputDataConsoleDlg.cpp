
// Horizon4OutputDataConsoleDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "Horizon4OutputDataConsole.h"
#include "Horizon4OutputDataConsoleDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CHorizon4OutputDataConsoleDlg 对话框



CHorizon4OutputDataConsoleDlg::CHorizon4OutputDataConsoleDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_HORIZON4OUTPUTDATACONSOLE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CHorizon4OutputDataConsoleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CHorizon4OutputDataConsoleDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CHorizon4OutputDataConsoleDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CHorizon4OutputDataConsoleDlg 消息处理程序

BOOL CHorizon4OutputDataConsoleDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CHorizon4OutputDataConsoleDlg::OnPaint()
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
HCURSOR CHorizon4OutputDataConsoleDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

#include "Horizon4OutputDataUDPServer.h"
Horizon4TelmetryData* h4tdata;
CEdit* edit[85];


int DlgUpdaterFlag = 0;
char* convertFormat = "iIfffffffffffffffffffffffffffiiiiffffffffffffffffffffiiiiifffffffffffffffffHBBBBBBbbb";

void DlgUpdaterWorker() {

	while (DlgUpdaterFlag) {
		int offset = 0;
		int count = 0;
		while (count<85) {
			CString str;
			switch (convertFormat[count]) {
				case 'f': {
					float* d = (float*)&Buffer[offset];
					offset += sizeof(float);
					str.Format(TEXT("%f"), *d);
					break;
				}
				case 'B': {
					byte* d = (byte*)&Buffer[offset];
					offset += sizeof(byte);
					str.Format(TEXT("%d"), (int)*d);
					break;
				}
				case 'b': {
					sbyte* d = (sbyte*)&Buffer[offset];
					offset += sizeof(sbyte);
					str.Format(TEXT("%d"), (int)*d);
					break;
				}
				case 'i': {
					int* d = (int*)&Buffer[offset];
					offset += sizeof(int);
					str.Format(TEXT("%d"),* d);
					break;
				}
				case 'I': {
					uint* d = (uint*)(&Buffer[offset]);
					offset += sizeof(uint);
					str.Format(TEXT("%d"), *d);
					break;
				}
				case 'H': {
					UInt16* d = (UInt16*)&Buffer[offset];
					offset += sizeof(UInt16);
					str.Format(TEXT("%d"), *d);
					break;
				}
			}
			edit[count++]->SetWindowText(str);
		}
		Sleep(40);
	}
}
void startDlgUpdater() {
	DlgUpdaterFlag = 1;
	_beginthread((_beginthread_proc_type)DlgUpdaterWorker, 0, NULL);
}

void endDlogUpdater() {
	DlgUpdaterFlag = 0;
}


void CHorizon4OutputDataConsoleDlg::OnBnClickedButton1()
{
	for (int i = 0; i < 85; i++) {
		edit[i] = (CEdit*)GetDlgItem(1001+i);
	}
	if (serverStartFlag == 0) {
		h4tdata = startServer();
		if (serverStartFlag == 1) {
			startDlgUpdater();
			((CButton*)GetDlgItem(IDC_BUTTON1))->SetWindowTextW(TEXT("close udp server"));
		}
	}
	else {
		serverStartFlag = 0;
		endDlogUpdater();
		((CButton*)GetDlgItem(IDC_BUTTON1))->SetWindowTextW(TEXT("start udp server"));
	}
}
