#include "server.h"
#include "dataModel.h"
#include "nlohmann/json.hpp"
#include "httplib.h"

namespace server {

    void registerESP1(httplib::Server& svr) {
        svr.Post("/esp1", [](const httplib::Request& req, httplib::Response& res) {
            try {
                auto receivedJson = nlohmann::json::parse(req.body);
                for (auto& [key, val] : receivedJson["esp1"].items()) {
                    if (key == "LDR0") esp1::LDR0 = val.get<int>();
                    else if (key == "LDR1") esp1::LDR1 = val.get<int>();
                    else if (key == "M0") esp1::M0 = val.get<int>();
                    else if (key == "M1") esp1::M1 = val.get<int>();
                    else if (key == "M2") esp1::M2 = val.get<int>();
                    else if (key == "M3") esp1::M3 = val.get<int>();
                    else if (key == "M4") esp1::M4 = val.get<int>();
                    else std::cout << "Unknown key: " << key << std::endl;
                }
                res.set_content("ESP1 data received", "text/plain");
            } catch (const std::exception& e) {
                res.status = 400;
                res.set_content(std::string("Error parsing JSON: ") + e.what(), "text/plain");
            }
        });

        svr.Get("/esp1", [](const httplib::Request&, httplib::Response& res) {
            nlohmann::json j;
            j["g1"] = esp1::g1;
            j["r1"] = esp1::r1;
            j["r2"] = esp1::r2;
            j["r3"] = esp1::r3;
            j["r4"] = esp1::r4;
            j["buzz"] = esp1::buzz;
            j["servo"] = esp1::servo;

            res.set_content(j.dump(), "application/json");
        });
    }

    void registerESP2(httplib::Server& svr) {
        svr.Post("/esp2", [](const httplib::Request& req, httplib::Response& res) {
            try {
                           auto receivedJson = nlohmann::json::parse(req.body);
                           for (auto& [key, val] : receivedJson["esp2"].items()) {
                               if (key == "F1") esp2::F1 = val.get<int>();
                               else if (key == "F2") esp2::F2 = val.get<int>();
                               else if (key == "F3") esp2::F3 = val.get<int>();
                               else if (key == "F4") esp2::F4 = val.get<int>();
                               else if (key == "F5") esp2::F5 = val.get<int>();


                               else std::cout << "Unknown key: " << key << std::endl;
                           }
                           res.set_content("esp2 data received", "text/plain");
                       } catch (const std::exception& e) {
                           res.status = 400;
                           res.set_content(std::string("Error parsing JSON: ") + e.what(), "text/plain");
                       }

        });

        svr.Get("/esp2", [](const httplib::Request&, httplib::Response& res) {
            nlohmann::json j;
                        j["OL"] = esp2::OL;
                        j["l1"] = esp2::l1;
                        j["l2"] = esp2::l2;
                        j["l3"] = esp2::l3;
                        j["l4"] = esp2::l4;
                        j["mg"] = esp2::mg;

                        res.set_content(j.dump(), "application/json");
        });
    }

    void registerMobile(httplib::Server& svr) {
        svr.Post("/mobile", [](const httplib::Request& req, httplib::Response& res) {
            try {
                auto receivedJson = nlohmann::json::parse(req.body);
                for (auto& [key, val] : receivedJson["mobile"].items()) {
                    if (key == "LDR0") esp1::LDR0 = val.get<int>();
                    //home modes
                    else if (key == "homeAway") mobile_app::homeAway = val.get<bool>();
                    else if (key == "bedTimeMode") mobile_app::bedTimeMode = val.get<bool>();
                    else if (key == "powerSavingMode") mobile_app::powerSavingMode = val.get<bool>();
                    else if (key == "EmergencyMode") mobile_app::EmergencyMode = val.get<bool>();
                    //room1
                    else if (key == "brightnessRoom1")mobile_app::room1::brightness= val.get<int>();
                    else if (key == "modeRoom1") mobile_app::room1::mode = val.get<int>();
                    else if (key == "ldrRoom1") mobile_app::room1::ldr = val.get<bool>();
                    else if (key == "irRoom1") mobile_app::room1::ir = val.get<bool>();
                    else if (key == "alarmModeRoom1") mobile_app::room1::alarmMode = val.get<bool>();
                    //room2
                    else if (key == "brightnessRoom2") mobile_app::room2::brightness = val.get<int>();
                    else if (key == "modeRoom2") mobile_app::room2::mode = val.get<int>();
                    else if (key == "ldrRoom2") mobile_app::room2::ldr = val.get<bool>();
                    else if (key == "irRoom2") mobile_app::room2::ir = val.get<bool>();
                    else if (key == "alarmModeRoom2") mobile_app::room2::alarmMode = val.get<bool>();
                    //reception
                    else if (key == "brightnessReception") mobile_app::reception::brightness = val.get<int>();
                    else if (key == "modeReception") mobile_app::reception::mode = val.get<int>();
                    else if (key == "ldrReception") mobile_app::reception::ldr = val.get<bool>();
                    else if (key == "irReception") mobile_app::reception::ir = val.get<bool>();
                    else if (key == "alarmModeReception") mobile_app::reception::alarmMode = val.get<bool>();
                    //garage
                    else if (key == "brightnessGarage") mobile_app::garage::brightness = val.get<int>();
                    else if (key == "modeGarage") mobile_app::garage::mode = val.get<int>();
                    else if (key == "ldrGarage") mobile_app::garage::ldr = val.get<bool>();
                    else if (key == "irGarage") mobile_app::garage::ir = val.get<bool>();
                    else if (key == "alarmModeGarage") mobile_app::garage::alarmMode = val.get<bool>();
                    //outerLed
                    else if (key == "brightnessOuterLed") mobile_app::outerLed::brightness = val.get<int>();
                    else if (key == "modeOuterLed") mobile_app::outerLed::mode = val.get<int>();
                    else if (key == "ldrOuterLed") mobile_app::outerLed::ldr = val.get<bool>();
                    //doors
                    else if (key == "mainDoor") esp1 ::servo= val.get<bool>();
                    else if (key == "garageDoor") esp2 ::mg = val.get<bool>();

                    else std::cout << "Unknown key: " << key << std::endl;
                }
            }catch (const std::exception& e) {
                           res.status = 400;
                           res.set_content(std::string("Error parsing JSON: ") + e.what(), "text/plain");
                       }

        });
        svr.Get("/mobile", [](const httplib::Request&, httplib::Response& res) {
            nlohmann::json j;
            j["AlarmStatues"] = esp1::buzz;


            res.set_content(j.dump(), "application/json");

        });
    }

    void startServer() {
        httplib::Server svr;

        // Register all endpoints
        registerESP1(svr);
        registerESP2(svr);
        registerMobile(svr);

        std::cout << "Server listening on port 5001..." << std::endl;
        svr.listen("192.168.1.200", 5001);
    }

}
