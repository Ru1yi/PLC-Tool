#pragma once

#include <string>
#include <map>
#include <utility>
#include <QMutex>

//	3rd Party Headers
#include "../Itech/ItechControl.h"
#include "../PlcControl/PlcControl.h"

extern QMutex mutex_plc;	// Avoid multiple threads accessing the plc at the same time

class IVT {
public:
	IVT();
	~IVT();
	/**
	  * \brief Get SN of product
	  * @param[in] DBnumber number of DB block
	  * @param[in] start offset of DB block
	  */
	void getSN(int DBnumber, int start);

	/**
	  * \brief Get m_sn value
	  * \return m_sn value
	  */
	std::string getSN();

	/**
	  * \brief 产品上电
	  * \return 返回上电结果
	  */
	bool initPower(QString com);

	/**
	  * \brief 检查MES过站情况 需要跟PLC确认检查方式
	  * \param[id] 当前站id
		暂定id列表 内参 深度&反射率  0
					   角度		   1
				  EOL  离线参数写入 2
					   测距能力检查 3
					   盲区测试     4
					   虚警率测试   5
					   激光功率测试 6

	  * \return 返回检查结果
	  */
	void checkMes(int id);

	/**
	  * \brief 检查内部状态
	  * \return 返回检查结果及故障类型编号，具体错误码表待双方确认，暂用0代表ok，1往后代表ng
	  */
	std::pair<int, std::string> checkInternalStatus();

private:
	std::string m_sn = "";
};

