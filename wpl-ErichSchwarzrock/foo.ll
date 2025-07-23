; ModuleID = 'foo.c'
source_filename = "foo.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @program() #0 {
  %1 = alloca [5 x i32], align 16
  %2 = alloca i32, align 4
  %3 = getelementptr inbounds [5 x i32], [5 x i32]* %1, i64 0, i64 3
  %4 = load i32, i32* %3, align 4
  store i32 %4, i32* %2, align 4
  ret i32 2
}

