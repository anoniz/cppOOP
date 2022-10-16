// Reg No: 4471 , Name: Abdul Latif,
// Reg No: 4458 , Name: Muhammad Umar,
// Reg No: 5559 , Name: Asil Zulfiqar,


#include <iostream>
#include <string>
#define BSIZE 10
#define MSIZE 5
using namespace std;

class bookType
{
    string title, author, publisher;
    unsigned int ISBN, yop, price, stock;

public:
    bookType()
    {
        title = author = publisher = "";
        ISBN = yop = price = stock = 0;
    }
    string setTitle(string);
    string setAuthor(string);
    string setPublisher(string);
    unsigned int setISBN(unsigned int);
    unsigned int setPrice(unsigned int);
    unsigned int inStock(unsigned int);
    unsigned int setYOP(unsigned int);
    unsigned int getISBN();
    unsigned int getStock();
    unsigned int getPrice();
    void showBook();
};

class memberType
{
    unsigned int ID, bookBought, amountSpent;
    string name;

public:
    memberType()
    {
        name = "";
        ID = bookBought = amountSpent = 0;
    }
    string setName(string);
    unsigned int setID(unsigned int);
    unsigned int setBookBought(unsigned int);
    unsigned int setAmountSpent(unsigned int);
    unsigned int getID();
    unsigned int getBookBought();
    unsigned int getAmountSpent();
    void showMember();
};

class bookStore
{
    bookType books[BSIZE];
    memberType members[MSIZE];

public:
    bookType addBook(bookType, unsigned int &totalBooks);
    memberType addMember(memberType, unsigned int &totalMembers);
    bookType *getBooks();
    memberType *getMembers();
    void removeBook(unsigned int &totalBooks);
    void removeMember(unsigned int &totalMembers);
    void visitStore(unsigned int);
    void visitMembers(unsigned int);
    int buyBooks(unsigned int &totalBooks, unsigned int &totalMembers);
    int adminWorks(bookStore &happyBooks, unsigned int &totalBooks, unsigned int &totalMembers);
};

/////////////////////////////////////////////////////////////////////////////
// bookType Class Functions.......

string bookType::setTitle(string title)
{
    this->title = title;
    return title;
}

string bookType::setAuthor(string author)
{
    this->author = author;
    return author;
}
string bookType::setPublisher(string publisher)
{
    this->publisher = publisher;
    return publisher;
}
unsigned int bookType::setISBN(unsigned int isbn)
{
    ISBN = isbn;
    return isbn;
}

unsigned int bookType::setPrice(unsigned int price)
{
    this->price = price;
    return price;
}

unsigned int bookType::inStock(unsigned int stock)
{
    this->stock = stock;
    return stock;
}

unsigned int bookType::setYOP(unsigned int yop)
{
    this->yop = yop;
    return yop;
}

unsigned int bookType::getISBN()
{
    return ISBN;
}

unsigned int bookType::getStock()
{
    return stock;
}

unsigned int bookType::getPrice()
{
    return price;
}

void bookType::showBook()
{
    cout << "Title : " << title << endl;
    cout << "Author : " << author << endl;
    cout << "Published By : " << publisher << endl;
    cout << "Year of Publication : " << yop << endl;
    cout << "ISBN : " << ISBN << endl;
    cout << "Price : " << price << endl;
    cout << "in Stock : " << stock << endl;
}

////////////////////////////////////////////////////////////////////////////
// memberType Class Functions......

string memberType::setName(string name)
{
    this->name = name;
    return name;
}

unsigned int memberType::setID(unsigned int id)
{
    this->ID = id;
    return id;
}

unsigned int memberType::setBookBought(unsigned int bookBought)
{
    this->bookBought = bookBought;
    return bookBought;
}

unsigned int memberType::setAmountSpent(unsigned int amountSpent)
{
    this->amountSpent = amountSpent;
    return amountSpent;
}

unsigned int memberType::getID()
{
    return ID;
}

unsigned int memberType::getBookBought()
{
    return bookBought;
}

unsigned int memberType::getAmountSpent()
{
    return amountSpent;
}

void memberType::showMember()
{
    cout << "Name : " << name << endl;
    cout << "ID : " << ID << endl;
    cout << "bookBought : " << bookBought << endl;
    cout << "amountSpent : " << amountSpent << endl;
}

