#include "logger.h"
#include <fmt/format.h>

TimeTracker::TimeTracker(const std::string &m) : msg(m) {
  tStart = std::chrono::steady_clock::now();
  LOG_INFO("{} started.", msg));
}

TimeTracker::~TimeTracker() {
  auto ts = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - tStart);
  LOG_INFO("{} completed. Elapsed {} ms.", msg, ts.count()));
}
