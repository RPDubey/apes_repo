#include <setjmp.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include "/home/ravi/cmocka/include/cmocka.h"
#include "../DataStructure/dlink_list.h"

//unit tests for memory

//node_info new_node_info[] = {0,{NULL,NULL}} ;

static void test_insert_at_begining_null_pointer(void **state){
assert_null(insert_at_begining(NULL,10));
}

static void test_destroy_null_pointer(void **state){
assert_null(destroy(NULL));
}

static void test_insert_at_end_null_pointer(void **state){
assert_null(insert_at_end(NULL,10));
}


static void test_insert_at_position_null_pointer(void **state){
assert_null(insert_at_position(NULL,10,10));
}

static void test_delete_from_begining_null_pointer(void **state){
assert_null(delete_from_begining(NULL));
}

static void test_delete_from_end_null_pointer(void **state){
assert_null(delete_from_end(NULL));
}

static void test_delete_from_position_null_pointer(void **state){
assert_null(delete_from_position(NULL,10));
}


//cases which couldnot be tested due to malloc failure
/*

static void test_insert_at_begining_ptr_equal(void **state){
assert_ptr_equal(insert_at_begining( &new_node_info->this_node_head,1), &new_node_info->this_node_head );
}

static void test_insert_at_begining_ptr_equal0(void **state){
assert_ptr_equal(insert_at_begining(&new_node_info->this_node_head,2), (new_node_info->this_node_head).prev );
}


static void test_insert_at_end_ptr_equal(void **state){
assert_ptr_equal(insert_at_end(&new_node_info->this_node_head,3), (new_node_info->this_node_head).prev );


static void test_insert_at_position_ptr_null_tail(void **state){
assert_non_null(insert_at_position(&new_node_info->this_node_head),100, 3 );

static void test_insert_at_position_ptr_null_head(void **state){
assert_non_null(insert_at_position(&new_node_info->this_node_head),100, -3 );

static void test_insert_at_position_ptr_equal1_head(void **state){
assert_ptr_equal(insert_at_position(&new_node_info->this_node_head),4,-2),(new_node_info->this_node_head).prev )

static void test_insert_at_position_ptr_equal2_head(void **state){
assert_ptr_equal(insert_at_position(&new_node_info->this_node_head),100, -1),(new_node_info->this_node_head).prev 

);
}


*/

int main(void){

const struct CMUnitTest tests[] = {
cmocka_unit_test(test_insert_at_begining_null_pointer),
cmocka_unit_test(test_destroy_null_pointer),
cmocka_unit_test(test_insert_at_end_null_pointer),
cmocka_unit_test(test_insert_at_position_null_pointer),
cmocka_unit_test(test_delete_from_begining_null_pointer),
cmocka_unit_test(test_delete_from_end_null_pointer),
cmocka_unit_test(test_delete_from_position_null_pointer)
};

return cmocka_run_group_tests(tests,NULL,NULL);
}
