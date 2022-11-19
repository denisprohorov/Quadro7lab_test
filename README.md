# Test work to quadro7lab 
  
It's a cmake c++17 project which transforms input.txt to output.txt.
String conversion in a static library. Project contains tests (Gtest) and a logging (Glog) link via conan.

## Conan required
+ [gtest](https://github.com/google/googletest)
+ [glog](https://github.com/google/glog)

## How to build project
```
git clone https://github.com/denisprohorov/Quadro7lab_test.git
cd Quadro7lab_test
mkdir conanBuild
cd conanBuild
conan install .. --build=missing -s build_type=Release
cd ..

mkdir build 
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build . --config Release

cd bin
./main
./tests

```

## My settings

VS compiler 2022

Conan profile:

|                                                                            Windows                                                                             |
|:--------------------------------------------------------------------------------------------------------------------------------------------------------------:|
| [settings]<br/>os=Windows<br/>os_build=Windows<br/>arch=x86_64<br/>arch_build=x86_64<br/>compiler=Visual Studio<br/> compiler.version=17<br/> build_type=Debug |

