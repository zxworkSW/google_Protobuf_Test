#include "protobuftest.h"
#include "test.pb.h"

using namespace std;
using namespace zxtest;

const bool isArray = false;

void protobuf_test(void)
{
	CProtobuf TeseProtobuf;
	string sendname("");
	int sendnumber = 0;

	if (isArray)
	{
		sendname = "Array";
		sendnumber = 5;
	}
	else
	{
		sendname = "String";
		sendnumber = 6;
	}

	TeseProtobuf.protosend(sendname, sendnumber, isArray);
	TeseProtobuf.proreceive(isArray);
	//TeseProtobuf.getaskreceive(isArray);
}

bool CProtubufBasic::protobufsend(google::protobuf::Message &buffmessage, bool isSerializeToArray /*= true*/)
{
	try
	{
		clean(isSerializeToArray);

		if (isSerializeToArray)
			protobufSerializeToArray(buffmessage);
		else
			protobufSerializeToString(buffmessage);
	}
	catch (const std::string &err_mesg)
	{
		cout << err_mesg << endl;
		return false;
	}
	catch (...)
	{
		cout << __FUNCTION__ << "is error!!!" << endl;
		return false;
	}

	return true;
}
bool CProtubufBasic::protobufreceive(google::protobuf::Message &buffmessage, bool isSerializeToArray /*= true*/)
{
	try
	{
		if (isSerializeToArray)
			protobufreceiveFromArray(buffmessage);
		else
			protobufreceiveFromString(buffmessage);
	}
	catch (const std::string &err_mesg)
	{
		cout << err_mesg << endl;
		return false;
	}
	catch (...)
	{
		cout << __FUNCTION__ << "is error!!!" << endl;
		return false;
	}

	return true;
}
void CProtubufBasic::protobufSerializeToArray(google::protobuf::Message &buffmessage)
{
	m_arraysendbuffersize = buffmessage.ByteSize();
	if (0 == m_arraysendbuffersize)
		throw std::string("ByteSize is zero!!!");

	p_arraysendbuffer = new char[m_arraysendbuffersize];
	if (!p_arraysendbuffer)
		throw std::string("new buffer is error!!!");

	if (!buffmessage.SerializeToArray(p_arraysendbuffer, m_arraysendbuffersize))
	{
		delete p_arraysendbuffer;
		p_arraysendbuffer = nullptr;
		m_arraysendbuffersize = 0;
		throw std::string("SerializeToArray is error!!!");
	}
}
void CProtubufBasic::protobufSerializeToString(google::protobuf::Message &buffmessage)
{
#if 0
	m_strsendbuffer = buffmessage.SerializeAsString();
	if (m_strsendbuffer.empty())
	{
		throw std::string("SerializeAsString is error!!!");
	}
#else 
	if (!buffmessage.SerializeToString(&m_strsendbuffer))
		throw std::string("SerializeToString is error!!!");
#endif

}
void CProtubufBasic::protobufreceiveFromArray(google::protobuf::Message &buffmessage)
{
	if (!p_arraysendbuffer || 0 == m_arraysendbuffersize)
		throw std::string("get buffer is error!!!");
	
	if (!buffmessage.ParseFromArray(p_arraysendbuffer, m_arraysendbuffersize))
	{
		delete p_arraysendbuffer;
		p_arraysendbuffer = nullptr;
		m_arraysendbuffersize = 0;
		throw std::string("ParseFromArray is error!!!");
	}
}
void CProtubufBasic::protobufreceiveFromString(google::protobuf::Message &buffmessage)
{
	if (m_strsendbuffer.empty())
		throw std::string("get buffer is empty!!!");
	else if (!buffmessage.ParseFromString(m_strsendbuffer))
	{
		m_strsendbuffer.clear();
		throw std::string("ParseFromString is empty!!!");
	}
}

bool CProtobuf::protosend(const std::string &name, int number, bool isSerializeToArray /*= true*/)
{
	prototest::TestSend sendmsg;

	sendmsg.set_sname(name);
	sendmsg.set_u32number(number);
	sendmsg.set_isserializearray(isSerializeToArray);

	return this->protobufsend(sendmsg, isSerializeToArray);
}
bool CProtobuf::proreceive(bool isSerializeToArray  /*= true*/)
{
	prototest::TestSend getsand;
	prototest::TestReceive setresand;
	setresand.set_srename("reprotobuf");

	do
	{
		if (!protobufreceive(getsand, isSerializeToArray))
		{
			setresand.set_enumcode(prototest::Recode::ERROR);
			cout << "get buffer is error!!!" << endl;
			break;
		}

		cout << "sendname = "	<< getsand.sname() << endl;
		cout << "number   = "	<< getsand.u32number() << endl;
		cout << "is array = "	<< getsand.isserializearray() << endl;

		//setresand.set_enumcode(prototest::Recode::SUCCESS);
		

	} while (0);
	return true;
	//return this->protobufsend(setresand, isSerializeToArray);
}
void CProtobuf::getaskreceive(bool isSerializeToArray /* = true */)
{
	prototest::TestReceive getsand;

	if (!protobufreceive(getsand, isSerializeToArray))
	{
		cout << "get buffer is error!!!" << endl;
		return;
	}
	cout << __FUNCTION__ << " is called." << endl;
	cout << "code = " << getsand.enumcode() << endl;
	cout << "re username = " << getsand.srename() << endl;
}

