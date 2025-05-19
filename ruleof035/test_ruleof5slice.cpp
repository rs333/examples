#include "ruleof5.h"
#include <gtest/gtest.h>
#include <cstdio>
#include <string>
#include <utility>

int slice(Asliceable a){
    return a.val();
}

TEST(ATest, Slice){
    Asliceable a; 
    a.setval(42); 
    B b; 
    b.setval(42); 
    ASSERT_EQ(b.val(),-42);
    ASSERT_EQ(slice(a),42);
    // This next one should be -42 but it isn't
    ASSERT_EQ(slice(b),42);
}