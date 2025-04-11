#include "jugo.h"
#include <gtest/gtest.h>

TEST(JugoTest, Test1) {
    std::vector<std::vector<int>> pesos = {
        {10000, 0, 0},
        {0, 10000, 0},
        {0, 0, 10000}
    };
    Jugo inicial;
    EXPECT_EQ(maxValorRetirado(inicial, 0, pesos), 1);
}

TEST(JugoTest, Test2) {
    std::vector<std::vector<int>> pesos = {
        {5000, 0, 0},
        {0, 2000, 0},
        {0, 0, 4000}
    };
    Jugo inicial;
    EXPECT_EQ(maxValorRetirado(inicial, 0, pesos), 2);
}

TEST(JugoTest, Test3) {
    std::vector<std::vector<int>> pesos = {
        {0, 1250, 0},
        {3000, 0, 3000},
        {1000, 1000, 1000},
        {2000, 1000, 2000},
        {1000, 3000, 2000}
    };
    Jugo inicial;
    EXPECT_EQ(maxValorRetirado(inicial, 0, pesos), 5);
}
