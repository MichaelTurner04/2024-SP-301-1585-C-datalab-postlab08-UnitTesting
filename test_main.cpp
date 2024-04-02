#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "list.h"
#include <ctime>
#include <stdlib.h>

TEST_CASE("test", "[int]"){
    SECTION("prepend"){
        time_t seed;
        srand(time(&seed));

        List<int> your_list;
        List<int> test_list;
        for (int k = 0; k<3; k++){
            int r = rand() % 50;
            your_list.prepend(r);
            test_list.prepend(r);
        }
        for (int k = 0; k<3; k++){
            CHECK(your_list.iterator() != test_list.iterator());
        }
    }
    SECTION("Copy construtor"){

    }
}
