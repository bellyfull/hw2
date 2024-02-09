#ifndef MOVIE_H
#define MOVIE_H
#include "product.h"

class Movie : public Product { //constructor
  public: 
    Movie(std::string category, std::string name, double price, int qty, std::string genre, std::string rating);
    virtual ~Movie(); //destructor
    virtual std::set<std::string> keywords() const;
    // virtual bool isMatch(std::vector<std::string>& searchTerms) const;
    virtual std::string displayString() const;
    virtual void dump(std::ostream& os) const;

  private:
    std::string genre_;
    std::string rating_;

};
#endif