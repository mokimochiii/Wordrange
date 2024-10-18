#include <iostream>
#include "avl.h"
#include <stack>
#include <stdexcept>
#include <fstream>
#include <array>
#include <vector> 
#include <algorithm>
#include <sstream>
#include <cstring>
using namespace std;

int main(int argc, char** argv){
  if (argc < 3) {
    throw std::invalid_argument("Usage: ./treewrapper <INPUT FILE> <OUTPUT FILE>"); // throw error
  }

  ifstream input; // stream for input file
  ofstream output; // stream for output file

  input.open(argv[1]); // open input file
  output.open(argv[2]); // open output file
  if(!input || !output){
    throw std::runtime_error("Error: Unable to open input or output file."); 
    return 1;
  }
  
  AVL tree;

  char op;
  string word1, word2;
  while(input >> op >> word1){
    if(op == 'i'){
      tree.insert(word1);
    }else if(op == 'r'){
      input >> word2;
      int count = tree.countInRange(word1,word2);
      output << count << endl;
    }
  }

  tree.deleteTree();
  input.close();
  output.close();
}
