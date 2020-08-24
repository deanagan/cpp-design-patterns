cc_test(
    name = "tests",
    srcs = glob(["*.cpp", "*.h"]),
    copts = ["-Icuriously_recurring_template_pattern/lib"],
    deps = [
        "//curiously_recurring_template_pattern/lib:curiously_recurring_template_pattern",
        "@googletest//:gtest_main",
    ],
)
