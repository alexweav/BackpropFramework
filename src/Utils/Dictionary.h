#ifndef SRC_UTILS_DICTIONARY_H_
#define SRC_UTILS_DICTIONARY_H_

#include <cstdint>
#include <unordered_map>
#include <memory>
#include "Datatypes.h"

namespace utils {

template<typename T>
struct PointerHash {
    inline size_t operator() (const T* ptr) const {
        auto addr = reinterpret_cast<uintptr_t>(ptr);
#if SIZE_MAX < UINTPTR_MAX
        addr %= SIZE_MAX;
#endif
        return addr;
    }
};

template<typename K, typename V>
using Dictionary = std::unordered_map<K, V, PointerHash<typename std::remove_pointer<K>::type>>;

}   // namespace utils

template<typename K, typename V>
using SharedDictionary = std::unordered_map<std::shared_ptr<K>, V, std::hash<std::shared_ptr<K>>>;

#endif  // SRC_UTILS_DICTIONARY_H_
