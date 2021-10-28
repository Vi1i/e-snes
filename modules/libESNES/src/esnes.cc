#include <esnes/esnes.h>

#include <cstdio>
#include <fstream>

namespace esnes {
void esnes() {

  puts("esnes");
}

auto read_rom(const std::filesystem::path& file) -> std::vector<types::byte> {
  std::ifstream instream(file, std::ios::binary);
  return {std::istreambuf_iterator<char>(instream),
          std::istreambuf_iterator<char>()};
}

auto check_smc_header(const std::vector<types::byte>& rom_data) -> smc_state {
  auto smc_size = rom_data.size() % constants::rom_block_size;
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
}

auto remove_smc_header(const std::vector<types::byte>& rom_data)
    -> std::vector<types::byte> {
  return {rom_data.begin() + 512, rom_data.end()};
}

}  // namespace esnes