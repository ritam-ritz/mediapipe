workspace(name = "mediapipe")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

# Protobuf expects an //external:python_headers target
bind(
    name = "python_headers",
    actual = "@local_config_python//:python_headers",
)

http_archive(
    name = "bazel_skylib",
    type = "tar.gz",
    urls = [
        "https://github.com/bazelbuild/bazel-skylib/releases/download/1.0.3/bazel-skylib-1.0.3.tar.gz",
        "https://mirror.bazel.build/github.com/bazelbuild/bazel-skylib/releases/download/1.0.3/bazel-skylib-1.0.3.tar.gz",
    ],
    sha256 = "1c531376ac7e5a180e0237938a2536de0c54d93f5c278634818e0efc952dd56c",
)
load("@bazel_skylib//:workspace.bzl", "bazel_skylib_workspace")
bazel_skylib_workspace()
load("@bazel_skylib//lib:versions.bzl", "versions")
versions.check(minimum_bazel_version = "3.7.2")

# ABSL cpp library lts_2021_03_24, patch 2.
http_archive(
    name = "com_google_absl",
    urls = [
        "https://github.com/abseil/abseil-cpp/archive/refs/tags/20220623.1.tar.gz",
    ],
    # Remove after https://github.com/abseil/abseil-cpp/issues/326 is solved.
    patches = [
        "@//third_party:com_google_absl_f863b622fe13612433fdf43f76547d5edda0c93001.diff"
    ],
    patch_args = [
        "-p1",
    ],
    strip_prefix = "abseil-cpp-20220623.1",
    sha256 = "91ac87d30cc6d79f9ab974c51874a704de9c2647c40f6932597329a282217ba8"
)

http_archive(
    name = "rules_cc",
    strip_prefix = "rules_cc-2f8c04c04462ab83c545ab14c0da68c3b4c96191",
# The commit can be updated if the build passes. Last updated 6/23/22.
    urls = ["https://github.com/bazelbuild/rules_cc/archive/2f8c04c04462ab83c545ab14c0da68c3b4c96191.zip"],
)

http_archive(
   name = "rules_foreign_cc",
   strip_prefix = "rules_foreign_cc-0.1.0",
   url = "https://github.com/bazelbuild/rules_foreign_cc/archive/0.1.0.zip",
)

load("@rules_foreign_cc//:workspace_definitions.bzl", "rules_foreign_cc_dependencies")

rules_foreign_cc_dependencies()

# This is used to select all contents of the archives for CMake-based packages to give CMake access to them.
all_content = """filegroup(name = "all", srcs = glob(["**"]), visibility = ["//visibility:public"])"""

# GoogleTest/GoogleMock framework. Used by most unit-tests.
# Last updated 2021-07-02.
http_archive(
    name = "com_google_googletest",
    urls = ["https://github.com/google/googletest/archive/4ec4cd23f486bf70efcc5d2caa40f24368f752e3.zip"],
    strip_prefix = "googletest-4ec4cd23f486bf70efcc5d2caa40f24368f752e3",
    sha256 = "de682ea824bfffba05b4e33b67431c247397d6175962534305136aa06f92e049",
)

# Google Benchmark library v1.6.1 released on 2022-01-10.
http_archive(
    name = "com_google_benchmark",
    urls = ["https://github.com/google/benchmark/archive/refs/tags/v1.6.1.tar.gz"],
    strip_prefix = "benchmark-1.6.1",
    sha256 = "6132883bc8c9b0df5375b16ab520fac1a85dc9e4cf5be59480448ece74b278d4",
    build_file = "@//third_party:benchmark.BUILD",
)

# gflags needed by glog
http_archive(
    name = "com_github_gflags_gflags",
    strip_prefix = "gflags-2.2.2",
    sha256 = "19713a36c9f32b33df59d1c79b4958434cb005b5b47dc5400a7a4b078111d9b5",
    url = "https://github.com/gflags/gflags/archive/v2.2.2.zip",
)

