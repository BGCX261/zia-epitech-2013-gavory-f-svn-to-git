#include "HTTPCommand.h"

namespace ZIAApi
{
	HTTPCommand::HTTPCommand(void)
	{
	}

	HTTPCommand::HTTPCommand(const EMethod method, const std::string url, const version version) : _method(method), _url(url), _version(version)
	{
	}

	HTTPCommand::~HTTPCommand(void)
	{
	}

	void				HTTPCommand::setMethod			(const EMethod method)
	{
		this->_method = method;
	}

	void				HTTPCommand::setUrl				(const std::string url)
	{
		this->_url = url;
	}

	void				HTTPCommand::setVersion			(const version version)
	{
		this->_version = version;
	}

	void				HTTPCommand::setVersion			(const int major, const int minor)
	{
		this->_version.minor = minor;
		this->_version.major = major;
	}
	
	const HTTPCommand::EMethod		HTTPCommand::getMethod		(void) const
	{
		return this->_method;
	}

	const std::string	HTTPCommand::getURL						(void) const
	{
		return this->_url;
	}

	const HTTPCommand::version		HTTPCommand::getVersion		(void) const
	{
		return this->_version;
	}

}