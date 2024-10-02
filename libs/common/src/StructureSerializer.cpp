#include "StructureSerializer.hpp"

nlohmann::json Serializer::serialize(const Common::Dataset& data) {
    nlohmann::json jsonObject;

    for (const auto &[key, value] : data) {
        nlohmann::json jsonRow = nlohmann::json::array();
        for (const auto &cell : value) {
            try {
                jsonRow.push_back(cell);
            } catch (const nlohmann::json::exception &e) {
                std::cout << "Skipping invalid UTF-8 character in key: {}. Error: {}" << key << e.what() << std::endl;
                continue;
            }
        }
        jsonObject[key] = jsonRow;
    }

    return jsonObject;
}

// Deserialization functions

Common::Dataset Serializer::deserialize(const nlohmann::json& buffer) {
    Common::Dataset dataset;
    for (auto &[key, jsonRow] : buffer.items()) {
        if (!jsonRow.is_array()) {
            std::cout << "Invalid JSON array for key: {}" << key << std::endl;
            continue;
        }

        Common::Data row;
        for (auto &cellValue : jsonRow) {
            try {
                row.push_back(cellValue.get<std::string>());
            } catch (const nlohmann::json::exception &e) {
                std::cout << "Skipping invalid UTF-8 character in key: {}. Error: {}" << key <<
                            e.what() << std::endl;
                continue;
            }
        }
        dataset[key] = std::move(row);
    }

    return dataset;
}
