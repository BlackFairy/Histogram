// ----------------- Histogram.cpp ---------------

#include <stdexcept>

#include "Histogram.h"
#include "Log.h"

namespace Hist
{
	Histogram::Histogram(std::unique_ptr<Logger> logger) : HistogramBase(std::move(logger))
	{
		clearData();
	}

	Histogram::~Histogram()
	{
	}

	void Histogram::add(EInteger increasedInterval)
	{
		++m_data[increasedInterval];
	}

	EInteger Histogram::getMode() const
	{
		EInteger mode = EInteger::Zero;
		int countInmode = m_data[mode];

		for (unsigned int i = 1; i < EINTEGER_COUNT; ++i)
		{
			int countInInspectedInterval = m_data[i];

			if (countInmode < countInInspectedInterval)
			{
				mode = (EInteger)i;
				countInmode = countInInspectedInterval;
			}
		}

		return mode;
	}

	EInteger Histogram::getMinValue() const
	{
		for (unsigned int i = 0; i < EINTEGER_COUNT; ++i)
		{
			int countInInspectedInterval = m_data[i];

			if (countInInspectedInterval > 0)
			{
				return (EInteger)i;
			}
		}

		return EInteger::Zero;
	}

	EInteger Histogram::getMaxValue() const
	{
		for (int i = EINTEGER_COUNT - 1; i > -1; --i)
		{
			int countInInspectedInterval = m_data[i];

			if (countInInspectedInterval > 0)
			{
				return (EInteger)i;
			}
		}

		return EInteger::Four;
	}

	void Histogram::clearData()
	{
		for (unsigned int i = 0; i < EINTEGER_COUNT; ++i)
		{
			m_data[i] = 0;
		}
	}
}