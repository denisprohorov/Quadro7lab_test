#pragma once

#include <string>

namespace emails{
    constexpr float hide_level = 0.55;

    std::string hide_email(std::string_view email);
}
