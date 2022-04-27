#include <iostream>
#include <fstream>
#include <cassert>

using std::ios;

struct Student
{
    char name[50];
    int32_t fn;
};

Student read_student(std::istream& in)
{
    Student s;
    in.read(reinterpret_cast<char *>(&s), sizeof(Student));

    return s;
}

std::ostream& write_student(std::ostream& out, const Student& student)
{
    return out.write(reinterpret_cast<const char *>(&student), sizeof(Student));
}

size_t get_size(std::istream& in)
{
    std::streampos cur{in.tellg()};
    in.seekg(0, ios::end);
    std::streampos size = in.tellg() / sizeof(Student);
    in.seekg(cur);

    return size;
}

Student read_student_at(std::istream& in, size_t pos)
{
    in.seekg(pos * sizeof(Student));
    Student result{read_student(in)};

    return result;
}

std::ostream& write_student_at(std::ostream& out, const Student& student, size_t pos)
{
    out.seekp(pos * sizeof(Student));

    return write_student(out, student);
}

std::ostream& print(std::istream& in, std::ostream& out)
{
    Student student{read_student(in)};

    while (in)
    {
        out << student.fn << ' ' << student.name << '\n';
        student = read_student(in);  
    }
    
    return out;
}

size_t min_student_index(std::istream& in, size_t start_pos)
{
    in.seekg(start_pos * sizeof(Student));

    Student current{read_student(in)};
    Student min{current};
    size_t min_index{start_pos};

    assert(in && "there are students in the file");

    while (in)
    {
        if (current.fn < min.fn)
        {
            min = current;
            min_index = start_pos;
        }

        current = read_student(in);
        start_pos++;
    }

    return min_index;
}

std::fstream& swap_students(std::fstream& stream, size_t pos_1, size_t pos_2)
{
    Student student_1{read_student_at(stream, pos_1)};
    Student student_2{read_student_at(stream, pos_2)};
 
    write_student_at(stream, student_2, pos_1);
    write_student_at(stream, student_1, pos_2);

    return stream;
}

std::fstream& sort(std::fstream& stream)
{
    size_t size{get_size(stream)};

    for(size_t i{0}; i < size; ++i)
    {
        swap_students(stream, i, min_student_index(stream, i));
    }

    return stream;
}

std::ostream& copy_students(std::istream& in, std::ostream& out)
{
    Student student{read_student(in)};

    while (in)
    {
        write_student(out, student);
        student = read_student(in);
    }

    return out;
}

std::ostream& merge(std::istream& in_1, std::istream& in_2, std::ostream& out)
{
    Student student_1{read_student(in_1)};
    Student student_2{read_student(in_2)};

    while (in_1 && in_2)
    {
        if (student_1.fn < student_2.fn)
        {
            write_student(out, student_1);
            student_1 = read_student(in_1);
        }
        else
        {
            write_student(out, student_2);
            student_2 = read_student(in_2);
        }
    }

    if (in_1)
    {
        write_student(out, student_1);
        return copy_students(in_1, out);
    }

    if (in_2)
    {
        write_student(out, student_2);
        return copy_students(in_2, out);
    }
    
    return out;
}

int main()
{
    std::fstream file{
        "students.bin",
        ios::binary | ios::in | ios::out | ios::trunc
    };

    write_student(file, Student{"pe6o", 1});
    write_student(file, Student{"ivan", 3});
    write_student(file, Student{"maria", 5});

    std::fstream file2{
        "students2.bin",
        ios::binary | ios::in | ios::out | ios::trunc
    };

    write_student(file2, Student{"georgi", 2});
    write_student(file2, Student{"joro", 4});
    write_student(file2, Student{"go6o", 6});
    write_student(file2, Student{"teodor", 8});
    write_student(file2, Student{"asparuh", 9});

    file.seekg(0);

    file2.seekg(0);

    std::fstream merged{
        "merged.bin",
        ios::binary | ios::in | ios::out | ios::trunc
    };

    merge(file, file2, merged);

    merged.seekg(0);

    print(merged, std::cout);

    return 0;
}


