#ifndef VKD3D_ADRENO_QUIRKS_H
#define VKD3D_ADRENO_QUIRKS_H

#include <stdint.h>
#include <stdbool.h>

/* VKD3D_VENDOR_ID_QUALCOMM is defined in vkd3d_private.h.
 * Including this header requires vkd3d_private.h to be included first
 * (which is the case for all current users: device.c, resource.c, swapchain.c). */

static inline bool vkd3d_is_adreno(uint32_t vendor_id)
{
    
    return vendor_id == VKD3D_VENDOR_ID_QUALCOMM;
}

#endif
