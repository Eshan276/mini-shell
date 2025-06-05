# Mini Shell — A Simple Command Interpreter in C++

## 📌 Overview
**Mini Shell** is a lightweight command-line shell built in C++. It demonstrates key operating system concepts such as:

- **Process management** (via `fork`, `exec`, `wait`)
- **I/O redirection** (`<`, `>`)
- **Command piping** (`|`)
- **Parsing and execution** of basic Linux commands

---

## 🛠️ Features
- ✅ Execute basic Linux commands
- ✅ Handle input/output redirection (e.g., `cat < input.txt`, `ls > out.txt`)
- ✅ Support for command piping (e.g., `ls | grep .cpp`)
- ✅ Graceful handling of invalid commands
- ✅ Modular codebase (divided into `parser`, `executor`, `utils`)

---

## 📁 Project Structure
```
mini-shell/
├── main.cpp              // Shell input loop
├── parser.cpp/hpp        // Tokenize user input
├── executor.cpp/hpp      // Execute commands & manage processes
├── utils.cpp/hpp         // Pipe and redirection helpers
├── Makefile              // For compilation
└── README.md             // Project documentation
```

---

## 🚀 Getting Started

### 📦 Prerequisites
- A Linux or WSL environment
- `g++` compiler (C++17 or above)

### 🧱 Build
```bash
make
```

### ▶️ Run
```bash
./mini_shell
```

---

## 💡 Example Usage
```bash
mini-shell> ls
mini-shell> cat < input.txt
mini-shell> ls | grep .cpp
mini-shell> echo hello > file.txt
mini-shell> exit
```

---

## 🧠 What You Learn
By working with Mini Shell, you will gain insights into:

- Low-level C++ system programming
- Process control using the POSIX API
- Shell-like behavior and piping logic
- Code modularization and effective use of headers