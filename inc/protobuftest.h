#ifndef __PROTOBUFTEST_H__
#define __PROTOBUFTEST_H__

#include <iostream>
#include "protobufbasic.h"

void protobuf_test(void);

class CProtobuf : public CProtubufBasic
{
public:
	CProtobuf(){};
	CProtobuf(bool serialize):CProtubufBasic(serialize){};
	~CProtobuf(){};

	bool protosend(const std::string &name, int number);
	bool protosendArray(const std::string &name, std::vector<CUserinfo> &Users);
	bool protosendMsg(const std::string &sendMsgname, const std::string &sendArrayname,std::vector<CUserinfo> &Users);
	bool protosendArrayMsg(const std::string &sendMsgname, const std::string &sendArrayname, std::vector<std::vector<CUserinfo>> &MsgUsers);
	bool protosendImport(const std::string &name, CUserinfo &user_info, const std::string &log_info);

	bool proreceive();
	bool proreceiveArray();
	bool proreceiveMsg();
	bool proreceiveArrayMsg();
	bool proreceiveImport();

	void getaskreceive();
};

#endif


