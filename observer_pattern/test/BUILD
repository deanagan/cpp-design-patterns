cc_test(
    name = "tests",
    srcs = glob(["*.cpp", "*.h"]),
    copts = ["-Iobserver_pattern/lib"],
    deps = [
        "//observer_pattern/lib:observer_pattern",
        "@googletest//:gtest_main",
    ],
)
