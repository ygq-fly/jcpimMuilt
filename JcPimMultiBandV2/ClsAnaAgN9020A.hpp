#ifndef _CLS_AGN9020A_HPP_
#define _CLS_AGN9020A_HPP_

#include "ClsVisa.hpp"
#include "IfAnalyzer.hpp"

#define eNULL 0

class ClsAnaAgN9020A : public ClsVisa, Implements_ IfAnalyzer
{
public:
	enum eParam
	{
		SPAN,
		CENTER,
		REFLEVEL,
		ATT,
		RBW,
		VBW,
		MARK_X,
		MARK_MAX,
		MARK_POS
	};

public:
	ClsAnaAgN9020A(bool isPreamp)
		:_isCmdSucc(false)
		,_freq_now(eNULL)
		, _isNeedPreamp(isPreamp)
		,ClsVisa()
	{}

	~ClsAnaAgN9020A() {

	}

public:
	bool InstrConnect(const char* c_addr){
		bool isconn = AgConnect(c_addr);
		//���ӳɹ�����ʼ��ʼ��
		//if (isconn)
		//	InstrInit();
		return isconn;
	}

	void InstrSession(unsigned long viConnectedSession, const char* cIdn) {
		AgSession(viConnectedSession, cIdn);
		//���ӳɹ�����ʼ��ʼ��
		//InstrInit();
	}

	bool InstrWrite(const char* c_cmd) {
		return AgWrite(c_cmd);
	}

	long InstrWriteAndRead(const char* c_cmd, char* rbuf) {
		return AgWriteAndRead(c_cmd, rbuf);
	}

	bool InstrConnStatus() const {
		return AgConnStatus();
	}

	void InstrClose() {
		AgClose();
	}

public:
	void InstrSetModeAtt(int pim_att, int offset_att) {
		m_pim_att = pim_att;
		m_offset_att = offset_att;
	}

	//��ʼ��ʼ��
	void InstrInit() {
		AgWrite("*RST\n");
		InstrPimSetting();
		SetParam(eParam::MARK_POS, eNULL);
		if (GetSpeIndex() == 0)
			AgWrite("MARK1:PEAK\n");
		SetParam(eParam::CENTER, 637 * 1000);
	}

	//��ʼ��ȡ
	double InstrGetAnalyzer(double freq_khz, bool isMax) {
		double result_val = 0;
		//if (freq_khz != _freq_now){
			InstrSetCenterFreq(freq_khz);
			_freq_now = freq_khz;
		//}	

		//���״̬
		_isCmdSucc = AgWrite("*CLS\n");
		//ִ��ɨ��
		_isCmdSucc = AgWrite("INIT:IMM\n");
		//��ʼ�ȴ�
		if (AgWait() == false)
			return -10000;
	
		//��ȡ
		result_val = ReadMarkY(isMax);
		return result_val;
	}

	//����ƽ������
	void InstrSetAvg(const int& avg_time) {
		AgWrite("AVER:TYPE RMS\n");
		if (avg_time > 0){
			std::string cmd = "AVER:COUN " + std::to_string(avg_time) + "\n";
			AgWrite(cmd.c_str());
			//AgWrite("AVER:STAT ON\n");
		}
		else {
			AgWrite("AVER:STAT OFF\n");
		}
	}

	void InstrClosgAvg() {
		AgWrite("AVER:STAT OFF\n");
	}

	//����offset
	void InstrSetOffset(const double& pow_db) {
		std::string cmd = "DISP:WIND:TRAC:Y:RLEV:OFFS " + std::to_string(pow_db) + "\n";
		AgWrite(cmd.c_str());
	}

	//����att����
	void InstrSetAtt(const int& att) {
		SetParam(eParam::ATT, att);		
	}

	//����ref����
	void InstrSetRef(const int& reflevel) {
		SetParam(eParam::REFLEVEL, reflevel);
	}

	//����rbw����
	void InstrSetRbw(const double& rbw_hz) {
		SetParam(eParam::RBW, rbw_hz);
	}

	//����vbw����
	void InstrSetVbw(const double& vbw_hz) {
		SetParam(eParam::VBW, vbw_hz);
	}

	//����span����
	void InstrSetSpan(const double& span_hz) {
		SetParam(eParam::SPAN, span_hz);
	}

	//��������Ƶ��
	void InstrSetCenterFreq(const double& freq_khz) {
		SetParam(eParam::CENTER, freq_khz);
		SetParam(eParam::MARK_X, freq_khz);
	}

