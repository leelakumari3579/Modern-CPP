#include "Request.hpp"

std::ostream &operator<<(std::ostream &os, const Request &rhs)
{
    os << "_apiEndPointUrl: " << rhs._apiEndPointUrl
       << " _curlSession: " << rhs._curlSession;
    return os;
}

Request::Request(std::string url)
    : _apiEndPointUrl{url},_curlSession{ curl_easy_init(),_curl_easy_cleanup }
{
    _curlSession = std::shared_ptr<CURL>{nullptr};

    /*
        decide logic for writing data
        saving this as a lambda function
        [BUG!!]
    */
    auto fn = [](void *ptr, size_t size, size_t nmemb, std::string *data) -> size_t
    {
        data->append((char *)ptr, size * nmemb);
        return size * nmemb;
    };
    // how will i save returning in my program's memory
    // pass pointer to a function that contains this logic
    // write functions is used here!

    curl_easy_setopt(
        _curlSession.get(),
        CURLOPT_WRITEFUNCTION,
        +fn);

    // option for URL
    curl_easy_setopt(_curlSession.get(), CURLOPT_URL, "https://api.github.com/repos/whoshuu/cpr/contributors?anon=true&key=value");
    // url part mapping is here!
    curl_easy_getinfo(_curlSession.get(), CURLINFO_EFFECTIVE_URL, &_apiEndPointUrl);
}

std::shared_ptr<Response> Request::ExecuteApiCall()
{
    std::shared_ptr<Response> resPtr = std::make_shared<Response>();

    // option to pass pointer to the response variable
    curl_easy_setopt(
        _curlSession.get(),
        CURLOPT_WRITEDATA,
        &resPtr->_responseString);

    // now use these commands to map above variable
    curl_easy_getinfo(_curlSession.get(), CURLINFO_RESPONSE_CODE, &resPtr->_responseStatusCode);
    curl_easy_getinfo(_curlSession.get(), CURLINFO_TOTAL_TIME, &resPtr->_resposeTimeElapsed);
}
