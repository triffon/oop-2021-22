#include<iostream>
#include<fstream>
#include <assert.h>
using namespace std;

struct Fraction {
    int num;
    int den;

    Fraction( int num = 0, int den = 1) { this->num = num; this->den = den;}

};

ostream& operator<<(ostream& out, const Fraction& param) {
    out<< param.num<<"/"<<param.den;
    return out;

}


int main() {
   /*  0 STDIN <<
    1 STDOUT >>
    2 STDERROR
    https://www.howtogeek.com/435903/what-are-stdin-stdout-and-stderr-on-linux/
   */
    Fraction temp(100,100);
    Fraction temp1(50,100);
    Fraction temp2(115,100);
    cout<<sizeof(Fraction)<<endl;
    ofstream filedata("test.data" , ios::binary | ios::app);

    if (!filedata.is_open()) {
        // error
    }
    filedata.write((char*) (&temp) , sizeof(Fraction));
    filedata.write((char*) (&temp1) , sizeof(Fraction));
    filedata.write((char*) (&temp2) , sizeof(Fraction));// Here we can use reinterpret_cast<char*>(&temp2)
    // working similar up to Union
    /*
    * union ipAddress {
    * uint32_t addr;
    * uint8_t octet[4];
    * } The size if of the biggest one. All attribues are left with left padding, so they will have in terms of the memory
    */
    filedata.close();

    ifstream filedata1("test.data" , ios::binary | ios::in);
    while(!filedata1.eof()) {
        filedata1.read((char*) (&temp) , sizeof(Fraction));
        cout<<temp<<" "<<filedata1.peek()<<endl;
    }
    // filedata1.seekg(); we can move throw different location. The only think we should carry about is is this actually
    // a place for a new object
    filedata1.close();
    //  [.........| ....... |.....]
    // assert(0); in case of assert not-flshed data will be lost

    return 0;
}
// asd.exe > output.txt
// asd.exe >> output.txt