# 2020-08-21
http_archive(
    name = "com_github_glog_glog",
    strip_prefix = "glog-0a2e5931bd5ff22fd3bf8999eb8ce776f159cda6",
    sha256 = "58c9b3b6aaa4dd8b836c0fd8f65d0f941441fb95e27212c5eeb9979cfd3592ab",
    urls = [
        "https://github.com/google/glog/archive/0a2e5931bd5ff22fd3bf8999eb8ce776f159cda6.zip",
    ],
)
http_archive(
    name = "com_github_glog_glog_no_gflags",
    strip_prefix = "glog-0a2e5931bd5ff22fd3bf8999eb8ce776f159cda6",
    sha256 = "58c9b3b6aaa4dd8b836c0fd8f65d0f941441fb95e27212c5eeb9979cfd3592ab",
    build_file = "@//third_party:glog_no_gflags.BUILD",
    urls = [
        "https://github.com/google/glog/archive/0a2e5931bd5ff22fd3bf8999eb8ce776f159cda6.zip",
    ],
    patches = [
        "@//third_party:com_github_glog_glog_9779e5ea6ef59562b030248947f787d1256132ae.diff",
    ],
    patch_args = [
        "-p1",
    ],
)

# easyexif
http_archive(
    name = "easyexif",
    url = "https://github.com/mayanklahiri/easyexif/archive/master.zip",
    strip_prefix = "easyexif-master",
    build_file = "@//third_party:easyexif.BUILD",
)

# libyuv
http_archive(
    name = "libyuv",
    # Error: operand type mismatch for `vbroadcastss' caused by commit 8a13626e42f7fdcf3a6acbb0316760ee54cda7d8.
    urls = ["https://chromium.googlesource.com/libyuv/libyuv/+archive/2525698acba9bf9b701ba6b4d9584291a1f62257.tar.gz"],
    build_file = "@//third_party:libyuv.BUILD",
)

# Note: protobuf-javalite is no longer released as a separate download, it's included in the main Java download.
# ...but the Java download is currently broken, so we use the "source" download.
http_archive(
    name = "com_google_protobuf_javalite",
    sha256 = "87407cd28e7a9c95d9f61a098a53cf031109d451a7763e7dd1253abf8b4df422",
    strip_prefix = "protobuf-3.19.1",
    urls = ["https://github.com/protocolbuffers/protobuf/archive/v3.19.1.tar.gz"],
)

http_archive(
    name = "com_google_protobuf",
    sha256 = "87407cd28e7a9c95d9f61a098a53cf031109d451a7763e7dd1253abf8b4df422",
    strip_prefix = "protobuf-3.19.1",
    urls = ["https://github.com/protocolbuffers/protobuf/archive/v3.19.1.tar.gz"],
    patches = [
        "@//third_party:com_google_protobuf_fixes.diff"
    ],
    patch_args = [
        "-p1",
    ],
    # TODO ouble check checksum
    #sha256 = "1fbf1c2962af287607232b2eddeaec9b4f4a7a6f5934e1a9276e9af76952f7e0",
    #strip_prefix = "protobuf-3.9.2",
    #urls = ["https://github.com/protocolbuffers/protobuf/archive/v3.9.2.tar.gz"],
    # need to drop patch in older version
)

load("//third_party/flatbuffers:workspace.bzl", flatbuffers = "repo")
flatbuffers()

http_archive(
    name = "com_google_audio_tools",
    strip_prefix = "multichannel-audio-tools-master",
    urls = ["https://github.com/google/multichannel-audio-tools/archive/master.zip"],
    repo_mapping = {"@com_github_glog_glog" : "@com_github_glog_glog_no_gflags"},
)

http_archive(
    name = "pffft",
    strip_prefix = "jpommier-pffft-7c3b5a7dc510",
    urls = ["https://bitbucket.org/jpommier/pffft/get/7c3b5a7dc510.zip"],
    build_file = "@//third_party:pffft.BUILD",
)

