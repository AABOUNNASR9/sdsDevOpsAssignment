# CI/CD Technical Assignment

For this technical evaluation, we ask you to add the necessary scripts and configuration 
files to an existing C++ and python project. 

This project simulates a common pattern: an R&D software engineer has started a software 
project and has some tests that run correctly on their local development machine. 
They need support to automate the build and test of the software on the company CI 
infrastructure. 
In this assignment, the CI infrastructure is a cloud-hosted solution such as Github 
and Github Actions. 

Your main task is to implement a pipeline of automated tasks running on each 
pushed commit on the repository, including at least the following results:  

- Automated build of the software on Linux x86_64 target platform with the clang compiler 
  - Linux distribution of your choosing. Any recent version of Ubuntu should work fine. 
- Automated run of the associated tests for the C++ library, with results visible in the log 
- Automated run of python tests, with results visible in the log 
- Automated run of some static analysis tools like cppcheck and pylint, with results 
  visible in the log. 

After these basic features, you can go as far as you want. The following features are 
examples of what you could add to the CI/CD pipeline: 

- Automate more code quality checkers, static or dynamic (e.g. valgrind, clang-sanitizers). 
- Provide automated packaging for both the C++ library and the python library. 
- Adding build and test pipelines for more target platforms: Linux ARM, Android, Windows, MacOS. 
- Improved reporting of the test results. 

Note that the given project might work fine in the developer environment, but not 
suitable for the CI environment. 
Be ready to modify the source code and build scripts when needed. 

