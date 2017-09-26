#pragma once
#include <atlstr.h>

/// �¼�֪ͨ��Ӧ����Ϣ
#define WM_TRADEEVENT_INITRETURN		WM_USER + 900
#define WM_TRADEEVENT_LOGINRETURN		WM_USER + 901
#define WM_TRADEEVENT_ORDEROK			WM_USER + 902
#define WM_TRADEEVENT_ORDERSUCCESS		WM_USER + 903
#define WM_TRADEEVENT_ORDERERROR		WM_USER + 904
#define WM_TRADEEVENT_STOCKQUOTE		WM_USER + 905
#define WM_TRADEEVENT_SERVERERRVER		WM_USER + 906
#define WM_TRADEEVENT_CHANGESERVER		WM_USER + 907

// �����¼���������
class CStockComEvent : 
	public CComObjectRoot,
	//ʵ�ֽ����¼�֪ͨ�ӿ�
	public _ITradeEvents
{
protected:

	/// �ص��������
	USHORT			m_nTradeIndex;

	/// ������
	HWND			m_hParentWnd;

	/// �������ݻ���
	ITradeRecordPtr	m_spiTradeRecord;

	/// ��������
	CString			m_strErrInfo;

public:
	CStockComEvent()
		:m_hParentWnd(NULL)
		,m_spiTradeRecord(NULL)
		,m_nTradeIndex(0)
	{
	}

	~CStockComEvent()
	{
		m_spiTradeRecord = NULL;
	}

	void SetCallPara(HWND hParentWnd,USHORT nIndex)
	{
		if(NULL != hParentWnd)
		{
			if(!::IsWindow(hParentWnd))
				return;
		}
		m_nTradeIndex = nIndex;
		m_hParentWnd = hParentWnd;
	}

	ITradeRecordPtr GetReqData()
	{
		return m_spiTradeRecord;
	}

BEGIN_COM_MAP(CStockComEvent)
	COM_INTERFACE_ENTRY(_ITradeEvents)
END_COM_MAP()

public:

	STDMETHODIMP GetTypeInfoCount(UINT*)
    {
       return E_NOTIMPL;
    }

    STDMETHODIMP GetTypeInfo( UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo)
    { 
       return E_NOTIMPL;
    }

    STDMETHODIMP GetIDsOfNames( REFIID riid,LPOLESTR *rgszNames,UINT cNames,
                    LCID lcid,DISPID *rgDispId)
    { 
      return E_NOTIMPL;
    }

	STDMETHOD(Invoke)(DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,
               VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
	
	//  _ITradeEvents
	/// ��ʼ���ӿڽ��֪ͨ
	STDMETHOD(InitEvent)(IDispatch* piTrade,VARIANT_BOOL bOK);
	/// ��¼���������֪ͨ
	STDMETHOD(LoginEvent)(IDispatch* piTrade,USHORT nTradeID,BSTR bstrHost,USHORT nPort,VARIANT_BOOL bOK);
	/// ����ί�гɹ��ر�
	STDMETHOD(OrderOKEvent)(ULONG nReqID,EZMExchangeType eExchangeType,IDispatch* piRecordInfo);
	/// ����ί��ʧ�ܻر�
	STDMETHOD(OrderErrEvent)(ULONG nReqID,BSTR bstrErrInfo);
	/// ��ѯָ����Ʊʵʱ5������ر�
	STDMETHOD(StockQuoteEvent)(ULONG nReqID,BSTR bstrCode,IDispatch* piRecordInfo);
	/// ����ί�гɽ��ر�
	STDMETHOD(OrderSuccessEvent)(ULONG nOrderID,BSTR bstrJson);

	/// ����������֪ͨ
	STDMETHOD(ServerErrEvent)(USHORT nTradeID,ULONG nReqID);
	/// �������л�֪ͨ�������������
	STDMETHOD(ServerChangedEvent)(USHORT nPreTradeID,USHORT nCurTradeID);
};