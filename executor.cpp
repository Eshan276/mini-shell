#include "executor.hpp"
#include "utils.hpp"
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <iostream>

void run_command(std::vector<std::string> args) {
    std::string inFile, outFile;
    check_redirection(args, inFile, outFile);

    std::vector<char*> c_args;
    for (auto& arg : args) c_args.push_back(const_cast<char*>(arg.c_str()));
    c_args.push_back(nullptr);

    if (fork() == 0) {
        if (!inFile.empty()) {
            int in = open(inFile.c_str(), O_RDONLY);
            if (in < 0) { perror("open input"); exit(1); }
            dup2(in, STDIN_FILENO);
            close(in);
        }

        if (!outFile.empty()) {
            int out = open(outFile.c_str(), O_WRONLY | O_CREAT | O_TRUNC, 0644);
            if (out < 0) { perror("open output"); exit(1); }
            dup2(out, STDOUT_FILENO);
            close(out);
        }

        execvp(c_args[0], c_args.data());
        perror("execvp failed");
        exit(1);
    } else {
        wait(nullptr);
    }
}

void run_pipe_command(std::vector<std::string> cmd1, std::vector<std::string> cmd2) {
    int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("pipe");
        return;
    }

    if (fork() == 0) {
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[0]);
        close(pipefd[1]);
        run_command(cmd1);
        exit(0);
    }

    if (fork() == 0) {
        dup2(pipefd[0], STDIN_FILENO);
        close(pipefd[1]);
        close(pipefd[0]);
        run_command(cmd2);
        exit(0);
    }

    close(pipefd[0]);
    close(pipefd[1]);
    wait(nullptr);
    wait(nullptr);
}
