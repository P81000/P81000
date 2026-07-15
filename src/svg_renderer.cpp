#include <fstream>
#include <sstream>
#include <iostream>

#include "svg_renderer.hpp"

// TODO: THIS CODE IS A MESS. FIX IT!
// use variables, instead of magic numbers and magic words, fix width (reduce everything?)

void generate_svg(const std::vector<InfoRow>& profile, const std::vector<std::string>& ascii_art, int followers, int repos, const std::string& filename, bool is_dark) {
    std::string bg_color     = is_dark ? "#0d1117" : "#ffffff";
    std::string panel_color  = is_dark ? "#161b22" : "#f6f8fa";
    std::string border_color = is_dark ? "#30363d" : "#d0d7de";
    std::string text_color   = is_dark ? "#c9d1d9" : "#1f2328";
    std::string accent_color = is_dark ? "#58a6ff" : "#0969da";
    std::string warn_color   = is_dark ? "#d29922" : "#9a6700";
    std::string muted_color  = is_dark ? "#8b949e" : "#59636e";

    std::ostringstream svg;

    svg << "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"680\" height=\"670\" "
        << "font-family=\"ui-monospace, SFMono-Regular, 'JetBrains Mono', 'Cascadia Code', Menlo, Consolas, monospace\">\n";
    
    svg << "<style>\n"
        << "  .val { fill: " << text_color << "; font-size: 10px; }\n"
        << "  .key { fill: #3fb950; font-size: 10px; font-weight: 700; }\n"
        << "  .acc { fill: " << accent_color << "; font-size: 10px; }\n"
        << "  .wrn { fill: " << warn_color << "; font-size: 10px; }\n"
        << "  .hdr { fill: " << accent_color << "; font-size: 10px; font-weight: 700; }\n"
        << "  .sec { fill: " << muted_color << "; font-size: 10px; letter-spacing: 1px; }\n"
        << "  .cur { fill: " << text_color << "; font-size: 10px; animation: blink 1s step-end infinite; }\n"
        << "  @keyframes blink { 50% { opacity: 0; } }\n"
        << "</style>\n";

    svg << "<rect x=\"1\" y=\"1\" width=\"678\" height=\"668\" rx=\"12\" fill=\"" << bg_color 
        << "\" stroke=\"" << border_color << "\" stroke-width=\"1.5\"/>\n";
    svg << "<path d=\"M1 13 a12 12 0 0 1 12 -12 h650 a12 12 0 0 1 12 12 v25 h-978 z\" fill=\"" << panel_color << "\"/>\n";
    svg << "<line x1=\"1\" y1=\"38\" x2=\"679\" y2=\"38\" stroke=\"" << border_color << "\"/>\n";
    
    svg << "<circle cx=\"24\" cy=\"20\" r=\"6\" fill=\"#ff5f56\"/>\n";
    svg << "<circle cx=\"44\" cy=\"20\" r=\"6\" fill=\"#ffbd2e\"/>\n";
    svg << "<circle cx=\"64\" cy=\"20\" r=\"6\" fill=\"#27c93f\"/>\n";
    
    svg << "<text x=\"350\" y=\"24\" class=\"sec\" text-anchor=\"middle\">P81000 — bash — 90x26</text>\n";

    svg << "<text x=\"30\" y=\"66\">\n"
        << "  <tspan class=\"key\">~ $ </tspan>\n"
        << "  <tspan class=\"val\">neofetch --P81000</tspan>\n"
        << "</text>\n";

    float art_x = 30.0;
    float art_y = 105.0;
    float art_lh = 1.7;

    for (const std::string& line : ascii_art) {
        svg << "<text x=\"" << art_x << "\" y=\"" << art_y << "\" class=\"acc\" "
            << "style=\"font-size: 2px; font-family: monospace; fill: #00ff0088;\" xml:space=\"preserve\">" 
            << line << "</text>\n";
        art_y += art_lh;
    }

    float y = 92.0;
    float info_x = 235.0;
    float val_x = info_x + 115.0;

    for (const auto& row : profile) {
        std::string label = std::get<0>(row);
        std::string value = std::get<1>(row);
        std::string style = std::get<2>(row);

        if (label == "__header__") {
            svg << "<text x=\"" << info_x << "\" y=\"" << y << "\" class=\"hdr\">" << value << "</text>\n";
            y += 17.0;
        } 
        else if (label == "__rule__") {
            svg << "<line x1=\"" << info_x << "\" y1=\"" << (y - 8) << "\" x2=\"640\" y2=\"" << (y - 8) 
                << "\" stroke=\"" << border_color << "\"/>\n";
            y += 8;
        }
        else if (label == "__section__") {
            svg << "<text x=\"" << info_x << "\" y=\"" << y << "\" class=\"sec\">" << value << "</text>\n";
            y += 17.0;
        }
        else if (label == "__blank__") {
            y += 10;
        }
        else {
            std::string css_class = (style == "accent") ? "acc" : (style == "warn") ? "wrn" : "val";
            
            if (!label.empty()) {
                svg << "<text x=\"" << info_x << "\" y=\"" << y << "\" class=\"key\">" << label << "</text>\n";
            }
            svg << "<text x=\"" << val_x << "\" y=\"" << y << "\" class=\"" << css_class << "\">" << value << "</text>\n";
            y += 17.0;
        }
    }

    y += 45;

    svg << "<text x=\"30\" y=\"" << y << "\">\n"
        << "  <tspan class=\"key\">~ $ </tspan>\n"
        << "  <tspan class=\"val\">" << "whoami" << "</tspan>\n"
        << "</text>\n";

    y += 2;
    svg << "<text x=\"30\" y=\"" << y << "\" class=\"val\">\n"
        << "  <tspan x=\"28\" dy=\"1.1rem\">" << "Systems Software Engineer focused on high-performance C/C++ systems, Linux-based infrastructure," << "</tspan>\n"
        << "  <tspan x=\"28\" dy=\"1.1rem\">" << "and networking programming." << "</tspan>\n"
        << "  <tspan x=\"28\" dy=\"1.1rem\">" << "Currently working on cybersecurity with secure communication systems and PAM solutions." << "</tspan>\n"
        << "  <tspan x=\"28\" dy=\"1.1rem\">" << "Background spans distributed systems, embedded software, and real-time applications." << "</tspan>\n"
        << "  <tspan x=\"28\" dy=\"1.1rem\">" << "Passionate about programming, linux and performance optimization." << "</tspan>\n"
        << "</text>\n";

    y += 125;
    
    svg << "<text x=\"30\" y=\"" << y << "\">\n"
        << "  <tspan class=\"key\">~ $ </tspan>\n"
        << "  <tspan class=\"val\">" << footer_prompt << "</tspan>\n"
        << "  <tspan class=\"cur\" dx=\"2\">▌</tspan>\n"
        << "</text>\n";

    svg << "</svg>\n";

    std::ofstream outfile(filename);
    if (outfile.is_open()) {
        outfile << svg.str();
        std::cout << "Successfully generated " << filename << "\n";
    } else {
        std::cerr << "Failed to write " << filename << "\n";
    }
}
