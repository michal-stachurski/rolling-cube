#pragma once

#include <string>

/* Violet Indigo Blue Green Yellow Orange Red */
const char colors[] = {'V','I','B','G','Y','O','R'};

std::string color(char c) {
    switch (c) {
        case '-': return "\033[40m  \033[0m";
        // case 'V':
        // case 'I':
        case 'B': return "\033[44m  \033[0m";
        case 'G': return "\033[42m  \033[0m";
        case 'Y': return "\033[43m  \033[0m";
        // case 'O': 
        case 'R': return "\033[41m  \033[0m";
        default:  return "\033[47m  \033[0m";
    }
}

std::string color(int i = 2) {
    switch (i) {
        case 0: return "\033[47m  \033[0m";
        case 1: return "\033[44m  \033[0m";
        default: return "\033[40m  \033[0m";
    }
}
