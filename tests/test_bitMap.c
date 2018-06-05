#include <check.h>
#include "bitMap.h"
#include "limits.h"

START_TEST (test_setBitByNumber)
    {
        int a = 0xffffffff;
        printf("int : %i, hex : %x\n", a, a);
        setBitByNumber(&a, 0, 0);
        printf("int : %i, hex : %x\n", a, a);

    }
END_TEST

START_TEST (test_getBitByNumber)
    {
        //YOUR CODE HERE
    }
END_TEST

START_TEST (test_setBitByAddress)
    {
        //YOUR CODE HERE
    }
END_TEST

START_TEST (test_getBitByAddress)
    {
//        unsigned int a = 0x0fffffff;
//        printf("%u\n", getBitByAddress(&(a)));
    }
END_TEST

Suite *str_suite(void) {
    Suite *suite = suite_create("priority queue");
    TCase *tcase = tcase_create("case");
    tcase_add_test(tcase, test_setBitByNumber);
    tcase_add_test(tcase, test_getBitByNumber);
    tcase_add_test(tcase, test_setBitByAddress);
    tcase_add_test(tcase, test_getBitByAddress);
    suite_add_tcase(suite, tcase);
    return suite;
}

int main(int argc, char *argv[]) {
    int number_failed;
    Suite *suite = str_suite();
    SRunner *runner = srunner_create(suite);
    srunner_run_all(runner, CK_NORMAL);
    number_failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return number_failed;
}