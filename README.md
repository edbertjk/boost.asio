## Learn Async I/O In Boost.asio
Playlist: https://youtube.com/playlist?list=PLIXt8mu2KcUJOwdLMp-Z-cDIZA1aZfVTN&si=unaE3OKu3iTsy0Rq


## Installation
1. Install Boost.asio use sudo apt-get install libboost-all-dev
2. Add Boost.asio into c_cpp_project "includePath": [ "/usr/include/boost" ],
3. Import Boost.asio into your project #include <boost/asio.hpp> & using namespace boost;
4. Compile and run the project (g++ -o ./build/a.out main.cpp -I/usr/include/boost -lboost_system)