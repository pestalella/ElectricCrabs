#include "stdafx.h"
#include "CppUnitTest.h"

#include "../Crabs/utils.h"
#include "../Crabs/utils.cpp"
#include "../Crabs/Component.h"
#include "../Crabs/Component.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{		
	TEST_CLASS(UnitTestUtils)
	{
	public:
		
        TEST_METHOD(TestKiloValueToPrefix)
        {
            Assert::AreEqual('k', Utils::valueToPrefix(1E3));
        }
        TEST_METHOD(TestMicroValueToPrefix)
        {
            Assert::AreEqual('u', Utils::valueToPrefix(200E-6));
        }
        TEST_METHOD(TestLargeMicroValueToPrefix)
        {
            Assert::AreEqual('u', Utils::valueToPrefix(999E-6));
        }
        TEST_METHOD(TestFemtoValueToPrefix)
        {
            Assert::AreEqual('f', Utils::valueToPrefix(1E-15));
        }
        TEST_METHOD(TestTeraValueToPrefix)
        {
            Assert::AreEqual('T', Utils::valueToPrefix(999E12));
        }

        TEST_METHOD(TestScaledTeraValue)
        {
            Assert::AreEqual(1.0, Utils::scaledToPrefix(1E12), 1E-3);
        }

        TEST_METHOD(TestScaledMicroValue)
        {
            Assert::AreEqual(123.0, Utils::scaledToPrefix(123E-6), 1E-3);
        }

        TEST_METHOD(TestScaledFemtoValue)
        {
            Assert::AreEqual(999.0, Utils::scaledToPrefix(999E-15), 1E-3);
        }
    };

    TEST_CLASS(UnitTestComponents)
    {
    public:

        TEST_METHOD(TestCapacitorSPICEstring)
        {
            Capacitor c(1, 2, 10E-6);
            Assert::AreEqual("C? 1 2 10uF", c.toSPICEString().c_str());
        }

        TEST_METHOD(TestComponentCapacitorSPICEstring)
        {
            Component c = Component::createCapacitor(1, 2, 10E-6);
            Assert::AreEqual("C? 1 2 10uF", c.toSPICEString().c_str());
        }

        TEST_METHOD(TestComponentResistorSPICEstring)
        {
            Component c = Component::createResistor(23, 2, 10E3);
            Assert::AreEqual("R? 23 2 10k", c.toSPICEString().c_str());
        }
    };
}