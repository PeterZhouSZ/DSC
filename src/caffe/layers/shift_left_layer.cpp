// ------------------------------------------------------------------
// Copyright (c) 2017
// The Chinese University of Hong Kong
// Written by Hu Xiaowei
//
// ShiftLeftLayer shift the feature map
// ------------------------------------------------------------------

#include <vector>
#include <iostream>

#include "caffe/layers/shift_left_layer.hpp"
#include "caffe/util/math_functions.hpp"

using namespace std;

namespace caffe {

template <typename Dtype>
void ShiftLeftLayer<Dtype>::LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {

  ShiftParameter shift_parameter = this->layer_param_.shift_param();
  CHECK_GT(shift_parameter.stride(), 0)
      << "stride must be > 0";

  stride = shift_parameter.stride();
  LOG(INFO) << "stride: " << stride;

  channels_ = bottom[0]->channels();
  height_ = bottom[0]->height();
  width_ = bottom[0]->width();
}

template <typename Dtype>
void ShiftLeftLayer<Dtype>::Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {


   top[0]->Reshape(bottom[0]->shape(0), channels_, height_, width_);

}

template <typename Dtype>
void ShiftLeftLayer<Dtype>::Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {
  
  NOT_IMPLEMENTED;
  
  //Dtype* top_data[4];
  //const Dtype* bottom_data[1];

  //for (int i=0; i<4; i++)
  //{
  //    top_data[i] = top[i]->mutable_cpu_data();
  //}
  //bottom_data[0] = bottom[0]->cpu_data();
 
}

template <typename Dtype>
void ShiftLeftLayer<Dtype>::Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {
  NOT_IMPLEMENTED;
}

#ifdef CPU_ONLY
STUB_GPU(ShiftLeftLayer);
#endif

INSTANTIATE_CLASS(ShiftLeftLayer);
REGISTER_LAYER_CLASS(ShiftLeft);

}  // namespace caffe
