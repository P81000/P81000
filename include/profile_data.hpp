#pragma once

#include <vector>
#include <string>
#include <tuple>

using InfoRow = std::tuple<std::string, std::string, std::string>;

inline std::vector<InfoRow> profile_info = {
    // Header
    InfoRow{"__header__", "Pedro Masteguin", ""},
    InfoRow{"__rule__", "", ""},
    
    // Core Identity
    InfoRow{"Role",     "Systems Software Engineer @ Segura", "val"},
    InfoRow{"Edu",      "Bachelor's Degree · UNIFESP", "val"},
    InfoRow{"Focus",    "Modern C++ · Real-Time Systems · Middleware", "accent"},
    InfoRow{"__blank__", "", ""},
    
    // Stack
    InfoRow{"__section__", "~/stack", ""},
    InfoRow{"Core",      "C++17/20 · C · Bash · Lua · Python", "val"},
    InfoRow{"Systems",   "Embedded Linux · Yocto · ROS2", "val"},
    InfoRow{"Infra",     "AWS · Docker", "val"},
    InfoRow{"Tools",     "CMake · Git · Neovim · perf · gdb", "val"},
    InfoRow{"Platforms", "Mission Planner · PX4 ArduPilot · XPlane", "val"},
    InfoRow{"__blank__", "", ""},
    
    // Projects
    InfoRow{"__section__", "~/projects", ""},
    InfoRow{"libssh2",  "Contributor to the C SSH2 library", "val"},
    InfoRow{"Vacuum-Robot", "Navigation and control system powered by ROS2", "val"},
    InfoRow{"Redis Internals", "Redis internals implementation in C++", "val"},
    InfoRow{"__blank__", "", ""},
    
    // Contact Info
    InfoRow{"__section__", "~/reach", ""},
    InfoRow{"In",       "linkedin.com/in/pedro-masteguin", "accent"},
    InfoRow{"Mail",     "pmasteguin@icloud.com", "accent"},
    InfoRow{"Phone",     "+55 (19) 99938-8063", "accent"}
};

inline std::string footer_prompt = "open to --System Engineer --Software Engineer --Embedded Systems roles";
