#ifndef SRC_UTILS_HASH_H_
#define SRC_UTILS_HASH_H_

namespace utils {

    inline size_t HashCombine(const size_t& val1, const size_t& val2) {
        return val1 ^ (val2 + 0x9e3779b9 + (val1<<6) + (val1>>2));
    }

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
}

#endif  // SRC_UTILS_HASH_H_
