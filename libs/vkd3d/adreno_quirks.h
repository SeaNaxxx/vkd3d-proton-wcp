#ifndef VKD3D_ADRENO_QUIRKS_H
#define VKD3D_ADRENO_QUIRKS_H

#include <stdint.h>
#include <stdbool.h>

#define VKD3D_VENDOR_QUALCOMM 0x5143u

static inline bool vkd3d_is_adreno(uint32_t vendor_id)
{
    return vendor_id == VKD3D_VENDOR_QUALCOMM;
}

static inline bool vkd3d_is_adreno_a7xx(uint32_t vendor_id, uint32_t device_id)
{
    return vendor_id == VKD3D_VENDOR_QUALCOMM &&
           device_id >= 0x0700u && device_id < 0x0800u;
}

static inline bool vkd3d_is_adreno_a8xx(uint32_t vendor_id, uint32_t device_id)
{
    return vendor_id == VKD3D_VENDOR_QUALCOMM &&
           device_id >= 0x0800u && device_id < 0x0900u;
}

static inline bool vkd3d_is_adreno_tiler(uint32_t vendor_id)
{
    return vendor_id == VKD3D_VENDOR_QUALCOMM;
}

#endif
