#ifndef VKD3D_ADRENO_QUIRKS_H
#define VKD3D_ADRENO_QUIRKS_H

#include <stdint.h>
#include <stdbool.h>

#define VKD3D_VENDOR_QUALCOMM 0x5143u
#define VKD3D_DEVICE_ADRENO_750 0x0750u

static inline bool vkd3d_is_adreno(uint32_t vendor_id)
{
    return vendor_id == VKD3D_VENDOR_QUALCOMM;
}

#endif
