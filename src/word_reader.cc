#include "include/word_reader.h"

namespace de{
    WordReader createReader(const std::string& inputFile){
        WordReader reader;
        reader.input.open(inputFile);
        return reader;
    }

    List<std::string> getWords(const WordReader& reader){
        std::string line;
        List<std::string> returnList;
        unsigned int index = 1;
        
        while(std::getline(reader.input, line)){
            returnList.insert(line, index++);
        }
    }
}
