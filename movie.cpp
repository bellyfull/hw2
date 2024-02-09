#include "movie.h"
#include "util.h"

using namespace std;





Movie::Movie(string category, string name, double price, int qty, string genre, string rating) : Product(category, name, price, qty) {
  genre_ = genre;
  rating_ = rating;
}

Movie::~Movie() {

};

std::set<std::string> Movie::keywords() const {

  set<string> keywords_;

  auto genreKeywords = parseStringToWords(genre_);
  auto nameKeywords = parseStringToWords(name_);

  for (const auto& word : genreKeywords) { //for genre parsing
   // cout <<"here" << endl;
    std::string lowerWord;
    for (char ch : word) {
      lowerWord += std::tolower(ch);
    }
    keywords_.insert(lowerWord);
  }
  //cout <<"here" << endl;
  for (const auto& word : nameKeywords) { // for name parsing
    std::string lowerWord;
    for (char ch : word) {
      lowerWord += std::tolower(ch);
    }
    keywords_.insert(lowerWord);
  }
  return keywords_;
}

std::string Movie::displayString() const { //cant use cout must be string format
    string displaystring = "";
    displaystring = name_ + "\n"  + "Genre: " + genre_ + " Rating: " + rating_ + "\n" +
    to_string(price_) + " " + to_string(qty_) + " left." + "\n" ;
    return displaystring;
}

void Movie::dump(std::ostream& os) const {
  Product::dump(os);
  os << genre_ << endl;
  os << rating_ << endl;
}


