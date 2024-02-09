#include "book.h"
#include "util.h"

using namespace std;



Book::Book(string category, string name, double price, int qty, string authorName, string isbn) : Product(category, name, price, qty) {
  authorName_ = authorName;
  isbn_ = isbn;
}

Book::~Book()
{

}

std::set<std::string> Book::keywords() const {
  //also add parse name
  // set<string> keywords_;
  // keywords_ = parseStringToWords(authorName_);
  // keywords_.insert(isbn_);
  // return keywords_;

  cout << "here <" << endl;
  set<string> keywords_;

  auto authorKeywords = parseStringToWords(authorName_);
  auto nameKeywords = parseStringToWords(name_);

cout <<" here" << endl;
  for (const auto& word : authorKeywords) { //for brand name parsing
    std::string lowerWord;
    for (char ch : word) {
      lowerWord += std::tolower(ch);
    }
    keywords_.insert(lowerWord);
  }
cout <<"here" << endl;
  for (const auto& word : nameKeywords) { //for name parsing
    std::string lowerWord;
    for (char ch : word) {
      lowerWord += std::tolower(ch);
    }
    keywords_.insert(lowerWord);
  }
  keywords_.insert(isbn_);
  return keywords_;

}

std::string Book::displayString() const { //cant use cout must be string format
  // cout << "<" << name_ << ">" << endl;
  // cout << "Author: " << authorName_ << "ISBN: " << isbn_ << endl;
  // cout << price_ << " " << qty_ << " left." << endl;
    string displaystring = "";
    displaystring = name_ + "\n" + "Author: " + authorName_ + " " + "ISBN: " + isbn_ + "\n" + to_string(price_) + " " + to_string(qty_) + " left." + "\n";
    return displaystring;
}

void Book::dump(std::ostream& os) const {
  Product::dump(os);
  os << isbn_ << endl;
  os << authorName_ << endl;
}
