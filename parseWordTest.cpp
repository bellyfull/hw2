#include "util.h"

using namespace std;

int main() {
  string test = "Men's crew";

  set<string> keyword = parseStringToWords(test);

  for (auto s : keyword) {
    cout << s << endl;
  }
}