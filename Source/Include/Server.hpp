#pragma once





#include "../CivetWeb/CivetServer.h"
#include <string>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#include "Configuration.hpp"





#define PRODUCT_REPOSITORY "https://www.blobwob.com"
#define OK_HEADER "HTTP/1.1 200 OK\r\n" \
                  "Server: Fubuki\r\n" \
                  "Content-Type: text/html; charset=utf-8\r\n" \
                  "Content-Length: %zu\r\n" \
                  "\r\n"
#define EMPTY_STRING_LENGTH 0


#define STRLEN_OFFSET 1
#define STRINGS_EQUAL 0


#define SQLITE_READ_UP_TO_NULL_TERMINATOR (-1)
#define SQLITE_PREPARED_STATEMENT_PARAMETER_NOT_IMPORTANT 0


#define MG_GET_VAR_VARIABLE_NOT_FOUND (-1)
#define MG_GET_VAR_DESTINATION_BUFFER_TOO_SMALL (-2)

static const unsigned int CIVIT_WEB_INIT_BITMASK = MG_FEATURES_FILES |
                                                   MG_FEATURES_IPV6 |
                                                   MG_FEATURES_SSL |
                                                   MG_FEATURES_WEBSOCKET;





extern volatile bool exitNow;