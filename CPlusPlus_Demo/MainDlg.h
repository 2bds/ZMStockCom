// MainDlg.h : interface of the CMainDlg class
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#include "StockComEvent.h"

class CMainDlg : public CAxDialogImpl<CMainDlg>
{
protected:

	/// StockTrade����ӿ����飬��Ҫ����������������Ҳ�������б�������
	IStockTradePtr		m_spiTrade[2];

	/// ���ײ�ѯ����
	CComboBox		m_wndTradeList;
	/// ��ʷ��������
	CComboBox		m_wndHistoryList;
	/// ȯ������
	CComboBox		m_wndBrokerType;
	/// �˺�����
	CComboBox		m_wndAccountType;

	/// ���׽ӿ��¼�COOKIE����
	DWORD							m_nTradeEventCookie[2];
	/// ���׽ӿ��¼���������
	CComObject<CStockComEvent>*		m_spiTradeClientEvent[2];

	/// �����¼�֪ͨ
	void AdviseTradeClient(int nIndex);
	/// �Ͽ��¼�֪ͨ
	void UnAdviseTradeClient(int nIndex);

	/// �ͷ����
	void ReleaseCom();

	///��ý�������
	ITradeRecordPtr GetCategoryData(EZMStockQueryType eCategoryType);
	///�����ʷί������
	ITradeRecordPtr GetHisData(EZMHisOrderType eCategoryType);

	/// ���ָ����Ʊ��ǰʵʱ����
	ITradeRecordPtr GetStockMarket(const CString& strStockCode);

public:
	enum { IDD = IDD_MAINDLG };

	BEGIN_MSG_MAP(CMainDlg)
		MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)

		MESSAGE_HANDLER(WM_TRADEEVENT_INITRETURN, OnInitReturn)
		MESSAGE_HANDLER(WM_TRADEEVENT_LOGINRETURN, OnLoginReturn)
		MESSAGE_HANDLER(WM_TRADEEVENT_ORDEROK, OnOrderOK)
		MESSAGE_HANDLER(WM_TRADEEVENT_ORDERERROR, OnOrderError)
		MESSAGE_HANDLER(WM_TRADEEVENT_STOCKQUOTE, OnStockQuote)
		MESSAGE_HANDLER(WM_TRADEEVENT_CHANGESERVER, OnChangeServer)
		MESSAGE_HANDLER(WM_TRADEEVENT_ORDERSUCCESS, OnOrderSuccess)

		COMMAND_ID_HANDLER(IDOK, OnOK)
		COMMAND_ID_HANDLER(IDCANCEL, OnCancel)

		COMMAND_HANDLER(IDC_BUTTON_INIT, BN_CLICKED, OnBnClickedInit)
		COMMAND_HANDLER(IDC_BUTTON_UNINIT, BN_CLICKED, OnBnClickedUnInit)
		COMMAND_HANDLER(IDC_BUTTON_GETTRADE, BN_CLICKED, OnBnClickedGetTradeData)
		COMMAND_HANDLER(IDC_BUTTON_FIVEMARKET, BN_CLICKED, OnBnClickedGetFiveMarket)
		COMMAND_HANDLER(IDC_BUTTON_HISDATA, BN_CLICKED, OnBnClickedGetHisData)
		COMMAND_HANDLER(IDC_BUTTON_BUY, BN_CLICKED, OnBnClickedBuy)
		COMMAND_HANDLER(IDC_BUTTON_SELL, BN_CLICKED, OnBnClickedSell)

		COMMAND_HANDLER(IDC_BUTTON_NEWSTOCK, BN_CLICKED, OnBnClickedIPO)
	END_MSG_MAP()

// Handler prototypes (uncomment arguments if needed):
//	LRESULT MessageHandler(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
//	LRESULT CommandHandler(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
//	LRESULT NotifyHandler(int /*idCtrl*/, LPNMHDR /*pnmh*/, BOOL& /*bHandled*/)

	LRESULT OnInitDialog(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	LRESULT OnOK(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnCancel(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/);

	LRESULT OnInitReturn(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	LRESULT OnLoginReturn(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	LRESULT OnOrderOK(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	LRESULT OnOrderError(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	LRESULT OnStockQuote(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	LRESULT OnChangeServer(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	LRESULT OnOrderSuccess(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);

	LRESULT OnBnClickedInit(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnBnClickedGetFiveMarket(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnBnClickedGetTradeData(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnBnClickedGetHisData(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnBnClickedBuy(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnBnClickedSell(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);

	LRESULT OnBnClickedUnInit(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnBnClickedIPO(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
};
