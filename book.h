#ifndef BOOK_H
#define BOOK_H
#include <fstream>
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "product.h"
using namespace std;
class Book: public Product{
	public:
		Book(string category, string name, double price, int qty,
		string IBSN, string author);
		string nameAuthor();
		string numIsbn();
		set<string> keywords();
		string displayInfo();
		void info(ostream& os);
	private:
		string ISBN_;
		string author_;
};
#endif