#pragma once

#define _SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING

#if !_HAS_CXX17
#error "The Ztui are available only with C++17 or later."
#endif

#include <iostream>
#include <exception>

namespace Ztui
{
	class OSException : public std::exception
	{
	public:
		OSException():Error_("[Ztui-Exception] Unkown Error") {}
		OSException(std::string Error):Error_("[Ztui-Exception] " + Error){}
		char const* what() const throw()
		{
			return Error_.c_str();
		}
	private:
		std::string Error_ = "";
	};
}