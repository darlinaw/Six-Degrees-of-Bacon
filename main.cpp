#include <iostream>
#include <string>
#include <vector>

#include "W_Node.h"
#include "Dictionary.h"


using namespace std;


vector<WNodeVec> searchBacon(string find, Dictionary dict){ // returns double vector with pathway to bacon                                                                                             

  vector<WNodeVec> doubleVect; // double vector                                                                                                                                                        

  WNode nodeFirst(find); // node for find string                                                                                                                                                       
  nodeFirst.link = &nodeFirst;
  WNodeVec vectFirst; // first vector                                                                                                                                                                  
  vectFirst.push_back(nodeFirst);
  doubleVect.push_back(vectFirst); // adds first vector to double vector                                                                                                                               

  WNodeVec *head = &doubleVect.at(0); // pointers to keep track                                                                                                                                        
  WNodePtr track = &doubleVect.at(0).at(0); // tracks nodes for *link                                                                                                                                  

  int index = 0;

  while(!head->empty()){
    // cout << "run: " << index << endl;                                                                                                                                                               

    WNodeVec* newVect = new WNodeVec; // dynamically allocated vector                                                                                                                                  

    for(int i = 0; i < head->size(); i++){ // iterates through WNodeVec elements                                                                                                                       

      track = &doubleVect.at(index).at(i); // sets track to a node                                                                                                                                     

      vector<string> temp = dict.search(track->word); // search vector                                                                                                                                 

      for(int j = 0; j < temp.size(); j++){ // iterates through string search vector, converts to WNodeVec                                                                                             

        WNode nodeTemp(temp.at(j));
        nodeTemp.link = track;

        //      cout << "word: " << temp.at(j) << endl;                                                                                                                                                

        newVect->push_back(nodeTemp);

        if(temp.at(j) == "bacon"){ //returns if bacon is found                                                                                                                                         
          // WNodePtr bacon = &nodeTemp;                                                                                                                                                               
          doubleVect.push_back(*newVect);
          return doubleVect;
        }
      }
    }
    doubleVect.push_back(*newVect); // adds new vector to the double vector                                                                                                                            
    index++; // updates index 
    
    head = &doubleVect.at(index); // updates head                                                                                                                                                      
    delete newVect; newVect = 0; // deletes dynamic vector                                                                                                                                             
  }

  return doubleVect;
}



void printSearch(vector<WNodeVec> doubleVect, string find){ // prints pathway                                                                                                                          

  WNodeVec *checkEnd = &doubleVect.at(doubleVect.size()-1);

  if(checkEnd->size() == 0){ // if last WNodeVec is empty                                                                                                                                              
    cout << "no path from " << find << " to bacon. " << endl;
    return;
  }

  WNodePtr temp = &checkEnd->at(0);

  int index = 1;

  while(temp->word != "bacon"){ // finds bacon node                                                                                                                                                    
    temp = &checkEnd->at(index);
    index++;
  }
  while(temp->word != find){ // prints nodes until reaches find node                                                                                                                                   
    cout << temp->word << endl;
    temp = temp->link;

  }
  cout << find << endl;
}



int main(int argc, char **argv){
  //  cout << "argc: " << argc;                                                                                                                                                                        
  if(argc != 2){
    cerr << "Incorrect number of arguments";
    return 0;
  }

  cout << "Six Degrees of Bacon" << endl;
  cout << "Darlina Williams, dwilliam@pengo.cabrillo.edu, darwilliams21@gmail.com" << endl;

  Dictionary dict(argv[1]);

  string find = "";
  cout << "Your word?";
  cin >> find;

  if(find.length() != 5){
    cerr << "Word must be of length 5" << endl;
    return 0;
  }

  vector<WNodeVec> test;

  test = searchBacon(find, dict);

  printSearch(test, find);

  return 0;
}

