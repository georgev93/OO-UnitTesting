project(
  'Empty Test Project',
  ['c'],
  version: '1.0',
  default_options: [
    'buildtype=debug',
  ],
)

add_languages('cpp', native: true)

### ========== SANITIZERS ==========
sanitizers = ['-fsanitize=undefined,integer']
### ================================

### ========== SOURCE ==========
proj_src = files(
  'src/source.cpp',
)

proj_main = files('src/main.cpp')

proj_inc = include_directories(
  [
    './inc',
  ],
)

proj_link_args = sanitizers + []

proj_common_args = sanitizers + []

proj_c_args = proj_common_args + []

proj_cpp_args = proj_common_args + [
  '-Wno-c++98-compat',
]

### ============================

### ========== FAKES ==========
# fake_src = files()

fake_inc = include_directories(
  [
    './tests/fakes/inc',
  ],
)
### ===========================

### ========== TESTS ==========
test_src = files(
  './tests/AllTests.cpp',
  './tests/testFile.cpp',
)

test_inc = include_directories([])

test_link_args = sanitizers + []

test_common_args = sanitizers + [
  '-Wall',
  '-Weverything',
]

test_c_args = test_common_args + ['-std=c90']

test_cpp_args = test_common_args + [
  '-std=c++11',
  '-Wno-c++98-compat', # CPPUTEST
  '-Wno-c++98-compat-pedantic', # CPPUTEST
  '-Wno-disabled-macro-expansion', # CPPUTEST
  '-Wno-padded', # CPPUTEST
  '-Wno-exit-time-destructors', # CPPUTEST
  '-Wno-global-constructors', # CPPUTEST
  '-Wno-weak-vtables', # CPPUTEST
  '-Wno-shorten-64-to-32', # CPPUTEST
  '-Wno-unsafe-buffer-usage', # fff
  '-Wno-old-style-cast', # fff
  '-Wno-cast-function-type-strict', # fff
]
### ===========================

### ========== SUBPROJECTS ==========
test_deps = [dependency('cpputest', native: true)]
### =================================

### ========== DEPENDENCIES ==========
### ==================================

### ========== EXECUTABLES ==========
test_exe = executable(
  'tests',
  build_by_default: false,
  dependencies: test_deps,
  sources: [proj_src, test_src],
  c_args: test_c_args,
  cpp_args: test_cpp_args,
  link_args: test_link_args,
  include_directories: [proj_inc, test_inc, fake_inc],
  native: true,
)

run_exe = executable(
  'executable',
  build_by_default: true,
  sources: [proj_src, proj_main],
  c_args: proj_c_args,
  cpp_args: proj_cpp_args,
  link_args: proj_link_args,
  include_directories: proj_inc,
  native: true,
)
### =================================

### ========== TESTS FOR MESON TO RUN  ==========
test('unit_tests', test_exe, args: '-c', timeout: 30, is_parallel: false)
### =============================================

### ========== CUSTOM TARGETS  ==========
run_target('unit_test', command: [test_exe, '-c'])
run_target('run_exe', command: [run_exe])
### =====================================
