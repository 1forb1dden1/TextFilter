#include <iostream>
#include <deque>
#include <iomanip>
#include <cmath>
#include <iterator>
#include <vector>
#include <map>

using namespace std;

template <class xtype>
struct tnode
{
  int balance;
  xtype info;
  tnode<xtype>* left;
  tnode<xtype>* right;
};

template<class xtype>
struct tdata
{
  int totalWords = 0;
  int uniqueWords = 0;
  int uniqueWordsThreeLetterMore = 0;
  //excludes spaces and punctuations.
  int totalCharacter = 0;
  std::map<std::string, int> WordCount;
};

template <class xtype>
class AVLtree
{
private:
  tnode<xtype>* root;
  tdata<xtype> data;
public:
  AVLtree();
  ~AVLtree();
  void destroy();
  void destroy(tnode<xtype>*&);
  AVLtree(const AVLtree<xtype>&);
  void copyAVL(tnode<xtype>*&, tnode<xtype>*);
  int getTotalWords();
  int getUniqueWords();
  int getUniqueWordsThreeLetterMore();
  int getTotalCharacter();
  bool isEmpty();
  void rotateLeft(tnode<xtype>*&);
  void rotateRight(tnode<xtype>*&);
  void balanceLeft(tnode<xtype>*&);
  void balanceRight(tnode<xtype>*&);
  void insertNode(tnode<xtype>*&, std::string, bool&);
  void insert(std::string);
  int  maxH(tnode<xtype>*);
  void printB(int, int, int, int, const deque<tnode<xtype>*>&);
  void printN(int, int, int, int, const deque<tnode<xtype>*>&);
  void printL(int, const deque<tnode<xtype>*>&);
  void printAVL(tnode<xtype>*);
  void print();
  void Delete(xtype item);
  void Delete(tnode<xtype>*& p, xtype item);
  void DeleteNode(tnode<xtype>*& p);
};
