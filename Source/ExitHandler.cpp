#include "Include/Server.hpp"
#include "Include/ExitHandler.hpp"



bool ExitHandler::handleGet(CivetServer *server, struct mg_connection *connection) {
    mg_printf(connection, "<p>Exiting</p>");


    exitNow = true;

    return true;
}