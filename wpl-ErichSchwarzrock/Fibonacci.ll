; ModuleID = '123'
source_filename = "123"

@0 = private unnamed_addr constant [38 x i8] c"\22Which fibinochi number do you want?\22\00", align 1
@1 = private unnamed_addr constant [28 x i8] c"\22The fibinochi number is: \22\00", align 1

declare void @outInt(i32)

declare void @outChar(i32)

declare i32 @in()

declare void @print(i8*)

define i32 @fibTail(i32 %0, i32 %1, i32 %2, i32 %3) {
entry:
  %a = alloca i32, align 4
  store i32 %0, i32* %a, align 4
  %b = alloca i32, align 4
  store i32 %1, i32* %b, align 4
  %i = alloca i32, align 4
  store i32 %2, i32* %i, align 4
  %n = alloca i32, align 4
  store i32 %3, i32* %n, align 4
  %i1 = load i32, i32* %i, align 4
  %n2 = load i32, i32* %n, align 4
  %4 = icmp eq i32 %i1, %n2
  %5 = zext i1 %4 to i32
  %6 = trunc i32 %5 to i1
  br i1 %6, label %bTrue, label %bContinue

bTrue:                                            ; preds = %entry
  %a3 = load i32, i32* %a, align 4
  ret i32 %a3
  br label %bContinue

bContinue:                                        ; preds = %bTrue, %entry
  %b4 = load i32, i32* %b, align 4
  %a5 = load i32, i32* %a, align 4
  %b6 = load i32, i32* %b, align 4
  %7 = add nsw i32 %a5, %b6
  %i7 = load i32, i32* %i, align 4
  %8 = add nsw i32 %i7, 1
  %n8 = load i32, i32* %n, align 4
  %9 = call i32 @fibTail(i32 %b4, i32 %7, i32 %8, i32 %n8)
  ret i32 %9
}

define i32 @fib(i32 %0) {
entry:
  %n = alloca i32, align 4
  store i32 %0, i32* %n, align 4
  %n1 = load i32, i32* %n, align 4
  %1 = call i32 @fibTail(i32 0, i32 1, i32 0, i32 %n1)
  ret i32 %1
}

define i32 @program() {
entry:
  call void @print(i8* getelementptr inbounds ([38 x i8], [38 x i8]* @0, i32 0, i32 0))
  call void @outChar(i32 10)
  %x = alloca i32, align 4
  %0 = call i32 @in()
  store i32 %0, i32* %x, align 4
  %x1 = load i32, i32* %x, align 4
  %1 = call i32 @fib(i32 %x1)
  store i32 %1, i32* %x, align 4
  call void @print(i8* getelementptr inbounds ([28 x i8], [28 x i8]* @1, i32 0, i32 0))
  %x2 = load i32, i32* %x, align 4
  call void @outInt(i32 %x2)
  ret i32 5
}
