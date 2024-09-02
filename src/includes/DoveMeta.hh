#pragma once

#include <cstdint>

#ifdef __cplusplus
extern "C" {
#endif

struct __attribute__((packed)) DoveFileMetadata {
    size_t file_sz;
};

#ifdef __cplusplus
}
#endif

