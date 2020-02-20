# cpp-design-patterns
A collection of C++ design pattern demos with gmock and gtest


# How To Run the Demos
1. Demos are divided into folders with the pattern. Cd to one of these folders.
2. To build all, enter `bazel build ...`
3. To execute just the main folder (primarily for testing temporary code), enter `bazel run main`
4. To execute the tests in the test folder, enter `bazel run //test:tests`