	void InstrSetPreamp(bool isOn) {
		if (!_isNeedPreamp) {
			AgWrite(":POW:GAIN OFF\n");
			return;
		}

		if (isOn) {
			//��ʼԤ��
			AgWrite(":POW:GAIN ON\n");
			if (GetSpeIndex() != 2)
				AgWrite(":POW:GAIN:BAND LOW\n");
		}
		else {
			//�ر�Ԥ��
			AgWrite(":POW:GAIN OFF\n");
		}
	}

	//��������
	void InstrPimSetting() {
		InstrSetOffset(0);
		InstrSetPreamp(true);

		InstrSetRef(-60);
		InstrClosgAvg();

		//moshi att
		InstrSetAtt(m_pim_att < 0 ? 0 : m_pim_att);

		//jcspe
		if (GetSpeIndex() == 0) {
			InstrSetSpan(10 * 1000);
			InstrSetRbw(1000);
			InstrSetVbw(1000);
		}
		//aglient
		else {
			InstrSetSpan(500);
			InstrSetRbw(10);
			InstrSetVbw(10);
		}
	}
	
	void InstrVcoSetting() {
		//OFFSET����
		InstrSetOffset(0);
		InstrSetPreamp(true);

		//jcspe
		if (GetSpeIndex() == 0) {
			InstrSetSpan(10 * 1000);
			InstrSetRbw(1000);
			InstrSetVbw(1000);
		}
		//aglient
		else {
			InstrSetSpan(15 * 1000);
			InstrSetRbw(100);
			InstrSetVbw(100);
		}
	}
	void InstrTxOffsetSetting() {
		//OFFSET����
		InstrSetOffset(0);
		InstrSetPreamp(false);
		InstrSetRef(10);
		InstrClosgAvg();

		//moshi att
		InstrSetAtt(m_offset_att < 0 ? 40 : m_offset_att);

		//jcspe
		if (GetSpeIndex() == 0) {
			InstrSetSpan(10 * 1000);
			InstrSetRbw(1000);
			InstrSetVbw(1000);

		} 
		//aglient
		else {
			InstrSetSpan(1000);
			InstrSetRbw(100);
			InstrSetVbw(100);
		}
	}
	void InstrRxOffsetSetting() {
		InstrPimSetting();
	}

private:
	//��ȡMARK
	double ReadMarkY(bool isMax) {
		if (isMax || GetSpeIndex() == 2) SetParam(eParam::MARK_MAX, eNULL);

		//��ʼ��ȡ
		char buf[128] = {0};
		long retCount = 0;
		double val = -10000;
		retCount = AgWriteAndRead("CALC:MARK1:Y?\n", buf);
		//ת��
		if (retCount)
			val = atof(buf);
		return val;
	}

	//����
	bool SetParam(const eParam& param, const double& val) {
		std::stringstream sstemp;	
		switch (param)
		{
		case SPAN:
			sstemp << "FREQ:SPAN " << val << " Hz\n"; break;	
		case RBW:
			sstemp << "BAND " << val << " Hz\n"; break;
		case VBW:
			sstemp << "BAND:VID " << val << " Hz\n"; break;
		case CENTER:
			sstemp << "FREQ:CENT " << val << " kHz\n"; break;	
		case MARK_X:
			sstemp << "CALC:MARK1:X " << val << " kHz\n"; break;
		case REFLEVEL:
			sstemp << "DISPlay:WINDow:TRACe:Y:RLEVel " << val << " dBm\n"; break;		
		case ATT:
			sstemp << "POW:ATT " << val << " dB\n"; break;		
		case MARK_MAX:
			sstemp << "CALC:MARK1:MAX" << "\n"; break;
		case MARK_POS:
			sstemp << "CALC:MARK1:MODE POS" << "\n"; break;
		default:
			break;
		}
		
		std::string str = sstemp.str();
		_isCmdSucc = AgWrite(str.c_str());

		return _isCmdSucc;
	}

	int GetSpeIndex() {
		if (Util::strFind(_strIDN, "JCSPE"))
			return 0;
		else if (Util::strFind(_strIDN, "E4407"))
			return 2;
		else
			return 1;
	}
	
private:
	bool _isCmdSucc;
	double _freq_now;
	bool _isNeedPreamp;
	int m_pim_att;
	int m_offset_att;
	
};

#endif

