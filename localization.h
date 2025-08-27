
/**
 * Localization library to help with translations in code.
 */
#ifndef LOCALIZATION_H
#define LOCALIZATION_H

#include <iostream>
#include "locale.h"

template<typename... Args>
void printLocalizedString(std::string key, Args... args);

template<typename... Args>
void printLocalizedString(Locale locale, std::string key, Args... args);

template<typename... Args>
void printwLocalizedString(std::string key, Args... args);

template<typename... Args>
void printwLocalizedString(Locale locale, std::string key, Args... args);

template<typename... Args>
void printlnLocalizedString(std::string key, Args... args);

template<typename... Args>
void printlnLocalizedString(Locale locale, std::string key, Args... args);

template<typename... Args>
std::string getLocalizedString(std::string key, Args... args);

template<typename... Args>
std::string getLocalizedString(Locale locale, std::string key, Args... args);

class Localization {
private:
    Locale locale;

public:

    Localization(Locale locale);

    static Localization* defaultLocalization;

    static void setDefaultLocale(Locale locale);

    std::string getLocalizedStringKey(std::string key);

    template<typename... Args>
    std::string getLocalizedString(std::string key, Args... args);

    template<typename... Args>
    void printLocalizedString(std::string key, Args... args);

    template<typename... Args>
    void printwLocalizedString(std::string key, Args... args);

};

#include "localization.tpp"

#endif