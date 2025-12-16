#ifndef SERVER_H
#define SERVER_H


#include "httplib.h"
namespace server {

     
    void registerESP1(httplib::Server& svr);

     
    void registerESP2(httplib::Server& svr);

     
    void registerMobile(httplib::Server& svr);

     
    void startServer();

}
#endif
