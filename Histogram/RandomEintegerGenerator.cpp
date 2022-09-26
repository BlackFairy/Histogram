// ----------------- RandomEintegerGenerator.cpp ---------------

#include "RandomEintegerGenerator.h"
#include "Histogram.h"

namespace Hist
{
	RandomEintegerGenerator::RandomEintegerGenerator(EInteger min, EInteger max) : RandomEintegerGeneratorBase(),
		m_dev(),
		m_rng(m_dev()),
		m_distribution(min, max)
	{
	}

	EInteger RandomEintegerGenerator::operator()()
	{
		int randomNumber = m_distribution(m_rng);

		return (EInteger)randomNumber;
	}
}