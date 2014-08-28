// UserName.cpp : Implementation of CUserName

#include "stdafx.h"
#include "UserName.h"
#include ".\username.h"

#include <string.h>
#include <security.h>

#define NAMESTRLEN	512
// CUserName


STDMETHODIMP CUserName::GetUserName(BSTR* SamName)
{
	TCHAR szName[512];
	ZeroMemory(szName, 512);
	
	char				theSignonName[NAMESTRLEN] = {0};
	char				theDomainName[NAMESTRLEN] = {0};

	ULONG ulSize = 512;
	if(GetUserNameEx((EXTENDED_NAME_FORMAT)2, theDomainName, &ulSize))
	{
		// 将 Domain\UserName 解析为 Domain 和 UserName
		UINT i = 0;
		ulSize = strlen(theDomainName);
		for( i = 0 ; i < ulSize; i++ )
		{
			if( theDomainName[i] == '\\' && i < ulSize - 1 )
			{
				strcpy(theSignonName, (char*)&theDomainName[i+1]);
				break;
			}
		}

		if( i >= ulSize )
		{
			return E_FAIL;
		}
		else
		{
			theDomainName[i] = 0;
		}

		*SamName = SysAllocString( CT2OLE(theSignonName) );
		return S_OK;
	}

	return E_FAIL;
}