/////////////////////////////////////////////////////////////////////////////
// bookStore Class Functions.......

bookType bookStore::addBook(bookType book, unsigned int &totalBooks)
{
    cout << " i am totalBook variable in addBook Func " << totalBooks << endl;

    // books[0] = book;
    books[totalBooks] = book;
    totalBooks++;
    return book;
}

bookType *bookStore::getBooks()
{
    return books;
}

memberType bookStore::addMember(memberType member, unsigned int &totalMember)
{
    members[totalMember] = member;
    totalMember++;
    return member;
}

memberType *bookStore::getMembers()
{
    return members;
}

void bookStore::removeBook(unsigned int &totalBooks)
{
    unsigned int isbn = 0, count = 0;
    bookType emptyBook;
    cout << "Please Give The ISBN Of Book You Wanna Remove \n";
    cin >> isbn;
    for (int i = 0; i < totalBooks; i++)
    {
        if (books[i].getISBN() == isbn)
        {
            books[i] = emptyBook;
            totalBooks--;
            count++;
        }
    }
    if (count == 0)
    {
        cout << "Couldn't Remove The Book.. Given ISBN Not Found..\n";
    }
    else
    {
        cout << "Removed Corresponding Book For Given ISBN....\n";
    }
}

void bookStore::removeMember(unsigned int &totalMembers)
{
    unsigned int id = 0, count = 0;
    memberType emptyMember;
    cout << "Please Give The ID Of Member To Remove \n";
    cin >> id;
    for (int i = 0; i < totalMembers; i++)
    {
        if (members[i].getID() == id)
        {
            members[i] = emptyMember;
            totalMembers--;
            count++;
        }
    }
    if (count == 0)
    {
        cout << "Couldn't Remove The Member.. Given ID Not Found..\n";
    }
    else
    {
        cout << "Removed Corresponding Member For Given ID....\n";
    }
}

int bookStore::buyBooks(unsigned int &totalBooks, unsigned int &totalMembers)
{    if(totalBooks == 0) {
       cout<<" Sorry No Books Available \n"<<endl;
       return 1;
    } 
    unsigned int isbn = 0;
    cout<<endl<<endl;
    cout << "Please Give The ISBN Of The Book You Wanna Buy...\n";
    cin >> isbn;
    for (int i = 0; i < totalBooks; i++)
    {   if(books[i].getISBN() != isbn)
         cout<<"Book Not Found \n";
        if (books[i].getISBN() == isbn)
        {
            if (books[i].getStock() == 0)
            {
                cout << "Sorry This Book is Not Availible in Stocks.. \n";
                break;
            }
            cout << "How Many Books You Wanna Buy? Type Number \n";
            cout << "We Only Have " << books[i].getStock() << " Books Availibe..\n";
            cin >> isbn;
            if (books[i].getStock() < isbn)
            {
                cout << "Sorry We Only Have " << books[i].getStock() << " Books Availibe..\n";
            }
            else if (books[i].getStock() >= isbn)
            {
                unsigned int price = books[i].getPrice();
                unsigned int discount = (price / 10) / 2;
                int memberPrice = (price * isbn) - (discount * isbn);
                unsigned int normalPrice = price * isbn;
                unsigned int newStock = 0;

                unsigned int id;
                char isMember = 'N';
                cout << "Are You A Member Of HappyBook Store?? Type Y/N.. \n";
                cin >> isMember;
                if (isMember == 'Y')
                {
                    cout << "Please Give Your Member ID!! \n";
                    cin >> id;
                    for (int i = 0; i < totalMembers; i++)
                    {
                        if (members[i].getID() == id)
                        {
                            if (members[i].getBookBought() == 10)
                            {
                                price = members[i].getAmountSpent();
                                discount = ((price / 10) / 2);
                                memberPrice = memberPrice - discount;
                                cout << " Its Your 11th BOOK So You Get " << discount << " Rupees Discount \n";
                            }
                        deposit:
                        {
                            cout << "Please Deposit " << memberPrice << " Rupess To Proceed \n";
                            cout << "Just Type " << memberPrice << " Here :) \n";
                            cin >> id;
                        }
                            if (id != memberPrice)
                                goto deposit;
                            else
                            {
                                newStock = books[i].getStock() - isbn;
                                books[i].inStock(newStock);
                                isbn = members[i].getBookBought() + isbn;
                                members[i].setBookBought(isbn);
                                members[i].setAmountSpent(memberPrice);
                                cout << "Thanks For Buying Books From Our HappyBook Store \n";
                                cout << "For Confirmation Visit The Store Again And Check Stocks..\n";
                                cout<<endl<<endl;
                            }
                        }
                    }
                }
                else if (isMember == 'N')
                {
                pay:
                {
                    cout << " Please Deposit " << normalPrice << " Rupess To Procceed \n";
                    cout << "Just Type " << normalPrice << " Here :) \n";
                    cin >> id;
                }
                    if (id != normalPrice)
                        goto pay;
                    else
                    {
                        newStock = books[i].getStock() - isbn;
                        books[i].inStock(newStock);
                        cout << "Thanks For Buying Books From Our HappyBook Store \n";
                        cout << "For Confirmation Visit The Store Again And Check Stocks.. \n";
                        cout << endl
                             << endl;
                    }
                }
            }
        }
    }
        return 0;
}

