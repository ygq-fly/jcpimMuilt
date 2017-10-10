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

#ifndef __SWITCH_CONFIG_HUAWEI_H__
#define __SWITCH_CONFIG_HUAWEI_H__
#define IO_STRING_HUAWEI	         "[STATE]\n"\
"//��Ϊ����ƽ̨\n"\
"//�ֱ����ÿһ������\n"\
"//������������˿ӡһ��\n"\
"//******************************************************\n"\
"//����1��2�����˿��ؾ���1��\n"\
"//\n"\
"//����1 SP6T ֻ����1-3\n"\
"[Signal1swich]\n"\
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
"//\n"\
"//����2 SP6T ֻ����1-3\n"\
"[Signal2swich]\n"\
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
"//******************************************************\n"\
"//����3-8�����˿��ؾ���2��\n"\
"[Powermeterswich]\n"\
"//\n"\
"//����3 SP10T ֻ����1-7\n"\
"//1ͨ��\n"\
"6=0,0,0,16,0,\n"\
"//2ͨ��\n"\
"7=0,0,0,8,0,\n"\
"//3ͨ��\n"\
"8=0,0,0,4,0,\n"\
"//4ͨ��\n"\
"9=0,0,0,2,0,\n"\
"//5ͨ��\n"\
"10=0,0,0,1,0,\n"\
"//6ͨ��\n"\
"11=0,0,4096,0,0,\n"\
"//7ͨ��\n"\
"12=0,0,2048,0,0,\n"\
"//8ͨ��\n"\
"13=0,0,1024,0,0,\n"\
"//9ͨ��\n"\
"14=32768,0,0,0,0,\n"\
"//10ͨ��\n"\
"15=16384,0,0,0,0,\n"\
"//\n"\
"//����4 SP10T ֻ����1-7\n"\
"[Spectrumswich]\n"\
"//1ͨ��\n"\
"13=0,0,0,0,2,\n"\
"//2ͨ��\n"\
"14=0,0,0,0,1,\n"\
"//3ͨ��\n"\
"15=0,512,0,0,0,\n"\
"//4ͨ��\n"\
"16=0,256,0,0,0,\n"\
"//5ͨ��\n"\
"17=0,32,0,0,0,\n"\
"//6ͨ��\n"\
"18=0,16,0,0,0,\n"\
"//7ͨ��\n"\
"19=0,8,0,0,0,\n"\
"//8ͨ��\n"\
"20=0,0,0,128,0,\n"\
"//9ͨ��\n"\
"21=0,0,0,64,0,\n"\
"//10ͨ��\n"\
"22=0,0,0,32,0,\n"\
"//\n"\
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
"//\n"\
"//����7 SP3T ����\n"\
"[PA2swich1]\n"\
"//1ͨ��\n"\
"26=0,0,0,0,1024,\n"\
"//2ͨ��\n"\
"27=0,0,0,0,2048,\n"\
"//3ͨ��\n"\
"28=0,0,0,0,4096,\n"\
"//\n"\
"//����8 SP3T ����\n"\
"[PA2swich2]\n"\
"//1ͨ��\n"\
"29=0,0,0,0,8192,\n"\
"//2ͨ��\n"\
"30=0,0,0,0,16384,\n"\
"//3ͨ��\n"\
"31=0,0,0,0,32768,\n"\
"//****************************************************** \n"\
"//����9-11������7����ͬ����Դģ����\n"\
"//����9-11����Failsafe���أ����1ͨ��Ϊʵ�ʿ��Ƶ�ƽ�ģ�2ͨ����Ϊ��ʾLEDʹ��\n"\
"//\n"\
"//����9 SPDT Failsafe\n"\
"[Pimswich]\n"\
"//1ͨ��\n"\
"32=32,0,0,0,0,\n"\
"//2ͨ��\n"\
"33=16,0,0,0,0,\n"\
"//\n"\
"//����10 SPDT Failsafe ����\n"\
"[Txoutswich]  \n"\
"//1ͨ��\n"\
"34=0,16,0,0,0,\n"\
"//2ͨ��\n"\
"35=0,8,0,0,0,\n"\
"//\n"\
"//����11 SPDT Failsafe\n"\
"[Couplerswich]\n"\
"//1ͨ��\n"\
"36=0,0,16,0,0,\n"\
"//2ͨ��\n"\
"37=128,0,0,0,0,\n"\
"\n"\
"=================================================================\n"\
"//����1 SP4T\n"\
"[PimswichCg8090]\n"\
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
"[TxoutswichCg8090]\n"\
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
"//����ģʽ1\n"\
"[modeswich1Cg8090]\n"\
"//1ͨ��\n"\
"26=0,0,0,0,1024,\n"\
"//2ͨ��\n"\
"27=0,0,0,0,2048,\n"\
"//3ͨ��\n"\
"28=0,0,0,0,4096,\n"\
"\n"\
"//����ģʽ2\n"\
"[modeswich2Cg8090]\n"\
"//1ͨ��\n"\
"29=0,0,0,0,8192,\n"\
"//2ͨ��\n"\
"30=0,0,0,0,16384,\n"\
"//3ͨ��\n"\
"31=0,0,0,0,32768,\n"\
"\n"\
"//����\n"\
"[couplerswichCg8090]\n"\
"//1ͨ��\n"\
"34=0,1024,0,0,0,\n"\
"//2ͨ��\n"\
"35=0,2048,0,0,0,\n"\
"\n"\
""
#define IMPLEMENT_STRING_HUAWEI  "[ip]\n"\
"namelist			=Signalswich,Paspecumpwmt,Testmdlte700,Testmddd800,Testmdgsm900,Testmddcs1800,Testmdpcs1900,Testmdwcdma2100,Testmdlte2600,Testmdpdc1500,Testmdcg8090\n"\
"Signalswich         =127.0.0.1:5000\n"\
"Paspecumpwmt        =127.0.0.1:5001\n"\
"Testmdlte700        =127.0.0.1:5002 \n"\
"Testmddd800         =127.0.0.1:5003\n"\
"Testmdgsm900        =127.0.0.1:5004\n"\
"Testmddcs1800       =127.0.0.1:5005\n"\
"Testmdpcs1900       =127.0.0.1:5006\n"\
"Testmdwcdma2100     =127.0.0.1:5007\n"\
"Testmdlte2600       =127.0.0.1:5008\n"\
"Testmdpdc1500      =127.0.0.1:5009\n"\
"Testmdcg8090      =127.0.0.1:5010\n"\
"\n"\
"[switch]\n"\
"namelist	    =Signal1swich,Signal2swich,PA1swich1,PA1swich2,PA2swich1,PA2swich2,Spectrumswich,Powermeterswich,Couplerswich,Pimswich,Txoutswich,couplerswichCg8090,modeswich1Cg8090,modeswich2Cg8090,PimswichCg8090,TxoutswichCg8090\n"\
"\n"\
"Signal1swich        =PA1in1,PA2in1,PA3in1,PA4in1\n"\
"PA1in1=1\n"\
"PA2in1=2\n"\
"PA3in1=3\n"\
"PA4in1=4\n"\
"\n"\
"Signal2swich        =PA1in2,PA2in2,PA3in2,PA4in2\n"\
"PA1in2=1\n"\
"PA2in2=2\n"\
"PA3in2=3\n"\
"PA4in2=4\n"\
"\n"\
"PA1swich1           =MDlte700tx1,MDdd800tx1,MDgsm900tx1 \n"\
"MDlte700tx1=1\n"\
"MDdd800tx1=2\n"\
"MDgsm900tx1=3\n"\
"\n"\
"PA1swich2           =MDlte700tx2,MDdd800tx2,MDgsm900tx2\n"\
"MDlte700tx2=1\n"\
"MDdd800tx2=2\n"\
"MDgsm900tx2=3\n"\
"\n"\
"PA2swich1           =MDdcs1800tx1,MDpcs1900tx1,MDwcdma2100tx1\n"\
"MDdcs1800tx1=1\n"\
"MDpcs1900tx1=2\n"\
"MDwcdma2100tx1=3\n"\
"\n"\
"PA2swich2           =MDdcs1800tx2,MDpcs1900tx2,MDwcdma2100tx2\n"\
"MDdcs1800tx2=1\n"\
"MDpcs1900tx2=2\n"\
"MDwcdma2100tx2=3 \n"\
"\n"\
"Spectrumswich       =MDlte700pim,MDdd800tpim,MDgsm900pim,MDdcs1800pim,MDpcs1900pim,MDwcdma2100pim,MDwcdma2600pim,MD1500pim\n"\
"MDlte700pim=1\n"\
"MDdd800tpim=2\n"\
"MDgsm900pim=3\n"\
"MDdcs1800pim=4\n"\
"MDpcs1900pim=5\n"\
"MDwcdma2100pim=6\n"\
"MDwcdma2600pim=7\n"\
"MD1500pim=8\n"\
"\n"\
"Powermeterswich     =MDlte700pwmt,MDdd800tpwmt,MDgsm900pwmt,MDdcs1800pwmt,MDpcs1900pwmt,MDwcdma2100pwmt,MDwcdma2600pwmt,MD1500ppwmt\n"\
"MDlte700pwmt=1\n"\
"MDdd800tpwmt=2\n"\
"MDgsm900pwmt=3\n"\
"MDdcs1800pwmt=4\n"\
"MDpcs1900pwmt=5\n"\
"MDwcdma2100pwmt=6\n"\
"MDwcdma2600pwmt=7\n"\
"MD1500ppwmt=8\n"\
"\n"\
"Couplerswich        =nc1,no2 \n"\
"Pimswich            =nc1,no2\n"\
"Txoutswich          =nc1,no2\n"\
"\n"\
"couplerswichCg8090  =nc1,no2\n"\
"modeswich1Cg8090    =nc1,no2\n"\
"modeswich2Cg8090    =nc1,no2\n"\
"nc1=1\n"\
"no2=2\n"\
"\n"\
"PimswichCg8090   =cdma800rxA,cdma800rxB,gsm900rxA,gsm900rxB\n"\
"cdma800rxA=1\n"\
"cdma800rxB=2\n"\
"gsm900rxA=3\n"\
"gsm900rxB=4\n"\
"\n"\
"TxoutswichCg8090 =cdma800txA,cdma800txB,gsm900txA,gsm900txB\n"\
"cdma800txA=1\n"\
"cdma800txB=2\n"\
"gsm900txA=3\n"\
"gsm900txB=4\n"\
"\n"\
"[actiontx1]\n"\
"namelist 	=lte700Atx1,Lte700Btx1,DD800Atx1,DD800Btx1,GSM900Atx1,GSM900Btx1,Dcs1800Atx1,Dcs1800Btx1,Pcs1900Atx1,Pcs1900Btx1,Wcdma2100Atx1,Wcdma2100Btx1,Lte2600Atx1,Lte2600Btx1,Gpp1500Atx1,Gpp1500Btx1,Cdma800Atx1,Cdma800Btx1,GSM9002Atx1,GSM9002Btx1\n"\
"\n"\
"lte700Atx1 	= Signal1swich(Signalswich,PA1in1) ,PA1swich1(Paspecumpwmt,MDlte700tx1),  Txoutswich(Testmdlte700 ,nc1) \n"\
"\n"\
"Lte700Btx1 	= Signal1swich(Signalswich,PA1in1) ,PA1swich1(Paspecumpwmt,MDlte700tx1),  Txoutswich(Testmdlte700 ,no2) \n"\
"\n"\
"DD800Atx1  	= Signal1swich(Signalswich,PA1in1) ,PA1swich1(Paspecumpwmt,MDdd800tx1),   Txoutswich(Testmddd800 ,nc1) \n"\
"\n"\
"DD800Btx1  	= Signal1swich(Signalswich,PA1in1) ,PA1swich1(Paspecumpwmt,MDdd800tx1),   Txoutswich(Testmddd800 ,no2) \n"\
"\n"\
"GSM900Atx1  	= Signal1swich(Signalswich,PA1in1) ,PA1swich1(Paspecumpwmt,MDgsm900tx1),  Txoutswich(Testmdgsm900 ,nc1) \n"\
"\n"\
"GSM900Btx1  	= Signal1swich(Signalswich,PA1in1) ,PA1swich1(Paspecumpwmt,MDgsm900tx1),  Txoutswich(Testmdgsm900 ,no2) \n"\
"\n"\
"Dcs1800Atx1 	= Signal1swich(Signalswich,PA2in1) ,PA2swich1(Paspecumpwmt,MDdcs1800tx1), Txoutswich(Testmddcs1800 ,nc1) \n"\
"\n"\
"Dcs1800Btx1 	= Signal1swich(Signalswich,PA2in1) ,PA2swich1(Paspecumpwmt,MDdcs1800tx1), Txoutswich(Testmddcs1800 ,no2) \n"\
"\n"\
"Pcs1900Atx1 	= Signal1swich(Signalswich,PA2in1) ,PA2swich1(Paspecumpwmt,MDpcs1900tx1), Txoutswich(Testmdpcs1900 ,nc1) \n"\
"\n"\
"Pcs1900Btx1 	= Signal1swich(Signalswich,PA2in1) ,PA2swich1(Paspecumpwmt,MDpcs1900tx1), Txoutswich(Testmdpcs1900  ,no2) \n"\
"\n"\
"Wcdma2100Atx1 	= Signal1swich(Signalswich,PA2in1) ,PA2swich1(Paspecumpwmt,MDwcdma2100tx1), Txoutswich(Testmdwcdma2100 ,nc1)\n"\
"\n"\
"Wcdma2100Btx1 	= Signal1swich(Signalswich,PA2in1) ,PA2swich1(Paspecumpwmt,MDwcdma2100tx1), Txoutswich(Testmdwcdma2100 ,no2) \n"\
"\n"\
"Lte2600Atx1 	= Signal1swich(Signalswich,PA3in1) , Txoutswich(Testmdlte2600  ,nc1) \n"\
"\n"\
"Lte2600Btx1 	= Signal1swich(Signalswich,PA3in1) , Txoutswich(Testmdlte2600  ,no2) \n"\
"\n"\
"Gpp1500Atx1     = Signal1swich(Signalswich,PA4in1) , Txoutswich(Testmdpdc1500 ,nc1)\n"\
"\n"\
"Gpp1500Btx1     = Signal1swich(Signalswich,PA4in1) , Txoutswich(Testmdpdc1500 ,no2)\n"\
"\n"\
"Cdma800Atx1  = Signal1swich(Signalswich,PA1in1) , PA1swich1(Paspecumpwmt,MDgsm900tx1),TxoutswichCg8090(Testmdcg8090 ,cdma800txA), modeswich1Cg8090(Testmdcg8090,nc1)\n"\
"\n"\
"Cdma800Btx1   = Signal1swich(Signalswich,PA1in1) , PA1swich1(Paspecumpwmt,MDgsm900tx1),TxoutswichCg8090(Testmdcg8090 ,cdma800txB), modeswich2Cg8090(Testmdcg8090,nc1) \n"\
"\n"\
"GSM9002Atx1  = Signal1swich(Signalswich,PA1in1) , PA1swich1(Paspecumpwmt,MDgsm900tx1),TxoutswichCg8090(Testmdcg8090 ,gsm900txA),  modeswich1Cg8090(Testmdcg8090,no2)\n"\
"\n"\
"GSM9002Btx1   = Signal1swich(Signalswich,PA1in1) , PA1swich1(Paspecumpwmt,MDgsm900tx1),TxoutswichCg8090(Testmdcg8090 ,gsm900txB),  modeswich2Cg8090(Testmdcg8090,no2)\n"\
"[actiontx2]\n"\
"\n"\
"namelist 	=lte700Atx2,Lte700Btx2,DD800Atx2,DD800Btx2,GSM900Atx2,GSM900Btx2,Dcs1800Atx2,Dcs1800Btx2,Pcs1900Atx2,Pcs1900Btx2,Wcdma2100Atx2,Wcdma2100Btx2,Lte2600Atx2,Lte2600Btx2,Gpp1500Atx2,Gpp1500Btx2,Cdma800Atx2,Cdma800Btx2,GSM9002Atx2,GSM9002Btx2\n"\
"\n"\
"lte700Atx2 	= Signal2swich(Signalswich,PA1in2) ,PA1swich2(Paspecumpwmt,MDlte700tx2), Txoutswich(Testmdlte700 ,nc1) \n"\
"\n"\
"Lte700Btx2 	= Signal2swich(Signalswich,PA1in2) ,PA1swich2(Paspecumpwmt,MDlte700tx2), Txoutswich(Testmdlte700 ,no2) \n"\
"\n"\
"DD800Atx2  	= Signal2swich(Signalswich,PA1in2) ,PA1swich2(Paspecumpwmt,MDdd800tx2), Txoutswich(Testmddd800 ,nc1) \n"\
"\n"\
"DD800Btx2  	= Signal2swich(Signalswich,PA1in2) ,PA1swich2(Paspecumpwmt,MDdd800tx2), Txoutswich(Testmddd800 ,no2)\n"\
"\n"\
"GSM900Atx2  	= Signal2swich(Signalswich,PA1in2) ,PA1swich2(Paspecumpwmt,MDgsm900tx2),Txoutswich(Testmdgsm900 ,nc1) \n"\
"\n"\
"GSM900Btx2  	= Signal2swich(Signalswich,PA1in2) ,PA1swich2(Paspecumpwmt,MDgsm900tx2),Txoutswich(Testmdgsm900 ,no2) \n"\
"\n"\
"Dcs1800Atx2 	= Signal2swich(Signalswich,PA2in2) ,PA2swich2(Paspecumpwmt,MDdcs1800tx2),Txoutswich(Testmddcs1800 ,nc1) \n"\
"\n"\
"Dcs1800Btx2 	= Signal2swich(Signalswich,PA2in2) ,PA2swich2(Paspecumpwmt,MDdcs1800tx2),Txoutswich(Testmddcs1800 ,no2) \n"\
"\n"\
"Pcs1900Atx2 	= Signal2swich(Signalswich,PA2in2) ,PA2swich2(Paspecumpwmt,MDpcs1900tx2),Txoutswich(Testmdpcs1900  ,nc1) \n"\
"\n"\
"Pcs1900Btx2 	= Signal2swich(Signalswich,PA2in2) ,PA2swich2(Paspecumpwmt,MDpcs1900tx2),Txoutswich(Testmdpcs1900  ,no2) \n"\
"\n"\
"Wcdma2100Atx2 	= Signal2swich(Signalswich,PA2in2) ,PA2swich2(Paspecumpwmt,MDwcdma2100tx2), Txoutswich(Testmdwcdma2100 ,nc1) \n"\
"\n"\
"Wcdma2100Btx2 	= Signal2swich(Signalswich,PA2in2) ,PA2swich2(Paspecumpwmt,MDwcdma2100tx2), Txoutswich(Testmdwcdma2100 ,no2) \n"\
"\n"\
"Lte2600Atx2 	= Signal2swich(Signalswich,PA3in2) ,Txoutswich(Testmdlte2600  ,nc1) \n"\
"\n"\
"Lte2600Btx2 	= Signal2swich(Signalswich,PA3in2) ,Txoutswich(Testmdlte2600  ,no2) \n"\
"\n"\
"Gpp1500Atx2     = Signal2swich(Signalswich,PA4in2) , Txoutswich(Testmdpdc1500 ,nc1)\n"\
"\n"\
"Gpp1500Btx2    = Signal2swich(Signalswich,PA4in2) , Txoutswich(Testmdpdc1500 ,no2)\n"\
"\n"\
"Cdma800Atx2    = Signal2swich(Signalswich,PA1in2) ,PA1swich2(Paspecumpwmt,MDgsm900tx2),   TxoutswichCg8090(Testmdcg8090 ,cdma800txA), modeswich1Cg8090(Testmdcg8090,nc1)\n"\
"\n"\
"Cdma800Btx2    = Signal2swich(Signalswich,PA1in2) ,PA1swich2(Paspecumpwmt,MDgsm900tx2),   TxoutswichCg8090(Testmdcg8090 ,cdma800txB), modeswich2Cg8090(Testmdcg8090,nc1)\n"\
"\n"\
"GSM9002Atx2    = Signal2swich(Signalswich,PA1in2) ,PA1swich2(Paspecumpwmt,MDgsm900tx2),   TxoutswichCg8090(Testmdcg8090 ,gsm900txA), modeswich1Cg8090(Testmdcg8090,no2)\n"\
"\n"\
"GSM9002Btx2    = Signal2swich(Signalswich,PA1in2) ,PA1swich2(Paspecumpwmt,MDgsm900tx2),   TxoutswichCg8090(Testmdcg8090 ,gsm900txB), modeswich2Cg8090(Testmdcg8090,no2)\n"\
"\n"\
"[actionpim]\n"\
"namelist 	=lte700Apim,Lte700Bpim,DD800Apim,DD800Bpim,GSM900Apim,GSM900Bpim,Dcs1800Apim,Dcs1800Bpim,Pcs1900Apim,Pcs1900Bpim,Wcdma2100Apim,Wcdma2100Bpim,Lte2600Apim,Lte2600Bpim,Gpp1500Apim,Gpp1500Bpim,Cdma800Apim,Cdma800Bpim,GSM9002Apim,GSM9002Bpim\n"\
"\n"\
"lte700Apim 	= Spectrumswich(Paspecumpwmt,MDlte700pim),Pimswich( Testmdlte700, nc1)\n"\
"\n"\
"Lte700Bpim 	= Spectrumswich(Paspecumpwmt,MDlte700pim),Pimswich( Testmdlte700, no2)\n"\
"\n"\
"DD800Apim  	= Spectrumswich(Paspecumpwmt,MDdd800tpim),Pimswich( Testmddd800, nc1)\n"\
"\n"\
"DD800Bpim  	= Spectrumswich(Paspecumpwmt,MDdd800tpim),Pimswich( Testmddd800, no2)\n"\
"\n"\
"GSM900Apim  	= Spectrumswich(Paspecumpwmt,MDgsm900pim),Pimswich( Testmdgsm900, nc1)\n"\
"\n"\
"GSM900Bpim  	= Spectrumswich(Paspecumpwmt,MDgsm900pim),Pimswich( Testmdgsm900, no2)\n"\
"\n"\
"Dcs1800Apim 	= Spectrumswich(Paspecumpwmt,MDdcs1800pim),Pimswich( Testmddcs1800 , nc1)\n"\
"\n"\
"Dcs1800Bpim 	= Spectrumswich(Paspecumpwmt,MDdcs1800pim),Pimswich( Testmddcs1800 , no2)\n"\
"\n"\
"Pcs1900Apim 	= Spectrumswich(Paspecumpwmt,MDpcs1900pim),Pimswich( Testmdpcs1900  , nc1)\n"\
"\n"\
"Pcs1900Bpim	= Spectrumswich(Paspecumpwmt,MDpcs1900pim),Pimswich( Testmdpcs1900  , no2)\n"\
"\n"\
"Wcdma2100Apim 	= Spectrumswich(Paspecumpwmt,MDwcdma2100pim),Pimswich( Testmdwcdma2100 , nc1)\n"\
"\n"\
"Wcdma2100Bpim 	= Spectrumswich(Paspecumpwmt,MDwcdma2100pim),Pimswich( Testmdwcdma2100 , no2)\n"\
"\n"\
"Lte2600Apim 	= Spectrumswich(Paspecumpwmt,MDwcdma2600pim),Pimswich( Testmdlte2600  , nc1)\n"\
"\n"\
"Lte2600Bpim 	= Spectrumswich(Paspecumpwmt,MDwcdma2600pim),Pimswich( Testmdlte2600  , no2)\n"\
"\n"\
"Gpp1500Apim 	= Spectrumswich(Paspecumpwmt,MD1500pim),Pimswich(Testmdpdc1500, nc1)\n"\
"\n"\
"Gpp1500Bpim 	= Spectrumswich(Paspecumpwmt,MD1500pim),Pimswich(Testmdpdc1500, no2)\n"\
"\n"\
"Cdma800Apim   = Spectrumswich(Paspecumpwmt,MDgsm900pim), PimswichCg8090 (Testmdcg8090, cdma800rxA), modeswich1Cg8090(Testmdcg8090,nc1)\n"\
"\n"\
"Cdma800Bpim   = Spectrumswich(Paspecumpwmt,MDgsm900pim), PimswichCg8090 (Testmdcg8090, cdma800rxB), modeswich2Cg8090(Testmdcg8090,nc1)\n"\
"\n"\
"GSM9002Apim   = Spectrumswich(Paspecumpwmt,MDgsm900pim), PimswichCg8090 (Testmdcg8090, gsm900rxA), modeswich1Cg8090(Testmdcg8090,no2)\n"\
"\n"\
"GSM9002Bpim   = Spectrumswich(Paspecumpwmt,MDgsm900pim), PimswichCg8090 (Testmdcg8090, gsm900rxB), modeswich2Cg8090(Testmdcg8090,no2)\n"\
"\n"\
"[actiondet]\n"\
"namelist 		=lte700tx1det,lte700tx2det,DD800tx1det,DD800tx2det,GSM900tx1det,GSM900tx2det,Dcs1800tx1det,Dcs1800tx2det,Pcs1900tx1det,Pcs1900tx2det,Wcdma2100tx1det,Wcdma2100tx2det,Lte2600tx1det,Lte2600tx2det,Gpp1500tx1det,Gpp1500tx2det,Cdma800tx1det,Cdma800tx2det,GSM9002tx1det,GSM9002tx2det\n"\
"\n"\
"lte700tx1det  	= Powermeterswich(Paspecumpwmt,MDlte700pwmt),    Couplerswich( Testmdlte700,nc1)\n"\
"\n"\
"lte700tx2det  	= Powermeterswich(Paspecumpwmt,MDlte700pwmt),    Couplerswich( Testmdlte700,no2)\n"\
"\n"\
"DD800tx1det   	= Powermeterswich(Paspecumpwmt,MDdd800tpwmt),    Couplerswich( Testmddd800,nc1)\n"\
"\n"\
"DD800tx2det   	= Powermeterswich(Paspecumpwmt,MDdd800tpwmt),    Couplerswich( Testmddd800,no2)\n"\
"\n"\
"GSM900tx1det  	= Powermeterswich(Paspecumpwmt,MDgsm900pwmt),    Couplerswich( Testmdgsm900,nc1)\n"\
"\n"\
"GSM900tx2det  	= Powermeterswich(Paspecumpwmt,MDgsm900pwmt),    Couplerswich( Testmdgsm900,no2)\n"\
"\n"\
"Dcs1800tx1det  	= Powermeterswich(Paspecumpwmt,MDdcs1800pwmt),   Couplerswich( Testmddcs1800,nc1)\n"\
"\n"\
"Dcs1800tx2det  	= Powermeterswich(Paspecumpwmt,MDdcs1800pwmt),   Couplerswich( Testmddcs1800,no2)\n"\
"\n"\
"Pcs1900tx1det  	= Powermeterswich(Paspecumpwmt,MDpcs1900pwmt),   Couplerswich( Testmdpcs1900,nc1)\n"\
"\n"\
"Pcs1900tx2det  	= Powermeterswich(Paspecumpwmt,MDpcs1900pwmt),   Couplerswich( Testmdpcs1900,no2)\n"\
"\n"\
"Wcdma2100tx1det	= Powermeterswich(Paspecumpwmt,MDwcdma2100pwmt), Couplerswich( Testmdwcdma2100,nc1)\n"\
"\n"\
"Wcdma2100tx2det	= Powermeterswich(Paspecumpwmt,MDwcdma2100pwmt), Couplerswich( Testmdwcdma2100,no2)\n"\
"\n"\
"Lte2600tx1det 	= Powermeterswich(Paspecumpwmt,MDwcdma2600pwmt), Couplerswich( Testmdlte2600,nc1)\n"\
"\n"\
"Lte2600tx2det 	= Powermeterswich(Paspecumpwmt,MDwcdma2600pwmt), Couplerswich( Testmdlte2600,no2)\n"\
"\n"\
"Gpp1500tx1det = Powermeterswich(Paspecumpwmt,MD1500ppwmt), Couplerswich(Testmdpdc1500,nc1)\n"\
"\n"\
"Gpp1500tx2det = Powermeterswich(Paspecumpwmt,MD1500ppwmt), Couplerswich(Testmdpdc1500,no2)\n"\
"\n"\
"Cdma800tx1det = Powermeterswich(Paspecumpwmt,MDgsm900pwmt), couplerswichCg8090(Testmdcg8090,nc1)\n"\
"\n"\
"Cdma800tx2det = Powermeterswich(Paspecumpwmt,MDgsm900pwmt), couplerswichCg8090(Testmdcg8090,no2)\n"\
"\n"\
"GSM9002tx1det = Powermeterswich(Paspecumpwmt,MDgsm900pwmt), couplerswichCg8090(Testmdcg8090,nc1)\n"\
"\n"\
"GSM9002tx2det = Powermeterswich(Paspecumpwmt,MDgsm900pwmt), couplerswichCg8090(Testmdcg8090,no2)\n"\
"\n"\

#endif
