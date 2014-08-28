// UserName.h : Declaration of the CUserName

#pragma once
#include "resource.h"       // main symbols

#include "SignonName.h"


// CUserName

class ATL_NO_VTABLE CUserName : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CUserName, &CLSID_UserName>,
	public IDispatchImpl<IUserName, &IID_IUserName, &LIBID_SignonNameLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CUserName()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_USERNAME)


BEGIN_COM_MAP(CUserName)
	COM_INTERFACE_ENTRY(IUserName)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}
	
	void FinalRelease() 
	{
	}

public:

	STDMETHOD(GetUserName)(BSTR* SamName);
};

OBJECT_ENTRY_AUTO(__uuidof(UserName), CUserName)
