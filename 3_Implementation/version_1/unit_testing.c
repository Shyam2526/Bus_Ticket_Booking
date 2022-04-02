#include "header.h"
#include "unity.h"
#include "manual.c"
//extern int shyam(int a, char b[], int c);
extern void manual_test();
void setUp(void)
{
}
void tearDown(void)
{
}
void testing_ac(){
    TEST_ASSERT_EQUAL(1750,ac(2,"6",775));
    TEST_ASSERT_EQUAL(275,ac(1,"7",75));
    TEST_ASSERT_EQUAL(1500,ac(2,"8",650));
    TEST_ASSERT_EQUAL(3200,ac(2,"9",1500));
    TEST_ASSERT_EQUAL(1400,ac(1,"10",1200));
}
void testing_sleeper(){
    TEST_ASSERT_EQUAL(400,sleeper(1,"2",300));
    TEST_ASSERT_EQUAL(900,sleeper(2,"3",400));
    TEST_ASSERT_EQUAL(1100,sleeper(2,"4",500));
    TEST_ASSERT_EQUAL(1000,sleeper(2,"5",450));
    TEST_ASSERT_EQUAL(500,sleeper(2,"1",200));
}
void testing_seater(){
    TEST_ASSERT_EQUAL(555,seater(1,"11",555));
    TEST_ASSERT_EQUAL(1000,seater(2,"12",500));
    TEST_ASSERT_EQUAL(725,seater(1,"13",725));
    TEST_ASSERT_EQUAL(500,seater(2,"14",250));
    TEST_ASSERT_EQUAL(100,seater(2,"15",50));
}
int testcode()
{
    //ac(total_seat, bus_code);
    manual_test_checking();
    manual_test_pass();
    manual_test_login();
    UnityBegin(NULL);
    RUN_TEST(testing_ac);
    RUN_TEST(testing_sleeper);
    RUN_TEST(testing_seater);
    return (UnityEnd());
}