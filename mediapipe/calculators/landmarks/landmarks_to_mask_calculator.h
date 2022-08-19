// Copyright 2020 The MediaPipe Authors.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
#ifndef MEDIAPIPE_CALCULATORS_UTIL_LANDMARKS_TO_MASK_CALCULATOR_H_
#define MEDIAPIPE_CALCULATORS_UTIL_LANDMARKS_TO_MASK_CALCULATOR_H_

#include "absl/strings/str_cat.h"
#include "absl/strings/str_join.h"
#include "mediapipe/framework/calculator_framework.h"
#include "mediapipe/framework/calculator_options.pb.h"
#include "mediapipe/framework/formats/landmark.pb.h"
#include "mediapipe/framework/formats/location_data.pb.h"
#include "mediapipe/framework/formats/image_format.pb.h"
#include "mediapipe/framework/formats/image_frame.h"
#include "mediapipe/framework/formats/image_frame_opencv.h"
#include "mediapipe/framework/port/opencv_core_inc.h"
#include "mediapipe/framework/port/opencv_imgproc_inc.h"

namespace mediapipe
{

    // A calculator that uses face landmarks to create face part masks and facebox for
    // visualization. The input should be LandmarkList proto and ImageFrame.
    //
    // Example config:
    // node {
    //   calculator: "LandmarksToMaskCalculator"
    //   input_stream: "IMAGE:image"
    //   input_stream: "NORM_LANDMARKS:face_landmarks"
    //   output_stream: "FACEBOX:face_box"
    //   output_stream: "MASK:mask"
    // }

    std::unordered_map<std::string, const std::vector<int>> orderList = {
        {"UPPER_LIP", {61, 185, 40, 39, 37, 0, 267, 269, 270, 409, 291, 308, 415, 310, 311, 312, 13, 82, 81, 80, 191, 78}},
        {"LOWER_LIP", {61, 78, 95, 88, 178, 87, 14, 317, 402, 318, 324, 308, 291, 375, 321, 405, 314, 17, 84, 181, 91, 146}},
        {"FACE_OVAL", {10, 338, 338, 297, 297, 332, 332, 284, 284, 251, 251, 389, 389, 356, 356, 454, 454, 323, 323, 361, 361, 288, 288, 397, 397, 365, 365, 379, 379, 378, 378, 400, 400, 377, 377, 152, 152, 148, 148, 176, 176, 149, 149, 150, 150, 136, 136, 172, 172, 58, 58, 132, 132, 93, 93, 234, 234, 127, 127, 162, 162, 21, 21, 54, 54, 103, 103, 67, 67, 109, 109, 10}},
        {"MOUTH_INSIDE", {78, 191, 80, 81, 13, 312, 311, 310, 415, 308, 324, 318, 402, 317, 14, 87, 178, 88, 95}},
        {"LEFT_EYE", {130, 33, 246, 161, 160, 159, 157, 173, 133, 155, 154, 153, 145, 144, 163, 7}},
        {"RIGHT_EYE", {362, 398, 384, 385, 386, 387, 388, 466, 263, 249, 390, 373, 374, 380, 381, 382}},
        {"LEFT_BROW", {70, 63, 105, 66, 107, 55, 65, 52, 53, 46}},
        {"RIGHT_BROW", {336, 296, 334, 293, 301, 300, 283, 282, 295, 285}},
        {"LIPS", {61, 185, 40, 39, 37, 0, 267, 269, 270, 409, 291, 375, 321, 405, 314, 17, 84, 181, 91, 146}},
        {"PART_FOREHEAD_B", {21, 54, 103, 67, 109, 10, 338, 297, 332, 284, 251, 301, 293, 334, 296, 336, 9, 107, 66, 105, 63, 71}},
    };

    class LandmarksToMaskCalculator : public CalculatorBase
    {
    public:
        LandmarksToMaskCalculator() = default;
        ~LandmarksToMaskCalculator() override = default;
        LandmarksToMaskCalculator(const LandmarksToMaskCalculator &) =
            delete;
        LandmarksToMaskCalculator &operator=(
            const LandmarksToMaskCalculator &) = delete;

        static absl::Status GetContract(CalculatorContract *cc);

        absl::Status Open(CalculatorContext *cc) override;

        absl::Status Process(CalculatorContext *cc) override;

    private:
        absl::Status RenderToCpu(CalculatorContext *cc,
                                 std::unordered_map<std::string, cv::Mat> &all_masks);

        absl::Status GetFaceBox(CalculatorContext *cc);

        absl::Status GetMasks(CalculatorContext *cc, std::unordered_map<std::string, cv::Mat> &all_masks);

        absl::Status CreateRenderTargetCpu(
            CalculatorContext *cc, std::unique_ptr<cv::Mat> &image_mat,
            ImageFormat::Format *target_format);
    };

} // namespace mediapipe
#endif // MEDIAPIPE_CALCULATORS_UTIL_LANDMARKS_TO_MASK_CALCULATOR_H_
