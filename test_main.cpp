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
    SECTION("append"){
        time_t seed;
        srand(time(&seed));

        List<int> test_list;
        int r = rand() %50;
        int r2 = rand() %50;
        test_list.append(r);
        test_list.append(r2);

        REQUIRE(test_list.length() ==2);
        REQUIRE(test_list.head() == r);
    }
    SECTION("pop"){
        time_t seed;
        srand(time(&seed));

        List<int> test_list;
        int r = rand() %50;
        int r2 = rand() %50;
        test_list.append(r);
        test_list.append(r2);
        test_list.pop();

        REQUIRE(test_list.length() ==1);
        REQUIRE(test_list.head() == r2);
    }
    SECTION("head"){
        time_t seed;
        srand(time(&seed));

        List<int> test_list;
        int r = rand() %50;
        int r2 = rand() %50;
        test_list.append(r);
        test_list.append(r2);
        REQUIRE(test_list.head()==r);
    }
    SECTION("tail"){
        time_t seed;
        srand(time(&seed));

        List<int> test_list;
        int r = rand() %50;
        int r2 = rand() %50;
        test_list.append(r);
        test_list.append(r2);
        List<int> tail = test_list.tail();
        REQUIRE(tail.length() == 1);
        REQUIRE(tail.head() ==r2);
    }
    SECTION("empty"){
        time_t seed;
        srand(time(&seed));

        List<int> test_list;
        REQUIRE(test_list.empty());
        int r = rand() %50;
        int r2 = rand() %50;
        test_list.append(r);
        test_list.append(r2);
        REQUIRE_FALSE(test_list.empty());
    }
    SECTION("length"){
        time_t seed;
        srand(time(&seed));

        List<int> test_list;
        int r = rand() %50;
        int r2 = rand() %50;
        test_list.append(r);
        test_list.append(r2);
        REQUIRE(test_list.length()==2);
    }
    SECTION("constructor"){
        List<int> test_list;
        REQUIRE(test_list.empty());
        REQUIRE(test_list.length() ==0);

    }
    SECTION("copy constructor"){
        List<int> test_list;

        int r = rand() %50;
        int r2 = rand() %50;
        int r3 = rand() %50;
        int r4 = rand() %50;
        test_list.append(r);
        test_list.append(r2);
        test_list.append(r3);
        test_list.append(r4);

        List<int> copy_list(test_list);
        REQUIRE(test_list.length() == copy_list.length());
        REQUIRE(test_list.head() == copy_list.head());

    }
    SECTION("iterator"){
        List<int> test_list;
        int r = rand() %50;
        int r2 = rand() %50;
        test_list.append(r);
        test_list.append(r2);
        Cell<int>* iterator = test_list.iterator();
        REQUIRE(iterator != nullptr);
        REQUIRE(iterator->elem ==r);

    }
}
