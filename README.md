# CLITE - A Simple Text Editor

CLITE is a basic text editor developed in C that uses the ncurses library to provide a terminal-based interface. It allows users to open, view, and edit text files within the terminal. The project aims to implement core text editing functionalities like file reading, writing, and navigation.

## Features

- Open and view text files.
- Simple text navigation with ncurses interface.
- Designed to work in a terminal environment.

## Requirements

- **C Compiler** (e.g., GCC)
- **CMake** (version 3.10 or higher)
- **ncurses** library for terminal-based UI

## Installation

Installation

1. Clone the repository:

```bash
    git clone https://github.com/username/CLITE.git
```

2. Install dependencies:

- On Linux, you can install the ncurses library using the package manager. For example:

```bash
    sudo apt-get install libncurses5-dev libncursesw5-dev
```

3. Build the project using CMake:

```bash
    mkdir build
    cd build
    cmake ..
    make
```

4. Run the text editor:

- After a successful build, the executable text_editor will be created in the out directory.

```bash
    ./out/text_editor
```
