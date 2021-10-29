#ifdef esnes_cpu_register_h
#define esnes_cpu_register_h

#include <esnes/common/types.h>

namespace esnes::cpu {
union Register {
  common::types::word word;

  struct {
    common::types::byte low;
    common::types::byte high;
  };
};
}  // namespace esnes::cpu

#endif
