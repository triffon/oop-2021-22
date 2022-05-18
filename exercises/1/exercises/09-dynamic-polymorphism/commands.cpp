#include <iostream>
#include <string>

// NVI - non-virtual interface
class Command
{
 public:
    void execute() const { do_execute(); }
    virtual ~Command() = default;
 private:
    virtual void do_execute() const = 0;
};

class Info: public Command
{
 public:
    Info(std::ostream& out):
        m_out{out}
    {}
 private:
    std::ostream& m_out;

    void do_execute() const final
    {
        m_out << "Type DOUBLE <int> to get the integer times two\n"
              << "Type GREET <string> to get a custom greeting\n"
              << "Type ADD <int> <int> to get the sum of the integers\n";
    }
};

class Invalid: public Command
{
 public:
    Invalid(std::ostream& out):
        m_out{out}
    {}
 private:
    std::ostream& m_out;

    void do_execute() const final
    {
        m_out << "INVALID COMMAND; Type INFO to get a list of corret commands\n";
    }
};

class Double: public Command
{
 public:
    Double(std::ostream& out, int arg):
        m_out{out},
        m_arg{arg}
    {}
 private:
    std::ostream& m_out;
    int m_arg;

    void do_execute() const final
    {
        m_out << m_arg * 2 << '\n';
    }
};

class Add: public Command
{
 public:
    Add(std::ostream& out, int lhs, int rhs):
        m_out{out},
        m_lhs{lhs},
        m_rhs{rhs}
    {}
 private:
    std::ostream& m_out;
    int m_lhs;
    int m_rhs;

    void do_execute() const final
    {
        m_out << m_lhs + m_rhs << '\n';
    }
};

class Greet: public Command
{
 public:
    Greet(std::ostream& out, const std::string& arg):
        m_out{out},
        m_arg{arg}
    {}
 private:
    std::ostream& m_out;
    std::string m_arg;

    void do_execute() const final
    {
        m_out << "Hello, " << m_arg << "!!!\n";
    }
};

// TODO: Add better error handling
// TODO: Use smart pointers
class CommandParser
{
 public:
    CommandParser(std::istream& in, std::ostream& out):
        m_in{in},
        m_out{out}
    {}

    Command * parse() const
    {
        Command * c = do_parse();
        if (m_in.fail())
        {
            m_in.clear();
            m_in.ignore();
            delete c;
            return new Invalid{m_out};
        }

        return c;
    }

    bool done() const
    {
        return static_cast<bool>(!m_in);
    }
 private:
    std::istream& m_in;
    std::ostream& m_out;

    Command * do_parse() const
    {
        std::string command_name;
        m_in >> command_name;

        if (command_name == "INFO")
        {
            return parse_info();
        }

        if (command_name == "DOUBLE")
        {
            return parse_double();
        }

        if (command_name == "ADD")
        {
            return parse_add();
        }

        if (command_name == "GREET")
        {
            return parse_greet();
        }

        return parse_invalid();
    }

    Command * parse_info() const
    {
        return new Info{m_out};
    }

    Command * parse_invalid() const
    {
        return new Invalid{m_out};
    }

    Command * parse_double() const
    {
        int arg;
        m_in >> arg;
        return new Double{m_out, arg};
    }

    Command * parse_add() const
    {
        int lhs;
        int rhs;
        m_in >> lhs >> rhs;

        return new Add{m_out, lhs, rhs};
    }

    Command * parse_greet() const
    {
        std::string arg;
        m_in.ignore();
        std::getline(m_in, arg);
        return new Greet{m_out, arg};
    }
};

class Console
{
 public:
    Console(std::istream& in, std::ostream& out):
        m_parser{in, out}
    {}

    void repl()
    {
        while(!done())
        {
            Command * command{read()};
            evaluate(command);
            delete command;
        }
    }
 private:
    CommandParser m_parser;

    void evaluate(Command * command) const
    {
        command->execute();
    }

    Command * read() const
    {
        return m_parser.parse();
    }

    bool done() const
    {
        return m_parser.done();
    }
};

int main()
{
    Console c{std::cin, std::cout};

    c.repl();
    return 0;
}
