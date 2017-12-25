#include "protobufbasic.h"

using namespace std;

namespace protobufbasic
{
	bool CProtubufBasic::protobufsend(google::protobuf::Message &buffmessage)
	{
		try
		{
			clean();

			if (m_isSerializeToArray)
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
			else
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
	bool CProtubufBasic::protobufreceive(google::protobuf::Message &buffmessage)
	{
		try
		{
			if (m_isSerializeToArray)
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
			else
			{
				if (m_strsendbuffer.empty())
					throw std::string("get buffer is empty!!!");
				else if (!buffmessage.ParseFromString(m_strsendbuffer))
				{
					m_strsendbuffer.clear();
					throw std::string("ParseFromString is empty!!!");
				}
			}
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

	void CProtubufBasic::clean()
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
}

