#ifndef __PROTOBUFTEST_H__
#define __PROTOBUFTEST_H__

#include <iostream>
#include "test.pb.h"

void protobuf_test(void);


class CProtubufBasic
{
public:
	CProtubufBasic():
	p_arraysendbuffer(nullptr),
	m_arraysendbuffersize(0),
	m_strsendbuffer("")
	{};
	~CProtubufBasic()
	{
		if (p_arraysendbuffer)
		{
			delete p_arraysendbuffer;
		}
		p_arraysendbuffer = nullptr;

		m_arraysendbuffersize = 0;
		m_strsendbuffer.clear();
	};

	bool protobufsend(google::protobuf::Message &buffmessage, bool isSerializeToArray = true);
	bool  protobufreceive(google::protobuf::Message &buffmessage, bool isSerializeToArray = true);
	void clean(bool isSerializeToArray = true)
	{
		if (isSerializeToArray)
		{
			if (p_arraysendbuffer)
			{
				delete p_arraysendbuffer;
			}
			p_arraysendbuffer = nullptr;

			m_arraysendbuffersize = 0;
		}
		else
		{
			m_strsendbuffer.clear();
		}
	}

private:
	void protobufSerializeToArray(google::protobuf::Message &buffmessage);
	void protobufSerializeToString(google::protobuf::Message &buffmessage);
	void protobufreceiveFromArray(google::protobuf::Message &buffmessage);
	void protobufreceiveFromString(google::protobuf::Message &buffmessage);

public:
	char *p_arraysendbuffer;
	int m_arraysendbuffersize;
	std::string m_strsendbuffer;
};

class CUserinfo
{
public:
	CUserinfo():m_username(""),m_number(0){}
	~CUserinfo(){ m_username.clear(); m_number = 0; }

public:
	std::string m_username;
	int m_number;
};

class CProtobuf : public CProtubufBasic
{
public:
	CProtobuf(){};
	~CProtobuf(){};

	bool protosend(const std::string &name, int number, bool isSerializeToArray = true);
	bool protosend(const std::string &name, std::vector<CUserinfo> &Users, bool isSerializeToArray = true);
	bool protosend(const std::string &name, std::vector<std::vector<CUserinfo>> &MsgUsers, bool isSerializeToArray = true);
	bool proreceive(bool isSerializeToArray = true);
	void getaskreceive(bool isSerializeToArray = true);
};

#endif


