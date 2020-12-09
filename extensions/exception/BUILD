load("@proxy_wasm_cpp_sdk//bazel/wasm:wasm.bzl", "wasm_cc_binary")

cc_library(
    name = "exceptional",
    srcs = [
        "exceptional.cc",
        "exceptional.h",
    ],
    deps = [
        "@proxy_wasm_cpp_sdk//:proxy_wasm_intrinsics",
    ],
)

wasm_cc_binary(
    name = "exceptionextension.wasm",
    srcs = [
        "plugin.cc",
        "plugin.h",
    ],
    deps = [
        ":exceptional",

        "@proxy_wasm_cpp_sdk//:proxy_wasm_intrinsics",
    ],
)

cc_library(
    name = "exceptionextension",
    srcs = [
        "plugin.cc",
    ],
    hdrs = [
        "plugin.h",
    ],
    copts = ["-DNULL_PLUGIN"],
    deps = [
        "@proxy_wasm_cpp_host//:lib",
    ],
)
