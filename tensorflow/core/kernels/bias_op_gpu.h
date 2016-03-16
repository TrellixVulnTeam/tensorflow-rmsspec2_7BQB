/* Copyright 2015 Google Inc. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#ifndef TENSORFLOW_CORE_KERNELS_BIAS_OP_GPU_H_
#define TENSORFLOW_CORE_KERNELS_BIAS_OP_GPU_H_

#define EIGEN_USE_GPU

#include "third_party/eigen3/unsupported/Eigen/CXX11/Tensor"
#include "tensorflow/core/framework/tensor_types.h"
#include "tensorflow/core/util/tensor_format.h"

namespace tensorflow {

typedef Eigen::GpuDevice GPUDevice;

template <typename T>
struct BiasGPU {
  static void compute(const GPUDevice& d, const T* input, const T* bias,
                      T* output, int32 batch, int32 height, int32 width,
                      int32 channel, TensorFormat data_format);
};

template <typename T>
struct BiasGradGPU {
  static void compute(const GPUDevice& device, const T* output_backprop,
                      T* bias_backprop, int32 batch, int32 height, int32 width,
                      int32 channel, TensorFormat data_format);
};

}  // namespace tensorflow

#endif  // TENSORFLOW_CORE_KERNELS_BIAS_OP_GPU_H_
