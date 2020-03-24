cc_test(
    name = "tests",
    srcs = glob(["*.cpp", "*.h"]),    
    copts = ["-std=c++17", "-Ilib"], 
    deps = [
        "//lib:library_under_test",
        "@googletest//:gtest_main",
    ],
)
