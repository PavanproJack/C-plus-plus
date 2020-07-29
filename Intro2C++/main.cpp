#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>


void print(std::string statement){
    std::cout<< statement << std::endl;
}

void PrintVector(std::vector<int> vec){
    std::cout<<"{";
    for(auto i : vec){
        std::cout << i << " ";
    }
    std::cout<< "}"<< "\n";
}
    

std::vector<int> ParseLine(std::string s){
    std::istringstream newLine(s);
    size_t pos = 0;
    std::string token;
    std::string delimiter = ",";
    std::vector<int> vec;
    std::vector<int>::iterator it;
    
    it = vec.begin();
    
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        //std::cout << stoi(token);
        vec.push_back(stoi(token));
        s.erase(0, pos + delimiter.length());
    }
    //std::cout << "myvector contains:";
    //PrintVector(vec);
    
    return vec;
}

std::vector<int> parseNew(std::string l){
    std::istringstream newLine(l);
    int n;
    char c;
    std::vector<int> row;
    while(newLine >> n >> c){
        row.push_back(n);
    }
    PrintVector(row);
    return row;
}

void ReadBoardFile(std::string path){
    std::ifstream fileObj(path);
    
    if(fileObj.is_open()){
        std::string line;
        while(getline(fileObj, line)){
            //std::cout<< line << std::endl;
            ParseLine(line);
            parseNew(line);
            //std::cout << "\n";
        }
    }
}

void ReadStringStream(){
    std::string a = " P a v a 1 ";
    std::istringstream myName(a);
    char n;
    
    std::vector<char> ss = { 'p', 'a', 'v', 'a', 'n' };
    std::vector<char>::iterator iit;
    std::vector<char> ps;
    iit = ps.begin();
    while (myName >> n){
        ps.push_back(n);
        std::cout << "That stream was successful: " << n << "\n";
    }
}

void TestParseLine() {
  std::cout << "----------------------------------------------------------" << "\n";
  std::cout << "TestParseLine: ";
  std::string line = "0,1,0,0,0,0,";
  std::vector<int> solution_vect{0,1,0,0,0,0};
  std::vector<int> test_vect;
  test_vect = ParseLine(line);
  if (test_vect != solution_vect) {
    std::cout << "failed" << "\n";
    std::cout << "\n" << "Test input string: " << line << "\n";
    std::cout << "Your parsed line: ";
    PrintVector(test_vect);
    std::cout << "\n";
  } else {
    std::cout << "passed" << "\n";
  }
  std::cout << "----------------------------------------------------------" << "\n";
  return;
}

int main()
{
    std::string boardPath = "map.board";
    //ReadBoardFile(boardPath);
    //ReadStringStream();
    TestParseLine();
    
    /*std::string t = "1234";
    int i = stoi(t);
    std::cout<< i << std::endl;
    
    std::vector<int>::iterator it;
    std::vector<int> myvector;
    
    myvector.insert(it, 1, 30);
    
    std::cout << "myvector contains:";
    for (it=myvector.begin(); it<myvector.end(); it++)
      std::cout << ' ' << *it;
    std::cout << '\n';*/

    return 0;
}

 
