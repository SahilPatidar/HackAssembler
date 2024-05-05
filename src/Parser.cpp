#include<iostream>
#include<vector>
#include<algorithm>
#include"../include/Parser.hpp"
#include"../include/SymbolTable.hpp"

namespace hack{

// bool Parser::advance(uint64_t &InstAddr) {
//     while(hasMoreCmd) {
//         size_t endline = src.find("\n", idx);
//         Cmd = src.substr(idx, endline-1);
//         size_t cmmtline = Cmd.find("//");
//         if(cmmtline != std::string::npos) {
//             Cmd.erase(cmmtline, endline);
//         }
//         Cmd.erase(std::remove_if(src.begin(), src.end(), ::isspace), src.end());
//     }
//     return false;
// }


std::string Parser::getSymbol(std::string &Cmd) {
    size_t lpos = Cmd.find("(");
    size_t rpos = Cmd.find(")");
    if(rpos != std::string::npos) {
        return Cmd.substr(lpos+1, rpos - lpos - 1);
    }
    return "";
}


std::string Parser::getVal(std::string &Cmd){
    if(Cmd[0] == '@')
        return Cmd.substr(1, Cmd.length() - 1);
    return "";
}


std::string Parser::ParseCmp(std::string &Cmd) {
    size_t sz = Cmd.size();
    size_t eqpos = Cmd.find("=");
    size_t scolpos = Cmd.find(";");
    if(eqpos != std::string::npos) {
        if(scolpos != std::string::npos) {
            return Cmd.substr(eqpos + 1, scolpos - eqpos - 1);
        }
        return Cmd.substr(eqpos + 1,  Cmd.length() - eqpos - 1);
    }
    if(scolpos != std::string::npos) {
            return Cmd.substr(0, scolpos);
    }

    return "";
}

std::string Parser::ParseDest(std::string &Cmd) {
    size_t eqpos = Cmd.find("=");
    if(eqpos != std::string::npos) {
        return Cmd.substr(0, eqpos);
    }

    return "";
}

std::string Parser::ParseJmp(std::string &Cmd) {
    size_t sz = Cmd.size();
    size_t scolpos = Cmd.find(";");
    if(scolpos != std::string::npos) {
        return Cmd.substr(scolpos + 1, Cmd.length() - scolpos - 1);
    }

    return "";
}
}
