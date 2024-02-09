#ifndef CLOTHING_H
#define CLOTHING_H
#include "product.h"

class Clothing : public Product { //constructor
  public: 
    Clothing(std::string category, std::string name, double price, int qty, std::string brand, std::string size);
    virtual ~Clothing(); //destructor
    virtual std::set<std::string> keywords() const;
    // virtual bool isMatch(std::vector<std::string>& searchTerms) const;
    virtual std::string displayString() const;
    virtual void dump(std::ostream& os) const;

  private:
    std::string brand_;
    std::string size_;

};
#endif