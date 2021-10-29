#ifndef ESNES_ESNES_H
#define ESNES_ESNES_H

#include <cstdint>
#include <filesystem>
#include <vector>

namespace esnes {
auto test_func() -> std::string;

namespace constants {
static constexpr const auto smc_header_size{512u};
static constexpr const auto rom_block_size{1024u};
}  // namespace constants

namespace types {
using byte = std::uint8_t;
using signed_byte = std::int8_t;
using word = std::uint16_t;
using signed_word = std::int16_t;
}  // namespace types

enum class smc_state { exists, none, malformed };

/**
 * @brief Read a rom into a byte buffer
 *
 * NOTE: As of right now, this function *does not* warn if the file extension is
 * not sfc
 *
 * @param file path to rom file
 * @return a vector of byte data representing an sfc rom file
 */
auto read_rom(const std::filesystem::path& file) -> std::vector<types::byte>;

/**
 * @brief Check the state of a rom's smc header
 *
 * NOTE: It would most likely be impossible to determine if a rom with only part
 * of the smc header could still be valid so this will be considered malformed
 *
 * @param rom_data a vector of byte data representing an sfc rom file
 * @return smc_state::exists if the smc header exists normally with size 512
 * bytes
 * @return smc_state::none if the smc header does not exist
 * @return smc_state::malformed in any other case
 */
auto check_smc_header(const std::vector<types::byte>& rom_data) -> smc_state;

/**
 * @brief Remove the smc header from a rom data buffer
 *
 * NOTE: This function assumes that the user already checked that the smc header
 * exists
 *
 * @param rom_data a vector of byte data representing an sfc rom file
 * @return the rom data with the sfc header removed
 */
auto remove_smc_header(std::vector<types::byte> rom_data)
    -> std::vector<types::byte>;

}  // namespace esnes

#endif  // ESNES_ESNES_H
