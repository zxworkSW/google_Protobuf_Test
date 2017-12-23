#ifndef __PROTOBUFTEST_H__
#define __PROTOBUFTEST_H__

#include <iostream>
#include "protobufbasic.h"

class CUserinfo
{
public:
	CUserinfo() :m_username(""), m_number(0) {}
	~CUserinfo() { m_username.clear(); m_number = 0; }

	void set_username(const std::string &name) { m_username = name; }
	std::string &get_username() { return m_username; }
	void set_number(int number) { m_number = number; }
	int get_number() { return m_number; }

private:
	std::string m_username;
	int m_number;
};

namespace zxtest
{
	using namespace protobufbasic;
	class CProtobuf : public CProtubufBasic
	{
	public:
		CProtobuf() {};
		CProtobuf(bool serialize) :CProtubufBasic(serialize) {};
		~CProtobuf() {};

		bool protosend(const std::string &name, int number);
		bool protosendArray(const std::string &name, std::vector<CUserinfo> &Users);
		bool protosendMsg(const std::string &sendMsgname, const std::string &sendArrayname, std::vector<CUserinfo> &Users);
		bool protosendArrayMsg(const std::string &sendMsgname, const std::string &sendArrayname, std::vector<std::vector<CUserinfo>> &MsgUsers);
		bool protosendImport(const std::string &name, CUserinfo &user_info, const std::string &log_info);

		bool proreceive();
		bool proreceiveArray();
		bool proreceiveMsg();
		bool proreceiveArrayMsg();
		bool proreceiveImport();

		void getaskreceive();
	};
}
#endif


