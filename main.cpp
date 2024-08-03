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

vector<char> vBuffer(20 * 1024);

void grabSomeData(asio::ip::tcp::socket& socket) {
    socket.async_read_some(asio::buffer(vBuffer.data(), vBuffer.size()),
        [&](std::error_code ec, std::size_t length) {
            if (!ec) {
                cout << "\n\nRead " << length << " bytes\n\n";
                for (int i = 0; i < length; i++) {
                    cout << vBuffer[i];
                }
                grabSomeData(socket);
            }
        });
}

int main() {
    //create a context for asio
    asio::io_context io_context; 

    //create a fake work if theres nothing to do
    asio::io_context::work idleWork(io_context);

    //create a thread to run the context in the background
    thread thrContext = thread([&]() { io_context.run(); });

    //create a handler for the error code
    system::error_code ec;

    //create a endpoint/target
    asio::ip::tcp::endpoint endPoint(asio::ip::address::from_string("109.110.188.5", ec), 80);

    //create a socket
    asio::ip::tcp::socket socket(io_context);

    //connect the socket
    socket.connect(endPoint, ec);

    if (ec) {
        std::cout << "Error code: " << ec.value() << " Message: " << ec.message() << std::endl;
    }
    else {
        std::cout << "Connected!" << std::endl;
    }

    //check if the socket is open
    if(socket.is_open()) {

        grabSomeData(socket);

        //send data
        std::string sRequest = "GET / HTTP/1.1\r\n"
            "Host: example.com\r\n"
            "Connection: close\r\n\r\n";

        socket.write_some(asio::buffer(sRequest.data(), sRequest.size()), ec);

        using namespace std::chrono_literals;
        std::this_thread::sleep_for(20000ms);

        io_context.stop();
        if (thrContext.joinable()) thrContext.join();

    }

    std::system("pause");
    return 0;
}