#pragma once
#include <iostream>
#include <nlohmann/json.hpp>
#include <string>

#include "Repositories.hpp"

namespace Serializer
{
    nlohmann::json serialize(const Common::Dataset& data);

    Common::Dataset deserialize(const nlohmann::json& buffer);
} // namespace Serializer