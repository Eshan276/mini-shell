#include <iostream>
#include "parser.hpp"
#include "executor.hpp"
#include "utils.hpp"

int main() {
    std::string input;
    while (true) {
        std::cout << "mini-shell> ";
        std::getline(std::cin, input);
        if (input.empty()) continue;
        if (input == "exit") break;

        auto args = parse_input(input);
        if (!args.empty()) {
            std::vector<std::string> left, right;
            if (contains_pipe(args, left, right)) {
                run_pipe_command(left, right);
            } else {
                run_command(args);
            }
        }
    }
    return 0;
}
