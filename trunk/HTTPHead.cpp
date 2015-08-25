#include "HTTPHead.h"

#include <sstream>
namespace ZIAApi
{

	HTTPHead::HTTPHead(void)
	{
	}


	HTTPHead::~HTTPHead(void)
	{
	}

	std::string	HTTPHead::serialize(void)
	{
		std::string							header;
		std::map<std::string, std::string>::iterator	i = this->_headers.begin();

		while (i != this->_headers.end())
		{
			header.append(i->first + std::string(": ") + i->second + ZIAPI_CRLF);
			i++;
		}
		return (header);
	}

	void	HTTPHead::unserialize(const std::string head)
	{
		std::stringstream	shead;
		std::string			line;
		std::string			tmpHead(head);

		shead << tmpHead;
		this->_headers.clear();
		while (std::getline(shead, line, '\n'))
		{
			int			found = line.find(":");
			if (found != line.npos)
			{
				std::string		name(line, 0, found);
				std::string		value(line, found + 1, line.length() - found);
				this->trim(value);
				this->_headers[name] = value;
			}
		}
	}
	
	void HTTPHead::trim(std::string & str)
	{
		int pos = str.find_first_not_of(" \t");
		if (pos != str.npos)
			str = str.substr(pos);
		pos = str.find_last_not_of(" \t\n\r");
		if (pos != str.npos)
			str = str.substr(0, pos + 1);
	}

	std::string	HTTPHead::getHeader(const std::string header)
	{
		if (this->_headers.find(header) != this->_headers.end())
			return (this->_headers[header]);
		return ZIAPI_HEADER_NO_EXIST;
	}

	bool HTTPHead::hasHeader(const std::string header)
	{
		if (this->_headers.find(header) != this->_headers.end())
			return true;
		return false;
	}

	void	HTTPHead::setHeader(const std::string header, const std::string value)
	{
		this->_headers[header] = value;
		return ;
	}

}