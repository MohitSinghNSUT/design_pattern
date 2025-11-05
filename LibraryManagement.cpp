
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Date
{
};
class Books
{
private:
    string title;
    string author;
    string isbn;
    int copies;
    int availableCopies;
    Date borrowDate;

public:
    Books(string t, string a, string i, int c, int ac) : title(t), author(a), isbn(i), copies(c) {}
    void displayInfo()
    {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << isbn << endl;
    }
};

class Member
{
protected:
    string name;
    string memberID;
    int borrowedBooks;
    int Fines;
    vector<Books *> borrowedBookList; 

public:
    virtual int calculateFines() = 0;  // abstract method
    virtual bool BorrowBook() = 0;
    bool ReturnBook()
    {
        if (borrowedBooks > 0)
        {
            borrowedBooks--;
            return true;
        }
        else
        {
            return false;
        }
    };
};
class student : public Member
{
private:
    string course;

public:
    student(string course, string name, string memberID)
    {
        this->course = course;
        this->name = name;
        this->memberID = memberID;
        this->borrowedBooks = 0;
        this->Fines = 0;
    }
    bool BorrowBook(string name)
    {
        if (borrowedBooks < 5)
        {
            borrowedBooks++;
            borrowedBookList.push_back(new Books(name, "", "", 1, 1));
            return true;
        }
        else
        {
            return false;
        }
    };
    int calculateFines()
    {
        //  Assuming a fine of $1 per day for each overdue book
        // current date and calcutate the fine
        int fine = 0;
        return fine;
    }
};

class faculty : public Member
{
private:
    string department;

public:
    bool BorrowBook()
    {
        if (borrowedBooks < 10)
        {
            borrowedBooks++;
            return true;
        }
        else
        {
            return false;
        }
    };
    int calculateFines()
    {
        //  Assuming a fine of $0.5 per day for each overdue book
        // current date and calcutate the fine
        int fine = 0;
        return fine;
    }
};

class Library
{
private:
    string name;
    string address;
    vector<Books *> books;    // composition
    vector<Member *> members; // aggregation
public:
    Library(string n, string a) : name(n), address(a) {}
    void displayInfo()
    {
        cout << "Library Name: " << name << endl;
        cout << "Library Address: " << address << endl;
    }
};
