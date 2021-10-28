#include <esnes/esnes.h>
#include <esnes/version.h>

#include <cstdio>
#include <cstdlib>

namespace esnes {
auto esnes() -> std::string { return meta::version_string; }
}  // namespace esnes
