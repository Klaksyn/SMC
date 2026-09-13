#include <iostream>
#include <chrono>
#include <format>
#include <print>
#include <filesystem>
#include <string>
#include <complex>
#include <unordered_map>
#include <functional>
#include <windows.h>

//======================
// fs
//======================
#include "header/fs/FILEOPEN.h"
#include "header/fs/FILEMAKE.hpp"
#include "header/fs/DIRMAKE.h"
#include "header/fs/FILERMV.h"
#include "header/fs/FILEFIND.h"
#include "header/fs/EXPLORER.h"
#include "header/fs/DISK.h"
#include "header/fs/Rename.h"

//======================
// text
//======================
#include "header/text/io_text.h"

//======================
// JSON
//======================
#include "header/json/JSON.h"

//======================
// console
//======================
#include "header/console/cmd.h"
#include "header/console/color_console.h"
#include "header/console/help.h"

//======================
// time and date
//======================
#include"header/date/date.h"

//======================
// helper
//======================
#include "header/fs/COPY.h"
#include "header/fs/MOVE.h"
#include "header/helper/helper.h"
#include "header/helper/helper_echo.h"
#include "header/helper/path_ff.h"
#include "header/helper/IO.hpp"

namespace fs = std::filesystem;

//================================
// C++ 26
// SMC - Simple Mini Commander
//================================

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // hello
#ifdef _WIN32 // for windows
    std::println("Hello Windows");
#elif __APPLE__
    std::println("Hello MAC-OS");
#else
    std::println("Hello LINUX");
