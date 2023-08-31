# EVerest "out-of-tree" example modules

In this repository you will find an example how EVerest "out-of-tree" modules can be built and used.
This can be very convenient during development of certain modules that might no directly fit in everest-core.

# How to write new "out-of-tree" modules and build EVerest

Make sure this repository is checked out in the same directory as everest-core, everest-cmake and everest-framework eg.:

```bash
├── everest-cmake
├── everest-core
├── everest-framework
└── everest-examples
```

To write a new module create a new directory inside the modules directory of this repository. The name of your directory is the name of your new module.

Create your module's manifest and the interfaces you need inside the interfaces directory.

Use ev-cli to initialize your module from its manifest

```bash
ev-cli mod create <your_module_name> --everest-dir . ../everest-core/
```

Note the "--everest-dir" parameters which should point to the "out-of-tree" repository as well as to everest-core. This ensures that interfaces and types are found properly during module creation.


To use the module you created within EVerest, add the name of the module to the [CMakeLists.txt](modules/CMakeLists.txt) file in the modules directory.

```cmake
ev_add_module(<your_module_name>)

```

Now you can build EVerest with your new module(s). Make sure you are in the root directory of this repository.

```bash
cmake -S . -B build
cmake --build build --target install
```

Make sure to modify or create your [EVerest config](config) to include your new module(s).

```bash
./build/run-scripts/run_your-config.sh
```
