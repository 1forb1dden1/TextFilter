#include "AVL.cpp"
#include <fstream>
#include <stdio.h>

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
int main()
{
  AVLtree<std::string> Text;
  std::string fileName = "SampleFile.txt";
  double totalSentence = totalSentences(fileName);
  inputTree(fileName, Text);
  std::cout << "Analyzing " << fileName << "...\n" << std::endl;
  double avg = (double)Text.getTotalCharacter() / (double)Text.getTotalWords();
  std::cout << "***STATISTICS***" << std::endl;
  std::cout << "TOTAL NUMBER OF WORDS: " << Text.getTotalWords() << std::endl;
  std::cout << "TOTAL NUMBER OF 'UNIQUE' WORDS: " << Text.getUniqueWords() << std::endl;
  std::cout << "TOTAL NUMBER OF 'UNIQUE' WORDS OF MORE THAN THREE LETTERS: " << Text.getUniqueWordsThreeLetterMore() << std::endl;
  std::cout << "AVERAGE WORD LENGTH: " << setprecision(3) << avg << std::endl;
  std::cout << "AVERAGE SENTENCE LENGTH: " << setprecision(3) << (double)Text.getTotalWords()/totalSentence;
  std::cout << "\n\n\n";
  //Text.print();
  return 0;
}
