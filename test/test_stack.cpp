#include "Stack_Queue.h"
#include <gtest.h>

TEST(Stack, create_Stack_with_default_konstruktor) {
     ASSERT_NO_THROW(Stack<int> stack);
 }

 TEST(Stack, can_push_element_to_stack) {
     Stack<int> stack;
     ASSERT_NO_THROW(stack.push(1));
 }
 TEST(Stack, can_pop_not_empty_Stack) {
     Stack<int> stack;
     stack.push(1);
     ASSERT_NO_THROW(stack.pop());
 }
 TEST(Stack, cant_pop_empty_Stack) {
     Stack<int> stack;
     ASSERT_ANY_THROW(stack.pop());
 }
 TEST(Stack, top_and_push_work_correctly) {
     Stack<int> stack;
     stack.push(2);
     EXPECT_EQ(2, stack.top());
 }
 TEST(Stack, GetSize_work_correctly) {
     Stack<int> stack;
     stack.push(1);
     stack.push(5);
     stack.push(7);
     EXPECT_EQ(3, stack.GetSize());
 }
 TEST(Stack, can_copy_another_Stack) {
     Stack<int> stack;
     stack.push(2);
     stack.push(1);
     ASSERT_NO_THROW(Stack<int>stack1(stack));
 }
 TEST(Stack, copy_Stack_has_the_same_top) {
     Stack<int> stack;
     stack.push(2);
     stack.push(1);
     Stack<int> stack1(stack);
     EXPECT_EQ(stack1.top(), stack.top());
 }
TEST(Stack, copy_Stack_has_the_same_size) {
    Stack<int> stack;
    stack.push(2);
    stack.push(1);
    Stack<int> stack1(stack);
    EXPECT_EQ(stack.GetSize(), stack1.GetSize());
}
TEST(Stack, copy_Stack_has_the_same_top_after_pop) {
    Stack<int> stack;
    stack.push(2);
    stack.push(1);
    Stack<int> stack1(stack);
    stack.pop(), stack1.pop();
    EXPECT_EQ(stack1.top(), stack.top());

}
 TEST(Stack, assign_operator_can_copy_another_Stack) {
     Stack<int> stack;
     Stack<int> stack1;
     stack.push(5);
     ASSERT_NO_THROW(stack1 = stack;);
 }
 TEST(Stack, assign_operator_copy_Stack_size_correct) {
     Stack<int> stack;
     Stack<int> stack1;
     stack.push(5);
     stack1 = stack;
     EXPECT_EQ(stack.GetSize(), stack1.GetSize());
 }
TEST(Stack, assign_operator_copy_Stack_top_correct) {
    Stack<int> stack;
    Stack<int> stack1;
    stack.push(5);
    stack1 = stack;
    EXPECT_EQ(stack1.top(), stack.top());
}
 TEST(Stack, possible_check_Stack_is_empty) {
     Stack<int> stack;
     ASSERT_NO_THROW(stack.empty());
 }
 TEST(Stack, empty_Stack_return_true) {
     Stack<int> stack;
     EXPECT_EQ(true, stack.empty());
 }
 TEST(Stack, not_empty_Stack_return_false) {
     Stack<int> stack;
     stack.push(7);
     EXPECT_EQ(false, stack.empty());
 }
TEST(Stack, count_of_pop_equal_count_of_push) {
    Stack<int> stack;
    int n = 3;
    for(int i=0; i <n; i++)
    {
        stack.push(1);
    }
    int n1 = 0;
    while(!stack.empty())
    {
        stack.pop();
        n1++;
    }
    EXPECT_EQ(true, n1 == n);
}
TEST(Stack, push_change_Stack_size) {
    Stack<int> stack;
    stack.push(4);
    stack.push(3);
    int n = stack.GetSize();
    stack.push(5);
    EXPECT_NE(n, stack.GetSize());
}
TEST(Stack, pop_change_Stack_size) {
    Stack<int> stack;
    stack.push(4);
    stack.push(3);
    int n = stack.GetSize();
    stack.pop();
    EXPECT_NE(n, stack.GetSize());
}
TEST(Stack, top_not_change_Stack_size) {
    Stack<int> stack;
    stack.push(4);
    stack.push(3);
    int n = stack.GetSize();
    stack.top();
    EXPECT_EQ(n,stack.GetSize());
}