# sentencepiece
http_archive(
    name = "com_google_sentencepiece",
    strip_prefix = "sentencepiece-1.0.0",
    sha256 = "c05901f30a1d0ed64cbcf40eba08e48894e1b0e985777217b7c9036cac631346",
    urls = [
        "https://github.com/google/sentencepiece/archive/1.0.0.zip",
    ],
    patches = [
        "//third_party:com_google_sentencepiece_no_gflag_no_gtest.diff",
    ],
    patch_args = ["-p1"],
    repo_mapping = {"@com_google_glog" : "@com_github_glog_glog_no_gflags"},
)

http_archive(
    name = "org_tensorflow_text",
    sha256 = "f64647276f7288d1b1fe4c89581d51404d0ce4ae97f2bcc4c19bd667549adca8",
    strip_prefix = "text-2.2.0",
    urls = [
        "https://github.com/tensorflow/text/archive/v2.2.0.zip",
    ],
    patches = [
        "//third_party:tensorflow_text_remove_tf_deps.diff",
        "//third_party:tensorflow_text_a0f49e63.diff",
    ],
    patch_args = ["-p1"],
    repo_mapping = {"@com_google_re2": "@com_googlesource_code_re2"},
)

http_archive(
    name = "com_googlesource_code_re2",
    sha256 = "e06b718c129f4019d6e7aa8b7631bee38d3d450dd980246bfaf493eb7db67868",
    strip_prefix = "re2-fe4a310131c37f9a7e7f7816fa6ce2a8b27d65a8",
    urls = [
        "https://github.com/google/re2/archive/fe4a310131c37f9a7e7f7816fa6ce2a8b27d65a8.tar.gz",
    ],
)

# 2020-07-09
http_archive(
    name = "pybind11_bazel",
    strip_prefix = "pybind11_bazel-203508e14aab7309892a1c5f7dd05debda22d9a5",
    urls = ["https://github.com/pybind/pybind11_bazel/archive/203508e14aab7309892a1c5f7dd05debda22d9a5.zip"],
    sha256 = "75922da3a1bdb417d820398eb03d4e9bd067c4905a4246d35a44c01d62154d91",
)

# 2022-10-20
http_archive(
    name = "pybind11",
    urls = [
        "https://github.com/pybind/pybind11/archive/v2.10.1.zip",
    ],
    sha256 = "fcf94065efcfd0a7a828bacf118fa11c43f6390d0c805e3e6342ac119f2e9976",
    strip_prefix = "pybind11-2.10.1",
    build_file = "@pybind11_bazel//:pybind11.BUILD",
)

http_archive(
    name = "pybind11_protobuf",
    sha256 = "baa1f53568283630a5055c85f0898b8810f7a6431bd01bbaedd32b4c1defbcb1",
    strip_prefix = "pybind11_protobuf-3594106f2df3d725e65015ffb4c7886d6eeee683",
    urls = [
        "https://github.com/pybind/pybind11_protobuf/archive/3594106f2df3d725e65015ffb4c7886d6eeee683.tar.gz",
    ],
)

# Point to the commit that deprecates the usage of Eigen::MappedSparseMatrix.
http_archive(
    name = "ceres_solver",
    url = "https://github.com/ceres-solver/ceres-solver/archive/123fba61cf2611a3c8bddc9d91416db26b10b558.zip",
    patches = [
        "@//third_party:ceres_solver_compatibility_fixes.diff"
    ],
    patch_args = [
        "-p1",
    ],
    strip_prefix = "ceres-solver-123fba61cf2611a3c8bddc9d91416db26b10b558",
    sha256 = "8b7b16ceb363420e0fd499576daf73fa338adb0b1449f58bea7862766baa1ac7"
)

http_archive(
    name = "opencv",
    build_file_content = all_content,
    strip_prefix = "opencv-3.4.10",
    urls = ["https://github.com/opencv/opencv/archive/3.4.10.tar.gz"],
)

