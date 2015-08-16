#include "word_reader.h"
#include <iostream>
#include <string>

namespace de{
    WordReader createReader(const std::string& inputFile){
        WordReader reader;
        reader.input.open(inputFile);

        return reader;
    }          
    

    List<List<char> > getWords(WordReader& reader){
        std::string line;
        List<List<char> > returnList;
        unsigned int index = 1;
        
        while(std::getline(reader.input, line)){
            List<char> templist;
            for(auto i = 0u; i < line.size(); ++i){
                templist.insert(line.at(i), i+1);
            }
            
            returnList.insert(templist, index++);
        }
        
        return returnList;
    }
}
