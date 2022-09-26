// ----------------- RandomEintegerGenerator.h ---------------

#ifndef RANDOMEINTEGERGENERATOR_H
#define RANDOMEINTEGERGENERATOR_H

#include <random>

#include "HistogramBase.h"

namespace Hist
{
	/**
	* Generates random EIntegers.
	*/
	class RandomEintegerGenerator : RandomEintegerGeneratorBase
	{
	public:
		/**
		* Constructor. Will assert that minimum is greater than maximum.
		* @param min The minimum EInteger that can be generated.
		* @param max The maximum EInteger that can be generated.
		*/
		RandomEintegerGenerator(EInteger min, EInteger max);

		/**
		* Returns a pseudo-random EInteger value
		*/
		EInteger operator()();

		/**
		* Disable copying.
		*/
		RandomEintegerGenerator(RandomEintegerGenerator const&) = delete;

		/**
		* Disable copying.
		*/
		RandomEintegerGenerator& operator=(RandomEintegerGenerator const&) = delete;

	private:
		/**
		* The random number generator.
		*/
		std::random_device m_dev;
		/**
		* The random number engine.
		*/
		std::mt19937 m_rng;
		/**
		* The distribution for random numbers.
		*/
		std::uniform_int_distribution<std::mt19937::result_type> m_distribution;
	};
}
#endif