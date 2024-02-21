#include <iostream>
#include "Request.hpp"

int main()
{
    //url to be used
    std::string _url = "https://api.github.com/repos/whoshuu/cpr/contributors?anon=true&key=value";

    //request object creation (on heap managed by smart pointer)
    std::shared_ptr<Request> requestPtr = std::make_shared<Request>(_url);

    //executing API call should return an object of type response
    //(created on heap managed by smart pointer)
    std::shared_ptr<Response> responsePtr = requestPtr->ExecuteApiCall();

    std::cout<<"API RETURNS\n"<<responsePtr->responseString();
    std::cout<<"API CALL STATUS CODE\n"<<responsePtr->responseStatusCode();
    std::cout<<"API CALL TIME TAKEN\n"<<responsePtr->resposeTimeElapsed();
}