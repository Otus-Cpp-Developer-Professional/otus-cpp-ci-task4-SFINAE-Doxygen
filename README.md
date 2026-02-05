## Task 1 — Build and Package Publishing

This repository is created to complete **Task 1**, which focuses on building a simple C++ project and setting up an automated build farm using **GitHub Actions**.

The project contains a program that prints the following output to the console:

build N  
Hello, World!

where **N** is the current build number.

During the build stage, automated tests are executed to validate the build/version number.

A GitHub Actions workflow is configured to:
- automatically build the project on every commit,
- run tests during the build stage,
- publish build artifacts,
- automatically create a release either on each commit or when a Git tag is created.
# otus-cpp-ci-task4-SFINAE-Doxygen