void bookStore::visitStore(unsigned int totalBooks)
{
    cout<<endl<<endl;
    if (totalBooks == 0)
        cout << "Sorry No Books Availibale in BookStore...\n";
    else
        cout << "These Are All Books Availible in Our BookStore \n";
    for (int i = 0; i < totalBooks; i++)
    {
        cout << " [[" << endl;
        books[i].showBook();
        cout << "            ]]" << endl;
    }
}

void bookStore::visitMembers(unsigned int totalMembers)
{
    cout << endl<<endl;
    for (int i = 0; i < totalMembers; i++)
    {
        cout << " {{ " << endl;
        members[i].showMember();
        cout << "                }} " << endl;
    }
}

//////////////////////////////////////////////////////////////////////////
// Some Other Important Functions..

bookType bookSetter(bookType book)
{
    string title, author, publisher;
    unsigned int ISBN, yop, price, stock;

    cout << "please give title for the book \n";
    cin.ignore();
    getline(cin, title);
    book.setTitle(title);
    cout << "please give the author name \n";
    // cin.ignore();
    getline(cin, author);
    book.setAuthor(author);
    cout << "please give the publisher name \n";
    getline(cin, publisher);
    book.setPublisher(publisher);
    cout << "please give ISBN of the book \n";
    cin >> ISBN;
    book.setISBN(ISBN);
    cout << "please give the price of book \n";
    cin >> price;
    book.setPrice(price);
    cout << "please give year of publication....\n";
    cin >> yop;
    book.setYOP(yop);
    cout << "please give number of books in Stock you want! \n";
    cin >> stock;
    book.inStock(stock);
    cout << "The book has been set successfully! \n";
    return book;
}

memberType memberSetter(memberType member, unsigned int id)
{
    system("clear");
    unsigned int bookBought = 0, amountSpent = 0;
    member.setID(id);
    string name;
    cout << "Please Give Your Name \n";
    cin.ignore();
    getline(cin, name);
    member.setName(name);
    member.setBookBought(bookBought);
    member.setAmountSpent(amountSpent);
    cout << endl
         << "Please Deposit a $10 Membership Fess \n";
    cout << "I am Kidding Just Type '10' Here :-) \n";
    cin >> amountSpent;
    cout << "You Are Now A Memeber Of HappyBook Store, Your ID is " << id << endl;
    return member;
}

