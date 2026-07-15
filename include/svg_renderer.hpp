#pragma once

#include <vector>
#include <string>
#include "profile_data.hpp"

void generate_svg(const std::vector<InfoRow>& profile, const std::vector<std::string>& ascii_art, int followers, int repos, const std::string& filename, bool is_dark);
