#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords)
{
    set<string> words;
    string word;
    unsigned int length = rawWords.length();
    // unsigned int start = 0;
    // cout << "blah " << endl;
    for (unsigned int i=0; i<length; ++i) {
        if (!(ispunct(rawWords[i]) || rawWords[i] == ' ')) { //if it's not a space or punctuation, add the word
            word.push_back(rawWords[i]); //add to current 'word'
        }
        else {
          if (rawWords[i] == '\'' && i+1 < length && rawWords[i+1]=='s') {
            i++;
            continue;
          }
          if (word.empty() == false) { //if word is not empty, its added to 'words set
            words.insert(word);
            word = ""; //word cleared for next word
          }

        }

        //Hello World
    }
    if (word.empty() == false) { //last word check
        words.insert(word);
    }
    return words;
}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}
