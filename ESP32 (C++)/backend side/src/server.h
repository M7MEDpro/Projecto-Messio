#ifndef SERVER_H
#define SERVER_H


#include "httplib.h"             // HTTP server

namespace server {

    // Register POST and GET endpoints for ESP1
    void registerESP1(httplib::Server& svr);

    // Register POST and GET endpoints for ESP2
    void registerESP2(httplib::Server& svr);

    // Register POST and GET endpoints for Mobile app
    void registerMobile(httplib::Server& svr);

    // Start the HTTP server (listens on specified IP/port)
    void startServer();

} // namespace server

#endif // SERVER_H
