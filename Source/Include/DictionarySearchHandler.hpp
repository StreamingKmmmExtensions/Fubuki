#pragma once

#define DICTIONARY_SEARCH_URI "/Dictionary"
#define WORD_INDEX 1
#define XML_ROW_INDEX 2

#include "sqlite3.h"


class DictionarySearchHandler : public CivetHandler
{
public:
    bool handleGet(CivetServer *server,
                   struct mg_connection *connection);

private:
    static const std::string SEARCH_QUERY;

    static bool validateDictionaryFileName(char *fileName);
};
