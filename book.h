#ifndef BOOK_H
#define BOOK_H
#include "product.h"

class Book : public Product { //constructor
  public: 
    Book(std::string category, std::string name, double price, int qty, std::string authorName, std::string isbn);
    virtual ~Book(); //destructor
    virtual std::set<std::string> keywords() const;
    // virtual bool isMatch(std::vector<std::string>& searchTerms) const;
    virtual std::string displayString() const;
    virtual void dump(std::ostream& os) const;

  private:
    std::string authorName_;
    std::string isbn_;

};

#endif