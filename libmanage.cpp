#include <iostream>     //decalred header files
#include <string>
#include <conio.h>
#include <vector>

using namespace std;

// structure BookInfo to store the title, author & book id 
struct BookInfo
{
    string title;
    string author;
    int book_id;
    int book_count;
};


// structure MemberInfo to store the name, Id & designation
struct MemberInfo
{
    string name;
    string designation;
    int member_id;
};


// Library Class to declare the private & public functions
class Library
{

private:
    vector<BookInfo> books;         //decalred books vector to store books information
    vector<MemberInfo> member;      //decalred member vector to store members information

public:

    //decalred addBook() to add book information in vector books
    void addBook(string title,string author,int book_id,int book_count)
    {
        books.push_back({title,author,book_id,book_count});
    }

    //declared displayBook() to display books information
    void displayBook()
    {
        cout << endl;
        cout << "-----------------" << endl;
        cout << "Books Information" << endl;
        cout << "-----------------" << endl << endl;

        if(books.size()==0)
        {
            cout << endl << "Sorry there are no books added in the library!!!!" << endl << endl;
        }
        else
        {
            for(int i=0;i<books.size();i++)
            {
                cout << "Title :- " << books[i].title << endl;
                cout << "Author :- " << books[i].author << endl;
                cout << "Book Id :- " << books[i].book_id << endl;
                cout << "Book Count :- " << books[i].book_count << endl << endl;
            }
        }
    }

    //decalred addMember() to add members information in vector member
    void addMember(string name,string designation,int member_id)
    {
        member.push_back({name,designation,member_id});
    }

    //declared displayMember() to display members information
    void displayMember()
    {
        cout << endl;
        cout << "------------------" << endl;
        cout << "Member Information" << endl;
        cout << "------------------" << endl << endl;

        if(member.size()==0)
        {
            cout << endl << "Sorry there are no members in the library!!!!" << endl << endl;
        }
        else
        {
            for(int i=0;i<member.size();i++)
            {
                cout << "Name :- " << member[i].name << endl;
                cout << "Designation :- " << member[i].designation << endl;
                cout << "Member Id :- " << member[i].member_id << endl << endl;
            }
        }
    }

    //declared bookIssue() for issuing the book
    int bookIssue(int id)
    {
        bool check=false;
        for(int i=0; i<books.size();i++)
        {
            if(books[i].book_id==id)
            {
                if(books[i].book_count>0)
                {
                    cout << endl;
                    cout << "Issuing Book....." << endl << endl;
                    cout << "Title :- " << books[i].title << endl;
                    cout << "Author :- " << books[i].author << endl;
                    cout << "Book Id :- " << books[i].book_id << endl;
                    cout << endl << "Book issued from the library!!!" << endl << endl;
                    books[i].book_count--;
                    check=true;
                    break;
                }
                else
                {
                    cout << endl << "Sorry, Currently this book is not available!!!" << endl;
                    check=true;
                }
            }
        }
        if(check==false)
        {
            if(books.size()==0)
            {
                cout << endl << "Sorry there are no books added in the library!!!!" << endl << endl;
            }
            else
            {
                cout << endl << "Sorry you have entered wrong book id !!!" << endl;
            }
        }
    }

    //declared bookReturn() to return the book
    int bookReturn(int id)
    {
        bool check=false;
        for(int i=0; i<books.size();i++)
        {
            if(books[i].book_id==id)
            {
                cout << endl;
                cout << "Book Returned....." << endl << endl;
                cout << "Title :- " << books[i].title << endl;
                cout << "Author :- " << books[i].author << endl;
                cout << "Book Id :- " << books[i].book_id << endl;
                cout << endl << "Book returned to the library!!!" << endl << endl;
                books[i].book_count++;
                check=true;
                break;
                
            }
        }
        if(check==false)
        {
            if(books.size()==0)
            {
                cout << endl << "Sorry there are no books added in the library!!!!" << endl << endl;
            }
            else
            {
                cout << endl << "Sorry you have entered wrong book id !!!" << endl;
            }
        }
    }
};


// Golbal Object of the class Library
Library lib;


// declared librarian() to perform operations by the Librarian
void librarian()
{
    int temp=1,temp1=1;
    string book_title,book_author;
    int b_id,b_count;

    while(temp==1)
    {
        int choice1;
        cout << endl;
        cout << "Choose the operation you want to do " << endl;
        cout << "1. Add books \n2. Display Book Information \n3. Display Member Information" << endl;
        cout << "Choice :- ";
        cin >> choice1;

        switch (choice1)
        {
        case 1: cout << endl << "Taking you on the page...." << endl << endl;
                while(temp1==1)
                {
                    cout << "Enter the title of the book :- ";
                    cin >> book_title;
                    //getline(cin,book_title);
                    while ((getchar()) != '\n');
                    cout << "Enter the author of the book :- ";
                    cin >> book_author;
                    //getline(cin,book_author);
                    cout << "Enter the book Id :- ";
                    cin >> b_id;
                    cout << "Enter the book count :- ";
                    cin >> b_count;
                    lib.addBook(book_title,book_author,b_id,b_count);

                    cout << endl << "Book added in the library!!!" << endl << endl;
                    cout << endl << "Do you want add more books ? (1/0) :- ";
                    cin >> temp1;
                }
                break;

        case 2: lib.displayBook();
                break;
        
        case 3: lib.displayMember();
                break;
        
        default:cout << "Wrong Choice!!!!" << endl;
                cout << "Enter a valid choice!!!" << endl;
                break;
        }   
        
        cout << endl << "Do you want to do more operations Mr Librarian ?? (1/0) :- ";
        cin >> temp; 
    }
}


