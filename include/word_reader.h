#ifndef WORD_READER_H
#define WORD_READER_H

#include <fstream>
#include "static_list_template.h"
#include "static_list_template.impl.h"

namespace de{

typedef struct WordReader{
    std::ifstream input;
}WordReader;

 WordReader createReader(const std::string& inputFile);
 List<std::string> getWords(const WordReader& reader);
     
}
#endif//WORD_READER
