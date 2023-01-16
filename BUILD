cc_library(
    name = "llvm_headers",
    hdrs = glob([
        "llvm/include/**/*.h",
        "llvm/include/llvm/Config/abi-breaking.h",
    ]),
    includes = [
        "llvm/include",
    ],
)

cc_library(
    name = "mlir_headers",
    hdrs = glob([
        "mlir/include/**/*.h",
        "mlir/include/**/*.h.inc",
    ]),
    includes = [
        "mlir/include",
    ],
    deps = [
        ":llvm_headers",
    ],
)

cc_library(
    name = "crash",
    srcs = ["crash.cpp"],
    deps = [":mlir_headers"],
    copts = ["-Wno-unused-function"],
)

