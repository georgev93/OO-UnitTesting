#include "CppUTest/TestHarness.h"
#include "fff/fff.h"
#include "header.h"
#include <CppUTest/UtestMacros.h>

using namespace std;

DEFINE_FFF_GLOBALS

FAKE_VALUE_FUNC(int, getSum_f, int, int)  // NOLINT
FAKE_VALUE_FUNC(int, getDiff_f, int, int) // NOLINT

class MockArithOps : public ArithOps {
  public:
    int getSum(int a, int b) const override {
        return getSum_f(a, b);
    }
    int getDiff(int a, int b) const override {
        return getDiff_f(a, b);
    }
};

// clang-format off

TEST_GROUP(Basic_g) {
    void setup() override {
    }
    void teardown() override {
      RESET_FAKE(getSum_f)
      RESET_FAKE(getDiff_f)
    }
};

// clang-format on

TEST(Basic_g, simple) {
    MyClass testCase1(10, 20);
    CHECK_EQUAL(300, testCase1.doComplexOp());

    MyClass testCase2(20, 30);
    CHECK_EQUAL(500, testCase2.doComplexOp());

    MyClass testCase3(30, 20);
    CHECK_EQUAL(500, testCase3.doComplexOp());
}

TEST(Basic_g, mockCalls) {
    MyClass testCase1(10, 20, new MockArithOps);
    testCase1.doComplexOp();
    CHECK_EQUAL(1, getSum_f_fake.call_count);
    CHECK_EQUAL(1, getDiff_f_fake.call_count);
    CHECK_EQUAL(10, getSum_f_fake.arg0_val);
    CHECK_EQUAL(20, getSum_f_fake.arg1_val);
    CHECK_EQUAL(10, getDiff_f_fake.arg0_val);
    CHECK_EQUAL(20, getDiff_f_fake.arg1_val);
}

TEST(Basic_g, arithOps) {
    ArithOps ops;
    CHECK_EQUAL(30, ops.getSum(10, 20));
    CHECK_EQUAL(50, ops.getSum(20, 30));
    CHECK_EQUAL(50, ops.getSum(30, 20));
    CHECK_EQUAL(10, ops.getDiff(10, 20));
    CHECK_EQUAL(10, ops.getDiff(20, 30));
    CHECK_EQUAL(10, ops.getDiff(30, 20));
  }
