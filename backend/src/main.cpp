#include "httplib.h"
#include <iostream>

int main() {
    httplib::Server svr;

    svr.set_mount_point("/", "../frontend"); // Sets / to read files from the frontend directory

    std::cout << "Listening on port 8080... \n";
    svr.listen("0.0.0.0", 8080);
}