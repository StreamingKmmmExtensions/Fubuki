#pragma once

#include "../CivetWeb/CivetServer.h"





#define EXIT_URI "/Commands/Exit"





class ExitHandler: public CivetHandler {
    public:
    bool handleGet(CivetServer *server, struct mg_connection *connection);

    private:

};