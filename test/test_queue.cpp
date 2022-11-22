
#include <gtest.h>
#include "Stack_Queue.h"
TEST(Queue, create_queue_with_default_konstruktor) {
     ASSERT_NO_THROW(Queue<int> q);
 }

 TEST(Queue, can_push_element_to_queue) {
     Queue<int> q;
     ASSERT_NO_THROW(q.push(1));
 }
 TEST(Queue, can_pop_not_empty_queue) {
     Queue<int> q;
     q.push(1);
     ASSERT_NO_THROW(q.pop());
 }
 TEST(Queue, cant_pop_empty_queue) {
     Queue<int> q;
     ASSERT_ANY_THROW(q.pop());
 }
 TEST(Queue, front_and_push_work_correctly) {
     Queue<int> q;
     q.push(2);
     EXPECT_EQ(2,q.front());
 }
 TEST(Queue, GetSize_work_correctly) {
     Queue<int> q;
     q.push(4);
     q.push(5);
     q.push(8);
     EXPECT_EQ(3, q.GetSize());
 }
 TEST(Queue, can_copy_another_queue) {
     Queue<int> q;
     q.push(2);
     q.push(1);
     ASSERT_NO_THROW(Queue<int>q1(q));
 }
 TEST(Queue, copy_queue_has_the_same_front) {
     Queue<int> q;
     q.push(2);
     q.push(1);
     Queue<int> q1(q);
     EXPECT_EQ(q1.front(),q.front());
 }
TEST(Queue, copy_queue_has_the_same_size) {
    Queue<int> q;
    q.push(2);
    q.push(1);
    Queue<int> q1(q);
    EXPECT_EQ(q.GetSize(), q1.GetSize());
}
TEST(Queue, copy_queue_has_the_same_top_after_pop) {
    Queue<int> q;
    q.push(2);
    q.push(1);
    Queue<int> q1(q);
    q.pop(), q1.pop();
    EXPECT_EQ(q1.front(), q.front());
}
 TEST(Queue, assign_operator_can_copy_another_queue) {
     Queue<int> q;
     Queue<int> q1;
     q.push(5);
     ASSERT_NO_THROW(q1 = q);
 }
 TEST(Queue, assign_operator_copy_queue_size_correct) {
     Queue<int> q;
     Queue<int> q1;
     q.push(5);
     q1 = q;
     EXPECT_EQ(q.GetSize(), q1.GetSize());
 }
TEST(Queue, assign_operator_copy_queue_front_correct) {
    Queue<int> q;
    Queue<int> q1;
    q.push(5);
    q1 = q;
    EXPECT_EQ(q1.front(), q.front());
}
 TEST(Queue, possible_check_queue_is_empty) {
     Queue<int> q;
     ASSERT_NO_THROW(q.empty());
 }
 TEST(Queue, empty_queue_return_true) {
     Queue<int> q;
     EXPECT_EQ(true, q.empty());
 }
 TEST(Queue, not_empty_queue_return_false) {
     Queue<int> q;
     q.push(1);
     EXPECT_EQ(0, q.empty());
 }
TEST(Queue, count_of_pop_equal_count_of_push) {
    Queue<int> q;
    int n = 3;
    for(int i=0; i <n; i++)
    {
        q.push(1);
    }
    int n1 = 0;
    while(!q.empty())
    {
        q.pop();
        n1++;
    }
    EXPECT_EQ(true, n1 == n);
}
TEST(Queue, push_change_queue_size) {
    Queue<int> q;
    q.push(4);
    q.push(3);
    int n = q.GetSize();
    q.push(5);
    EXPECT_NE(n, q.GetSize());
}
TEST(Queue, pop_change_queue_size) {
    Queue<int> q;
    q.push(4);
    q.push(3);
    int n = q.GetSize();
    q.pop();
    EXPECT_NE(n, q.GetSize());
}
TEST(Queue, top_not_change_queue_size) {
    Queue<int> q;
    q.push(4);
    q.push(3);
    int n = q.GetSize();
    q.front();
    EXPECT_EQ(n,q.GetSize());
}
