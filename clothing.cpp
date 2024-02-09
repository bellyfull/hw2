#include "clothing.h"
#include "util.h"
using namespace std;

Clothing::Clothing(string category, string name, double price, int qty, string brand, string size) : Product(category, name, price, qty) {
  brand_ = brand;
  size_ = size;
}

Clothing::~Clothing() {

};

std::set<std::string> Clothing:: keywords() const {
 cout << "here <" << endl;
  set<string> keywords_;

  auto brandKeywords = parseStringToWords(brand_);
  auto nameKeywords = parseStringToWords(name_);
cout <<" here" << endl;
  for (const auto& word : brandKeywords) { //for brand name parsing
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
  return keywords_;
}

std::string Clothing::displayString() const { //cant use cout must be string format
    string displaystring = "";
    displaystring = name_ + "\n" + "Size: " + size_ + " Brand: " + brand_ + "\n"  +
    to_string(price_) + " " + to_string(qty_) + " left." + "\n" ;
    return displaystring;
}

void Clothing::dump(std::ostream& os) const {
  Product::dump(os);
  os << size_ << endl;
  os << brand_ << endl;
}
