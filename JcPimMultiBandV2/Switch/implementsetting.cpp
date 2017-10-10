/*******************************Copyright (c)***********************************
*
*              Copyright (C), 1999-2015, Jointcom . Co., Ltd.
*
*------------------------------------------------------------------------------
* @file	:	implementsetting.cpp
* @author	:mashuai
* @version	:v2.0
* @date		:2015.3.1
* @brief	:
2015.3.6
	�Ľ����ݣ�1���첽���ӣ�������ĳЩģ�鲻���߶������ͬ��������ʱʱ��ĵ��ӡ�
			 2�������ӣ�����쳣ģ�飬���Ը�λģ�鲢��������
			 3�������������������в����κ���ʱ

	�������⣺���������У�Ӳ�����쳣���ߣ����������·���ڣ�ż���޷���λģ�顣����취
			 ���ε���DisConnect��Connet������		
2015.3.20
	�޸����ݣ�
			1������ʱ�첽���ӵ�һ̨�����ó�ʱ�ȴ���Ȼ��ÿ̨�ֱ�ʱ�ȴ�500ms,�8��
			�����в����ߣ�
			2���������������صĿ���ʹ��
2015.5.4
	��Connect�еĹ��ܽ���
2015.11.25
	�޸�����ʧ����ʾ����ֻ�ϱ���һ������ʧ�ܵ�ģ�飩��
2016.1.18
	���ӻ�Ϊ8Ƶ���ñ�
2016.1.26
	���ݣ���JcConfig.ini������ģ��ʱ�������Ĭ�����ñ��е�ģ����Ա��ص�ַ
*------------------------------------------------------------------------------*/
#include "../stdafx.h"
#include "switch_info_poi.h"
#include "switch_info_huawei.h"
#include "switch_info_hw_ext8.h"
#include "switch_info_hw_ext12.h"
#include "switch_info_dpx_sw01.h"
#include "implementsetting.h"

namespace ns_com_io_ctl
{
	//���캯��
	implementsetting::implementsetting(void) : isZeroFrame(false)
	{
		//virtual table not build,do not call the virtual function
		__ac_tx1 = &__actionCellc[0];
		__ac_tx2 = &__actionCellc[1];
		__ac_pim = &__actionCellc[2];
		__ac_det = &__actionCellc[3];
	}
	//��������
	implementsetting::~implementsetting(void)
	{
		//������������ʼ����ʱ�����麯����ָ������麯����
		//������캯��ʱδ�����麯���������������
		//DisConnect();
	}	
	//��ȡ����������Ϣ
	void implementsetting::GetHostsCtrl(map<string,stHostControl>&host)
	{
		string ip;

		for (map<string, stHostControl>::iterator itr = __hostCtrl.begin();
			itr != __hostCtrl.end();
			itr++)
		{
			ip = split(itr->second.ip, ":")[0];		
		}

		host = __hostCtrl;
	}
	//��������������Ϣ
	//�����������������ʹ������(�ź�Դ���أ���⿪����)
	void implementsetting::SetHostsCtrl(const map<string, stHostControl>&host, bool bSignal, bool bDetect)
	{		
		__hostCtrl = host;
		__hostCtrl["Signalswich"].enable = bSignal;
		__hostCtrl["Paspecumpwmt"].enable = bDetect;
	}
	//��ȡTX1�����б�
	vector<string>&implementsetting::GetTx1NameList(void)
	{
		return __ac_tx1->namelist;
	}
	//��ȡTX2�����б�
	vector<string>&implementsetting::GetTx2NameList(void)
	{
		return __ac_tx2->namelist;
	}
	//��ȡPIM�����б�
	vector<string>&implementsetting::GetPimNameList(void)
	{
		return __ac_pim->namelist;
	}
	//��ȡDet�����б�
	vector<string>&implementsetting::GetDetNameList(void)
	{
		return __ac_det->namelist;
	}
	//�ַ����滻
	void implementsetting::StringReplace(std::string &strBase, std::string strSrc, std::string strDes)  
	{  
		string::size_type pos = 0;  
		string::size_type srcLen = strSrc.size();  
		string::size_type desLen = strDes.size();  
		pos=strBase.find(strSrc, pos);   
		while ((pos != std::string::npos))  
		{  
			strBase.replace(pos, srcLen, strDes);  
			pos=strBase.find(strSrc, (pos+desLen));  
		}  
	} 
	//�ַ����ָ�
	vector<string> implementsetting::split(string str,string pattern)  
	{  
		string::size_type pos = 0;  
		vector<string> result;  
		str+=pattern;//��չ�ַ����Է������   
		int size=(int)str.size();  
	  
		for(int i=0; i<size; i++)  
		{  
			pos=str.find(pattern,i);  
			if(pos<(string::size_type)size)  
			{  
				string s=str.substr(i,pos-i);  
				result.push_back(s);  
				i = (int)(pos+pattern.size()-1);  
			}  
		}  
		return result;  
	}  
	//����ӳ���1
	bool implementsetting::LoadMap(int type)
	{
		return LoadMap(type,NULL);
	}


