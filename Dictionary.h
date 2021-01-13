#ifndef Dictionary__H
#define Dictionary__H

#include <string>
#include <vector>

class Dictionary{

 public:

  Dictionary(std::string);
  std::vector<std::string> search(std::string);
  void print();

 private:

  bool remove(std::string);
  bool removeByIndex(int);
  bool isAdjacent(std::string, std::string);

  std::vector<std::string> list;
};


#endif

