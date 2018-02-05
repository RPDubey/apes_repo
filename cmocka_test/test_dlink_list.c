#include <cmocka.h>
#include <setjmp.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>

#include "../DataStructure/dlink_list.h"

//unit tests for memory

static void test_insert_at_begining_null_pointer(voi **state){
assert_non_null(insert_at_begining(NULL,10));
}

int main(void){

const struct CMUnitTest tests[] = {
cmocka_unit_test(test_insert_at_begining_null_pointer)
};

return cmocka_run_group_tests(tests,NULL,NULL);
}
