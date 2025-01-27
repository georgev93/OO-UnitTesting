#include "CppUTest/TestHarness.h"
#include "MyClass_mocks.h"
#include "fff/fff.h"
#include "header.h"

using namespace std;

// clang-format off

TEST_GROUP(Basic_g) {
    void setup() override {
    }
    void teardown() override {
      getSum_f_reset();
      getDiff_f_reset();
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

TEST(Basic_g, mockedCalls) {
  MyMockClass testCase(10, 20);
  testCase.doComplexOp();

  CHECK_EQUAL(getSum_f_fake.call_count, 1);
  CHECK_EQUAL(getDiff_f_fake.call_count, 1);
}

TEST(Basic_g, getSum) {
  MyPublicClass testCase1(10, 20);
  CHECK_EQUAL(30, testCase1.getSum());

  MyPublicClass testCase2(20, 30);
  CHECK_EQUAL(50, testCase2.getSum());

  MyPublicClass testCase3(30, 20);
  CHECK_EQUAL(50, testCase3.getSum());
}

TEST(Basic_g, getDiff) {
  MyPublicClass testCase1(10, 20);
  CHECK_EQUAL(10, testCase1.getDiff());

  MyPublicClass testCase2(20, 30);
  CHECK_EQUAL(10, testCase2.getDiff());

  MyPublicClass testCase3(30, 20);
  CHECK_EQUAL(10, testCase3.getDiff());
}

