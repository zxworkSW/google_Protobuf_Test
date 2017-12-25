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
		virtual ~CProtubufBasic()
		{
			if (p_arraysendbuffer)
			{
				delete p_arraysendbuffer;
			}
			p_arraysendbuffer = nullptr;

			m_arraysendbuffersize = 0;
			m_strsendbuffer.clear();
		};
		
		bool protobufsend(google::protobuf::Message &buffmessage);
		bool  protobufreceive(google::protobuf::Message &buffmessage);
		void getaskreceive();

		bool isSerializeToArray() { return m_isSerializeToArray; }
		inline void clean();

	private:
		char *p_arraysendbuffer;
		int m_arraysendbuffersize;
		std::string m_strsendbuffer;

		bool m_isSerializeToArray;
	};
}


#endif

