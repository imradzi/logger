#pragma once
#include "logging.hpp"
class Logger : public DB::Logger {
public:
  static void InitializeLogger(const std::string &logName) {DB::Logger::initialize(logName); }
};

inline void wpLogMessage(const std::string &s) { LOG_INFO(s); }
inline bool LOG_INFO(const std::string &t) {LOG_INFO(t); return true; }

inline bool LOG_INFO(const std::string &str) {LOG_INFO(str); return true; }

class TimeTracker {
  std::chrono::steady_clock::time_point tStart;
  std::string msg;

public:
  TimeTracker(const std::string &m);
  ~TimeTracker();
};
