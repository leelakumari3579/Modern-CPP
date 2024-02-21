#include <curl/curl.h>
#include <string>

size_t writeFunction(void *ptr, size_t size, size_t nmemb, std::string* data) {
    data->append((char*) ptr, size * nmemb);
    return size * nmemb;
}

int main(int argc, char** argv) {

    //step1: intialize the session object
    auto curl = curl_easy_init();

    //step2: if session object is NOT NULL!
    if (curl) {

        //option for URL
        curl_easy_setopt(curl, CURLOPT_URL, "https://api.github.com/repos/whoshuu/cpr/contributors?anon=true&key=value");

        //string where returning data will be stored
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L);

        //while making a request, if any extra item needs
        //
        curl_easy_setopt(curl, CURLOPT_USERPWD, "user:pass");
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "curl/7.42.0");
        curl_easy_setopt(curl, CURLOPT_MAXREDIRS, 50L);
        curl_easy_setopt(curl, CURLOPT_TCP_KEEPALIVE, 1L);
        
        std::string response_string;
        std::string header_string;
        
        //how will i save returning in my program's memory
        //pass pointer to a function that contains this logic
        //write functions is used here!

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeFunction);

        //option to pass pointer to the response variable
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_string);
        
        //options to pass pointer to the header variable
        curl_easy_setopt(curl, CURLOPT_HEADERDATA, &header_string);
        
        char* url; //use this curl to fetch data!
        long response_code; //use this variable store API response code
        double elapsed; //time taken to complete the request

        //now use these commands to map above variable

        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
        curl_easy_getinfo(curl, CURLINFO_TOTAL_TIME, &elapsed);
        curl_easy_getinfo(curl, CURLINFO_EFFECTIVE_URL, &url);
        
        //finally execute the API call
        curl_easy_perform(curl);
        //end the session 
        curl_easy_cleanup(curl);
        //set the pointer to NULL to inticate end of process!
        curl = NULL;
    }
}

//RAII: RESOURCE ACQUISITION IS INTIALIZATION 
/*
    Database managing code
    i want to connect to a databse. execute a query
    password and database url, port number
    class DataConnector
    {
        DataConnector
        {
            //code for connection to database goes here!
        }
        ~DataConnector
        {
            //code for deallocating the database conncetion/session terminate
        }
    }
*/