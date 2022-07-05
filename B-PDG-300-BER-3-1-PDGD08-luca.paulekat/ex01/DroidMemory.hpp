#ifndef DroidMemory_hpp_
    #define DroidMemory_hpp_

#include <string>
#include <iostream>

class DroidMemory
{
    private:
        size_t Fingerprint;
        size_t Exp;
    public:
        DroidMemory();
        size_t getFingerprint() const;
        void setFingerprint(size_t fingerprint);
        size_t getExp() const;
        void setExp(size_t exp);
        void operator<<(const size_t& exp);
        void operator<<(const DroidMemory& second);
        void operator>>(DroidMemory& second);
        void operator>>(size_t& exp);
        DroidMemory operator+=(const DroidMemory& second);
        void operator+=(const size_t& exp);
        DroidMemory operator+(const size_t& exp);
        DroidMemory operator+(const DroidMemory& second);
};

std::ostream& operator<<(std::ostream& os, const DroidMemory& droid);

#endif