#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <cstdint>
#include <unordered_map>
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
}

#endif