new_local_repository(
    name = "linux_opencv",
    build_file = "@//third_party:opencv_linux.BUILD",
    path = "/usr/local",
)

new_local_repository(
    name = "linux_ffmpeg",
    build_file = "@//third_party:ffmpeg_linux.BUILD",
    path = "/usr"
)

new_local_repository(
    name = "macos_opencv",
    build_file = "@//third_party:opencv_macos.BUILD",
    # For local MacOS builds, the path should point to an opencv@3 installation.
    # If you edit the path here, you will also need to update the corresponding
    # prefix in "opencv_macos.BUILD".
    path = "/usr/local",
)

new_local_repository(
    name = "macos_ffmpeg",
    build_file = "@//third_party:ffmpeg_macos.BUILD",
    path = "/usr/local/opt/ffmpeg",
)

new_local_repository(
    name = "windows_opencv",
    build_file = "@//third_party:opencv_windows.BUILD",
    path = "C:\\opencv\\build",
)

http_archive(
    name = "android_opencv",
    build_file = "@//third_party:opencv_android.BUILD",
    strip_prefix = "OpenCV-android-sdk",
    type = "zip",
    url = "https://github.com/opencv/opencv/releases/download/3.4.3/opencv-3.4.3-android-sdk.zip",
)

# After OpenCV 3.2.0, the pre-compiled opencv2.framework has google protobuf symbols, which will
# trigger duplicate symbol errors in the linking stage of building a mediapipe ios app.
# To get a higher version of OpenCV for iOS, opencv2.framework needs to be built from source with
# '-DBUILD_PROTOBUF=OFF -DBUILD_opencv_dnn=OFF'.
http_archive(
    name = "ios_opencv",
    sha256 = "7dd536d06f59e6e1156b546bd581523d8df92ce83440002885ec5abc06558de2",
    build_file = "@//third_party:opencv_ios.BUILD",
    type = "zip",
    url = "https://github.com/opencv/opencv/releases/download/3.2.0/opencv-3.2.0-ios-framework.zip",
)

http_archive(
    name = "stblib",
    strip_prefix = "stb-b42009b3b9d4ca35bc703f5310eedc74f584be58",
    sha256 = "13a99ad430e930907f5611325ec384168a958bf7610e63e60e2fd8e7b7379610",
    urls = ["https://github.com/nothings/stb/archive/b42009b3b9d4ca35bc703f5310eedc74f584be58.tar.gz"],
    build_file = "@//third_party:stblib.BUILD",
    patches = [
        "@//third_party:stb_image_impl.diff"
    ],
    patch_args = [
        "-p1",
    ],
)

# Load Zlib before initializing TensorFlow and the iOS build rules to guarantee
# that the target @zlib//:mini_zlib is available
http_archive(
    name = "zlib",
    build_file = "//third_party:zlib.BUILD",
    sha256 = "c3e5e9fdd5004dcb542feda5ee4f0ff0744628baf8ed2dd5d66f8ca1197cb1a1",
    strip_prefix = "zlib-1.2.11",
    urls = [
        "http://mirror.bazel.build/zlib.net/fossils/zlib-1.2.11.tar.gz",
        "http://zlib.net/fossils/zlib-1.2.11.tar.gz",  # 2017-01-15
    ],
    patches = [
        "@//third_party:zlib.diff",
    ],
    patch_args = [
        "-p1",
    ],
)

# iOS basic build deps.
http_archive(
    name = "build_bazel_rules_apple",
    sha256 = "f94e6dddf74739ef5cb30f000e13a2a613f6ebfa5e63588305a71fce8a8a9911",
    url = "https://github.com/bazelbuild/rules_apple/releases/download/1.1.3/rules_apple.1.1.3.tar.gz",
    patches = [
        # Bypass checking ios unit test runner when building MP ios applications.
        "@//third_party:build_bazel_rules_apple_bypass_test_runner_check.diff"
    ],
    patch_args = [
        "-p1",
    ],
)

load(
    "@build_bazel_rules_apple//apple:repositories.bzl",
    "apple_rules_dependencies",
)
apple_rules_dependencies()

