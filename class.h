class Base{
public:
    Base();
    ~Base();
};  

//////////////////////////////
class Book{
private:
    char* title;
    char* writer_name;
    int isbn;
public:
    Book();
    ~Book();

    void set_title(const char*);
    void set_writer_name(const char*);
    void set_isbn(int);

    char* get_title() const;
    char* get_writer_name() const;
    int get_isbn() const;
};

////////////////////////////
class Shelf{
private:
    char* name;
    int max_load;
    int curr_load;
    bool empty;
    bool full;
public:
    Shelf();//const char*);
    ~Shelf();

    void set_max_load(int);
    void set_curr_load(int);
    void place_book();
    void take_book();
    void print();

    int get_max_load() const;
    int get_curr_load() const;

    Book b;
};

////////////////////////////
class Closet{
public:
    Closet();
    ~Closet();

    void place_book(int);
    void take_book(int);

    void print();

    Shelf sc1, sc2;
};

/////////////////////////////
class Bookcase{  
private: 
    int num_of_books;
public:
    Bookcase();
    ~Bookcase();

    Shelf s1, s2, s3;
    Closet cc;

    void place_book(int);
    void take_book(int);
    void print();
};