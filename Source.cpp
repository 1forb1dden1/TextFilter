//Creator: Me
//Created: 5/8/2022 5:48PM
//Last Updated: 5/11/2022 5:01 AM
//Worked on: Created User Interface
//Description: Using an AVL tree to read a report ( runner text ) and issue warnings on style and partially
//correct poor writing style.
//Output:
//1.Total Number of words in the report.
//2.Total number of unique words in the report.
//3.Number of unique words with three or more letters.
//4.Average word length.
//5.Average sentence length
//6.An index(alphabetical listing) of all unique words in the report.
#include "AVL.cpp"
#include <fstream>
#include <stdio.h>
#include <limits>

std::string insertFile()
{
  std::string s;
  std::cout << "Enter the name of the file: "; std::cin >> s;
  system("CLS");
  return s;
}
void LowerCase(std::string &s)
{
  for (int i = 0; i < s.length(); i++)
  {
    s[i] = tolower(s[i]);
  }
}
void inputTree(std::string fileName, AVLtree<std::string> &tree)
{
  std::ifstream file(fileName);
  std::string input;
  while (file >> input)
  {
    input.erase(std::remove_if(input.begin(), input.end(), ispunct), input.end());
    LowerCase(input);
    tree.insert(input);
  }
}
double totalSentences(std::string fileName)
{
  double totalSentences = 0;
  double totalWords = 0;
  std::ifstream file(fileName);
  std::string input;
  while (file >> input)
  {
    if (input[input.length() - 1] == ('.') || input[input.length() - 1] == ('?') || input[input.length() - 1] == ('!'))
    {
      totalSentences++;
    }
  }
  return (totalSentences);
}
void checkWordCount(double n)
{
  if (n == 0)
  {
    std::cout << "There are no words in this file." << std::endl;
  }
  else if (n >= 8)
  {
    std::cout << "AVERAGE WORD LENGTH TOO LONG - " << n << "Chracters" << std::endl;
  }
  else
  {
    std::cout << "THE AVERAGE WORD LENGTH: " << n << std::endl;
  }
}
void checkSentenceLength(double n)
{
  if (n == 0)
  {
    std::cout << "There are no sentences in this file." << std::endl;
  }
  else if (n >= 12)
  {
    std::cout << "AVERAGE SENTENCE LENGTH TOO LONG - " << n <<  " words" << std::endl;
  }
  else
  {
    std::cout << "THE AVERAGE SENTENCE LENGTH: " << n << std::endl;
  }
}
void displayWordUsedOften(std::map<std::string, int> map, int totalwords)
{
  //one percent of words
  int temp = totalwords / 100;
  std::map<string, int>::iterator it;
  int counter = 1;
  std::cout << "\n";
  std::cout << "~Words Used Too Much~" << std::endl;
  for (it = map.begin(); it != map.end(); it++)
  {
    if (it->second > temp && it->first.length() > 3)
    {
      std::cout << counter << ") " << it->first << std::endl;
      counter++;
    }
  }
  std::cout << "~Words Used Too Much~" << std::endl;
  std::cout << "\n";
}
void displayUniqueWords(std::map<std::string, int> map)
{
  std::map<string, int>::iterator it;
  char firstLetter = 'a';
  for (it = map.begin(); it != map.end(); it++)
  {
    if(toupper(it->first[0]) != firstLetter)
    {
      firstLetter = toupper(it->first[0]);
      std::cout << "\n" << "*" << firstLetter << "*" << "\n" << std::endl;
    }
    std::cout << it->first << std::endl;
  }
}
void displayAllData(std::string fileName)
{
  AVLtree<std::string> Text; std::map<std::string, int> map;
  double totalSentence; double CharacterWordCount; double SentenceLength;
  totalSentence = totalSentences(fileName);
  inputTree(fileName, Text); std::cout << "Analyzing " << fileName << "...\n" << std::endl;
  map = Text.getAllWord();
  CharacterWordCount = (double)Text.getTotalCharacter() / (double)Text.getTotalWords();
  SentenceLength = (double)Text.getTotalWords() / totalSentence;
  std::cout << "***STATISTICS***" << std::endl;
  std::cout << "TOTAL NUMBER OF WORDS: " << Text.getTotalWords() << std::endl;
  std::cout << "TOTAL NUMBER OF 'UNIQUE' WORDS: " << Text.getUniqueWords() << std::endl;
  std::cout << "TOTAL NUMBER OF 'UNIQUE' WORDS OF MORE THAN THREE LETTERS: " << Text.getUniqueWordsThreeLetterMore() << std::endl;
  std::cout << "AVERAGE WORD LENGTH: " << setprecision(3) << CharacterWordCount << std::endl;
  std::cout << "AVERAGE SENTENCE LENGTH: " << setprecision(3) << SentenceLength;
  std::cout << "\n\n";
  std::cout << "***STYLE WARNINGS***" << std::endl;
  displayWordUsedOften(map, Text.getTotalWords());
  checkSentenceLength(SentenceLength);
  checkWordCount(CharacterWordCount);
  std::cout << "\n\n";
  std::cout << "***INDEX OF UNIQUE WORDS***" << std::endl;
  displayUniqueWords(map);
  std::cin.ignore();
  cout << "Press Enter to Continue...\n";
  std::cin.get();
}
int printmenu()
{
  int x;
  std::cout << "1: Insert A File"; 
  std::cout << "\n2: Process the File"; 
  std::cout << "\n3: Exit the program";
  std::cout << "\nChoice: ";
  std::cin >> x;
  return x;
}
int main()
{
  int choice = 0;
  std::string fileName;
  choice = printmenu();
  while (choice != 3)
  {
    switch (choice)
    {
    case 1: system("CLS"); fileName = insertFile(); break;
    case 2: system("CLS"); displayAllData(fileName); break;
    default: system("CLS");  std::cout << "Enter a valid choice. \n";
    }
    system("CLS"); choice = printmenu();
  }
}