#endif

    // history all
    std::vector<std::string> history {};
    std::vector<std::string> hist_search {}; // history of found files
    std::string lastListedPath;

    std::string user_input;

    bool isRun = true;
    bool isShowPathWhenStartLoop = true;

    std::unordered_map<std::string, std::function<void(const std::vector<std::string>&)>> commands;

    // commands
    //============
    // console
    //============
    commands["help"] = [&](const std::vector<std::string>& args) {
        help::check_help(args);
    };

    commands["color"] = [&](const std::vector<std::string>& args) {
        if (args.size() <= 1) {
            IO::phint("you need to write like this -> color ... <- (color name)");
            return;
        }

        std::println("{}", ColorConsole::choice_color(args[1]));
    };
    commands["col"] = commands["color"];

    commands["info"] = [&](const std::vector<std::string>&) {
        std::println("____Simple Mini Commander____");
        std::println("_____Author: Alexander K_____");
        std::println("_____Git-Hub: Syneation______");
        std::println("____Git-Hub: AlexanderSYN____");
        std::println("_________Beta Test V1.2________");
    };
    commands["about"] = commands["info"];

    //================
    // time and date
    //================
    commands["time"] = [&](const std::vector<std::string>&) {
        println("{}", date::local_time());
    };

    commands["date"] = [&](const std::vector<std::string>&) {
        println("{}", date::local_date_and_time());
    };

    //=================
    // console
    //=================
    commands["cmd"] = [&](const std::vector<std::string>& args) {
        if (args.size() == 1 || args[1] == "run") {
            std::println("You just to run the cmd by Windows!");
            std::println("To exit type exit!");
            cmd::run("cmd");
            return;
        }

        cmd::run(args[1]);
    };

    commands["path"] = [&](const std::vector<std::string>& args) {
        if (args.size() == 1) {
            if (isShowPathWhenStartLoop)
                std::println("[HINT] maybe you mean -> path --hide?");
            else
                std::println("[HINT] maybe you mean -> path --show?");
            return;
        }

        if (args[1] == "--hide" || args[1] == "-h" || args[1] == "hide")
            isShowPathWhenStartLoop = false;

        else if (args[1] == "--show" || args[1] == "-s" || args[1] == "show")
            isShowPathWhenStartLoop = true;
        else {
            std::println("[ERR] Unknown parameter!");
            std::println("[HINT] maybe you mean -> path --hide"
                                                     " or path --show?");
        }
    };

    commands["history"] = [&](const std::vector<std::string>& args) {
        if (args.size() > 1) {

            if (args[1] == "search" || args[1] == "-s" || args[1] == "--search")
                if (!hist_search.empty())
                    for (int i = 0; i < hist_search.size(); i++)
                        std::println("{}) {}", i, hist_search[i]);
                else
                    std::println("[HINT] history search empty");

            else if (args[1] == "save" || args[1] == "-sv" || args[1] == "--save") {
                if (args.size() < 4) {
                    std::println("[HINT] you can to specify the path to"
                                 " the txt file to save the console histor, example:"
                                 "hist save name.txt -h or -h_s path");
                    std::print("maybe create a text file and record the"
                               " history in the current path? <y/n>: ");
                    char choice;
                    std::cin >> choice;
                    if (std::tolower(choice) == 'y')
                        FILEC::create_file_and_record(path_ff::get_path(), "history.txt", history);
                    helper::clear_input_buffer();
                }
                else {
                    if (args[3] == "hist" or args[3] == "history"
                        || args[3] == "-h" || args[3] == "--history")
                        FILEC::create_file_and_record(args[4], args[2], history);

                    else if (args[3] == "hist_srh" or args[3] == "history_search"
                        || args[3] == "-h-s" || args[3] == "--history_search")
                        FILEC::create_file_and_record(args[4], args[2], hist_search);
                }
            }
            helper::clear_input_buffer();
        } else
            for (int i = 1; i < history.size(); i++)
                std::println("{}) {}", i, history[i]);

    };
    commands["hist"] = commands["history"];


    commands["clear"] = [&](const std::vector<std::string>& args) {
        #ifdef _WIN32 // for windows
                system("cls");
        #else // for Mac OS / Linux
                system("clear");
        #endif
    };
    commands["cls"] = commands["clear"];

    commands["exit"] = [&](const std::vector<std::string>&) {
        isRun = false;
    };
    commands["ex"] = commands["exit"];

    //=======================
    // JSON
    //=======================
    commands["mkcommand"] = [&](const std::vector<std::string>& args) {
        if (args.size() < 3) {
            IO::phint("you need write like so: mkcommand (name) (action)");
            return;
        }
        JSON::save_command(args[1], args);
    };
    commands["mkcmd"] = commands["mkcommand"];


    commands["my-commands"] = [&](const std::vector<std::string>) {
        JSON::print_all_commands();
    };
    commands["mycmd"] = commands["my-commands"];

    commands["change-command"] = [&](const std::vector<std::string>& args) {
        if (args.size() > 3) {
            IO::phint("you need to write like so: change-command (old command) (new command)");
            return;
        }

        if (JSON::change_command(args[1], args[2])) {
            IO::psuccess("command successfully changed!");
            return;
        }

        IO::perror("command is not changed!");
    };
    commands["chcmd"] = commands["change-command"];

    commands["del-command"] = [&](const std::vector<std::string>& args) {
        if (args.size() > 2) {
            IO::phint("you need to write like so: del-command (what command)");
            return;
        }

        if (JSON::delete_command(args[1])) {
            IO::psuccess("command successfully deleted!");
            return;
        }

        IO::perror("command is not deleted!");
    };
    commands["delcmd"] = commands["del-command"];

    commands["change-action"] = [&](const std::vector<std::string>& args) {
        if (args.size() > 3) {
            IO::phint("you need to write like so: change-action (command) (new action)");
            return;
        }

        if (JSON::change_action(args[1], args)) {
            IO::psuccess("action successfully changed!");
            return;
        }

        IO::perror("action is not changed!");
    };
    commands["chact"] = commands["change-action"];

    commands["run-command"] = [&](const std::vector<std::string>& args) {
        if (args.size() > 2) {
            IO::phint("You need to write like this: run-command (command)");
            return;
        }

        std::string action = JSON::get_action(args[1]);

        std::vector<std::string> sub_args;
        std::string token;
        std::istringstream iss(action);

        while (iss >> token)
            sub_args.push_back(token);

        if (sub_args.empty()) return;

        std::string cmd_name = sub_args[0];
        if (commands.contains(cmd_name)) {
            commands[cmd_name](sub_args);
        } else {
            IO::perror("Internal command from JSON action is unknown!");
        }
    };
    commands["rnc"] = commands["run-command"];
    commands["rc"] = commands["run-command"];
    commands["rn"] = commands["run-command"];


    //=================
    // work with text
    //=================
    commands["cat"] = [&](const std::vector<std::string>& args) {
        if (args.size() > 1) {
            fs::path path = helper::connect_path(path_ff::get_path(), args[1]);
            if (fs::exists(path) & fs::is_regular_file(path))
                text::read(path.string());
            else
                text::read(args[1]);
        }
        else
            text::read(path_ff::get_path());
    };
    commands["read"] = commands["cat"];

    // echo (param) (path / text) (text)
    commands["echo"] = [&](const std::vector<std::string>& args) {
        text::echo(args, path_ff::get_path());
    };
    //==================================================
    // write many lines
    // example
    // >> echoln (path)
    // if the default path is specified via cd,
    // then you don't have to write anything.
    //==================================================
    commands["echoln"] = [&](const std::vector<std::string>& args) {
        fs::path path_f = text::resolve_file_path_for_echolnrw(args,
                                            path_ff::get_path());
        text::write_many_lines(path_f);
    };
    // rewrite (text)
    commands["echoln-rw"] = [&](const std::vector<std::string>& args) {
        fs::path path_f = text::resolve_file_path_for_echolnrw(args,
                                        path_ff::get_path());
        text::rewrite_many_lines(path_f);
    };


    //============================
    // work with files / folders
    //============================
    commands["cd"] = [&](const std::vector<std::string>& args) {
        if (args.size() <= 1)
            std::println("{}", path_ff::get_OPath());

        else if (args.size() == 2) {

            if (args[1] == "!$") {
                FILEO::set_path_in_cd(lastListedPath);
                return;
            }

            FILEO::set_path_in_cd(args[1]);
        }

        else {
            // if has parametr --path then to ask place path
            if (args[1] == "-p" || args[1] == "--place") {
                FILEO::choice_place_path_in_cd(stoi(args[2]));
                return;
            }

            FILEO::set_path_in_cd(
                helper::connect_path_with_spaces_str(args));
        }
    };
    commands["pwd"] = [&](const std::vector<std::string>&) {
        std::println("{}", path_ff::get_OPath());
    };

    commands["explorer"] = [&](const std::vector<std::string>& args) {
        if (args.size() <= 1) {
            explr::reveal_in_explorer(path_ff::get_path());
            return;
        }

        if (args.size() > 2) {
            explr::reveal_in_explorer(helper::connect_path_with_spaces(args));
        }

        explr::reveal_in_explorer(args[1]);
    };
    commands["exp"] = commands["explorer"];
    commands["explr"] = commands["explorer"];
    commands["openf"] = commands["explorer"];

    //========================
    // File
    //========================
    commands["run"] = [&](const std::vector<std::string>& args) {
        if (args.size() <= 1)
            explr::run_file(path_ff::get_path());

        else {
            if (fs::exists(args[1])) {
                explr::run_file(args[1]);
            }
            else {
                fs::path fll_path = helper::connect_path(path_ff::get_path(),
                                                        args[1]);
                explr::run_file(fll_path);
            }
        }
    };

    commands["copy"] = [&](const std::vector<std::string>& args) {
        if (args.size() < 2) {
            std::println("[HINT] incorrectly command, you need to write so: copy / cp (parametr) (source) (target) or\n"
                         "copy / cp (source) (target)!");
            return;
        }

        std::string parameter = "no";
        fs::path source = (args.size() == 2) ? path_ff::get_path() : args[1];
        fs::path target = (args.size() == 2) ? args[1] : args[2];

        if (args.size() == 4) {
            parameter = args[3];
        }

        copy::copy_folder_or_file(source, target, parameter);

    };
    commands["cp"] = commands["copy"];

    commands["move"] = [&](const std::vector<std::string>& args) {
        if (args.size() < 2) {
            IO::phint("incorrectly command, you need to write so: move (source) (target)!");
            return;
        }
        std::string source ;
        std::string target ;

        if (args.size() < 3) {
            source = path_ff::get_path().string();
            target = args[1];
        }
        else {
            source = args[1];
            target = args[2];
        }

        MOVE::move_item(source, target);
    };

    commands["rename"] = [&](const std::vector<std::string>& args) {
        if (args.size() < 3) {
            std::println("[SYSTEM] [HINT] You need to write so: rename [old_name] [new_name]");
            std::println("[SYSTEM] [HINT] ren [old_name] [new_name]");
            std::println("[SYSTEM] [HINT] rnm [old_name] [new_name]");
            return;
        }

        std::string source = args[1];
        std::string target = args[2];

        Rename::ren(source, target);
    };
    commands["ren"] = commands["rename"];
    commands["rn"] = commands["rename"];
    commands["rnm"] = commands["rename"];

    commands["open"] = [&](const std::vector<std::string>& args) {
        if (args.size() <= 1)
            FILEO::command_open();
        else
            FILEO::command_open(args[1]);
    };
    commands["dir"] = [&](const std::vector<std::string>&) {
        FILEO::command_dir_windows();
    };
    commands["ls"] = [&](const std::vector<std::string>& args) {
        if (args.size() <= 1)
            FILEO::command_list();
        else {
            fs::path tmp_path = helper::connect_path(path_ff::get_path(),
                args[1]);

            lastListedPath = args[1];

            if (fs::exists(tmp_path))
                FILEO::command_list(tmp_path);
            else
                FILEO::command_list_with_parameter(args[1]);
        }
    };

    //========================
    // find
    //========================
    commands["find"] = [&](const std::vector<std::string>& args) {
        if (args.size() == 1) {
            std::println("[HINT] You need to write like so: "
                         "find <param> <file or folder>");
            return;
        }
        if (args.size() <= 2) {
            FILEFIND::find(args[1], "-g", path_ff::get_path());
            hist_search.push_back(args[1]);
            return;
        }
        FILEFIND::find(args[2], args[1], path_ff::get_path());
        hist_search.push_back(args[1]);
    };

    //========================
    // create file or folder
    //========================
    commands["touch"] = [&](const std::vector<std::string>& args) {
      if (args.size() > 2) {
          std::println(std::cerr, "[HINT] You need to write so: touch (name file).(extension)");
          return;
      }
      FILEC::command_touch(path_ff::get_path(), args);
    };
    commands["mkdir"] = [&](const std::vector<std::string>& args) {
        if (args.empty()) {
            std::println(std::cerr, "[HINT] You need to write so: touch (name folder)");
            return;
        }

        DIRMAKE::command_mkdir(path_ff::get_path(), args);
    };
    //========================
    // delete file or folder
    //========================
    commands["delete"] = [&](const std::vector<std::string>& args) {
        if (args.size() == 1) {
            FILERMV::remove(path_ff::get_path());

            if (!fs::exists(path_ff::get_path()))
                path_ff::set_path(path_ff::get_path().parent_path().string());
        }
        else
            FILERMV::remove_multiple(path_ff::get_path(), args);
    };
    commands["del"] = commands["delete"];
    commands["remove"] = commands["delete"];
    commands["rmv"] = commands["delete"];

    //=================================
    // disk drive
    //=================================
    // get free drive space
    // example: D:/path >> free
    // or : />> free D:\
    //=================================
    commands["free"] = [&](const std::vector<std::string>& args) {
        if (args.size() == 1)
            disk::output_free_in_disk(path_ff::get_path());
        else
            disk::output_free_in_disk(args[1]);
    };
    // folder size
    commands["size"] = [&](const std::vector<std::string>& args) {
        if (args.size() == 1)
            disk::output_ocuppied_in_folders(path_ff::get_path());
        else
            disk::output_ocuppied_in_folders(args[1]);
    };
    commands["du"] = commands["size"];

    std::println("for help type help!");

    while (isRun) {
        try {
            if (isShowPathWhenStartLoop)
                std::print("{} >>", path_ff::get_OPath());
            else
                std::print("$ ");

            std::getline(std::cin, user_input);
            history.push_back(user_input);

            std::vector<std::string> args;
            std::istringstream iss(user_input);
            std::string word;

            while (iss >> word)
                args.push_back(word);

            if (!args.empty() && commands.contains(args[0]))
                commands[args[0]](args);
            else {
                std::println("Unknown command!");
                std::println("for help type help!");
            }
        } catch (const std::exception& e) {
            std::cerr << "[ERROR_CONSOLE] " << e.what() << std::endl;
        }
    }

}