// declared teacher() to perform operations by the teacher
void teacher()
{

    int temp=1,temp1=1;
    string teacher_name,teacher_designation;
    int m_id,bid;

    cout << endl;
    cout << "Please fill up your details..." << endl << endl;
    cout << "Enter your name :- ";
    cin >> teacher_name;
    //getline(cin,book_title);
    while ((getchar()) != '\n');
    cout << "Enter the designation :- ";
    cin >> teacher_designation;
    //getline(cin,book_author);
    cout << "Enter the member id :- ";
    cin >> m_id;
    lib.addMember(teacher_name,teacher_designation,m_id);
    cout << "Thank you for the details..!!!" << endl ;

    while(temp==1)
    {
        int choice1;
        cout << endl << "Choose the operation you want to do " << endl;
        cout << "1. Display Book Information \n2. Issue Book \n3. Return Book" << endl;
        cout << "Choice :- ";
        cin >> choice1;

        switch (choice1)
        {
        case 1: lib.displayBook();
                break;

        case 2: cout << endl << "Taking you on the page...." << endl << endl;
                while(temp1==1)
                {
                    cout << "Enter the book Id you want to issue :- ";
                    cin >> bid;
                    lib.bookIssue(bid);
                    cout << endl << "Do you want Issue more books ? (1/0) :- ";
                    cin >> temp1;
                }
                break;
            
        case 3: cout << endl << "Taking you on the page...." << endl << endl;
                while(temp1==1)
                {
                    cout << "Enter the book Id you want to return:- ";
                    cin >> bid;
                    lib.bookReturn(bid);
                    cout << endl << "Do you want return more books ? (1/0) :- ";
                    cin >> temp1;
                }
                break;

        default:cout << "Wrong Choice!!!!" << endl;
                cout << "Enter a valid choice!!!" << endl;
                break;
        }
        
        cout << endl << "Do you want to do more operations Mr Teacher ?? (1/0) :- ";
        cin >> temp; 
    }
}


// declared student() to perform operations by the Student
void student()
{
    int temp=1,temp1=1;
    string student_name,student_designation;
    int s_id,bid;

    cout << endl;
    cout << "Please fill up your details..." << endl << endl;
    cout << "Enter your name :- ";
    cin >> student_name;
    //getline(cin,book_title);
    while ((getchar()) != '\n');
    cout << "Enter the designation :- ";
    cin >> student_designation;
    //getline(cin,book_author);
    cout << "Enter the member id :- ";
    cin >> s_id;
    lib.addMember(student_name,student_designation,s_id);
    cout << "Thank you for the details..!!!" << endl ;

    while(temp==1)
    {
        int choice1;
        cout << endl << "Choose the operation you want to do " << endl;
        cout << "1. Display Book Information \n2. Issue Book \n3. Return Book" << endl;
        cout << "Choice :- ";
        cin >> choice1;

        switch (choice1)
        {
        case 1: lib.displayBook();
                break;

        case 2: cout << endl << "Taking you on the page...." << endl << endl;
                while(temp1==1)
                {
                    cout << "Enter the book Id you want to issue :- ";
                    cin >> bid;
                    lib.bookIssue(bid);
                    cout << endl << "Do you want Issue more books ? (1/0) :- ";
                    cin >> temp1;
                }
                break;
            
        case 3: cout << endl << "Taking you on the page...." << endl << endl;
                while(temp1==1)
                {
                    cout << "Enter the book Id you want to return:- ";
                    cin >> bid;
                    lib.bookReturn(bid);
                    cout << endl << "Do you want return more books ? (1/0) :- ";
                    cin >> temp1;
                }
                break;

        default:cout << "Wrong Choice!!!!" << endl;
                cout << "Enter a valid choice!!!" << endl;
                break;
        }
        
        cout << endl << "Do you want to do more operations Mr Student ?? (1/0) :- ";
        cin >> temp; 
    }
}


// driver function
int main()
{
    int userchoice,temp1=1;
    cout << endl;
    cout << "\t\t\t\t\t===============================================" << endl;
    cout << "\t\t\t\t\t||                                           ||" << endl;
    cout << "\t\t\t\t\t||                                           ||" << endl;
    cout << "\t\t\t\t\t||        Library Management System          ||" << endl;
    cout << "\t\t\t\t\t||                                           ||" << endl;
    cout << "\t\t\t\t\t||                                           ||" << endl;
    cout << "\t\t\t\t\t===============================================" << endl << endl; 

    while(temp1==1)
    {
        cout << "Users : \n1. Librarian \n2. Teacher \n3. Student" << endl;
        cout << "Enter User Choice :- ";
        cin >> userchoice;

        //user choice for the user
        switch (userchoice)
        {
            case 1 :    cout << endl << "Hello Mr. Librarian!!!" << endl << endl;
                        librarian();
                        break;

            case 2 :    cout << endl << "Hello Mr. Teacher!!!" << endl << endl;
                        teacher();
                        break;

            case 3 :    cout << endl << "Hello Dear Student!!!" << endl << endl;
                        student();
                        break;

            default:    cout << "Wrong Choice!!!!" << endl;
                        cout << "Enter a valid choice!!!" << endl;
                        break;
        }
        cout << endl << "Do you want to continue the program ?? (1/0) :- ";
        cin >> temp1;
    }
    return 0;
}





