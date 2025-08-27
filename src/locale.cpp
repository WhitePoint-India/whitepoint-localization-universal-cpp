#include <fstream>
#include <iostream>
#include <localization/locale.h>

Locale::Locale(const nlohmann::json json): json(json) {

}

Locale Locale::create(std::string filepath) {
    /// - Create the file input stream, to read the JSON file.
    std::ifstream stream(filepath);
    /// - Parse the JSON stream to get the JSON object.
    nlohmann::json json = nlohmann::json::parse(stream);
    /// - Create and return the Locale.
    return Locale(json);
}

std::string Locale::operator[](const std::string& key) const {
    try {
        return json.at(key).get<std::string>();
    } catch (const nlohmann::json::exception& e) {
        return key;
    }
}