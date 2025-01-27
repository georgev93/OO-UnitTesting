#include "CppUTest/TestHarness.h"
#include "fff/fff.h"
#include "header.h"

using namespace std;

// clang-format off

TEST_GROUP(Basic_g) {
    void setup() override {
    }
    void teardown() override {
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

