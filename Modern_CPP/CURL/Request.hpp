#ifndef REQUEST_HPP
#define REQUEST_HPP

#include <string>
#include <curl/curl.h>
#include <ostream>
#include <memory>
#include "Response.hpp"

class Request final //this class cannot be used as "parent" for inheritance
{
private:
    std::string _apiEndPointUrl;
    std::shared_ptr<CURL> _curlSession;
public:
    Request() = delete;
    Request(const Request&) = delete;
    Request(Request&&) = delete;
    Request& operator=(const Request&) = delete;
    Request& operator=(Request&&) = delete;    
    ~Request() = default;

    std::string apiEndPointUrl() const { return _apiEndPointUrl; }
    //setter might be useful to reuse one request object for subsequent API calls!
    void setApiEndPointUrl(const std::string &apiEndPointUrl) { _apiEndPointUrl = apiEndPointUrl; }

    explicit Request(std::string url);

    friend std::ostream &operator<<(std::ostream &os, const Request &rhs);

    /*
        this will help in diplaying the request object for debugging and logging pupose
    */
    std::shared_ptr<Response> ExecuteApiCall();
};

#endif // REQUEST_HPP
