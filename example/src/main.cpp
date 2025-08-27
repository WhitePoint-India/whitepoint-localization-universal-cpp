#include <localization/localization.h>
#include <localization/locale.h>
#include <iostream>

int main() {
    // Create a locale from a JSON file
    Locale englishLocale = Locale::create("locales/en.json");
    
    // Set the default locale
    Localization::setDefaultLocale(englishLocale);
    
    // Use the localization system
    // Assuming you have a key "welcome_message" in your JSON file
    std::string welcomeMsg = Localization::defaultLocalization->getLocalizedStringKey("welcome_message");
    std::cout << welcomeMsg << std::endl;
    
    // You can also use the template functions for formatted strings
    printlnLocalizedString("greeting", "John");
    
    return 0;
}