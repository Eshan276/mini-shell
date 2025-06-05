#pragma once
#include <vector>
#include <string>

bool contains_pipe(const std::vector<std::string>& args,
                   std::vector<std::string>& cmd1,
                   std::vector<std::string>& cmd2);

bool check_redirection(std::vector<std::string>& args,
                       std::string& inFile,
                       std::string& outFile);
