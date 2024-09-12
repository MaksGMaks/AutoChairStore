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

2. Go to build folder and run cmake with presets

   ```
   cd build
   cmake .. --preset conan-debug -DBUILD_CLIENT=ON -DBUILD_SERVER=ON
   ```

3. Build the project

   ```
   cmake --build .
   ```
