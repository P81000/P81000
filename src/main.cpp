#include <iostream>
#include <string>
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>

#include "profile_data.hpp"
#include "svg_renderer.hpp"
#include "ascii_gen.hpp"

using json = nlohmann::json;

int main() {
    std::string asset_name = "assets/tux-linux.png";
    std::string username = "P81000";
    std::string uri = "https://api.github.com/users/" + username;

    std::cout << "➜ ~ fetching stats for " << username << "...\n";

    cpr::Response r = cpr::Get(cpr::Url{uri}, cpr::Header{{"User-Agent", "cpp-profile-readme"}});

    if (r.status_code == 200) {
        json user_data = json::parse(r.text);
        
        std::string name = user_data.value("name", "Unknown");
        int followers = user_data.value("followers", 0);
        int repos = user_data.value("public_repos", 0);
        
        std::cout << "\n[ Data Ready for Rendering ]\n";
        std::cout << "GitHub Name: " << name << " | Followers: " << followers << " | Repos: " << repos << "\n";
        
        std::cout << "Profile Role: " << std::get<1>(profile_info[2]) << "\n"; 

        std::cout << "Generating ASCII art from assets\n";
        std::vector<std::string> ascii_art = generate_ascii_portrait(asset_name);
        
        std::cout << "Rendering SVGs...\n";
        generate_svg(profile_info, ascii_art, followers, repos, "dark.svg", true);

    } else {
        std::cerr << "Error fetching data! HTTP Status: " << r.status_code << "\n";
        return 1;
    }

    return 0;
}
