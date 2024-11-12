#include "IVT.h"

QMutex mutex_plc;

IVT::IVT() {}

IVT::~IVT() {}

void IVT::getSN(int DBnumber, int start) {
	// Interact with PLC
	QMutexLocker locker(&mutex_plc);
	try {
		m_sn = GlobalPlc->DBRead_String(DBnumber, start);
	}
	catch (std::exception& e) {
		std::string errMsg = std::string("[Get SN] ") + e.what();
		throw std::exception(errMsg.c_str());
	}

	// Check m_sn
	if(0)	
		throw std::invalid_argument("Wrong sn!");
}

std::string IVT::getSN()
{
	return m_sn;
}

bool IVT::initPower(QString com) {
	GlobalItech = new ItechControl(NULL);
	bool ret = GlobalItech->Init(com);
	GlobalItech->InitItech();
	return ret;
}

void IVT::checkMes(int id) {
	QMutexLocker locker(&mutex_plc);
	// Interact with plc	
}

std::pair<int, std::string> IVT::checkInternalStatus() {
	return std::make_pair(1, "Internal Error");
}
