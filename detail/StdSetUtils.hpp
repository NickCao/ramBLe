/**
 * @file StdSetUtils.hpp
 * @brief Implementation of functions for operations on std::set.
 */
#ifndef DETAIL_STDSETUTILS_HPP_
#define DETAIL_STDSETUTILS_HPP_

#include <algorithm>
#include <set>


template <>
std::set<uint8_t>
set_init<std::set<uint8_t>, uint8_t>(
  std::set<uint8_t>&& set,
  const uint8_t
)
{
  return set;
}

template <>
std::set<uint16_t>
set_init<std::set<uint16_t>, uint16_t>(
  std::set<uint16_t>&& set,
  const uint16_t
)
{
  return set;
}

template <>
std::set<uint32_t>
set_init<std::set<uint32_t>, uint32_t>(
  std::set<uint32_t>&& set,
  const uint32_t
)
{
  return set;
}

template <>
bool
set_contains<std::set<uint8_t>, uint8_t>(
  const std::set<uint8_t>& set,
  const uint8_t value
)
{
  return (set.find(value) != set.end());
}

template <>
bool
set_contains<std::set<uint16_t>, uint16_t>(
  const std::set<uint16_t>& set,
  const uint16_t value
)
{
  return (set.find(value) != set.end());
}

template <>
bool
set_contains<std::set<uint32_t>, uint32_t>(
  const std::set<uint32_t>& set,
  const uint32_t value
)
{
  return (set.find(value) != set.end());
}

template <>
std::set<uint8_t>
set_union<std::set<uint8_t>>(
  const std::set<uint8_t>& first,
  const std::set<uint8_t>& second
)
{
  std::set<uint8_t> result;
  std::set_union(first.begin(), first.end(), second.begin(), second.end(), std::inserter(result, result.begin()));
  return result;
}

template <>
std::set<uint16_t>
set_union<std::set<uint16_t>>(
  const std::set<uint16_t>& first,
  const std::set<uint16_t>& second
)
{
  std::set<uint16_t> result;
  std::set_union(first.begin(), first.end(), second.begin(), second.end(), std::inserter(result, result.begin()));
  return result;
}

template <>
std::set<uint32_t>
set_union<std::set<uint32_t>>(
  const std::set<uint32_t>& first,
  const std::set<uint32_t>& second
)
{
  std::set<uint32_t> result;
  std::set_union(first.begin(), first.end(), second.begin(), second.end(), std::inserter(result, result.begin()));
  return result;
}

template <>
std::set<uint8_t>
set_difference<std::set<uint8_t>>(
  const std::set<uint8_t>& first,
  const std::set<uint8_t>& second
)
{
  std::set<uint8_t> result;
  std::set_difference(first.begin(), first.end(), second.begin(), second.end(), std::inserter(result, result.begin()));
  return result;
}

template <>
std::set<uint16_t>
set_difference<std::set<uint16_t>>(
  const std::set<uint16_t>& first,
  const std::set<uint16_t>& second
)
{
  std::set<uint16_t> result;
  std::set_difference(first.begin(), first.end(), second.begin(), second.end(), std::inserter(result, result.begin()));
  return result;
}

template <>
std::set<uint32_t>
set_difference<std::set<uint32_t>>(
  const std::set<uint32_t>& first,
  const std::set<uint32_t>& second
)
{
  std::set<uint32_t> result;
  std::set_difference(first.begin(), first.end(), second.begin(), second.end(), std::inserter(result, result.begin()));
  return result;
}

/**
 * @brief Function for getting the output represention of a set.
 */
template <typename Element>
std::ostream&
operator<<(
  std::ostream& stream,
  const std::set<Element>& set
)
{
  stream << "{";
  for (auto elem: set) {
    stream << static_cast<uint32_t>(elem) << ",";
  }
  if (set.size() > 0) {
    stream << '\b';
  }
  stream << "}";
  return stream;
}

#endif // DETAIL_STDSETUTILS_HPP_
