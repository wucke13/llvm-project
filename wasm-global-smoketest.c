// clear && build/bin/clang -debug -target wasm32-unknown-none wasm-global-smoketest.c -c -o build/wasm-global-smoketest.wasm -fcolor-diagnostics && nix shell nixpkgs\#wabt --command wasm2wat build/wasm-global-smoketest.wasm
void readMyGlobal(void);

__asm__("\
.global my_global\n\
.export_name my_global, my_global\n\
.globaltype my_global_i32, i32, immutable\n\
.globaltype my_global_i64, i64, immutable\n\
.globaltype my_global_f32, f32, immutable\n\
.globaltype my_global_f64, f64, immutable\n\
my_global_i32:\n\
my_global_i64:\n\
my_global_f32:\n\
my_global_f64:\n\
");

void readMyGlobal(void) {
  int MyGlobalI32;
  long long MyGlobalI64;
  float MyGlobalF32;
  double MyGlobalF64;

  __asm__("\
global.get my_global_i32\n\
global.get my_global_i64\n\
global.get my_global_f32\n\
global.get my_global_f64\n\
local.set %0\n\
local.set %1\n\
local.set %2\n\
local.set %3\n\
"
          : "=r"(MyGlobalF64), "=r"(MyGlobalF32), "=r"(MyGlobalI64),
            "=r"(MyGlobalI32));
}
