#include "pch.h"
#include "CppUnitTest.h"
#include "../Pr_10.4/10.4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            const int numCars = 3;
            Car testCars[numCars] = {
                {"BrandA", 10000, 50},
                {"BrandB", 12000, 60},
                {"BrandC", 8000, 40}
            };

            const double expectedAverageMileage = 50.0;

            double actualAverageMileage = calculateAverageMileage(testCars, numCars);

            Assert::AreEqual(expectedAverageMileage, actualAverageMileage);
		}
	};
}