load(
    "@build_bazel_rules_swift//swift:repositories.bzl",
    "swift_rules_dependencies",
)
swift_rules_dependencies()

load(
    "@build_bazel_rules_swift//swift:extras.bzl",
    "swift_rules_extra_dependencies",
)
swift_rules_extra_dependencies()

load(
    "@build_bazel_apple_support//lib:repositories.bzl",
    "apple_support_dependencies",
)
apple_support_dependencies()

# More iOS deps.

http_archive(
    name = "google_toolbox_for_mac",
    url = "https://github.com/google/google-toolbox-for-mac/archive/v2.2.1.zip",
    sha256 = "e3ac053813c989a88703556df4dc4466e424e30d32108433ed6beaec76ba4fdc",
    strip_prefix = "google-toolbox-for-mac-2.2.1",
    build_file = "@//third_party:google_toolbox_for_mac.BUILD",
)

# Maven dependencies.

RULES_JVM_EXTERNAL_TAG = "4.0"
RULES_JVM_EXTERNAL_SHA = "31701ad93dbfe544d597dbe62c9a1fdd76d81d8a9150c2bf1ecf928ecdf97169"

http_archive(
    name = "rules_jvm_external",
    strip_prefix = "rules_jvm_external-%s" % RULES_JVM_EXTERNAL_TAG,
    sha256 = RULES_JVM_EXTERNAL_SHA,
    url = "https://github.com/bazelbuild/rules_jvm_external/archive/%s.zip" % RULES_JVM_EXTERNAL_TAG,
)

load("@rules_jvm_external//:defs.bzl", "maven_install")

# Important: there can only be one maven_install rule. Add new maven deps here.
maven_install(
    artifacts = [
        "androidx.concurrent:concurrent-futures:1.0.0-alpha03",
        "androidx.lifecycle:lifecycle-common:2.3.1",
        "androidx.activity:activity:1.2.2",
        "androidx.exifinterface:exifinterface:1.3.3",
        "androidx.fragment:fragment:1.3.4",
        "androidx.annotation:annotation:aar:1.1.0",
        "androidx.appcompat:appcompat:aar:1.1.0-rc01",
        "androidx.camera:camera-core:1.0.0-beta10",
        "androidx.camera:camera-camera2:1.0.0-beta10",
        "androidx.camera:camera-lifecycle:1.0.0-beta10",
        "androidx.constraintlayout:constraintlayout:aar:1.1.3",
        "androidx.core:core:aar:1.1.0-rc03",
        "androidx.legacy:legacy-support-v4:aar:1.0.0",
        "androidx.recyclerview:recyclerview:aar:1.1.0-beta02",
        "androidx.test.espresso:espresso-core:3.1.1",
        "com.github.bumptech.glide:glide:4.11.0",
        "com.google.android.material:material:aar:1.0.0-rc01",
        "com.google.auto.value:auto-value:1.8.1",
        "com.google.auto.value:auto-value-annotations:1.8.1",
        "com.google.code.findbugs:jsr305:latest.release",
        "com.google.android.datatransport:transport-api:3.0.0",
        "com.google.android.datatransport:transport-backend-cct:3.1.0",
        "com.google.android.datatransport:transport-runtime:3.1.0",
        "com.google.flogger:flogger-system-backend:0.6",
        "com.google.flogger:flogger:0.6",
        "com.google.guava:guava:27.0.1-android",
        "com.google.guava:listenablefuture:1.0",
        "junit:junit:4.12",
        "org.hamcrest:hamcrest-library:1.3",
    ],
    repositories = [
        "https://maven.google.com",
        "https://dl.google.com/dl/android/maven2",
        "https://repo1.maven.org/maven2",
        "https://jcenter.bintray.com",
    ],
    fetch_sources = True,
    version_conflict_policy = "pinned",
)

