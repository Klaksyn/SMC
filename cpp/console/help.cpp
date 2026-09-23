//
// Created by AlexanderSYN on 02.06.2026.
//
#include "../../header/console/help.h"
#include "../../header/console/color_console.h"
#include "../../header/helper/IO.hpp"

void help::check_help(const std::vector<std::string>& args) {
    if (args.size() <= 1) {
        std::println("---------------------- HELP ----------------------");
        std::println("help -c  / --color         Show color help");
        std::println("help --cmd                 Show CMD help");
        std::println("help -dt / --date          Show date and time help");
        std::println("help -ph / --path          Show path command help");
        std::println("help -hs / --history       Show command history help");
        std::println("help -cls / --clear        Show clear command help");
        std::println("help -mc / --my_commands   Show custom commands help");
        std::println("help -op / --open          Show open command help");
        std::println("help -fd / --file_dir      Show file and directory help");
        std::println("help -txt / --text         Show text file help");
        std::println("help -ls / --list          Show directory listing help");
        std::println("help -f  / --find          Show search help");
        std::println("help -dk / --disk          Show disk utility help");
        std::println("help -ex / --exit          Show exit command help");
        std::println("help --all                 Show all help topics");
        std::println("-------------------- END HELP --------------------");
    }
    else if (args[1] == "--color" || args[1] == "-col" || args[1] == "--colour")help::color();
    else if (args[1] == "--date" || args[1] == "--time"
        || args[1] == "-d" || args[1] == "-t") help::date();
    else if (args[1] == "--all") help::all();
    else if (args[1] == "--cmd") help::cmd();
    else if (args[1] == "-ph" || args[1] == "--path") help::path();
    else if (args[1] == "-hs" || args[1] == "--history") help::history();
    else if (args[1] == "-cls" || args[1] == "--clear") help::clear();
    else if (args[1] == "-mc" || args[1] == "--my_commands"
        || args[1] == "mkcmd" || args[1] == "-mkcmd") help::my_commands();
    else if (args[1] == "-op" || args[1] == "--open") help::open();
    else if (args[1] == "-fd" || args[1] == "--file_dir") help::fileDir();
    else if (args[1] == "-txt" || args[1] == "--text") help::text();
    else if (args[1] == "-ls" || args[1] == "--list") help::ls();
    else if (args[1] == "-f" || args[1] == "--find") help::find();
    else if (args[1] == "-dk" || args[1] == "--disk") help::disk();
    else if (args[1] == "-ex" || args[1] == "--exit") help::exit();
    else IO::perror("Unknown parameter. Use 'help' without arguments to see available options.");
}

void help::cmd() {
    std::println("[-------- HELP: CMD --------]");
    std::println("cmd");
    std::println("    Start Windows Command Prompt.");
    std::println();
    std::println("cmd [command]");
    std::println("    Execute a Windows CMD command.");
    std::println();
}

void help::history() {
    std::println("[--------HELP HISTORY--------]");
    std::println("history - show your history");
    std::println("history <param>| -h-s | --history_search - show a history search");
    std::println("param:");
    std::println("--search | -s - history search");
    std::println("--save | -sv - save your history in txt file");
    std::println("-cls | --clear - clear history");
    std::println();
}

void help::clear() {
    std::println("[--------HELP CLEAR--------]");
    std::println("clear | cls - clear console");
    std::println();
}

void help::my_commands() {
    std::println("[--------HELP MY_COMMANDS--------]");
    std::println("my_commands:");
    std::println("mkcommand | mkcmd [name] [action] - make your command");
    std::println("to change:");
    std::println("change-command | chcmd [old command] [new command] - change old command");
    std::println("change-action | chact [command] [new-action] - change action");
    std::println("delete command:");
    std::println("del-command | delcmd [command] - delete command");
    std::println("to run:");
    std::println("run-command | rnc | rc | rn [your command] - run your command");
    std::println();
}

