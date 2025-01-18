#ifndef GITATTRIBUTES_GENERATOR_HPP
#define GITATTRIBUTES_GENERATOR_HPP

#include <string>
#include <unordered_set>

void generateGitattributes(const std::unordered_set<std::string> &extensions);

#endif
