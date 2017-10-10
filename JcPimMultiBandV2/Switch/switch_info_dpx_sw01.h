/*******************************Copyright (c)***********************************
*
*              Copyright (C), 1999-2015, Jointcom . Co., Ltd.
*
*------------------------------------------------------------------------------
* @file	:
* @author	:mashuai
* @version	:v2.0
* @date		:2015.3.1
* @brief	:
*				 2016.1.21 ������8Ƶ
*------------------------------------------------------------------------------*/

#ifndef __SWITCH_CONFIG_DPX_SW01_H__
#define __SWITCH_CONFIG_DPX_SW01_H__
#define IO_STRING_DPX_SW01	         "[STATE]\n"\
"//��Ϊ����ƽ̨\n"\
"//�ֱ����ÿһ������\n"\
"//������������˿ӡһ��\n"\
"//******************************************************\n"\
"=================================================================\n"\
"//����������1������J5��4о�� 1-3\n"\
"[Signal1swich]\n"\
"20=16,0,0,0,0,\n"\
"21=32,0,0,0,0,\n"\
"22=64,0,0,0,0,\n"\
"//����������2������J6��4о�� 1-3\n"\
"[Signal2swich]\n"\
"23=128,0,0,0,0,\n"\
"24=0,0,16,0,0,\n"\
"25=0,0,32,0,0,\n"\
"//����1 SP4T\n"\
"[TXoutswich]\n"\
"//1ͨ��\n"\
"0=0,0,0,0,2,\n"\
"//2ͨ��\n"\
"1=0,0,0,0,1,\n"\
"//3ͨ��\n"\
"2=0,512,0,0,0,\n"\
"//4ͨ��\n"\
"3=0,256,0,0,0,\n"\
"//5ͨ��\n"\
"4=0,32,0,0,0,\n"\
"//6ͨ��\n"\
"5=0,16,0,0,0,\n"\
"//7ͨ��\n"\
"6=0,8,0,0,0,\n"\
"\n"\
"//����2 SP4T\n"\
"[RXinswich]\n"\
"//1ͨ��\n"\
"3=0,0,0,16,0,\n"\
"//2ͨ��\n"\
"4=0,0,0,8,0,\n"\
"//3ͨ��\n"\
"5=0,0,0,4,0,\n"\
"//4ͨ��\n"\
"6=0,0,0,2,0,\n"\
"//5ͨ��\n"\
"7=0,0,0,1,0,\n"\
"//6ͨ��\n"\
"8=0,0,4096,0,0,\n"\
"//7ͨ��\n"\
"9=0,0,2048,0,0,\n"\
"\n"\
"//����5 SP3T ����\n"\
"[PA1swich1]\n"\
"//1ͨ��\n"\
"20=16,0,0,0,0,\n"\
"//2ͨ��\n"\
"21=32,0,0,0,0,\n"\
"//3ͨ��\n"\
"22=64,0,0,0,0,\n"\
"//\n"\
"//����6 SP3T ����\n"\
"[PA1swich2]\n"\
"//1ͨ��\n"\
"23=128,0,0,0,0,\n"\
"//2ͨ��\n"\
"24=0,0,16,0,0,\n"\
"//3ͨ��\n"\
"25=0,0,32,0,0,\n"\
"//����6 SP3T ����\n"\
"[Couplerswich]\n"\
"26=0,1,0,0,0,\n"\
"27=0,2,0,0,0,\n"\

