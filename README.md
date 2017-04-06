# EResult

Repository contains template class ResultBase for operations results. 
Class has full set of operators + operators for equality check and conversions.


## Requirement 

 - c++ compiler with c++11/c++14 

## Usage

Just copy *ResultBase.h* to your project and specialise with codes and string types.


## Simple example

**Step 1** : Describe you codes

    enum class HTTPCodes
    {
        Ok = 200,
        NotFound = 404
    }

**Step 2** : Make result type with your codes and strings type

    using HTTPResponse = ResultBase<HTTPCodes, HTTPCodes::Ok, std::string>
   
**Step 3** : Use it!

    HTTPResponse result{HTTPCodes::NotFound, "Page Not Found!!!"};
    std::cout << " Is all OK? " 
              << (result == HTTPCodes::Ok ? "Yes" : "No") 
              << std::endl
    
*Full examples and HowTo in main.cpp*

## Compile and run other examples 


### Requirement (for examples)

 - c++ compiler with c++11/c++14 
 - cmake 3.4 and greather
 
### Usage
 
 - compile main.cpp with cmake
 - run eresult
 
You may change main.cpp as you like for plaing with ResultBase