cc_test(
    name = "tests",
    srcs = glob(["*.cpp", "*.h"]),
    copts = ["-Ibuilder_pattern/lib"],
    deps = [
        "//builder_pattern/lib:builder_pattern",
        "@googletest//:gtest_main",
    ],
)
