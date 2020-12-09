workspace(name = "exception_extensions")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "proxy_wasm_cpp_sdk",
    strip_prefix = "proxy-wasm-cpp-sdk-f5ecda129d1e45de36cb7898641ac225a50ce7f0",
    url = "https://github.com/proxy-wasm/proxy-wasm-cpp-sdk/archive/f5ecda129d1e45de36cb7898641ac225a50ce7f0.tar.gz",
)

load("@proxy_wasm_cpp_sdk//bazel/dep:deps.bzl", "wasm_dependencies")

wasm_dependencies()

load("@proxy_wasm_cpp_sdk//bazel/dep:deps_extra.bzl", "wasm_dependencies_extra")

wasm_dependencies_extra()

