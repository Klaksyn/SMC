
| <a href="README_ru.md">ru</a> | <a href="README_en.md">en</a> |

# Help

This document describes all commands available in the console.

---

# CMD

Start Windows Command Prompt.

## Syntax

```text
cmd
```

Start the Windows Command Prompt.

```text
cmd <command>
```

Execute a Windows CMD command.

---

# Date & Time

Display the current date.

```text
date
```

Display the current time.

```text
time
```

---

# Path

Commands for working with the current directory.

## Change directory

```text
cd <directory>
```

Change the current directory.

```text
cd !$
```

Change to the last listed directory.

```text
cd -p <number>
```

Change to a directory by its index.

## Current directory

```text
pwd
```

Display the current working directory.

## Path visibility

```text
path --show
path -s
```

Show the current path.

```text
path --hide
path -h
```

Hide the current path.

---

# Command History

Display the command history.

```text
history
```

Search the command history.

```text
history --search
history -s
```

or

```text
history -h-s
history --history_search
```

Save the command history to a text file.

```text
history --save
history -sv
```

---

# Clear Console

Clear the console screen.

```text
clear
```

or

```text
cls
```

---

# Console Colors

Display all available console colors.

```text
help --color
```

Available color names:

| Color |
|-------|
| dark_red |
| red |
| dark_green |
| green |
| dark_blue |
| blue |
| dark_cyan |
| cyan |
| brown |
| dark_gray |
| gray |
| magenta |
| yellow |
| white |
| default |
| def |

---

# Custom Commands

## Create

```text
mkcommand <name> <action>
```

or

```text
mkcmd <name> <action>
```

Create a custom command.

---

## Rename

```text
change-command <old_command> <new_command>
```

or

```text
chcmd <old_command> <new_command>
```

Rename an existing command.

---

## Change action

```text
change-action <command> <new_action>
```

or

```text
chact <command> <new_action>
```

Change the action associated with a command.

---

## Delete

```text
del-command <command>
```

or

```text
delcmd <command>
```

Delete a custom command.

---

## Run

```text
run-command <command>
```

or

```text
rnc <command>
rc <command>
rn <command>
```

Execute a custom command.

---

# Open

Open a directory in File Explorer.

```text
explorer
explr
exp
openf
```

Open the current directory.

```text
explorer <path>
```

Open the specified directory.

Run any executable or supported file.

```text
run <file>
```

Example:

```text
run D:\t.txt
```

---

# Files & Directories

## Create a file

```text
touch <filename>
```

Example:

```text
touch notes.txt
```

---

## Create a directory

```text
mkdir <directory>
```

Example:

```text
mkdir Projects
```

---

## Rename

```text
ren <old_name> <new_name>
rnm <old_name> <new_name>
rename <old_name> <new_name>
```

Rename a file or directory.
You can also specify full paths

---

## Delete

```text
del <path>
delete <path>
remove <path>
rmv <path>
```

Delete a file or directory.

---

## Copy

```text
copy <source> <destination>
```

or

```text
cp <source> <destination>
```

Copy a file or directory.

If only the destination is specified, the current directory is used as the source.

Example:

```text
cp D:\Backup
```

---

## Move

```text
move <source> <destination>
```

Move a file or directory.

---

# Text Files

## Read

```text
read <file>
```

or

```text
cat <file>
```

Display the contents of a readable file.

---

## Write

```text
echo --write <text>
```

or

```text
echo -w <text>
```

Write text to a file.

---

## Rewrite

```text
echo --rewrite <text>
```

or

```text
echo -rw <text>
```

Overwrite a file with new text.

---

## Multiple lines

```text
echoln <file>
```

Write multiple lines to a file.

```text
echoln-rw <file>
```

Overwrite a file with multiple lines.

---

# List Files

Display files and directories.

```text
ls
```

You can change directories by index.

```text
cd -p <number>
```

Other listing commands:

```text
open
```

List files and directories on supported operating systems.

```text
dir
```

List files and directories on Windows.

---

# Find

Search for files or directories.

## Syntax

```text
find <option> <name>
```

### Options

| Option | Description |
|---------|-------------|
| `-g` | Search files and directories across the entire system |
| `-gf` | Search only files across the entire system |
| `-gd` | Search only directories across the entire system |
| `-l` | Search files and directories in the current directory |
| `-lf` | Search only files in the current directory |
| `-ld` | Search only directories in the current directory |

Long options:

| Option |
|---------|
| `--global` |
| `--global-file` |
| `--global-directory` |
| `--local` |
| `--local-file` |
| `--local-directory` |

---

# Disk

Display available disk space.

```text
free
```

or

```text
free <path>
```

Display the size of a directory.

```text
du <directory>
```

or

```text
size <directory>
```

---

# Exit

Exit the console.

```text
exit
```

or

```text
ex
```

---

# Show All Help

Display every help topic.

```text
help --all
```

## Credits & Third-Party Libraries

This project uses the following third-party software:

* **JSON for Modern C++** (v3.12.0) — [GitHub Repository](https://github.com/nlohmann/json)
    * SPDX-FileCopyrightText: 2013 - 2025 Niels Lohmann <https://nlohmann.me>
    * SPDX-License-Identifier: MIT
