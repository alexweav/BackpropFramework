#ifndef SRC_UTILS_DICTIONARY_H_
#define SRC_UTILS_DICTIONARY_H_

#include <cstdint>
#include <unordered_map>
#include <memory>

#include "Hash.h"

namespace utils {

    template<typename K, typename V>
    using PtrDictionary = std::unordered_map<K, V, PointerHash<typename std::remove_pointer<K>::type>>;

    template<typename K, typename V>
    using Dictionary = std::unordered_map<std::shared_ptr<K>, V, std::hash<std::shared_ptr<K>>>;

}

#endif  // SRC_UTILS_DICTIONARY_H_
