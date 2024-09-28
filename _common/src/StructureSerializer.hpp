#pragma once
#include <iostream>
#include <nlohmann/json.hpp>
#include <string>

#include "Repositories.hpp"
using json = nlohmann::json;

namespace Serializer
{
    json serialize(const Common::Dataset& data);

    Common::Dataset deserialize(const json& buffer);
} // namespace Serializer