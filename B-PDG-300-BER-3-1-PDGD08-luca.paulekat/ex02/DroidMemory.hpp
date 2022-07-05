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
        DroidMemory(const DroidMemory& droid);
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
        void operator=(const DroidMemory& second);
        bool operator==(const DroidMemory& second);
        inline bool operator!=(const DroidMemory& second) { return !(*this==second); };
        bool operator<(const DroidMemory& second);
        inline bool operator>(const DroidMemory& second) { return !(*this<second); };
        bool operator<=(const DroidMemory& second);
        bool operator>=(const DroidMemory& second);
        bool operator==(const size_t& exp);
        inline bool operator!=(const size_t& exp) { return !(*this==exp); };
        bool operator<(const size_t& exp);
        inline bool operator>(const size_t& exp) { return !(*this<exp); };
        bool operator<=(const size_t& exp);
        bool operator>=(const size_t& exp);
};

std::ostream& operator<<(std::ostream& os, const DroidMemory& droid);

#endif