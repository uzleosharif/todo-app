

// SPDX-License-Identifier: MIT

export module task;

import std;

export namespace todo {

enum class Status { kPending, kDone };

struct Task {
  std::size_t id;
  std::string description;
  Status status{Status::kPending};
  std::chrono::system_clock::time_point created_at;
};

} // namespace todo