# Needed by TensorFlow
http_archive(
    name = "io_bazel_rules_closure",
    sha256 = "e0a111000aeed2051f29fcc7a3f83be3ad8c6c93c186e64beb1ad313f0c7f9f9",
    strip_prefix = "rules_closure-cf1e44edb908e9616030cc83d085989b8e6cd6df",
    urls = [
        "http://mirror.tensorflow.org/github.com/bazelbuild/rules_closure/archive/cf1e44edb908e9616030cc83d085989b8e6cd6df.tar.gz",
        "https://github.com/bazelbuild/rules_closure/archive/cf1e44edb908e9616030cc83d085989b8e6cd6df.tar.gz",  # 2019-04-04
    ],
)

# TensorFlow repo should always go after the other external dependencies.
# TF on 2022-08-10.
_TENSORFLOW_GIT_COMMIT = "af1d5bc4fbb66d9e6cc1cf89503014a99233583b"
_TENSORFLOW_SHA256 = "f85a5443264fc58a12d136ca6a30774b5bc25ceaf7d114d97f252351b3c3a2cb"
http_archive(
    name = "org_tensorflow",
    urls = [
      "https://github.com/tensorflow/tensorflow/archive/%s.tar.gz" % _TENSORFLOW_GIT_COMMIT,
    ],
    patches = [
        "@//third_party:org_tensorflow_compatibility_fixes.diff",
        # Diff is generated with a script, don't update it manually.
        "@//third_party:org_tensorflow_custom_ops.diff",
    ],
    patch_args = [
        "-p1",
    ],
    strip_prefix = "tensorflow-%s" % _TENSORFLOW_GIT_COMMIT,
    sha256 = _TENSORFLOW_SHA256,
)

load("@org_tensorflow//tensorflow:workspace3.bzl", "tf_workspace3")
tf_workspace3()
load("@org_tensorflow//tensorflow:workspace2.bzl", "tf_workspace2")
tf_workspace2()

# Edge TPU
http_archive(
  name = "libedgetpu",
  sha256 = "14d5527a943a25bc648c28a9961f954f70ba4d79c0a9ca5ae226e1831d72fe80",
  strip_prefix = "libedgetpu-3164995622300286ef2bb14d7fdc2792dae045b7",
  urls = [
    "https://github.com/google-coral/libedgetpu/archive/3164995622300286ef2bb14d7fdc2792dae045b7.tar.gz"
  ],
)
load("@libedgetpu//:workspace.bzl", "libedgetpu_dependencies")
libedgetpu_dependencies()

load("@coral_crosstool//:configure.bzl", "cc_crosstool")
cc_crosstool(name = "crosstool")

# Node dependencies
http_archive(
    name = "build_bazel_rules_nodejs",
    sha256 = "5aae76dced38f784b58d9776e4ab12278bc156a9ed2b1d9fcd3e39921dc88fda",
    urls = ["https://github.com/bazelbuild/rules_nodejs/releases/download/5.7.1/rules_nodejs-5.7.1.tar.gz"],
)

load("@build_bazel_rules_nodejs//:repositories.bzl", "build_bazel_rules_nodejs_dependencies")
build_bazel_rules_nodejs_dependencies()

# fetches nodejs, npm, and yarn
load("@build_bazel_rules_nodejs//:index.bzl", "node_repositories", "yarn_install")
node_repositories()
yarn_install(
    name = "npm",
    package_json = "//:package.json",
    yarn_lock = "//:yarn.lock",
)

# Protobuf for Node dependencies
http_archive(
    name = "rules_proto_grpc",
    sha256 = "bbe4db93499f5c9414926e46f9e35016999a4e9f6e3522482d3760dc61011070",
    strip_prefix = "rules_proto_grpc-4.2.0",
    urls = ["https://github.com/rules-proto-grpc/rules_proto_grpc/archive/4.2.0.tar.gz"],
)

