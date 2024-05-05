#pragma once
#include<iostream>
#include<map>

namespace hack{

class LookUp{
private:
    std::map<std::string, int>vals;
public:
    LookUp() {
        vals.insert({"R0",0});
        vals.insert({"R1",1});
        vals.insert({"R2",2});
        vals.insert({"R3",3});
        vals.insert({"R4",4});
        vals.insert({"R5",5});
        vals.insert({"R6",6});
        vals.insert({"R7",7});
        vals.insert({"R8",8});
        vals.insert({"R9",9});
        vals.insert({"R10",10});
        vals.insert({"R11",11});
        vals.insert({"R12",12});
        vals.insert({"R13",13});
        vals.insert({"R14",14});
        vals.insert({"R15",15});
        vals.insert({"SCREEN", 16384});
        vals.insert({"KEYBOARD", 24576});
        vals.insert({"KBD", 24576});
        vals.insert({"SP", 0});
        vals.insert({"LCL", 1});
        vals.insert({"ARG", 2});
        vals.insert({"THIS", 3});
        vals.insert({"THAT", 4});
    }
    ~LookUp() {}

    inline int64_t operator [](std::string s) noexcept {
        return vals.find(s) == vals.end()? 0: vals[s];
    }

    inline bool Has(std::string s) noexcept {
        return vals.find(s) != vals.end();
    }

    inline void put(std::string s, int64_t val) noexcept {
        vals.insert({s, val});
    }

    inline void drop(std::string &s) noexcept {
        vals.erase(s);
    }
};

}