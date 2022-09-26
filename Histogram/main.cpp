// ----------------- main.cpp ---------------

#include <iostream>
#include <memory>

#include "Log.h"
#include "Histogram.h"
#include "RandomEintegerGenerator.h"

using Hist::EInteger;

int main()
{
    Hist::Histogram test_histogram(std::make_unique<Hist::Logger>());

    Hist::RandomEintegerGenerator Generator(EInteger::Zero, EInteger::Four);

    const int SIZE_OF_DATA_SET = 100;

    for (int i = 0; i < SIZE_OF_DATA_SET; ++i)
    {
        test_histogram.add(Generator());
    }

    auto mode = test_histogram.getMode();
    auto min = test_histogram.getMinValue();
    auto max = test_histogram.getMaxValue();

    std::cout << "Values in histogram:" << std::endl <<
        "mode: " << mode << std::endl <<
        "min: " << min << std::endl <<
        "max: " << max << std::endl;
}