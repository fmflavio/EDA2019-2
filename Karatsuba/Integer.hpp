#pragma once
#include <string>
#include <functional>

class Integer{
    public:
        Integer();
        Integer(const std::string& input);
        ~Integer();
        Integer operator+(const Integer& other) const;
        Integer operator-(const Integer& other) const;
        Integer operator*(const Integer& other) const;
        size_t size() const{return fString.size();}
        void padRight(size_t num);
        void padLeft(size_t num);
        Integer substr(size_t pos, size_t length) const;
        void print() const;
        void stripLeadingZeros();
    private:
        std::string fString;
};
void equalizeLengthsPadLeft(Integer& first, 
                            Integer& second);
void equalizeLengthsPadRight(std::string& first, std::string& second);