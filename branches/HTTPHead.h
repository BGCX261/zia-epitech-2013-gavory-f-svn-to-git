#pragma once

#include <map>
#include <string>
#define ZIAPI_CRLF	"\r\n"
#define ZIAPI_HEADER_NO_EXIST ""

namespace ZIAApi
{
	class HTTPHead
	{
	private:
		std::map<std::string, std::string>	_headers;
		static void trim(std::string & str);
	public:
		HTTPHead					(void);
		~HTTPHead					(void);
		std::string		serialize	(void);
		void			unserialize	(const std::string);
		std::string		getHeader	(const std::string header);
		bool			hasHeader	(const std::string header);
		void			setHeader	(const std::string header, const std::string value);
	};
}