#include "logger.h"
#include <fmt/format.h>

TimeTracker::TimeTracker(const std::string &m) : msg(m) {
  tStart = std::chrono::steady_clock::now();
  ShowLog(fmt::format("{} started.", msg));
}

TimeTracker::~TimeTracker() {
  auto ts = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - tStart);
  ShowLog(fmt::format("{} completed. Elapsed {} ms.", msg, ts.count()));
}
