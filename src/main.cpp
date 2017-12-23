#include <iostream>
#include "protobuftest.h"

using namespace std;

#define ISARRAY 0

#if ISARRAY
#define SANDNAME std::string("Array")
#define MSGNAME std::string("MsgArray")
#else
#define SANDNAME std::string("String")
#define MSGNAME std::string("MsgString")
#endif

static void protobuf_send();
static void protobuf_sendarray();
static void protobuf_sendMsg();
static void protobuf_sendArrayMsg();
static void protobuf_sendImport();

void protobuf_test(void)
{
	//protobuf_send();
	//protobuf_sendarray();
	//protobuf_sendMsg();
	//protobuf_sendArrayMsg();
	protobuf_sendImport();
}

static void protobuf_send()
{
	zxtest::CProtobuf TeseProtobuf(ISARRAY);

	TeseProtobuf.protosend(SANDNAME, ISARRAY);
	TeseProtobuf.proreceive();
	TeseProtobuf.getaskreceive();
}

static void protobuf_sendarray()
{
	zxtest::CProtobuf TeseProtobuf(ISARRAY);

	std::vector<CUserinfo> Users;

	for (int i = 4; i < 9; i++)
	{
		CUserinfo addusers;
		addusers.set_number(i);
		std::string addname = "userarray num" + std::to_string(i);
		addusers.set_username(addname);
		Users.push_back(addusers);
	}

	TeseProtobuf.protosendArray(SANDNAME, Users);
	TeseProtobuf.proreceiveArray();
	TeseProtobuf.getaskreceive();
}

static void protobuf_sendMsg()
{
	zxtest::CProtobuf TeseProtobuf(ISARRAY);

	std::vector<CUserinfo> Users;

	for (int i = 7; i < 12; i++)
	{
		CUserinfo addusers;
		addusers.set_number(i);
		std::string addname = MSGNAME + ":" + std::to_string(i);
		addusers.set_username(addname);
		Users.push_back(addusers);
	}

	TeseProtobuf.protosendMsg(MSGNAME, SANDNAME, Users);
	TeseProtobuf.proreceiveMsg();
	TeseProtobuf.getaskreceive();
}

static void protobuf_sendArrayMsg()
{
	zxtest::CProtobuf TeseProtobuf(ISARRAY);

	std::vector<std::vector<CUserinfo>> Usersgroup;
	for (int i = 0; i < 5; i++)
	{
		std::vector<CUserinfo> Users;
		for (int j = 4; j < 13; j += 2)
		{
			CUserinfo addusers;
			addusers.set_number(i + j);
			std::string addname = "userarray num " + std::to_string(i + j);
			addusers.set_username(addname);
			Users.push_back(addusers);
		}
		Usersgroup.push_back(Users);
	}


	TeseProtobuf.protosendArrayMsg(MSGNAME, SANDNAME, Usersgroup);
	TeseProtobuf.proreceiveArrayMsg();
	TeseProtobuf.getaskreceive();
}


static void protobuf_sendImport()
{
	zxtest::CProtobuf TeseProtobuf(ISARRAY);

	CUserinfo User;
	User.set_number(13);
	User.set_username("TestUser");
	std::string LogInfo("LogTest");

	TeseProtobuf.protosendImport(SANDNAME, User, LogInfo);
	TeseProtobuf.proreceiveImport();
	TeseProtobuf.getaskreceive();
}

int main(int argc, char **argv)
{
	protobuf_test();
	return 0;
}
