#include <bits/stdc++.h>
#ifdef _WIN32
#define _WIN32_WINNT 0x0A00
#endif

#define ASIO_STANDALONE
#include <boost/asio.hpp>
#include <asio/ts/buffer.hpp>
#include <asio/ts/internet.hpp>
using namespace std;
using namespace boost;

int main() {
    asio::io_context io_context; 

    system::error_code ec;

    asio::ip::tcp::endpoint endPoint(asio::ip::address::from_string("109.110.188.7", ec), 80);

    asio::ip::tcp::socket socket(io_context);

    socket.connect(endPoint, ec);

    if (ec) {
        std::cout << "Error code: " << ec.value() << " Message: " << ec.message() << std::endl;
    }
    else {
        std::cout << "Connected!" << std::endl;
    }

    std::system("pause");
    return 0;
}