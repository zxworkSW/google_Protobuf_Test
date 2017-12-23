#include "protobuftest.h"
#include "test.pb.h"

using namespace std;


namespace zxtest
{
	bool CProtobuf::protosend(const std::string &name, int number)
	{
		if (name.empty())
			return false;

		prototest::TestSend sendmsg;

		sendmsg.set_sname(name);
		sendmsg.set_u32number(number);
		sendmsg.set_isserializearray(this->isSerializeToArray());

		return this->protobufsend(sendmsg);
	}

	bool CProtobuf::protosendArray(const std::string &name, std::vector<CUserinfo> &Users)
	{
		if (name.empty() || Users.empty())
			return true;

		prototest::TestSendArray sendmsg;

		sendmsg.set_sname(name);

		std::vector<CUserinfo>::iterator iter = Users.begin();
		while (iter != Users.end())
		{
			sendmsg.add_u32number(iter->get_number());
			sendmsg.add_usernames_array(iter->get_username());
			iter++;
		}
		sendmsg.add_usernames_array("end array");

		return this->protobufsend(sendmsg);
	}

	bool CProtobuf::protosendMsg(const std::string &sendMsgname, const std::string &sendArrayname, std::vector<CUserinfo> &Users)
	{
		if (sendMsgname.empty() || sendArrayname.empty() || Users.empty())
			return true;

		prototest::TestSendMsg sendmsg;

		sendmsg.set_smsg_name(sendMsgname);
		prototest::TestSendArray *send_msg = sendmsg.mutable_msg_info();
		if (!send_msg)
			return false;

		send_msg->set_sname(sendArrayname);
		std::vector<CUserinfo>::iterator iter = Users.begin();
		while (iter != Users.end())
		{
			send_msg->add_u32number(iter->get_number());
			send_msg->add_usernames_array(iter->get_username());
			iter++;
		}
		send_msg->add_usernames_array("end array");

		return this->protobufsend(sendmsg);
	}

	bool CProtobuf::protosendArrayMsg(const std::string &sendMsgname, const std::string &sendArrayname, std::vector<std::vector<CUserinfo>> &MsgUsers)
	{
		if (sendMsgname.empty() || sendArrayname.empty() || MsgUsers.empty())
			return true;

		prototest::TestSendArrayMsg sendmsg;

		sendmsg.set_smsg_name(sendMsgname);


		std::vector<std::vector<CUserinfo>>::iterator msgiter = MsgUsers.begin();
		while (msgiter != MsgUsers.end())
		{
			prototest::TestSendArray *send_msg = sendmsg.add_msg_array();
			if (!send_msg)
				return false;
			static int i = 6;
			send_msg->set_sname(sendArrayname + std::to_string(i));
			i++;
			std::vector<CUserinfo>::iterator iter = msgiter->begin();
			while (iter != msgiter->end())
			{
				send_msg->add_u32number(iter->get_number());
				send_msg->add_usernames_array(iter->get_username());
				iter++;
			}
			send_msg->add_usernames_array("end array");
			msgiter++;
		}

		return this->protobufsend(sendmsg);
	}

	bool CProtobuf::protosendImport(const std::string &name, CUserinfo &user_info, const std::string &log_info)
	{
		if (name.empty() || log_info.empty())
			return false;

		prototest::TestImport sendmsg;

		sendmsg.set_simport_name(name);
		user::UserInfo *send_user = sendmsg.mutable_userinfo();
		if (!send_user)
			return false;

		send_user->set_index(user_info.get_number());
		send_user->set_username(user_info.get_username());

		log::SendLog *send_log = sendmsg.mutable_log();
		if (!send_log)
			return false;

		send_log->set_sname(name);
		send_log->set_log(log_info);
		send_log->set_scode(log::Recode::SUCCESS);

		return this->protobufsend(sendmsg);
	}


	bool CProtobuf::proreceive()
	{
		prototest::TestSend getsand;
		prototest::TestReceive setresand;
		setresand.set_srename("reprotobuf");

		if (!protobufreceive(getsand))
			return false;

		cout << "sendname = " << getsand.sname() << endl;
		cout << "number   = " << getsand.u32number() << endl;
		cout << "is array = " << getsand.isserializearray() << endl;

		setresand.set_enumcode(prototest::Recode::SUCCESS);

		return this->protobufsend(setresand);
	}

	bool CProtobuf::proreceiveArray()
	{
		prototest::TestSendArray getsand;
		prototest::TestReceive setresand;
		setresand.set_srename("reprotobuf");
		prototest::Recode revalue = prototest::Recode::ERROR;

		if (!protobufreceive(getsand))
			return false;

		try
		{
			cout << "sendname = " << getsand.sname() << endl;

			int numberlen = getsand.u32number_size();
			if (numberlen < 0)
				throw std::string("get u32number len is error!!!");

			for (int i = 0; i < numberlen; i++)
			{
				cout << "number   = " << getsand.u32number(i) << endl;
			}

			int nameslen = getsand.usernames_array_size();
			if (nameslen < 0)
				throw std::string("get usernames_array len is error!!!");

			for (int i = 0; i < nameslen; i++)
			{
				cout << "usersname   = " << getsand.usernames_array(i) << endl;
			}

			revalue = prototest::Recode::SUCCESS;
		}
		catch (const std::string &err_msg)
		{
			cout << err_msg << endl;
		}
		catch (...)
		{
			cout << __FUNCTION__ << " is Error." << endl;
		}

		setresand.set_enumcode(revalue);
		return this->protobufsend(setresand);
	}

