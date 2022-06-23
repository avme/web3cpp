#ifndef NET_H
#define NET_H

#include <future>
#include <string>
#include <cstdlib>
#include <iostream>
#include <string>

#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>

#include <web3cpp/Provider.h>
#include <web3cpp/Utils.h>
#include <web3cpp/root_certificates.h>
#include <web3cpp/Error.h>

/**
 * Namespace for making HTTP requests.
 */

namespace Net {
  /// Enum for the request types.
  enum RequestTypes { POST, GET };

  /**
   * Make an HTTP request to a given provider.
   * @param *provider The provider to send the request to.
   * @param requestType The type of network request.
   * @param reqBody The body of the request.
   * @return The response of the request as a string.
   */
  std::string HTTPRequest(
    Provider *provider, RequestTypes requestType, std::string reqBody
  );

  /**
   * Make an HTTP request to a custom target.
   * @param reqBody The body of the request.
   * @param host The host to send the request to.
   * @param port The port of the host to send the request to.
   * @param target The %RPC endpoint target of the host to send the request to.
   * @param requestType The type of network request.
   * @param contentType The type of content the request body has (e.g. "application/json").
   * @return The response of the request as a string.
   */
  std::string customHTTPRequest(
    std::string reqBody, std::string host, std::string port,
    std::string target, std::string requestType, std::string contentType
  );
}

#endif  // NET_H
