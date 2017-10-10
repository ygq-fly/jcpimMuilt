#ifndef _CLS_JCSWITCH_H_
#define _CLS_JCSWITCH_H_

//#include "Switch/com_io_ctl.h"
#include "JcMatrixSwitch.h"
#include "../IfSwitch.hpp"

class ClsJcSwitch: Implements_ IfSwitch
{
public:
	ClsJcSwitch();
	~ClsJcSwitch();

public:
	//���س�ʼ��
	bool SwitchInit(int switch_work_type, int switch_conn_type, std::string path);
	//����ִ���л�
	bool SwitchExcut(const int& iSwitchTx1, const int& iSwitchTx2, 
		const int& iSwitchPim, const int& iSwitchDet, bool reset = false);
	//�ͷ���Դ
	void SwitchClose();
	//��ȡ��Ϣ
	std::string SwitchGetError();
	//��ȡ�豸��Ϣ
	void SwitchGetInfo(std::string& sInfo, int iIndex);

private:
	bool _isConn;
	//���ع�������
	int _switch_work_type;
	//������������
	int _switch_conn_type;
	std::string _error_info;
};
#endif