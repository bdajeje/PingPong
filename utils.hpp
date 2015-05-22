#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>

/*! Takes a input string and ensure it ends with a '/'
 *  \param filepath - to update
 *  \returns returns filepath input with a '/' at the end
 */
std::string ensureDirEnd(std::string filepath);

#endif // UTILS_HPP
