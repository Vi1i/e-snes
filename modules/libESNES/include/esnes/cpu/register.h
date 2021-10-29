/**
 * @brief Defines a register class and related functionality
 */

#ifndef ESNES_CPU_REGISTER_H
#define ESNES_CPU_REGISTER_H

#include <esnes/common/types.h>

namespace esnes::cpu {

/**
 * @brief Represents a SNES CPU register
 */
struct Register {
  common::types::byte low;
  common::types::byte high;

  /**
   * @brief Construct a register from a word value
   *
   * NOTE: This deconstructs the word into low and high bytes
   *
   * @param word Initial whole register value
   */
  constexpr Register(common::types::word word) {
    low = w & 0x00ff;
    high = (w >> 8);
  }

  /**
   * @brief Construct a register from a low and high byte
   * @param low_byte the initial low byte value of the register
   * @param high_byte the initial high byte value of the register
   */
  constexpr Register(common::types::byte low_byte,
                     common::types::byte high_byte)
      : low(low_byte), high(high_byte) {}

  /**
   * @brief Set the whole register value
   * @param word the new register value
   */
  constexpr void operator=(common::types::word word) {
    low = word & 0x00ff;
    high = (word >> 8);
  }

  /**
   * @brief Get the register value as a word
   * @return the register value as a common::types::word
   */
  [[nodiscard]] constexpr operator common::types::word() const {
    std::uint16_t value;
    value = low | (high << 8);
    return value;
  }
};

}  // namespace esnes::cpu

#endif  // ESNES_CPU_REGISTER_H
