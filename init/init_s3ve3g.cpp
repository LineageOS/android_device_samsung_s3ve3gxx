/*
   Copyright (c) 2016, The Linux Foundation. All rights reserved.
   Copyright (c) 2017-2020, The LineageOS Project. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


#include <android-base/logging.h>
#include <android-base/properties.h>

#include "property_service.h"

#include "init_msm8226.h"

using android::base::GetProperty;
using android::init::property_set;

void vendor_load_properties()
{
    std::string bootloader = GetProperty("ro.bootloader", "");

    if (bootloader.find("I9301I") == 0) {
        /* s3ve3gxx */
        property_override("ro.build.description", "s3ve3gds-user 4.4.2 KOT49H I9301IXXUANL1 release-keys");
        set_ro_product_prop("device", "s3ve3gxx");
        set_ro_build_prop("fingerprint", "samsung/s3ve3gxx/s3ve3g:4.4.2/KOT49H/I9301IXXUANL1:user/release-keys");
        set_ro_product_prop("model", "GT-I9301I");
        set_ro_product_prop("name", "s3ve3gxx");
        gsm_properties("3", "0");
    } else if (bootloader.find("I9301Q") == 0) {
        /* s3ve3gjv */
        property_override("ro.build.description", "samsung/s3ve3gjv/s3ve3g:4.4.2/KOT49H/I9301QXXUANH1:user/release-keys");
        set_ro_product_prop("device", "s3ve3gjv");
        set_ro_build_prop("fingerprint", "samsung/s3ve3gjv/s3ve3g:4.4.2/KOT49H/I9301QXXUANH1:user/release-keys");
        set_ro_product_prop("model", "GT-I9301Q");
        set_ro_product_prop("name", "s3ve3gjv");
        gsm_properties("3", "0");
    } else if (bootloader.find("I9300I") == 0) {
        /* s3ve3gdsds */
        property_override("ro.build.description", "s3ve3gdsxx-user 4.4.4 KTU84P I9300IXWUBNJ1 release-keys");
        set_ro_product_prop("device", "s3ve3gds");
        set_ro_build_prop("fingerprint", "samsung/s3ve3gdsxx/s3ve3gds:4.4.4/KTU84P/I9300IXWUBNJ1:user/release-keys");
        set_ro_product_prop("model", "GT-I9300I");
        set_ro_product_prop("name", "s3ve3gds");
        gsm_properties("3", "0");
    } else {
        gsm_properties("3", "0");
    }

    std::string device = GetProperty("ro.product.device", "");
    LOG(ERROR) << "Found bootloader id " << bootloader <<  " setting build properties for "
        << device <<  " device" << std::endl;
}