#define IMPLEMENT_STRING_DPX_SW01  "[ip]\n"\
"namelist=IMA_0627_DPX_SW01\n"\
"IMA_0627_DPX_SW01=127.0.0.1:5000\n"\
"\n"\
"[switch]\n"\
"namelist	    =Signal1swich,Signal2swich,Couplerswich,RXinswich,TXoutswich\n"\
"\n"\
"Signal1swich        = PAin1, F1Cal\n"\
"PAin1=1\n"\
"F1Cal=2\n"\
"\n"\
"Signal2swich        =PAin2, F2Cal\n"\
"PAin2=1\n"\
"F2Cal=2\n"\
"\n"\
"Couplerswich       =nc1, no2\n"\
"nc1=1\n"\
"no2=2\n"\
"\n"\
"TXoutswich     =Txout1,Txout2,Txout3,Txout4,Txout5,Txout6\n"\
"Txout1=1\n"\
"Txout2=2\n"\
"Txout3=3\n"\
"Txout4=4\n"\
"Txout5=5\n"\
"Txout6=6\n"\
"\n"\
"RXinswich       =RXin1,RXin2,RXin3,RXin4,RXin5,RXin6\n"\
"RXin1=1\n"\
"RXin2=2\n"\
"RXin3=3\n"\
"RXin4=4\n"\
"RXin5=5\n"\
"RXin6=6\n"\
"\n"\
"[actiontx1]\n"\
"namelist 	= 1tx1toant1,2tx1toant2,3tx1toant3,4tx1toant4,5tx1toant5,6tx1toant6,7tx1tof1cal\n"\
"1tx1toant1 =  Signal1swich(IMA_0627_DPX_SW01,PAin1), TXoutswich(IMA_0627_DPX_SW01,Txout1)\n"\
"2tx1toant2 =  Signal1swich(IMA_0627_DPX_SW01,PAin1), TXoutswich(IMA_0627_DPX_SW01,Txout2)\n"\
"3tx1toant3 =  Signal1swich(IMA_0627_DPX_SW01,PAin1), TXoutswich(IMA_0627_DPX_SW01,Txout3)\n"\
"4tx1toant4 =  Signal1swich(IMA_0627_DPX_SW01,PAin1), TXoutswich(IMA_0627_DPX_SW01,Txout4)\n"\
"5tx1toant5 =  Signal1swich(IMA_0627_DPX_SW01,PAin1), TXoutswich(IMA_0627_DPX_SW01,Txout5)\n"\
"6tx1toant6 =  Signal1swich(IMA_0627_DPX_SW01,PAin1), TXoutswich(IMA_0627_DPX_SW01,Txout6)\n"\
"7tx1tof1cal = Signal1swich(IMA_0627_DPX_SW01,F1Cal)\n"\
"[actiontx2]\n"\
"namelist 	= 1tx2toant1,2tx2toant2,3tx2toant3,4tx2toant4,5tx2toant5,6tx2toant6,7tx2tof2cal\n"\
"1tx2toant1 =  Signal2swich(IMA_0627_DPX_SW01,PAin2), TXoutswich(IMA_0627_DPX_SW01,Txout1)\n"\
"2tx2toant2 =  Signal2swich(IMA_0627_DPX_SW01,PAin2), TXoutswich(IMA_0627_DPX_SW01,Txout2)\n"\
"3tx2toant3 =  Signal2swich(IMA_0627_DPX_SW01,PAin2), TXoutswich(IMA_0627_DPX_SW01,Txout3)\n"\
"4tx2toant4 =  Signal2swich(IMA_0627_DPX_SW01,PAin2), TXoutswich(IMA_0627_DPX_SW01,Txout4)\n"\
"5tx2toant5 =  Signal2swich(IMA_0627_DPX_SW01,PAin2), TXoutswich(IMA_0627_DPX_SW01,Txout5)\n"\
"6tx2toant6 =  Signal2swich(IMA_0627_DPX_SW01,PAin2), TXoutswich(IMA_0627_DPX_SW01,Txout6)\n"\
"7tx2tof2cal = Signal2swich(IMA_0627_DPX_SW01,F2Cal)\n"\
"[actionpim]\n"\
"namelist 	= 1pimant1,2pimant2,3pimant3,4pimant4,5pimant5,6pimant6\n"\
"1pimant1  = RXinswich(IMA_0627_DPX_SW01,RXin1)\n"\
"2pimant2  = RXinswich(IMA_0627_DPX_SW01,RXin2)\n"\
"3pimant3  = RXinswich(IMA_0627_DPX_SW01,RXin3)\n"\
"4pimant4  = RXinswich(IMA_0627_DPX_SW01,RXin4)\n"\
"5pimant5  = RXinswich(IMA_0627_DPX_SW01,RXin5)\n"\
"6pimant6  = RXinswich(IMA_0627_DPX_SW01,RXin6)\n"\
"[actiondet]\n"\
"namelist 		= 1couptx1,2couptx2\n"\
"1couptx1 = Couplerswich(IMA_0627_DPX_SW01,nc1)\n"\
"2couptx2 = Couplerswich(IMA_0627_DPX_SW01,no2)\n"\

#endif
