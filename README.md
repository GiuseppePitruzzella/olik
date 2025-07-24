<br />
<div align="center">
  <a href="https://github.com/GiuseppePitruzzella/olik">
    <img src="assets/images/logo.png" alt="Logo" width="300">
  </a>

  <h3 align="center">Olik Text Editor</h3>

  <p align="center">
    <i>A minimal text editor written in C from scratch.</i>
    <br />
    <a href="https://github.com/GiuseppePitruzzella/olik/issues">Report Bug</a>
    ·
    <a href="https://github.com/GiuseppePitruzzella/olik/issues">Request Feature</a>
  </p>
</div>

## 📘 Project Overview

This project is a personal exercise in C programming, focused on building a minimal, console-based text editor inspired by **`antirez's kilo`**. The primary goal is to understand low-level terminal handling, file I/O, and data structure manipulation in C.

The editor is built from scratch with no external dependencies and includes core features like syntax highlighting and a search function.

***

## ⚙️ How to Compile and Run

This project is written in C and requires a C compiler like **`gcc`** to build.

1.  Clone the repository:
    ```bash
    git clone [https://github.com/GiuseppePitruzzella/olik.git](https://github.com/GiuseppePitruzzella/olik.git)
    cd olik
    ```
2.  Compile the source code:
    ```bash
    make
    ```
3.  Run the editor:
    ```bash
    ./olik
    ```
    You can also open a specific file:
    ```bash
    ./kilo my_file.txt
    ```

***

## ✨ Features

The editor implements all the basic features you expect, including:

* **Dependency-Free Build**: Compiles with a standard C compiler.
* **Terminal Raw Mode**: Processes keypresses instantly for a responsive UI.
* **Text Viewing and Editing**: Full cursor navigation and text modification.
* **Search**: Incremental search functionality.
* **Syntax Highlighting**: Basic highlighting for C code.

***

## 📁 Project Structure

The project is intentionally kept minimal, with the core logic in a single file.

```bash
olik/
├── assets/
│   └── images/
│       └── logo.png         # Project logo
├── kilo.c                   # Main C source file
├── .gitignore
├── LICENSE.txt
└── README.md