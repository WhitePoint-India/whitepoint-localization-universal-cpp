#ifndef LOCALE_H
#define LOCALE_H

#include <string>
#include <nlohmann/json.hpp>

class Locale {
private:
    nlohmann::json json;
    explicit Locale(const nlohmann::json);
public:
    static Locale create(std::string filepath);

    std::string operator[](const std::string& key) const;
};

#endif // LOCALE_H