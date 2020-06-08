# cpp-design-patterns
A collection of C++ design pattern demos with gmock and gtest


# How To Run the Demos
1. Demos are divided into folders with the pattern. Change directory to one of these folders.
2. To build only, enter `bazel build ...`
3. To build and execute the tests in the test folder, enter `bazel run //test:tests`


# Notes
* When running on systems where you need to specify the exact C++ compiler version, you can add `--cxxopt='-std=c++14'`
e.g.<br/>
    * Build Only: `bazel build ... --cxxopt='-std=c++14'`
    * Build and Run Test: `bazel test ... --cxxopt='-std=c++14' --test_output=all`

* If you're on *nix type system and want to run valgrind, you can do it against the test:<br/>
`valgrind bazel-bin/test/tests`
