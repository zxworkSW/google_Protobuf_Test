#ifndef __PROTOBUFBASIC_H__
#define __PROTOBUFBASIC_H__

#include <google/protobuf/message.h>

class CProtubufBasic
{
public:
	CProtubufBasic():
	p_arraysendbuffer(nullptr),
	m_arraysendbuffersize(0),
	m_strsendbuffer(""),
	m_isSerializeToArray(true)
	{};
	CProtubufBasic(bool serialize) :
	p_arraysendbuffer(nullptr),
	m_arraysendbuffersize(0),
	m_strsendbuffer(""),
	m_isSerializeToArray(serialize)
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
	bool isSerializeToArray() { return m_isSerializeToArray; }
	bool protobufsend(google::protobuf::Message &buffmessage);
	bool  protobufreceive(google::protobuf::Message &buffmessage);
	void clean()
	{
		if (m_isSerializeToArray)
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

private:
	char *p_arraysendbuffer;
	int m_arraysendbuffersize;
	std::string m_strsendbuffer;

	bool m_isSerializeToArray;
};

class CUserinfo
{
public:
	CUserinfo():m_username(""),m_number(0){}
	~CUserinfo(){ m_username.clear(); m_number = 0; }
	
	void set_username(const std::string &name){ m_username = name; }
	std::string &get_username(){ return m_username; }
	void set_number(int number){ m_number = number; }
	int get_number(){ return m_number; }

private:
	std::string m_username;
	int m_number;
};




#endif

