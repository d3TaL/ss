#
# Copyright (C) 2020 The MoKee/rr Open Source Project
#
# SPDX-License-Identifier: Apache-2.0
#

# Inherit from meizu sdm710-common
-include device/meizu/sdm710-common/BoardConfigCommon.mk

DEVICE_PATH := device/meizu/m1872

# Assertion
TARGET_OTA_ASSERT_DEVICE := m1872,16X

# Bluetooth
BOARD_BLUETOOTH_BDROID_BUILDCFG_INCLUDE_DIR := $(DEVICE_PATH)/bluetooth/include

# Kernel
TARGET_PREBUILT_KERNEL := $(DEVICE_PATH)/prebuilt/Image.gz-dtb
BOARD_KERNEL_SEPARATED_DTBO := true
BOARD_PREBUILT_DTBOIMAGE := $(DEVICE_PATH)/prebuilt/dtbo.img

# HAX: Remove ASAP
BOARD_KERNEL_CMDLINE += androidboot.selinux=permissive

# Properties
TARGET_SYSTEM_PROP += $(DEVICE_PATH)/system.prop

# Releasetools
TARGET_BOARD_INFO_FILE := $(DEVICE_PATH)/board-info.txt

# Soong namespaces
PRODUCT_SOONG_NAMESPACES += $(DEVICE_PATH)

# inherit from the proprietary version
-include vendor/meizu/m1872/BoardConfigVendor.mk
