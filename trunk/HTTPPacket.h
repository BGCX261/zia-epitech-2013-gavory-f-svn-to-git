#pragma once
#include <string>
#include "HTTPHead.h"

#define ZIAPI_CRLF	"\r\n"

namespace ZIAApi
{

	class HTTPPacket
	{
	public:
		HTTPPacket(void);
		HTTPPacket(std::string packet);
		~HTTPPacket(void);

		void				unserialize(std::string packet);
		const std::string	serialize(void);

		std::string body;
		HTTPHead	head;
	};

}