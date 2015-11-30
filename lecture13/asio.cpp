//
// sync_client.cpp
// ~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2010 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <iostream>
#include <istream>
#include <ostream>
#include <string>
#include <boost/asio.hpp>

#define PORT "3490"

using boost::asio::ip::tcp;

int main(int argc, char* argv[])
{
  if (argc != 2) {
    std::cout << "Usage: sync_client <server>\n";
    std::cout << "Example:\n";
    std::cout << "  sync_client www.boost.org /LICENSE_1_0.txt\n";
    return 1;
  }

  boost::asio::io_service io_service;
  
  // Get a list of endpoints corresponding to the server name.
  tcp::resolver resolver(io_service);
  tcp::resolver::query query(argv[1], PORT);
  tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);
  tcp::resolver::iterator end;
  
  // Try each endpoint until we successfully establish a connection.
  tcp::socket socket(io_service);
  boost::system::error_code error = boost::asio::error::host_not_found;
  while (error && endpoint_iterator != end) {
    socket.close();
    socket.connect(*endpoint_iterator++, error);
  }

  if (error)
    throw boost::system::system_error(error);
  
  // Read the response status line. The response streambuf will automatically
  // grow to accommodate the entire line. The growth may be limited by passing
  // a maximum size to the streambuf constructor.
  boost::asio::streambuf response;
  boost::asio::read_until(socket, response, "\r\n");
  std::cout << &response;

  socket.close();

  return 0;
}
