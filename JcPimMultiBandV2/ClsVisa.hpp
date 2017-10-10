#ifndef _CLS_AGILENT_HPP_
#define _CLS_AGILENT_HPP_

#include "stdafx.h"
#include "MyUtil/JcCommonAPI.h"

class ClsVisa
{
public:
	ClsVisa()
		:_viStatus(VI_NULL),
		_viDefaultRM(VI_NULL),
		_viSession(VI_NULL),
		_isConn(false),
		_esr(0),
		_strIDN("")
	{}

	~ClsVisa() {}

public:
	//��ʼ����
	bool AgConnect(const char* c_addr) {
		if (_isConn) return true;

		_viStatus = viOpenDefaultRM(&_viDefaultRM);
		_viStatus = viOpen(_viDefaultRM, const_cast<char*>(c_addr), VI_NULL, 3000, &_viSession);

		//if (_viStatus == VI_SUCCESS)
		//	AgWrite("*RST\n");

		_isConn = !_viStatus;
		return _isConn;
	}

	//��ʼ����
	void AgSession(ViSession viConnectedSession, std::string Idn) {
		//_viDefaultRM = viRM;
		_viSession = viConnectedSession;
		_strIDN = Idn;
		//printf("%s", _strIDN.c_str());
		//if (_viSession != VI_NULL)
		//	AgWrite("*RST\n");

		_isConn = true;
	}

	//д������
	bool AgWrite(const char* c_cmd) {
		_viStatus = viPrintf(_viSession, const_cast<char*>(c_cmd));
		return !_viStatus;
	}

	//д�벢�ȴ���ȡ�����ض�ȡ�ֽڳ��ȣ�
	long AgWriteAndRead(const char* c_cmd, char* rbuf) {
		//��ʼд��
		_viStatus = viPrintf(_viSession, const_cast<char*>(c_cmd));
		if (_viStatus) return 0;
		//��ʼ��ȡ
		unsigned char buf[256] = {0};
		unsigned long retCount = 0;
		_viStatus = viRead(_viSession, buf, 128, &retCount);

		//��%#t���ĸ�ʽ����ͨ��
		//char buf[128] = {0};
		//unsigned long retCount = 0;
		//viQueryf(_viSession, const_cast<char*>(c_cmd), "%#t", &retCount, buf);

		if (retCount) 
			memcpy(rbuf, buf, retCount);

		return retCount;
	}

	//��������״��
	bool AgConnStatus() const {
		return _isConn;
	}

	//���ش�����Ϣ
	ViStatus AgError() const {
		return _viSession;
	}

	void AgClose() {
		_viStatus = viClose(_viSession);
		_isConn = false;
	}

	//�ȴ�
	bool AgWait() {
		viPrintf(_viSession, const_cast<char*>("*OPC\n"));
		_esr = 0;
		//����visa��ʱʱ��,����500��
		for (int i = 0; i <= 500; i++)
		{
			if (i == 500)
				return false;

			viQueryf(_viSession, const_cast<char*>("*ESR?\n"), const_cast<char*>("%ld"), &_esr);
			if (_esr & 1)
				break;

			Util::setSleep(20);
		}
		return true;
	}

	void PrintError(long err)
	{
		if (err < VI_SUCCESS)
		{
			unsigned long retCount = 0;
			unsigned char error_message[256] = { 0 };

			_viStatus = viPrintf(_viSession, const_cast<char*>("SYST:ERR?\n"));
			_viStatus = viRead(_viSession, error_message, 256, &retCount);
			//viQueryf(_viSession, "")
			printf("Error: %s\n", error_message);
		}

	}

protected:
	bool _isConn;
	ViStatus _viStatus;
	ViSession _viDefaultRM;
	ViSession _viSession;
	ViUInt16 _esr;
	std::string _strIDN;
};

#endif