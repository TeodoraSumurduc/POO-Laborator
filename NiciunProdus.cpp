//
// Created by TEODORA on 26.04.2023.
//

#include "NiciunProdus.h"
NiciunProdus::NiciunProdus() {}
const char* NiciunProdus::what() const noexcept {
    return "Nu puteti introduce 0 produse in depozit.";
}