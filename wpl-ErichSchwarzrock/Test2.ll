; ModuleID = '123'
source_filename = "123"

declare i32 @in()

declare void @outInt(i32)

define i32 @program() {
entry:
  %x = alloca i32, align 4
  %0 = call i32 @in()
  store i32 %0, i32* %x, align 4
  %x1 = load i32, i32* %x, align 4
  call void @outInt(i32 %x1)
  ret i32 5
}
