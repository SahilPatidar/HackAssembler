#pragma once
#include<iostream>
#include<map>
#include<fstream>

namespace hack {
class InstrHandler{
private:
    std::string src;
    std::string Cmd;
    int idx{0};
    std::map<char, char>CmdTy;
public:
    InstrHandler(std::string &_src)
    :src(_src) {
        CmdTy.insert({'@', 'A'});
        CmdTy.insert({'(', 'L'});
        CmdTy.insert({'M', 'C'});
        CmdTy.insert({'D', 'C'});
        CmdTy.insert({'A', 'C'});
        CmdTy.insert({'!', 'C'});
        CmdTy.insert({'0', 'C'});
    }
    ~InstrHandler(){}

    inline std::string &Instr() { return Cmd; }

    void advance() {
        int len = src.size();
        Cmd = "";
        bool cmmt = false;
        while(idx < len) {
            if(src[idx] == '\n') {
                idx++;
                cmmt = false;
                if(Cmd.empty()) {
                    continue;
                }
                break;
            }
            if(cmmt) {
                continue;
            }
            if(isspace(src[idx])) {
                idx++;
                continue;
            }
            if(src[idx] == '/' && src[idx+1] == '/') {
                cmmt = true;
                continue;
            }
            Cmd += src[idx];
            ++idx;
        }
    }

    char cmdType() { 
        if(CmdTy.find(CmdTy[0]) != CmdTy.end()) {
            return CmdTy[Cmd[0]];
        }
    }
    bool HasMoreCmd() { return idx != src.size();}
    void reset() { idx = 0; }
};
}