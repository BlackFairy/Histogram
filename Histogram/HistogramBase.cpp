// ----------------- HistogramBase.cpp ---------------

#include "HistogramBase.h"
#include "Log.h"

namespace Hist
{
	HistogramBase::HistogramBase(std::unique_ptr<Logger> logger) : m_log(std::move(logger))
	{
	}

	HistogramBase::~HistogramBase()
	{
	}
}