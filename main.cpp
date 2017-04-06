#include <string>
#include <iostream>
#include <ResultBase.h>


//Example 1. Partial template specialization for any code, but messages - std::string
template<typename CodeT, CodeT OkCode>
using StdStringResult = ResultBase<CodeT, OkCode, std::string>;

//------------------------------------------------------------------------
//Example 2. Default result codes
enum class ResCodes : std::uint8_t
{
    Ok = 0,
    Info,
    Warning,
    Error,
    FatalError
};

//define for default codes + std::string messages
using DefaultResult = StdStringResult<ResCodes, ResCodes::Ok>;

//------------------------------------------------------------------------
//Example 3. HTML codes
enum class HTMLCodes : std::uint16_t
{
    Ok         = 200,
    Accepted   = 202,
    BadRequest = 400,
    Forbidden  = 403,
    NotFound   = 404,
    ServiceUnavailable = 503
};

//define for html codes + std::string messages (full scep)
using HTMLResporse = ResultBase<HTMLCodes, HTMLCodes::Ok, std::string>;


const int t_ok = 100;
const int t_err = 101;
const int t_fatal = 200;

using IntResporse = ResultBase<int, t_ok, std::string>;


//------------------------------------------------------------------------
//------------------------------------------------------------------------

int main(int argc, char *argv[])
{

    //Ex 2. Default result
    DefaultResult ok{ResCodes::Ok};
    DefaultResult error{ResCodes::Error, "Big badaboom!!!"};

    std::cout << "DEFAULT codes." << std::endl
              << " Ok value: " << static_cast<int>(ok.code()) << std::endl
              << " Err value: " << static_cast<int>(error.code()) << " Message: " << error.descr() << std::endl
              << " Err result is OK? " << (error == ResCodes::Ok ? "Yes" : "No") << std::endl
              << " Ok result is OK? " << (ok == ResCodes::Ok ? "Yes" : "No")
              << std::endl;


    //Ex 3. HTML Code

    //Won't compile - different codes
    //HTMLResporse ok{ResCodes::Ok};


    HTMLResporse resp_ok{HTMLCodes::Ok};
    HTMLResporse notFound{HTMLCodes::NotFound, "Page Not Found!!!"};

    //Won't compile - different codes
    //bool q = resp_ok == ok;

    std::cout << "HTML codes." << std::endl
              << " Ok value: " << static_cast<int>(resp_ok.code()) << std::endl
              << " NF value: " << static_cast<int>(notFound.code()) << " Message: " << notFound.descr() << std::endl
              << " NotFound is OK? " << (notFound == HTMLCodes::Ok ? "Yes" : "No") << std::endl
              << " Ok result is OK? " << (resp_ok == HTMLCodes::Ok ? "Yes" : "No")
              << std::endl;
    //


    return 0;
}
