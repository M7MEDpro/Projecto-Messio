#include "server.h"
#include "dataModel.h"
#include "nlohmann/json.hpp"
#include "httplib.h"

namespace httplib {

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
                        j[";2"] = esp2::l2;
                        j["l3"] = esp2::l3;
                        j["l4"] = esp2::l4;


                        res.set_content(j.dump(), "application/json");
        });
    }

    void registerMobile(httplib::Server& svr) {
        svr.Post("/mobile", [](const httplib::Request& req, httplib::Response& res) {
        });

        svr.Get("/mobile", [](const httplib::Request&, httplib::Response& res) {
        });
    }

    void startServer() {
        httplib::Server svr;

        // Register all endpoints
        registerESP1(svr);
        registerESP2(svr);
        registerMobile(svr);

        std::cout << "Server listening on port 5001..." << std::endl;
        svr.listen("0.0.0.0", 5001);
    }

}
