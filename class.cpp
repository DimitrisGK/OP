#include <cstring>
#include <iostream>
#include "class.h"
using namespace std;

Base::Base(){
    cout<<"A base is constructed\n"<<endl;
}

Base::~Base(){
    cout<<"A base is destructed\n"<<endl;
}

///////////////////////////////
Book::Book(){}

Book::~Book(){}

void Book::set_title(const char* btitle){
    title= new char[strlen(btitle)+1];
    strcpy(title,btitle);
}

void Book::set_writer_name(const char* writname){
    writer_name= new char[strlen(writname)+1];
    strcpy(writer_name,writname);
}

void Book::set_isbn(int n){
    isbn=n;
}

char* Book::get_title() const{
    return title;
}

char* Book::get_writer_name() const{
    return writer_name;
}

int Book::get_isbn() const{
    return isbn;
}

////////////////////////////////
Bookcase::Bookcase(){
    num_of_books=0;
    cout<<"A bookcase is constructed\n"<<endl;
}

Bookcase::~Bookcase(){
    cout<<"A bookcase is destructed\n"<<endl;
}

void Bookcase::place_book(int n){
    num_of_books=num_of_books+1;
    switch(n){
    case 1:
        cout<<"Placing book in up bookcase shelf\n"<<endl;
        s1.place_book();
        break;
    case 2:
        cout<<"Placing book in middle bookcase shelf\n"<<endl;
        s2.place_book();
        break;
    case 3:
        cout<<"Placing book in down bookcase shelf\n"<<endl;
        s3.place_book();
        break;
    case 4:
        cout<<"Placing book in up closet bookcase shelf\n"<<endl;
        cc.place_book(1);
        break;
    case 5:
        cout<<"Placing book in down closet bookcase shelf\n"<<endl;
        cc.place_book(2);
        break;
    default:
        cout<<"There is no shelf or closet to place a book\n"<<endl;        
    }
}

void Bookcase::take_book(int n){
    num_of_books=num_of_books-1;
    switch (n){
    case 1:
        cout<<"Taking book from up bookcase shelf\n"<<endl;
        s1.take_book();
        break;
    case 2:
        cout<<"Taking book from middle bookcase shelf\n"<<endl;
        s2.take_book();
        break;
    case 3:
        cout<<"Taking book from down bookcase shelf\n"<<endl;
        s3.take_book();
        break;
    case 4:
        cout<<"Taking book from up closet bookcase shelf\n"<<endl;
        cc.take_book(1);
        break;
    case 5:
        cout<<"Taking book from down closet bookcase shelf\n"<<endl;
        cc.take_book(2);
        break;        
    default:
        cout<<"There is no shelf or closet to take a book\n"<<endl;
        break;
    }
}

void Bookcase::print(){
    s1.print();
    s2.print();
    s3.print();
    cc.print();
}

////////////////////////////////////////
Closet::Closet(){
    cout<<"A closet is constructed\n"<<endl;
}

Closet::~Closet(){
    cout<<"A closet is destructed\n"<<endl;
}

void Closet::place_book(int n){
    if (n==1){
        sc1.place_book(); 
    }
    if (n==2){
        sc2.place_book(); 
    }
}

void Closet::take_book(int n){
    if (n==1){
        sc1.take_book(); 
    }
    if (n==2){
        sc2.take_book();
    }
}

void Closet::print(){
    sc1.print();
    sc2.print();
}

///////////////////////////////////////
Shelf::Shelf(){//const char* sh){
    //name=new char[strlen(sh)+1];
    //strcpy(name,sh);
    curr_load=0;
    empty=true;
    full=false;
    cout<<"A shelf is constructed\n"<<endl;
}

Shelf::~Shelf(){
    cout<<"A shelf is destructed\n"<<endl;
    //delete[] name;
}

void Shelf::set_max_load(int n){
    max_load=n;
}

void Shelf::set_curr_load(int n){
    curr_load=n;
}

int Shelf::get_max_load()const{
    return max_load;
}

int Shelf::get_curr_load() const{
    return curr_load;
}

void Shelf::place_book(){
    if(curr_load<max_load){
        empty=false;
        curr_load=curr_load+1;
        b.get_title();
        b.get_writer_name();
        b.get_isbn();
    }
    else if(curr_load==max_load){
        cout<<"The shelf is full\n"<<endl;
        full=true;
    }
}

void Shelf::take_book(){
    if(curr_load>0){
        full=false;
        curr_load=curr_load-1;
    }
    if (curr_load==0){
        cout<<"The self is empty\n"<<endl;
        empty=true;
    }
}

void Shelf::print(){
    if (empty==false){
        cout<<b.get_isbn()<<"\n"<<endl;
        printf("%s", b.get_title());
        cout<<+b.get_title()<<"\n"<<endl;
        printf("%s", b.get_writer_name());
        cout<<+b.get_writer_name()<<"\n"<<endl;
    }
    else {
        cout<<"The self is empty\n"<<endl;
    }
}