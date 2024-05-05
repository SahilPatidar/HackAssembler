#pragma once
#include<iostream>
#include<map>
#include<fstream>
namespace hack{

class Parser{
// private:
//     int64_t idx{0};
//     std::string src;
//     std::string Cmd;
//     std::map<char, char>CmdTy;
public:
    Parser() {} 
    ~Parser() {} 
    // char CmdType() {  }

    // bool hasMoreCmd() { return idx == src.size(); }

    // bool advance(uint64_t &InstAddr);

    std::string ParseCmp(std::string &Cmd);

    std::string ParseJmp(std::string &Cmd);

    std::string ParseDest(std::string &Cmd);

    std::string getSymbol(std::string &Cmd);

    std::string getVal(std::string &Cmd);
};

}