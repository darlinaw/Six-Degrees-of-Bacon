#ifndef W_NODE__H
#define W_NODE__H

#include <string>
#include <vector>

// "Linkable" (to create a trace) string (a word)                                                                                                                                                      
struct WNode{
  WNode(std::string s=""){word = s; link = 0;}
  std::string word;
  WNode *link;
};

// example typedefs:                                                                                                                                                                                   
typedef WNode* WNodePtr;

typedef std::vector<WNode> WNodeVec;

#endif

