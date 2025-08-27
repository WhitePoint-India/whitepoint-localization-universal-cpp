#include <stdio.h>
#include <iostream>
#include <string>
#include <localization/localization.h>

Localization* Localization::defaultLocalization = NULL;

Localization::Localization(Locale locale): locale(locale) {
    
}

std::string Localization::getLocalizedStringKey(std::string key) {
    return this->locale[key];
}

void Localization::setDefaultLocale(Locale locale) {
    Localization::defaultLocalization = new Localization(locale);
}
