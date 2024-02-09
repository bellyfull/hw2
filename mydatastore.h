#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include <string>
#include <set>
#include <vector>
#include "product.h"
#include "user.h"
#include "datastore.h"
#include <algorithm>
#include "db_parser.h"
#include <map>
#include "util.h"


/**
 * DataStore Interface needed for parsing and instantiating products and users
 *
 * A derived version of the DataStore can provide other services as well but
 * must support those below
 *
 * DO NOT EDIT
 */


class MyDataStore : public DataStore {
public:
  MyDataStore();
  ~MyDataStore();

    /**
     * Adds a product to the data store
     */
  void addProduct(Product* p);
  void addUser(User* u);

  std::vector<Product*> search(std::vector<std::string>& terms, int type);

  void dump(std::ostream& ofile);

  void addToCart(std::string username, Product* p);
  void viewCart(std::string username);
  void buyCart(std::string username);

  private:
    std::set<Product*> products_;
    std::set<User*> users_;
    std::map<std::string,std::set<Product*>> searchmap;
    std::map<std::string,std::vector<Product*>> cart;
};

#endif
