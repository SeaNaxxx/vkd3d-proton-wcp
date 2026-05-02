# Adreno optimizations

This branch adds runtime-gated Adreno paths for Qualcomm Adreno 750 with Turnip on Android emulator stacks.

## Adreno detection

- File: `libs/vkd3d/adreno_quirks.h`
- Adds Qualcomm and Adreno 750 identifiers and a vendorID predicate for Adreno runtime checks.
- Upstream reference: local fork integration point.

## Device queue and render-pass behavior

- File: `libs/vkd3d/device.c`
- Aliases the transfer queue family to the compute queue family on Adreno to avoid transfer-only queue paths.
- Removes Turnip from the relaxed load/store compatibility path.
- Enables the QCOM render-pass shader resolve capability only when the Adreno vendorID path and the device extension are both present.
- Upstream references: issue #2950, PR #2915.

## Integer blend handling

- File: `libs/vkd3d/state.c`
- Force-disables blending for integer render targets instead of rejecting pipeline creation.
- Upstream reference: local Adreno hang mitigation.

## Resource alignment

- File: `libs/vkd3d/resource.c`
- Clamps sub-64 KiB placement alignment values to the default resource placement alignment and soft-fails buffer alignment validation on Adreno after warning.
- Upstream reference: issue #2927.

## Swapchain present path

- File: `libs/vkd3d/swapchain.c`
- Removes transfer-destination swapchain image usage on Adreno.
- Forces the render-pass present path by disabling the blit-command path on Adreno.
- Upstream reference: local tiled-GPU present optimization.

## Submission diagnostics

- File: `libs/vkd3d/command.c`
- Downgrades selected non-fatal submit and signal diagnostics from errors to warnings without changing return values or control flow.
- Upstream reference: local Android emulator stability tuning.

## Build option

- File: `meson_options.txt`
- Adds the `adreno_optimizations` Meson option for downstream configuration.
- Upstream reference: local fork configuration.

## Vulkan profile

- File: `VP_D3D12_VKD3D_PROTON_profile.json`
- Adds an optional Adreno capability block for QCOM shader resolve, fragment shader interlock, fragment shading rate, and Qualcomm vendorID matching.
- Upstream reference: local profile extension.
