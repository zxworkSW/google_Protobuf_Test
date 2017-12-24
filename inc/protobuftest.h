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
	class CProtobuf : public protobufbasic::CProtubufBasic
	{
	public:
		CProtobuf() {};
		CProtobuf(bool serialize) :protobufbasic::CProtubufBasic(serialize) {};
		virtual ~CProtobuf() {};

		bool protosend(const std::string &name, int number);
		virtual bool protoreceive();

		void getaskreceive();
	};
}

namespace zxtest
{
	class CProtobufArray : public CProtobuf
	{
	public:
		CProtobufArray() {};
		CProtobufArray(bool serialize) :CProtobuf(serialize) {};
		~CProtobufArray() {};

		bool protosend(const std::string &name, std::vector<CUserinfo> &Users);
		bool protoreceive();
	};
}

namespace zxtest
{
	class CProtobufMsg : public CProtobuf
	{
	public:
		CProtobufMsg() {};
		CProtobufMsg(bool serialize) :CProtobuf(serialize) {};
		~CProtobufMsg() {};

		bool protosend(const std::string &sendMsgname, const std::string &sendArrayname, std::vector<CUserinfo> &Users);
		bool protoreceive();
	};
}

namespace zxtest
{
	class CProtobufArrayMsg : public CProtobuf
	{
	public:
		CProtobufArrayMsg() {};
		CProtobufArrayMsg(bool serialize) :CProtobuf(serialize) {};
		~CProtobufArrayMsg() {};

		bool protosend(const std::string &sendMsgname, const std::string &sendArrayname, std::vector<std::vector<CUserinfo>> &MsgUsers);
		bool protoreceive();
	};
}

namespace zxtest
{
	class CProtobufImport : public CProtobuf
	{
	public:
		CProtobufImport() {};
		CProtobufImport(bool serialize) :CProtobuf(serialize) {};
		~CProtobufImport() {};

		bool protosend(const std::string &name, CUserinfo &user_info, const std::string &log_info);
		bool protoreceive();
	};
}

#endif


