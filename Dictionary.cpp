#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

#include "Dictionary.h"

using std::string;
using std::vector;



Dictionary::Dictionary(string filename){ // constructor, transfer file words into vector                                                                                                               
  std::ifstream inF;
  inF.open(filename.c_str());
  if(inF.fail()){
    std::cerr << "Error in filename" << std::endl;
    std::exit(1);
  }
  for(string word; getline(inF, word);){
    list.push_back(word);
  }
}




void Dictionary::print(){ // prints vector                                                                                                                                                             
  auto iter = list.begin();
  for(iter = list.begin(); iter < list.end(); iter++){
    std::cout << *iter << std::endl;
  }
}


vector<string> Dictionary::search(string find){ // finds adjacent words and removes them from list                                                                                                     

  vector <string> adjacentWords;

  auto iter = list.begin();

  for(iter = list.begin(); iter < list.end(); iter++){
    //    std::cout << "iter is on: " << *iter << std::endl;                                                                                                                                           
    if(isAdjacent(find, *iter)){
      adjacentWords.push_back(*iter);
      remove(*iter);
      if(*iter == "bacon")
        return adjacentWords;
     }
   }

  return adjacentWords;
}






bool Dictionary::isAdjacent(string find, string temp){ // tests if a word is adjacent                                                                                                                  

  if(find.length() != temp.length())
    return false;

  int count = 0;

  for(int i = 0; i < find.length(); i++){
    if(find[i] != temp[i])
      count++;
  }

  if(count == 1)
    return true;

  return false;
}


bool Dictionary::remove(string find){ // removes a word                                                                                                                                                
  auto iter = list.begin();
  for(iter = list.begin(); iter < list.end(); iter++){
    if(*iter == find){
      list.erase(iter);
      return true;
    }

  }


  return false;
}







bool Dictionary::removeByIndex(int index){
  list.erase(list.begin()+index);
  return true;


}
