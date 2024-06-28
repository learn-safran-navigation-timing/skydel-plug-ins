#pragma once

#include <QObject>

#include <chrono>
#include <cstdint>

/* The Skydel Radio Time Observer Interface provides a plugin with information
 * regarding the radio time. This enables a plugin to delay events, such as
 * the transmission of a UDP packet, until approximately when the radio is
 * transmitting corresponding RF.
 *
 * pushPosition may be called up to many milliseconds ahead of corresponding
 * RF transmission depending on buffer and latency settings. pushRadioTime
 * provides the implementer with the information needed to estimate just how
 * far ahead in time the plugin is being called relative to RF transmission.
 *
 * The RadioTimeEstimate contains a recent radio simulation estimated time
 * and a steady_clock timestamp of when that estimate was made. The elapsed
 * time estimate is a double type as it may include a fraction of a second.
 * Time may pass between when that estimate was made and when pushRadioTime
 * or pushPosition are called, so users may have to use steady_clock to
 * estimate how much time has passed between the radio time estimation and
 * their code. The provided helper functions use this strategy.
 *
 * Two helper functions are provided-
 * - getDeadline returns a system time_point for when the RF corresponding
 *   to the given elapsedMs is expected to be broadcast from the radio.
 *
 *   This same deadline can be used in conjunction with the DelayedBroadcaster
 *   in the given example to broadcast a UDP packet at the same time as the RF.
 *
 * - microsecondsUntilRadioTransmission returns an integer number of
 *   microseconds until RF corresponding to the given elapsedMs is expected
 *   to be broadcast from the radio.
 */

class SkydelRuntimeRadioTimeObserver : public QObject
{
public:
  virtual ~SkydelRuntimeRadioTimeObserver() = default;

  struct RadioTimeEstimate
  {
    double radioElapsedTimeMs;
    std::chrono::time_point<std::chrono::steady_clock> osTime;
  };

  virtual void pushRadioTime(const RadioTimeEstimate&) = 0;
  virtual void connectToView(QWidget* view) = 0;

  static std::chrono::time_point<std::chrono::steady_clock> getDeadline(int64_t elapsedMs,
                                                                        const RadioTimeEstimate& recentEstimate)
  {
    const std::chrono::microseconds usIntoFuture(elapsedMs * 1000 -
                                                 static_cast<int64_t>(recentEstimate.radioElapsedTimeMs * 1000));
    const auto estimateOfThisTimedPositionAtRadio = recentEstimate.osTime + usIntoFuture;

    return estimateOfThisTimedPositionAtRadio;
  }

  static int64_t microsecondsUntilRadioTransmission(int64_t elapsedMs, const RadioTimeEstimate& recentEstimate)
  {
    const auto now = std::chrono::steady_clock::now();
    const auto deadline = getDeadline(elapsedMs, recentEstimate);
    const auto estimateOfTimeUntilRfTransmittion = deadline - now;
    const auto usUntilRfTransmission =
      std::chrono::duration_cast<std::chrono::microseconds>(estimateOfTimeUntilRfTransmittion).count();

    return usUntilRfTransmission;
  }
};

class SkydelRadioTimeObserverInterface
{
public:
  virtual ~SkydelRadioTimeObserverInterface() = default;

  virtual SkydelRuntimeRadioTimeObserver* createRuntimeRadioTimeObserver() = 0;

  static constexpr auto ID = "SkydelRadioTimeObserver";
  static constexpr auto VERSION = 1;
};
