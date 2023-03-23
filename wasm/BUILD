load("@rules_cc//cc:defs.bzl", "cc_binary")
load("@emsdk//emscripten_toolchain:wasm_rules.bzl", "wasm_cc_binary")

cc_binary(
    name = "lyra",
    srcs = ["lyra.cc"],
    deps = [
        "@lyra//lyra:lyra_encoder",
        "@lyra//lyra:lyra_decoder",
    ],
    linkopts = [
      "--bind",
      "-s INITIAL_MEMORY=64MB",
      "-s EXPORT_ES6=1",
      "-s MODULARIZE=1",
      "-s EXPORT_NAME=LyraWasmModule",
      "-s FORCE_FILESYSTEM",

      # [FIXME]
      # "undefined symbol: _Unwind_GetIP (referenced by top-level compiled C/C++ code)" エラーを抑制するためのオプション
      # 対処法が判明したらこれは指定しないようにする
      "-s ERROR_ON_UNDEFINED_SYMBOLS=0",
    ],
)

wasm_cc_binary(
    name = "lyra-wasm",
    cc_target = ":lyra",
)

# C API
cc_binary(
    name = "lyra-c-api",
    srcs = ["lyra_c_api.cc", "lyra_c_api.h"],
    deps = [
        "@lyra//lyra:lyra_encoder",
        "@lyra//lyra:lyra_decoder",
    ],
    linkopts = [
      "--bind",
      "-s INITIAL_MEMORY=64MB",
      "-s EXPORT_ES6=1",
      "-s MODULARIZE=1",
    #   "-s EXPORT_NAME=LyraWasmModule",
      "-s FORCE_FILESYSTEM",

      # [FIXME]
      # "undefined symbol: _Unwind_GetIP (referenced by top-level compiled C/C++ code)" エラーを抑制するためのオプション
      # 対処法が判明したらこれは指定しないようにする
      "-s ERROR_ON_UNDEFINED_SYMBOLS=0",
    ],
)

wasm_cc_binary(
    name = "lyra-wasm-c-api",
    cc_target = ":lyra-c-api",
)

