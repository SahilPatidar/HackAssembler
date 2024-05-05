#include<iostream>
#include<vector>
#include<fstream>
#include"../include/Parser.hpp"
#include"../include/SymbolTable.hpp"
#include"../include/Translator.hpp"
#include"../include/Cmd.hpp"

using namespace hack;

bool get_src(char *file_path, std::string &src) {   
    char buffer[256];
    FILE* file;
    file = fopen(file_path, "r");
    if(file == NULL) {
        fprintf(stderr, "Error: unable to open file: %s\n", file_path);
        return false;
    }
    while(fgets(buffer, sizeof(buffer), file) != NULL) {
        src += buffer;
    }
    
    ///@todo line count

    fclose(file);
    if(src.empty()){
        fprintf(stderr, "Error: encountered empty file: %s\n", file_path);
        return false;
    };
    return true;
}

std::string getBin(int16_t val) {
    std::string bit = "";
    for(ssize_t i = 15; i >= 0; i--) {
        bit.push_back(((val>>i)&1)?'1':'0');
    }
    return bit;
}
int main(int argc, char **argv) {
    if(argc < 2){
        std::cout<<"too few args"<<std::endl;
        return 0;
    }

    std::string src = "";
    if(!get_src(argv[1], src)){
        std::cout<<"unable open file"<<std::endl;
        return 0;
    }
    // std::string despath = "";
    // if(argc == 1) {
    //     std::string path = argv[0];
    //     despath = path.substr(0, path.find_last_of("/"));
    //     despath.append("hack.bin");
    // }else {
    //     despath = argv[1];
    // }
    // std::ofstream of;
    // of.open(despath, std::fstream::out);

    InstrHandler cmdSource(src); 
    Translator T;
    LookUp L;
    Parser P;
    int InstrAddr = 0;
    while (cmdSource.HasMoreCmd())
    {
        cmdSource.advance();
        if(cmdSource.Instr().empty()) {
            break;
        }
        if(cmdSource.cmdType() == 'A' || cmdSource.cmdType() == 'C') {
            InstrAddr++;
        }
        if(cmdSource.cmdType() == 'L')  {
            std::cout<<P.getSymbol(cmdSource.Instr())<<" "<<InstrAddr<<std::endl;
            L.put(P.getSymbol(cmdSource.Instr()), InstrAddr);
        }
    }
    
    cmdSource.reset();
    int addr = 16;

    std::ofstream of("bin.hack", std::fstream::out);
    while (cmdSource.HasMoreCmd())
    {

        cmdSource.advance();
        if(cmdSource.Instr().empty()) {
            break;
        }
        if(cmdSource.cmdType() == 'A')  {
            of << '0';
            std::string Val = P.getVal(cmdSource.Instr());
            if(Val.find_first_not_of("0123456789") == std::string::npos) {
                of << getBin(std::stoull(Val));
            }else {
                if(!L.Has(Val)) {
                    L.put(Val, addr++);
                }
                of << getBin(L[Val]);
            }
            of << std::endl;
        }else if(cmdSource.cmdType() == 'C') {
            of << "111";
            of << T.get_cmp(P.ParseCmp(cmdSource.Instr()));
            of << T.get_dest(P.ParseDest(cmdSource.Instr()));
            of << T.get_jmp(P.ParseJmp(cmdSource.Instr()));
            of << std::endl;
        }
        // instr += '\n';
    }

    of.close();
    return 0;
}