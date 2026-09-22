//
// Created by AlexanderSYN on 28.03.2026.
//
#include "../../header/helper/path_ff.h"

#include "../../header/helper/helper.h"

fs::path path_ff::path_f = "\\";
std::string path_ff::OPath = "\\";

///
/// OPath is Output Path for string
/// @return path (string)
std::string path_ff::get_OPath() {
    if (path_ff::OPath.empty())
        return "\\";

    return path_ff::OPath;
}

///
/// path is path for fs::path
/// @return path (fs::path)
fs::path path_ff::get_path() {
    if (path_ff::path_f.empty())
        return "\\";

    return path_ff::path_f;
}

///
/// filename from your path
/// @return filename
std::string path_ff::filename() {
    return path_f.filename().string();
}


///
/// set new path for path_f and OPath
/// @param new_path new path for path and OPath
///
void path_ff::set_path(const std::string& new_path) {
    if (new_path.empty()) return;

    fs::path p(new_path);

    std::string clean_path = p.lexically_normal().make_preferred().string();

    if (clean_path.starts_with(R"(\?\)") || clean_path.starts_with(R"(\\?\)")) {
        std::size_t pos = clean_path.find(":");
        if (pos != std::string::npos && pos > 0) {
            clean_path = clean_path.substr(pos - 1);
        }
    }

    path_ff::OPath = new_path;
    path_ff::path_f = new_path;
}
