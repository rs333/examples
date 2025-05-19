#include "ruleof0.h"
#include <gtest/gtest.h>
#include <utility>
#include <stdio.h>

class ATest : public testing::Test {

  protected:
    void SetUp() override {
    }
    void TearDown() override{
    }
};

TEST_F(ATest, Allocation){
    A *a=(A*)calloc(1,sizeof(A));
    ASSERT_EQ(a->a(),0);
}

TEST_F(ATest, Constructor){
    ASSERT_NO_FATAL_FAILURE( A a; );
}

TEST_F(ATest, Assignment){
    A a;
    a.a(42);
    A b=a;
    ASSERT_EQ(b.a(),42);
}

TEST_F(ATest, Copy){
    A a;
    a.a(42);
    A b(a);
    ASSERT_EQ(b.a(),42);
}