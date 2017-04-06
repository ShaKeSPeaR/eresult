# EResult

Contain base templated ResultBase class for operation results.
Class have full stack for operators + operators for equality check and conversions.

## Requirement 

 - c++ compiler with c++11/c++14 

## Usage

Just copy *ResultBase.h* to your project and specialise with code and string types.


## Simple example

**Step 1** : Describe you codes

    enum class HTMLCodes
    {
        Ok = 200,
        NotFound = 404
    }

**Step 2** : Make result type with your codes and strings type

    using HTMLResporse = ResultBase<HTMLCodes, HTMLCodes::Ok, std::string>
   
**Step 3** : Use it!

    HTMLResporse result{HTMLCodes::NotFound, "Page Not Found!!!"};
    std::cout << " Is all OK? " 
              << (result == HTMLCodes::Ok ? "Yes" : "No") 
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