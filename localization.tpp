#ifndef LOCALIZATION_TPP
#define LOCALIZATION_TPP

#include <format>
#include <stdio.h>
#include <iostream>
#include <stdexcept>
#include <ncurses.h>

template<typename... Args>
std::string Localization::getLocalizedString(std::string key, Args... args) {
    const std::string localizedStringKey = getLocalizedStringKey(key);
    try {
        return std::vformat(localizedStringKey, std::make_format_args(args...));
    } catch (const std::format_error& e) {
        throw std::runtime_error("Invalid string format.");
    }
}


template<typename... Args>
void Localization::printLocalizedString(std::string key, Args... args) {
    const std::string localizedStringKey = getLocalizedStringKey(key);
    printf(localizedStringKey.c_str(), args...);
}


template<typename... Args>
void Localization::printwLocalizedString(std::string key, Args... args) {
    const std::string localizedStringKey = getLocalizedStringKey(key);
    printw(localizedStringKey.c_str(), args...);
}

template<typename... Args>
std::string getLocalizedString(std::string key, Args... args) {
    if (!Localization::defaultLocalization) {
        throw std::runtime_error("No default locale is set. Please call the Localization::setDefaultLocale() before calling printLocalizedString().");
    }
    return Localization::defaultLocalization->getLocalizedString(key, args...);
}


template<typename... Args>
std::string getLocalizedString(Locale locale, std::string key, Args... args) {
    Localization localization = Localization(locale);
    return localization.getLocalizedString(key, args...);
}

template<typename... Args>
void printLocalizedString(std::string key, Args... args) {
    if (!Localization::defaultLocalization) {
        throw std::runtime_error("No default locale is set. Please call the Localization::setDefaultLocale() before calling printLocalizedString().");
    }
    Localization::defaultLocalization->printLocalizedString(key, args...);
}

template<typename... Args>
void printLocalizedString(Locale locale, std::string key, Args... args) {
    Localization localization = Localization(locale);
    localization.printLocalizedString(key, args...);
}

template<typename... Args>
void printwLocalizedString(std::string key, Args... args) {
    if (!Localization::defaultLocalization) {
        throw std::runtime_error("No default locale is set. Please call the Localization::setDefaultLocale() before calling printLocalizedString().");
    }
    Localization::defaultLocalization->printwLocalizedString(key, args...);
}

template<typename... Args>
void printwLocalizedString(Locale locale, std::string key, Args... args) {
    Localization localization = Localization(locale);
    localization.printwLocalizedString(key, args...);
}

template<typename... Args>
void printlnLocalizedString(std::string key, Args... args) {
    printLocalizedString(key, args...);
    std::cout << std::endl;
}

template<typename... Args>
void printlnLocalizedString(Locale locale, std::string key, Args... args) {
    printLocalizedString(locale, key, args...);
    std::cout << std::endl;
}

#endif