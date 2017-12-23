#ifndef __PROTOBUFBASIC_H__
#define __PROTOBUFBASIC_H__

#include <google/protobuf/message.h>

namespace protobufbasic
{
	class CProtubufBasic
	{
	public:
		CProtubufBasic() :
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
}


#endif

