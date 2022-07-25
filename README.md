# scratchpad

This is the place where I collect pieces of C++ code I write to experiment, learn or measure.

## Building

I'm on macOS Monterey and AppleClang just sucks!

```
cmake -DCMAKE_CXX_COMPILER=/usr/local/bin/g++-11 -DCMAKE_BUILD_TYPE=Debug -GNinja -Bbuild
ninja -C build [target_name]
```

## Acknowledgements

Basically everything in the cmake folder has been copied from https://github.com/lefticus/cpp_starter_project.