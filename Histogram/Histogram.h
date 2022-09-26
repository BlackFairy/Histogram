// ----------------- Histogram.h ---------------

#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include "HistogramBase.h"

namespace Hist
{
	/**
	* Stores histogram data of EInteger values, and returns key metrics of it.
	*/
	class Histogram : HistogramBase
	{
	public:
		/**
		* Total number of possible EInteger values.
		*/
		static const int EINTEGER_COUNT = 5;

		/**
		* Constructor.
		* @param logger A logger required by the base class.
		*/
		Histogram(std::unique_ptr<Logger> logger);

		virtual ~Histogram();

		/**
		* Adds a new value to the data set.
		* @param toConvert The data to add.
		*/
		void add(EInteger toConvert);

		/**
		* Return the value that occurrs most often in the data set (I.e. there exists no other value that occurs more often than the return value)
		*/
		EInteger getMode() const;

		/**
		* Return the smallest value in the data set, according to default ordering relation of integer numbers
		*/
		EInteger getMinValue() const;

		/**
		* Return the largest value in the data set
		*/
		EInteger getMaxValue() const;

		/**
		* Disable copying.
		*/
		Histogram(Histogram const&) = delete;

		/**
		* Disable copying.
		*/
		Histogram& operator=(Histogram const&) = delete;

	private:
		/**
		* Purge all data from the data set.
		*/
		void clearData();

		/**
		* The data set.
		*/
		int m_data[EINTEGER_COUNT];
	};
}

#endif