int bookStore::adminWorks(bookStore &happyBooks, unsigned int &totalBooks, unsigned int &totalMembers)
{
start:
{   cout<<endl<<endl;
    cout << "What Do You Wanna Do?? \n";
    cout << "1. Add a new book to HappyBook Store? \n";
    cout << "2. Remove a book from HappyBook Store? \n";
    cout << "3. Add a new custom member to HappyBook Store? \n";
    cout << "4. Remove a member from HappyBook Store? \n";
    cout << "5. Add books to Stock?? \n";
    cout << "6. See All Available Books ? \n";
    cout << "7. See All Members Of HappyBook Store? \n";
    cout << "8. Go To The Start Of The Program...\n";
    cout << "Type appropriate numbers of above options... \n";
    unsigned int choise;
    cin >> choise;
    switch (choise)
    {
    case 1:
    {
        bookType book = bookSetter(books[totalBooks]);
        bookType happyStore = happyBooks.addBook(book, totalBooks);
        happyBooks.visitStore(totalBooks);
        goto start;
    }
    break;
    case 2:
    {
        cout<<" Sorry This Feature is Under Developement \n";
        //   happyBooks.removeBook(totalBooks);
        goto start;
    }
    break;
    case 3:
    {
        memberType temp = memberSetter(members[totalMembers], totalMembers);
        memberType temp1 = happyBooks.addMember(temp, totalMembers);
        goto start;
    }
    break;
    case 4:
    {
        cout<<" Sorry This Feature is Under Developement \n";
        //   happyBooks.removeMember(totalMembers);
        goto start;
    }
    break;
    case 5:
    {
         cout<<" Sorry This Feature is Under Developement \n";
         goto start;
    }
    break;
    case 6:
    {
        happyBooks.visitStore(totalBooks);
        goto start;
    }
    break;
    case 7:
    {
        happyBooks.visitMembers(totalMembers);
        goto start;
    }
    break;
    case 8:
    {
        return 1;
    }
    break;
    default:
        cout << " Sorry.. Given Option is not availabale \n";
        goto start;
        break;
    }
}
    return 0;
}

int memberWorks(bookStore &happyBooks,unsigned int &totalBooks, unsigned int &totalMembers)
{   int choise = 0;
    start : {
    cout << "What Do You Wanna Do?? \n";
    cout << "1. Buy A Book?? \n";
    cout << "2. See All Books? \n";
    cout << "3. Go To The Start Of Program? \n";
    cout << "Type appropriate numbers of above options... \n";
    cin>>choise;
    switch(choise) {
        case 1: {
            happyBooks.buyBooks(totalBooks,totalMembers);
            goto start;
        }
        break;
        case 2: {
            happyBooks.visitStore(totalBooks);
            goto start;
        }
        break;
        case 3: {
            return 1;
        }
        default:
        cout << " Sorry.. Given Option is not availabale \n";
        goto start;
        break;
    }
} 
    return 0; 
}



int main1(bookStore &happyBooks, memberType &tempMember, unsigned int &totalBooks, unsigned int &totalMember, unsigned int password)
{

    char isMember = 'N';
    unsigned int userPass = 0;
    bool isAdmin = false;
start:
{   cout<<endl<<endl;
    cout << "Are You a Member Of HappyBook Store? Type Y/N \n";
    cout << " Are you an Admin Here?? Type 'A' \n";
    cin >> isMember;
    switch (isMember)
    {
    case 'Y': {
        int val = memberWorks(happyBooks,totalBooks,totalMember);
        if(val) return 1;
        goto start;
    }
    break;
    case 'N':
    {
        cout << "Do You Want To Become Member? Type Y/N \n";
        cin >> isMember;
        switch (isMember)
        {
        case 'N':
        {
            cout << "Do You Wanna Buy Any Books or Just Visit Our BookStore? Type B/V \n";
            cin >> isMember;
            switch (isMember)
            {
            case 'V':
            {
                happyBooks.visitStore(totalBooks);
                goto start;
            }
            break;
            case 'B':
            {
                happyBooks.visitStore(totalBooks);
                if (totalBooks == 0) goto start;
                happyBooks.buyBooks(totalBooks, totalMember);
                goto start;
            }
             break;
            }
        }
        break;
        case 'Y':
        {
            memberType member = memberSetter(tempMember, totalMember);
            memberType addedMember = happyBooks.addMember(member, totalMember);
            addedMember.showMember();
            goto start;
        }
        break;
        }
    }
    break;
    case 'A':
    {
        cout << "Please Insert Admin Password... :) 1234 \n";
        cin >> userPass;
        if (userPass == password)
        {
            isAdmin = true;
            system("clear");
            userPass = happyBooks.adminWorks(happyBooks, totalBooks, totalMember);
            if (userPass) return 1;       
        }
         else {
            cout<<" Wrong Password..... \n";
            goto start;
         }
    }
    break;
    default:
        break;
    }
}

    return 0;
}

int main()
{
    system("clear");

    unsigned int totalBooks = 0, totalMember = 0;
    unsigned int password = 1234;
    bookStore happyBooks;
    memberType tempMember;
    int val = 0;
    do
    {
        val = main1(happyBooks, tempMember, totalBooks, totalMember, password);

    } while (val);

    return 0;
}