	bool CProtobuf::proreceiveMsg()
	{
		prototest::TestSendMsg getsand;
		prototest::TestReceive setresand;
		setresand.set_srename("reprotobuf");
		prototest::Recode revalue = prototest::Recode::ERROR;

		if (!protobufreceive(getsand))
			return false;

		try
		{
			cout << "sendMsgname = " << getsand.smsg_name() << endl;

			prototest::TestSendArray *send_msg = getsand.mutable_msg_info();
			if (!send_msg)
				throw std::string("get mutable_msg_info is error!!!");

			cout << "sendname = " << send_msg->sname() << endl;
			int numberlen = send_msg->u32number_size();
			if (numberlen < 0)
				throw std::string("get u32number len is error!!!");

			for (int i = 0; i < numberlen; i++)
			{
				cout << "number   = " << send_msg->u32number(i) << endl;
			}

			int nameslen = send_msg->usernames_array_size();
			if (nameslen < 0)
				throw std::string("get usernames_array len is error!!!");

			for (int i = 0; i < nameslen; i++)
			{
				cout << "usersname   = " << send_msg->usernames_array(i) << endl;
			}

			revalue = prototest::Recode::SUCCESS;
		}
		catch (const std::string &err_msg)
		{
			cout << err_msg << endl;
		}
		catch (...)
		{
			cout << __FUNCTION__ << " is Error." << endl;
		}

		setresand.set_enumcode(revalue);
		return this->protobufsend(setresand);
	}

	bool CProtobuf::proreceiveArrayMsg()
	{
		prototest::TestSendArrayMsg getsand;
		prototest::TestReceive setresand;
		setresand.set_srename("reprotobuf");
		prototest::Recode revalue = prototest::Recode::ERROR;

		if (!protobufreceive(getsand))
			return false;

		try
		{
			cout << "sendMsgname = " << getsand.smsg_name() << endl;

			int msg_array_size = getsand.msg_array_size();
			if (msg_array_size < 0)
				throw std::string("get msg_array_size len is error!!!");

			for (int i = 0; i < msg_array_size; i++)
			{
				prototest::TestSendArray get_msgarray = getsand.msg_array(i);

				cout << "sendname = " << get_msgarray.sname() << endl;
				int numberlen = get_msgarray.u32number_size();
				if (numberlen < 0)
					throw std::string("get u32number len is error!!!");

				for (int i = 0; i < numberlen; i++)
				{
					cout << "number   = " << get_msgarray.u32number(i) << endl;
				}

				int nameslen = get_msgarray.usernames_array_size();
				if (nameslen < 0)
					throw std::string("get usernames_array len is error!!!");

				for (int i = 0; i < nameslen; i++)
				{
					cout << "usersname   = " << get_msgarray.usernames_array(i) << endl;
				}

			}

			revalue = prototest::Recode::SUCCESS;
		}
		catch (const std::string &err_msg)
		{
			cout << err_msg << endl;
		}
		catch (...)
		{
			cout << __FUNCTION__ << " is Error." << endl;
		}

		setresand.set_enumcode(revalue);
		return this->protobufsend(setresand);
	}

	bool CProtobuf::proreceiveImport()
	{
		prototest::TestImport getsand;
		prototest::TestReceive setresand;
		setresand.set_srename("reprotobuf");

		if (!protobufreceive(getsand))
			return false;

		try
		{
			cout << "sendname = " << getsand.simport_name() << endl;

			user::UserInfo *get_user = getsand.mutable_userinfo();
			if (!get_user)
				throw std::string("get user info is error!!!");

			cout << "user index = " << get_user->index() << endl;
			cout << "user name = " << get_user->username() << endl;

			log::SendLog *get_log = getsand.mutable_log();
			if (!get_log)
				throw std::string("get log info is error!!!");

			cout << "log sand name = " << get_log->sname() << endl;
			cout << "log  = " << get_log->log() << endl;
			cout << "log  code = " << get_log->scode() << endl;

			setresand.set_enumcode(prototest::Recode::SUCCESS);
		}
		catch (const std::string &err_msg)
		{
			cout << err_msg << endl;
		}
		catch (...)
		{
			cout << __FUNCTION__ << " is Error." << endl;
		}

		return this->protobufsend(setresand);
	}




	void CProtobuf::getaskreceive()
	{
		prototest::TestReceive getsand;

		if (!protobufreceive(getsand))
			return;

		cout << "re code  = " << getsand.enumcode() << endl;
		cout << "re name  = " << getsand.srename() << endl;
	}

}
