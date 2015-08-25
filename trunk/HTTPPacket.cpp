#include "HTTPPacket.h"

namespace ZIAApi
{
	HTTPPacket::HTTPPacket(void)
	{
	}

	HTTPPacket::HTTPPacket(std::string packet)
	{
		this->unserialize(packet);
	}

	HTTPPacket::~HTTPPacket(void)
	{
	}

	void				HTTPPacket::unserialize(std::string packet)
	{
		std::string reconStr(ZIAPI_CRLF + std::string(ZIAPI_CRLF));
		int found = packet.find(reconStr);
		std::string headStr(packet, 0, found);
		std::string bodyStr(packet, found + reconStr.length(), packet.length());
		this->head.unserialize(headStr);
		this->body = bodyStr;
	}

	const std::string	HTTPPacket::serialize(void)
	{
		std::string serializedPacket;
		std::string	tmpPacket;
		serializedPacket.append(this->head.serialize());
		serializedPacket.append(ZIAPI_CRLF);
		serializedPacket.append(this->body);
		return serializedPacket;
	}

}