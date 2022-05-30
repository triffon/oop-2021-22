#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Book {
    string author;
    string name;
    int year;
    int pages;
    double raiting;
    Book (string author="", string name="", int year=0, int pages=0, double raiting=0) : author(author),
        name(name), year(year),  pages(pages), raiting(raiting) {}
};

bool isMin (int a, int b) {
    return a < b;

}

bool isMax (int a, int b) {
    return a > b;
}

bool isAuthorSK(Book c) { // const Book?
    return c.author == "Stephen King";
}

Book updateTPBook(Book c) {
    if (c.author == "Terry Pratchett")
        c.raiting += 0.5;
    return c;
}

vector<Book> mapBook(Book* b, const int N, Book (*f)(Book c)) { //conts Book* ?
    vector<Book> res;
    //Book arr[10]
    for (int i =0;i<N;i++) {
        res.push_back(f(b[i]));
    }
    // return arr?
    return res;
}

vector<Book> filterBook(Book* b, const int N, bool (*f)(Book c)) {
    vector<Book> res;
    //Book arr[10]
    for (int i =0;i<N;i++) {
        if (f(b[i])) { //
            res.push_back(b[i]);
        }
    }
    // return arr??? Where is the problem here....
    return res;
}

// Is this buble sort?
void bubbleSort(int *a, const int N, bool (*f)(int, int)) { // is this bubble sort?
    for (int i = 0; i < N; i++)
        for (int t = i+1; t < N; t++)
           // if (a[i] > a[t])
            if(f(a[i], a[t]))
                swap(a[i],a[t]);

}

//void bubleSortMax(int *a, int N) { DRY principle is broken...
//    for (int i = 0;i<N;i++)
//        for (int t = i+1;t<N;t++)
//            if (a[i] < a[t])
//                swap(a[i],a[t]);
//
//}

int main() {
    const int N = 5;
    [] () {cout<<"Hello Lambda..."<<endl;}();
//    int a[N] = {5,2,4,3,1};
//    bubbleSort(a, N, isMax);
//    for (int i =0;i<N;i++) {
//        cout<<a[i] <<" ";
//    }
//    bubbleSort(a, N, isMin);
//    for (int i =0;i<N;i++) {
//        cout<<a[i] <<" ";
//    }
    Book b[5];
    b[0] = {"Stephen King", "The Dark Tower", 1982, 300,5};
    b[1] = {"Stephen King", "Misery", 1987,250, 4.2};
    b[2] = {"Terry Pratchett", "The Colour of Magic", 1983,130, 4.5};
    b[3] = {"Terry Pratchett", "The Light Fantastic", 1986,130, 4};
    b[4] = {"Terry Pratchett", "Pyramids", 1989, 200, 5};

    vector<Book> res = filterBook(b, N, [] (Book b) { return b.author == "Stephen King" ;});
    cout<<res.size();
    // vector <Book> res = mapBook(b,N, updateTPBook);
    // cout<<res[2].raiting;
    // cout<<res[0].author<<endl;
    return 0;
}