	//����ӳ���2
	bool implementsetting::LoadMap(int type, char * cfgPath)
	{
		bool result = true;
		string iopath;
		string impath;
		string cfgpath(cfgPath);

		//cfgpath = cfgpath.substr(0, cfgpath.rfind('\\'));

		__runPath.assign(cfgpath);

		iopath.assign(GetTempFileInfo("~io"));
		impath.assign(GetTempFileInfo("~implementsetting"));

		cfgpath.append("\\JcConfig.ini");

		__ioPath = iopath;
		__imPath = impath;
		__cfgPath = cfgpath;

		ofstream ofio(iopath);
		ofstream ofimplt(impath);

		string fstr;

		switch (type)
		{
			//case ID_HUAWEI:
			case 1:
				fstr.assign(IO_STRING_HUAWEI); 
				ofio.write(fstr.c_str(), fstr.size());
				fstr.assign(IMPLEMENT_STRING_HUAWEI);
				ofimplt.write(fstr.c_str(), fstr.size());
				break;
			//case ID_POI:
			case 2:
				fstr.assign(IO_STRING_POI);
				ofio.write(fstr.c_str(), fstr.size());
				fstr.assign(IMPLEMENT_STRING_POI);
				ofimplt.write(fstr.c_str(), fstr.size());				
				break;
			//case ID_HUAWEI_EXT12:
			case 3:
				fstr.assign(IO_STRING_HW_EXT12);
				ofio.write(fstr.c_str(), fstr.size());
				fstr.assign(IMPLEMENT_STRING_HW_EXT12);
				ofimplt.write(fstr.c_str(), fstr.size());
				break;
			//case ID_HUAWEI_EXT8:
			case 4:
				fstr.assign(IO_STRING_HW_EXT8);
				ofio.write(fstr.c_str(), fstr.size());
				fstr.assign(IMPLEMENT_STRING_HW_EXT8);
				ofimplt.write(fstr.c_str(), fstr.size());
				break;
			//case ID_DPX_SW01:
			case 5:
				fstr.assign(IO_STRING_DPX_SW01);
				ofio.write(fstr.c_str(), fstr.size());
				fstr.assign(IMPLEMENT_STRING_DPX_SW01);
				ofimplt.write(fstr.c_str(), fstr.size());
				break;
			default:break;
		}		

		ofio.close();
		ofimplt.close();

		//string ipSection = (type == ID_HUAWEI) ? "ip_huawei" : "ip_poi";
		string ipSection = "ip";

		if (LoadParaIM(ipSection) == false)
		{
			result = false;
		}
		else
		{
			LoadParaIO();
		}

		__logEnable = (0 != atoi(GetRowFromFile(ipSection, "log", "0", __cfgPath).c_str()));

		WindowsDeleteFile(iopath.c_str());
		WindowsDeleteFile(impath.c_str());

		bLoadMap = result;

		return result;
	}
	//����
	bool implementsetting::Connect(void)
	{
		if (!bLoadMap)
		{			
			Message("SWITCH::load map failed!");			
			return false;
		}

		return true;

		//bool result = true,cyc2 = false;
		//regex pattern("\\d{1,4}");
		//smatch mat;

		//for(map<string,string>::iterator hostIter = __ipmap.begin();
		//	hostIter != __ipmap.end();
		//	hostIter++)
		//{
		//	regex_search(hostIter->first, mat, pattern);

		//	string strTemp(mat[0].str());

		//	if ( strTemp != "" )
		//	{				
		//		__hostCtrl[strTemp].state = __hostCtrl[strTemp].enable;
		//	}
		//	else
		//	{
		//		strTemp = hostIter->first;				
		//	}

		//	if (!__hostCtrl[strTemp].enable)continue;			

		//	IOConnectBegin(hostIter->second);
		//}			

		//bool delayFirst = true;
		//bool funcResult = true;
		//string infoPrintf("");

		//for (map<string, stHostControl>::iterator itr = __hostCtrl.begin();
		//	itr != __hostCtrl.end();
		//	itr++)
		//{
		//	if (!itr->second.enable)continue;

		//	result = IOConnectEnd(itr->second.ip, delayFirst?3000:500);
		//	
		//	if (result)
		//		LoadModuleState(itr->second.ip);
		//	else
		//		funcResult = false;

		//	if (!funcResult)
		//	{
		//		infoPrintf.append("<Switch IP - "+itr->second.ip+">:Failed!\n");

		//		string info("SWITCH::Connet::IP(");
		//		info.append(itr->second.ip);
		//		info.append(")::Failed");
		//		Message(info);				
		//	}

		//	itr->second.state = result;

		//	delayFirst = false;
		//}

		//if (!funcResult)
		//{
		//	Message(infoPrintf);
		//}

		//return funcResult;
	}
	//�Ͽ�
	void implementsetting::DisConnect(void)
	{
		if (!bLoadMap)return;

		for(map<string,stHostControl>::iterator itr = __hostCtrl.begin();
			itr != __hostCtrl.end();
			itr++)
		{
			if(itr->second.enable)
			{
				IODisConnect(itr->second.ip);
			}
		}
	}
	//��ȡ�����б�
	vector<string>&implementsetting::GetNameList(string&strBase)
	{	
		__nameList.clear();
		StringReplace(strBase," ","");
		__nameList = split(strBase,",");
		//���þ��Ƕ���ı���
		return dynamic_cast<vector<string>&>(__nameList);
	}
	//����IM����
	bool implementsetting::LoadParaIM(const string&ipSection)
	{
		string strValue;
		//ip
		__ipNameList = GetNameList(GetRowFromIMFile(ipSection, "namelist", ""));

		for(int i=0;i<(int)__ipNameList.size();i++)
		{
			__ipmap[__ipNameList[i]] = GetRowFromIMFile(ipSection, __ipNameList[i], "");
			strValue = GetRowFromCfgFile(ipSection, __ipNameList[i], "");
			if (strValue != "")
			{
				__ipmap[__ipNameList[i]] = strValue;
			}
			//else//���ݣ���JcConfig.ini������ģ��ʱ�������Ĭ�����ñ��е�ģ����Ա��ص�ַ
			//{
			//	return false;
			//}
			__ipGpioBak[ __ipmap[__ipNameList[i]]] = __ipGpioBakArray[i];
		}
		
		//switch
		__switchNameList = GetNameList( GetRowFromIMFile("switch","namelist",""));

		for(int i=0;i<(int)__switchNameList.size();i++)
		{		
			iniSwitch is;
			is.name = __switchNameList[i];
			vector<string>&temp =  GetNameList( GetRowFromIMFile("switch",__switchNameList[i],""));
			for(int j=0;j<(int)temp.size();j++)
			{
				string&index = GetRowFromIMFile("switch",temp[j],"0");
				is.io[temp[j]] = atol(index.c_str());
			}
			__switchMap[__switchNameList[i]] = is;
		}

		//ACTION
		LoadActionList("actiontx1",*__ac_tx1);
		LoadActionList("actiontx2",*__ac_tx2);
		LoadActionList("actionpim",*__ac_pim);
		LoadActionList("actiondet",*__ac_det);

		const regex pattern("\\d{1,4}");
		smatch mat;
		stHostControl stHC;

		for(map<string,string>::iterator itr = __ipmap.begin();
			itr != __ipmap.end();
			itr++)
		{
			stHC.state = true;
			stHC.enable = true;
			stHC.name = itr->first;
			stHC.ip = itr->second;
			regex_search(itr->first, mat, pattern);
			//__hostCtrl.push_back(stHC);
			if (mat[0].str() != "")
				__hostCtrl[mat[0].str()] = stHC;
			else
				__hostCtrl[stHC.name] = stHC;
		}

		for( map<string,unsigned short*> ::iterator it = __ipGpioBak.begin();
				 it != __ipGpioBak.end();
				 it++
			)
		{
			memset((void*)it->second,0,10);
		}

		return true;
	}
	//����IO����
	void implementsetting::LoadActionList(const string&section,actionCellc&ac)
	{
		ac.namelist = GetNameList( GetRowFromIMFile(section,"namelist",""));

		for(int i=0;i<(int)ac.namelist.size();i++)
		{
			string&funcStr = GetRowFromIMFile(section,ac.namelist[i],"");
			rowRun rr;
			GetRowRunFunc(funcStr,rr);
			ac.actionMap[ac.namelist[i]] = rr;		
		}
	}
	//��ȡ�к����б�
	void implementsetting::GetRowRunFunc(string str,rowRun&rr)
	{
		if (str == "") return;

		StringReplace(str," ","");
		vector<string>&temp = split(str,"),");
					
		iniFunc ifc;
		string buff;

		for(int j=0;j<(int)temp.size();j++)
		{						
			buff = split(temp[j],"(")[1];
			StringReplace(buff,")","");
			vector<string>&parav = split(buff,",");

			ifc.swName = split(temp[j],"(")[0];
			ifc.ip = __ipmap[parav[0]];
			ifc.swIdx =  __switchMap[ ifc.swName ].io[ parav[1] ];
			rr.push_back(ifc);
		}
	}
	//����IO����
	bool implementsetting::LoadParaIO(void)
	{
		string strBuff;
		char pBuf[10] = {0};

		for( vector<string>::iterator swName = __switchNameList.begin();
			swName != __switchNameList.end();
			swName++)
		{
			for(int i = 0,j=0;i<100;i++)
			{
				_itoa_s(i,pBuf,10);
				strBuff = GetRowFromIOFile(*swName,pBuf,"");
				if(strBuff != "")
				{				
					__ioInfoMap[*swName].push_back(strBuff);
					j++;
					if(j>=(int)__switchMap[*swName].io.size())break;				
				}
			}		
		}

		return true;
	}
	//��������б�
	void implementsetting::Clear(void)
	{
		__actionList.clear();
	}
	//�������ز���
	void implementsetting::AddSwitchActionList(int addr, int swId, int swIdx)
	{
		if (addr > (int)__ipNameList.size() || addr < 0)
		{
			char buf[10];
			sprintf_s(buf,"%d",addr);
			Message("JcMatrixSwitch : Switch : ModuleNumber < "+string(buf));
			return;
		}

		if (swId > (int)__switchNameList.size() || swId < 0)
		{
			char buf[10];
			sprintf_s(buf, "%d", swId);
			Message("JcMatrixSwitch : Switch : SwitchNumber < " + string(buf));
			return;
		}

		auto itrIP = __ipNameList.begin();

		for (int i = 1; i < addr && itrIP != __ipNameList.end(); itrIP++, i++){}

		auto itrSwName = __switchNameList.begin();

		for (int i = 1; i < swId && itrSwName != __switchNameList.end(); itrSwName++, i++){}

		AddActionList(__ipmap[*itrIP],*itrSwName,swIdx);
	}
	//��Ӷ����б�
	void implementsetting::AddActionList(const string&ip,const string&sw,int chan)
	{
		string str;
		vector<string>gpioValueStr;
		unsigned short *gpioBak = __ipGpioBak[ip],
								 port[5]={0};

		for(_tp_vs::iterator itr = __ioInfoMap[sw].begin();
			itr != __ioInfoMap[sw].end();
			itr++	)
		{
			gpioValueStr = split(*itr,",");
			for(int i =0;i<sizeof(port)/sizeof(short);i++)
			{				
				port[i] |= atoi(gpioValueStr[i].c_str());
			}
		}

		if (chan < 1 || chan > (int)__ioInfoMap[sw].size())
		{
			char buf[10];
			sprintf_s(buf,"%d",chan);
			Message("JcMatrixSwitch : " + sw + " : has no Idx = " + string(buf));
			return;
		}

		str = __ioInfoMap[sw][chan-1];
		gpioValueStr = split(str,",");

		for(int i =0;i<sizeof(port)/sizeof(short);i++)
		{			
			gpioBak[i] &=~port[i];
			gpioBak[i] |= atoi(gpioValueStr[i].c_str());
		}

		__actionList[ip] = gpioBak;
	}
	//����ģ����Ϣ
	void implementsetting::LoadModuleState(const string&host)
	{
		unsigned char txBuf[12]={0},rxBuf[12]={0};
		unsigned char checkValue = 0;
		unsigned short *gpioBak = NULL;
		int len = 0;

		gpioBak = __ipGpioBak[host];

		txBuf[0] = 'R';

		for(int i =1;i<11;i++)
		{
			checkValue^=txBuf[i];
		}

		txBuf[11] = checkValue;		

		IOWrite(host, (char*)txBuf, (int)sizeof(txBuf));
		len = (int)sizeof(txBuf);
		IORead(host, (char*)rxBuf, &len);			

		if(rxBuf[0] != 'R')return;

		checkValue = 0;

		for(int i =1;i<11;i++)
		{
			checkValue^=rxBuf[i];
		}

		//if(checkValue != rxBuf[11])return;//�˴���Ҫ����

		for(int i =1,j=0;i<11;j++)
		{
			gpioBak[j] = rxBuf[i];				
			i++;
			gpioBak[j] += rxBuf[i]*256;
			i++;
		}
	}
	//ִ�ж���
	bool implementsetting::Excute(void)
	{
		if (!bLoadMap)
		{
			Message("SWITCH::Excute failed::load map failed!");
			return false;
		}

		bool funcResult = true;
		unsigned char txBuf[12] = { 0 }, rxBuf[12] = { 0 };
		unsigned char checkValue = 0;
		unsigned short *gpioBak = NULL;
		string ip;
		string ipFailed;
		int replyCnt = 0; //���Դ���
		vector<string> actListOk;
		map<string, bool> hostIPEnableList;
		map<string, unsigned short*> actList;

		actList.clear();
		actListOk.clear();

		txBuf[0] = 'W';

		//��������ʹ�ܶ���
		/*		for (map<string, stHostControl>::iterator itr = __hostCtrl.begin();
		itr != __hostCtrl.end();
		itr++)
		{
		hostIPEnableList[itr->second.ip] = itr->second.enable;
		}*/
		//bak Temp
		for (map<string, string>::iterator itr = __ipmap.begin();
			itr != __ipmap.end();
			itr++)
		{
			hostIPEnableList[itr->second] = true;
		}
		//Copy��__actionList
		for (map<string, unsigned short*>::iterator actionIter = __actionList.begin();
			actionIter != __actionList.end();
			actionIter++)
		{
			if (!hostIPEnableList[actionIter->first])continue;
			actList[actionIter->first] = actionIter->second;
		}

		replyCnt = 0;

		while (true)
		{
			//�·�����ָ�����
			for (map<string, unsigned short*>::iterator actionIter = actList.begin();
				actionIter != actList.end();
				actionIter++)
			{
				ip = actionIter->first;
				gpioBak = actionIter->second;

				if (!hostIPEnableList[ip])continue;

				checkValue = 0;
				for (int i = 1, j = 0; i < 11; j++)
				{
					txBuf[i] = gpioBak[j] % 256;
					checkValue ^= txBuf[i];
					i++;
					txBuf[i] = gpioBak[j] / 256;
					checkValue ^= txBuf[i];
					i++;
				}

				txBuf[11] = checkValue;

				//֡����
				if (isZeroFrame)
				{
					memset(txBuf + 1, 0, 11);
				}

				bool wrResult = false;
				int len = 12;
				//д��ģ��
				for (int i = 0; i < 1; i++)
				{
					funcResult = wrResult = IOWrite(ip, (char*)txBuf, sizeof(txBuf));

					if (wrResult == false)continue;

					funcResult = wrResult = IORead(ip, (char*)rxBuf, &len);

					if (wrResult == false)continue;
					//�ж�ģ��ʹ��λ
					vector<string>hostInfo = split(ip, ":");
					if (hostInfo.size() > 2)if (hostInfo[2] == "0")break;

					for (int j = 0; j < sizeof(txBuf); j++)
					{
						if (rxBuf[j] != txBuf[j])
						{
							wrResult = false; break;
						}
					}

					funcResult = wrResult;
					if (wrResult == true)break;
				}

				if (!funcResult)
				{
					ipFailed = ip;
					break;
				}
				else
				{//��װ�ɹ���ģ�����
					actListOk.push_back(ip);
				}
			}

			if (replyCnt > 1 || funcResult)break;
			//�����������гɹ���ģ�����
			for (vector<string>::iterator itr = actListOk.begin();
				itr != actListOk.end();
				itr++)
			{
				actList.erase(*itr);
			}
			actListOk.clear();
			//�Լ����
			replyCnt++;
			//�Ͽ�����
			IODisConnect(ipFailed);
			//��λ
			vector<string> retList;
			retList.clear();
			retList.push_back(ipFailed);
			IOResetWithList(retList);
			Delay(500);
			//����
			IOConnectBegin(ipFailed);
			funcResult = IOConnectEnd(ipFailed, 1000);

			if (!funcResult)
			{
				string info("<MatrixSwitch>:[");

				for (map<string, string>::iterator mtr = __ipmap.begin();
					mtr != __ipmap.end();
					mtr++)
				{
					if (mtr->second == ipFailed)info.append(mtr->first + '@');
				}

				info.append(ipFailed + "]:<Failed>");
				Message(info);

				break;
			}
			else
			{
				replyCnt = 0;
			}

			Delay(500);
		}

		return funcResult;
	}
	//ѡ��ͨ��
	void implementsetting::SelChan(rowRun&rr)
	{
		for(rowRun::iterator swList = rr.begin();
			swList != rr.end();
			swList ++)
		{			
			AddActionList(	swList->ip,swList->swName,swList->swIdx);
		}
	}
	//ѡ��ͨ��TX1
	void implementsetting::SelChanTx1(const string&chan)
	{
		SelChan(__ac_tx1->actionMap[chan]);
	}
	//ѡ��ͨ��TX2
	void implementsetting::SelChanTx2(const string&chan)
	{
		SelChan(__ac_tx2->actionMap[chan]);
	}
	//ѡ��ͨ��PIM
	void implementsetting::SelChanPim(const string&chan)
	{
		SelChan(__ac_pim->actionMap[chan]);
	}
	//ѡ��ͨ��DET
	void implementsetting::SelChanDet(const string&chan)
	{
		SelChan(__ac_det->actionMap[chan]);
	}
	//���������ļ�
	string implementsetting::GetRowFromCfgFile(const string&section,const string&key,const string&defaultValue)
	{
		return GetRowFromFile(section, key, defaultValue, __cfgPath);
	}
	//����IM�ļ�
	string implementsetting::GetRowFromIMFile(const string&section,const string&key,const string&defaultValue)
	{
		return GetRowFromFile(section,key,defaultValue,__imPath);
	}
	//����IO�ļ�
	string implementsetting::GetRowFromIOFile(const string&section,const string&key,const string&defaultValue)
	{
		return GetRowFromFile(section,key,defaultValue,__ioPath);
	}
	//��ȡģ���б�
	vector<string>&implementsetting::GetModuleList(void)
	{
		list<int> listTmp;
		int flag = 0;
		char str[10] = {0};

		__moduleList.clear();		

		for (map<string, stHostControl>::iterator itr = __hostCtrl.begin();
			itr != __hostCtrl.end();
			itr++)
		{
			flag = atoi(itr->first.c_str());

			if (flag!=0)
				listTmp.push_front(flag);
		}
		
		listTmp.sort();

		for (list<int>::iterator itr = listTmp.begin();
			itr != listTmp.end();
			itr++
			)
		{
			_itoa_s(*itr, str, 10);
			__moduleList.push_back(str);
		}

		return __moduleList;
	}
}
