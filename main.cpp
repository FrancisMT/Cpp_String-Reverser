#include<iostream>
#include<string>
#include<algorithm>

namespace StringUtils {

    void StringReverserA(std::string &InString) {
       
        std::reverse(begin(InString), end(InString));
    }

    void StringReverserB(std::string &InString) {

        uint8_t 
            MiddleIndex = InString.size() / 2,
            MaxIndex = InString.size() - 1;

        for(uint8_t StrIndex = 0; StrIndex < MiddleIndex ; ++StrIndex){
            std::swap(InString[StrIndex], InString[MaxIndex - StrIndex]);
        }
    }

    void StringReverserC(std::string &InString) {
        
        std::string TempStr = "";

        for(int8_t StrIndex = InString.size() -1 ; StrIndex >= 0 ; --StrIndex){
            TempStr.push_back(InString[StrIndex]);
        }

        std::swap(InString, TempStr);
    }

    void StringCaseReverser(std::string &InString) {

        std::transform(std::begin(InString), std::end(InString), std::begin(InString), 
        [](char StrChr){
            return std::islower(StrChr) ? std::toupper(StrChr) : std::tolower(StrChr);
        });   
    }
}

int main() {
    
    std::string TestString = "This test string shall be reversed";
    std::cout << TestString << std::endl;

    StringUtils::StringReverserA(TestString);
    std::cout << TestString << std::endl;

    StringUtils::StringReverserB(TestString);
    std::cout << TestString << std::endl;
    
    StringUtils::StringReverserC(TestString);
    std::cout << TestString << std::endl;
    
    StringUtils::StringCaseReverser(TestString);
    std::cout << TestString << std::endl;

    return 0;
}