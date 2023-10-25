#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

// returns count of non-overlapping occurrences of 'sub' in 'str'
int countSubstring(const string &str, const string &sub) {
  if (sub.length() == 0)
    return 0;
  int count = 0;
  for (int offset = str.find(sub); offset != string::npos;
       offset = str.find(sub, offset + sub.length())) {
    ++count;
  }
  return count;
}

int wordCount(string text) {
  int tot = 0;
  for (int i = 0; i < text.length(); i++) {
    if (text[i] == ' ' && text[i - 1] != ' ') {
      tot++;
    }
  }
  return tot;
}

int uniqueWords(string text) {
  string words[wordCount(text) + 1];
  int tot = 0;
  int tr = 0;
  bool check = false;
  string cur = " ";
  bool rep = false;
  int ch = 0;

  for (int i = 0; i < text.length(); i++) {
    check = false;
    if (text[i] != ' ' && text[i] != '.') {
      ch = i;
      while (!check) {
        ch++;
        if (text[ch] == ' ' || text[ch] == '.') {
          cur = text.substr(i, ch - i);
          check = true;
          i = ch - 1;
          words[tr] = cur;
          tr++;
        }
      }
    }
  }

  for (int i = 0; i < tr; i++) {
    for (int k = i + 1; k < tr; k++) {
      if (words[i] == words[k]) {
        rep = true;
        break;
      }
    }
    if (!rep)
      tot++;
    rep = false;
  }
  return tot - 1;
}

int numSentence(string text) {
  int tot = 0;
  for (int i = 0; i < text.length(); i++) {
    if (text[i] == '.')
      tot++;
  }
  return tot;
}

int averageWords(string text) {
  double ret = ((double)uniqueWords(text) / wordCount(text));
  int ret1 = llround(ret);
  return ret1;
}

int lexicalDens(string text) {
  double ret = ((double)uniqueWords(text) / wordCount(text)) * 100;
  int ret1 = llround(ret);
  return ret1;
}

int main() {

  string source =
      ("I was born in Lousiana down on the ol bayou raised on shrimps and "
       "catfish mamas good gumbo.  I got the ramblin fever.  Said goodbye to "
       "ma and pa.   Crossed that ol red river and this is what I saw. I saw "
       "miles and miles of Texas 1000 stars up in the sky.  I saw miles and "
       "miles of Texas gonna live here till I die.");

  cout << "substring count: " << countSubstring(source, "is") << '\n';
  cout << "word count: " << wordCount(source) << '\n';
  cout << "Unique word count: " << uniqueWords(source) << '\n';
  cout << "Lexical density: " << lexicalDens(source) << "%" << '\n';

  return 0;
}