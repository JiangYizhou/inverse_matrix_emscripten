# inverse_matrix_emscripten

This project is to reproduce the bug when trying to use SIMD in chromium.
Calculating inverse matrix failure when enabling SIMD.

# Required Tools and Configurations
Install [emscripten](https://emscripten.org/docs/getting_started/downloads.html), cmake, python, [depot_tools](https://commondatastorage.googleapis.com/chrome-infra-docs/flat/depot_tools/docs/html/depot_tools_tutorial.html), and [chrome canary](https://www.google.com/chrome/canary/).

Use llvm instead of fastcomp  // simd is an experimental feature, install latest-upstream of emscripten
```sh
emsdk install latest-upstream // where llvm is enabled by default
emsdk activate latest-upstream
```

# Build the project
```sh
cd Release
emconfigure cmake -DCMAKE_C_FLAGS=-O3 -DCMAKE_CXX_FLAGS=-O3 -DCMAKE_EXE_LINKER_FLAGS=-O3  -D_NDEBUG=true -DCMAKE_BUILD_TYPE=Release ../
// build on windows
ninja
// build on linux or macOS
make
```

# Run the project
Start chrome canary // SIMD is an experimental feature in chromium, so we have to pass the flag
```sh
chrome.exe --js-flags="--experimental-wasm-simd"
```
Start a local server
```sh
python -m SimpleHTTPServer
```
Run inverse_matrix.html in canary
