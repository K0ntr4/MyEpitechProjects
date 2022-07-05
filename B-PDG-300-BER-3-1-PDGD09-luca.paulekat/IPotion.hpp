//
// Created by Luca on 1/24/22.
//

#ifndef _IPOTION_HPP_
    #define _IPOTION_HPP_

#include <string>

class IPotion {
    public:
        virtual std::string getType() const = 0;
};

#endif
