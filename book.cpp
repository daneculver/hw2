#include <sstream>
#include <fstream>
#include <string>
#include <set>
#include <iomanip>
#include "product.h"
#include "book.h"
#include "util.h"
using namespace std;
string Book::nameAuthor(){
	return author_;
}
string Book::numIsbn(){
	return ISBN_;
}
string Book::displayInfo(){
	string item = name_ + "\n" + "Author: " + author_ + " ISBN: " + ISBN_ + "\n";
	stringstream cost, amt;
	string data1, data2;
	cost << price_;
	amt << qty_;
	cost >> data1;
	amt >> data2;
	item = item + data1 + " " + data2 + " left";
	return item;
}
void Book::info(ostream& os){
		os << category_ << endl << name_ << endl << price_ << endl << qty_ << endl << author_ << endl << ISBN_ << endl;
}
Book::Book(string category, string name, double price, int qty, string author,
	string ISBN):Product(category, name, price, qty){
		ISBN_ = ISBN;
		author_ = author;
}
set<string> Book::keywords(){
	set<string> names = parseStringToWords(name_);
	set<string> authors = parseStringToWords(author_);
	set<string> isbns = parseStringToWords(ISBN_);
	names = setUnion<string>(names, authors);
	names = setUnion<string>(names, isbns);
	return names;
}
