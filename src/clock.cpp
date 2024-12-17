#include "../include/clock.hpp"

uint64_t clock::current_micros() {
  const uint64_t high = *TIMER_COUNTER_HIGH;
  const uint64_t low = *TIMER_COUNTER_LOW;

  return (high << 32) | low;
}

uint64_t clock::random_range(uint64_t min, uint64_t max) {
  const uint64_t range = max - min;
  const uint64_t seed =
      ((RAND_MULTIPLIER * current_micros()) + RAND_INCREMENT) % RAND_MAX;

  return min + (seed % range);
}