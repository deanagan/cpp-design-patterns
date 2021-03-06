[![Build Status](https://travis-ci.com/deanagan/cpp-design-patterns.svg?branch=master)](https://travis-ci.com/github/deanagan/cpp-design-patterns)
# cpp-design-patterns
A collection of C++ design pattern demos with gmock and gtest. This repo also includes C++ idioms.


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


# Problem Running on Windows
I get this when running build
`Action failed to execute: java.io.IOException: ERROR: src/main/native/windows/process.cc(202):`

To fix this, do:
`set BAZEL_VC=C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC`

See Bazel Github for details: https://github.com/bazelbuild/bazel/issues/8589