http_archive(
    name = "com_google_protobuf_javascript",
    sha256 = "35bca1729532b0a77280bf28ab5937438e3dcccd6b31a282d9ae84c896b6f6e3",
    strip_prefix = "protobuf-javascript-3.21.2",
    urls = ["https://github.com/protocolbuffers/protobuf-javascript/archive/refs/tags/v3.21.2.tar.gz"],
)

load("@rules_proto_grpc//:repositories.bzl", "rules_proto_grpc_toolchains", "rules_proto_grpc_repos")
rules_proto_grpc_toolchains()
rules_proto_grpc_repos()

load("@rules_proto//proto:repositories.bzl", "rules_proto_dependencies", "rules_proto_toolchains")
rules_proto_dependencies()
rules_proto_toolchains()

load("//third_party:external_files.bzl", "external_files")
external_files()

load("//third_party:wasm_files.bzl", "wasm_files")
wasm_files()

load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

git_repository(
    name = "ovms",
    remote = "https://github.com/openvinotoolkit/model_server",
    commit = "ce602ca2af742282b1e14166bfca47beaf4d0236", # Updated CAPI calls (#2012)
)

# DEV ovms - adjust local repository path for build
#new_local_repository(
#    name = "ovms",
#    path = "/ovms/",
#    build_file = "/ovms/BUILD.bazel",
#)

load("@bazel_tools//tools/build_defs/repo:git.bzl", "new_git_repository")

# minitrace
new_git_repository(
    name = "minitrace",
    remote = "https://github.com/hrydgard/minitrace.git",
    commit = "020f42b189e8d6ad50e4d8f45d69edee0a6b3f23",
    build_file_content = """
cc_library(
    name = "trace",
    hdrs = ["minitrace.h"],
    srcs = ["minitrace.c"],
    visibility = ["//visibility:public"],
    local_defines = [
    ],
)
""",
)

# Tensorflow serving
git_repository(
    name = "tensorflow_serving",
    remote = "https://github.com/tensorflow/serving.git",
    tag = "2.6.5",
    patch_args = ["-p1"],
    patches = ["@ovms//external:net_http.patch", "@ovms//external:listen.patch"]
    #                             ^^^^^^^^^^^^
    #                       make bind address configurable
    #          ^^^^^^^^^^^^
    #        allow all http methods
)

# AWS S3 SDK
new_local_repository(
    name = "awssdk",
    build_file = "@ovms//third_party/aws:BUILD",
    path = "/awssdk",
)

# Azure Storage SDK
new_local_repository(
    name = "azure",
    build_file = "@ovms//third_party/azure:BUILD",
    path = "/azure/azure-storage-cpp",
)

# Azure Storage SDK dependency - cpprest
new_local_repository(
    name = "cpprest",
    build_file = "@ovms//third_party/cpprest:BUILD",
    path = "/azure/cpprestsdk",
)

# Boost (needed for Azure Storage SDK)

new_local_repository(
    name = "boost",
    path = "/usr/local/lib/",
    build_file = "@ovms//third_party/boost:BUILD"
)

# Google Cloud SDK
http_archive(
    name = "com_github_googleapis_google_cloud_cpp",
    sha256 = "a370bcf2913717c674a7250c4a310250448ffeb751b930be559a6f1887155f3b",
    strip_prefix = "google-cloud-cpp-0.21.0",
    url = "https://github.com/googleapis/google-cloud-cpp/archive/v0.21.0.tar.gz",
    repo_mapping = {"@com_github_curl_curl" : "@curl"}
)

load("@com_github_googleapis_google_cloud_cpp//bazel:google_cloud_cpp_deps.bzl", "google_cloud_cpp_deps")
google_cloud_cpp_deps()

load("@com_google_googleapis//:repository_rules.bzl", "switched_rules_by_language")
switched_rules_by_language(
    name = "com_google_googleapis_imports",
    cc = True,  # C++ support is only "Partially implemented", roll our own.
    grpc = True,
)

load("@com_github_googleapis_google_cloud_cpp_common//bazel:google_cloud_cpp_common_deps.bzl", "google_cloud_cpp_common_deps")
google_cloud_cpp_common_deps()

