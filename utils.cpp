#include "utils.hpp"

std::string ensureDirEnd(std::string filepath)
{
  return (filepath.back() == '/') ? filepath : filepath + '/';
}
