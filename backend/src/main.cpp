#include <httplib.h>
#include <nlohmann/json.hpp>
#include <string>
#include <vector>

using json = nlohmann::json;

int main() {
    httplib::Server server;

    server.Get("/", [](const httplib::Request&, httplib::Response& res) {
        json body;
        body["service"] = "mini-soc";
        body["status"] = "ok";
        body["endpoints"] = {"/api/status", "/api/events"};

        res.set_content(body.dump(), "application/json");
    });

    server.Get("/api/status", [](const httplib::Request&, httplib::Response& res) {
        json body;
        body["service"] = "mini-soc";
        body["status"] = "ok";
        body["message"] = "C++ backend is running";

        res.set_content(body.dump(), "application/json");
    });

    server.Get("/api/events", [](const httplib::Request&, httplib::Response& res) {
        json events = json::array();

        json event1;
        event1["id"] = 1;
        event1["severity"] = "low";
        event1["source"] = "demo";
        event1["message"] = "Test security event";

        json event2;
        event2["id"] = 2;
        event2["severity"] = "high";
        event2["source"] = "auth";
        event2["message"] = "Multiple failed login attempts detected";

        events.push_back(event1);
        events.push_back(event2);

        json body;
        body["events"] = events;

        res.set_content(body.dump(), "application/json");
    });

    server.listen("127.0.0.1", 8081);

    return 0;
}