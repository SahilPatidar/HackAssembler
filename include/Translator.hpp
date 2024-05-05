#pragma once
#include<iostream>
#include<map>
namespace hack{

class Translator{
private:
    std::map<std::string, std::string>Jump;
    std::map<std::string, std::string>Dest;
    std::map<std::string, std::string>Cmp;
public:

    Translator() {
    Jump.insert({"", "000"});
    Jump.insert({"JGT", "001"});
    Jump.insert({"JEQ", "010"});
    Jump.insert({"JGE", "011"});
    Jump.insert({"JLT", "100"});
    Jump.insert({"JNE", "101"});
    Jump.insert({"JLE", "110"});
    Jump.insert({"JMP", "111"});

    Dest.insert({"", "000"});
    Dest.insert({"M", "001"});
    Dest.insert({"D", "010"});
    Dest.insert({"MD", "011"});
    Dest.insert({"A", "100"});
    Dest.insert({"AM", "101"});
    Dest.insert({"AD", "110"});
    Dest.insert({"AMD", "111"});

    Cmp.insert({"0", "0101010"});
    Cmp.insert({"1", "0111111"});
    Cmp.insert({"-1", "0111010"});
    Cmp.insert({"D", "0001100"});
    Cmp.insert({"A", "0110000"});
    Cmp.insert({"!D", "0001101"});
    Cmp.insert({"!A", "0110001"});
    Cmp.insert({"-D", "0001111"});
    Cmp.insert({"-A", "0110011"});
    Cmp.insert({"D+1", "0011111"});
    Cmp.insert({"A+1", "0110111"});
    Cmp.insert({"D-1", "0001110"});
    Cmp.insert({"A-1", "0110010"});
    Cmp.insert({"D+A", "0000010"});
    Cmp.insert({"D-A", "0010011"});
    Cmp.insert({"A-D", "0000111"});
    Cmp.insert({"D&A", "0000000"});
    Cmp.insert({"D|A", "0010101"});

    //M
    Cmp.insert({"M", "1110000"});
    Cmp.insert({"!M", "1110001"});
    Cmp.insert({"-M", "1110011"});
    Cmp.insert({"M+1", "1110111"});
    Cmp.insert({"M-1", "1110010"});
    Cmp.insert({"D+M", "1000010"});
    Cmp.insert({"D-M", "1010011"});
    Cmp.insert({"M-D", "1000111"});
    Cmp.insert({"D&M", "1000000"});
    Cmp.insert({"D|M", "1010101"});
    }

    ~Translator() {}
    
    std::string get_jmp(const std::string &s) {
        if(Jump.find(s) == Jump.end()){
            std::cout<<"invalid expression"<<std::endl;
            exit(1);
        }
        return Jump[s];
    }

    std::string get_cmp(const std::string &s) {
        if(Cmp.find(s) == Cmp.end()){
            std::cout<<"invalid expression"<<std::endl;
            exit(1);
        }
        return Cmp[s];
    }

    std::string get_dest(const std::string &s) {
        if(Dest.find(s) == Dest.end()){
            std::cout<<"invalid expression"<<std::endl;
            exit(1);
        }
        return Dest[s];
    }
};

}