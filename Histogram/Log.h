// ----------------- Log.h ---------------

#ifndef LOG_H
#define LOG_H

namespace Hist
{
	/**
	* Does nothing.
	*/
	class Logger
	{
	public:
		/**
		* Constructor.
		*/
		Logger();

		/**
		* Disable copying.
		*/
		Logger(Logger const&) = delete;

		/**
		* Disable copying.
		*/
		Logger& operator=(Logger const&) = delete;
	};
}

#endif