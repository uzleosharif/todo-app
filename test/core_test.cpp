
// SPDX-License-Identifier: MIT

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>

import std;

namespace todo {

auto generate_id() -> std::string {}

} // namespace todo

TEST_CASE("generate_id(): 32-char lowercase hex", "[generate_id]") {
  // TODO(uzleo)
}

TEST_CASE("generate_id(): two back-to-back calls differ", "[generate_id]") {
  // TODO(uzleo)
}

TEST_CASE("generate_id(): no collisions over 10000 calls",
          "[generate_id][stress]") {
  // TODO(uzleo)
}
