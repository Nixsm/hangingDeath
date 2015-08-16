#ifndef WORD_READER_H
#define WORD_READER_H

#include <fstream>
#include <string>
#include "dynamic_list_template.h"
#include "dynamic_list_template.impl.h"

namespace de{
    
    typedef struct WordReader{
        std::fstream input;
    }WordReader;

    WordReader createReader(const std::string& inputFile);
    List<List<char> > getWords(WordReader& reader);
    
}
#endif//WORD_READER
