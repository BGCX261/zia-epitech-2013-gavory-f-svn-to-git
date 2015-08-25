#pragma once

#include <string>

namespace ZIAApi
{
	class HTTPCommand
	{
	public:
		// Enum who describes the Method used in the HTTP Command.
		enum EMethod
		{
			GET,
			HEAD,
			POST,
			OPTIONS,
			CONNECT,
			TRACE,
			PUT,
			DELETE
		};
		struct version
		{
			version(int major = 1, int minor = 1) : major(major), minor(minor){};
			int major;
			int minor;
		};

		// Constructor & Deconstructor
		HTTPCommand								(void);
		HTTPCommand								(const EMethod method, const std::string url, const version version);
		~HTTPCommand							(void);
		// Setters
		void				setMethod			(const EMethod method);
		void				setUrl				(const std::string url);
		void				setVersion			(const version version);
		void				setVersion			(const int major, const int minor);
		// Getters
		const EMethod		getMethod			(void) const;
		const std::string	getURL				(void) const;
		const version		getVersion			(void) const;
	private:
		EMethod			_method;
		std::string		_url;
		version			_version;
	};

}