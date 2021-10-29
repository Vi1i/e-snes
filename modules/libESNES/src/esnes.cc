#include <esnes/common/constants.h>
#include <esnes/common/types.h>
#include <esnes/esnes.h>
#include <esnes/version.h>

#include <cstdio>
#include <fstream>

namespace esnes {
auto test_func() -> std::string { return meta::version_string; }

auto read_rom(const std::filesystem::path& file)
    -> std::vector<common::types::byte> {
  std::ifstream instream(file, std::ios::binary);
  return {std::istreambuf_iterator<char>(instream),
          std::istreambuf_iterator<char>()};
}

auto check_smc_header(const std::vector<common::types::byte>& rom_data)
    -> smc_state {
  auto smc_size = rom_data.size() % common::constants::rom_block_size;
  if (rom_data.size() < 1024) {
    return smc_state::malformed;
  }

  switch (smc_size) {
    case 0: {
      return smc_state::none;
    }
    case 512: {
      return smc_state::exists;
    }
    default:
      return smc_state::malformed;
  }
  return smc_state::malformed;
}

auto remove_smc_header(const std::vector<common::types::byte>& rom_data)
    -> std::vector<common::types::byte> {
  return {rom_data.begin() + 512, rom_data.end()};
}

}  // namespace esnes