void help::color() {
    std::println("_____available colors that you can use_____");

    ColCons::set_red_color_console();
    std::println("this text is dark red in color -> dark_red");
    ColCons::set_LightRed_color_console();
    std::println("this text is red in color -> red");

    ColCons::set_green_color_console();
    std::println( "this text is dark green in color -> dark_green");
    ColCons::set_LightGreen_color_console();
    std::println( "this text is green in color -> green");

    ColCons::set_blue_color_console();
    std::println( "this text is dark blue in color -> dark_blue");
    ColCons::set_LightBlue_color_console();
    std::println( "this text is blue in color -> blue");

    ColCons::set_cyan_color_console();
    std::println( "this text is dark cyan in color -> dark_cyan");
    ColCons::set_LightCyan_color_console();
    std::println( "this text is cyan in color -> cyan");

    ColCons::set_Brown_color_console();
    std::println( "this text is brown in color -> brown");

    ColCons::set_DarkGray_console();
    std::println( "this text is dark gray in color -> dark_gray");
    ColCons::set_LightGray_color_console();
    std::println( "this text is gray in color -> gray");

    ColCons::set_magenta_color_console();
    std::println( "this text is magenta in color -> magenta");

    ColCons::set_yellow_color_console();
    std::println( "this text is yellow in color -> yellow");

    ColCons::set_white_color_console();
    std::println( "this text is white in color -> white / default / def");
    std::println();
}

void help::path() {
    std::println("[--------HELP PATH--------]");
    std::println("path:");
    std::println("cd [dir] - change directory");
    std::println("cd !$ - last listed path");
    std::println("cd -p [number]");
    std::println("pwd - output current path");
    std::println("path [param] - show or hide path");
    std::println("^[param] - --show | -s | --hide | -h^");
    std::println();
}

void help::open() {
    std::println("[--------HELP OPEN--------]");
    std::println("open:");
    std::println("explorer | explr | exp | openf - show current path in explorer");
    std::println("explorer | explr | exp | openf [path] - open a path in explorer");
    std::println("D:\\t.txt>>run | run [path to file] - run any file via console");
    std::println();

}

void help::fileDir() {
    std::println("[--------HELP FileDir--------]");
    std::println("File | Folder:");
    std::println("touch (name file).(extension) ... - create file in current path");
    std::println("mkdir name_dir ... - create folder in current path");
    std::println("ren | rnm | rename [old_name] [new_name] - rename file or directory");
    std::println("del | delete | remove | rmv name ... - delete files or directories");
    std::println("copy | cp [source] [target] - copy from source path to target path");
    std::println("or just: D:\\test>>cp [target] - source path use from current path");
    std::println("move [source] [target] - move from source to target");
    std::println();
}

void help::text() {
    std::println("[--------HELP Text--------]");
    std::println("Text File or any other:");
    std::println("read | cat | read/cat [path to any files which can to read] - read file");
    std::println("echo [param] [text] - write text in current path");
    std::println("[param] -> -w | --write | -rw | --rewrite");
    std::println("echoln | echoln [path] - write text with many lines");
    std::println("echoln-rw | echoln-rw [path] - rewrite text with many lines");
    std::println();
}

void help::ls() {
    std::println("[--------HELP LS--------]");
    std::println("ls - list files and folders with count");
    std::println("[HINT] you can too use number when you want change directory:");
    std::println("cd -p [number]");
    std::println("open - output all files and folders on all OS");
    std::println("dir - output all files and folders on Windows");
    std::println();
}

void help::find() {
    std::println("[--------HELP FIND--------]");
    std::println("Find:");
    std::println("find [param] [file or folder] - find file or folder");
    std::println("param -> -g | -gf | -gd | -l | -lf | -ld");
    std::println("param -> --global | --global-file | --global-directory | --local | --local-file | --local-directory");
    std::println("--global | -g -> search for files and folders by name throughout the system");
    std::println("--global-file | -gf -> search only files by name throughout the system");
    std::println("--global-directory | -gd -> search only directory by name throughout the system");
    std::println("--local | -l - search for files and folders by name in a local folder");
    std::println("--local-file | -lf - search only files by name in a local folder");
    std::println("--local-directory | -ld - search only folders by name in a local folder");
    std::println();
}

void help::disk() {
    std::println("[--------HELP DISK--------]");
    std::println("disk:");
    std::println("free | free [path] - get free space in disk");
    std::println("du | size | size [path dir] | du [path dir] - size folder");
    std::println();
}

void help::exit() {
    std::println("[--------HELP EXIT--------]");
    std::println("exit:");
    std::println("ex | exit - to exit from console");
    std::println();
}

void help::date() {
    std::println("[--------HELP DATE--------]");
    std::println("date -> output current date");
    std::println("time -> output current time");
    std::println();
}

void help::all() {
    std::println("[---------HELP ALL---------]");
    help::cmd();
    help::path();
    help::history();
    help::clear();
    help::color();
    help::my_commands();
    help::open();
    help::fileDir();
    help::text();
    help::ls();
    help::find();
    help::disk();
    help::exit();
}
