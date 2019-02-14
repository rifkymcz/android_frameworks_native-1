/*
 * Copyright (C) 2017 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#define LOG_NDEBUG 0
#undef LOG_TAG
#define LOG_TAG "LayerBE"
#define ATRACE_TAG ATRACE_TAG_GRAPHICS

#include "Layer.h"

namespace android {

LayerBE::LayerBE(Layer* layer, std::string layerName) : mLayer(layer) {
    compositionInfo.layer = std::make_shared<LayerBE>(*this);
    compositionInfo.layerName = layerName;
}

LayerBE::LayerBE(const LayerBE& layer) : mLayer(layer.mLayer) {
    compositionInfo.layer = layer.compositionInfo.layer;
    compositionInfo.layerName = layer.mLayer->getName().string();
}

void LayerBE::onLayerDisplayed(const sp<Fence>& releaseFence) {
    mLayer->onLayerDisplayed(releaseFence);
}

}; // namespace android
