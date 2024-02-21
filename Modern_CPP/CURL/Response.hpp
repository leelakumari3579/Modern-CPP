#ifndef RESPONSE_HPP
#define RESPONSE_HPP

#include <string>
#include <ostream>

class Response
{
private:
    std::string _responseString {""};
    long _responseStatusCode {-1};
    double _resposeTimeElapsed {0.0f};
public:
    Response() = default;
    Response(const Response&) = delete;
    Response(Response&&) = delete;
    Response& operator=(const Response&) = delete;
    Response& operator=(Response&&) = delete;    
    ~Response() = default;

    Response(std::string responseString, long responseCode, float responseTimeElapsed);

    std::string responseString() const { return _responseString; }

    long responseStatusCode() const { return _responseStatusCode; }

    double resposeTimeElapsed() const { return _resposeTimeElapsed; }

    friend std::ostream &operator<<(std::ostream &os, const Response &rhs);

    friend class Request;
};



#endif // RESPONSE_HPP
