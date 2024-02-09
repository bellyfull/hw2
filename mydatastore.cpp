#include <iomanip>
#include <iostream>
#include "util.h"
#include "datastore.h"
#include "mydatastore.h"
#include <vector>
#include "user.h"
#include "product.h"
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

MyDataStore::MyDataStore() {

  
}
MyDataStore::~MyDataStore() {

}

void MyDataStore::addProduct(Product* p) { // needs to generate a list of keywords, each which can be used to search this product
  // set<Product*> products_;
  products_.insert(p); // products list
  auto keywords = p->keywords();
  for (const auto& keyword : keywords) {
    if (searchmap.count(keyword)==0) {
      set<Product*> newProducts;
      newProducts.insert(p);
      searchmap[keyword]=newProducts;
    }
    else {
      searchmap[keyword].insert(p);
    }
  }
  // set<string> keywords = parseStringToWords(p);

  // for (set<string>::iterator it = keywords.begin(); it!= keywords.end(); it++) {
  //   products_[it*].insert(p);
  // }

}

void MyDataStore::addUser(User* u) { 
  // set<User*> users_;
  users_.insert(u);

}

    /**
     * Performs a search of products whose keywords match the given "terms"
     *  type 0 = AND search (intersection of results for each term) while
     *  type 1 = OR search (union of results for each term)
     */
     //so keywords must == terms
std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type) {
  // if (terms.empty()) {
  //   return std::vector<Product*>();
  // }
  // if (terms.size()==1) {
  //   hits = 
  // }
  std::vector<set<Product*>> productWithKeyword;//vector of sets of products* that have this keyword

  for (unsigned int i=0; i<terms.size(); i++) { //iterating thru terms list
    if (searchmap.find(terms[i])!=searchmap.end()) { //found the term in the map
      productWithKeyword.push_back(searchmap[terms[i]]); //adds the set of product* that has this term
    // } else if (type==0) {
    //   return std::vector<Product*>();
    // }
    }
  // if (productWithKeyword.empty()) {
  //   return std::vector<Product*>();
  }
  set<Product*> hits = productWithKeyword.front();
  
  for (unsigned int i=1; i<productWithKeyword.size(); i++) {
    if (type == 0) {
      hits = setIntersection(hits, productWithKeyword[i]);
    }
    else if (type == 1) {
      hits = setUnion(hits, productWithKeyword[i]);
    }
  }

  // for (set<Product*>::iterator it=hits.begin(); it!=hits.end(); it++) {
  //   Product* p = *it;
  //   hits.push_back(p);
  // }
  std::vector<Product*> hitsVector(hits.begin(), hits.end());
  return hitsVector;
}

void MyDataStore::dump(std::ostream& ofile) {
  ofile << "<products>" << endl;
  set<Product*>::iterator it;

  for (it = products_.begin(); it!= products_.end(); it++) {
    Product* temp = *it;
    temp->dump(ofile);
    delete temp;
  }

  ofile <<"</products>" << endl;
  ofile <<"<users>" << endl;
  set<User*>::iterator iter;
  for (iter = users_.begin(); iter != users_.end(); iter++) {
    User* usertemp = *iter;
    usertemp->dump(ofile);
    delete usertemp;
  }
  ofile << "</users>" << endl;
}

void MyDataStore::addToCart(string username, Product* p) {
  if (p->getQty()==0) {
    cout << "out of stock." << endl;
    return;
  }
    /* existence Check */ 
  bool exists = false;
  for (User* user : users_) {
    if (user->getName() == username) {
      exists = true;
      break;
    }
  }

  if (exists == false) {
    cout << "Invalid request" << endl;
  }
  //else
  cart[username].push_back(p); //p will be added to username's cart 

}

void MyDataStore::viewCart(string username) {
    /* existence Check */ 
  bool exist = false;
  for (User* user : users_) { //finding if username exists
    if (user->getName() == username) {
      exist = true;
      break;
    }
  }

  if (exist == false) { // leave function if invalid user
    cout <<"Invalid username" << endl;
    return;
  }

  if (cart.find(username)!=cart.end() && cart[username].empty()==false) {
    for (unsigned int i=0; i<cart[username].size(); i++) {
      cout <<"Product: " << i+1 << endl;
      cout << cart[username][i]->displayString() << endl;
    }
  }
  else {
    cout <<"empty cart." << endl;
  }

}

void MyDataStore::buyCart(string username) {
  /* existence Check */ 
  User* currentUser = nullptr;
  for (User* user : users_) { //finding if username exists
    if (user->getName() == username) {
      currentUser = user;
      break;
    }
  }
  if (!currentUser) {
      cout << "Invalid username" << endl;
      return;
  }

  if(currentUser) {
    std::vector<Product*> other;
    for (Product* item : cart[username]) {
      double price_ = item->getPrice();
      if (price_ <= currentUser->getBalance() && item->getQty()>0) {
        currentUser->deductAmount(price_);
        item->subtractQty(1);
      }
      else {
        cout <<"insufficient funds" << endl;
        other.push_back(item);
      }
    //}
    // if (other.empty()) {
    //   cart[username]=other;
    // }
    // else {
    //   cart.pop(username);
    // }
    }
    if (other.empty()==false) {
       cart[username] = other;
    }
    else {
      cart.erase(username);
    }
}

  else {
    cout << "empty cart." << endl;
  }
}