/*******************************Copyright (c)***********************************
*
*              Copyright (C), 1999-2015, Jointcom . Co., Ltd.
*
*------------------------------------------------------------------------------
* @file	:	com_io_ctl.h
* @author	:mashuai
* @version	:v2.0
* @date		:2015.3.1
* @brief	:
*------------------------------------------------------------------------------*/
#pragma once
#include "implementsetting.h"

namespace ns_com_io_ctl{
	using  namespace std;

	#define  CONNECT_TYEP			E_TCP
	#define	 DLL_HOST_NAME			"JcPimMultiBandV2.dll"		//������̬���ӿ���
	#define	 DLL_HOST_NAME_W		L"JcPimMultiBandV2.dll"		//������̬���ӿ���
	#define  TCP_CONNECT_TIMEOUT	(3)
	#define  TCP_SEND_TIMEOUT		(3)
	#define  TCP_RCV_TIMEOUT		(3)
	//#define  _WINSOCK_DEPRECATED_NO_WARNINGS		//�������Ԥ���붨��

	#define DEF_BUF_SIZE 1024
	#define IP_HEADER_SIZE 20
	#define ICMP_HEADER_SIZE 12

	typedef enum
	{
		E_TCP = 2, E_UDP = 3, E_COM = 4,
	}EConType;

	class com_io_ctl :
		public implementsetting
	{	
	public:
		int __conType = CONNECT_TYEP;
		string __dllHostName = DLL_HOST_NAME;
		wstring __dllHostNameW = DLL_HOST_NAME_W;
		com_io_ctl(void);		
		static void SocketTest();
		virtual bool Reset(void);		
		map<string, bool> __socketState;
		virtual string GetRunPath();
		virtual wstring GetRunPathW();
	private:	
		bool __maskIO;	
		// ����1
		char __ioBuf1[100];
		map<string,SOCKET> __socketClient;	
		map<string,sockaddr_in> __addrRecver;
		vector<string> __mAccpetHosts;
		virtual void Delay(int mil);
		virtual bool IOConnect(const string&host);
		virtual bool IODisConnect(const string&host);
		virtual bool IOWrite(const string&host,const char*buf,int len);
		virtual bool IORead(const string&host,char*buf,int*len);
		virtual void WindowsDeleteFile(const char* file);
		virtual string GetRowFromFile(const string&section,const string&key,const string&defaultValue,const string&fileName);
		virtual string GetTempFileInfo(const string& flagName);
		USHORT GetCheckSum(LPBYTE lpBuff, DWORD dwSize);
	public:
		virtual~com_io_ctl(void);	
		void SetAccpectHosts(char *hosts[],int size);
	private:
		virtual bool ResetOne(const string&host);
		virtual bool IOConnectBegin(const string&host);
		virtual bool IOConnectEnd(const string&host,int timeout);
		virtual bool IOSocketIsActive(const string&host);
		virtual bool IOResetWithList(vector<string>&ipList);		
		virtual void Message(const string&info);
		void log(const string& info);
		string logGetLastError();
		wstring StringToWString(const string &str);
		bool IsAcceptModule(const string&host);			
	};
}
