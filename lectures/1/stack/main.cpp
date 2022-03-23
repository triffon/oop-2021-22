#include <iostream>
#include <cassert>
#include "stack.hpp"
//#include "rstack.hpp"
#include "lstack.hpp"

//typedef ResizingStack Stack;
//typedef LinkedStack Stack;

void convertBase() {
    unsigned n;
    std::cout << "n = ";
    std::cin >> n;

    unsigned base;
    do {
        std::cout << "base = ";
        std::cin >> base;
    } while (base < 2 || base > 10);

    Stack s;
    unsigned k = n;
    while (k > 0) {
        s.push(k % base);
        k /= base;
    }

    std::cout << n << "(10) = ";
    while (!s.empty())
        std::cout << s.pop();
    std::cout << "(" << base << ")" << std::endl;

}

/*
<израз> ::= <цифра>|(<израз><операция><израз>)
след завършване на функцията expr ще сочи след последния обработен символ
*/

/*
double calculateExpression(char const*& expr) {
    if (isdigit(*expr))
        // <цифра>
        return *expr++ - '0';
    assert(*expr == '(');
    // да сметнем левия операнд, прескачайки отварящата скоба
    double left = calculateExpression(++expr);
    // вече сме сигурни, че сме върху операцията
    assert(isop(*expr));
    char op = *expr;
    // да сметнем десния операнд, прескачайки операцията
    double right = calculateExpression(++expr);
    assert(*expr == ')');
    // да осигурим, че expr сочи след последния обработен символ
    expr++;
    return calculate(left, op, right);
}
*/

bool isdigit(char c) {
    return '0' <= c && c <= '9';
}

bool isop(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int calculate(int left, char op, int right) {
    switch(op) {
        case '+' : return left + right;
        case '-' : return left - right;
        case '*' : return left * right;
        case '/' : return right == 0 ? 0 : left / right;
        default  : assert(isop(op)); return 0;
    }
}

int calculateExpression(char const* expr) {
    Stack results, ops;
    while (*expr) {
        if (isdigit(*expr))
            // <цифра>
            results.push(*expr - '0');
        else if (isop(*expr))
            // <операция>
            ops.push(*expr);
        else if (*expr == ')') {
            int right = results.pop();
            int left = results.pop();
            char op = ops.pop();
            results.push(calculate(left, op, right));
        }
        expr++;
    }
    return results.pop();
}

bool isOpeningParenthesis(char c) {
    return c == '(' || c == '[' || c == '{';
}

bool isClosingParenthesis(char c) {
    return c == ')' || c == ']' || c == '}';
}

bool matchParentheses(char open, char close) {
    return open == '(' && close == ')' ||
           open == '[' && close == ']' ||
           open == '{' && close == '}';
}

void testExpression() {
    const int MAXEXPR = 100;
    char expr[MAXEXPR];
    std::cin.getline(expr, MAXEXPR);
    std::cout << " = " << calculateExpression(expr) << std::endl;
}

bool checkParentheses(const char* expr) {
    Stack s;
    while (*expr != '\0') {
        if (isOpeningParenthesis(*expr))
            s.push(*expr);
        else if (isClosingParenthesis(*expr)) {
            if (s.empty() || !matchParentheses(s.pop(), *expr))
                // грешка тип 2: затваряща скоба без отваряща
                // грешка тип 3: несъвпадащи по вид скоби
                return false;
        }
        expr++;
    }
    // грешка тип 1: повече отварящи скоби
    return s.empty();
}

void autoTestParentheses() {
    assert(true  == checkParentheses("((2+3)*(5-7))"));
    assert(true  == checkParentheses("[(2+3)*{5-7}]"));
    // тест за грешка тип 1
    assert(false == checkParentheses("((2+3)+(5-7)"));
    // тест за грешка тип 2
    assert(false == checkParentheses("((2+3)))*((5-7)"));
    // тест за грешка тип 3
    assert(false == checkParentheses("[(2+3)*{5-7)]"));
    // тест за голям израз (100 скоби)
    assert(true == checkParentheses("((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((2))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))"));
    // тест за голям израз (101 скоби)
    assert(true == checkParentheses("(((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((2)))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))"));
    std::cout << "OK" << std::endl;
}

void testCopyStack() {
    LinkedStack s1;
    for(int i = 1; i <= 10; i++)
        s1.push(i);
    LinkedStack s2 = s1;
    std::cout << s2.pop() << std::endl;
    // !!! std::cout << s1.pop() << std::endl;
    s1.push(20);
    std::cout << s1.peek() << std::endl;
    std::cout << s2.pop() << std::endl;
    std::cout << s1.pop() << std::endl;
    std::cout << s1.pop() << std::endl;   
}

void testDestroyStack() {
    for(int i = 0; i < 1E8; i++) {
        // ResizingStack s;
        LinkedStack s;
        for(int j = 1; j <= 10; j++)
            s.push(j);
    }
    std::cout << "Готово!\n";
    char x; 
    std::cin >> x;
}

int main(int, char**) {
    //convertBase();
    //testExpression();
    //autoTestParentheses();
    // !!! testCopyStack();
    // !!! testDestroyStack();
}
