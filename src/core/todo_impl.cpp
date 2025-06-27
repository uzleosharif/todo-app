
// SPDX-License-Identifier: MIT

module core;

import std;

namespace todo {

auto generate_id() -> std::string {
  std::size_t constexpr kNumBytes{16};

  static thread_local std::mt19937_64 gen{std::random_device{}()};
  std::uniform_int_distribution<std::uint8_t> dist{0, 0xff};

  std::ostringstream oss{};
  oss << std::hex << std::setfill('0');
  for (std::size_t i{0}; i < kNumBytes; ++i) {
    oss << std::setw(2) << static_cast<int>(dist(gen));
  }

  return oss.str();
}

} // namespace todo
