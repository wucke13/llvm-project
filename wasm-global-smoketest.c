int readMyGlobal(void);

__asm__("\
.global my_global\n\
.export_name my_global, my_global\n\
.globaltype my_global, i32, immutable\n\
my_global:\n\
");

int readMyGlobal(void){
  int MyGlobal;
  __asm__("global.get my_global\n"
          "local.set %0\n"
          : "=r"(MyGlobal));
  return MyGlobal;
}