load("@com_github_grpc_grpc//bazel:grpc_deps.bzl", "grpc_deps")
grpc_deps()

load("@com_github_grpc_grpc//bazel:grpc_extra_deps.bzl", "grpc_extra_deps")
grpc_extra_deps()

# cxxopts
http_archive(
    name = "com_github_jarro2783_cxxopts",
    url = "https://github.com/jarro2783/cxxopts/archive/v2.2.0.zip",
    sha256 = "f9640c00d9938bedb291a21f9287902a3a8cee38db6910b905f8eba4a6416204",
    strip_prefix = "cxxopts-2.2.0",
    build_file = "@ovms//third_party/cxxopts:BUILD",
)

# RapidJSON
http_archive(
    name = "com_github_tencent_rapidjson",
    url = "https://github.com/Tencent/rapidjson/archive/v1.1.0.zip",
    sha256 = "8e00c38829d6785a2dfb951bb87c6974fa07dfe488aa5b25deec4b8bc0f6a3ab",
    strip_prefix = "rapidjson-1.1.0",
    build_file = "@ovms//third_party/rapidjson:BUILD"
)

# spdlog
http_archive(
    name = "com_github_gabime_spdlog",
    url = "https://github.com/gabime/spdlog/archive/v1.4.0.tar.gz",
    sha256 = "afd18f62d1bc466c60bef088e6b637b0284be88c515cedc59ad4554150af6043",
    strip_prefix = "spdlog-1.4.0",
    build_file = "@ovms//third_party/spdlog:BUILD"
)

# fmtlib
http_archive(
    name = "fmtlib",
    url = "https://github.com/fmtlib/fmt/archive/6.0.0.tar.gz",
    sha256 = "f1907a58d5e86e6c382e51441d92ad9e23aea63827ba47fd647eacc0d3a16c78",
    strip_prefix = "fmt-6.0.0",
    build_file = "@ovms//third_party/fmtlib:BUILD"
)

# libevent
http_archive(
    name = "com_github_libevent_libevent",
    url = "https://github.com/libevent/libevent/archive/release-2.1.8-stable.zip",
    sha256 = "70158101eab7ed44fd9cc34e7f247b3cae91a8e4490745d9d6eb7edc184e4d96",
    strip_prefix = "libevent-release-2.1.8-stable",
    build_file = "@ovms//third_party/libevent:BUILD",
)

# prometheus-cpp
http_archive(
    name = "com_github_jupp0r_prometheus_cpp",
    strip_prefix = "prometheus-cpp-1.0.1",
    urls = ["https://github.com/jupp0r/prometheus-cpp/archive/refs/tags/v1.0.1.zip"],
)
load("@com_github_jupp0r_prometheus_cpp//bazel:repositories.bzl", "prometheus_cpp_repositories")
prometheus_cpp_repositories()

new_local_repository(
    name = "mediapipe_calculators",
    build_file = "@ovms//third_party/mediapipe_calculators:BUILD",
    path = "/opt/ovms/",
)

new_local_repository(
    name = "linux_openvino",
    build_file = "@ovms//third_party/openvino:BUILD",
    path = "/opt/intel/openvino/runtime",
)

git_repository(
    name = "oneTBB",
    branch = "v2021.8.0",
    remote = "https://github.com/oneapi-src/oneTBB/",
    patch_args = ["-p1"],
    patches = ["@ovms//external:mwaitpkg.patch",]
)

new_git_repository(
    name = "model_api",
    remote = "https:///github.com/openvinotoolkit/model_api/",
    build_file_content = """
cc_library(
    name = "adapter_api",
    hdrs = ["model_api/cpp/adapters/include/adapters/inference_adapter.h",],
    includes = ["model_api/cpp/adapters/include"],
    deps = ["@linux_openvino//:openvino"],
    visibility = ["//visibility:public"],
)
    """,
    commit = "ca5a91ed5b3dbf428dc4de6b72f0a3da93d2aa0a"
)
