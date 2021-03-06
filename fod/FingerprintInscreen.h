/*
 * Copyright (C) 2019 The LineageOS Project
 * Copyright (C) 2020 The MoKee Open Source Project
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 */

#ifndef VENDOR_LINEAGE_BIOMETRICS_FINGERPRINT_INSCREEN_V1_1_FINGERPRINTINSCREEN_H
#define VENDOR_LINEAGE_BIOMETRICS_FINGERPRINT_INSCREEN_V1_1_FINGERPRINTINSCREEN_H

#include <vendor/lineage/biometrics/fingerprint/inscreen/1.1/IFingerprintInscreen.h>
#include <vendor/synaptics/fingerprint/interfaces/extensions/1.0/ISteller.h>
#include <vendor/synaptics/fingerprint/interfaces/extensions/1.0/IStellerClientCallback.h>
#include <vendor/goodix/hardware/biometrics/fingerprint/2.1/IGoodixFingerprintDaemon.h>

namespace vendor {
namespace lineage {
namespace biometrics {
namespace fingerprint {
namespace inscreen {
namespace V1_1 {
namespace implementation {

using ::android::sp;
using ::android::hardware::Return;
using ::android::hardware::Void;
using ::android::hardware::hidl_vec;

using ::vendor::lineage::biometrics::fingerprint::inscreen::V1_0::IFingerprintInscreenCallback;
using ::vendor::synaptics::fingerprint::interfaces::extensions::V1_0::ISteller;
using ::vendor::synaptics::fingerprint::interfaces::extensions::V1_0::IStellerClientCallback;
using ::vendor::goodix::hardware::biometrics::fingerprint::V2_1::IGoodixFingerprintDaemon;

class FingerprintInscreen : public IFingerprintInscreen {
  public:
    FingerprintInscreen();

    Return<int32_t> getPositionX() override;
    Return<int32_t> getPositionY() override;
    Return<int32_t> getSize() override;
    Return<void> onStartEnroll() override;
    Return<void> onFinishEnroll() override;
    Return<void> onPress() override;
    Return<void> onRelease() override;
    Return<void> onShowFODView() override;
    Return<void> onHideFODView() override;
    Return<bool> handleAcquired(int32_t acquiredInfo, int32_t vendorCode) override;
    Return<bool> handleError(int32_t error, int32_t vendorCode) override;
    Return<void> setLongPressEnabled(bool enabled) override;
    Return<int32_t> getDimAmount(int32_t cur_brightness) override;
    Return<bool> shouldBoostBrightness() override;
    Return<int32_t> getHbmOffDelay() override;
    Return<int32_t> getHbmOnDelay() override;
    Return<bool> supportsAlwaysOnHBM() override;
    Return<void> switchHbm(bool enabled) override;
    Return<bool> noDim() override;
    Return<void> setCallback(const sp<IFingerprintInscreenCallback>& callback) override;

  private:
    sp<ISteller> mSteller;
    sp<IStellerClientCallback> mStellerClientCallback;

    int32_t mDC;
    int32_t mHBM;
    int32_t mHBMCheckOn;
    int32_t mHBMCheckOff;

    bool mFingerPressed;

    std::string mFODModel;

    void notifyHal(int32_t status, int32_t data);
};

}  // namespace implementation
}  // namespace V1_1
}  // namespace inscreen
}  // namespace fingerprint
}  // namespace biometrics
}  // namespace lineage
}  // namespace vendor

#endif  // VENDOR_LINEAGE_BIOMETRICS_FINGERPRINT_INSCREEN_V1_1_FINGERPRINTINSCREEN_H
