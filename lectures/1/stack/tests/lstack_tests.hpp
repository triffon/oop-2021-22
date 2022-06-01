#include "../lstack.hpp"

using TestStack = LinkedStack<int>;

TEST_CASE("LinkedStack: след създаване на стек той е празен") {
    TestStack s;
    CHECK(s.empty());
}

TEST_CASE("LinkedStack: стекът не е празен след добавяне") {
    TestStack s;
    s.push(10);
    CHECK(!s.empty());
}

TEST_CASE("LinkedStack: елементите се изключват в ред обратен на включване") {
    TestStack s;
    s.push(10); s.push(20); s.push(30);
    CHECK( !s.empty() );
    CHECK_EQ( s.pop(), 30);
    CHECK_EQ( s.pop(), 20);
    CHECK_EQ( s.pop(), 10);
    CHECK( s.empty() );
}

TEST_CASE("LinkedStack: peek връща последно включения елемент") {
    TestStack s;
    s.push(10);
    CHECK_EQ( s.peek(), 10);
    s.push(20);
    CHECK_EQ( s.peek(), 20);
    s.pop();
    CHECK_EQ( s.peek(), 10);
}

TEST_CASE("LinkedStack: опит за поглеждане в празен стек") {
    TestStack s;
    int x;
    CHECK( ! s.peek(x) );
}

TEST_CASE("LinkedStack: безопасният peek връща последно включения елемент") {
    TestStack s;
    s.push(10);
    int x;
    CHECK( s.peek(x));
    CHECK_EQ( x, 10 );
    s.push(20);
    CHECK( s.peek(x));
    CHECK_EQ( x, 20 );
    s.pop();
    CHECK( s.peek(x));
    CHECK_EQ( x, 10 );
}


TEST_CASE("LinkedStack: конструкторът за копиране не споделя памет") {
    TestStack s1;
    for(int i = 1; i <= 10; i++)
        s1.push(i);
    TestStack s2 = s1;
    std::cout << s2.pop() << std::endl;
    s2.push(20);
    for(int i = 10; i >= 1; i--) {
        CHECK(! s1.empty());
        CHECK_EQ(s1.pop(), i);
    }
    CHECK(s1.empty());
}