#include "Response.hpp"

std::ostream &operator<<(std::ostream &os, const Response &rhs) {
    os << "_responseString: " << rhs._responseString
       << " _responseStatusCode: " << rhs._responseStatusCode
       << " _resposeTimeElapsed: " << rhs._resposeTimeElapsed;
    return os;
}
Response::Response(std::string responseString, long responseCode, float responseTimeElapsed)
    :_responseString{responseString},_responseStatusCode{responseCode},_resposeTimeElapsed{responseTimeElapsed}
{
}
