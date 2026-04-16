#include <iostream>
#include <string>
#include <tchar.h>

int _tmain(int argc, _TCHAR* argv[])
{
    char chAnswer;
    long long uDecNum, uTempVal;
    std::string strHexNum;
    std::cout << "Input an unsigned integer number\r\n";
    std::cin >> uDecNum;
    if (uDecNum < 0 or uDecNum > UINT32_MAX)
    {
        std::cout << "Incorrect number format\r\n";
        std::cin.ignore();
        std::cin.get();
        return 0;
    }
    std::cout << "Lower case ? (y / n) ";
    std::cin >> chAnswer;
    bool bLowerCase = (chAnswer == 'y' || chAnswer == 'Y');
    uTempVal = uDecNum;
    while (uTempVal > 0)
    {
        long long nHexDigit = uTempVal % 16;
        char chHexDigit = '\0';
        if (nHexDigit >= 0 && nHexDigit <= 9)
            chHexDigit = static_cast<char>(nHexDigit + '0');
        else if (nHexDigit >= 10 && nHexDigit <= 15 && bLowerCase)
            chHexDigit = static_cast<char>(nHexDigit - 10 + 'a');
        else if (nHexDigit >= 10 && nHexDigit <= 15)
            chHexDigit = static_cast<char>(nHexDigit - 10 + 'A');
        strHexNum = chHexDigit + strHexNum;
        uTempVal /= 16;
    }
    if (strHexNum.empty()) strHexNum = "0";
    std::cout << "The hexadecimal equivalent of the decimal number "
              << uDecNum << " is:" << strHexNum << "\r\n";
    std::cin.ignore();
    std::cin.get();
    return 0;
}
