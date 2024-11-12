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
	  * \brief ��Ʒ�ϵ�
	  * \return �����ϵ���
	  */
	bool initPower(QString com);

	/**
	  * \brief ���MES��վ��� ��Ҫ��PLCȷ�ϼ�鷽ʽ
	  * \param[id] ��ǰվid
		�ݶ�id�б� �ڲ� ���&������  0
					   �Ƕ�		   1
				  EOL  ���߲���д�� 2
					   ���������� 3
					   ä������     4
					   �龯�ʲ���   5
					   ���⹦�ʲ��� 6

	  * \return ���ؼ����
	  */
	void checkMes(int id);

	/**
	  * \brief ����ڲ�״̬
	  * \return ���ؼ�������������ͱ�ţ������������˫��ȷ�ϣ�����0����ok��1�������ng
	  */
	std::pair<int, std::string> checkInternalStatus();

private:
	std::string m_sn = "";
};

