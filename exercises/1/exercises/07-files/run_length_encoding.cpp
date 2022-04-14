#include <iostream>
#include <fstream>
#include <cctype>

void run_length_encode(std::istream& in, std::ostream& out)
{
    char c{};

    while (in.get(c))
    {
        unsigned count{1};

        while (c == in.peek())
        {
            in.ignore();
            ++count;
        }

        if (count > 1)
        {
            out << count;
        }
        out.put(c);
    }
}

void run_length_encode(const char * input_file_path, const char * output_file_path)
{
    std::ifstream in{input_file_path};
    std::ofstream out{output_file_path};
    run_length_encode(in, out);
}

void run_length_decode(std::istream& in, std::ostream& out)
{
    while (in)
    {
        if (isdigit(in.peek()))
        {
            unsigned count;

            in >> count;
            char letter = in.get();
            for (; count; --count)
            {
                out.put(letter);
            }
        }
        else
        {
            char letter = in.get();
            if (in)
            {
                out.put(letter);
            }
        }
    }
}

void run_length_decode(const char * input_file_path, const char * output_file_path)
{
    std::ifstream in{input_file_path};
    std::ofstream out{output_file_path};
    run_length_decode(in, out);
}

int main()
{
    run_length_encode("rle_string.txt", "rle_encoded.txt");
    run_length_decode("rle_encoded.txt", "rle_decoded.txt");
    return 0;
}