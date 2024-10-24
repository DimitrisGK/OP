#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include "class.h"
using namespace std;

int main(int argc,char* argv[]){
    srand((unsigned) time(0));

    int Nmax=std::atoi(argv[1]);
    int L=std::atoi(argv[2]);
    int K1=std::atoi(argv[3]);
    int K2=std::atoi(argv[4]);

    Bookcase bookcase;

    bookcase.s1.set_max_load(Nmax);
    bookcase.s2.set_max_load(Nmax);
    bookcase.s3.set_max_load(Nmax);
    bookcase.cc.sc1.set_max_load(Nmax);
    bookcase.cc.sc2.set_max_load(Nmax);

    Book book[L];
    for (int i=0; i<=L; i++){
        book[i].set_isbn(1+(rand()%L));
        book[i].set_title("title");
        book[i].set_writer_name("writer");
    }

    for(int i=0; i<=K1; i++){
        int o=1+(rand()%5);
        bookcase.place_book(o);
    }

    for(int i=0; i<=K2; i++){
        int e=1+(rand()%5);
        bookcase.take_book(e);
    }
    
    //bookcase.print();

    return 0;
}