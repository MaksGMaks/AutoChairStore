## Manual build process
1. Install conan debs

   ```
   conan install . --output-folder=build --build=missing
   ```

   Or if your conan have sudo rights:
   ```
   conan install . --output-folder=build --build=missing -c tools.system.package_manager:mode=install
   ```
   If you have already installed qt manualy, add
   ```
   QT_DIR='your_path_to_qt_with_gcc_64'
   export QT_DIR
   ```
   into your .bashrc file. INPORTANT: version of qt is 6.6.2

3. Go to build folder and run cmake with presets

   ```
   cd build
   cmake .. --preset conan-debug -DBUILD_CLIENT=ON -DBUILD_SERVER=ON
   ```

4. Build the project

   ```
   cmake --build .
   ```
## If conan not installed
If you don't have conan, install it via official site
   ```
   https://conan.io
   ```
   or, if you in Linux
   ```
   sudo apt install python3-pip
   sudo pip install conan
   ```
To start, use
```
conan profile detect
```
then find path to profile
```
conan profile path default
```
and paste next into it
```
[settings]
arch=x86_64
build_type=Debug
compiler=gcc
compiler.cppstd=gnu20
compiler.libcxx=libstdc++11
compiler.version=11
os=Linux
[options]
*:shared=True
[conf]
tools.cmake.cmaketoolchain:generator=Ninja
```