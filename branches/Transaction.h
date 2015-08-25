#pragma once
#include "HTTPCommand.h"
#include "HTTPPacket.h"

namespace ZIAApi
{
	class Transaction
	{
	public:
		Transaction(HTTPCommand command, const HTTPPacket request) : command(command), request(request){};
		Transaction(const HTTPPacket request) : request(request){};
		~Transaction(void) {};
	
		HTTPCommand			command;
		const HTTPPacket	request;
		HTTPPacket			response;
	};
}
