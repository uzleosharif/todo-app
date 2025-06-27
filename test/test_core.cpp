

#define CATCH_CONFIG_MAIN

#include <catch2/catch_all.hpp>

import std;
import core.utils;

TEST_CASE("generateId() yields a 32-character lowercase hex string",
          "[generateId]") {
  auto id = todo::generate_id();
  SECTION("length is exactly 32") {
    REQUIRE(id.size() == 32u);
  }
  SECTION("only 0–9,a–f characters") {
    static const std::regex hexRe("^[0-9a-f]{32}$");
    REQUIRE(std::regex_match(id, hexRe));
  }
}

TEST_CASE("generateId() is non-deterministic", "[generateId]") {
  auto a = todo::generate_id();
  auto b = todo::generate_id();
  REQUIRE(a != b);
}

TEST_CASE("generateId() produces no collisions over 10 000 calls",
          "[generateId][stress]") {
  constexpr size_t N = 10'000;
  std::unordered_set<std::string> seen;
  seen.reserve(N);

  for (size_t i = 0; i < N; ++i) {
    auto id = todo::generate_id();
    REQUIRE(seen.emplace(id).second);  // fails if duplicate
  }
  REQUIRE(seen.size() == N);
}
