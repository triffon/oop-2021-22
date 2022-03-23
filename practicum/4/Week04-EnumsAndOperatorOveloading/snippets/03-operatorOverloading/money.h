#pragma once

class Money
{
private:
    unsigned int levs;
    unsigned int stotinkas;

public:
    Money(const unsigned int levs, const unsigned int stotinkas);

    bool operator == (const Money& other) const;
    bool operator != (const Money& other) const;
    bool operator < (const Money& other) const;
};