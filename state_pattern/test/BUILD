cc_test(
    name = "tests",
    srcs = glob(["*.cpp", "*.h"]),
    copts = ["-Istate_pattern/lib"],
    deps = [
        "//state_pattern/lib:state_pattern",
        "@googletest//:gtest_main",
    ],
)
