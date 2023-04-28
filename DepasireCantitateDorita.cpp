//
// Created by TEODORA on 25.04.2023.
//

#include "DepasireCantitateDorita.h"

#include <iostream>
using namespace std;


const char* DepasireCantitateDorita::what() const noexcept {
    return "Vreti sa introduceti prea multe obiecte din categoria selectata. Maximul este de 100.Produsele nu vor fi introduse in depozit.";
}

DepasireCantitateDorita::DepasireCantitateDorita() {}
