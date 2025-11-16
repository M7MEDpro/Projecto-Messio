#ifndef HTTP_MANAGER_H
#define HTTP_MANAGER_H
#include <Arduino.h>
namespace http {

    void send_data(const String& key, const String& value) ;
    String read_data(const String& key);

} 

#endif 
