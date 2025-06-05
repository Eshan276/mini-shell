#include "utils.hpp"
#include <algorithm>

bool contains_pipe(const std::vector<std::string>& args,
                   std::vector<std::string>& cmd1,
                   std::vector<std::string>& cmd2) {
    auto it = std::find(args.begin(), args.end(), "|");
    if (it != args.end()) {
        cmd1 = std::vector<std::string>(args.begin(), it);
        cmd2 = std::vector<std::string>(it + 1, args.end());
        return true;
    }
    return false;
}

bool check_redirection(std::vector<std::string>& args,
                       std::string& inFile,
                       std::string& outFile) {
    for (size_t i = 0; i < args.size(); ++i) {
        if (args[i] == ">") {
            if (i + 1 < args.size()) {
                outFile = args[i + 1];
                args.erase(args.begin() + i, args.begin() + i + 2);
                --i;
            }
        } else if (args[i] == "<") {
            if (i + 1 < args.size()) {
                inFile = args[i + 1];
                args.erase(args.begin() + i, args.begin() + i + 2);
                --i;
            }
        }
    }
    return !inFile.empty() || !outFile.empty();
}
